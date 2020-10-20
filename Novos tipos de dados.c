#include <stdio.h>
#include <stdlib.h>

int main ();
    struct horario {
        int horas, minutos, segundos;
}
    struct data {
        int dia, mes, ano;
}
    struct compromisso {
        struct data; struct horario; char descricao[50];
}
}
