#include <stdio.h> //bblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de es��o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema 
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // cria o arquivo
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //colentando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");// cria o arquivo
	fprintf(file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a");// cria o arquivo
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");
	
} 

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagens
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado! .\n");	
	} 

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
		
	}
	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do us�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		printf("excluido com sucesso!.\n");
		system("pause");
	}


}


int main()
   {
	int opcao=0; //Definindo vari�veis  
	int laco=1;
	
	 for(laco=1;laco=1;)
     {
     	system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagens
	
 		
         printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
         printf("escolha a op��o desejada do menu:\n\n");
         printf("\t1 - registrar nomes\n");
         printf("\t2 - consultar nomes\n");
         printf("\t3 - deletar nomes\n\n");
         printf("\t4 - Sair do sistema\n\n");
		 printf("op��o: ");    //Fim do menu 
         
         
	    scanf("%d", &opcao); //Armazenamento a escolha do usu�rio
        
        
		system("cls");//responasevl por limpar a tela
        
	 	switch(opcao) //in�cio da sele��o do menu
	{
		case 1: 
		registro(); //chamada de fun��es
	    break;
	
	    case 2: 
		consulta(); //chamada de fun��es
        break;
        
       
	    case 3: 
	    deletar(); //chamada de fun��es
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
	    
	    default:
	    printf ("Essa op��o n�o est� dispon�vel!\n");
        system("pause");
		break;	
	}
	
}


} 





