#define Max_letters 50
#define ERROR 0
#define SUCCESS 1

typedef struct data{
    char data_inicial[15];
    int d;
    int m;
    int a;
    int type_year;
}data_valid;
 
typedef struct Qtd{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

int q1(char data_s[]);

DiasMesesAnos q2(char data_inicial[], char data_final[]);

int q3(char text[], char let, int CaseSensitive);

int q4(char *strTexto, char *strBusca, int posicoes[]);

int q5(int num);

int q6(int num, int comp);

void remove_fgets(char *p);

int bissexto(data_valid *p);

void get_data(char sup[], data_valid *p);

int meses(data_valid *start_data, DiasMesesAnos *distance, int mes);