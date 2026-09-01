#include <stdio.h>
#include "aluno_white.h"

int salvarAluno(const Aluno *aluno){

    //Verifiquei um novo modo - > ab
    // O ab, diferentemente do  wb, ele não sobrescreve o arquivo 
    FILE *arquivo = fopen("turma.bin", "ab"); // --> é bacana no cadastrar/salavar 

    //Verificando se o arquivo foi aberto/criado 
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    // Gravando alun e verificando se deu certo 
    if(fwrite(aluno, sizeof(Aluno), 1, arquivo) != 1){
        printf("Erro ao gravar aluno!\n");
        fclose(arquivo);
        return -1;
    }
    //Fechando o arquivo 
    fclose(arquivo);

    return 0;
}