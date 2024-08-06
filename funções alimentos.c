#include <stdio.h>
#include <stdlib.h>
#include "prototipo dos alimentos.h"
#include "prototipo de pedidos.h"
#include "prototipo de interface.h"

void cria_lista_vazia(FILE* arq){
    cabecalho_item * cab = (cabecalho_item*) malloc(sizeof(cabecalho_item));
    cab->pos_cabeca = -1;
    cab->pos_cauda = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreve_cabecalho(arq,cab);
    free(cab);
}

cabecalho_item* le_cabecalho(FILE * arq) {
    cabecalho_item * cab = (cabecalho_item*) malloc(sizeof(cabecalho_item));
    fseek(arq,0,SEEK_SET); // posiciona no inicio do arquivo
    fread(cab,sizeof(cabecalho_item),1,arq);
    return cab;
}

void escreve_cabecalho(FILE* arq, cabecalho_item* cab){
    fseek(arq,0,SEEK_SET); //posiciona no inicio do arquivo
    fwrite(cab,sizeof(cabecalho_item),1,arq);
}

Lista_Sanduiche* le_ListaSanduiche(FILE* arq, int pos) {
    Lista_Sanduiche* x = malloc(sizeof(Lista_Sanduiche));
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Sanduiche), SEEK_SET);
    fread(x, sizeof(Lista_Sanduiche), 1, arq);
    return x;
}

void escreve_ListaSanduiche(FILE* arq, Lista_Sanduiche* x, int pos){
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Sanduiche), SEEK_SET);
    fwrite(x, sizeof(Lista_Sanduiche), 1, arq);
}

Lista_Bebidas* le_ListaBebidas(FILE* arq, int pos) {
    Lista_Bebidas* x = malloc(sizeof(Lista_Bebidas));
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Bebidas), SEEK_SET);
    fread(x, sizeof(Lista_Bebidas), 1,arq);
    return x;
}

void escreve_ListaBebidas(FILE* arq, Lista_Bebidas* x, int pos){
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Bebidas), SEEK_SET);
    fwrite(x, sizeof(Lista_Bebidas), 1, arq);
}

Lista_Extra* le_ListaExtra(FILE* arq, int pos){
    Lista_Extra* x = (Lista_Extra*) malloc(sizeof(Lista_Extra));
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Extra), SEEK_SET);
    fread(x, sizeof(Lista_Extra), 1, arq);
    return x;
}

void escreve_ListaExtra(FILE* arq, Lista_Extra* x, int pos){
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Extra), SEEK_SET);
    fwrite(x, sizeof(Lista_Extra), 1, arq);
}

Lista_Sobremesa* le_ListaSobremesas(FILE* arq, int pos) {
    Lista_Sobremesa* x = (Lista_Sobremesa*) malloc(sizeof(Lista_Sobremesa));
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Sobremesa), SEEK_SET);
    fread(x, sizeof(Lista_Sobremesa), 1, arq);
    return x;
}

void escreve_ListaSobremesas(FILE* arq, Lista_Sobremesa* x, int pos){
    fseek(arq, sizeof(cabecalho_item)+ pos*sizeof(Lista_Sobremesa), SEEK_SET);
    fwrite(x, sizeof(Lista_Sobremesa), 1, arq);
}

void Insere_Sanduiche(FILE* arq, Lista_Sanduiche* no){
    cabecalho_item* cab = le_cabecalho(arq);

    no->prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // nao ha nos livres, entao usar o topo
        escreve_ListaSanduiche(arq, no, cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar no da lista de livres
        Lista_Sanduiche* aux = le_ListaSanduiche(arq, cab->pos_livre);
        escreve_ListaSanduiche(arq, no, cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

void Insere_Bebida(FILE* arq, Lista_Bebidas* no){
    cabecalho_item* cab = le_cabecalho(arq); //Salva o cabeçalho em um auxiliar

    no->prox = cab->pos_cabeca; // Encadeia o novo elemento com a lista
    if(cab->pos_livre == -1) { // Caso não haja elementos livres na lista, entra aqui
        escreve_ListaBebidas(arq, no, cab->pos_topo); //Insere no arquivo o nó na determinada posição, no caso o topo
        cab->pos_cabeca = cab->pos_topo; //O topo inserido se torna a nova cabeça
        cab->pos_topo++; //Incremeta o topo
    }
    else { // Caso haja elementos livres, entra aqui
        Lista_Bebidas* aux = le_ListaBebidas(arq, cab->pos_livre); // Cria lista auxíliar só para pegar o prox da cabeça de livres
        escreve_ListaBebidas(arq, no, cab->pos_livre); //Escreve no arquivo o nó na determinada posição, no caso sobreescreve o livre
        cab->pos_cabeca = cab->pos_livre; //Torna a cabeça o elemento novo inserido
        cab->pos_livre = aux->prox; // Muda a cabeça da lista de elementos livres
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

void Insere_Extra(FILE* arq, Lista_Extra* no){
    cabecalho_item* cab = le_cabecalho(arq);

    no->prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // nao ha nos livres, entao usar o topo
        escreve_ListaExtra(arq, no, cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar no da lista de livres
        Lista_Extra* aux = le_ListaExtra(arq, cab->pos_livre);
        escreve_ListaExtra(arq, no, cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); free(cab);
}

void Insere_Sobremesa(FILE* arq, Lista_Sobremesa* no){
    cabecalho_item* cab = le_cabecalho(arq);

    no->prox = cab->pos_cabeca;
    if(cab->pos_livre == -1) { // nao ha nos livres, entao usar o topo
        escreve_ListaSobremesas(arq, no, cab->pos_topo);
        cab->pos_cabeca = cab->pos_topo;
        cab->pos_topo++;
    }
    else { // usar no da lista de livres
        Lista_Sobremesa* aux = le_ListaSobremesas(arq, cab->pos_livre);
        escreve_ListaSobremesas(arq, no, cab->pos_livre);
        cab->pos_cabeca = cab->pos_livre;
        cab->pos_livre = aux->prox;
        free(aux);
    }
    escreve_cabecalho(arq,cab); 
    free(cab);
}

void Retira_Sanduiche(FILE* arq, int codigo){
    cabecalho_item* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    Lista_Sanduiche* aux = NULL;
    while(pos_aux != -1 && ((aux = le_ListaSanduiche(arq,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remocao na cabeca
            cab->pos_cabeca = aux->prox;
        }
        else { // remocaoo no meio
            Lista_Sanduiche * ant = le_ListaSanduiche(arq,pos_ant);
            ant->prox = aux->prox;
            escreve_ListaSanduiche(arq, ant, pos_ant);
            free(ant);
        }
    aux->prox = cab->pos_livre; // torna o no removido um no livre
    cab->pos_livre = pos_aux;
    escreve_ListaSanduiche(arq,aux,pos_aux);
    escreve_cabecalho(arq,cab);
    free(aux);
    }
    free(cab);
}

void Retira_Bebidas(FILE* arq, int codigo){
    cabecalho_item* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    Lista_Bebidas* aux = NULL;
    while(pos_aux != -1 && ((aux = le_ListaBebidas(arq, pos_aux))!= NULL) && aux->produto.codigo != codigo){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remocao na cabeca
            cab->pos_cabeca = aux->prox;
        }
        else { // remocaoo no meio
            Lista_Bebidas * ant = le_ListaBebidas(arq, pos_ant);
            ant->prox = aux->prox;
            escreve_ListaBebidas(arq, ant, pos_ant);
            free(ant);
        }
    aux->prox = cab->pos_livre; // torna o no removido um no livre
    cab->pos_livre = pos_aux;
    escreve_ListaBebidas(arq, aux, pos_aux);
    escreve_cabecalho(arq, cab);
    free(aux);
    }
    free(cab);
}

void Retira_Extra(FILE* arq, int codigo){
    cabecalho_item* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    Lista_Extra* aux = NULL;
    while(pos_aux != -1 && ((aux = le_ListaExtra(arq, pos_aux))!= NULL) && aux->produto.codigo != codigo){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remocao na cabeca
            cab->pos_cabeca = aux->prox;
        }
        else { // remocaoo no meio
            Lista_Extra * ant = le_ListaExtra(arq, pos_ant);
            ant->prox = aux->prox;
            escreve_ListaExtra(arq, ant, pos_ant);
            free(ant);
        }
    aux->prox = cab->pos_livre; // torna o no removido um no livre
    cab->pos_livre = pos_aux;
    escreve_ListaExtra(arq, aux, pos_aux);
    escreve_cabecalho(arq, cab);
    free(aux);
    }
    free(cab);
}

void Retira_Sobremesa(FILE* arq, int codigo){
    cabecalho_item* cab = le_cabecalho(arq);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    Lista_Sobremesa* aux = NULL;
    while(pos_aux != -1 && ((aux = le_ListaSobremesas(arq, pos_aux))!= NULL) && aux->produto.codigo != codigo){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    if(pos_aux != -1) { //encontrou o elemento
        if(pos_ant == pos_aux){ // remocao na cabeca
            cab->pos_cabeca = aux->prox;
        }
        else { // remocaoo no meio
            Lista_Sobremesa * ant = le_ListaSobremesas(arq, pos_ant);
            ant->prox = aux->prox;
            escreve_ListaSobremesas(arq, ant, pos_ant);
            free(ant);
        }
    aux->prox = cab->pos_livre; // torna o no removido um no livre
    cab->pos_livre = pos_aux;
    escreve_ListaSobremesas(arq, aux, pos_aux);
    escreve_cabecalho(arq, cab);
    free(aux);
    }
    free(cab);
}

double ler_Precos(){
    int pre, pos;
    float numeroDecimal;
    scanf("%d,%d%*c", &pre, &pos);//Entrada do teclado mascarado

    numeroDecimal = pre;
    numeroDecimal += pos/100.0;

    return numeroDecimal;
}

double ler_Precos_Lote_PontoVirgula(FILE *fi){
    int pre, pos;
    float numeroDecimal;
    fscanf(fi, "%d,%d;", &pre, &pos);//Entrada do teclado mascarado

    numeroDecimal = pre;
    numeroDecimal += pos/100.0;

    return numeroDecimal;
}

double ler_Precos_Lote_ContraBarraN(FILE *fi){
    int pre, pos;
    float numeroDecimal;
    fscanf(fi, "%d,%d\n", &pre, &pos);//Entrada do teclado mascarado

    numeroDecimal = pre;
    numeroDecimal += pos/100.0;

    return numeroDecimal;
}

Lista_Sanduiche* cadastra_Sanduiche(Lista_Sanduiche* lista){
    printf("Código do produto: ");
    scanf("%d%*c", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente
    
    printf("Nome do produto: ");
    scanf("%[^\n]%*c", lista->produto.nome);

    printf("Descrição: ");
    scanf("%[^\n]%*c", lista->produto.descricao);

    printf("Disponibilidade(D/I): ");
    scanf("%c%*c", &lista->produto.diponibilidade);

    printf("Preço do pequeno: ");
    lista->produto.precos.pequeno = ler_Precos();

    printf("Preço do médio: ");
    lista->produto.precos.medio = ler_Precos();

    printf("Preço do grande: ");
    lista->produto.precos.grande = ler_Precos();

    return lista;
}

Lista_Bebidas* cadastra_Bebidas(Lista_Bebidas* lista){
    printf("Código do produto: ");
    scanf("%d%*c", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    printf("Nome do produto: ");
    scanf("%[^\n]%*c", lista->produto.nome);

    printf("Disponibilidade(D/I): ");
    scanf("%c%*c", &lista->produto.diponibilidade);

    printf("Preço do pequeno: ");
    lista->produto.precos.pequeno = ler_Precos();

    printf("Preço do médio: ");
    lista->produto.precos.medio = ler_Precos();

    printf("Preço do grande: ");
    lista->produto.precos.grande = ler_Precos();

    return lista;
}

Lista_Extra* cadastra_Extra(Lista_Extra* lista){

    printf("Código do produto: ");
    scanf("%d%*c", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    printf("Nome do produto: ");
    scanf("%[^\n]%*c", lista->produto.nome);

    printf("Disponibilidade(D/I): ");
    scanf("%c%*c", &lista->produto.diponibilidade);
    
    printf("Preço: ");
    lista->produto.preco = ler_Precos();

    return lista;
}

Lista_Sobremesa* cadastra_Sobremesas(Lista_Sobremesa* lista){
    printf("Código do produto: ");
    scanf("%d%*c", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    printf("Nome do produto: ");
    scanf("%[^\n]%*c", lista->produto.nome);

    printf("Disponibilidade(D/I): ");
    scanf("%c%*c", &lista->produto.diponibilidade);

    printf("Preço: ");
    lista->produto.preco = ler_Precos();
    
    return lista;
}

void imprimir_Sanduiche(FILE* arq){
    cabecalho_item * cab = le_cabecalho(arq);

    if(!(cab->pos_cabeca!=-1)) printf("Não há sanduiche cadastrado\n");
    else{
        Lista_Sanduiche* lista;
        int ant; //Para permitir que eu printe todos os pedidos, sem pular o último da lista
        
        for(lista = le_ListaSanduiche(arq, cab->pos_cabeca); ant != -1; lista = le_ListaSanduiche(arq, lista->prox)){
            ant = lista->prox;
            printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
            printf("║Código do produto: %03d\n", lista->codigo);
            printf("║Nome do sanduiche: %s\n", lista->produto.nome);
            printf("║Descrição: %s\n", lista->produto.descricao);
            (lista->produto.diponibilidade == 'D') ? printf("║Produto disponível\n") : printf("║Produto indisponível\n"); //Ternário para diponibilidade
            printf("║Tabela de Preços:\n");
            printf("║P = R$%4.02lf\n", lista->produto.precos.pequeno);
            printf("║M = R$%4.02lf\n", lista->produto.precos.medio);
            printf("║G = R$%4.02lf\n", lista->produto.precos.grande);
            printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
        }
           
    }
}

void imprimir_Bebida(FILE* arq){
    cabecalho_item * cab = le_cabecalho(arq);

    if(!(cab->pos_cabeca!=-1)) printf("Não há bebidas cadastrado\n");
    else{
        Lista_Bebidas* lista;
        int ant; //Para permitir que eu printe todos os pedidos, sem pular o último da lista
        
        for(lista = le_ListaBebidas(arq, cab->pos_cabeca); ant != -1; lista = le_ListaBebidas(arq, lista->prox)){
            ant = lista->prox;
            printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
            printf("║Código do produto: %03d\n", lista->codigo);
            printf("║Nome da bebida: %s\n", lista->produto.nome);
            (lista->produto.diponibilidade == 'D') ? printf("║Produto disponível\n") : printf("║Produto indisponível\n"); //Ternário para diponibilidade
            printf("║Tabela de Preços:\n");
            printf("║P = R$%4.02lf\n", lista->produto.precos.pequeno);
            printf("║M = R$%4.02lf\n", lista->produto.precos.medio);
            printf("║G = R$%4.02lf\n", lista->produto.precos.grande);
            printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
        }
    }
}

void imprimir_Extra(FILE* arq){
    cabecalho_item * cab = le_cabecalho(arq);

    if(!(cab->pos_cabeca!=-1)) printf("Não há bebidas cadastrado\n");
    else{
        Lista_Extra* lista;
        int ant; //Para permitir que eu printe todos os pedidos, sem pular o último da lista
        
        for(lista = le_ListaExtra(arq, cab->pos_cabeca); ant != -1; lista = le_ListaExtra(arq, lista->prox)){
            ant = lista->prox;
            printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
            printf("║Código do produto: %03d\n", lista->codigo);
            printf("║Nome do Extra: %s\n", lista->produto.nome);
            (lista->produto.diponibilidade == 'D') ? printf("║Produto disponível\n") : printf("║Produto indisponível\n"); //Ternário para diponibilidade
            printf("║Preço = R$%4.02lf\n", lista->produto.preco);
            printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
        }
    }
}

void imprimir_Sobremesa(FILE* arq){
    cabecalho_item * cab = le_cabecalho(arq);

    if(!(cab->pos_cabeca!=-1)) printf("Não há bebidas cadastrado\n");
    else{
        Lista_Sobremesa* lista;
        int ant; //Para permitir que eu printe todos os pedidos, sem pular o último da lista
        
        for(lista = le_ListaSobremesas(arq, cab->pos_cabeca); ant != -1; lista = le_ListaSobremesas(arq, lista->prox)){
            ant = lista->prox;
            printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
            printf("║Código do produto: %03d\n", lista->codigo);
            printf("║Nome do Sobremesa: %s\n", lista->produto.nome);
            (lista->produto.diponibilidade == 'D') ? printf("║Produto disponível\n") : printf("║Produto indisponível\n"); //Ternário para diponibilidade
            printf("║Preço = R$%4.02lf\n", lista->produto.preco);
            printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
        }
    }
}

void apresenta_Precos(Valores precos){
    printf("P: %.2lf\n", precos.pequeno);
    printf("M: %.2lf\n", precos.medio);
    printf("G: %.2lf\n", precos.grande);
}

Lista_Sanduiche* cadastra_Sanduiche_Lote(Lista_Sanduiche* lista, FILE *fi){
    fscanf(fi ,"%d;", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo;

    fscanf(fi ,"%[^;]%*c", lista->produto.nome);

    fscanf(fi ,"%[^;]%*c", lista->produto.descricao);

    fscanf(fi ,"%c;", &lista->produto.diponibilidade);

    lista->produto.precos.pequeno = ler_Precos_Lote_PontoVirgula(fi);
    lista->produto.precos.medio = ler_Precos_Lote_PontoVirgula(fi);
    lista->produto.precos.grande = ler_Precos_Lote_ContraBarraN(fi);

    return lista;
}

Lista_Bebidas* cadastra_Bebidas_Lote(Lista_Bebidas* lista, FILE *fi){
    fscanf(fi ,"%d;", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    fscanf(fi ,"%[^;]%*c", lista->produto.nome);

    fscanf(fi ,"%c;", &lista->produto.diponibilidade);

    lista->produto.precos.pequeno = ler_Precos_Lote_PontoVirgula(fi);
    lista->produto.precos.medio = ler_Precos_Lote_PontoVirgula(fi);
    lista->produto.precos.grande = ler_Precos_Lote_ContraBarraN(fi);

    return lista;
}

Lista_Extra* cadastra_Extra_Lote(Lista_Extra* lista, FILE *fi){    
    fscanf(fi ,"%d;", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    fscanf(fi ,"%[^;]%*c", lista->produto.nome);

    fscanf(fi ,"%c;", &lista->produto.diponibilidade);

    lista->produto.preco = ler_Precos_Lote_ContraBarraN(fi);
    
    return lista;
}

Lista_Sobremesa* cadastra_Sobremesas_Lote(Lista_Sobremesa* lista, FILE *fi){
    fscanf(fi ,"%d;", &lista->produto.codigo);
    lista->codigo = lista->produto.codigo; //Para facilitar a procura do código durante a passagem mais a frente

    fscanf(fi ,"%[^;]%*c", lista->produto.nome);

    fscanf(fi ,"%c;", &lista->produto.diponibilidade);

    lista->produto.preco = ler_Precos_Lote_ContraBarraN(fi);
    
    return lista;
}