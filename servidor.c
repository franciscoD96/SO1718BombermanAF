#include "estruturas.h"

/*Verifica a existencia de ficheiro com credenciais*/
int ficheiroTxt_existe(char *nome_ficheiro) {
    FILE *dados;
    dados = fopen(nome_ficheiro, "r");
    if (dados) {
        return 1;
        fclose(dados);
    }
    return 0;
}

void ficheiroTxt_cria() {
    FILE *dados;
    dados = fopen("dados.txt", "w");
    fprintf(dados, "admin 123\n");
    fclose(dados);
}

int comparar(char nome[], char dados_txt[]) {
    char *username;
    username = strtok(dados_txt, " ");

    if (strcmp(nome, username) == 0)
        return 0;
    return 1;

}

int ficheiroTxT_verificaUtilizador(char nome[]) {
    FILE *dados;
    char *result, linha[50];
    dados = fopen("dados.txt", "rt");

    while (!feof(dados)) {
        result = fgets(linha, 100, dados);
        if (result) {
            if (comparar(nome, linha) == 0)
                return 0;
        }
    }

    fclose(dados);
    return 1;
}

int ficheiroTxT_adicionaUtilizador(char nome[], char password[]) {
    int comp;

    comp = ficheiroTxT_verificaUtilizador(nome);
    if (comp == 1) {
        FILE *dados;
        dados = fopen("dados.txt", "a+");
        fprintf(dados, "%s %s\n", nome, password);
        fclose(dados);
        return 1;
    }
    return 0;
}

void comandosServidor() {
    char comando[MAX];
    char *username, *password, *nome_ficheiro;
    int tam, space, i;
    const char s[2] = " ";

    while (1) {

        scanf(" %[^\n]", comando);
        tam = strlen(comando);
        space = 0;
        if (strncmp(comando, "add ", 3) == 0) {

            for (i = 0; i < tam; i++) {
                if (comando[i] == ' ') {
                    space++;
                }
            }
            if (space == 2) {
                char *token;

                token = strtok(comando, s);
                username = strtok(NULL, s);
                password = strtok(NULL, s);

                if (ficheiroTxT_adicionaUtilizador(username, password) == 1) {
                    printf("\nSucesso ao registar o utilizador!\n\n");
                } else {
                    printf("\nUtilizador ja registado\n");
                }
            } else {
                printf("\nComando [%s] invalido\n", comando);
            }

        } else if (strcmp("users", comando) == 0) {

            printf("\nComando [users]\n");

        } else if (strncmp(comando, "kick ", 4) == 0) {

            for (i = 0; i < tam; i++) {
                if (comando[i] == ' ') {
                    space++;
                }
            }
            if (space == 1) {
                char *token;

                token = strtok(comando, s);
                username = strtok(NULL, s);

                printf("Comando [kick %s]\n", username);
            } else {
                printf("Comando [%s] invalido\n", comando);
            }
        } else if (strcmp("game", comando) == 0) {

            printf("Comando [game]");

        } else if (strcmp("shutdown", comando) == 0) {

            printf("Comando [game]\n");

            break;

        } else if (strncmp(comando, "map ", 3) == 0) {


            for (i = 0; i < tam; i++) {
                if (comando[i] == ' ') {
                    space++;
                }
            }
            if (space == 1) {
                char *token;

                token = strtok(comando, s);
                nome_ficheiro = strtok(NULL, s);

                printf("Comando [map %s]\n", nome_ficheiro);
            } else {
                printf("Comando [%s] invalido\n", comando);
            }
        } else {
            printf("Comando [%s] invalido\n", comando);
        }
    }

}

int main(int argc, char** argv) {


    //confirmar que o ficheiro existe
    int cria_ficheiro = ficheiroTxt_existe("dados.txt");
    if (cria_ficheiro == 0) {
        ficheiroTxt_cria();
        fprintf(stderr, "Ficheiro com conta de administrador criado com sucesso\n");
    }

    comandosServidor();
    return (EXIT_SUCCESS);
}