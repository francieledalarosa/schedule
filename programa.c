#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"evento.h"

struct no {
    evento event;
    struct no *next;
};

typedef struct no list;

void inilist(list **lista) {
    *lista = (list*)malloc(sizeof(list));
    (*lista)->next = NULL;
}

void incluirno(list **event) {
    list *newlist = (list*)malloc(sizeof(list));
    inilist(&newlist);
    fillEvent(&newlist->event);
    newlist->next = NULL;

    if (*event == NULL) {
        *event = newlist;
    } else {
        list *aux = *event;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newlist;
    }
}

void showallEvent(list *eventos) {
    if (eventos == NULL) {
        printf("Agenda vazia\n");
    } else {
        list *aux = eventos;
        while (aux != NULL) {
            showEvent(&(aux->event));
            aux = aux->next;
        }
    }
}

void searchEventdatebyhour(list *eventos, date data, hour time) {
    list *aux = eventos;
    if(eventos == NULL){
        printf("Agenda vazia\n");
    }else{
        int encontrado= 1;
    while (aux != NULL) {
        if (aux->event.data.year == data.year &&
            aux->event.data.month == data.month &&
            aux->event.data.day == data.day &&
            aux->event.horas.hours == time.hours &&
            aux->event.horas.minutes == time.minutes) {
            showEvent(&(aux->event));
            encontrado = 0;
        }
        aux = aux->next;
    }
    if(encontrado != 0){
        printf("\nEvento não encontrado, voltando ao menu inicial\n");
    }
    }
}

void searchEventdate(list *eventos, date data) {
    if(eventos == NULL){
        printf("Agenda vazia\n");
    }else{
        list *aux = eventos;
    int encontrado= 1;
    while (aux != NULL) {
        if (aux->event.data.year == data.year &&
            aux->event.data.month == data.month &&
            aux->event.data.day == data.day) {
            showEvent(&(aux->event));
            encontrado = 0;
        }
        aux = aux->next;
    }
    if(encontrado != 0){
        printf("Evento não encontrado, voltando ao menu inicial\n");
    }
    }
}

void changEvent(list **eventos, date data, hour time) {
    if(*eventos == NULL){
        printf("Agenda vazia\n");
    }else{
        list *aux = *eventos;
    while (aux != NULL) {
        if (aux->event.data.year == data.year &&
            aux->event.data.month == data.month &&
            aux->event.data.day == data.day &&
            aux->event.horas.hours == time.hours &&
            aux->event.horas.minutes == time.minutes) {
            printf("\nEvento localizado\n");
            showEvent(&(aux->event));
            printf("\nDigite a nova descrição do compromisso:\n");
            getchar();
            fgets(aux->event.descricao, sizeof(aux->event.descricao), stdin);
            printf("\nDigite a nova duração do compromisso:\n");
            timeD(&(aux->event.duracao));
            printf("\nCompromisso alterado com sucesso!\n");
            showEvent(&(aux->event));
            return;
        }
        aux = aux->next;
    }
    printf("\nCompromisso não encontrado.\n");
    }
}

void excluirCompromisso(list **eventos, date searchDate, hour searchTime) {
    if(*eventos == NULL){
        printf("Agenda vazia\n");
    }else{
        list *current = *eventos;
    list *previous = NULL;

    while (current != NULL) {
        if (current->event.data.year == searchDate.year &&
            current->event.data.month == searchDate.month &&
            current->event.data.day == searchDate.day &&
            current->event.horas.hours == searchTime.hours &&
            current->event.horas.minutes == searchTime.minutes) {
            printf("\nEvento encontrado\n");
            printf("Tem certeza que deseja exluir o evento?\n");
            showEvent(&(current->event));
            int opc = 0 ;
            while(opc != 1 || opc != 2){
                printf("SIM opcão: 1\nNÃO opção: 2\n");
                scanf("%d", &opc);
                if(opc == 1){
                    previous->next = current->next;
                    free(current);
                    printf("\nCompromisso excluído com sucesso!\n");
                    return;
                    break;
                }else if(opc == 2){
                    break;
                }else{
                    printf("Opção inválida\n");
                    printf("SIM opcão: 1\n NÃO opção: 2\n");
                    scanf("%d", &opc);
                }
            }
           
        }

        previous = current;
        current = current->next;
    }

    printf("\nCompromisso não encontrado.\n");
    }
}

void freeall(list **event) {
    list *current = *event;
    list *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *event = NULL;
}

int main() {
    int op = 0;
    list *event = NULL;
    inilist(&event);
    printf("UFFSAgenda\n\n");
    printf("Digite o número da opção que deseja:\n 1 - Incluir\n 2 - Consultar\n 3 - Alterar\n 4 - Excluir\n 5 - Listar todos\n 6 - Sair\n\n");
    scanf("%d", &op);
    while (op != 6) {
        
        if (op == 1) {
            incluirno(&event);
        } else if (op == 2) {
            int op2;
            printf("\nMENU DE BUSCAS:\n");
            if(event ==  NULL){
                printf("Agenda vazia\n");
            }else{
                printf("Se deseja fazer a busca por DATA digite: 1\nSe deseja fazer a busca por DATA e HORA digite: 2\n\n");
            scanf("%d", &op2);
            if (op2 == 1) {
                date data;
                printf("\n");
                printf("Digite a data que deseja procurar no formato (DD MM AAAA):\n");
                scanf("%d %d %d", &data.day, &data.month, &data.year);
                searchEventdate(event, data);
            } else if (op2 == 2) {
                date data;
                hour hora;
                printf("Digite a data que deseja procurar no formato (DD MM AAAA):\n");
                scanf("%d %d %d", &data.day, &data.month, &data.year);
                printf("Digite o horário que deseja procurar no formato HH MM:\n");
                scanf("%d %d", &hora.hours, &hora.minutes);
                searchEventdatebyhour(event, data, hora);
            } else {
                printf("\nOpção inválida.\n");
            }
            }
        } else if (op == 3) {
            printf("\nPrecisará informar a data e o horário do evento que deseja alterar, caso não saiba, use a opção 2 / 1 do menu para procurar.\n");
            printf("Deseja continuar ou voltar?\nDigite 1 para continuar ou 2 para retornar ao menu!\n\n");
            int op3;
            scanf("%d", &op3);
            while(op3 != 1 || op3 != 2){
                if(op3 == 1){
                date data;
                hour hora;
                printf("\nDigite a data que deseja procurar no formato (DD MM AAAA):\n");
                scanf("%d %d %d", &data.day, &data.month, &data.year);
                printf("\nDigite o horário que deseja procurar no formato HH MM:\n");
                scanf("%d %d", &hora.hours, &hora.minutes);
                changEvent(&event, data, hora);
                break;
            }else if(op3 == 2){

                printf("\nVoltando ao menu\n");
                break;

            }else{

                printf("Opção inválida\n");
                printf("Deseja continuar ou voltar?\nDigite 1 para continuar ou 2 para retornar ao menu!\n\n");
                scanf("%d", &op3);  
            }
            }
            
           
        } else if (op == 4) {
            printf("\nPrecisará informar a data e o horário do evento que deseja excluir.\n");
            printf("Caso não saiba, use a função 2 para procurar.\n\n");
            printf("Deseja continuar digite 1 ou para retornar ao menu digite 2\n");
            int op4=0;
            while(op4 != 1 || op4 !=2){
                scanf("%d", &op4);
                if(op4 == 1){
                    date data;
                    hour hora;
                    printf("Digite a data que deseja procurar no formato (DD MM AAAA):\n");
                    scanf("%d %d %d", &data.day, &data.month, &data.year);
                    printf("Digite o horário que deseja procurar no formato HH MM:\n");
                    scanf("%d %d", &hora.hours, &hora.minutes);
                    excluirCompromisso(&event, data, hora);
                    break;
                }else if(op4 == 2){

                    printf("Voltando ao menu\n");
                    break;

                }else{
                    printf("\nOpção inválida\n");
                    printf("Digite 1 para continuar ou 2 para retornar ao menu!\n\n");
                    scanf("%d", &op4);
                }
            }
            
        } else if (op == 5) {
            showallEvent(event);
        }
       printf("\nUFFSAgenda\n");
        printf("\n 1 - Incluir\n 2 - Consultar\n 3 - Alterar\n 4 - Excluir\n 5 - Listar todos\n 6 - Sair\n\n");
        printf("Digite a opção que deseja:\n\n");

        scanf("%d", &op);
    }

    freeall(&event);

    return 0;
}