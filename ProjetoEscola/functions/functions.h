#define n_find -1 //utilizado para erros
#define find -2 
#define Max 50
#define Max_cadastros 10
#define Range_codigo 11
#define Max_cad_disc 5

typedef struct ls_gr{
    int matricula, data_nasc[3];
    char sexo, cpf[15], nome[Max];
}cadastros;

typedef struct disci{
    char nome[Max], codigo[Range_codigo], nome_prof[Max];
    int semestre, matricula_prof;
    int matriculas_alu[Max_cad_disc];
    int qtd_alunos;
}disciplina;

//Outros
void limpa_buffer();

void name_pattern(char *p);

void remove_fgets(char *p);

void zerar_cadastros_disciplina(disciplina *p);

void print_cadastros(int i, cadastros *p);
//Menus
int menu();

int menu_update();

int menu_lista(int opcao_menu);

int menu_2(int menu);

int menu_update_disc();

int menu_lista_disc();

//Cadastros e Exclusão
char cad_sexo();

int cad_delete(int qtd_cadastros, cadastros *p);

int disc_delete(int qtd_cadastros, disciplina *p);

int cad_matricula(int qtd_cadastros, cadastros *p);

int matricula_al_disc(int qtd_disciplinas, int qtd_alunos, disciplina *p, cadastros *a);

void delete_matricula_disc(int qtd_cadastros, int qtd_disc, cadastros *p, disciplina *d);

//listas
void list_sexo(int qtd_cadastros, cadastros *p);

void list_nome(int qtd_cadastros, cadastros *p);

void list_geral(int qtd_cadastros, cadastros *p);

void search_cad(int qtd_cadastros, cadastros *p);

void list_qtd_al_disc(int qtd_disc, disciplina *p);

void search_disc(int qtd_disciplinas, disciplina *p);

void list_disc_semestre(int qtd_disc, disciplina *p);

void list_data_nasc(int qtd_cadastros, cadastros *p);

void list_nome_disc(int qtd_disciplinas, disciplina *p);

void list_geral_disc(int qtd_cadastros, disciplina *p, int opcao);

void list_alu_disc(int qtd_disc, disciplina *p, int qtd_aln, cadastros *a);

void list_qtd_disc(int qtd_aluno, int qtd_disc, cadastros *p, disciplina *d);

void list_prof_sem_disc(int qtd_prof, int qtd_disc, cadastros *p, disciplina *d);

void list_alphabet(int qtd_cadastros, cadastros *p, disciplina *d, int qtd_disc, int opcao);

//Update
int update(int qtd_cadastros, cadastros *p);

int update_disciplina(int qtd_disciplinas, disciplina *p);

//Verificações
int ver_cpf(int qtd_cadastros, cadastros *p);

int ver_data_nasc(int qtd_cadastros, cadastros *p);

int ver_matricula(int qtd_cadastros, cadastros *p, cadastros d);

int ver_codigo_disc(int qtd_cadastros, disciplina *p, int lugar_do_codigo);

//CADASTROS PARA TESTES
int disciplina_lista_teste(int qtd_disc, disciplina *p);

int alunos_lista_teste(int qtd_cadastros, cadastros *p);

int professor_lista_teste(int qtd_cadastros, cadastros *p);