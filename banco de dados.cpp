#include <stdio.h> // user communication library
#include <stdlib.h> // memory space allocation library
#include <locale.h> // text allocation library by region
#include <string.h> // library responsible for creating strings

int registro() // isso é uma função. Pedaço de codigo que faz alguma tarefa em específico e pode ser chamado de qualquer parte do programa qts vzs necessário. Uma função não enxerga a outra pq sao independentes.
{
	
	// inicio criação de variaveis/strings
	char arquivo[40];// esse variavel será o arquivo com o mesmo nome do CPF, e sempre mudará sempre que criar um usuário/cliente novo. Ou seja, vai copiar o valor do CPF na variavel arquivo.
	char cpf[40]; // char é uma variavel de texto, e o "[40]" é uma sequencia de no maximo 40 cararacteres que formaram o texto. Essa sequencia de caracteres de letras chama-se String.
	char nome[40]; // nesse caso, nao é necessário atribuir um valor 0 (zero) à variavel.
	char sobrenome[40]; // "char" é uma variavel e é utilizado para definir um ou mais valores que são manipulados por um programa durante operação.
	char cargo[40]; //  o nome variável é utilizado por ser um conteúdop que muda de valor conforme a execusão do programa/sistema. Ex: de variaveis (INT, CHAR, FLOAT, DOUBLE, STRING, BOOLEAN...)
	
	//coletando info dos usuarios.
	printf("digite o cpf a ser cadastrado: ");   // aqui ultilizarmos o CPF como a chave que nomeará cada usuario/cliente. Lembrando que o banco de dado precisa de um nome unico para poder ser identificado, encontrado e/ou chamado dentro do banco de dados.
	scanf("%s", cpf);   // armazenamento da informaçao. o "%S" é pq a variavel é uma string. Observar se a biblioteca  #include <string.h> esta declarada. o "cpf" nesse caso é a variavel onde esta sendo armazenado as informações.
	
	strcpy(arquivo, cpf); // essa função é para copiar a string de 40 caracteres. Nesse caso copiará do cpf para o arquivo.
	
	FILE *file; //Cria arquivo. A função "FILE" já existe, entao aqui estamos chamando ela. o *file é o arquico da qual estou criando agora.
	file = fopen(arquivo, "w"); // fopnen eu estou pedindo para abrir um arquivo, que nesse caso, é a nossa variavel "arquivo" que tem o nome do CPF. o comando "w" vem de write, que significa que iremos escrever ou edita-lo.
	fprintf(file, cpf);  // o "fprintf" é a função que irá salvar no arquivo "file" a variavel CPF
	fclose(file); // aqui fecha o arquivo
	
	file = fopen(arquivo, "a"); // fopnen eu estou pedindo para abrir um arquivo, que nesse caso, é a nossa variavel "arquivo" que tem o nome do CPF. o comando "a" significa iremos atualizar o arquivo.
	fprintf(file, ","); // dentro do arquivo vou colocar uma "," para separar
	fclose(file); // aqui fecha o arquivo
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome); // estamos salvando em uma string, e na variavel nome
	
	file = fopen(arquivo, "a"); // recaptulando. Aqui esta sendo aberto o arquivo (que é o nome da variavel declarado acima, e estou dando a instruçao que que o arquivo será atualizado "a"
	fprintf(file, nome); // aqui o arquivo entende que o que será atualizado é a variavel nome
	fclose(file); // aqui estou fechando a arquivo com a função "fclose"
	
	file = fopen(arquivo, "a"); // idem em referência com a instrucao acima
	fprintf(file,","); // aqui estou instruindo para que o sistema adicione uma "," para que tenha mais organização no momento da impressão na tela.
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
	setlocale(LC_ALL, "Portuguese");  // a categoria da liguagem da qual estamos falando é portugues, para o programa entender os acentos em pontuações

	char cpf[40];	// aqui vamos novamente criar o arquivo que tem o nome do CPF para consulta-lo. Como estamos em uma função à parte, esse arquivo deve ser criado novamente independente de ter sido criado na função anterior.
	char conteudo[200]; // a variavel acima apenas esta pedindo para o sistema localizar e ler o arquivo que esta salvo com o nome do CPF. Nessa, o sistema pede para que a informação buscada seja armazenada na variavel conteúdo.
	
	printf("Digite o CPF a ser consultado: "); // peço ao usuario/cliente pra digitar o a informaçao desejada
	scanf("%s", cpf); // aqui eu peço para o sistema salva a informaçao digitada na variavel "cpf"
	
	FILE * file; // sistema sabendo o que o sistema esta procurando, agora ele ira atraz desse arquivo em FILE, que APARENTEMENTE é uma pasta
	file = fopen(cpf, "r"); // apos encontrado o arquivo buscado, o sistema abre-o e o consulta atraves do comando "r" de read (ler), pois é apenas consulta
	
	if(file == NULL) // Aqui estou pedindo para o sistema me alertar caso o numero do CPF digitado nao for encontrado no sistema.
	{
		printf("Arquivo não localizado. Digite novamente. \n"); // msg de aviso caso informaçao nao for encontrada.
	}
	
	while(fgets(conteudo, 200, file) != NULL) 	// o fato de termos usado uma variavel do tipo string (sequencia de variaveis, no caso do CONTEÚDO, 200 variaveis), preciso pedir que o sistema salve cada caractere do CONTEUDO ate acabar. Por isso iremos usar um laço de repetição
	{	// a instruçao acima diz que, enquanto (while) esta buscando no arquivo o conteudo (conteudo), com tamanho maximo de 200 (200) entao repetirá o ciclo 200 vezes dentro do arquivo (file) e irá parar somente quando a informaçao recebida pelo usuario for nulo (!=NULL)
		printf("\nEssas são as informações do usuário: "); 
		printf("%s",conteudo); // informação buscada com a instrução acima e apresentada na tela.
		printf("\n\n");	// 2 linhas puladas para fins estético
	}
	
	system("pause"); // sistema da um pause aqui.
}

int deletar() 
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);  // scannea tudo o que o usuario digitou e irá salvar na variarel "cpf" declado acima.
	
	remove(cpf);
	
	FILE*file; // estou pedido para acessar a função FILE da biblioteca. e dentro dela puxar os arquivos (file)
	file = fopen(cpf, "r"); // com o aquivo "file" à disposição, estarei dando a ordem de abrir esse arquivo (fopen), q nada mais é o arquivo de CPF, e entao, pedirei para ler ("r")
	
	if(file == NULL)
	{
		printf("Usuário nao encontrado. \n");
		system("pause"); // sistema da um pause aqui para que o usuário possa ter tempo para ler o status atual do sistema.	
	}
		
}


int main()
    {
	int opcao=0; // Ao declarar essa variavel, o sistema aloca um espaço de memório. Então, é atribuido um valo Zero (0) para que seja setado o valor nessa variavel.
	int laco=1;
	
	for(laco=1;laco=1;) // Operador de repetição. Utilizado para qnd for preciso repetir o codigo/validaçao varias vezes, evitando ficar copiando e colando algum techo de codigo varias vezes.
	{
	
		system("cls"); // o "cls" serve para limpar a informação print anterior
		
		setlocale(LC_ALL, "Portuguese");  // a categoria da liguagem da qual estamos falando é portugues, para o programa entender os acentos em pontuações
	
		printf("### CARTÓRIO DA EBAC ###\n\n");  // \n significa espaços abaixo da frase. Essa linha é o Inicio do MENU.
		printf("Escolha a opção desejada do MENU:\n\n");
		printf("\t1 - Registrar nomes\n"); // o simbolo /t são os espaços horizontais
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Essa linha é o Fim do MENU.
		printf("\t4 - Sair do sistema\n\n\n"); // Essa linha é o Fim do MENU.

		printf("Opção: ");
		
		scanf("%d", &opcao); // Aqui escanear e armazena a escolha do usuário.  Para armazenar uma variave do tipo inteiro, usa o "%d". O "&opcao" é a variavel atribuida no inicio do codigo. Aqui no "scanf" o programa fica pausado aguardado intrução do usuário.
		
		system("cls"); //Responsavel por limpar a tela. Comando usado para chamar o sistema. Tem por funçao limpar a tela. Deleta todas as menssagens que tnha antes
		
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
			return 0; // Quebra `a função zero. Quebro laço, função e etc e retorna do zero saindo do sistema
			
			default:
			printf("Opcao inválida!\n");
			system("pause");
			break;
		}	
   
   }

}
		
		
		
		
		
		

