#include<stdio.h>
#include<stdlib.h>
#include"hora.h"
#include"evento.h"


hour* timeD(hour* descricao) {
    hour* time = (hour*)malloc(sizeof(hour));
    hour* inicial = (hour*)malloc(sizeof(hour));
    hour* final = (hour*)malloc(sizeof(hour));

    printf("\nDigite novamente a hora inicial do evento no formato 24H (HH MM)\n");
    scanf("%d %d", &inicial->hours, &inicial->minutes);
    while (inicial->hours > MAX_HOURS || inicial->hours < 0 || inicial->minutes > MAX_MINUTES || inicial->minutes < 0) {
        printf("\nValor de horas inválido. Digite a hora inicial do evento no formato 24H (HH MM)\n");
        scanf("%d %d", &inicial->hours, &inicial->minutes);
    }

    printf("\nDigite a hora final do evento no formato 24H (HH MM)\n");
    scanf("%d %d", &final->hours, &final->minutes);
    while (final->hours > MAX_HOURS || final->hours < 0 || final->minutes > MAX_MINUTES || final->minutes < 0) {
        printf("\nValor de horas inválido. Digite a hora final do evento no formato 24H (HH MM)\n");
        scanf("%d %d", &final->hours, &final->minutes);
    }

    if(final->hours < inicial->hours){
        time->hours = (24 - final->hours)+ inicial->hours;
    }
    else{time->hours = final->hours - inicial->hours;}
    if(final->minutes < inicial->minutes){
        time->hours = time->hours -1;
        time->minutes = (60 - inicial->minutes) + final->minutes;
    }
    else{time->minutes = final->minutes - inicial->minutes;}

    free(inicial);
    free(final);

    descricao->hours = time->hours;
    descricao->minutes = time->minutes;

    free(time);

    return descricao;
}