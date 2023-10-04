/*
 gcc DeivisonSantos-20231160043-T1.c -o t1
 gcc novoCorretor.c DeivisonSantos-20231160043-T1.c -o t1
*/

//------------ Dados Aluno ------------------

// Nome: Deivison Cassimiro Dos Santos
// Email: deivisonddj3@gmail.com
// Matrícula: 20231160043
// Semestre: 2
// ------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "DeivisonSantos-20231160043-T1.h"


void remove_fgets(char *p){
    int i;

    i = strlen(p) -1;
    if(p[i] == '\n')
        p[i] = '\0';
}

int q1(char data_s[]){
    data_valid data_i;
    int i;

    get_data(data_s, &data_i);

//se alguma data for negativa
    if(data_i.a <= 0){
        // printf("Ano Invalido\n");
        return ERROR;
    }
    else if(data_i.m <= 0 || data_i.m > 12){
        // printf("Mes Invalido\n");
        return ERROR;
    }
    else if(data_i.d <= 0){
        // printf("Dia Invalido\n");
        return ERROR;
    }

//Caso o dia tenha passado do limite do mês 
    if(data_i.m == 2)
    {
    //Ano bissexto
        i = bissexto(&data_i);
        if(i==0 && data_i.d > 29){  
            //printf("Dia Invalido\n");
            return ERROR; 
        }
        else if(i==0 && data_i.d > 28){
            //printf("Dia Invalido\n");
            return ERROR;
        }
    }
    else if((data_i.m==1 || data_i.m==3 || data_i.m==5 || data_i.m==7 || data_i.m==8 || data_i.m==10 || data_i.m==12) && data_i.d>31){  
        //printf("Dia Invalido\n");
        return ERROR;
    }
    else if((data_i.m==4 || data_i.m==6 || data_i.m==9 || data_i.m==11) && data_i.d>30){
       //printf("Dia Invalido\n");
       return ERROR;
    }

    //Casso a pessoa seja de antes de 2000
    if(data_i.type_year == 2 || data_i.type_year == 1)
        data_i.a += 2000;

    return SUCCESS;
}

DiasMesesAnos q2(char data_inicial[], char data_final[]){
    DiasMesesAnos distance;
    data_valid start_data;
    data_valid end_data;
    char sup[15];
    int i;

    if(q1(data_inicial)==0){
        distance.retorno = 2;
        return distance;
    }
    else if(q1(data_final)==0){
        distance.retorno = 3;
        return distance;
    }

    get_data(data_inicial, &start_data);
    get_data(data_final, &end_data);

    if(end_data.a < start_data.a){
        // printf("Ano Final Invalido\n");
        distance.retorno = 4;
        return distance;
    }
    else if(end_data.a == start_data.a && end_data.m < start_data.m){
        // printf("Mes Final Invalido\n");
        distance.retorno = 4;
        return distance;
    }
    else if(end_data.a == start_data.a && end_data.m == start_data.m && end_data.d < start_data.d){
        // printf("Dia Final Invalido\n");
        distance.retorno = 4;
        return distance;
    }

    distance.qtdDias = 0;
    distance.qtdAnos = 0;
    distance.qtdMeses = 0;
    //int start; start = start_data.d;
    int mes; mes = start_data.m;
    while(start_data.d != end_data.d || start_data.m != end_data.m || start_data.a != end_data.a)
    {
        if(start_data.m==2)
        {
            i = bissexto(&start_data);
            if(i==1 && start_data.d==29){   //se o ano for bissexto.
                    start_data.d = 1;
                    start_data.m++;
                    distance.qtdDias++;
            }
            else if(i==0 && start_data.d==28){
                start_data.d = 1;
                start_data.m++;
                distance.qtdDias++;
            }
            else{
                start_data.d++;
                distance.qtdDias++;
            }
            
        }
        else if((start_data.m==1 || start_data.m==3 || start_data.m==5 || start_data.m==7 || start_data.m==8 || start_data.m==10 || start_data.m==12) && start_data.d==31)
        {  
            //caso seja fim de mes.
            if(start_data.m==12){
                start_data.a++;
                start_data.m = 1;
                start_data.d = 1;
                distance.qtdDias++;
                // printf("%d ", start_data.d);
            }
            else{
                start_data.m++;
                start_data.d = 1;
                distance.qtdDias++;
                // printf("%d ", start_data.d);
            }
        }
        else if((start_data.m==4 || start_data.m==6 || start_data.m==9 || start_data.m==11) && start_data.d==30){
            start_data.d = 1;
            start_data.m++;
            distance.qtdDias++;
            // printf("%d ", start_data.d);
        }
        else{ //caso nao seja fim de mes.
            start_data.d++;
            distance.qtdDias++;
        }

        // printf("%d  ", start_data.d);
        // printf("%d  ", start_data.m);
        // printf("%d  ", start_data.a);
        mes = meses(&start_data, &distance, mes);
    }
    
    // if(data_inicial->d == end_data.d && data_inicial->m == end_data.m){
    //     if((distance.qtdDias==30 || distance.qtdDias==31) && distance.m==11){
    //         distance.qtdDias=0;
    //         distance.m=0;
    //         distance.a++;
    //     }
    // }
    i=bissexto(&end_data);
    if((start_data.m==2 && start_data.d==29) && (end_data.d==28 && end_data.m==2))
        if(((distance.qtdDias==30 || distance.qtdDias==31) && distance.qtdMeses==11) && i!=1){
            distance.qtdDias=0;
            distance.qtdMeses=0;
            distance.qtdAnos++;
        }
    // printf("\nDistance: ");
    // printf("\n%d", distance.qtdDias);
    // printf("/%d", distance.qtdMeses);
    // printf("/%d\n", distance.qtdAnos);

    distance.retorno = 1;

    return distance;
}

int q3(char text[], char let, int CaseSensitive){
    int i, qtd;

    if(CaseSensitive)
    {
        for(i=0, qtd=0; text[i] != '\0'; i++)
            if(text[i] == let)
                qtd++;
    }
    else{
        i = strlen(text);

        char *lower_text = malloc(i * sizeof(char));
        let = tolower(let);

        for(i=0, qtd=0; text[i] != '\0'; i++){
            lower_text[i] = tolower(text[i]);

            if(lower_text[i] == let)
                qtd++;
        }
    }

    return qtd;
}

int q4(char *strTexto, char *strBusca, int posicoes[]){
    int i, j, ctrl=0, qtd=0;
  
  char *TextClean = malloc(strlen(strTexto) * sizeof(char));
  char *BuscaClean = malloc(strlen(strBusca) * sizeof(char));

    for(i=0, j=0; strTexto[i] != '\0'; i++)
        if(strTexto[i] != -61){
            TextClean[j] = strTexto[i];
            j++;
        }
    TextClean[j] = '\0';
  
    for(i=0, j=0; strBusca[i] != '\0'; i++)
        if(strBusca[i] != -61){
            BuscaClean[j] = strBusca[i];
            j++;
        }
    BuscaClean[j] = '\0';

    for(i=0; TextClean[i] != '\0'; i++)
    {  
       if(TextClean[i] == BuscaClean[0])
       {
         for(j=0; BuscaClean[j] != '\0'; j++)
            if(BuscaClean[j] != TextClean[j+i])
              break;

         if(strlen(BuscaClean) == j){
           posicoes[ctrl] = i+1;
        //    printf("comeco: %d\n", posicoes[ctrl]);
           posicoes[ctrl+1] = i+j;
        //    printf("fim: %d\n", posicoes[ctrl+1]);
           ctrl += 2;
           i++;
          qtd++;
         }
      }
    }

    free(TextClean);
    free(BuscaClean);
    return qtd;
}

int q5(int num){
    int out, i, j;
    char num_s[20], aux;

    sprintf(num_s, "%d", num);

    i = strlen(num_s) -1;

    for(j=0; j <= i/2; j++, i--){
        aux = num_s[j];
        num_s[j] = num_s[i];
        num_s[i] = aux;
    }
    //printf("s: %s\n", num_s);

    out = atoi(num_s);
    //printf("%d\n", out);
    return out;
}

int q6(int num, int comp){
    char s_num[20], s_comp[20];
    int qtd=0, range;
    int i, j;

    sprintf(s_num, "%d", num); 
    sprintf(s_comp, "%d", comp); 
    range = strlen(s_comp); 

    for(i=0; s_num[i] != '\0'; i++)
    {
        if(s_num[i] == s_comp[0]){
            j=0;
            while(s_comp[j]!='\0' && s_comp[j] == s_num[i+j])
                j++;
            

            if(j==range){
                qtd++;
                i += range-1;
            }
        }
    }
    // printf("qtd: %d\n", qtd);
    return qtd;
}

void get_data(char sup[], data_valid *p){
    int i, d, m, a, j;
    char aux[10];

    aux[0]='a';
    for(i=0; sup[i] != '/'; i++)
        aux[i] = sup[i];
    aux[i] = '\0';
    d = atoi(aux);

    aux[0]='a';
    for(j=0, i++; sup[i] != '/'; i++, j++)
        aux[j] = sup[i];
    aux[j] = '\0';
    m = atoi(aux);

    aux[0]='a';
    for(j=0, i++; sup[i] != '\0'; i++, j++)
        aux[j] = sup[i];
    aux[j] = '\0';
    a = atoi(aux);

    p->type_year = j; 
    p->d = d; 
    p->m = m; 
    p->a = a; 
}

int meses(data_valid *start_data, DiasMesesAnos *distance, int mes){
    int i, j; j=mes;

    //se o ano for bissexto.
    if(mes==2)
    {
        i = bissexto(start_data);
        if(i==1 && distance->qtdDias==29){
            distance->qtdDias = 0;
            distance->qtdMeses++;
            mes++;
        }
        else if(i==0 && distance->qtdDias==28){
            distance->qtdDias = 0;
            distance->qtdMeses++;
            mes++;
        }
    }
    else if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && distance->qtdDias==31){  
        distance->qtdMeses++;
        distance->qtdDias = 0;
        mes++;
        // printf("%d ", distance->qtdDias);
        
    }
    else if((mes==4 || mes==6 || mes==9 || mes==11) && distance->qtdDias==30){
        distance->qtdDias = 0;
        distance->qtdMeses++;
        mes++;
        // printf("%d ", distance->qtdDias);
    }

    if(distance->qtdMeses == 12){
        distance->qtdAnos++;
        distance->qtdDias=0;
        distance->qtdMeses=0;
        if(mes==j)
            mes++;
    }

    if(mes==13)
        mes=1;

    // printf("(%d/", distance->qtdDias);
    // printf("%d/", distance->qtdMeses);
    // printf("%d) ", distance->a);
    // // printf("%d )", mes);
    // printf("(%d/", start_data->d);
    // printf("%d/", start_data->m);
    // printf("%d)", start_data->a);
    // printf("  %d\n", mes);
    // printf("/%d ", distance->a);

    return mes;
}

int bissexto(data_valid *p){
  int i;

  if((p->a % 4==0 && p->a % 100 != 0) || p->a % 400==0)
    i=1;
  else
    i=0;

  return i;
}