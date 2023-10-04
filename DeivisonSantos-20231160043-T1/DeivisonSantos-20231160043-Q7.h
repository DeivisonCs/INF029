#define MAX 3
#define WIN_P_1 -1
#define WIN_P_2 -2
#define EMPATE -3
#define LINHAS 3
#define COLUNAS 3

typedef struct{
    char tabela_game[LINHAS][COLUNAS];
    char move[MAX];
    int player;
}Posicoes;

void tabela(Posicoes *p);

int end_game(Posicoes *p);

void get_move(Posicoes *p);

void new_game(Posicoes *p);

int valid_move(Posicoes *p);

int move_normalize(Posicoes *p);