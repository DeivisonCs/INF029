/*
    gcc EstruturaVetores.c -o ev
*/
#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

Main_Vet Vetor[MAX];

int main(){
    int nav_menu;
    int sair = 0;

    while(!sair){
        nav_menu = menu(0);

        switch (nav_menu)
        {
            case 0:
            break;

            case 1:
                nav_menu = menu(1);

                if(nav_menu == SUCESSO)
                    printf("Numero Inserido\n");
                else
                    printf("Numero nao inserido\n");
            continue;
            
            default:
                printf("Valor Invalido\n");
            continue;
        }
    }

    return EXIT_SUCCESS;
}

void init(Main_Vet *p_Vet){
    for(int i=0; i<MAX; i++){
        p_Vet[i].tam = 0;
        p_Vet[i].sub = NULL; 
    }
}

int menu(int option){
    int ctrl;

    switch (option)
    {
        case 0:
            printf("------------- Menu -------------\n\n");
            printf("0 - Sair\n");
            printf("1 - Inserir\n");
            printf("2 - Excluir\n");
            printf("3 - Listar\n");
            printf("4 - Aumentar Estrutura\n\n");

            scanf("%d", &ctrl);
            return ctrl;
        break;

        case 1:
            int posicao, valor;

            printf("------------ Inserir -----------\n\n");
            printf("Digite a Posição: ");
            scanf("%d", &posicao);

            printf("Digite o Valor: ");
            scanf("%d", &valor);

            return inserirNumeroEmEstrutura(posicao, valor);
        break;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho){
    int i = posicao-1;

    if(posicao > 10 || posicao < 1)
        return POSICAO_INVALIDA;
    
    else if(Vetor[i].sub != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    else if(Vetor[i].tam + tamanho > SUB_MAX)
        return SEM_ESPACO_DE_MEMORIA;

    else if(tamanho < 1)
        return TAMANHO_INVALIDO;

    else{

        for(int j=0; j<tamanho; j++){
            Sub_Vet *node = malloc(sizeof(Sub_Vet));

            node->num = 0;
            
            if(Vetor[i].sub == NULL){
                Vetor[i].sub = node;
            }
            else{

                Sub_Vet *aux = Vetor[i].sub;
                while(aux->next != NULL)
                    aux = aux->next;
                
                aux->next = node;
            }

            node->next = NULL;
            Vetor[i].tam++;
        } 

        return SUCESSO;
    }
}

int inserirNumeroEmEstrutura(int posicao, int valor){
    int i = posicao-1;

    if(posicao > 10 || posicao < 0){    //Posição Inválida
        return POSICAO_INVALIDA;
    }
    else{

        if(Vetor[i].sub == NULL)     //Sem Sub-Lista
            return SEM_ESTRUTURA_AUXILIAR;
        
        else
        {
        // Verifica se tem espaço livre
            int j=0;
            Sub_Vet *node = Vetor[i].sub;
            while(j < Vetor[i].tam || node->num != 0){
                node = node->next;
                j++;
            }

        //Caso não tiver espaço
            if(j == Vetor[i].tam && node->num != 0)
                return SEM_ESPACO;

        //Caso haja espaço
            else{
                node->num = valor;
                return SUCESSO;
            }
        }
    }
}