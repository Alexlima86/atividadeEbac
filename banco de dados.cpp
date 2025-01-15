#include <stdio.h> // user communication library
#include <stdlib.h> // memory space allocation library
#include <locale.h> // text allocation library by region
#include <string.h> // library responsible for creating strings

int registro() // isso � uma fun��o. Peda�o de codigo que faz alguma tarefa em espec�fico e pode ser chamado de qualquer parte do programa qts vzs necess�rio. Uma fun��o n�o enxerga a outra pq sao independentes.
{
	
	// inicio cria��o de variaveis/strings
	char arquivo[40];// esse variavel ser� o arquivo com o mesmo nome do CPF, e sempre mudar� sempre que criar um usu�rio/cliente novo. Ou seja, vai copiar o valor do CPF na variavel arquivo.
	char cpf[40]; // char � uma variavel de texto, e o "[40]" � uma sequencia de no maximo 40 cararacteres que formaram o texto. Essa sequencia de caracteres de letras chama-se String.
	char nome[40]; // nesse caso, nao � necess�rio atribuir um valor 0 (zero) � variavel.
	char sobrenome[40]; // "char" � uma variavel e � utilizado para definir um ou mais valores que s�o manipulados por um programa durante opera��o.
	char cargo[40]; //  o nome vari�vel � utilizado por ser um conte�dop que muda de valor conforme a execus�o do programa/sistema. Ex: de variaveis (INT, CHAR, FLOAT, DOUBLE, STRING, BOOLEAN...)
	
	//coletando info dos usuarios.
	printf("digite o cpf a ser cadastrado: ");   // aqui ultilizarmos o CPF como a chave que nomear� cada usuario/cliente. Lembrando que o banco de dado precisa de um nome unico para poder ser identificado, encontrado e/ou chamado dentro do banco de dados.
	scanf("%s", cpf);   // armazenamento da informa�ao. o "%S" � pq a variavel � uma string. Observar se a biblioteca  #include <string.h> esta declarada. o "cpf" nesse caso � a variavel onde esta sendo armazenado as informa��es.
	
	strcpy(arquivo, cpf); // essa fun��o � para copiar a string de 40 caracteres. Nesse caso copiar� do cpf para o arquivo.
	
	FILE *file; //Cria arquivo. A fun��o "FILE" j� existe, entao aqui estamos chamando ela. o *file � o arquico da qual estou criando agora.
	file = fopen(arquivo, "w"); // fopnen eu estou pedindo para abrir um arquivo, que nesse caso, � a nossa variavel "arquivo" que tem o nome do CPF. o comando "w" vem de write, que significa que iremos escrever ou edita-lo.
	fprintf(file, cpf);  // o "fprintf" � a fun��o que ir� salvar no arquivo "file" a variavel CPF
	fclose(file); // aqui fecha o arquivo
	
	file = fopen(arquivo, "a"); // fopnen eu estou pedindo para abrir um arquivo, que nesse caso, � a nossa variavel "arquivo" que tem o nome do CPF. o comando "a" significa iremos atualizar o arquivo.
	fprintf(file, ","); // dentro do arquivo vou colocar uma "," para separar
	fclose(file); // aqui fecha o arquivo
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome); // estamos salvando em uma string, e na variavel nome
	
	file = fopen(arquivo, "a"); // recaptulando. Aqui esta sendo aberto o arquivo (que � o nome da variavel declarado acima, e estou dando a instru�ao que que o arquivo ser� atualizado "a"
	fprintf(file, nome); // aqui o arquivo entende que o que ser� atualizado � a variavel nome
	fclose(file); // aqui estou fechando a arquivo com a fun��o "fclose"
	
	file = fopen(arquivo, "a"); // idem em refer�ncia com a instrucao acima
	fprintf(file,","); // aqui estou instruindo para que o sistema adicione uma "," para que tenha mais organiza��o no momento da impress�o na tela.
	fclose(file); // fecha arquivo
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
}	


int consulta()
{
	setlocale(LC_ALL, "Portuguese");  // a categoria da liguagem da qual estamos falando � portugues, para o programa entender os acentos em pontua��es

	char cpf[40];	// aqui vamos novamente criar o arquivo que tem o nome do CPF para consulta-lo. Como estamos em uma fun��o � parte, esse arquivo deve ser criado novamente independente de ter sido criado na fun��o anterior.
	char conteudo[200]; // a variavel acima apenas esta pedindo para o sistema localizar e ler o arquivo que esta salvo com o nome do CPF. Nessa, o sistema pede para que a informa��o buscada seja armazenada na variavel conte�do.
	
	printf("Digite o CPF a ser consultado: "); // pe�o ao usuario/cliente pra digitar o a informa�ao desejada
	scanf("%s", cpf); // aqui eu pe�o para o sistema salva a informa�ao digitada na variavel "cpf"
	
	FILE * file; // sistema sabendo o que o sistema esta procurando, agora ele ira atraz desse arquivo em FILE, que APARENTEMENTE � uma pasta
	file = fopen(cpf, "r"); // apos encontrado o arquivo buscado, o sistema abre-o e o consulta atraves do comando "r" de read (ler), pois � apenas consulta
	
	if(file == NULL) // Aqui estou pedindo para o sistema me alertar caso o numero do CPF digitado nao for encontrado no sistema.
	{
		printf("Arquivo n�o localizado. Digite novamente. \n"); // msg de aviso caso informa�ao nao for encontrada.
	}
	
	while(fgets(conteudo, 200, file) != NULL) 	// o fato de termos usado uma variavel do tipo string (sequencia de variaveis, no caso do CONTE�DO, 200 variaveis), preciso pedir que o sistema salve cada caractere do CONTEUDO ate acabar. Por isso iremos usar um la�o de repeti��o
	{	// a instru�ao acima diz que, enquanto (while) esta buscando no arquivo o conteudo (conteudo), com tamanho maximo de 200 (200) entao repetir� o ciclo 200 vezes dentro do arquivo (file) e ir� parar somente quando a informa�ao recebida pelo usuario for nulo (!=NULL)
		printf("\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s",conteudo); // informa��o buscada com a instru��o acima e apresentada na tela.
		printf("\n\n");	// 2 linhas puladas para fins est�tico
	}
	
	system("pause"); // sistema da um pause aqui.
}

int deletar() 
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);  // scannea tudo o que o usuario digitou e ir� salvar na variarel "cpf" declado acima.
	
	remove(cpf);
	
	FILE*file; // estou pedido para acessar a fun��o FILE da biblioteca. e dentro dela puxar os arquivos (file)
	file = fopen(cpf, "r"); // com o aquivo "file" � disposi��o, estarei dando a ordem de abrir esse arquivo (fopen), q nada mais � o arquivo de CPF, e entao, pedirei para ler ("r")
	
	if(file == NULL)
	{
		printf("Usu�rio nao encontrado. \n");
		system("pause"); // sistema da um pause aqui para que o usu�rio possa ter tempo para ler o status atual do sistema.	
	}
		
}


int main()
    {
	int opcao=0; // Ao declarar essa variavel, o sistema aloca um espa�o de mem�rio. Ent�o, � atribuido um valo Zero (0) para que seja setado o valor nessa variavel.
	int laco=1;
	
	for(laco=1;laco=1;) // Operador de repeti��o. Utilizado para qnd for preciso repetir o codigo/valida�ao varias vezes, evitando ficar copiando e colando algum techo de codigo varias vezes.
	{
	
		system("cls"); // o "cls" serve para limpar a informa��o print anterior
		
		setlocale(LC_ALL, "Portuguese");  // a categoria da liguagem da qual estamos falando � portugues, para o programa entender os acentos em pontua��es
	
		printf("### CART�RIO DA EBAC ###\n\n");  // \n significa espa�os abaixo da frase. Essa linha � o Inicio do MENU.
		printf("Escolha a op��o desejada do MENU:\n\n");
		printf("\t1 - Registrar nomes\n"); // o simbolo /t s�o os espa�os horizontais
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Essa linha � o Fim do MENU.
		printf("\t4 - Sair do sistema\n\n\n"); // Essa linha � o Fim do MENU.

		printf("Op��o: ");
		
		scanf("%d", &opcao); // Aqui escanear e armazena a escolha do usu�rio.  Para armazenar uma variave do tipo inteiro, usa o "%d". O "&opcao" � a variavel atribuida no inicio do codigo. Aqui no "scanf" o programa fica pausado aguardado intru��o do usu�rio.
		
		system("cls"); //Responsavel por limpar a tela. Comando usado para chamar o sistema. Tem por fun�ao limpar a tela. Deleta todas as menssagens que tnha antes
		
		switch(opcao)
		{
			case 1:
			registro();
			break;	
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema \n");
			return 0; // Quebra `a fun��o zero. Quebro la�o, fun��o e etc e retorna do zero saindo do sistema
			
			default:
			printf("Opcao inv�lida!\n");
			system("pause");
			break;
		}	
   
   }

}
		
		
		
		
		
		

