#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria.
#include <locale.h> //biblioteca de aloca��es de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das string.

int registro(){ //Fun��o respons�vel por gerar um arquivo de cadastro de usu�rio no sistema.

	//�nicio da cria��o de string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de string.
	
	printf("Digite o CPF do jogador a ser cadastrado: "); //Coleta de informa��es para a cria��o do arquivo.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo.
	fprintf(file, cpf); //salva o valor da vari�vel.
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

int consulta(){ //Fun��o respons�vel por consultar um arquivo j� existente no sistema e mostrar suas infoma��es caso encontrado.
	setlocale(LC_ALL, "Portuguese"); //Mesmo se um comando como esse j� estiver em outra fun��o, ele deve ser declarado novamente pois a maquina sozinha n�o faz essa liga��o de uma fun��o para outra.
	//�nicio da cria��o de vari�veis.
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){ //Se o arquivo desejado n�o existir/n�o for encontrado, mostre essa mensagem.
		printf("Meu cria, esse arquivo n�o existe.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){ //Sen�o, analise o documento encontrado e mostre as informa��es contidas para o usu�rio.
		printf("\nEssas s�o as informa��es encontradas para este CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause"); 
}

int deletar(){ //Fun��o respons�vel pela exclus�o de um arquivo j� existente no sistema.
	
	char cpf[40];
	
	printf("Digite o CPF do jogador a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL){
		printf("Esse jogador n�o foi encontrado no sistema.\n");
		system("pause");
	}
	else{
		remove(cpf); //Comando para deletar o arquivo.
		printf("Jogador deletado com sucesso.");
		system("pause");
	}
	
}

int padrao(){ //Fun��o para caso o usu�rio escolha qualquer outra op��o que n�o seja uma das 3.
	printf("Quando for 12:99 eu fa�o essa op��o, ent�o escolhe uma das 3 por favor.\n"); 
	system("pause");
}


int main(){ //B�sicamente o corpo do menu que ser� apresentado ao usu�rio.
	
	int opcao=0; //Definindo vari�veis.
	//O s�mbolo "=" significa valida��o, essa vari�vel vale 0.
	int repetir=1;
	
	for(repetir=1;repetir=1;){	
	
		system("cls"); //Comando respons�vel por limpar a tela ap�s uma nova sele��o, o fim da polui��o visual.
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem.
		//O setlocale varia dependendo do sistema operacional utilizado.
	
		printf("### Cart�rio do Steve do Minecraftkkkj ###\n\n"); //Come�o do menu.
		printf("Escolha uma das seguintes op��es:\n\n");
		printf("\t1 - Registrar novo jogador.\n");
		printf("\t2 - Consultar jogadores registrados.\n");
		printf("\t3 - Excluir jogador.\n\n\n"); //Fim do menu.
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Scan � um comando para o usu�rio armazenar informa��es.
	
		system("cls"); //System � um comando para falar com o sistema operacional e o CLS � para limpar a tela tornando agradav�l para o usu�rio, esse comando � o mesmo para todos os sistemas operacionais.
		
		switch(opcao){ //�nicio das op��es.
			case 1:
				registro(); //chamada de fun��es: registro.
			break;
			
			case 2:
				consulta(); //chamada de fun��es: consulta.
			break;
			
			case 3:
				deletar(); //chamada de fun��es: deletar.
			break;
			
			default:
				padrao(); //chamada de fun��es: nenhuma das anteriores.
			break;
		} //Fim das op��es.
	}
}

