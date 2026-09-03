#include <stdio.h>
#include <string.h>
#include "aluno.h"

int atualizarAluno(int id, int opcao) {

    // r+ = leitura e escrita
    // b  = binário
    FILE *arquivo = fopen("turma.bin", "r+b");

    // Verifica se conseguiu abrir
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return -1;
    }

    // Variável que recebe o aluno encontrado
    Aluno aluno;

    // Procura o aluno pelo ID
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {

        if (aluno.id == id) {

            printf("\n===== ALUNO ENCONTRADO =====\n");
            printAluno(&aluno);
            printf("\n");


            // qual informação será atualizada
            switch (opcao) {

                case 1: {

                    // Atualizar nome
                    getchar();

                    printf("Digite o novo nome: ");

                    fgets(aluno.nome, sizeof(aluno.nome), stdin);

                    // Remove o \n do fgets
                    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

                    break;
                }


                case 2: {

                    // Atualizar matrícula
                    printf("Digite a nova matricula: ");
                    scanf("%u", &aluno.matricula);

                    break;
                }


                case 3: {

                    // Atualizar nota 1
                    do {

                        printf("Digite a nova nota 1: ");
                        scanf("%f", &aluno.nota1);

                        if (aluno.nota1 < 0 || aluno.nota1 > 10) {
                            printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
                        }

                    } while (aluno.nota1 < 0 || aluno.nota1 > 10);

                    break;
                }


                case 4: {

                    // Atualizar nota 2
                    do {

                        printf("Digite a nova nota 2: ");
                        scanf("%f", &aluno.nota2);

                        if (aluno.nota2 < 0 || aluno.nota2 > 10) {
                            printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
                        }

                    } while (aluno.nota2 < 0 || aluno.nota2 > 10);

                    break;
                }


                case 5: {

                    // Atualizar faltas
                    printf("Digite o novo numero de faltas: ");
                    scanf("%u", &aluno.faltas);

                    break;
                }


                default:

                    printf("Opcao invalida!\n");

                    fclose(arquivo);

                    return -1;
            }


            // O fread() avançou o ponteiro para depois do aluno.
            // Voltamos o ponteiro para o início desse aluno.
            fseek(arquivo, -sizeof(Aluno), SEEK_CUR);


            // Sobrescreve o aluno antigo com os dados atualizados
            if (fwrite(&aluno, sizeof(Aluno), 1, arquivo) != 1) {

                printf("Erro ao atualizar aluno!\n");

                fclose(arquivo);

                return -1;
            }


            printf("\nAluno atualizado com sucesso!\n");

            fclose(arquivo);

            return 0;
        }
    }
}