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
    // inicializar();

//     while(!sair){
//         nav_menu = menu();

//         if(nav_menu == 0)
//             break;

//         else if(nav_menu > 6)
//             printf("Valor Invalido\n");
        
//         else
//             nav_menu = menu_control(nav_menu);
//     }

//     finalizar();
//     return EXIT_SUCCESS;
// }

void inicializar(){
    for(int i=0; i<MAX; i++){
        Vetor[i].tam = 0;
        Vetor[i].Qtd = 0;
        Vetor[i].sub = NULL;
    }
}

int menu(){
    int ctrl;

        printf("------------- Menu -------------\n\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Excluir\n");
        printf("3 - Listar\n");
        printf("4 - Criar Estrutura\n");
        printf("5 - GetDados\n");
        printf("6 - Aumentar Estrutura\n\n");

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
        case 0: return 0; break;

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

            else  if(ctrl == SUCESSO) return SUCESSO;
            else return EXIT_FAILURE;
        break;

    // EXCLUIR ELEMENTO
        case 2:
            printf("------------ Excluir -----------\n\n");
            printf("1 - Ultimo Elemento\n");
            printf("2 - Elemento Especifico\n\n");
            printf("-->");
            scanf("%d", &ctrl);
            getchar();

            printf("------------ Excluir -----------\n\n");
            printf("Posicao: ");
            scanf("%d", &posicao);
            getchar();

            if(ctrl == 2){
                printf("Valor: ");
                scanf("%d", &valor);
                getchar();

                ctrl = excluirNumeroEspecificoDeEstrutura(posicao, valor);
            }
            else
                ctrl = excluirNumeroDoFinaldaEstrutura(posicao);

            if(ctrl == SUCESSO) return SUCESSO;
            else return EXIT_FAILURE;
            
        break;

    // LISTAR
        case 3:
            printf("------------- Listar -----------\n\n");
            printf("Listar estrutura: ");
            scanf("%d", &ctrl); 
            getchar();

            show_selected(ctrl);
        break;

    // CRIAR ESTRUTURA
        case 4:
            printf("------------- Criar ------------\n\n");
            printf("Posicao: ");
            scanf("%d", &posicao);
            getchar();

            printf("Tamanho: ");
            scanf("%d", &valor);
            getchar();

            ctrl = criarEstruturaAuxiliar(posicao, valor);

            if(ctrl == SUCESSO) return SUCESSO;
            else return EXIT_FAILURE;
        break;
    
    // GETDADOS
        case 5:
            int dados[100];  
            printf("----------- GetDados -----------\n\n");
            printf("Posicao: ");
            scanf("%d", &posicao);
            getchar();

            ctrl = getDadosOrdenadosDeTodasEstruturasAuxiliares(dados);

            if(ctrl == SUCESSO){
                // TESTE
                // for(ctrl=0; ctrl<Vetor[posicao-1].Qtd; ctrl++)
                //     printf("%d ", dados[ctrl]);
                return SUCESSO;
            }
            else return EXIT_FAILURE;
        break;

        case 6:
            printf("------- Aumentar Estrutura -----\n\n");
            printf("Posicao: ");
            scanf("%d", &posicao);
            getchar();

            printf("Novo tamanho: ");
            scanf("%d", &valor);
            getchar();

            ctrl = modificarTamanhoEstruturaAuxiliar(posicao, valor);
        break;
    }
}

int criarEstruturaAuxiliar(int posicao, int tamanho){
    int i = posicao-1;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;
    
    else if(Vetor[i].sub != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    else if(tamanho < 1)
        return TAMANHO_INVALIDO;

    else{

        for(int j=0; j<tamanho; j++)
        {
            No *node = malloc(sizeof(No));

            if(node == NULL)
                return SEM_ESPACO_DE_MEMORIA;

            node->num = 0;
            node->status = INACTIVE;
            
            if(Vetor[i].sub == NULL)
                Vetor[i].sub = node;
            
            else{
                No *aux = Vetor[i].sub;
                while(aux->prox != NULL)
                    aux = aux->prox;
                
                aux->prox = node;
            }

            node->prox = NULL;
            Vetor[i].tam++;
        } 
        return SUCESSO;
    }
}

int inserirNumeroEmEstrutura(int posicao, int valor){
    int i = posicao-1;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
          
    else
    {
    // Verifica se tem espaço livre
        No *node = Vetor[i].sub;

        int j=0;
        while(j < Vetor[i].tam && node->status != INACTIVE){
            if(node->prox != NULL)
                node = node->prox;
            j++;
        }

    //Caso não tiver espaço
        if(j == Vetor[i].tam && node->status == ACTIVE)
            return SEM_ESPACO;
        

    //Caso haja espaço
        else{
            node->num = valor;
            Vetor[i].Qtd++;
            node->status = ACTIVE;
            return SUCESSO;
        }
    }
}

int excluirNumeroDoFinaldaEstrutura(int posicao){
    int i = posicao-1;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    else
    {
        No *node = Vetor[i].sub;

        while(node->prox != NULL && node->prox->status == ACTIVE)
            node = node->prox;

        if(node->status == INACTIVE && (node->prox == NULL || node->prox->status == INACTIVE))
            return ESTRUTURA_AUXILIAR_VAZIA;
        
        else{
            node->status = INACTIVE;
            Vetor[i].Qtd--;
            return SUCESSO;
        }
    }
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int i = posicao-1;
    int ctrl = 0;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    else
    {
        No *node = Vetor[i].sub;

        while(node != NULL){
            
            if(node->status == ACTIVE)
                ctrl++;

            if(node->num == valor && node->status == ACTIVE)
                break;

            node = node->prox;
        }

        if(ctrl == 0)
            return ESTRUTURA_AUXILIAR_VAZIA;
        

        else if(node == NULL)
            return NUMERO_INEXISTENTE;

        else{
            node->status = INACTIVE;
            Vetor[i].Qtd--;
            return SUCESSO;
        }
    }
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int i = posicao-1;
    int j;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    else
    {
        No *node = Vetor[i].sub;
        j=0;
        while(node != NULL){
            if(node->status == ACTIVE){
                vetorAux[j] = node->num;
                j++;
            }
            node = node->prox;
        }
        return SUCESSO;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int ctrl;

    ctrl = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if(ctrl == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;
    
    else if(ctrl == SEM_ESTRUTURA_AUXILIAR)
        return SEM_ESTRUTURA_AUXILIAR;
    
    else if(ctrl == SUCESSO)
    {
        int menor, aux;
        for(int i=0; i < Vetor[posicao-1].Qtd-1; i++)
        {
            menor = i;
            for(int j=i+1; j < Vetor[posicao-1].Qtd; j++)
                if(vetorAux[j] < vetorAux[menor])
                    menor = j;
            
            if(menor != i){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[menor];
                vetorAux[menor] = aux;
            }
        }
        return SUCESSO;
    }
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int i, ctrl, j, qtd_null;

    for(i=0, j=0, qtd_null=0; i<MAX; i++)
    {
        if(Vetor[i].Qtd == 0)
            qtd_null++;

        else{
            ctrl = getDadosEstruturaAuxiliar(i+1, &vetorAux[j]);
            j += Vetor[i].Qtd;
        }
    }

    if(qtd_null == MAX) return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int i=0, qtd, menor, j, aux;

    i = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if(i == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for(i=0, qtd=0; i<MAX; i++)
        qtd += Vetor[i].Qtd;  

    for(i=0; i<qtd-1; i++){
        menor = i;

        for(j=i+1; j<qtd; j++)
            if(vetorAux[j] < vetorAux[menor])
                menor = j;

        if(menor != i){
            aux = vetorAux[i];
            vetorAux[i] = vetorAux[menor];
            vetorAux[menor] = aux;
        }
    }

    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int i = posicao-1;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;
    
    else if(Vetor[i].tam + novoTamanho <= 0)
        return NOVO_TAMANHO_INVALIDO;
    
    else if(Vetor[i].tam + novoTamanho < Vetor[i].tam)  //CASO O NOVO TAMANHO DECREMENTE A SUB-LISTA
    {
        No *node = Vetor[i].sub;

        int j=0;
        while(j < 1-(Vetor[i].tam + novoTamanho)){    //ACHA O PONTO A SER EXCLUIDO
            node = node->prox;
            j++;
        }
        
        No *aux = node->prox;
        node->prox = NULL;

        while(aux != NULL){
            No *remove = aux;
            aux = aux->prox;
            free(remove);
        }

        Vetor[i].tam += novoTamanho;
    }

    else    //CASO NOVO INCREMENTE A SUB-LISTA
    {
        No *node = Vetor[i].sub;

        while(node->prox != NULL)
            node = node->prox;

        for(int j=0; j<novoTamanho; j++)
        {
            No *new_Node = malloc(sizeof(No));

            if(new_Node == NULL){
                printf("SEM_ESPACO_DE_MEMORIA\n");
                return SEM_ESPACO_DE_MEMORIA;
            }
            else{
                node->prox = new_Node;
                node = node->prox;
                new_Node->prox = NULL;
                new_Node->status = INACTIVE;
                Vetor[i].tam++;
            }
        }
    }

    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int i = posicao-1;

    if(valid_position(posicao) == POSICAO_INVALIDA) 
        return POSICAO_INVALIDA;

    else if(Vetor[i].sub == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    else if(Vetor[i].Qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    else
    {
        No *node = Vetor[i].sub;

        int qtd=0;
        while(node != NULL)
        {
            if(node->status == ACTIVE)
                qtd++;

            node = node->prox;
        }
        return qtd;
    }
}

No *montarListaEncadeadaComCabecote(){
    int qtd_Null=0;
    int get_start=0;
    No *start = malloc(sizeof(No)); start->prox = NULL;

    for(int i=0; i<MAX; i++)
    {
        if(Vetor[i].sub != NULL)
        {
            No *aux = Vetor[i].sub;
            while(aux != NULL)
            {
                if(aux->status == ACTIVE)
                {
                    No *new_Node = malloc(sizeof(No));
                    new_Node->num = aux->num;

                    if(start->prox == NULL)
                        start->prox = new_Node;

                    else{
                        No *get_End = start->prox;
                        while(get_End->prox != NULL)
                            get_End = get_End->prox;

                        get_End->prox = new_Node;
                    }
                    new_Node->prox = NULL;
                }
                aux = aux->prox;
            }
        }
    }

    return start;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    int i=0;
    No *node = inicio->prox;

    while(node != NULL){
        vetorAux[i] = node->num;
        i++;
        // if(node->status == ACTIVE){
        //     vetorAux[i] = node->num;
        //     i++;
        // }
        node = node->prox;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio){

    No *node = *inicio;

    while(node != NULL){
        No *remove = node->prox;
        free(node);
        node = remove;
    }
    *inicio = NULL;
}

void show_selected(int x){

    if(Vetor[x-1].sub == NULL){
        printf("Sem Estrutura Auxiliar\n");
        return;
    }

    No *node = Vetor[x-1].sub;

    while(node != NULL){
        
        if(node->status == ACTIVE)
            printf("%d ", node->num);
        else
            printf("(vazio) ");
        
        node = node->prox;   
    }

    printf("\n");
    
}

void finalizar(){
    int i = 0;

    while(i < MAX)
    {
        if(Vetor[i].sub != NULL)
        {
            No *aux = Vetor[i].sub;

            while(aux != NULL){
                No *remove = aux;
                aux = aux->prox;
                free(remove);
            }
        }

        i++;
    }

    printf("Espaço Liberado\n");
    printf("Programa Finalizado Com Sucesso\n");
}

void free_especific(int posicao){
    int i;

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
    printf("Espaço Liberado\n");
}

int valid_position(int posicao){
    if(posicao > 10 || posicao < 1) return POSICAO_INVALIDA;
    else  return SUCESSO;
}