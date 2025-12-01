#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_emprestimos 100
#define max_livros 50
#define max_string 100

struct livro {
    char nome [max_string];
    char autor [max_string];
    char editora [max_string];
    int edicao;
    int disponivel;
};

struct emprestimo {
    int id_livro;
    char pessoa[max_string];
};


void limpar_buffer();
void linhas();
void registro_livro(struct livro *biblioteca,int *qtd_livros);
void ver_livros(struct livro *biblioteca, int qtd_livros );
void emprestimo_livro(struct livro *biblioteca, struct emprestimo *emprestimos, int qtd_livros, int *qtd_emprestimos);
void ver_emprestimos(struct livro *biblioteca, struct emprestimo *emprestimos, int qtd_emprestimos);


int main (){
    struct livro *biblioteca = calloc (max_livros, sizeof(struct livro));
    struct emprestimo *emprestimos = malloc (max_emprestimos * sizeof(struct emprestimo));

    if (!biblioteca || !emprestimos){
        printf("Erro ao alocar memória !");
    }else{
        int qtd_livros = 0;
        int qtd_emprestimos = 0;
        int opcao;
        do{
            linhas();
            printf("Menu de opções\n");
            printf("1. Registrar novo livro\n");
            printf("2. Ver livros\n");
            printf("3. Emprestimo de livros\n");
            printf("4. Ver emprestimos\n");
            printf("5. Sair\n");
            scanf("%d", &opcao);
            limpar_buffer();
            linhas();
            switch (opcao){
            case 1: 
                if (qtd_livros <= max_livros){
                    registro_livro(biblioteca, &qtd_livros);
                }else{
                    printf("Quantidade maxima de livros atingida");
                }
                break;
                
            case 2:
                if (qtd_livros == 0){
                    printf("Nenhum livro disponivel para ver aqui");
                }else{
                    ver_livros(biblioteca, qtd_livros);
                }
                    break;
        
            case 3:
                emprestimo_livro(biblioteca, emprestimos, qtd_livros, &qtd_emprestimos);              
                break;

            case 4:
                ver_emprestimos(biblioteca, emprestimos, qtd_emprestimos);
                break;

            }
        }while (opcao != 5);
    }
    free (biblioteca);
    free (emprestimos);
    return 0;
}


void limpar_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void linhas(){
    printf("\n----------------------\n");
}

void registro_livro(struct livro *biblioteca, int *qtd_livros){
    linhas();
    int i = *qtd_livros;
    printf("Nome: ");
    fgets(biblioteca[i].nome, max_string, stdin);
    printf("Autor: ");
    fgets(biblioteca[i].autor, max_string, stdin);
    printf("Editora: ");
    fgets(biblioteca[i].editora, max_string, stdin);

    biblioteca[i].nome[strcspn(biblioteca[i].nome, "\n")] = '\0';
    biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = '\0';
    biblioteca[i].editora[strcspn(biblioteca[i].editora, "\n")] ='\0';
    
    printf("Edição: ");
    scanf("%d", &biblioteca[i].edicao);
    limpar_buffer();
    printf("Aperte Enter para continuar\n");
    getchar();
    biblioteca[i].disponivel = 1;
    (*qtd_livros)++;
}

void ver_livros(struct livro *biblioteca, int qtd_livros){
    for (int i = 0; i < qtd_livros; i++){
        printf("Livro %d\n", i + 1);
        printf("Nome: %s\n", biblioteca[i].nome);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Editora: %s\n", biblioteca[i].editora);
        printf("Edição: %d\n", biblioteca[i].edicao);
        printf("Status: %s\n", biblioteca[i].disponivel ? "Disponivel" : "Indisponivel");
        linhas();
    }
    printf("Pressione Enter para continuar");
    getchar();
}

void emprestimo_livro(struct livro *biblioteca, struct emprestimo *emprestimos, int qtd_livros, int *qtd_emprestimos){
    int indice_livro;
    int checar_livros = 0;

    
    for (int i = 0; i < qtd_livros; i++){
        if (!biblioteca[i].disponivel){
            continue;
        }else{
        printf("%d- %s\n", i + 1, biblioteca[i].nome);
        checar_livros++;
    }
}
    printf("Selecione o livro que você deseja emprestar: ");
    scanf("%d", &indice_livro);
    limpar_buffer();

    indice_livro --; 

    if(indice_livro >= 0 && indice_livro < qtd_livros && biblioteca[indice_livro].disponivel ){
        printf("Coloque algum nome para a retirada do livro: ");
        fgets(emprestimos[indice_livro].pessoa, max_string, stdin);
        emprestimos[indice_livro].id_livro = indice_livro;
        biblioteca[indice_livro].disponivel = 0;
        printf("Empréstimo realizado com sucesso!\n");
        printf("Pressione Enter para continuar");
        getchar();
        (*qtd_emprestimos)++;
    }
}




void ver_emprestimos(struct livro *biblioteca, struct emprestimo *emprestimos, int qtd_emprestimos){
    if (qtd_emprestimos == 0 ){
        printf("Nenhum livro foi emprestado ainda\n");
    }else{
        for (int i = 0; i < qtd_emprestimos; i++){
            printf("%d- %s\n",i + 1,biblioteca[i].nome);
            printf("Nome: %s\n", emprestimos[i].pessoa);
        }
    }
    printf("Pressione Enter para continuar!");
    getchar();
}