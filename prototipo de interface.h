// Função responsável por deixar a página em branco
void quebra_Pagina(char sistemaOperacional);

// Função responsável pela tela inicializadora do sistema
void inicializa_Programa(char* sistemaOperacional, char* ArquivoBinario);

// Função responsável por ler ou criar Arquivo Binários
void inicializa_ArquivoBinario(char ArquivoBinario, FILE** lsan, FILE** lbe, FILE** lso, FILE** lex, FILE** filaPedidos, FILE** filaPedidos_Atendidos);

// Função responsável pelo impressão do menu de opções principais do sistema
void apresenta_Menu();

// Função responsável pela impressão da interface do cadastro
void apresenta_Cadastro();

// Função responsável pela impressão da interface do catálogo
void apresenta_Catalogo();

// Função responsável pela impressão da interface de pedidos
void apresenta_Pedidos();

// Função responsável pelas operações de cadastro
void menu_Cadastro(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char sistemaOperacional);

// Função responsável pelas operações de printar cardápio
void menu_Catalogo(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char sistemaOperacional);

// Função responsável pelas operações de realizar e finalizar pedidos
void menu_Pedidos(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, FILE* fpeAtendidos, FILE* fpe, char sistemaOperacional);

// Função responsável pela leitura de lote geral
void ler_Lote(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, FILE* fpe, char sistemaOperacional);