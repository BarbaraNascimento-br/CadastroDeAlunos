#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "media.h"


//"construtor" para alunos
Aluno *criarAluno(int id, char *nome, unsigned int matricula, float nota1, float nota2, unsigned faltas){
    // Alocação dinâmica
    Aluno *aluno = calloc(1, sizeof(Aluno));

    if (aluno == NULL) {
        return NULL;
    }

    for (int i = 0; i < 40; i++){
        nome[i] = toupper(nome[i]);
    }
    

    aluno->id = id;
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->nota1 = nota1;
    aluno->nota2 = nota2;
    aluno->faltas = faltas;

    return aluno;
}

//Imprinmindo dados Aluno 
void printAluno(const Aluno *aluno){
    printf(
        "ID :%d | NOME: %s | MATRICULA: %d | NOTA 1: %.2f | NOTA 2: %.2f | Nº DE FALTAS: %d | MEDIA: %.2f | STATUS: %s",
        aluno->id, aluno->nome, aluno->matricula, aluno->nota1, aluno->nota2, aluno->faltas, mediaAluno(aluno), situacaoAluno(aluno)
    );
}