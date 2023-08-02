#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data.h"
#include"hora.h"
#include"evento.h"

void fillEvent(evento *event){
   
    printf("\nDigite a data do evento no formato (DD MM AAAA)\n");
    scanf("%2d %2d %4d", &event->data.day, &event->data.month, &event->data.year);
    printf("\nDigite o horário do evento no formato 24H (HH MM)\n");
    scanf("%2d %2d", &event->horas.hours, &event->horas.minutes);
    timeD(&(event->duracao));
    printf("\nDigite a descrição do compromisso\n");
    getchar();
    fgets(event->descricao, sizeof(event->descricao), stdin);
    event->descricao[strcspn(event->descricao, "\n")] = '\0';

}
    
void showEvent(evento *event) {
    printf("\n");
    printf("UFFS Agenda\n");
    printf("=========================================================\n");
    printf("DATA: %02d/%02d/%04d\n", event->data.day, event->data.month, event->data.year);
    printf("HORAS: %02d:%02d\n", event->horas.hours, event->horas.minutes);
    printf("DURAÇÃO: %2d:%2d\n", event->duracao.hours, event->duracao.minutes);
    printf("DESCRIÇÃO: %s\n", event->descricao);
    printf("==========================================================\n\n");
}