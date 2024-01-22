#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int registro() // Funçaõ responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/strings
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char arquivo[40]; // Declarei a variável arquivo
    //final da criação de variáveis/strings

    printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuário 
    scanf("%s", cpf);  //%s refere-se a string 

    strcpy(arquivo, cpf);

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    fprintf(file, "%s", cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");  //cadastrar os nomes 
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome); //Corrigi o uso da variável nome
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: "); //cadastrar o sobrenome 
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);  //Corrigi o uso da variavel sobrenome
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");  //cadastrar o cargo
    scanf("%s", cargo);  // Corrigi o uso da variavel cargo

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
    return 0;
}

int consulta()
 {
    setlocale(LC_ALL, "Portuguese"); //localizção  de liguagem acentos etc.. 
 	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: "); //consulta os nomes 
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
        system("pause");
        return 1; // Retorna código de erro
	}
	
	while(fgets(conteudo, sizeof(conteudo), file) !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
    system("pause");
    return 0;
}

void Deletar() {
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    // Verificar se o arquivo existe antes de tentar deletar
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) {
        printf("Usuário não encontrado.\n");
        system("pause");
        return;  // Saímos da função se o usuário não foi encontrado
    }
    
    fclose(file);

    // Tentar remover o arquivo
    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o usuário.\n");
    }

    system("pause");
}




int main() {
    int opcao = 0;
    int laco = 1;

    for (laco = 1; laco == 1;) {
        system("cls");

        setlocale(LC_ALL, "Portuguese");

        printf("##### Cartório da EBAC ### \n\n");
        printf(" Escolha a opção desejada no menu: \n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        system("cls");  // responsável por deletar a tela 

        switch (opcao) {
            case 1:
                registro();  //chamada de funções 
                break;

            case 2:
                consulta();
                break;

            case 3:
                Deletar();
                break;

            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;
            
            
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }      //fim da seleção
    }

    return 0;
}
