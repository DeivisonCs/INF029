/*
  gcc main.c functions/functions.c cadastrosPteste.c -o teste
  
  ./teste
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions/functions.h"

int main(){
    disciplina disc[Max_cadastros];
    cadastros alu[Max_cadastros], prof[Max_cadastros], aux;
    int qtd_alunos=0, qtd_professores=0, qtd_disc=0;  //controladores de quantidade
    int opcao, opcao_menu, sair=0;  //controladores de menu 
    int ctrl, i;  char sup[Max];  //variáveis de controle

//Zerando Numero de Alunos nas Disciplinas
zerar_cadastros_disciplina(disc);

//Cadastros Para Testes
qtd_alunos = alunos_lista_teste(qtd_alunos, alu);
qtd_professores = professor_lista_teste(qtd_professores, prof);
qtd_disc = disciplina_lista_teste(qtd_disc, disc);

while(!sair){
  opcao_menu = menu();

  switch (opcao_menu)
  {
  case 0:
      sair = 1;
      break;

//MENU ALUNOS
  case 1:
      while(!sair){
          opcao = menu_2(opcao_menu);

          if(opcao == 0)
              break;
          
          //CADASTRO ALUNO
          else if(opcao == 1){

              if(qtd_alunos >= Max_cadastros){
                  printf("\nLimite de Cadastros Atingido!\n");
                  continue;
              }
              else
              {
                  printf("------ Cadastro Matricula -----\n");

                  //CADASTRO NOME:
                  printf("Nome: ");
                  fgets(sup, Max, stdin);
                      remove_fgets(sup);
                      name_pattern(sup);
                      strcpy(alu[qtd_alunos].nome, sup);

                  //CADASTRO SEXO:
                  alu[qtd_alunos].sexo = cad_sexo();
                      if(alu[qtd_alunos].sexo == n_find)
                          continue;

                  //CADASTRO MATRICULA:
                  alu[qtd_alunos].matricula = cad_matricula(qtd_alunos, alu);
                      if(alu[qtd_alunos].matricula == n_find)
                          continue;

                  //CADASTRO CPF:
                  printf("CPF (xxx.xxx.xxx-xx): ");
                  scanf("%s", alu[qtd_alunos].cpf);
                  getchar();
                      ctrl = ver_cpf(qtd_alunos, alu);
                      if(ctrl == n_find)
                          continue;
                          
                      
                  //CADASTRO DATA DE NASCIMENTO:
                  printf("Data de Nascimento (xx/xx/xxxx): ");
                  scanf("%d/%d/%d", &alu[qtd_alunos].data_nasc[0], &alu[qtd_alunos].data_nasc[1], &alu[qtd_alunos].data_nasc[2]); 
                  getchar();
                      ctrl = ver_data_nasc(qtd_alunos, alu);
                      if (ctrl == n_find)
                          continue;
                      
                      
                      
                  qtd_alunos++;
                  printf("\nCadastro realizado!\n");
                  continue;
              }
          }

          //ATUALIZAR ALUNO
          else if(opcao == 2){

              while(!sair)
              {
                  opcao = menu_update();

                  switch (opcao)
                  {
                      //VOLTAR
                      case 0: 
                      break;

                      //ATUALIZAR NOME ALUNO
                      case 1:
                          ctrl = update(qtd_alunos, alu);

                          if(ctrl == n_find)
                              continue;
                          else
                          {
                              printf("Novo nome: ");
                              fgets(sup, Max, stdin);
                                  remove_fgets(sup);
                                  name_pattern(sup);
                                  strcpy(alu[ctrl].nome, sup);

                              printf("\nAtualizado Com Sucesso\n");
                          }
                      continue;

                      //ATUALIZAR SEXO ALUNO
                      case 2:
                          ctrl = update(qtd_alunos, alu);
                          
                          if(ctrl == n_find)
                              continue;
                          else
                          {
                              sup[0] = cad_sexo();
                                  if(sup[0] != n_find){
                                      alu[ctrl].sexo = sup[0];
                                      printf("\nAtualizado Com Sucesso\n");
                                  }
                          }

                      continue;

                      //ATUALIZAR CPF ALUNO
                      case 3:
                          ctrl = update(qtd_alunos, alu);

                              if(ctrl == n_find)
                                  continue;
                              else
                              {
                                  strcpy(sup, alu[ctrl].cpf); //Salvando cpf anterior
                                  printf("Novo CPF (xxx.xxx.xxx-xx): ");
                                  scanf("%s", alu[ctrl].cpf);
                                  getchar();
                                      i = ver_cpf(ctrl, alu);
                                      if(i == n_find)
                                          strcpy(alu[ctrl].cpf, sup);
                                      else
                                          printf("\nAtualizado Com Sucesso\n");
                              }
                      continue;

                      //ATUALIZAR MATRICULA ALUNO
                      case 4:
                          ctrl = update(qtd_alunos, alu);

                              if(ctrl == n_find)
                                  continue;
                              else
                              {
                                  aux.matricula = cad_matricula(qtd_alunos, alu);
                                  if(aux.matricula != n_find)
                                  {
                                      alu[ctrl].matricula = aux.matricula;
                                      printf("\nAtualizado Com Sucesso\n");
                                  }
                              }
                      continue;
                      
                      //ATUALIZAR DATA_NASC ALUNO
                      case 5:
                          ctrl = update(qtd_alunos, alu);

                          if(ctrl == n_find)
                                  continue;
                          else
                          {
                              printf("Nova Data de Nascimento (xx/xx/xxxx): ");
                              scanf("%d/%d/%d", &aux.data_nasc[0], &aux.data_nasc[1], &aux.data_nasc[2]); 
                              getchar();
                                  i = ver_data_nasc(ctrl, alu);
                                  if (i != n_find)
                                  {
                                      alu[ctrl].data_nasc[0] = aux.data_nasc[0];
                                      alu[ctrl].data_nasc[1] = aux.data_nasc[1];
                                      alu[ctrl].data_nasc[2] = aux.data_nasc[2];
                                      printf("\nAtualizado Com Sucesso\n");
                                  }
                          }
                      continue;
                          
                      default:
                          printf("\nValor invalido!\n");
                      continue;
                  }
                  break;
              }
          }

          //EXCLUSÃO ALUNO
          else if(opcao == 3){
  
              ctrl = cad_delete(qtd_alunos, alu);
                  if(ctrl == find)
                      qtd_alunos--;

          }

          //LISTAS ALUNOS
          else if(opcao == 4){
              while(!sair){
                  opcao = menu_lista(opcao_menu);

                  if(opcao == 0)
                      break;

                  else if(opcao == 1)
                      list_geral(qtd_alunos, alu);

                  else if(opcao == 2)
                      list_sexo(qtd_alunos, alu);

                  else if(opcao == 3)
                      list_nome(qtd_alunos, alu);

                  else if(opcao == 4)
                      list_alphabet(qtd_alunos, alu, disc, qtd_disc, opcao_menu);

                  else if(opcao == 5)
                      list_data_nasc(qtd_alunos, alu);

                  else if(opcao == 6)
                      list_qtd_disc(qtd_alunos, qtd_disc, alu, disc);

                  else
                      printf("Valor invalido!\n");

              }
          }

          //BUSCA ALUNO
          else if(opcao == 5)
          {
              if(qtd_alunos == 0){
                  printf("-----------------------------\n\n");
                  printf("Nenhum Aluno Cadastrado!\n");
                  continue;
              }
              else
                  search_cad(qtd_alunos, alu);

          }
          else{
              printf("\nValor invalido!\n");
          }
      }
  break;

//MENU PROFESSORES
  case 2:
      while(!sair)
      {
          opcao = menu_2(opcao_menu);

          if(opcao == 0)
              break;
          
          //CADASTRO PROFESSOR
          else if(opcao == 1)
          {
              if(qtd_professores >= Max_cadastros){
                  printf("\nLimite de Cadastros Atingido!\n");
                  continue;
              }
              else
              {
                  //CADASTRO NOME:
                  printf("------ Cadastro Matricula -----\n");
                  printf("Nome: ");
                  fgets(sup, Max, stdin);
                      //Remoção do '\n' da função fgets
                      remove_fgets(sup);
                      name_pattern(sup);
                      strcpy(prof[qtd_professores].nome, sup);

                  //CADASTRO SEXO:
                  prof[qtd_professores].sexo = cad_sexo();
                      if(prof[qtd_professores].sexo == n_find)
                          continue;

                  //CADASTRO MATRICULA:
                  prof[qtd_professores].matricula = cad_matricula(qtd_professores, prof);
                      if(prof[qtd_professores].matricula == n_find)
                          ;continue;

                  //CADASTRO CPF:
                  printf("CPF (xxx.xxx.xxx-xx): ");
                  scanf("%s", prof[qtd_professores].cpf);
                  getchar();
                      ctrl = ver_cpf(qtd_professores, prof);
                      if(ctrl == n_find)
                          continue;
                          
                      
                  //CADASTRO DATA DE NASCIMENTO:
                  printf("Data de Nascimento (xx/xx/xxxx): ");
                  scanf("%d/%d/%d", &prof[qtd_professores].data_nasc[0], &prof[qtd_professores].data_nasc[1], &prof[qtd_professores].data_nasc[2]); 
                  getchar();
                      ctrl = ver_data_nasc(qtd_professores, prof);
                      if (ctrl == n_find)
                          continue;
                      
                      
                      
                  qtd_professores++;
                  printf("\nCadastro realizado!\n");
                  continue;
              }
          }

          //ATUALIZAR PROFESSOR
          else if(opcao == 2){
              while(!sair)
              {
                  opcao = menu_update();

                  switch (opcao)
                  {
                      //VOLTAR
                      case 0: 
                          break;
                      break;

                      //ATUALIZAR NOME PROFESSOR
                      case 1:
                          ctrl = update(qtd_professores, prof);

                          if(ctrl == n_find)
                              continue;
                          else
                          {
                              printf("Novo nome: ");
                              fgets(sup, Max, stdin);
                                  remove_fgets(sup);
                                  name_pattern(sup);
                                  strcpy(prof[ctrl].nome, sup);

                              printf("\nAtualizado Com Sucesso\n");
                          }
                      continue;

                      //ATUALIZAR SEXO PROFESSOR
                      case 2:
                          ctrl = update(qtd_professores, prof);
                          
                          if(ctrl == n_find)
                              continue;
                          else
                          {
                              sup[0] = cad_sexo();
                                  if(sup[0] != n_find){
                                      prof[ctrl].sexo = sup[0];
                                      printf("\nAtualizado Com Sucesso\n");
                                  }
                          }

                      continue;

                      //ATUALIZAR CPF PROFESSOR
                      case 3:
                          ctrl = update(qtd_professores, prof);

                              if(ctrl == n_find)
                                  continue;
                              else
                              {
                                  strcpy(sup, prof[ctrl].cpf); //Salvando cpf anterior
                                  printf("Novo CPF (xxx.xxx.xxx-xx): ");
                                  scanf("%s", prof[ctrl].cpf);
                                  getchar();
                                      i = ver_cpf(ctrl, prof);
                                      if(i == n_find)
                                          strcpy(prof[ctrl].cpf, sup);
                                      else
                                          printf("\nAtualizado Com Sucesso\n");
                              }
                      continue;

                      //ATUALIZAR MATRICULA PROFESSOR
                      case 4:
                          ctrl = update(qtd_professores, prof);

                              if(ctrl == n_find)
                                  continue;
                              else
                              {
                                  aux.matricula = cad_matricula(qtd_professores, prof);
                                  if(aux.matricula != n_find)
                                  {
                                      prof[ctrl].matricula = aux.matricula;
                                      printf("\nAtualizado Com Sucesso!\n");
                                  }
                              }
                      continue;
                      
                      //ATUALIZAR DATA_NASC PROFESSOR
                      case 5:
                          ctrl = update(qtd_professores, prof);

                          if(ctrl == n_find)
                                  continue;
                          else
                          {
                              printf("Nova Data de Nascimento (xx/xx/xxxx): ");
                              scanf("%d/%d/%d", &aux.data_nasc[0], &aux.data_nasc[1], &aux.data_nasc[2]); 
                              getchar();
                                  i = ver_data_nasc(ctrl, prof);
                                  if (i != n_find)
                                  {
                                      prof[ctrl].data_nasc[0] = aux.data_nasc[0];
                                      prof[ctrl].data_nasc[1] = aux.data_nasc[1];
                                      prof[ctrl].data_nasc[2] = aux.data_nasc[2];
                                      printf("\nAtualizado Com Sucesso!\n");
                                  }
                          }
                      continue;
                          
                      default:
                          printf("\nValor invalido!\n");
                      continue;
                  }
                  break;
              }
          }

          //EXCLUSÃO PROFESSOR
          else if(opcao == 3){
  
              ctrl = cad_delete(qtd_professores, prof);
                  if(ctrl == find)
                      qtd_professores--;

          }

          //LISTAS PROFESSOR
          else if(opcao == 4){
              while(!sair){
                  opcao = menu_lista(opcao_menu);

                  if(opcao == 0)
                      break;
                  else if(opcao == 1)
                      list_geral(qtd_professores, prof);

                  else if(opcao == 2)
                      list_sexo(qtd_professores, prof);

                  else if(opcao == 3)   
                      list_nome(qtd_professores, prof);

                  else if(opcao == 4)   
                      list_alphabet(qtd_professores, prof, disc, qtd_disc, opcao_menu);

                  else if(opcao == 5)
                      list_data_nasc(qtd_professores, prof);

                  else if(opcao == 6)
                      list_prof_sem_disc(qtd_professores, qtd_disc, prof, disc);
                  
                  else
                      printf("Valor invalido!\n");
                  
              
              }
          }

          //BUSCA PROFESSOR
          else if(opcao == 5)
              search_cad(qtd_professores, prof);

          else{
              printf("\nValor invalido!\n");
          }
      }
  break;

//MENU DISCIPLINA
  case 3:
    while(!sair)
    {
        opcao = menu_2(opcao_menu);

        if(opcao == 0)
            break;

    //CADASTRAR DISCIPLINA
        else if(opcao == 1)
        {
            
            //CADASTRO NOME
            printf("------ Cadastro Disciplina -----\n");
            printf("Nome: ");
            fgets(sup, Max, stdin);
                remove_fgets(sup);
                name_pattern(sup);
                strcpy(disc[qtd_disc].nome, sup);

            //CADASTRO CÓDIGO
            printf("Codigo: ");
            fgets(sup, Max, stdin);
                remove_fgets(sup);
                strcpy(disc[qtd_disc].codigo, sup);

                i = qtd_disc;
                ctrl = ver_codigo_disc(qtd_disc, disc, i);
                if(ctrl == n_find)
                    continue;

            //CADASTRO SEMESTRE
            printf("Semestre: ");
            scanf("%d", &disc[qtd_disc].semestre);
            getchar();

                if(disc[qtd_disc].semestre <= 0){
                    printf("\nSemestre Invalido!\n");
                    continue;
                }

            //VINCULAR PROFESSOR
            printf("Matricula do Professor (0 - caso nao houver): ");
            scanf("%d", &aux.matricula);    getchar();

                ctrl = ver_matricula(qtd_professores, prof, aux);
                    if(ctrl == n_find)
                        disc[qtd_disc].matricula_prof = n_find;
                    else{
                        disc[qtd_disc].matricula_prof = aux.matricula;
                        strcpy(disc[qtd_disc].nome_prof, prof[ctrl].nome);
                    }

            printf("\nDisciplina Cadastrada com Sucesso!\n");
            qtd_disc++;
            continue;
            
        }

    //ATUALIZAR DISCIPLINAS
        else if (opcao == 2)
        {
          while(!sair)
          {
            opcao = menu_update_disc();

            //Voltar
            switch(opcao)
            {
                case 0:
                break;

                //ATUALIZAR NOME DISCIPLINA
                case 1:
                    ctrl = update_disciplina(qtd_disc, disc);

                    if(ctrl == n_find)
                      continue;

                    else
                    {
                      printf("Novo nome: ");
                      fgets(sup, Max, stdin);
                        remove_fgets(sup);
                        name_pattern(sup);
                        strcpy(disc[ctrl].nome, sup);

                      printf("\nAtualizado Com Sucesso!\n");
                    }
                continue;

                //ATUALIZAR CODIGO DISCIPLINA
                case 2:
                  ctrl = update_disciplina(qtd_disc, disc);

                  if(ctrl == n_find)
                    continue;

                  else
                  {
                    strcpy(sup, disc[ctrl].codigo);

                    printf("Novo Codigo: ");
                    fgets(sup, Max, stdin);
                      remove_fgets(sup);
                      strcpy(disc[ctrl].codigo, sup);

                    i = ver_codigo_disc(qtd_disc, disc, ctrl);

                    if(i == n_find){
                      strcpy(disc[ctrl].codigo, sup);
                      continue;
                    }
                    else
                      printf("\nAtualizado Com Sucesso!\n");
                    
                  }   
                continue;

                //ATUALIZAÇÃO SEMESTRE DISCIPLINA
                case 3:
                  ctrl = update_disciplina(qtd_disc, disc);

                  if(ctrl == n_find)
                    continue;

                  else
                  {
                    printf("Novo Semestre: ");
                    scanf("%d", &aux.matricula);
                    getchar();
                    if(aux.matricula <= 0){
                      printf("\nSemestre Invalido!\n");
                      continue;
                    }
                    else
                      disc[ctrl].semestre = aux.matricula;

                    printf("\nAtualizado Com Sucesso!\n");
                  }
                continue;

                //ATUALIZAÇÃO PROFESSOR DISCIPLINA
                case 4:
                  ctrl = update_disciplina(qtd_disc, disc);

                    if(ctrl == n_find)
                        continue;

                    else
                    {
                      printf("Matricula do Professor (0 - caso nao houver): ");
                      scanf("%d", &aux.matricula); getchar();

                      if(aux.matricula == 0){
                        disc[ctrl].matricula_prof = n_find;
                        continue;
                      }
                      
                      i = ver_matricula(qtd_professores, prof, aux);

                      if(i == n_find)
                        continue;
                      else{
                        disc[ctrl].matricula_prof = aux.matricula;
                        strcpy(disc[ctrl].nome_prof, prof[i].nome);
                      }

                      printf("\nAtualizado Com Sucesso!\n");
                    }
                continue;

                default:
                  printf("Valor invalido!!\n");
                continue;
              }
              break;
          }
      } 

  //EXCLUIR DISCIPLINA    
      else if(opcao == 3)
      {
        ctrl = disc_delete(qtd_disc, disc);
          if(ctrl == find)
            qtd_disc--;
      }

  //LISTAR DISCIPLINAS
      else if(opcao == 4)
      {
        while(!sair)
        {
          opcao = menu_lista_disc();

          if(opcao == 0)
            break;
          
          else if(opcao == 1)
            list_geral_disc(qtd_disc, disc, opcao);
          
          else if(opcao == 2)
            list_disc_semestre(qtd_disc, disc);
          
          else if(opcao == 3)
            list_geral_disc(qtd_disc, disc, opcao);

          else if(opcao == 4)
           list_alu_disc(qtd_disc, disc, qtd_alunos, alu);
          
          else if(opcao == 5)
            list_nome_disc(qtd_disc, disc);

          else if(opcao == 6)
            list_qtd_al_disc(qtd_disc, disc);

          else if(opcao == 7)
            list_alphabet(qtd_alunos, alu, disc, qtd_disc, opcao_menu);

          else
              printf("Valor invalido!!\n");
        }
        
      }

      //BUSCAR DISCIPLINA
      else if(opcao == 5)
      {
        if(qtd_disc == 0){
          printf("-----------------------------\n\n");
          printf("Nenhuma Disciplina Cadastrada!\n");
          continue;
        }
        else
          search_disc(qtd_disc, disc);
      }

      //MATRICULAR ALUNO EM DISCIPLINA
      else if(opcao == 6)
        matricula_al_disc(qtd_disc, qtd_alunos, disc, alu); 

      //CANCELAR MATRICULA DE ALUNO
      else if(opcao == 7)
        delete_matricula_disc(qtd_alunos, qtd_disc, alu, disc);
          
        
    }
  break;

  default:
    printf("Valor invalido!!\n");
    break;
  }

}

  printf("\t------------------------\n\n");
  printf("\t Finalizado com sucesso\n\n");
  printf("\t------------------------\n");

  return EXIT_SUCCESS;
}