#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 50
#define INTERFACE 10000

//Estrutura para comunicar do cliente para o servidor e gerir clientes no servidor;
typedef struct {
    pid_t id;
    int mensagem;
    char username[MAX];
    char password[MAX];
}cliente;

//Estrutura para mandar mensagens do servidor para o cliente;
typedef struct {
    char mensagem[MAX];
}servidor;

//Estrutura do jogo
typedef struct {
    int mapa[20][40];
    int nInimigos;
    int nObjetos;
    int nivel;
}jogo;

//Estrutura enviada para os utilizadores , interface do jogo;
typedef struct {
    char interface[INTERFACE];
}interface_jogo;


//Estrutura do bomberman
typedef struct {
    int x;
    int y;
    int super_bomba;
    int bomba;
    int direcao;
}bomberman;

//Estrutura dos bots (inimigos)
typedef struct {
    int x;
    int y;
    int item;
    int direcao;
}inimigos;