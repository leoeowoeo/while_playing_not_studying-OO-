FROM gcc:latest AS base
# gcc:latest define um Linux com compilador GCC disponível

# Define o mesmo diretório do devcontainer
WORKDIR /workspace

# Instala ncurses para compilar e rodar o jogo
RUN apt-get update && apt-get install -y \
    libncurses-dev \
    libicu70 \
    libssl3 \
    libkrb5-3 \
    zlib1g \
    libsecret-1-0 \
    libglib2.0-0 \
    && rm -rf /var/lib/apt/lists/*
RUN code --install-extension MS-vsliveshare.vsliveshare \
    && code --install-extension ms-vscode.cpptools

# Copia os arquivos locais para dentro do container
COPY . /workspace