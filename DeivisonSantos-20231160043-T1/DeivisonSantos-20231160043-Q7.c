/*
    gcc DeivisonSantos-20231160043-Q7.c -o q7
*/

//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DeivisonSantos-20231160043-Q7.h"

/*
    end_game com falha, e o formato 3c nn funciona
*/
int main(){
    Posicoes jogadas;
    int sair=0, in_game=0, ctrl, i;
    int p1=0, p2=0, emp=0;
    char confirm;

    while(!sair)
    {
        new_game(&jogadas);

        while(!in_game)
        {
            tabela(&jogadas);
            ctrl = end_game(&jogadas);
            if(ctrl != 0){
                switch(ctrl){
                    case WIN_P_1: p1++; break; 
                    case WIN_P_2: p2++; break;
                    case EMPATE: emp++; break;
                }
                break;
            }

            if(jogadas.player%2 == 0)
                printf("\n    Jogador 1 (O): ");
            else
                printf("\n    Jogador 2 (X): ");

            //fgets(jogadas.move, MAX, stdin);
            scanf("%s", jogadas.move); fflush(stdin);
            //getchar();

            i = move_normalize(&jogadas);
            if(i == EXIT_FAILURE){
                printf("\tJogada Invalida!!!\n");
            }
            else
                get_move(&jogadas);
            
        }

        printf("\nJogar Novamente ( S ou N ): ");
        scanf(" %c", &confirm); getchar();
        if(toupper(confirm) != 'S')
            break;
    }
    printf("\n------------- Resultado ------------\n");
    printf("\nPlayer 1: %d vitorias", p1);
    printf("\nPlayer 2: %d vitorias", p2);
    printf("\nEmpates: %d\n", emp);
    printf("\n---------------------------------\n");

    return EXIT_SUCCESS;
}

void tabela(Posicoes *p){
    char aux[3];    

    printf("\n\n");
    printf("\t     1     2     3 \n\n");
    printf("\tA    %c  |  %c  |  %c \n", p->tabela_game[0][0], p->tabela_game[0][1], p->tabela_game[0][2]);
    printf("\t   _____|_____|_____\n");
    printf("\t        |     |    \n");
    printf("\tB    %c  |  %c  |  %c \n", p->tabela_game[1][0], p->tabela_game[1][1], p->tabela_game[1][2]);
    printf("\t   _____|_____|_____\n");
    printf("\t        |     |    \n");
    printf("\tC    %c  |  %c  |  %c \n\n", p->tabela_game[2][0], p->tabela_game[2][1], p->tabela_game[2][2]);
}

void new_game(Posicoes *p){
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++)
            p->tabela_game[i][j] = ' '; 
    }
  strcpy(p->move, " ");
  p->player = 0;
}

void get_move(Posicoes *p){
    int i;
    
    i = valid_move(p);
    if(i == EXIT_FAILURE)
        return;

    switch(p->move[1])
    {

        case 'A':
            i = atoi(p->move);
            if(p->player%2 == 0)
                p->tabela_game[0][i-1] = 'O';
            else
                p->tabela_game[0][i-1] = 'X';
        break;

       case 'B':
            i = atoi(p->move);
            if(p->player%2 == 0)
                p->tabela_game[1][i-1] = 'O';
            else
                p->tabela_game[1][i-1] = 'X';
        break;

        case 'C':
            i = atoi(p->move);
            if(p->player%2 == 0)
                p->tabela_game[2][i-1] = 'O';
            else
                p->tabela_game[2][i-1] = 'X';
        break;
    }

    printf("\tMove: %s\n", p->move);
    p->player++;
}

int valid_move(Posicoes *p){
    int i, j;

    if(p->move[1] == 'A' && p->tabela_game[0][atoi(p->move)-1] != ' '){
        printf("\tJogada Ja Efetuada!!!\n");
        return EXIT_FAILURE;
    }
    else if(p->move[1] == 'B' && p->tabela_game[1][atoi(p->move)-1] != ' '){
        printf("\tJogada Ja Efetuada!!!\n");
        return EXIT_FAILURE;
    }
    else if(p->move[1] == 'C' && p->tabela_game[2][atoi(p->move)-1] != ' '){
        printf("\tJogada Ja Efetuada!!!\n");
        return EXIT_FAILURE;
    }
    else return EXIT_SUCCESS;
}

int move_normalize(Posicoes *p){
    char aux;
    int ascii[6]={65, 66, 67, 97, 98, 99}; 
    int i, ctrl; 

    if(strlen(p->move) != 2)
        return EXIT_FAILURE;
    
    //TESTA SE MOVE[0] É LETRA 
    for(i=0; i<6; i++)
        if(toupper(p->move[0]) == ascii[i])
            break;
        
    //TESTA SE MOVE[1] É NÚMERO
    if(i<6){
        if((p->move[1] - '0') <1 || (p->move[1] - '0') >3){
            // printf("here2");
            return EXIT_FAILURE;
        }
    }
    else{
        //TESTA SE MOVE[1] É LETRA 
        for(i=0; i<6; i++)
            if(toupper(p->move[1]) == ascii[i])
                break;
            
        //TESTA SE MOVE[0] É NÚMERO
        if(i<6){
            if((p->move[0] - '0') <1 || (p->move[0] - '0') >3){
                // printf("here3");
                return EXIT_FAILURE;
            }
        }else{
            // printf("here4");
            return EXIT_FAILURE;
        }
    }
 
    //DEFINE O PADRÃO (Coluna)(Linha)
    i = atoi(p->move);
    if(i == 0){
        aux = p->move[0];
        p->move[0] = p->move[1];
        p->move[1] = aux;
    }

    p->move[1] = toupper(p->move[1]);
}

int end_game(Posicoes *p){
    int i, j, ctrl[2], result=0;

//Confere as linhas
    for(i=0; i<LINHAS; i++)
    {
        ctrl[0] = 0;
        ctrl[1] = 0;
        for(j=0; j<COLUNAS; j++)
        {
            if(p->tabela_game[i][j] == 'O')
                ctrl[0]++;
            else if(p->tabela_game[i][j] == 'X')
                ctrl[1]++;
        }

        if(ctrl[0] == LINHAS){
            result = WIN_P_1;
            break;
        }
        else if(ctrl[1] == LINHAS){
            result = WIN_P_2;
            break;
        }
    }

//Confere as colunas
    for(i=0; i<COLUNAS; i++)
    {
        ctrl[0] = 0;
        ctrl[1] = 0;
        for(j=0; j<LINHAS; j++)
        {
            if(p->tabela_game[i][j] == 'O')
                ctrl[0]++;
            else if(p->tabela_game[i][j] == 'X')
                ctrl[1]++;
        }

        if(ctrl[0] == COLUNAS){
            result = WIN_P_1;
            break;;
        }
        else if(ctrl[1] == COLUNAS){
            result WIN_P_2;
            break;;
        }
    }

//Confere diagonal principal
    if(p->tabela_game[0][0] == 'O' && p->tabela_game[1][1] == 'O' && p->tabela_game[2][2] == 'O')
        result = WIN_P_1;
    else if(p->tabela_game[0][0] == 'X' && p->tabela_game[1][1] == 'X' && p->tabela_game[2][2] == 'X')
        result WIN_P_2;

//Confere diagonal secundaria
    else if(p->tabela_game[0][2] == 'O' && p->tabela_game[1][1] == 'O' && p->tabela_game[2][0] == 'O')
        result = WIN_P_1;
    else if(p->tabela_game[0][2] == 'X' && p->tabela_game[1][1] == 'X' && p->tabela_game[2][0] == 'X')
        result WIN_P_2;

//Empate
    else if(p->player == 9)
        result = EMPATE;

    if(result == WIN_P_1){
        tabela(p);
        printf("\n----------------------------------------------\n");
        printf("             ! Vitoria Jogador 1 !      \n");
        printf("-----------------------------------------------\n");
        return WIN_P_1;
    }
    else if(result == WIN_P_2){
        tabela(p);
         printf("\n----------------------------------------------\n");
        printf("             ! Vitoria Jogador 2 !      \n");
        printf("-----------------------------------------------\n");
        return WIN_P_2;
    }
    else if(result == EMPATE){
        tabela(p);
        printf("\n----------------------------------------------\n");
        printf("               ! Jogo Empatado !      \n");
        printf("-----------------------------------------------\n");
        return EMPATE;
    }
    else
        return 0;

}