#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

//--------- Outros -----------------------------------------------------
void name_pattern(char *p){
    int i, lenght;

    lenght = strlen(p);

    for(i=0; i<=lenght; i++)
    {
        if(i == 0 || (p[i-1] == ' ' && p[i] != ' '))
            p[i] = toupper(p[i]);
        else
            p[i] = tolower(p[i]);
    }
}

void limpa_buffer(){
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void zerar_cadastros_disciplina(disciplina *p){
    int i;

    for(i=0; i<Max_cadastros; i++)
        p[i].qtd_alunos = 0;
}

void remove_fgets(char *p){
    int i;

    i = strlen(p) -1;
    if(p[i] == '\n')
        p[i] = '\0';
}

void print_cadastros(int i, cadastros *p){
    printf("\nNome: %s\n", p[i].nome);
    printf("Sexo: %c\n", p[i].sexo);
    printf("CPF: %s\n", p[i].cpf);
    printf("Matricula: %d\n", p[i].matricula);
    printf("Data de Nascimento: %d/%d/%d\n\n", p[i].data_nasc[0], p[i].data_nasc[1], p[i].data_nasc[2]);
}

void print_disciplinas(int i, disciplina *p){
  printf("\nNome: %s\n", p[i].nome);
  printf("Semestre: %d\n", p[i].semestre);
  printf("Codigo: %s\n", p[i].codigo);
  if(p[i].matricula_prof == n_find)
      printf("Professor: N/A\n");
  else{
      printf("Professor: %s\n", p[i].nome_prof);
      printf("Matricula do Professor: %d\n", p[i].matricula_prof);
  }
}

//------------------ Menus ---------------------------------------------------
int menu(){
    int opcao=-1;
    
    printf("\n----------- Menu -------------\n\n");
    printf("0 - Finalizar\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplinas\n");

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

return opcao;
}

int menu_2(int menu){
    int opcao=-1;

    if(menu == 1)
        printf("\n-------- Menu Alunos ---------\n\n");
    else if(menu == 2)
        printf("\n----- Menu Professores -------\n\n");
    else
        printf("\n----- Menu Disciplina -------\n\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar\n");
    printf("2 - Atualizar\n");
    printf("3 - Excluir\n");
    printf("4 - Listar\n");
    printf("5 - Buscar\n");
    if(menu == 3){
        printf("6 - Matricular Aluno\n");
        printf("7 - Cancelar Matricula\n");
    }

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    // int c;
    // while ((c = getchar()) != '\n' && c != EOF);
    
    printf("\n");

return opcao;
}

int menu_lista(int opcao_menu){
    int opcao=-1;

    printf("\n----------- Listar -----------\n\n");
    printf("0 - Voltar\n");
    printf("1 - Listar Todos\n");
    printf("2 - Por Sexo\n");
    printf("3 - Parte do Nome\n");
    printf("4 - Por Ordem Alfabetica\n");
    printf("5 - Por Data de Nascimento\n");
    if(opcao_menu == 1)
      printf("6 - Matriculados em Menos de x Disciplinas\n");
    if(opcao_menu == 2)
        printf("6 - Sem Disciplina\n");

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

return opcao;
}

int menu_update(){
    int opcao=-1;

    printf("\n-------- Atualizar ---------\n\n");
    printf("0 - Voltar\n");
    printf("1 - Nome\n");
    printf("2 - Sexo\n");
    printf("3 - CPF\n");
    printf("4 - Matricula\n");
    printf("5 - Data de Nascimento\n");

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

return opcao;
}

int menu_update_disc(){
    int opcao=-1;

    printf("\n-------- Atualizar ---------\n\n");
    printf("0 - Voltar\n");
    printf("1 - Nome\n");
    printf("2 - Codigo\n");
    printf("3 - Semestre\n");
    printf("4 - Professor\n");

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

return opcao;
}

int menu_lista_disc(){
    int opcao=-1;

    printf("\n----------- Listar -----------\n\n");
    printf("0 - Voltar\n");
    printf("1 - Listar Todas\n");
    printf("2 - Por Semestre\n");
    printf("3 - Sem Professor\n");
    printf("4 - Listar Alunos\n");
    printf("5 - Por Parte do Nome\n");
    printf("6 - Quantidade de Alunos\n");
    printf("7 - Por Ordem Alfabetica\n");

    printf("\n--> ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");

return opcao;
}
//------ Verificações(CPF, sexo, ...) ----------------------------------------
int ver_data_nasc(int qtd_cadastros, cadastros *p){

    if(p[qtd_cadastros].data_nasc[0] < 0 || p[qtd_cadastros].data_nasc[0] > 30){
        printf("\nDia Invalido!\n");
        return n_find;
    }
    else if(p[qtd_cadastros].data_nasc[1] < 0 || p[qtd_cadastros].data_nasc[1] > 12){
        printf("\nMes Invalido!\n");
        return n_find;
    }
    else if(p[qtd_cadastros].data_nasc[1] < 0 || p[qtd_cadastros].data_nasc[2] > 2023){
        printf("\nAno Invalido!\n");
        return n_find;
    }
    else
    return find;
}

int ver_matricula(int qtd_cadastros, cadastros *p, cadastros d){
    int i;

    if(qtd_cadastros == 0){
        printf("\nNenhum Professor Listado!\n");
        return n_find;
    }
    
    for(i=0; i<qtd_cadastros; i++)
    {
        if(d.matricula == p[i].matricula){
            printf("\nProfessor %s cadastrado na disciplina com sucesso!", p[i].nome);
            return i;
        }
    }

    if(i == qtd_cadastros){
        printf("\nCadastro Inexistente!\n");
        return n_find;
    }
}

int ver_codigo_disc(int qtd_cadastros, disciplina *p, int lugar_do_codigo){
    int i, ctrl;

    for(i=0; i<qtd_cadastros; i++)
    {
        ctrl = strcmp(p[i].codigo, p[lugar_do_codigo].codigo);

        if(ctrl == 0 && i != lugar_do_codigo){
            printf("\nCodigo Ja Existente!\n");
            return n_find;
        }
    }

    if(i == qtd_cadastros)
        return find;
}

//-------------- Atualizações ------------------------------------------------
int update(int qtd_cadastros, cadastros *p){
    int matricula, i;
    char confirm;

    if(qtd_cadastros == 0){
        printf("\nNenhuma Matricula Listada!\n");
        return n_find;
    }

    printf("Matricula a ser atualizada: ");
    scanf("%d", &matricula);
    getchar();

    for(i=0; i<qtd_cadastros; i++){
        if(p[i].matricula == matricula){
            print_cadastros(i, p);
            break;
        }
        if(i+1 == qtd_cadastros){
            printf("\nMatricula nao Encontrada!\n");
            return n_find;
        }
    }

    printf("Continuar Update (S-sim / N-nao): ");
    scanf(" %c", &confirm);
    getchar();
    confirm = toupper(confirm);

    if(confirm == 'S')
        return i;
    else
    {
        printf("\nUpdate Cancelado!\n");
        return n_find;
    }
}

int update_disciplina(int qtd_disciplinas, disciplina *p){
    int i, ctrl;
    char confirm, codigo[Range_codigo];

    if(qtd_disciplinas == 0){
        printf("\nNenhuma Disciplina Listada!\n");
        return n_find;
    }

    printf("Codigo a ser atualizado: ");
    fgets(codigo, Range_codigo, stdin);
        remove_fgets(codigo);

    for(i=0; i<qtd_disciplinas; i++)
    {
        ctrl = strcmp(codigo, p[i].codigo);

        if(ctrl == 0){
            printf("\nDisciplina encontrada\n\n");
            print_disciplinas(i, p);
            break;
        }
        if(i+1 == qtd_disciplinas){
            printf("\nDisciplina nao Encontrada!\n");
            return n_find;
        }
    }

    printf("\nContinuar Update (S-sim / N-nao): ");
    scanf(" %c", &confirm);
    getchar();
    confirm = toupper(confirm);

    if(confirm == 'S')
        return i;
    else
    {
        printf("\nUpdate Cancelado!\n");
        return n_find;
    }
}
//--------------- Cadastros --------------------------------------------------

int cad_matricula(int qtd_cadastros, cadastros *p){
    int matricula=-1, i;

    printf("Matricula: ");
    scanf("%d", &matricula); 
    //limpa buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    for(i=0; i<qtd_cadastros; i++){
        if(p[i].matricula == matricula){
            printf("\nMatricula Ja Existente!\n");
            return n_find;
        }
    }

    if(matricula <= 0){
        printf("\nMatricula invalida!\n");
        return n_find;
    }
    else
        return matricula;
}

char cad_sexo(){
    char sexo;

    printf("Sexo (F ou M): ");
    scanf(" %c", &sexo); limpa_buffer();

        if(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f'){
            printf("\nOpcao invalida!\n\n");
            return n_find;
        }
        if(sexo > 98 && sexo < 123)
        sexo -= 32;

        return sexo;
}

int ver_cpf(int qtd_cadastros, cadastros *p){
    int ctrl, i;

    ctrl = strlen(p[qtd_cadastros].cpf);
        if(ctrl != 14){
            printf("\nCPF Invalido!\n");
            return n_find;
        }
            

    //verificando o padrão xxx.xxx.xxx-xx
    for(i=0; p[qtd_cadastros].cpf[i] != '\0'; i++){

        switch (i)
        {
        case 3:
            if(p[qtd_cadastros].cpf[i] != '.'){
                printf("\nCPF Invalido!\n");
                return n_find;
            }
            break;

        case 7:
            if(p[qtd_cadastros].cpf[i] != '.'){
                printf("\nCPF Invalido!\n");
                return n_find;
            }
            break;

        case 11:
            if(p[qtd_cadastros].cpf[i] != '-'){
                printf("\nCPF Invalido!\n");
                return n_find;
            }
            break;

        default:
            if(p[qtd_cadastros].cpf[i] < '0' || p[qtd_cadastros].cpf[i] > '9'){
                printf("\nCPF Invalido!\n");
                return n_find;
            }
            break;
        }
    }

    return find;
}

int matricula_al_disc(int qtd_disciplinas, int qtd_cadastros, disciplina *p, cadastros *a)
{
    char codigo[Range_codigo];
    int i, ctrl, j, n_efetuada=0, qtd;

    if(qtd_disciplinas == 0){
        printf("\nNenhuma Disciplina Listada!\n");
        return n_find;
    }
    else if(qtd_cadastros == 0){
        printf("\nNenhum Aluno Existente!\n");
        return n_find;
    }
    else
    {
        printf("Digite o codigo da disciplina: ");
        fgets(codigo, Range_codigo, stdin);
            remove_fgets(codigo);

        for(i=0; i<qtd_disciplinas; i++)
        {
            ctrl = strcmp(codigo, p[i].codigo);

            if(ctrl == 0){
                printf("\n---------------------------\n");
                printf("\tDisicplina\n");
                printf("\nNome: %s\n", p[i].nome);
                print_disciplinas(i, p);

                ctrl = i;
                i = -1;
                break;
            }
        }

        if(i != -1){
            printf("\nDisciplina nao Encontrada!\n");
            return n_find;
        }
        else if(p[ctrl].qtd_alunos >= Max_cad_disc){
            printf("\nDisciplina Sem Vagas!\n");
            return n_find;
        }
        else
        {
            printf("\nNumero de Alunos a Cadastrar: ");
            scanf("%d", &qtd); getchar();

            for(i=0; i<qtd; i++)
            {
                printf("\nMatricula: ");
                scanf("%d", &p[ctrl].matriculas_alu[p[ctrl].qtd_alunos]); getchar();

                //Procurando se o aluno já esta matriculado
                for(j=0; j<p[ctrl].qtd_alunos; j++)
                {
                    if(p[ctrl].matriculas_alu[p[ctrl].qtd_alunos] == p[ctrl].matriculas_alu[j]) {
                        printf("Aluno Ja Cadastrado!\n");
                        j = n_find;
                        break;
                    }
                }
                if(j == n_find){
                    n_efetuada++;
                    continue;
                }

                //Procurando o Cadastro do aluno
                for(j=0; j<qtd_cadastros; j++)
                {
                    if(p[ctrl].matriculas_alu[p[ctrl].qtd_alunos] == a[j].matricula){
                        p[ctrl].qtd_alunos++;
                        break;
                    }
                    else if(j+1 == qtd_cadastros){
                        printf("Aluno nao Encontrado!\n");
                        n_efetuada++;
                    }
                }
            }

            if(n_efetuada == qtd)
                printf("\nNenhuma Matricula Foi Efetuada!\n");
            // else
            // {
            //     printf("\nMatriculas Efetuadas!\n");
            //     p[ctrl].qtd_alunos -= n_efetuada;
            //     return find;
            // }
        }
    }
    return n_find;
}

//--------------- Exclusão -----------------------------------------------

int cad_delete(int qtd_cadastros, cadastros *p){
    int i, j, matricula;

    printf("\n------ Exlcuir Aluno ------\n\n");
    if(qtd_cadastros == 0){
        printf("Nenhuma Matricula Listada!\n");
        return n_find;
    }

    printf("Digite a matricula (0 - voltar): ");
    scanf("%d", &matricula); getchar();

    if(matricula == 0)
        return n_find;

    for(i=0; i<qtd_cadastros; i++){
        if(matricula == p[i].matricula){
            for(j=i; j<qtd_cadastros; j++){
                p[j].sexo = p[j+1].sexo;
                strcpy(p[j].nome, p[j+1].nome);
                strcpy(p[j].cpf, p[j+1].cpf);
                p[j].matricula = p[j+1].matricula;
                p[j].data_nasc[0] = p[j+1].data_nasc[0];
                p[j].data_nasc[1] = p[j+1].data_nasc[1];
                p[j].data_nasc[2] = p[j+1].data_nasc[2];
            }
            printf("\nMatricula Finalizada com Sucesso!\n");
            break;
        }
        //se chegou nessa condicional e não há próximo na lista
        //a matricula não foi encontrada
        if(qtd_cadastros-1 == i){
            printf("\nMatricula inexistente!\n");
            return n_find;
        }
    }

    return find;
}

int disc_delete(int qtd_cadastros, disciplina *p){
    int i, j, ctrl;
    char codigo[Range_codigo];

    printf("\n---- Exlcuir Disciplina ----\n\n");
    if(qtd_cadastros == 0){
        printf("Nenhuma Disciplina Listada!\n");
        return n_find;
    }

    printf("Digite o codigo (0 - voltar): ");
    fgets(codigo, Range_codigo, stdin);
        remove_fgets(codigo);

    if(codigo[0] == '0')
        return n_find;

    for(i=0; i<qtd_cadastros; i++){

        ctrl = strcmp(codigo, p[i].codigo);

        if(ctrl ==0){
            for(j=i; j<qtd_cadastros; j++)
            {
                strcpy(p[j].nome, p[j+1].nome);
                strcpy(p[j].codigo, p[j+1].codigo);
                p[j].semestre = p[j+1].semestre;
                p[j].matricula_prof = p[j+1].matricula_prof;
                strcpy(p[j].nome_prof, p[j+1].nome_prof);
            }
            printf("\nDisciplina Finalizada com Sucesso!\n");
            return find;
        }
        //se chegou nessa condicional e não há próximo na lista
        //a disciplina não foi encontrada
        if(qtd_cadastros-1 == i){
            printf("\nDisciplina inexistente!\n");
            return n_find;
        }
    }
}

void delete_matricula_disc(int qtd_cadastros, int qtd_disc, cadastros *p, disciplina *d){
    int i, j, c, aux, qtd, x;
    char codigo[Range_codigo];

    printf("Codigo da disciplina: ");
    fgets(codigo, Range_codigo, stdin);
        remove_fgets(codigo);

//Buscando A Disciplina
    for(i=0; i<qtd_disc; i++)
    {
        aux = strcmp(codigo, d[i].codigo);
        if(aux == 0)
        {
            printf("\n\t%s\n\n", d[i].nome);

            for(j=0; j<d[i].qtd_alunos; j++)
                for(c=0; c<qtd_cadastros; c++)
                {
                    if(d[i].matriculas_alu[j] == p[c].matricula){
                        printf("Aluno: %s\n", p[c].nome);
                        printf("Matricula: %d\n\n", p[c].matricula);
                        break;
                    }
                }   

            aux = i;
            break;    
        }
        if(i+1 == qtd_disc){
            printf("\nDisciplina Nao Encontrada!\n");
            return;
        }
    }

    printf("Quantidade de Matriculas a Cancelar: ");
    scanf("%d", &qtd); getchar();

    for(i=0; i<qtd; i++)
    {
        printf("\nMatricula: ");
        scanf("%d", &c); getchar();

        for(j=0; j<d[aux].qtd_alunos; j++)
        {
            if(d[aux].matriculas_alu[j] == c)
            {
                for(x=j; x<d[aux].qtd_alunos-1; x++)
                    d[aux].matriculas_alu[x] = d[aux].matriculas_alu[x+1];
                
                //J-- por causa do shift do vetor
                j--; 
                d[aux].qtd_alunos--;
                printf("Matricula Encerrada Com Sucesso!\n");
                break;
            }
            if(j+1 == d[aux].qtd_alunos)
                printf("Matricula Nao Encontrada!\n");
        }

    }
}

//---------------- Listas ------------------------------------------------

void list_geral(int qtd_cadastros, cadastros *p){
    int i;


    if(qtd_cadastros == 0){
        printf("\tNenhuma Matricula Listada!\n");
        return;
    }

    printf("---------------- Listar Cadastros ------------------\n\n");

    for(i=0; i < qtd_cadastros; i++){
        print_cadastros(i, p);
    }
    printf("----------------------------------------------------\n\n");
}

void list_sexo(int qtd_cadastros, cadastros *p){
    char s;
    int i, j;

    if(qtd_cadastros == 0){
        printf("\tNenhuma Matricula Listada!\n");
        return;
    }

    printf("Digite o sexo(F / M): ");
    scanf(" %c", &s);
    s = toupper(s);
    printf("-------------------- Sexo: %c ----------------------\n\n", s);

    for(i=0, j=0; i < qtd_cadastros; i++){
        if(p[i].sexo == s){
            print_cadastros(i, p);
            j++;
        }
    }

    if(j == 0)
        printf("\tNenhuma Matricula Encontrada!\n\n");

    printf("----------------------------------------------------\n\n");
}

void list_nome(int qtd_cadastros, cadastros *p){
    char src_nome[Max];
    int i, j, ctrl;
    int c;

    if(qtd_cadastros == 0){
        printf("\tNenhuma Matricula Listada!\n");
        return;
    }

    printf("Parte do Nome: ");
    fgets(src_nome, Max, stdin);
        remove_fgets(src_nome);

    printf("\n-------------- Listar Parte Do Nome ----------------\n\n");
    for(i=0, c=0; i<qtd_cadastros; i++)
    {

        for(j=0, ctrl=0; p[i].nome[j] != '\0'; j++)
        {
            if(p[i].nome[j] == src_nome[ctrl])
            {
                ctrl++;
                if(src_nome[ctrl] == '\0'){
                    ctrl= -1;
                    break;
                }
            }

        }

        if(ctrl == -1){
            print_cadastros(i, p);
            c++;
            continue;
        }
    }

    if(c == 0)
        printf("\tBusca Nao Encontrada!\n\n");

    printf("----------------------------------------------------\n\n");
}

void search_cad(int qtd_cadastros, cadastros *p){
    int i, matricula;

    if(qtd_cadastros == 0){
        printf("\tNenhum Cadastro Listado!\n");
        return;
    }

    printf("Digite a Matricula: ");
    scanf("%d", &matricula); getchar();

    printf("\n----------------- Buscar Cadastro ------------------\n\n");

    for(i=0; i<qtd_cadastros; i++){
        if(p[i].matricula == matricula){
            print_cadastros(i, p);
            return;
        }
    }

        if(qtd_cadastros == i)
            printf("\tMatricula inexistente!\n\n");

    printf("----------------------------------------------------\n\n");

}

void list_data_nasc(int qtd_cadastros, cadastros *p){
    cadastros aux[qtd_cadastros], ctrl;
    int i, c;

    if(qtd_cadastros == 0){
        printf("\tNenhuma Matricula Listada!\n");
        return;
    }

    printf("--------------- Data de Nascimento -----------------\n\n");
    
    for(i=0; i < qtd_cadastros; i++)
        aux[i] = p[i];
    

    for(c=0; c < qtd_cadastros-1; c++)
    {
        for(i=1; i < qtd_cadastros; i++)
        {
            if(aux[i].data_nasc[2] < aux[i-1].data_nasc[2]){
                ctrl = aux[i];
                aux[i] = aux[i-1];
                aux[i-1] = ctrl;
            }
            else if(aux[i].data_nasc[2] == aux[i-1].data_nasc[2])
            {
                if(aux[i].data_nasc[1] < aux[i-1].data_nasc[1]){
                    ctrl = aux[i];
                    aux[i] = aux[i-1];
                    aux[i-1] = ctrl;
                }
                else if(aux[i].data_nasc[1] == aux[i-1].data_nasc[1])
                {
                    if(aux[i].data_nasc[0] < aux[i-1].data_nasc[0]){
                        ctrl = aux[i];
                        aux[i] = aux[i-1];
                        aux[i-1] = ctrl;    
                    }
                }
            }
        }
    }

    for (i=0; i < qtd_cadastros; i++)
    {
      print_cadastros(i, aux);
    }

    printf("----------------------------------------------------\n\n");
}

void list_geral_disc(int qtd_cadastros, disciplina *p, int opcao){
    int i, ctrl;

    if(qtd_cadastros == 0){
        printf("\tNenhuma Disciplina Listada!\n");
        return;
    }

    if(opcao == 1)
        printf("---------------- Listar Disciplinas ----------------\n\n");
    else
        printf("------------- Disciplinas Sem Professor ------------\n\n");

    if(opcao == 1)
    {
        for(i=0; i < qtd_cadastros; i++)
        {
            print_disciplinas(i, p);
            printf("Quantidade de Alunos: %d\n", p[i].qtd_alunos);
        }
    }
    else
    {
        for(i=0, ctrl=0; i < qtd_cadastros; i++)
        {
            if(p[i].matricula_prof == n_find)
            {
                print_disciplinas(i, p);
                printf("Quantidade de Alunos: %d\n", p[i].qtd_alunos);
                ctrl++;
            }

        }
        if(!ctrl)
            printf("\tNenhuma Disciplina Sem Professor Encontrada!\n\n");
    }
    printf("----------------------------------------------------\n\n");
}

void list_alu_disc(int qtd_disc, disciplina *p, int qtd_aln, cadastros *a){
    int i, ctrl, j;
    char codigo[Range_codigo];

    if(qtd_disc == 0){
        printf("\tNenhuma Disciplina Cadastrada!\n");
        return;
    }
    else if(qtd_aln == 0){
        printf("\tNenhuma Aluno Existente!\n");
        return;
    }
    else{
        printf("Codigo da Disciplina: ");
        fgets(codigo, Range_codigo, stdin);
            remove_fgets(codigo);

        printf("\n------------------ Listar Alunos --------------------\n");

        for(i=0; i<qtd_disc; i++){
            ctrl = strcmp(codigo, p[i].codigo);

            if(ctrl == 0){
                ctrl = i;
                break;
            }
            else if(i+1 == qtd_disc){
                printf("\tDisciplina nao Encontrada!\n");
                return;
            }
        }

        if(p[ctrl].qtd_alunos == 0){
            printf("\tNenhum Aluno Cadastrado Na Disciplina!\n");
            return;
        }
        else
        {
            for(i=0; i<p[ctrl].qtd_alunos; i++)
            {
                for(j=0; j<qtd_aln; j++)
                {
                    if(p[ctrl].matriculas_alu[i] == a[j].matricula){
                        printf("\t  Nome: %s\n", a[j].nome);
                        printf("\t  Matricula: %d\n\n", a[j].matricula);
                    }
                }
            }
        }
    }
    printf("----------------------------------------------------\n\n");
}

void list_qtd_al_disc(int qtd_disc, disciplina *p){
    char codigo[Range_codigo];
    int i, ctrl, vet[qtd_disc];

    if(qtd_disc == 0){
        printf("\tNenhuma Disciplina Cadastrada!\n");
        return;
    }
    else
    {
        printf("Codigo da Disciplina: ");
        fgets(codigo, Range_codigo, stdin);
            remove_fgets(codigo);

        printf("\n--------------- Quantidade de Alunos ----------------\n\n");

        for(i=0; i<qtd_disc; i++){
            ctrl = strcmp(codigo, p[i].codigo);

            if(ctrl == 0){
                ctrl = i;
                break;
            }
        }

        if(i == qtd_disc)
            printf("\tDisciplina nao Encontrada!\n\n");
        else
            printf("\tQuantidade de Alunos: %d\n\n", p[ctrl].qtd_alunos);
        
        printf("----------------------------------------------------\n\n");
    }

}

void list_disc_semestre(int qtd_disc, disciplina *p){
    int i, opcao, ctrl;
    disciplina aux[Max_cadastros], key;

    while(0==0)
    {
        printf("------- Listar Por Semestre --------\n\n");
        printf("0 - Voltar\n");
        printf("1 - Ordem de Semestre\n");
        printf("2 - Inserir Semestre\n");
        printf("\n--> ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 0:
                return;
                break;
            case 1:
                printf("----------------- Lista Semestres ------------------\n\n");

                //Copiando o Vetor de Disciplina para Ordenar
                for(i=0; i<qtd_disc; i++){
                    strcpy(aux[i].codigo, p[i].codigo);
                    aux[i].semestre = p[i].semestre; 
                }

                int j;
                for(i=0; i<qtd_disc; i++){
                    key.semestre = aux[i].semestre; 
                    strcpy(key.codigo, aux[i].codigo);
                    j = i-1;

                    while(j>=0 && aux[j].semestre>key.semestre){
                        strcpy(aux[j+1].codigo, aux[j].codigo);
                        aux[j+1].semestre = aux[j].semestre; 
                        j--;
                    }

                    strcpy(aux[j+1].codigo, key.codigo);
                    aux[j+1].semestre = key.semestre; ;
                }

                for (i=0; i<qtd_disc; i++)
                {
                    for(j=0; j<qtd_disc; j++)
                    {
                        ctrl = strcmp(aux[i].codigo, p[j].codigo);

                        if(ctrl == 0)
                        {
                            print_disciplinas(j, p);
                            break;
                        }
                    }
                }
            break;

            case 2:
                printf("Digite o Semestre: ");
                scanf("%d", &opcao); getchar();
                printf("\n----------------- Lista Semestres ------------------\n\n");

                for(i=0, ctrl=0; i<qtd_disc; i++){
                    if(p[i].semestre == opcao){
                        print_disciplinas(i, p);
                        ctrl++;
                    }
                }

                if(ctrl == 0){
                    printf("\tNenhuma Disciplina Encontrada!\n\n");
                }
            break;

            default:
                printf("\tValor Invalido!\n\n");
        }
        printf("----------------------------------------------------\n\n");
    }
}

void search_disc(int qtd_disciplinas, disciplina *p){
    int i, ctrl;
    char codigo[Range_codigo];

    printf("Digite o Codigo: ");
    fgets(codigo, Range_codigo, stdin);
        remove_fgets(codigo);

    printf("\n-------------------- Buscar ------------------------\n\n");

    for(i=0; i<qtd_disciplinas; i++)
    {
        ctrl = strcmp(codigo, p[i].codigo);

        if(ctrl == 0)
        {
          print_disciplinas(i, p);
          break;
        }
        if(i+1 == qtd_disciplinas)
          printf("\tDisciplina Nao Encontrada!\n\n");
    }

    printf("----------------------------------------------------\n\n");
}

void list_nome_disc(int qtd_disciplinas, disciplina *p){
    char src_nome[Max];
    int i, j, ctrl;
    int c;

    if(qtd_disciplinas == 0){
        printf("\tNenhuma Disciplina Listada!\n");
        return;
    }

    printf("Parte do Nome: ");
    fgets(src_nome, Max, stdin);
        remove_fgets(src_nome);

    printf("\n-------------- Listar Parte Do Nome ----------------\n\n");

    for(i=0, c=0; i<qtd_disciplinas; i++)
    {

        for(j=0, ctrl=0; p[i].nome[j] != '\0'; j++)
        {
            if(p[i].nome[j] == src_nome[ctrl])
            {
                ctrl++;
                if(src_nome[ctrl] == '\0'){
                    ctrl= -1;
                    break;
                }
            }

        }

        if(ctrl == -1){
          print_disciplinas(i, p);
          c++;
          continue;
        }
    }

    if(c == 0)
        printf("\tBusca Nao Encontrada!\n\n");

    printf("----------------------------------------------------\n\n");
}

void list_alphabet(int qtd_cadastros, cadastros *p, disciplina *d, int qtd_disc, int opcao){
    int i, j, x, menor;
    cadastros aux[qtd_cadastros];
    char sup[Max];

    printf("\n------------- Lista Ordem Alfabetica --------------\n\n");

    if(opcao == 3)
    {
      if(qtd_disc == 0){
          printf("\tNenhuma Disciplina Cadastrada!\n");
          return;
      }

      for(i=0; i<qtd_disc; i++)
          strcpy(aux[i].nome, d[i].nome);
      
      

      for(i = 0; i < qtd_disc - 1; i++)
      {
          x = 0;
          menor = i;
          for(j = i + 1; j < qtd_disc; j++)
          {
              x = 0;
              while(aux[menor].nome[x] == aux[j].nome[x])
                  x++;

              if(aux[menor].nome[x] > aux[j].nome[x])
                  menor = j;

          }
          if(menor != i)
          {
              strcpy(sup, aux[menor].nome);
              strcpy(aux[menor].nome, aux[i].nome);
              strcpy(aux[i].nome, sup);
          }
      }

      for(i=0; i<qtd_disc; i++)
      {
          for(j=0; j<qtd_disc; j++)
          {
            x = strcmp(aux[i].nome, d[j].nome);

            if(x == 0)
              print_disciplinas(j, d);
          }
      }
  }

  else
  {
      if(qtd_cadastros == 0){
          printf("\tNenhuma Matricula Cadastrada!\n");
          return;
      }

      for(i=0; i<qtd_cadastros; i++){
          aux[i].matricula = p[i].matricula;
          strcpy(aux[i].nome, p[i].nome);
      }

      for(i = 0; i < qtd_cadastros - 1; i++)
      {
          x = 0;
          menor = i;
          for(j = i + 1; j < qtd_cadastros; j++)
          {
              x = 0;
              while(aux[menor].nome[x] == aux[j].nome[x])
                  x++;

              if(aux[menor].nome[x] > aux[j].nome[x])
                  menor = j;

          }
          if(menor != i)
          {
              strcpy(sup, aux[menor].nome);
              strcpy(aux[menor].nome, aux[i].nome);
              strcpy(aux[i].nome, sup);
              x = aux[menor].matricula;
              aux[menor].matricula = aux[i].matricula;
              aux[i].matricula = x;
          }
      }

      for(i=0; i<qtd_cadastros; i++)
      {
          for(j=0; j<qtd_cadastros; j++)
          {
            if(aux[i].matricula == p[j].matricula)
              print_cadastros(j, p);              
          }
      }
    }

    printf("----------------------------------------------------\n\n");
}

void list_qtd_disc(int qtd_aluno, int qtd_disc, cadastros *p, disciplina *d){
    int i, j, x, ctrl[2], qtd;

    printf("Quantidade de Disciplinas: ");
    scanf("%d", &qtd); getchar();

    printf("\n------------- Menos de %d Disciplinas --------------\n\n", qtd);

    for(i=0, ctrl[1]=0; i<qtd_aluno; i++)
    {
        for(j=0, ctrl[0]=0; j<qtd_disc; j++)
            for(x=0; x<d[j].qtd_alunos; x++)
                if(p[i].matricula == d[j].matriculas_alu[x])
                    ctrl[0]++;

        if(ctrl[0] < qtd)
        {
            printf("\t  Nome: %s\n", p[i].nome);
            printf("\t  CPF: %s\n", p[i].cpf);
            printf("\t  Matricula: %d\n", p[i].matricula);
            printf("\t  Quantidade de Materias: %d\n\n", ctrl[0]);

        ctrl[1]++;
        }
    }

    if(ctrl[1] == 0)
        printf("\tNenhum Aluno encontrado!\n");

    printf("\n----------------------------------------------------\n\n");
}

void list_prof_sem_disc(int qtd_prof, int qtd_disc, cadastros *p, disciplina *d){
    int i, j, ctrl, x;

    printf("\n--------- Professsores Sem Disciplinas ------------\n\n");

    for(i=0, ctrl=0; i<qtd_prof; i++)
    {
        for(j=0, x=0; j<qtd_disc; j++)
            if(p[i].matricula == d[j].matricula_prof)
                x++;

        if(x == 0){
            printf("\t  Nome: %s\n", p[i].nome);
            printf("\t  CPF: %s\n", p[i].cpf);
            printf("\t  Matricula: %d\n\n", p[i].matricula);
            ctrl++;
        }
    }

    if(ctrl == 0)
        printf("\tNenhum Professor encontrado!\n");
    
    printf("\n----------------------------------------------------\n\n");
}