#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipo dos alimentos.h"
#include "prototipo de pedidos.h"
#include "prototipo de interface.h"

void criaFila_Pedidos(FILE *fila){
    Cabecalho_Pedido *cabecalho=(Cabecalho_Pedido*)malloc(sizeof(Cabecalho_Pedido));

    cabecalho->posiCabeca=-1;
    cabecalho->posiCauda=-1;
    cabecalho->posiTopo=0;

    cabecalho->quantItens=0;
    cabecalho->quantItens_AntCauda=0;
    cabecalho->quantItens_AntCabeca=0;

    escreve_CabPedidos(fila, cabecalho);
    free(cabecalho);
}

void escreve_CabPedidos(FILE *fila, Cabecalho_Pedido *cabecalho){
    fseek(fila,0,SEEK_SET);
    fwrite(cabecalho,sizeof(Cabecalho_Pedido),1,fila);
}

Pedido_No insere_Dados_Pedido(Pedido_No novo, char nome[50], char tipo[3], int codigo, int quantidade, double valor){
    strcpy(novo.tipo, tipo); //Fala que esse produto é um sanduiche
    strcpy(novo.nome, nome);
    novo.codigo = codigo;
    novo.quantidade = quantidade;
    novo.valorPedido = valor*quantidade;

    return novo;
}

Lista_Pedido* pedido_Sanduiche(Lista_Pedido* pedidos, FILE* lsan, double* valorTotal){
    int codigo, quantidade;
    double valor;
    char preco;
    Lista_Sanduiche* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lsan);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    imprimir_Sanduiche(lsan);
    while(1){ //Faz leitura do código do produto desejado
        printf("Insira o código: ");
        scanf("%d%*c", &codigo);

        while(pos_aux != -1 && ((aux = le_ListaSanduiche(lsan,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
            pos_ant = pos_aux;
            pos_aux = aux->prox;
            free(aux);
            aux = NULL;
        }

        if(pos_aux != -1){
            if(aux->produto.diponibilidade != 'I') break;
            else printf("Produto não disponível!");
        }
        else
            printf("Produto não existente!\n");
    }
    
    printf("Quantidade: ");
    scanf("%d%*c", &quantidade);
    
    while(1){ //Faz leitura do preço desejado
        apresenta_Precos(aux->produto.precos);
        printf("Insira o tamanho desejado (P/M/G): ");
        scanf("%c%*c", &preco);

        if(preco != 'G' && preco != 'g' && preco != 'M' && preco != 'm' && preco != 'P' && preco != 'p')
            printf("tamanho invalido, insira o tamanho correto!\n");
        else{
            if(preco == 'g' || preco == 'G')
                valor = aux->produto.precos.grande;
            else if(preco == 'M' || preco == 'm')
                valor = aux->produto.precos.medio;
            else //Se não for grande nem médio é pequeno
                valor = aux->produto.precos.pequeno;
            break; //Sempre vai dar o break depois de fazer alguma condição
        }
    }

   Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "SD", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Bebida(Lista_Pedido* pedidos, FILE* lbe, double* valorTotal){
    int codigo, quantidade;
    double valor;
    char preco;
    Lista_Bebidas* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lbe);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;
    imprimir_Bebida(lbe);

    while(1){ //Faz leitura do código do produto desejado
        printf("Insira o código: ");
        scanf("%d%*c", &codigo);

        while(pos_aux != -1 && ((aux = le_ListaBebidas(lbe,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
            pos_ant = pos_aux;
            pos_aux = aux->prox;
            free(aux);
            aux = NULL;
        }

        if(pos_aux != -1){
            if(aux->produto.diponibilidade != 'I') break;
            else printf("Produto não disponível!");
        }
        else
            printf("Produto não existente!\n");
    }
    
    printf("Quantidade: ");
    scanf("%d%*c", &quantidade);
    
    while(1){ //Faz leitura do preço desejado
        apresenta_Precos(aux->produto.precos);
        printf("Insira o tamanho desejado (P/M/G): ");
        scanf("%c%*c", &preco);

        if(preco != 'G' && preco != 'g' && preco != 'M' && preco != 'm' && preco != 'P' && preco != 'p')
            printf("tamanho invalido, insira o tamanho correto!\n");
        else{
            if(preco == 'g' || preco == 'G')
                valor = aux->produto.precos.grande;
            else if(preco == 'M' || preco == 'm')
                valor = aux->produto.precos.medio;
            else //Se não for grande nem médio é pequeno
                valor = aux->produto.precos.pequeno;
            break; //Sempre vai dar o break depois de fazer alguma condição
        }
    }

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "BB", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Extra(Lista_Pedido* pedidos, FILE* lex, double* valorTotal){
    int codigo, quantidade;
    double valor;
    Lista_Extra* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lex);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    imprimir_Extra(lex);
    while(1){ //Faz leitura do código do produto desejado
        printf("Insira o código: ");
        scanf("%d%*c", &codigo);

        while(pos_aux != -1 && ((aux = le_ListaExtra(lex,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
            pos_ant = pos_aux;
            pos_aux = aux->prox;
            free(aux);
            aux = NULL;
        }

        if(pos_aux != -1){
            if(aux->produto.diponibilidade != 'I') break;
            else printf("Produto não disponível!");
        }
        else
            printf("Produto não existente!\n");
    }
    
    printf("Quantidade: ");
    scanf("%d%*c", &quantidade);

    valor =  aux->produto.preco;

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome,"EX", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Sobremesa(Lista_Pedido* pedidos, FILE* lso, double* valorTotal){
    int codigo, quantidade;
    double valor;
    Lista_Sobremesa* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lso);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    imprimir_Sobremesa(lso);
    while(1){ //Faz leitura do código do produto desejado
        printf("Insira o código: ");
        scanf("%d%*c", &codigo);

        while(pos_aux != -1 && ((aux = le_ListaSobremesas(lso,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
            pos_ant = pos_aux;
            pos_aux = aux->prox;
            free(aux);
            aux = NULL;
        }

        if(pos_aux != -1){
            if(aux->produto.diponibilidade != 'I') break;
            else printf("Produto não disponível!");
        }
        else
            printf("Produto não existente!\n");
    }
    
    printf("Quantidade: ");
    scanf("%d%*c", &quantidade);

    valor =  aux->produto.preco;

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "SM", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

void inserir_FilaPedidos(FILE* fila, Fila_Pedidos* novo, Lista_Pedido *lista){
    Cabecalho_Pedido *cabecalho = le_cabecalhoPedidos(fila);

    novo->prox=-1;

    if(cabecalho->posiCabeca == -1) cabecalho->posiCabeca=cabecalho->posiTopo;
    else{
        Fila_Pedidos *aux = (Fila_Pedidos*)malloc(sizeof(Fila_Pedidos));
        aux = le_Filapedidos(fila, cabecalho->posiCauda, cabecalho->quantItens_AntCauda);
        aux->prox = cabecalho->posiTopo;
        escreve_Filapedidos(fila, aux, cabecalho->posiCauda, cabecalho->quantItens_AntCauda);
    }
    cabecalho->posiCauda=cabecalho->posiTopo;
    escreve_Filapedidos(fila, novo, cabecalho->posiTopo, cabecalho->quantItens);
    cabecalho->posiTopo++;

    insere_ListaPedidos(fila, lista, cabecalho);
    cabecalho->quantItens_AntCauda = cabecalho->quantItens-novo->quantItens;
    escreve_CabPedidos(fila, cabecalho);
    free(cabecalho);
}

Cabecalho_Pedido* le_cabecalhoPedidos(FILE *fila){
        Cabecalho_Pedido *cab=(Cabecalho_Pedido*)malloc(sizeof(Cabecalho_Pedido));

        fseek(fila,0,SEEK_SET);
        fread(cab,sizeof(Cabecalho_Pedido),1,fila);

    return cab;
}

void insere_ListaPedidos(FILE *fila, Lista_Pedido *lista, Cabecalho_Pedido *cab){
    Lista_Pedido *aux = lista;

    while(aux!=NULL){
        fseek(fila, sizeof(Cabecalho_Pedido)+sizeof(Fila_Pedidos)*(cab->posiTopo) + sizeof(Lista_Pedido)*cab->quantItens, SEEK_SET);
        fwrite(aux, sizeof(Lista_Pedido), 1, fila);

        cab->quantItens++;
        aux=aux->proximo;
    }
}

Fila_Pedidos* le_Filapedidos(FILE *fila, int posi, int quantItens){
        Fila_Pedidos *aux = (Fila_Pedidos*)malloc(sizeof(Fila_Pedidos));
        fseek(fila,sizeof(Cabecalho_Pedido)+sizeof(Fila_Pedidos)*posi+ sizeof(Lista_Pedido)*quantItens, SEEK_SET); //Passa o espaço de quantidade de produtos pedidos, que serão colocados a frente
        fread(aux, sizeof(Fila_Pedidos), 1, fila);
    return aux;
}

void escreve_Filapedidos(FILE *fila, Fila_Pedidos *novo, int posi,int quantItens){
    fseek(fila, sizeof(Cabecalho_Pedido)+sizeof(Fila_Pedidos)*posi + sizeof(Lista_Pedido)*quantItens, SEEK_SET); //Passa o espaço de quantidade de produtos pedidos, que serão colocados a frente
    fwrite(novo, sizeof(Fila_Pedidos), 1, fila); 
}

void cadastrar_Pedidos(FILE* fila, FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char OS){
    Fila_Pedidos* novo = (Fila_Pedidos*) malloc(sizeof(Fila_Pedidos));
    novo->valorTotal = 0;
    novo->quantItens = 0;

    Lista_Pedido* lista = NULL; //Inicializa a lista de produtos pedido

    char repetir = 'n';
    char continuarPedidos = 's'; //Para na primeira repetição já ser possível de realizar um pedido
    int tipoPedido;
    
    printf("Código do pedido: ");
    scanf("%d%*c", &novo->codigo);

    printf("Insira o cpf do cliente: ");
    scanf("%[^\n]%*c", novo->cpf);

    if(repetir == 'n' || repetir == 'N'){
        while(continuarPedidos == 's' || continuarPedidos == 'S'){
            printf("O que você deseja pedir?\n1)Sanduíche   2)Bebida  3)Extra  4)Sobremesa\n");
            scanf("%d%*c", &tipoPedido);

            if(tipoPedido == 1){
                lista = pedido_Sanduiche(lista, lsan, &novo->valorTotal);
                quebra_Pagina(OS);
            }
            if(tipoPedido == 2){
                lista = pedido_Bebida(lista, lbe, &novo->valorTotal);
                quebra_Pagina(OS);
            }
            if(tipoPedido == 3){
                lista = pedido_Extra(lista, lex, &novo->valorTotal);
                quebra_Pagina(OS);
            }
            if(tipoPedido == 4){
                lista = pedido_Sobremesa(lista, lso, &novo->valorTotal);
                quebra_Pagina(OS);
            }
            novo->quantItens+=1; //Incrementa a quantidade de itens

            printf("Deseja continuar? (S/N):\n");
            scanf("%c%*c", &continuarPedidos);
        }
    }

    
    inserir_FilaPedidos(fila, novo, lista);
    free(novo);
    free(lista);
}

Lista_Pedido* pedido_Sanduiche_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lsan, double* valorTotal){
    int codigo, quantidade;
    double valor;
    char preco;
    Lista_Sanduiche* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lsan);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    while(pos_aux != -1 && ((aux = le_ListaSanduiche(lsan,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }

    fscanf(fi, "%d,", &codigo);

    fscanf(fi, "%d,", &quantidade);
    
    fscanf(fi, "%c)", &preco);

    
    if(preco == 'g' || preco == 'G')
        valor = aux->produto.precos.grande;
    else if(preco == 'M' || preco == 'm')
        valor = aux->produto.precos.medio;
    else //Se não for grande nem médio é pequeno
        valor = aux->produto.precos.pequeno;

   Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "SD", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Bebida_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lbe, double* valorTotal){
int codigo, quantidade;
    double valor;
    char preco;
    Lista_Bebidas* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lbe);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    fscanf(fi, "%d,", &codigo);

    while(pos_aux != -1 && ((aux = le_ListaBebidas(lbe,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    
    fscanf(fi, "%d,", &quantidade);
    
    fscanf(fi, "%c)", &preco);

    if(preco == 'g' || preco == 'G')
        valor = aux->produto.precos.grande;
    else if(preco == 'M' || preco == 'm')
        valor = aux->produto.precos.medio;
    else //Se não for grande nem médio é pequeno
        valor = aux->produto.precos.pequeno;

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "BB", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Extra_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lex, double* valorTotal){
    int codigo, quantidade;
    double valor;
    Lista_Extra* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lex);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    fscanf(fi, "%d,", &codigo);

    while(pos_aux != -1 && ((aux = le_ListaExtra(lex,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }
    
    fscanf(fi, "%d)", &quantidade);
    valor =  aux->produto.preco;

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome,"EX", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

Lista_Pedido* pedido_Sobremesa_Lote(FILE* fi, Lista_Pedido* pedidos, FILE* lso, double* valorTotal){
    int codigo, quantidade;
    double valor;
    Lista_Sobremesa* aux = NULL; //Para procurar o sanduiche da lista de cadastrados

    cabecalho_item* cab = le_cabecalho(lso);
    int pos_aux = cab->pos_cabeca;
    int pos_ant = cab->pos_cabeca;

    fscanf(fi, "%d,", &codigo);

    while(pos_aux != -1 && ((aux = le_ListaSobremesas(lso,pos_aux))!= NULL) && (aux->produto.codigo != codigo)){ //Procura o elemento a ser removido
        pos_ant = pos_aux;
        pos_aux = aux->prox;
        free(aux);
        aux = NULL;
    }

    fscanf(fi, "%d)", &quantidade);

    valor =  aux->produto.preco;

    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));

    novo->produto = insere_Dados_Pedido(novo->produto, aux->produto.nome, "SM", codigo, quantidade, valor);
    *valorTotal += novo->produto.valorPedido;

    novo->proximo = pedidos;

    return novo; //Retorna pedidos alterado
}

void cadastrar_Pedidos_Lote(FILE* fila, FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char OS, FILE *fi){ //lcli
    Fila_Pedidos* novo = (Fila_Pedidos*) malloc(sizeof(Fila_Pedidos));
    novo->valorTotal = 0;
    novo->quantItens = 0;

    Lista_Pedido* lista = NULL; //Inicializa a lista de produtos pedido
    char tipo[3];
    char pontoVirgula;

    
    fscanf(fi, "%d;", &novo->codigo);
    
    fscanf(fi, "%[^;]%*c", novo->cpf);


    while(fscanf(fi,"(%[^,]%*c", tipo) != EOF){
        if(!strcmp("SD", tipo)){
            lista = pedido_Sanduiche_Lote(fi, lista, lsan, &novo->valorTotal);
        }
        if(!strcmp("BB", tipo)){
            lista = pedido_Bebida_Lote(fi, lista, lbe, &novo->valorTotal);
        }
        if(!strcmp("EX", tipo)){
            lista = pedido_Extra_Lote(fi, lista, lex, &novo->valorTotal);
        }
        if(!strcmp("SM", tipo)){
            lista = pedido_Sobremesa_Lote(fi, lista, lso, &novo->valorTotal);
        }
        novo->quantItens++;

        fscanf(fi,"%c", &pontoVirgula);
        if(pontoVirgula != ';') break;
    }
    inserir_FilaPedidos(fila, novo, lista);
}

void atender_Pedido(FILE* fpe_Atendidos, FILE* fpe){
    Cabecalho_Pedido *cab=le_cabecalhoPedidos(fpe); //Leitura do cabeçalho de pedidos não atendidos
    
    if(cab->posiCabeca == -1) printf("Não há pedidos para atender!\n"); //Caso não haja nenhum pedido pendente, a fila estará vazia
    else{
        int lixo; //Reutiliza uma função, essa var. é lixo aqui

        Fila_Pedidos *aux=(Fila_Pedidos*)malloc(sizeof(Fila_Pedidos));//Fila auxiliar que ira transportar o pedido atendido
        aux = le_Filapedidos(fpe, cab->posiCabeca, cab->quantItens_AntCabeca);//Pega esse pedido que vai ser atendido

        Lista_Pedido* listaAux = NULL;//Lista auxiliar que ira receber os produtos pedidos
        listaAux = leProdutosCabeca_Ped(aux, listaAux, fpe, cab);//Pega esses produtos pedidos

        remove_Pedido(fpe, aux->codigo, aux->cpf, &lixo);

        inserir_FilaPedidos(fpe_Atendidos,aux,listaAux);
        printf("Pedido atendido!\n");
    }
}

Lista_Pedido* inserir_FilaPedido(Lista_Pedido* lista, Pedido_No info){
    Lista_Pedido* novo = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));
    novo->produto = info;
    novo->proximo = lista;

    return novo;
}

Lista_Pedido* leProdutosCabeca_Ped(Fila_Pedidos *aux, Lista_Pedido* lista, FILE *fila, Cabecalho_Pedido *cab){

    Lista_Pedido* lAux=(Lista_Pedido*)malloc(sizeof(Lista_Pedido));
    Pedido_No produto;
    int i;
    for(i = 0; i < aux->quantItens; i++){  //Faz passagem de item a item para a lista auxiliar
        fseek(fila,sizeof(Cabecalho_Pedido)+sizeof(Fila_Pedidos)*(cab->posiCabeca+1) + sizeof(Lista_Pedido)*cab->quantItens_AntCabeca + sizeof(Lista_Pedido)*i,SEEK_SET);
        fread(lAux,sizeof(Lista_Pedido),1,fila);

        //Cria uma cópia das informações
        produto.codigo = lAux->produto.codigo;
        strcpy(produto.nome,lAux->produto.nome);
        produto.quantidade=lAux->produto.quantidade;
        strcpy(produto.tipo,lAux->produto.tipo);
        produto.valorPedido=lAux->produto.valorPedido;

        //Faz várias inserções
        lista = inserir_FilaPedido(lista, produto);
    }

    return lista;
}

void cancelar_Pedido(FILE* fpe){
    Cabecalho_Pedido *cab=le_cabecalhoPedidos(fpe);

    if(cab->posiCabeca == -1) printf("Não há pedidos para remover!\n");
    else{
        Fila_Pedidos *filaAux=(Fila_Pedidos*)malloc(sizeof(Fila_Pedidos)); //Vai fazer passagem

        int quantItemAux=0;
        int posAux=cab->posiCabeca;

        filaAux = le_Filapedidos(fpe, posAux, cab->quantItens_AntCabeca);
        quantItemAux += filaAux->quantItens + cab->quantItens_AntCabeca;

        char cpf[12], continuar;
        int flag = 0; //Caso não ache o pedido, permanecerá igual a um
        int numeroPedido;
        int ant;
        
        while(1){
            printf("Digite o CPF cadastrado no pedido: ");
            scanf("%[^\n]%*c", cpf);

            printf("Pedidos não atendidos com esse cpf: \n");

            while(ant != -1){
                ant = filaAux->prox;
                if(!strcmp(filaAux->cpf, cpf)){
                    flag = 1; //Demarca que encontrou o pedido
                    imprimir_Lista_Pedido(fpe, filaAux);
                }
                filaAux=le_Filapedidos(fpe, ++posAux, quantItemAux);//Fica realizando a passagem
                quantItemAux += filaAux->quantItens;
            }

            if(flag) break; //Quebra o loop infinito pq tem pedidos com o cpf escrito
            else{
                printf("Não há pedido com esse cpf, deseja colocar outro cpf?(S/N)");
                scanf("%c%*c", &continuar);
                if(continuar == 'S' || continuar == 's'); //Faz nada e repete o while
                else if(continuar == 'N' || continuar == 'n') break;
                else{
                    printf("Entrada invalida!");
                    break;
                }
            }
        }
        while(flag){
            printf("Insira o número do pedido que deseja remover: ");
            scanf("%d%*c", &numeroPedido);
            
            remove_Pedido(fpe, numeroPedido, cpf, &flag);

            if(flag){ //Se o flag continuar 1, foi inserido número do pedido errado
                printf("Não há pedido com esse número, deseja colocar outro número?(S/N)");
                scanf("%c%*c", &continuar);
                if(continuar == 'S' || continuar == 's'); //Faz nada e repete o while
                else if(continuar == 'N' || continuar == 'n') break;
                else{
                    printf("Entrada invalida!");
                    break;
                }
            }
            else break;
        }
    }
}

void remove_Pedido(FILE* fpe, int numeroPedido, char cpf[12], int *flag){
    Cabecalho_Pedido *cab=le_cabecalhoPedidos(fpe);

    Fila_Pedidos *filaAux=(Fila_Pedidos*)malloc(sizeof(Fila_Pedidos)); //Vai fazer passagem
    Fila_Pedidos *filaAnt=(Fila_Pedidos*)malloc(sizeof(Fila_Pedidos)); //Vai ajudar na remoção

    int quantItemAux=0;
    int posAux=cab->posiCabeca;
    int posAnt,quantAnt;
    int ant;

    filaAux = le_Filapedidos(fpe, posAux, cab->quantItens_AntCabeca);
    quantItemAux += filaAux->quantItens + cab->quantItens_AntCabeca;
    filaAnt = le_Filapedidos(fpe, posAux, cab->quantItens_AntCabeca);

    while(ant !=-1){
        ant = filaAux->prox;
        if(filaAux->prox!=0){//Se for igual a zero, o pedido não é válido
            posAnt = posAux;
            quantAnt = quantItemAux-filaAux->quantItens;
            filaAnt = le_Filapedidos(fpe, posAnt, quantAnt);
        }
        if(filaAux->codigo == numeroPedido && !strcmp(filaAux->cpf, cpf)){
            *flag = 0; //Demarca que encontrou o pedido
            break;
        }
        filaAux=le_Filapedidos(fpe, ++posAux, quantItemAux);//Fica realizando a passagem
        quantItemAux += filaAux->quantItens;
    }

    if(*flag == 0){ //Demarca que encontrou o pedido
        if(posAux==cab->posiCabeca){ //Se o elemento estiver na cabeça da fila
            if(cab->posiCabeca == cab->posiCauda)cab->posiCauda=-1; //Se ele for o único pedido na fila
            cab->posiCabeca = filaAux->prox; //Muda a cabeça
            cab->quantItens_AntCabeca += filaAux->quantItens; //Modifica a quantidade de itens na cabeça
        }
        else{
            filaAnt->prox = filaAux->prox; //Encadeia o elemento anteriro com o removido
            escreve_Filapedidos(fpe,filaAnt,posAnt,quantAnt);
            if(posAux == cab->posiCauda){ //Se o elemento está na cauda
                cab->posiCauda = posAnt;
                cab->quantItens_AntCauda -= filaAnt->quantItens;//Modifica quantidade itens
            }
        }
        quantItemAux -= filaAux->quantItens;
        filaAux->prox = 0;
        escreve_Filapedidos(fpe, filaAux, posAux, quantItemAux);
        escreve_CabPedidos(fpe, cab);
        free(filaAnt);
        free(filaAux);
    }
}

void imprimir_Pedido_Desejado(FILE* fpe){
    Cabecalho_Pedido *cab=le_cabecalhoPedidos(fpe);

    if(cab->posiCabeca == -1) printf("A fila está vázia...");
    else{
        Fila_Pedidos *filaAux=(Fila_Pedidos*)malloc(sizeof(Fila_Pedidos)); //Vai fazer passagem

        char continuar, comando;
        int flag = 1; //Caso não ache o pedido, permanecerá igual a um
        int numeroPedido;
        int ant;

        printf("Deseja ver os pedidos disponíveis? (S/N): ");
        scanf("%c%*c", &comando);
        if(comando == 'S' || comando == 's') //Só é preciso fazer verificação para imprimir, caso não queira tanto faz
            imprimir_Fila_Pedidos(fpe);
        

        while(1){
            printf("Insira o número do pedido que deseja visualizar: ");
            scanf("%d%*c", &numeroPedido);

            int quantItemAux=0;
            int posAux=cab->posiCabeca;

            filaAux = le_Filapedidos(fpe, posAux, cab->quantItens_AntCabeca);
            quantItemAux += filaAux->quantItens + cab->quantItens_AntCabeca;

            while(ant != -1){
                ant = filaAux->prox;
                if(filaAux->codigo == numeroPedido){
                    flag = 0; //Demarca que encontrou o pedido
                    imprimir_Lista_Pedido(fpe, filaAux);
                    break;
                }
                filaAux=le_Filapedidos(fpe, ++posAux, quantItemAux);//Fica realizando a passagem
                quantItemAux += filaAux->quantItens;
            }

            if(flag){
                printf("Pedido não encontrado com esse número. Deseja tentar novamente? (S/N): ");
                scanf("%c%*c", &comando);
                if(comando == 'S' && comando == 's');
                else break;
            }
            else break;
        }
    }
}

void imprimir_Lista_Pedido(FILE* fila, Fila_Pedidos *lpe){
    Lista_Pedido* aux = (Lista_Pedido*) malloc(sizeof(Lista_Pedido));
    int cont;

    printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
    printf("║Pedido nº %d\n", lpe->codigo);
    printf("╠══════════════════════════════════════════════════════════════════════════\n");
    for(cont = 0; cont < lpe->quantItens; cont++){
        fseek(fila, 0, SEEK_CUR);
        fread(aux, sizeof(Lista_Pedido), 1, fila);

        printf("║Cod do produto: %d\n", aux->produto.codigo);
        printf("║Nome do produto: %-25s       Tipo:%s \n", aux->produto.nome, aux->produto.tipo);
        printf("║Valor = R$%4.02lf                            Quantidade: %d\n", aux->produto.valorPedido, aux->produto.quantidade);
        printf("╠══════════════════════════════════════════════════════════════════════════\n");
    }
    printf("║Valor Total = R$%4.02lf\n", lpe->valorTotal);
    printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
}

void imprimir_Fila_Pedidos(FILE* arq){
    Cabecalho_Pedido *cab = le_cabecalhoPedidos(arq);
    if(cab->posiCabeca==-1) printf("Não há pedidos cadastrado\n");
    else{
        Fila_Pedidos* aux = (Fila_Pedidos*) malloc(sizeof(Fila_Pedidos));
        int quantItem = 0;
        int auxi = cab->posiCabeca;
        int ant; //Para permitir que eu printe todos os pedidos, sem pular o último da lista

        aux = le_Filapedidos(arq, auxi, cab->quantItens_AntCabeca);
        quantItem += aux->quantItens+cab->quantItens_AntCabeca;
        
        while(ant != -1){
            if(ant != 0){
                printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
                printf("║Código do pedido: %d       CPF:%s \n", aux->codigo, aux->cpf);
                printf("║Valor Total = R$%4.02lf\n", aux->valorTotal);
                printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n");
            }
            ant = aux->prox;
            aux = le_Filapedidos(arq, ++auxi, quantItem);
            quantItem+=aux->quantItens;
        }
    }
}