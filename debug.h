#ifndef DEBUG_GRID_H
#define DEBUG_GRID_H

/*
 * debug_grid.h
 * ----------------
 * Modulo de grid de debug para projetos em ncurses.
 *
 * Como usar (arquivo separado, facil de ativar/desativar):
 *   1. #include "debug_grid.h" no seu arquivo principal.
 *   2. A cada frame do seu loop, chame:
 *        int dbg_ativo = debug_grid_update(tecla);
 *        debug_grid_draw(dbg_ativo);
 *        debug_grid_draw_status();
 *   3. Para desativar o modulo por completo, basta nao chamar
 *      as funcoes acima (ou definir DEBUG_GRID_DESATIVADO).
 *
 * Ativacao:
 *   - Segure 'y' por 3 segundos  (etapa 1)
 *   - Em seguida, segure '1' por 3 segundos (etapa 2 / confirmacao)
 *   - O grid de debug liga/desliga (toggle).
 *
 * Requer ncurses com nodelay(stdscr, TRUE) ativo no loop principal.
 */

#include <ncurses.h>
#include <time.h>

#define DEBUG_GRID_HOLD_MS      3000   /* tempo de segurar cada tecla        */
#define DEBUG_GRID_RELEASE_MS   250    /* tempo sem a tecla => soltou         */
#define DEBUG_GRID_COLOR        20     /* par de cores usado no grid (opc.)   */

/* Estados da maquina de ativacao */
enum {
    DBG_IDLE = 0,   /* esperando 'y'                          */
    DBG_HOLD_Y,     /* segurando 'y'                          */
    DBG_WAIT_1,     /* 'y' confirmado, esperando '1'          */
    DBG_HOLD_1      /* segurando '1' (confirmacao final)      */
};

/* Estado interno do modulo (static => nao polui o codigo principal) */
static int    dbg_state        = DBG_IDLE;
static double dbg_held_ms      = 0.0;
static double dbg_since_key_ms = 0.0;
static clock_t dbg_last_clock  = 0;
static int    dbg_active       = 0;

static double dbg_clock_ms(void)
{
    return (double)clock() * 1000.0 / (double)CLOCKS_PER_SEC;
}

/*
 * Atualiza a maquina de estados de ativacao.
 * `tecla` deve ser o valor retornado por getch() no modo nodelay.
 * Retorna 1 se o grid de debug estiver ativo, 0 caso contrario.
 */
int debug_grid_update(int tecla)
{
#ifdef DEBUG_GRID_DESATIVADO
    (void)tecla;
    return 0;
#else
    clock_t now = clock();
    double dt;

    if (dbg_last_clock == 0)
        dbg_last_clock = now;

    dt = (double)(now - dbg_last_clock) * 1000.0 / (double)CLOCKS_PER_SEC;
    dbg_last_clock = now;
    if (dt < 0.0)    dt = 0.0;
    if (dt > 200.0)  dt = 200.0;   /* clamp para evitar pulos grandes      */

    switch (dbg_state)
    {
        case DBG_IDLE:
            dbg_held_ms      = 0.0;
            dbg_since_key_ms = 0.0;
            if (tecla == 'y') {
                dbg_state    = DBG_HOLD_Y;
                dbg_held_ms += dt;
                dbg_since_key_ms = 0.0;
            }
            break;

        case DBG_HOLD_Y:
            if (tecla == 'y') {
                dbg_held_ms      += dt;
                dbg_since_key_ms  = 0.0;
                if (dbg_held_ms >= DEBUG_GRID_HOLD_MS) {
                    dbg_state    = DBG_WAIT_1;
                    dbg_held_ms  = 0.0;
                }
            } else {
                /* ERR (sem input neste frame) ou outra tecla */
                dbg_since_key_ms += dt;
                if (tecla != ERR && tecla != 'y') {
                    dbg_state = DBG_IDLE;
                } else if (dbg_since_key_ms >= DEBUG_GRID_RELEASE_MS) {
                    /* soltou o 'y' antes de completar */
                    dbg_state = DBG_IDLE;
                }
            }
            break;

        case DBG_WAIT_1:
            dbg_held_ms      = 0.0;
            dbg_since_key_ms = 0.0;
            if (tecla == '1') {
                dbg_state    = DBG_HOLD_1;
                dbg_held_ms += dt;
                dbg_since_key_ms = 0.0;
            } else if (tecla != ERR && tecla != 'y') {
                /* tecla diferente cancela a confirmacao */
                dbg_state = DBG_IDLE;
            }
            break;

        case DBG_HOLD_1:
            if (tecla == '1') {
                dbg_held_ms      += dt;
                dbg_since_key_ms  = 0.0;
                if (dbg_held_ms >= DEBUG_GRID_HOLD_MS) {
                    dbg_active = !dbg_active;   /* toggle on/off */
                    dbg_state  = DBG_IDLE;
                    dbg_held_ms = 0.0;
                }
            } else {
                dbg_since_key_ms += dt;
                if (tecla != ERR && tecla != '1') {
                    dbg_state = DBG_IDLE;
                } else if (dbg_since_key_ms >= DEBUG_GRID_RELEASE_MS) {
                    dbg_state = DBG_IDLE;
                }
            }
            break;
    }

    return dbg_active;
#endif
}

/*
 * Desenha o grid de debug (numeros nas laterais + tabuleiro).
 * So desenha se `ativo` for verdadeiro.
 */
void debug_grid_draw(int ativo)
{
#ifdef DEBUG_GRID_DESATIVADO
    (void)ativo;
#else
    if (!ativo)
        return;

    /* Tenta usar cor se houver pares de cor inicializados; senao, usa dim. */
    int has_color = (has_colors() && can_change_color());
    if (has_color)
        attron(COLOR_PAIR(DEBUG_GRID_COLOR) | A_DIM);
    else
        attron(A_DIM);

    /* --- Numeros das colunas (linha superior) --- */
    for (int c = 0; c < COLS; c++) {
        char ch = (char)('0' + (c % 10));
        if (c == 0)
            mvaddch(0, c, '+' | A_BOLD);
        else if (c % 10 == 0)
            mvaddch(0, c, ch | A_BOLD);
        else
            mvaddch(0, c, ch);
    }

    /* --- Numeros das linhas (coluna esquerda) --- */
    for (int r = 0; r < LINES; r++) {
        char ch = (char)('0' + (r % 10));
        if (r == 0)
            mvaddch(r, 0, '+' | A_BOLD);
        else if (r % 10 == 0)
            mvaddch(r, 0, ch | A_BOLD);
        else
            mvaddch(r, 0, ch);
    }

    /* --- Tabuleiro de debug: padrao xadrez com marcadores --- */
    for (int r = 1; r < LINES; r++) {
        for (int c = 1; c < COLS; c++) {
            if (r % 5 == 0 && c % 5 == 0) {
                mvaddch(r, c, '+' | A_BOLD);          /* cruz a cada 5x5     */
            } else if (r % 5 == 0) {
                mvaddch(r, c, '-');                   /* linha horizontal    */
            } else if (c % 5 == 0) {
                mvaddch(r, c, '|');                   /* linha vertical      */
            } else if (((r + c) % 2) == 0) {
                mvaddch(r, c, '.');                   /* celula par          */
            } else {
                mvaddch(r, c, ' ');                  /* celula impar        */
            }
        }
    }

    /* --- Painel de informacao --- */
    mvprintw(1, 2, "[DEBUG GRID] LINES=%d COLS=%d", LINES, COLS);
    mvprintw(2, 2, "y/1 p/ alternar | estado=%d", dbg_state);

    if (has_color)
        attroff(COLOR_PAIR(DEBUG_GRID_COLOR) | A_DIM);
    else
        attroff(A_DIM);
#endif
}

/*
 * Desenha o status de ativacao (barra de progresso) no rodape.
 * Chame todo frame para o usuario ver o progresso ao segurar as teclas.
 */
void debug_grid_draw_status(void)
{
#ifdef DEBUG_GRID_DESATIVADO
    return;
#else
    const char *msg   = "";
    double      prog  = 0.0;

    switch (dbg_state)
    {
        case DBG_IDLE:
            if (!dbg_active)
                msg = "Debug desligado: segure 'y' por 3s...";
            else
                msg = "Debug ligado: segure 'y' por 3s para desligar...";
            break;
        case DBG_HOLD_Y:
            msg  = "Segurando 'y'...";
            prog = dbg_held_ms / (double)DEBUG_GRID_HOLD_MS;
            break;
        case DBG_WAIT_1:
            msg  = "'y' OK! Agora segure '1' por 3s para confirmar...";
            prog = 0.0;
            break;
        case DBG_HOLD_1:
            msg  = "Segurando '1' (confirmacao)...";
            prog = dbg_held_ms / (double)DEBUG_GRID_HOLD_MS;
            break;
    }

    if (prog < 0.0) prog = 0.0;
    if (prog > 1.0) prog = 1.0;

    int row = LINES - 1;
    if (row < 0) row = 0;

    attron(A_REVERSE);
    mvprintw(row, 0, "%-*s", COLS, "");   /* limpa a linha de baixo       */
    attroff(A_REVERSE);

    mvprintw(row, 0, "%s [", msg);

    int label_len = (int)strlen(msg) + 2;
    int bar_x     = label_len;
    int bar_max   = COLS - bar_x - 1;
    if (bar_max < 0) bar_max = 0;

    int filled = (int)(prog * (double)bar_max);
    for (int i = 0; i < bar_max; i++) {
        if (i < filled)
            mvaddch(row, bar_x + i, '#');
        else
            mvaddch(row, bar_x + i, '-');
    }
    if (bar_max >= 0)
        mvaddch(row, bar_x + bar_max, ']');
#endif
}

/* Reseta o estado do modulo (util ao trocar de cena/menu). */
void debug_grid_reset(void)
{
    dbg_state        = DBG_IDLE;
    dbg_held_ms      = 0.0;
    dbg_since_key_ms = 0.0;
    dbg_last_clock   = 0;
}

/* Forca liga/desliga do grid (uso programatico). */
void debug_grid_set(int ativo)
{
    dbg_active = ativo ? 1 : 0;
    debug_grid_reset();
}

int debug_grid_is_active(void)
{
    return dbg_active;
}

#endif /* DEBUG_GRID_H */