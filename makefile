#variaveis e compilação
# ====================================================================================

# 'CC' define o compilador
CC = gcc

# 'CFLAGS' guarda as opções (flags) que alteram o comportamento do compilador.
# -Wall        : Ativa os warnings, sobre erro lógico etc
# -Wextra      : Ativa warnings extra como variavel inutilizada
# -Werror      : Transforma TODOS os avisos em erros, n compila se tiver um warning ( n precisa ativar esse n)
# -O2          : Otimiza o código em assembly para velocidade e performance. ( poderia usar o -O3, mas dependendo n vale a pena pq pode dar mais bolha no pipeline, já que ele aumenta mt o código em assembly, desenrolando os loops etc)
# -g           : Adiciona símbolos de debug.presisa pro Valgrind e GDB pra achar a linha onde o código quebra.
# -I.          : Diz ao compilador para procurar headers (.h) na mesma pasta atual (o '.' significa diretório atual).
CFLAGS = -Wall -O2 -Wextra -g -I.

# 'LIBS' define as bibliotecas que estão fora da biblioteca padrão do C que precisam ser anexadas.
# -lncursesw   : A biblioteca principal do jogo. Permite desenhar no terminal(o 'w' deixa suportar acentuação/Unicode).
# -lm          : Linka a "math.h" Se for usar seno, cosseno, etc. precisa do -lm.
# -lpthread    : Necessário pra usar threads (pra rodar coisas em paralelo).
LIBS = -lncursesw

# 'OUT' é o nome e o caminho do executável final que será gerado.
# OUT = /tmp/game        : Cria o jogo na pasta temporária do Linux. Apaga sozinho quando desliga o PC. Não polui a pasta do projeto.
# OUT = jogo.out      : Cria o executável na mesma pasta que este Makefile.
# OUT = bin/game         : Guarda o jogo pronto dentro de uma pasta chamada 'bin' para organizar melhor.
OUT = /tmp/game

# 'DELETE' define o comando que apaga arquivo.
# DELETE = rm -f       : Padrão do Linux. 'rm' remove, o '-f' (force) apaga sem encher o saco com "tem certeza?" e não dá erro se o arquivo não existir.
# DELETE = rm -rf      : Apaga pastas inteiras à força.
DELETE = rm -f

# 'CLEAR' guarda o comando para limpar o terminal.
# O '&&' é um operador só executa o clear se o comando anterior não der erro.
CLEAR = && clear

# ------------------------------------------------------------------------------------
# WILDCARD automatiza o bagulho de escrever os nomes, só precisa botar eles no arquivo:

SRC = WhilePlayingNotStudying.c \
    $(wildcard funcoes/*.c) \
    $(wildcard jogos/*.c) \
    $(wildcard animacoes/*.c) \
    $(wildcard provas/*.c) \
    $(wildcard dialogos/*.c) \
    $(wildcard funcoes/save/*.c) \
    $(wildcard funcoes/cenario/*.c) \
    $(wildcard funcoes/cenario/mecanicas/*.c) \
    $(wildcard funcoes/hud/*.c) \
    $(wildcard funcoes/jogador/*.c) \
    $(wildcard funcoes/menu/*.c)

# 1. "O que o wildcard faz?"
# o wildcard Substitui a digitação manual. O "$(wildcard animacoes/*.c)" faz o Make pegar tudo na pasta animacoes que termine com .c
#
# 2. n pode botar só um `$(wildcard *.c)` pra pegar tudo pq ela só ve a pasta atual
# onde ta o make, tem q ter um wildcard pra cada pasta.

# 'OBJDIR' é o nome da pasta onde a gente vai jogar todos os arquivos .o compilados,
# pra não ficar aquela bagunça de arquivo solto do lado dos .c ocupando espaço.
OBJDIR = obj

# Transformação automática usando patsubst:
# Ele pega tudo que tá no SRC e enfia o "obj/" na frente e troca o ".c" por ".o".
# Ex: "animacoes/dormir.c" vira "obj/animacoes/dormir.o"
# (Antes a gente só usava $(SRC:.c=.o), mas ai ele não mudava a pasta, só o finalzinho).
# Essa variável OBJ agora guarda a lista de todos os nossos Arquivos Objeto já na pasta certa.
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

# sempre q a gente compila,a o GCC pegava os arquivos, passava pra assembly, ai o 
# montador ( assembler) passava pro código maquina fazia virar o objéto, né?
# juntava com o link editor com a rotina da biblioteca e dps fazia virar executavel.
# oq demora bastante
# Esse OBJ pega os .c e já transforma em .o, que já são executaveis em máqina e deixa
# esses .o, ent quando mudamos um arquivo, ele escolhe só usar os .o
# que já tão la e compilar e juntar com oq a gente mexeu ao inves de recompilar tudo
# ====================================================================================

# Pra que serve o alvo 'debug'?:
# como C trata malloc() FOPEN, se a gente esquecer de fechar ou de dar free ela da  
# vazamento né? O Valgrind acha isso.
#
# as flags na frente do comando valgrind:
# --leak-check=full      : Relata os blocos de memória não liberado.
# --show-leak-kinds=all  : Mostra todo tipo de vazamento (até as memórias ainda acessíveis no fim do programa).
# --track-origins=yes    : Se o jogo crashar por ler uma variável vazia/lixo, ele diz a linha exata onde criamos ela.
# ====================================================================================


# Alvo principal. Quando você digita só 'make', ele busca o 'all', que depende da variável $(OUT) para existir.
all: $(OUT)

# Alvo: $(OUT) (o executável /tmp/game). Dependências: $(OBJ) (todos os 70 arquivos .o).
# $(CC)     -> chama o gcc.
# $(CFLAGS) -> Passa as flags
# $^        -> Variável que lista todas as dependências automaticamente (todos os .o), nesse caso
# -o $@     -> O '-o' diz o nome da saída. '$@' é uma variável automática, tipo a de cima que copia o nome do alvo (/tmp/game).
# $(LIBS)   -> Gruda a biblioteca ncursesw no executável.
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Regra pra compilar os .o e já jogar na pasta certa (dentro da obj/):
# O símbolo '%' da pra traduzir pra "Para fazer qualquer .o, ve o seu respectivo .c".
# @mkdir -p $(dir $@) -> Cria as pastas e subpastas tudo sozinho lá dentro, milissegundos antes de compilar,
# pra não dar erro de diretório não encontrado. O '@' esconde o comando no terminal pra n encher a tela.
# $(CC)     -> chama o gcc.
# $(CFLAGS) -> Passa as flags.
# -c        -> diz pro gcc para compilar os .o, mas n linkar num executável ainda.
# $<        -> Variável automática, pega apenas o PRIMEIRO item das dependências (o arquivo .c específico).
# -o $@     -> O '-o' diz o nome da saída. '$@' copia o nome do alvo (o arquivo .o específico na pasta obj).
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# chama o valgrind no terminal, passa as flags de rastreamento extremo, e roda o executável guardado em $(OUT).
debug: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(OUT)

# Apenas chama o executável (/tmp/game) no terminal do 'make run'.
run: $(OUT)
	$(OUT)

# Chama o programa 'gnome-terminal' nativo do Ubuntu e o '--' diz para ele abrir uma nova janela preta rodando apenas o seu jogo $(OUT).
run-ext: $(OUT)
	gnome-terminal -- $(OUT)

# ALVO DE LIMPEZA
# Apaga as sobras da compilação.
# $(DELETE) -r $(OBJDIR) -> Apaga a pasta 'obj' inteira de uma vez (o -r é recursivo, apaga oq tem dentro tbm). Limpa tudo os .o.
# $(DELETE) $(OUT)       -> Apaga o executável final /tmp/game.
# $(CLEAR)               -> Por fim, roda '&& clear' para deixar a tela do seu terminal limpinha.
clean:
	$(DELETE) -r $(OBJDIR)
	$(DELETE) $(OUT) $(CLEAR)