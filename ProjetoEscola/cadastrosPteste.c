#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions/functions.h"

int alunos_lista_teste(int qtd_cadastros, cadastros *p){
    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 1;
    p[qtd_cadastros].data_nasc[0] = 12;
    p[qtd_cadastros].data_nasc[1] = 4;
    p[qtd_cadastros].data_nasc[2] = 2000;
    strcpy(p[qtd_cadastros].nome, "Isa");
    strcpy(p[qtd_cadastros].cpf, "321.412.412-41");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 2;
    p[qtd_cadastros].data_nasc[0] = 1;
    p[qtd_cadastros].data_nasc[1] = 6;
    p[qtd_cadastros].data_nasc[2] = 1990;
    strcpy(p[qtd_cadastros].nome, "Anna");
    strcpy(p[qtd_cadastros].cpf, "751.412.461-11");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 3;
    p[qtd_cadastros].data_nasc[0] = 8;
    p[qtd_cadastros].data_nasc[1] = 7;
    p[qtd_cadastros].data_nasc[2] = 2005;
    strcpy(p[qtd_cadastros].nome, "Deivison");
    strcpy(p[qtd_cadastros].cpf, "281.613.451-71");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 4;
    p[qtd_cadastros].data_nasc[0] = 18;
    p[qtd_cadastros].data_nasc[1] = 10;
    p[qtd_cadastros].data_nasc[2] = 2006;
    strcpy(p[qtd_cadastros].nome, "Maria");
    strcpy(p[qtd_cadastros].cpf, "712.822.156-91");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 5;
    p[qtd_cadastros].data_nasc[0] = 10;
    p[qtd_cadastros].data_nasc[1] = 2;
    p[qtd_cadastros].data_nasc[2] = 2010;
    strcpy(p[qtd_cadastros].nome, "Pedro");
    strcpy(p[qtd_cadastros].cpf, "821.982.733-27");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 6;
    p[qtd_cadastros].data_nasc[0] = 26;
    p[qtd_cadastros].data_nasc[1] = 5;
    p[qtd_cadastros].data_nasc[2] = 1991;
    strcpy(p[qtd_cadastros].nome, "Joao");
    strcpy(p[qtd_cadastros].cpf, "573.813.158-26");
    qtd_cadastros++;

    return qtd_cadastros;
}

int professor_lista_teste(int qtd_cadastros, cadastros *p){
    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 1;
    p[qtd_cadastros].data_nasc[0] = 6;
    p[qtd_cadastros].data_nasc[1] = 12;
    p[qtd_cadastros].data_nasc[2] = 1980;
    strcpy(p[qtd_cadastros].nome, "Julia");
    strcpy(p[qtd_cadastros].cpf, "321.412.412-41");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 2;
    p[qtd_cadastros].data_nasc[0] = 6;
    p[qtd_cadastros].data_nasc[1] = 1;
    p[qtd_cadastros].data_nasc[2] = 1990;
    strcpy(p[qtd_cadastros].nome, "Simone");
    strcpy(p[qtd_cadastros].cpf, "751.412.461-11");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 3;
    p[qtd_cadastros].data_nasc[0] = 6;
    p[qtd_cadastros].data_nasc[1] = 1;
    p[qtd_cadastros].data_nasc[2] = 1463;
    strcpy(p[qtd_cadastros].nome, "Jonas");
    strcpy(p[qtd_cadastros].cpf, "281.613.451-71");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'F';
    p[qtd_cadastros].matricula = 4;
    p[qtd_cadastros].data_nasc[0] = 18;
    p[qtd_cadastros].data_nasc[1] = 4;
    p[qtd_cadastros].data_nasc[2] = 1474;
    strcpy(p[qtd_cadastros].nome, "Bruna");
    strcpy(p[qtd_cadastros].cpf, "712.822.156-91");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 5;
    p[qtd_cadastros].data_nasc[0] = 18;
    p[qtd_cadastros].data_nasc[1] = 6;
    p[qtd_cadastros].data_nasc[2] = 2015;
    strcpy(p[qtd_cadastros].nome, "Erick");
    strcpy(p[qtd_cadastros].cpf, "821.982.733-27");
    qtd_cadastros++;

    p[qtd_cadastros].sexo = 'M';
    p[qtd_cadastros].matricula = 6;
    p[qtd_cadastros].data_nasc[0] = 7;
    p[qtd_cadastros].data_nasc[1] = 9;
    p[qtd_cadastros].data_nasc[2] = 1824;
    strcpy(p[qtd_cadastros].nome, "Mark");
    strcpy(p[qtd_cadastros].cpf, "573.813.158-26");
    qtd_cadastros++;

    return qtd_cadastros;
}

int disciplina_lista_teste(int qtd_disc, disciplina *p){
    p[qtd_disc].semestre = 2; 
    p[qtd_disc].qtd_alunos = 2;
    p[qtd_disc].matricula_prof = 3; 
    p[qtd_disc].matriculas_alu[0] = 1;
    p[qtd_disc].matriculas_alu[1] = 4;
    strcpy(p[qtd_disc].codigo, "INF006");
    strcpy(p[qtd_disc].nome, "Estrutura de Dados");
    strcpy(p[qtd_disc].nome_prof, "Professor de Dados");
    qtd_disc++;

    p[qtd_disc].semestre = 1; 
    p[qtd_disc].qtd_alunos = 2;
    p[qtd_disc].matricula_prof = 4; 
    p[qtd_disc].matriculas_alu[0] = 2;
    p[qtd_disc].matriculas_alu[1] = 5;
    strcpy(p[qtd_disc].codigo, "INF031");
    strcpy(p[qtd_disc].nome, "Software");
    strcpy(p[qtd_disc].nome_prof, "Professor de Software");
    qtd_disc++;

    p[qtd_disc].semestre = 1; 
    p[qtd_disc].qtd_alunos = 5;
    p[qtd_disc].matricula_prof = 5; 
    p[qtd_disc].matriculas_alu[0] = 3;
    p[qtd_disc].matriculas_alu[1] = 6;
    p[qtd_disc].matriculas_alu[2] = 5;
    p[qtd_disc].matriculas_alu[3] = 2;
    p[qtd_disc].matriculas_alu[4] = 1;
    strcpy(p[qtd_disc].codigo, "MAT");
    strcpy(p[qtd_disc].nome, "Matematica");
    strcpy(p[qtd_disc].nome_prof, "Professor de Matematica");
    qtd_disc++;

    return qtd_disc;
}