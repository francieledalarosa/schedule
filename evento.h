#ifndef EVENTO_H
#define EVENTO_H

#include "data.h"
#include "hora.h"

struct node {
    char descricao[40];
    date data;
    hour horas;
    hour duracao;
};

typedef struct node evento;

void fillEvent(evento *event);
void showEvent(evento *event);

#endif
