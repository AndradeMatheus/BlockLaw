/* HACKATON AASP 

GRUPO: BLOCKLAW
- Denis Dickson
- Ezequiel Costa
- Matheus Andrade
- Michelly Almeida

Notes: 

Os 'system('CLS')' foram todos comentados por haver conflitos entre compiladoes (MINGw64 e GCC)
O código final de :121-125 é a informação que deveria ser incluída entre os blócos do blockchain 
então é totalmente uma simulação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define PDT (-3)

bool loginExiste = false, cadastroAuth = false;
int resposta = 3, i, tempo;
float valor;
char login[30], senha[30], loginAuth[30], senhaAuth[30], nome[30], artista[30], musica[30], nomeUser[30], tempoChar[10];
char tabela1[5][30] = {{"Los Hermanos"}, {"Mastodon"}, {"Coldplay"}, {"Sid Berrett"}, {"Mamonas Assassinas"}};
char tabela2[5][30] = {{"Ultimo Romance"}, {"Blood and Thunder"}, {"Magic"}, {"Octopus"}, {"Brasilia Amarela"}};

bool loginAuthenticator(char log[30], char pass[30], char logComp[30], char passComp[30])
{
	int l, p;
	l = strcmp(log, logComp);
	p = strcmp(pass, passComp);

	if(l == 0){
		if(p == 0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}


void main()
{
	struct tm *gtime;
    time_t now;

	while(resposta > 0){
		printf("=========================\n");
		printf("==========MENU===========\n");
		printf("[1] - Cadastro de Advogado\n");
		printf("[2] - Login de Advogado\n");
		printf("[0] - Sair\n");
		printf("Resposta: ");
		scanf("%d", &resposta);

		switch (resposta){
		case 1:
			//system('CLS');
			printf("=======================\n");
			printf("========CADASTRO=======\n");
			printf("Nome: ");
			scanf("%s", nome);
			printf("Login: ");
			scanf("%s", login);
			if (login != "" || login != 0){
				printf("Senha: ");
				scanf("%s", senha);	
				if (senha != "" || senha != 0){
					loginExiste = true;
					break;
				}else{
					//system('CLS')
					printf("Campo de senha vaziom reiniciando... \n");
				}
			}else{
				//system('CLS');
				printf("Campo de login vazio, reiniciando... \n");
				break;
			}
		break;
		case 2:
			//system('CLS');
			if (loginExiste == true){
				printf("=====================\n");
				printf("========LOGIN========\n");
				printf("Login: ");
				scanf("%s", loginAuth);
				printf("Senha: ");
				scanf("%s", senhaAuth);
				cadastroAuth = loginAuthenticator(login, senha, loginAuth, senhaAuth);
				if (cadastroAuth == true){
					//system('CLS');
					printf("Bem vindo %s!\n", nome);
					printf("=====================\n");
					printf("Escolha um artista/música:\n");
					for(i = 0; i <5; i++){
						printf("[%d] - %s / %s\n", i+1, tabela1[i], tabela2[i]);
					}
					printf("R: ");
					scanf("%d", &i);
					strcpy(artista, tabela1[i-1]);
					strcpy(musica, tabela2[i-1]);

					printf("====================\n");
					printf("O nome do seu cliente: ");
					scanf("%s", nomeUser);
					printf("Valor da transação (EHT): ");
					scanf("%f", &valor);
					printf("O período é em dias, meses ou anos?\nR: ");
					scanf("%s", tempoChar);
					printf("Por quantos %s?\nR: ", tempoChar);
					scanf("%d", &tempo);

					//system('CLS');
					printf("\n\nO(A) advogado(a) %s mediou a aquisição da música %s do(a) ", nome, musica);
					printf("artista %s por uma transação de %f ETH para o(a) ", artista, valor);
					printf("usuário(a) %s com limite de uso de %d %s\nCaso o contrato ", nomeUser, tempo, tempoChar); 
					printf("não seja cumprido, haverá a cobrança de multa de %f ETH.\n", (0.02*valor + valor));
					printf("\n Transação efetuada (%li): \n -%f | 0xA (%s) \n +%f | 0xB (%s)\n", time(&now), valor, nomeUser, valor, artista);

				}else{
					printf("Informações incorretas.\n");
					//system('CLS');
				}
			}else{
				//system('CLS');
				printf("Não há cadastro realizado, realize o cadastro.\n");
			}
		break;
		default:
			//system('CLS');
			printf("Seleção inválida\n");
		}
	}
	//system('CLS');
	printf("Saindo...");
}