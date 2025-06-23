#include <stdio.h>  //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar do string

int registro() // Função responsavel por cadastrar os usuarios no sistema
{
	// Inicio da criação de variáveis/String
	char arquivo[40];
	char cpf[40];
	char nome[60];
	char sobrenome[60];
	char cargo [40];
	//Final da criação de variáveis/String
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação de variaveis 
	scanf("%s", cpf); //%s = armazenando na string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // escrever uma informação w = write 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualizar informação
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
		printf("Não foi possível abrir o arquivo, não foi localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! .\n");
		system("pause");
			
	}
	
	else
	
	 { 
	    fclose(file);
		if (remove(cpf) == 0)
	 	{
	 	
	 	printf("Usuário deletado com sucesso!\n");
	 	system("pause");
	 	
		}
	 	
	 	else
	 
	 	{
	 	
		 printf("Erro ao deletar o usuário!\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do programa\n \n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario

    	system("cls");
    	
    	
    	switch (opcao)
    	{
    		case 1:
    		registro(); // chamada de funções
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
			printf("Esta opção não esta disponivel!\n");
			system("pause");
			break;	
		} // seleção 
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


