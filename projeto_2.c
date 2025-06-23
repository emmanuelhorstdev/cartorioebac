#include <stdio.h>  //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar do string

int registro() // Fun��o responsavel por cadastrar os usuarios no sistema
{
	// Inicio da cria��o de vari�veis/String
	char arquivo[40];
	char cpf[40];
	char nome[60];
	char sobrenome[60];
	char cargo [40];
	//Final da cria��o de vari�veis/String
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o de variaveis 
	scanf("%s", cpf); //%s = armazenando na string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // escrever uma informa��o w = write 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualizar informa��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //salvar na string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	system("pause");
	
	
}

int consultar()
{	
	setlocale(LC_ALL, "Portuguese");

	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o foi localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! .\n");
		system("pause");
			
	}
	
	else
	
	 { 
	    fclose(file);
		if (remove(cpf) == 0)
	 	{
	 	
	 	printf("Usu�rio deletado com sucesso!\n");
	 	system("pause");
	 	
		}
	 	
	 	else
	 
	 	{
	 	
		 printf("Erro ao deletar o usu�rio!\n");
	 	system("pause");
	 	
	 	}
	 	
	 }
	 return 0;
}

int main()
    {
	int opcao=0;  //definindo variaveis
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
	{
		
		system("cls"); //resposnavel por limpar a tela 
	
	 	setlocale(LC_ALL, "PORTUGUESE"); // definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do programa\n \n");
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario

    	system("cls");
    	
    	
    	switch (opcao)
    	{
    		case 1:
    		registro(); // chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
    		
    		case 3:
    		deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o esta disponivel!\n");
			system("pause");
			break;	
		} // sele��o 
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


