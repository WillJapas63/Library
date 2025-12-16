# Library
Isso é basicamente uma livaria, aonde você pode registrar e emprestar livros.

Explicação do código:
1. Inclui todas as bibliotecas necessárias
2. Defini um tamanho máximo de emprestimos, livros e letras
3. Defini uma estrutura de livros e de emprestimos
4. Declarei todas as funções que eu iria usar
5. Entrei no programa principal
6. Declarei que a estrutura livros aponta para a biblioteca, com a função calloc (arruma o espaço na memória e esvazia ela)

7. Declarei que a estrutura emprestimos aponta para emprestimos, chamando a função malloc
8. Conferi se deu tudo certo com a alocação de memória fazendo uma validação
9. Com tudo isso certo, iniciei um menu de opções com o switch
10. Fiz uma validação inicial se era possivel alocar livros ainda, e depois chamei a função de registrar.
11. Fiz uma validação se existia livros alocados, e depois chamei a função de ver os livros
12. chamei as funções de emprestimos e ver emprestimos e finalizei o programa liberando a memória.
13. Explicação das funções{

    1. Limpar buffer:{ <br>
    Inicia uma variavel C; <br>
    C é ligado a getchar(); <br>
    Getchar consome tudo no caminho da entrada de dados e envia para C; <br>
    C fica com varios caracteres aleatórios C(abriu,a ja...); <br>
    Quando getchar consumir '\n', o looping acaba; <br>
    Consumir é basicamente não deixar o caracter ir para a proxima sentença; <br>
    C != EOF(end of file), como o próprio nome ja diz, <br>
    Se não houver uma parada no arquivo abrupta, o looping continua normalmente; <br>
    Isso é mais uma verificação de segurança para não entrar em looping infinito, pois <br>
    se não existir c != EOF, ele nunca vai achar '\n' em caso de parada abrupta; <br>
    }
    <br>

    2. Linhas:{<br> Basicamente printa na tela linhas, afim de estilização <br>
    }<br>
    3. Registro livro: { <br>
        Primeiramente repare na declaração da função aonde dentro dos () temos ponteiros, isso é necessario para alterar alguma informação deles. <br>
        Para registrar livros, eu inicio uma variavel I que aponta para qtd_livros, isso porque eu não consigo iniciar uma variavel qtd_livros, porque ja existe. <br>
        em fgets eu trago o ponteiro (biblioteca), o indice, e a variavel dentro da estrutura que apontou (livros), ai eu determino o tamanho maximo e chamo a função stdin (que simboliza que a entrada padrão é o teclado, ISSO É SÓ CURIOSIDADE, não precisa decorar) <br>
        Ai entra a função strcspn que atua como um detetive procurando "\n"<br>
        Quando ela acha "\n", eu declaro novamente biblioteca[i].alguma_coisa (lembre-se que agora isso contém o "\n" que estavamos procurando) <br>
        e faço biblioteca[i].alguma_coisa => biblioteca[i].alguma_coisa = '\0' <br>
        


    }



}


