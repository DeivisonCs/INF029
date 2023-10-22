/*
    gcc EstruturaVetores.c -o ev
*/
#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

Main_Vet Vetor[MAX];

// int main(){
//     int nav_menu = -1;
//     int sair = 0;

//     printf("Here\n\n");

//     while(!sair){
//         nav_menu = menu();

//         if(nav_menu == 0){
//             free_all();
//             break;
//         }

//         else if(nav_menu == 1)
//         {
//             nav_menu = menu_control(nav_menu);

//             // if(nav_menu == SUCESSO)
//             //     printf("Numero Inserido\n");
//             // else
//             //     printf("Numero nao inserido\n");
//             if(nav_menu != SUCESSO)
//                 printf("Numero nao inserido\n");
//         }

//         else if(nav_menu == 3)
//             nav_menu = menu_control(nav_menu);
        
//         else       
//             printf("Valor Invalido\n");
//     }

//     return EXIT_SUCCESS;
// }

void inicializar(Main_Vet *p_Vet){
    for(int i=0; i<MAX; i++){
        p_Vet[i].tam = 0;
        p_Vet[i].sub = NULL;
    }
}

int menu(){
    int ctrl;

        printf("------------- Menu -------------\n\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Excluir\n");
        printf("3 - Listar\n");
        printf("4 - Aumentar Estrutura\n\n");

        printf("--> ");

        scanf("%d", &ctrl);
        getchar();

        return ctrl;
}

int menu_control(int option){
    int ctrl;

    switch(option)
    {
    // SAIR
        case 0:
            return 0;
        break;

    // INSERIR NA ESTRUTURA AUXILIAR 
        case 1:
            int posicao, valor;

            printf("------------ Inserir -----------\n\n");
            printf("Digite a Posição: ");
            scanf("%d", &posicao); 
            getchar();

            printf("Digite o Valor: ");
            scanf("%d", &valor); 
            getchar();

            ctrl = inserirNumeroEmEstrutura(posicao, valor);

            if(ctrl == SEM_ESTRUTURA_AUXILIAR)
            {
                ctrl = criarEstruturaAuxiliar(posicao, valor);

                if(ctrl == SUCESSO)
                {
                    ctrl = inserirNumeroEmEstrutura(posicao, valor);
                    if(ctrl == SUCESSO)
                        return SUCESSO;
                }
            }
            else  if(ctrl == SUCESSO)
                return SUCESSO;
            else
                return EXIT_FAILURE;
        break;

        case 3:
            printf("------------- Listar -----------\n\n");
            printf("Listar estrutura: ");
            scanf("%d", &ctrl); 
            getchar();

            show_selected(ctrl);
        break;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho){
    int i = posicao-1;

    // printf("\tCriar Estrutura Auxiliar\n");

    if(posicao > 10 || posicao <= 0){
        // printf("Posicao Invalida (estrutura)\n");
        return POSICAO_INVALIDA;
    }
    
    else if(Vetor[i].sub != NULL){
        // printf("Ja Tem Estrutura Auxiliar\n");
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    else if(Vetor[i].tam + tamanho > SUB_MAX){
        // printf("SEM_ESPACO_DE_MEMORIA\n");
        return SEM_ESPACO_DE_MEMORIA;
    }

    else if(tamanho < 1){
        // printf("TAMANHO_INVALIDO (Estrutura)\n");
        return TAMANHO_INVALIDO;
    }

    else{

        for(int j=0; j<tamanho; j++){
            No *node = malloc(sizeof(No));

            node->num = 0;
            node->status = INACTIVE;
            
            if(Vetor[i].sub == NULL){
                // printf("Sub-lista Posicao %d\n", j);
                Vetor[i].sub = node;
            }
            else{
                // printf("Sub-lista Posicao %d\n", j);
                No *aux = Vetor[i].sub;
                while(aux->prox != NULL)
                    aux = aux->prox;
                
                aux->prox = node;
            }

            node->prox = NULL;
            Vetor[i].tam++;
            // printf("Vetor Tamanho: %d\n", Vetor[i].tam);
        } 
        // printf("\n");
        return SUCESSO;
    }
}

int inserirNumeroEmEstrutura(int posicao, int valor){
    int i = posicao-1;

    // printf("\tFuncao Inserir\n");
    if(posicao > 10 || posicao <= 0){    //Posição Inválida
        // printf("Posicao Invalida (inserir)\n");
        return POSICAO_INVALIDA;
    }
    else{

        if(Vetor[i].sub == NULL)     //Sem Sub-Lista
        {
            // printf("Sem estrutura auxiliar\n");   
            return SEM_ESTRUTURA_AUXILIAR;
        }
        
        else
        {
        // Verifica se tem espaço livre
            No *node = Vetor[i].sub;
            int j=0;
            while(j < Vetor[i].tam && node->status != INACTIVE){
                
                if(node->prox != NULL)
                    node = node->prox;
                // printf("j: %d\n", j);
                j++;
            }

        //Caso não tiver espaço
            if(j == Vetor[i].tam && node->status == ACTIVE){
                // printf("Sem Espaco\n");
                return SEM_ESPACO;
            }

        //Caso haja espaço
            else{
                // printf("Numero Inserido\n");
                node->num = valor;
                node->status = ACTIVE;
                return SUCESSO;
            }
        }
    }
    // printf("\n");
}

//TO DO
int excluirNumeroDoFinaldaEstrutura(int posicao){}
//TO DO
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){}
//TO DO
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){}
//TO DO
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){}
//TO DO
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){}
//TO DO
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){}
//TO DO
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){}
//TO DO
int getQuantidadeElementosEstruturaAuxiliar(int posicao){}
//TO DO
No *montarListaEncadeadaComCabecote(){}

void show_selected(int x){

    No *node = Vetor[x-1].sub;

    while(node != NULL){
        printf("%d ", node->num);
        node = node->prox;   
    }

    printf("\n");
    
}

void free_all(){
    int i = 0;

    while(i < MAX)
    {
        if(Vetor[i].sub != NULL)
        {
            No *aux = Vetor[i].sub;

            while(aux != NULL){
                // printf("Removing\n");
                No *remove = aux;
                aux = aux->prox;
                free(remove);
            }
        }

        i++;
    }
}