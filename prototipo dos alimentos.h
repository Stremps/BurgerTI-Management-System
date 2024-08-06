//Struct para facilitar valor dos produtos com mais de 1 tamanho
typedef struct valor{
    double pequeno;
    double medio;
    double grande;
}Valores;

//Struct do sanduíche que segue o padrão proposto
typedef struct sanduiche{
    int codigo;
    char nome[50];
    char descricao[200];
    char diponibilidade;
    Valores precos;
}Sanduiche;

//Struct da bebida que segue o padrão proposto
typedef struct bebidas{
    int codigo;
    char nome[50];
    char diponibilidade;
    Valores precos;
}Bebidas;

//Struct do extra que segue o padrão proposto
typedef struct extra{
    int codigo;
    char nome[50];
    char diponibilidade;
    double preco;
}Extra;

//Struct do sobremesa que segue o padrão proposto
typedef struct sobremesa{
    int codigo;
    char nome[50];
    char diponibilidade;
    double preco;
}Sobremesa;

//Lista encadeada exclusiva para os sanduíches
typedef struct{
    int codigo; //Facilitador na hora que for procurar um produto
    Sanduiche produto;
    int prox;
}Lista_Sanduiche;

//Lista encadeada exclusiva para as bebidas
typedef struct{
    int codigo; //Facilitador na hora que for procurar um produto
    Bebidas produto;
    int prox;
}Lista_Bebidas;

//Lista encadeada exclusiva para os extras
typedef struct{
    int codigo; //Facilitador na hora que for procurar um produto
    Extra produto;
    int prox;
}Lista_Extra;

//Lista encadeada exclusiva para as sobremesas
typedef struct{
    int codigo; //Facilitador na hora que for procurar um produto
    Sobremesa produto;
    int prox;
}Lista_Sobremesa;

typedef struct {
    int pos_cabeca; //posicao do inıcio da lista
    int pos_topo; // 1a posicao nao usada no fim do arquivo
    int pos_cauda; // posicao do inıcio da lista de nos livres
    int pos_livre; // posicao do ultimo elemento no arquivo
} cabecalho_item;

//Cria uma lista nova em arquivo
//Pré-condicao: arquivo aberto para leitura/escrita
//Pós-condição: arquivo é inicializado com uma lista vazia
void cria_lista_vazia(FILE* arq);

//Lê o cabeçalho do arquivo contendo as informações da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: retorna o ponteiro para o cabeçalho_item lido

cabecalho_item* le_cabecalho(FILE * arq);

//Escreve no arquivo o cabeçalho contendo as informações da lista
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: cabeçalho_item escrito no arquivo

void escreve_cabecalho(FILE* arq, cabecalho_item* cab);


//Lê um nó do tipo Lista_Sanduiche
Lista_Sanduiche* le_ListaSanduiche(FILE* arq, int pos);


//Escreve um nó do tipo Lista_Sanduiche
void escreve_ListaSanduiche(FILE* arq, Lista_Sanduiche* x, int pos);

//Lê um nó do tipo Lista_Bebidas
Lista_Bebidas* le_ListaBebidas(FILE* arq, int pos);

//Escreve um nó do tipo Lista_Bebidas
void escreve_ListaBebidas(FILE* arq, Lista_Bebidas* x, int pos);

//Lê um nó do tipo Lista_Extra
Lista_Extra* le_ListaExtra(FILE* arq, int pos);

//Escreve um nó do tipo Lista_Extra
void escreve_ListaExtra(FILE* arq, Lista_Extra* x, int pos);

//Lê um nó do tipo Lista_Sobremesa
Lista_Sobremesa* le_ListaSobremesas(FILE* arq, int pos);

//Escreve um nó do tipo Lista_Sobremesa
void escreve_ListaSobremesas(FILE* arq, Lista_Sobremesa* x, int pos);

//Insere uma Lista_Sanduiche na cabeça da lista do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: Lista_Sanduiche inserida no arquivo
void Insere_Sanduiche(FILE* arq, Lista_Sanduiche* no);


//Insere uma Lista_Bebidas na cabeça da lista do arquivo
//Pré-condicao: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: Lista_Bebidas inserida no arquivo
void Insere_Bebida(FILE* arq, Lista_Bebidas* no);

//Insere uma Lista_Extra na cabeça da lista do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: Lista_Extra inserida no arquivo
void Insere_Extra(FILE* arq, Lista_Extra* no);

//Insere um Lista_Sobremesa na cabeça da lista do arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: Lista_Sobremesa inserida no arquivo
void Insere_Sobremesa(FILE* arq, Lista_Sobremesa* no);

//Remove um elemento Lista_Sanduiche da lista no arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: elemento do tipo Lista_Sanduiche removido do arquivo
void Retira_Sanduiche(FILE* arq, int codigo);

//Remove um elemento Lista_Bebidas da lista no arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: elemento do tipo Lista_Bebidas removido do arquivo
void Retira_Bebidas(FILE* arq, int codigo);

//Remove um elemento Lista_Extra da lista no arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: elemento do tipo Lista_Extra removido do arquivo
void Retira_Extra(FILE* arq, int codigo);

//Remove um elemento Lista_Sobremesa da lista no arquivo
//Pré-condição: arquivo deve estar aberto e ser um arquivo de lista
//Pós-condição: elemento do tipo Lista_Sobremesa removido do arquivo
void Retira_Sobremesa(FILE* arq, int codigo);

// Insere um produto na cauda da lista de sanduíches
// Entrada: Lista de sanduíches
// Retorno: cabeça da lista
// Pré-condição: nenhuma
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Sanduiche* cadastra_Sanduiche(Lista_Sanduiche* lista);

// Insere um produto na cauda da lista de bebidas
// Entrada: Lista de bebidas
// Retorno: cabeça da lista
// Pré-condição: nenhuma
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Bebidas* cadastra_Bebidas(Lista_Bebidas* lista);

// Insere um produto na cauda da lista de extras
// Entrada: Lista de extras
// Retorno: cabeça da lista
// Pré-condição: nenhuma
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Extra* cadastra_Extra(Lista_Extra* lista);

// Insere um produto na cauda da lista de sobremesas
// Entrada: Lista de sobremesas
// Retorno: cabeça da lista
// Pré-condição: nenhuma
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Sobremesa* cadastra_Sobremesas(Lista_Sobremesa* lista);

// Remove um produto da lista de sanduiche por meio do código
// Entrada: lista de sanduiches e codigo do sanduiche
// Retorno: lista modificada
// Pré-condição: produto tem que estar na lista
// Pós-condição: produto é removido e lista adaptada
Lista_Sanduiche* remove_Sanduiche(Lista_Sanduiche* lista, int codigo);

// Remove um produto da lista de bebidas por meio do código
// Entrada: lista de bebidas e codigo da bebida
// Retorno: lista modificada
// Pré-condição: produto tem que estar na lista
// Pós-condição: produto é removido e lista adaptada
Lista_Bebidas* remove_Bebidas(Lista_Bebidas* lista, int codigo);

// Remove um produto da lista de extra por meio do código
// Entrada: lista de extra e codigo do extra
// Retorno: lista modificada
// Pré-condição: produto tem que estar na lista
// Pós-condição: produto é removido e lista adaptada
Lista_Extra* remove_Extra(Lista_Extra* lista, int codigo);

// Remove um produto da lista de sobremesa por meio do código
// Entrada: lista de sobremesa e codigo da sobremesa
// Retorno: lista modificada
// Pré-condição: produto tem que estar na lista
// Pós-condição: produto é removido e lista adaptada
Lista_Sobremesa* remove_Sobremesa(Lista_Sobremesa* lista, int codigo);

// Imprime os elementos da lista de Sanduíches
// Entrada: lista de Sanduíches
// Retorno: nenhuma
// Pré-condição: nenhuma
// Pós-condição: os produtos são impressos no console
void imprimir_Sanduiche(FILE* arq);

// Imprime os elementos da lista de Bebidas
// Entrada: lista de Bebidas
// Retorno: nenhuma
// Pré-condição: nenhuma
// Pós-condição: os produtos são impressos no console
void imprimir_Bebida(FILE* arq);

// Imprime os elementos da lista de Extras
// Entrada: lista de Extras
// Retorno: nenhuma
// Pré-condição: nenhuma
// Pós-condição: os produtos são impressos no console
void imprimir_Extra(FILE* arq);

// Imprime os elementos da lista de Sobremesas
// Entrada: lista de Sobremesas
// Retorno: nenhuma
// Pré-condição: nenhuma
// Pós-condição: os produtos são impressos no console
void imprimir_Sobremesa(FILE* arq);

// Imprime os elementos da lista de preços de sanduiches e sucos
// Entrada: lista de preços
// Retorno: nenhuma
// Pré-condição: nenhuma
// Pós-condição: os preços são impressos no console
void apresenta_Precos(Valores precos);

// Permite a mascaração da leitura de um número decimal com ',' 
// Entrada: número com casa decimal no formato brasileiro
// Retorno: variável de dupla precisão traduzida
// Pré-condição: nenhuma
// Pós-condição: nenhuma
double ler_Precos();

//Realiza o mesmo que o ler preço, mas mascara para leiutra de arquivo
double ler_Precos_Lote_PontoVirgula(FILE *fi);

//Realiza o mesmo que o ler preço, mas mascara para leiutra de arquivo
double ler_Precos_Lote_ContraBarraN(FILE *fi);

// Insere um produto na cauda da lista de sanduíches
// Entrada: Lista de sanduíches
// Retorno: cabeça da lista
// Pré-condição: leitura de um arquivo
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Sanduiche* cadastra_Sanduiche_Lote(Lista_Sanduiche* lista, FILE *fi);

// Insere um produto na cauda da lista de bebidas
// Entrada: Lista de bebidas
// Retorno: cabeça da lista
// Pré-condição: leitura de um arquivo
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Bebidas* cadastra_Bebidas_Lote(Lista_Bebidas* lista, FILE *fi);

// Insere um produto na cauda da lista de extras
// Entrada: Lista de extras
// Retorno: cabeça da lista
// Pré-condição: leitura de um arquivo
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Extra* cadastra_Extra_Lote(Lista_Extra* lista, FILE *fi);

// Insere um produto na cauda da lista de sobremesas
// Entrada: Lista de sobremesas
// Retorno: cabeça da lista
// Pré-condição: leitura de um arquivo
// Pós-condição:  código é salvo e produto inserido na cauda da lista
Lista_Sobremesa* cadastra_Sobremesas_Lote(Lista_Sobremesa* lista, FILE *fi);

