#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "aluno.h"
#include "aluno_white.h"
#include "aluno_read.h"

int main() {

    //Definindo a quantidade de alunos na sala. Max = 40 alunos 
    Aluno *aluno[40];

    //Variaveis que serão utilizadas no switch 
    int quantidade;
    int opcao;

    // Define quantos alunos poderão ser cadastrados
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);

    // Verifica se a quantidade está dentro do limite da turma
    if (quantidade < 1 || quantidade > 40) {
        printf("Quantidade invalida! Digite um valor entre 1 e 40.\n");
        return 1;
    }

    //Verifinado opção 
    do {

        //menuzinho básico
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Atualizar aluno\n");
        printf("5 - Excluir aluno\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                for (int i = 0; i < quantidade; i++){

                    // Atributos do aluno que serão repassadas na função criarAluno 
                    int id; 
                    char nome[40]; 
                    unsigned int matricula; 
                    float nota1, nota2; 
                    unsigned faltas;

                    printf("Cadastrar aluno\n");

                    // Definindo valor ao id 
                    id =  i + 1;

                    //Definindo o nome do aluno i
                    printf("Nome: "); fgets(nome, sizeof(nome), stdin);
                    // Retirando o o "enter" no final do nome 
                    nome[strcspn(nome, "\n")] = '\0';

                    //Defininto a matricula do aluno i
                    printf("Matricula: "); 
                    scanf("%u", &matricula);

                    // Definindo as notas 1 e 2 do aluno i
                    // OBS: notas não podem ser nem nagativas e não existe nota maior que 10 
                    do {
                        printf("Nota 1: ");
                        scanf("%f", &nota1);

                        if (nota1 < 0 || nota1 > 10) {
                            printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
                    }

                    } while (nota1 < 0 || nota1 > 10); 

                 
                    do {
                        printf("Nota 2: ");
                        scanf("%f", &nota2);

                        if (nota2 < 0 || nota2 > 10) {
                            printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
                    }

                    } while (nota2 < 0 || nota2 > 10);

                    // Definindo quantidade de faltas do aluno i 
                    printf("Numero de faltas: "); 
                    scanf("%u", &faltas);

                    // Chamano a funçao criarAluno para criar o objeto aluno i 
                    aluno[i] = criarAluno( id, nome, matricula, nota1, nota2, faltas ); 
                    
                    // Verificar se não estã vazio 
                    if (aluno[i] == NULL) { 
                        printf("Erro ao criar aluno!\n");
                         break; } 
                    


                    if(salvarAluno(aluno[i]))
                    printf("Aluno cadastrado com sucesso!\n");

                }
                break;

            case 2:
                printf("Listar alunos\n");
                listarAlunos();
                break;

            case 3:
                // variaveis que irão ser utilizadas como parametro 
                int escolha;
                int idInformado;
                char nomeInformado[40];

                //menuzinho buscar por id ou por nome 
                printf("\n===== Buscar aluno =====\n");
                printf(" 1 - Id\n 2 - Nome\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &escolha);
            
                if(escolha == 1){

                    printf("Informe o id do aluno:\n");
                    scanf("%d", &idInformado);

                    buscarAlunoPorId(idInformado);
                }else if (escolha == 2){
                    printf("Informe o nome do aluno:\n");
                    scanf("%s", &nomeInformado);

                    buscarPorNome(toupper(nomeInformado));
                }else{
                    printf("Opção inválida");
                }
                
                break;

            case 4:
        
                int id; 
                int opcaoUpdate; 
                printf("\n=====Atualizar aluno =====\n"); 
                
                printf("Digite o ID do aluno: "); 
                scanf("%d", &id); 
                printf("\nO que deseja atualizar?\n");
                printf("1 - Nome\n2 - Matricula\n3 - Nota 1\n4 - Nota 2\n5 - Faltas\n0 - Cancelar\n"); 
                 
                printf("Escolha uma opcao: "); 
                scanf("%d", &opcaoUpdate); 

                if (opcaoUpdate == 0) { 
                    printf("Atualizacao cancelada.\n");
                     break; } 
                if (opcaoUpdate < 1 || opcaoUpdate > 5) { 
                    printf("Opcao invalida!\n"); break; 
                } 
                
                atualizarAluno(id, opcaoUpdate); break;
                break;

            case 5:
                printf("Excluir aluno\n");
                // Pede o ID do aluno que será excluído 
                printf("Digite o ID do aluno: "); 
                scanf("%d", &id); 
                // Chama a função responsável por excluir 
                excluirAluno(id);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}