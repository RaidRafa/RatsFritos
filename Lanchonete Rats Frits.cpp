// Programa para calcular os dados das vendas de uma Lanchonete 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int iMenuPrincipal, iMenuLanches, iMenuBebidas, iMenuSobremesas, iMenuBemVindo;
    float valorLanches = 0, valorBebidas = 0, valorSobremesas = 0, valorTotal;

    do {
        printf("\n -----------------------------------------\n");
        printf("\n ********        BEM VINDO        ********\n");
        printf("\n -----------------------------------------\n");
        printf(" \n Entre com uma das opções abaixo:\n\n");
        printf("  1 - ABRIR PEDIDO\n");
        printf("  2 - VISUALIZAR PEDIDOS\n");
        printf("  3 - SAIR DO SISTEMA\n");
        printf("  Opção: ");
        scanf("%d", &iMenuBemVindo);
        printf("\n -----------------------------------------\n");

        if (iMenuBemVindo == 1) {
            srand(time(NULL));
            int num = rand();
            char nomeArquivo[50];
            snprintf(nomeArquivo, sizeof(nomeArquivo), "%d.txt", num);

            // Criando o arquivo no início do pedido
            FILE *arquivo = fopen(nomeArquivo, "w");
            if (arquivo == NULL) {
                perror("Erro ao criar o arquivo");
                return 1;
            }

            fprintf(arquivo, "Pedido Número: %d\n", num);
            fprintf(arquivo, "--------------------------------\n");
            fclose(arquivo); // Fechamos para abrir depois em modo de append ("a")

            do {
                printf("\n ********  LANCHONETE RATS FRITS  ********\n");
                printf("   1 - LANCHES\n");
                printf("   2 - BEBIDAS\n");
                printf("   3 - SOBREMESAS\n");
                printf("   4 - FINALIZAR PEDIDO\n");
                printf("\n Opção selecionada: ");
                scanf("%d", &iMenuPrincipal);

                switch(iMenuPrincipal) {
                    case 1:
                        // MENU LANCHES
                        do {
                            printf("\n 1 | MISTO         | R$ 2,50 \n");    
                            printf("  2 | PÃO COM OVO   | R$ 3,60 \n");
                            printf("  3 | HOTDOG        | R$ 4,50 \n");
                            printf("  4 | X-SALADA      | R$ 6,00 \n");
                            printf("  5 | X-BACON       | R$ 7,50 \n");
                            printf("  6 | PÃO COM TUDO  | R$ 10,00 \n");
                            printf("  7 - Voltar ao menu principal \n");
                            printf("\n Opção selecionada: ");
                            scanf("%d", &iMenuLanches);

                            // Abre o arquivo em modo append para adicionar cada item
                            FILE *arquivo = fopen(nomeArquivo, "a");
                            if (arquivo == NULL) {
                                perror("Erro ao abrir o arquivo para escrita");
                                return 1;
                            }

                            if (iMenuLanches == 1) {
                                valorLanches += 2.5;
                                fprintf(arquivo, "Lanche: Misto - R$ 2,50\n");
                            } else if (iMenuLanches == 2) {
                                valorLanches += 3.6;
                                fprintf(arquivo, "Lanche: Pão com Ovo - R$ 3,60\n");
                            } else if (iMenuLanches == 3) {
                                valorLanches += 4.5;
                                fprintf(arquivo, "Lanche: Hotdog - R$ 4,50\n");
                            } else if (iMenuLanches == 4) {
                                valorLanches += 6;
                                fprintf(arquivo, "Lanche: X-Salada - R$ 6,00\n");
                            } else if (iMenuLanches == 5) {
                                valorLanches += 7.5;
                                fprintf(arquivo, "Lanche: X-Bacon - R$ 7,50\n");
                            } else if (iMenuLanches == 6) {
                                valorLanches += 10;
                                fprintf(arquivo, "Lanche: Pão com Tudo - R$ 10,00\n");
                            }

                            fclose(arquivo); // Fecha o arquivo após cada escrita
                        } while (iMenuLanches < 7);
                        break;

                    case 2:
                        // MENU BEBIDAS
                        do {
                            printf(" 1 | PINGADO         | R$ 1,20 \n");    
                            printf(" 2 | TUBAINA         | R$ 2,50 \n");
                            printf(" 3 | SODA            | R$ 4,50 \n");
                            printf(" 4 | SUCO            | R$ 5,00 \n");
                            printf(" 5 - Voltar ao Menu Principal \n");
                            printf("\n Opção selecionada: ");
                            scanf("%d", &iMenuBebidas);

                            FILE *arquivo = fopen(nomeArquivo, "a");
                            if (arquivo == NULL) {
                                perror("Erro ao abrir o arquivo para escrita");
                                return 1;
                            }

                            if (iMenuBebidas == 1) {
                                valorBebidas += 1.2;
                                fprintf(arquivo, "Bebida: Pingado - R$ 1,20\n");
                            } else if (iMenuBebidas == 2) {
                                valorBebidas += 2.5;
                                fprintf(arquivo, "Bebida: Tubaina - R$ 2,50\n");
                            } else if (iMenuBebidas == 3) {
                                valorBebidas += 4.5;
                                fprintf(arquivo, "Bebida: Soda - R$ 4,50\n");
                            } else if (iMenuBebidas == 4) {
                                valorBebidas += 5.0;
                                fprintf(arquivo, "Bebida: Suco - R$ 5,00\n");
                            }

                            fclose(arquivo);
                        } while (iMenuBebidas < 5);
                        break;

                    case 3:
                        // MENU SOBREMESAS
                        do {
                            printf(" 1 | ARROZ-DOCE    | R$ 2,50 \n");
                            printf(" 2 | AÇAÍ         | R$ 3,60 \n");
                            printf(" 3 | GELADINHO    | R$ 4,50 \n");
                            printf(" 4 | PÉ-DE-MOLEQUE | R$ 6,00 \n");
                            printf(" 5 - Voltar ao Menu Principal \n");
                            printf("\n Opção selecionada: ");
                            scanf("%d", &iMenuSobremesas);

                            FILE *arquivo = fopen(nomeArquivo, "a");
                            if (arquivo == NULL) {
                                perror("Erro ao abrir o arquivo para escrita");
                                return 1;
                            }

                            if (iMenuSobremesas == 1) {
                                valorSobremesas += 2.5;
                                fprintf(arquivo, "Sobremesa: Arroz-Doce - R$ 2,50\n");
                            } else if (iMenuSobremesas == 2) {
                                valorSobremesas += 3.6;
                                fprintf(arquivo, "Sobremesa: Açaí - R$ 3,60\n");
                            } else if (iMenuSobremesas == 3) {
                                valorSobremesas += 4.5;
                                fprintf(arquivo, "Sobremesa: Geladinho - R$ 4,50\n");
                            }

                            fclose(arquivo);
                        } while (iMenuSobremesas < 5);
                        break;
                        
                    case 4:
                    	
                    	int decisao;
                    	printf("Voce deseja fechar o pedido?\n\n");
                    	printf("SIM\n");
                    	printf("NAO\n");
                    	scanf("%s", &decisao);
                    	
                    	if(decisao == "sim"){
                    		
						}
                }
            } while (iMenuPrincipal != 4);
        }
    } while (iMenuBemVindo < 3);

    return 0;
}

