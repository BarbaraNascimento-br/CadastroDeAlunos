#include <stdio.h>
#include <string.h>
#include "aluno_read.h"

int excluirAluno(int id) {

    // Abre o arquivo original para leitura
    FILE *arquivo = fopen("turma.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    // Cria um arquivo temporário para receber
    // todos os alunos, menos o que será excluído
    FILE *temporario = fopen("temp.bin", "wb");

    if (temporario == NULL) {
        printf("Erro ao criar arquivo temporario!\n");

        fclose(arquivo);

        return -1;
    }

    Aluno aluno;

    // Controla se o aluno foi encontrado
    int encontrado = 0;

    // Lê um aluno por vez do arquivo original
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {

        // Verifica se é o aluno que queremos excluir
        if (aluno.id == id) {

            // Encontrou o aluno
            encontrado = 1;

            // Não grava esse aluno no arquivo temporário
            continue;
        }

        // Se não for o aluno que queremos excluir,
        // grava normalmente no arquivo temporário
        if (fwrite(&aluno, sizeof(Aluno), 1, temporario) != 1) {

            printf("Erro ao gravar no arquivo temporario!\n");

            fclose(arquivo);
            fclose(temporario);

            return -1;
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(temporario);


    // Verifica se encontrou o aluno
    if (encontrado == 0) {

        printf("Aluno com ID %d nao encontrado!\n", id);

        // Remove o arquivo temporário
        remove("temp.bin");

        return -1;
    }


    // Remove o arquivo original
    if (remove("turma.bin") != 0) {

        printf("Erro ao remover o arquivo original!\n");

        remove("temp.bin");

        return -1;
    }


    // Renomeia o arquivo temporário
    // para o nome do arquivo original
    if (rename("temp.bin", "turma.bin") != 0) {

        printf("Erro ao renomear o arquivo temporario!\n");

        return -1;
    }


    printf("Aluno com ID %d excluido com sucesso!\n", id);

    return 0;
}

