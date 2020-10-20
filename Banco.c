#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro_cliente{
	char nome[50];
	int num_conta;
	int senha;
	char chave[3];
	float saldo;
}cad_cliente[26];

int criar_conta(int indice);
void consultar_saldo();
void deposito();
void saque();
void encerrar_conta();

int main(void){

	int op = -1, posicao = 0, retorno;
	do{
		printf("Bem Vindo!\n\n");
		printf("Escolha a operacao desejada: \n");
		printf("1 - Criar conta\n");
		printf("2 - Consultar saldo\n");
		printf("3 - Deposito\n");
		printf("4 - Saque\n");
		printf("5 - Encerrar conta\n");
		printf("0 - sair\n");
		scanf("%d", &op);

		switch(op){

			case 0:
				system("cls");
				printf("Fim do programa");
				break;
			case 1:
				system("cls");
				retorno = criar_conta(posicao);
				if(retorno == 0){
					posicao++;
				}
				break;
			case 2:
				system("cls");
				consultar_saldo();
				break;
			case 3:
				system("cls");
				deposito();
				break;
			case 4:
				system("cls");
				saque();
				break;
			case 5:
				system("cls");
				encerrar_conta();
				break;
			default:
				system("cls");
				if(op != 0){
					printf("Opcao invalida!\n");
					break;
				}
		}
	}while(op != 0);

	return 0;
}

int criar_conta(int indice){

	int numConta, senha, i;
	char string[50];
	char key[4];

	printf("Digite o seu primeiro nome: ");
	scanf("%s", &string);
	printf("Digite o numero da conta( max: 8 digitos): ");
	scanf("%d", &numConta);
	printf("Digite a senha numerica(max: 4 digitos): ");
	scanf("%d", &senha);
	printf("Digite a chave de seguranca(max: 1 caractere ente a e z): ");
	scanf("%s", &key);

	for(i = 0; i < 26; i++){
		if(cad_cliente[i].num_conta == numConta){
			printf("Numero de conta ja existe. Tente novamente!\n\n");
			return 1;
			break;
		}else if(strcmp(cad_cliente[i].chave, key) == 0){
			printf("Chave de seguranca ja existe. Tente novamente!\n\n");
			return 1;
			break;
		}else{
			printf("Conta cadastrada com sucesso!\n\n");
			strcpy(cad_cliente[indice].nome, string);
			cad_cliente[indice].num_conta = numConta;
			cad_cliente[indice].senha = senha;
			strcpy(cad_cliente[indice].chave, key);
			cad_cliente[indice].saldo = 0.0;
			return 0;
			break;
		}
	}
}

void consultar_saldo(){

	int numConta, i, senha;

	printf("Digite o numero da sua conta: ");
	scanf("%d", &numConta);

	for(i = 0; i < 26; i++){
		if(numConta == cad_cliente[i].num_conta){

			printf("Digite a senha numerica: ");
			scanf("%d", &senha);

			if(senha == cad_cliente[i].senha){
				printf("Ola %s. Seu saldo e de: R$%.2f\n", cad_cliente[i].nome, cad_cliente[i].saldo);
				break;
			}else{
				printf("Senha incorreta!\n");
				break;
			}
		}else if(numConta != cad_cliente[i].num_conta && i == 25){
			printf("Conta inexistente!\n\n");
		}
	}
}

void deposito(){

	int numConta, valor, opcao, i;

	printf("Digite o numero da sua conta: ");
	scanf("%d", &numConta);

	printf("Digite o valor que deseja depositar: ");
	scanf("%d", &valor);

	for(i = 0; i < 26; i++){
		if(numConta == cad_cliente[i].num_conta){

			printf("\n---------------------------\n");
			printf("Confirme se esta e mesmo a sua conta: (1-sim 2-nao)!\n\n");
			printf("Nome: %s\n", cad_cliente[i].nome);
			printf("Numero da Conta: %d\n", cad_cliente[i].num_conta);
			printf("\n---------------------------\n");

			scanf("%d", &opcao);

			if(opcao == 1){
				cad_cliente[i].saldo += valor;
				printf("Deposito realizado com sucesso! O seu saldo atual e de: R$%.2f\n", cad_cliente[i].saldo);
				break;
			}else if(opcao == 2){
				printf("");
				break;
			}else{
				printf("Opcao invalida!\n");
				break;
			}
		}else if(numConta != cad_cliente[i].num_conta && i == 25){
			printf("Conta inexistente!\n\n");
		}
	}
}

void saque(){

	int numConta, valor_saque, i, senha;
	char chave_seg[3];

	printf("Digite o numero da sua conta: ");
	scanf("%d", &numConta);

	printf("Digite o valor que deseja sacar: ");
	scanf("%d", &valor_saque);

	for(i = 0; i < 26; i++){
		if(numConta == cad_cliente[i].num_conta && valor_saque <= cad_cliente[i].saldo){

			printf("Digite a senha numerica: ");
			scanf("%d", &senha);

			printf("Digite a chave de seguranca: ");
			scanf("%s", &chave_seg);

			if(senha == cad_cliente[i].senha && strcmp(chave_seg, cad_cliente[i].chave) == 0){
				cad_cliente[i].saldo -= valor_saque;
				printf("Ola %s. Saque realizado com sucesso! O seu saldo atual e de: R$%.2f\n\n", cad_cliente[i].nome, cad_cliente[i].saldo);
				break;
			}else if(senha != cad_cliente[i].senha){
				printf("Senha incorreta! Nao foi possivel realizar o saque.\n");
				break;
			}else if(chave_seg != cad_cliente[i].chave){
				printf("Chave incorreta! Nao foi possivel realizar o saque.\n");
				break;
			}
		}else if(numConta == cad_cliente[i].num_conta && valor_saque >= cad_cliente[i].saldo){
			printf("Nao foi possivel realizar o saque. O valor de saque e maior que o seu saldo!\n\n");
			break;
		}else if(numConta != cad_cliente[i].num_conta && i == 25){
			printf("Conta inexistente!\n\n");
		}
	}
}

void encerrar_conta(){
	int numConta, senha, opcao, i, j;
	char chave_seg[3];

	printf("Digite o numero da conta: ");
	scanf("%d", &numConta);

	for(i = 0; i < 26; i++){
		if(numConta == cad_cliente[i].num_conta){
			printf("Digite sua senha numerica: ");
			scanf("%d", &senha);

			if(senha == cad_cliente[i].senha){
				printf("Digite sua chave de seguranca: ");
				scanf("%s", &chave_seg);
				if(strcmp(chave_seg, cad_cliente[i].chave) == 0){
					j = i;

					printf("Tem certeza que deseja encerrar esta conta? (1-SIM 2-NAO)\n\n");
					printf("Nome: %s\n", cad_cliente[i].nome);
					printf("Numero da conta: %d\n", cad_cliente[i].num_conta);
					scanf("%d", &opcao);

					if(opcao == 1 && cad_cliente[i].saldo == 0.0){
						while(j < 26){
							cad_cliente[j] = cad_cliente[j+1];
							j++;
						}
						printf("Conta encerrada com sucesso!\n");
						break;
					}else{
						printf("Nao foi possivel encerrar sua conta pois voce ainda tem saldo positivo\n");
						break;
					}
				}else{
					printf("Chave incorreta!\n");
					break;
				}
			}else{
				printf("Senha incorreta!\n");
				break;
			}
		}else if(numConta != cad_cliente[i].num_conta && i == 25){
			printf("Conta inexistente!\n");
		}
	}
}

