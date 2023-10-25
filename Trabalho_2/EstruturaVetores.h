
#define MAX 10
#define SUB_MAX 30
#define EMPTY -15
#define ACTIVE 0
#define INACTIVE -1

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };
       
typedef struct Sub_Vet{
    int num;
    int status;
    struct Sub_Vet *prox;
}No;

typedef struct Main_Vet{
    int tam;    //Tamanho total da sub-lista
    int Qtd;    //Qtd de elementos válidos
    No *sub;
}Main_Vet;

int menu();

void free_all();

void free_especific(int posicao);

void show_selected(int x);

void inicializar(Main_Vet *p_Vet);

int menu_control(int option);

int criarEstruturaAuxiliar(int posicao, int tamanho);

int inserirNumeroEmEstrutura(int posicao, int valor);

int excluirNumeroDoFinaldaEstrutura(int posicao);

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);

int getQuantidadeElementosEstruturaAuxiliar(int posicao);

No *montarListaEncadeadaComCabecote();