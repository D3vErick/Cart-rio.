#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço de memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das string.

int registro(){ //Função responsável por gerar um arquivo de cadastro de usuário no sistema.

	//Ínicio da criação de string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de string.
	
	printf("Digite o CPF do jogador a ser cadastrado: "); //Coleta de informações para a criação do arquivo.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo.
	fprintf(file, cpf); //salva o valor da variável.
	fclose(file); //fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome do jogador a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome do jogador a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo do jogador a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){ //Função responsável por consultar um arquivo já existente no sistema e mostrar suas infomações caso encontrado.
	setlocale(LC_ALL, "Portuguese"); //Mesmo se um comando como esse já estiver em outra função, ele deve ser declarado novamente pois a maquina sozinha não faz essa ligação de uma função para outra.
	//Ínicio da criação de variáveis.
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){ //Se o arquivo desejado não existir/não for encontrado, mostre essa mensagem.
		printf("Meu cria, esse arquivo não existe.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Senão, analise o documento encontrado e mostre as informações contidas para o usuário.
		printf("\nEssas são as informações encontradas para este CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause"); 
}

int deletar(){ //Função responsável pela exclusão de um arquivo já existente no sistema.
	
	char cpf[40];
	
	printf("Digite o CPF do jogador a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		printf("Esse jogador não foi encontrado no sistema.\n");
		system("pause");
	}
	else{
		remove(cpf); //Comando para deletar o arquivo.
		printf("Jogador deletado com sucesso.");
		system("pause");
	}
	
}

int padrao(){ //Função para caso o usuário escolha qualquer outra opção que não seja uma das 3.
	printf("Quando for 12:99 eu faço essa opção, então escolhe uma das 3 por favor.\n"); 
	system("pause");
}


int main(){ //Básicamente o corpo do menu que será apresentado ao usuário.
	
	int opcao=0; //Definindo variáveis.
	//O símbolo "=" significa validação, essa variável vale 0.
	int repetir=1;
	
	for(repetir=1;repetir=1;){	
	
		system("cls"); //Comando responsável por limpar a tela após uma nova seleção, o fim da poluição visual.
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem.
		//O setlocale varia dependendo do sistema operacional utilizado.
	
		printf("### Cartório do Steve do Minecraftkkkj ###\n\n"); //Começo do menu.
		printf("Escolha uma das seguintes opções:\n\n");
		printf("\t1 - Registrar novo jogador.\n");
		printf("\t2 - Consultar jogadores registrados.\n");
		printf("\t3 - Excluir jogador.\n\n\n"); //Fim do menu.
		printf("Opção: ");
	
		scanf("%d", &opcao); //Scan é um comando para o usuário armazenar informações.
	
		system("cls"); //System é um comando para falar com o sistema operacional e o CLS é para limpar a tela tornando agradavél para o usuário, esse comando é o mesmo para todos os sistemas operacionais.
		
		switch(opcao){ //Ínicio das opções.
			case 1:
				registro(); //chamada de funções: registro.
			break;
			
			case 2:
				consulta(); //chamada de funções: consulta.
			break;
			
			case 3:
				deletar(); //chamada de funções: deletar.
			break;
			
			default:
				padrao(); //chamada de funções: nenhuma das anteriores.
			break;
		} //Fim das opções.
	}
}

