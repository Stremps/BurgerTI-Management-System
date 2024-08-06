/***********************************************************************/
typedef struct{
    int posiCabeca; //Posição da cabeça do arquivo
    int posiCauda; //Posição da cauda do arquivo
    int posiTopo; //Primeira posição livre
    // int posLivre; //Tentar fazer se tiver tempo, não compreendi Sou burro >:(

    int quantItens; //Quantidade de produtos registrados em um pedido
    int quantItens_AntCauda; //Quantidade de produtos registrados no último pedido
    int quantItens_AntCabeca; //Quantidade de produtos registrados no primeiro pedido
}Cabecalho_Pedido;

typedef struct produto{
    char tipo[3];
    char nome[51];
    int codigo;
    int quantidade;
    double valorPedido;

}Pedido_No;

// Nó de pedido que permite guardar todas as informações
typedef struct pedidos{
    Pedido_No produto;
    struct pedidos *proximo; //Apesar de não ser inteiro, dentro do Arquivo binário não vai dar problema

}Lista_Pedido;

// Molde que precederá os pedidos dentro do arquivo binário
typedef struct{
    int quantItens;
    int codigo;
    char cpf[12];
    double valorTotal;
    int prox;
    
}Fila_Pedidos;

//Inicializa o arquivo binário para fila pedidos
void criaFila_Pedidos(FILE *fila);

//Função que escreve no arquivo binario o cabeçalho da fila de pedidos
void escreve_CabPedidos(FILE *fila, Cabecalho_Pedido *cabecalho);

//Insere um pedido na fila de pedidos não atendidos
void cadastrar_Pedidos(FILE* fila, FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char OS);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Sanduiche_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lsan, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Bebida_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lbe, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Extra_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lex, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Sobremesa_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lso, double* valorTotal);

//Carrega pedidos em lote de forma mascarada de leitura, a partir de um arquivo de Entrada2.txt
void cadastrar_Pedidos_Lote(FILE* fila, FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char OS, FILE *fi);

Pedido_No insere_Dados_Pedido(Pedido_No novo, char nome[50], char tipo[3], int codigo, int quantidade, double valor);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Sanduiche(Lista_Pedido* pedidos, FILE* lsan, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Bebida(Lista_Pedido* pedidos, FILE* lbe, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Extra(Lista_Pedido* pedidos, FILE* lex, double* valorTotal);

//Função que vai inserir na variável temporária de produtos de um pedido
Lista_Pedido* pedido_Sobremesa(Lista_Pedido* pedidos, FILE* lso, double* valorTotal);

//Atende o pedido para a fila de pedidos não atendidos para fila de pedidos atendidos
void atender_Pedido(FILE* fpe_Atendidos, FILE* fpe);

//Cancela um pedido mediante o código dele
void cancelar_Pedido(FILE* fpe);

//Complemento do cancelar pedidos que remove definitivamente o pedido da fila
void remove_Pedido(FILE* fpe, int numeroPedido, char cpf[12], int *flag);

//Função responsável por imprimir um pedido detalhado
void imprimir_Lista_Pedido(FILE* fila, Fila_Pedidos *lpe);

//Função que mediante fila de pedidos desejada e código desejado imprime o pedido detalhado
void imprimir_Pedido_Desejado(FILE* fpe);

//Função responsável por imprimir um fila de pedidos, seja não atendidos ou atendidos, de forma reduzida
void imprimir_Fila_Pedidos(FILE* arq);

//Função que encaminha para salvar no arquivo binário
void inserir_FilaPedidos(FILE* fila, Fila_Pedidos* novo, Lista_Pedido *lista);

//Função que encaminha para salvar no arquivo binário
void insere_ListaPedidos(FILE *fila, Lista_Pedido *lista, Cabecalho_Pedido *cab);

//Escreve os dois encaminhamentos no arquivo de forma definitiva
void escreve_Filapedidos(FILE *fila, Fila_Pedidos *novo, int posi, int quantItens);

Fila_Pedidos* le_Filapedidos(FILE *fila, int posi, int quantItens);

Cabecalho_Pedido* le_cabecalhoPedidos(FILE *fila);

Lista_Pedido* inserir_FilaPedido(Lista_Pedido* lista, Pedido_No info);

Lista_Pedido* leProdutosCabeca_Ped(Fila_Pedidos *aux, Lista_Pedido* lista, FILE *fila, Cabecalho_Pedido *cab);