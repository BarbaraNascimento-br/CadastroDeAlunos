#ifndef ALUNO_H
#define ALUNO_H

typedef struct _aluno{
    unsigned int id;
    char nome[40];
    unsigned int matricula;
    float nota1;
    float nota2;
    unsigned int faltas;

}Aluno;

void printAluno(const Aluno *aluno);
Aluno *criarAluno(int id, char *nome, int matricula, float nota1, float nota2, unsigned faltas);

#endif