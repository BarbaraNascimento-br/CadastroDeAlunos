#include <string.h>
#include <stdlib.h>
#include "aluno.h"

// Calcula a média das notas do aluno
float mediaAluno(const Aluno *aluno) {

    // Verifica se o ponteiro para o aluno é nulo
    if (aluno == NULL) {
        return -1;
    }

    // Calcula a média das duas notas
    float media = (aluno->nota1 + aluno->nota2) / 2;

    return media;
}
// Retorna a situação do aluno com base na média e no número de faltas
const char *situacaoAluno(const Aluno *aluno) {

    // Verifica se o aluno atingiu a média mínima
    // e se não ultrapassou o limite de faltas
    if (mediaAluno(aluno) >= 6.0f && aluno->faltas <= 20) {
        return "Aprovado";
    }

    // Caso não atenda aos critérios, o aluno está reprovado
    return "Reprovado";
}