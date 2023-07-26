#ifndef HORA_H
#define HORA_H
#define MAX_HOURS 24
#define MAX_MINUTES 60

struct hora{
    int hours;
    int minutes;
};

typedef struct hora hour;

hour* timeD(hour* descricao);

#endif