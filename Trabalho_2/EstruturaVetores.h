
#define MAX 10
#define SUB_MAX 30
#define EMPTY -15

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };
       
typedef struct Sub_Vet{
    int num;
    struct Sub_Vet *next;
}Sub_Vet;

typedef struct Main_Vet{
    int tam;
    Sub_Vet *sub;
}Main_Vet;

int menu(int option);

void init(Main_Vet *p_Vet);

int criarEstruturaAuxiliar(int posicao, int tamanho);

int inserirNumeroEmEstrutura(int posicao, int valor);