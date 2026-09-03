#include <stdio.h>
#include <ctype.h>
#include "aluno_read.h"
#include "aluno.h"

void listarAlunos() {

    //Abrindo 
    FILE *arquivo = fopen("turma.bin", "rb");

    //Verificando se o arquivo foi aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Aluno aluno;

    // Lê um aluno por vez do arquivo
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        // Mostra os dados do aluno na tela
        printAluno(&aluno);
        printf("\n");
    }

    fclose(arquivo);
}

int buscarAlunoPorId(int i){
     
    //Abrindo 
    FILE *arquivo = fopen("turma.bin", "rb");

    //Verificando se o arquivo foi aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    // Variável que recebe o aluno encontrado
    Aluno aluno;

    // Lê um aluno por vez do arquivo
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        // Verifica se o ID do aluno é igual ao ID procurado
        if(aluno.id == i){
            printAluno(&aluno);
            printf("\n");
            fclose(arquivo);
            return 0;
        }
    }
    //se não achou, vem para essa area 
    printf("Aluno com ID %d nao encontrado!\n", i);
    fclose(arquivo);

    return -1;
    
}

int buscarPorNome(char n[]){

    for(int i = 0; n[i] != '\0'; i++){
        n[i] = toupper(n[i]);
    }
     //Abrindo 
    FILE *arquivo = fopen("turma.bin", "rb");

    //Verificando se o arquivo foi aberto
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }
    
    // Variável que recebe o aluno encontrado
    Aluno aluno;

    // Lê um aluno por vez do arquivo
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        // Verifica se o nome do aluno é igual ao NOME procurado
        if(aluno.nome == n){
            printAluno(&aluno);
            printf("\n");
            fclose(arquivo);
            return 0;
        }
    }
    //se não achou, vem para essa area 
    printf("Aluno com Nome %s nao encontrado!\n", n);
    fclose(arquivo);

    return -1;
}