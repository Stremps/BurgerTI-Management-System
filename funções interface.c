#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototipo dos alimentos.h"
#include "prototipo de pedidos.h"
#include "prototipo de interface.h"

//Outras Funcionalidades

void quebra_Pagina(char sistemaOperacional){
    if(sistemaOperacional == 'W' || sistemaOperacional == 'w') //Caso o usuário coloque letra minuscula sem querer
        system("cls"); //Limpador de página para windows.
    else if(sistemaOperacional == 'L' || sistemaOperacional == 'l') //Caso o usuário coloque letra minuscula sem querer
        printf("\033c"); //Limpador de página para linux
}

void inicializa_ArquivoBinario(char ArquivoBinario, FILE** lsan, FILE** lbe, FILE** lso, FILE** lex, FILE** filaPedidos, FILE** filaPedidos_Atendidos){
    char operacao[5];

    if(ArquivoBinario == 'N' || ArquivoBinario == 'n') strcpy(operacao, "w+b");
    else strcpy(operacao, "r+b");


    *lsan = fopen("sanduiches.bin",operacao);
    *lbe = fopen("bebidas.bin",operacao);
    *lso = fopen("sobremesas.bin",operacao);
    *lex = fopen("extras.bin",operacao);
    *filaPedidos = fopen("filaPedidos.bin", operacao);
    *filaPedidos_Atendidos = fopen("filaPedidosAtendidos.bin", operacao);
    
    if(ArquivoBinario == 'N' || ArquivoBinario == 'n'){
        cria_lista_vazia(*lsan);
        cria_lista_vazia(*lbe);
        cria_lista_vazia(*lex);
        cria_lista_vazia(*lso);
        criaFila_Pedidos(*filaPedidos);
        criaFila_Pedidos(*filaPedidos_Atendidos);
    }
}

//Funções de interface

void inicializa_Programa(char* sistemaOperacional, char* ArquivoBinario){
    char confirma;
    printf("\n\n");
    printf("██████╗ ██╗   ██╗██████╗  ██████╗ ██╗   ██╗███████╗██████╗     ████████╗██╗\n");
    printf("██╔══██╗██║   ██║██╔══██╗██╔════╝ ██║   ██║██╔════╝██╔══██╗    ╚══██╔══╝██║\n");
    printf("██████╔╝██║   ██║██████╔╝██║  ███╗██║   ██║█████╗  ██████╔╝       ██║   ██║\n");
    printf("██╔══██╗██║   ██║██╔══██╗██║   ██║██║   ██║██╔══╝  ██╔══██╗       ██║   ██║\n");
    printf("██████╔╝╚██████╔╝██║  ██║╚██████╔╝╚██████╔╝███████╗██║  ██║       ██║   ██║\n");
    printf("╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝       ╚═╝   ╚═╝\n\n\n");

    printf("Selecione o sistema operacional(W\\L):\n"); //W para windows e L para linux
    scanf("%c%*c", sistemaOperacional);
    while(1){ //Parte muito importante para o usuário não realizar algum erro inversível!
        printf("Deseja carregar o arquivo binário? (S\\N):\n"); //Se não quiser carregar, cria novos arquivos
        scanf("%c%*c", ArquivoBinario);
        if(*ArquivoBinario == 'n' || *ArquivoBinario == 'N'){
            printf("Irá perder tudo se já tem algo salvo. Tem certeza disso?(S\\N):\n");
            scanf("%c%*c", &confirma);
            if(confirma == 'S' || confirma == 's') break;
        }
        else break;
    }

    printf("\n\n\n\n");
}

void apresenta_Menu(){
    printf("███╗   ███╗██████╗███╗   ██╗██╗  ██╗   \n");
    printf("████╗ ████║██╔═══╝████╗  ██║██║  ██║   \n");
    printf("██╔████╔██║████╗  ██╔██╗ ██║██║  ██║   \n");
    printf("██║╚██╔╝██║██══╝  ██║╚██╗██║██║  ██║   \n");
    printf("██║ ╚═╝ ██║██████╗██║ ╚████║╚█████╔╝   \n");
    printf("╚═╝     ╚═╝╚═════╝╚═╝  ╚═══╝ ╚════╝    \n\n");
    printf("╔════════════════════════════════╗\n");
    printf("║1) Cadastro de produtos         ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║2) Catálogo de produtos         ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║3) Seção de pedidos             ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║4) Inserção em lote             ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║5) Sair do sistema              ║\n");
    printf("╚════════════════════════════════╝\n");   
}

void apresenta_Cadastro(){
    printf(" ██████╗ █████╗ ██████╗  █████╗ ███████╗████████╗██████╗  ██████╗ \n");
    printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔═══██╗\n");
    printf("██║     ███████║██║  ██║███████║███████╗   ██║   ██████╔╝██║   ██║\n");
    printf("██║     ██╔══██║██║  ██║██╔══██║╚════██║   ██║   ██╔══██╗██║   ██║\n");
    printf("╚██████╗██║  ██║██████╔╝██║  ██║███████║   ██║   ██║  ██║╚██████╔╝\n");
    printf(" ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ \n\n");
    printf("╔════════════════════════════════╦════════════════════════════════╗\n");
    printf("║1) Cadastro de sanduíche        ║6) Remover sanduíche            ║\n");
    printf("╠════════════════════════════════╬════════════════════════════════╣\n");
    printf("║2) Cadastro de bebida           ║7) Remover bebida               ║\n");
    printf("╠════════════════════════════════╬════════════════════════════════╣\n");
    printf("║3) Cadastro de extra            ║8) Remover extra                ║\n");
    printf("╠════════════════════════════════╬════════════════════════════════╣\n");
    printf("║4) Cadastro de sobremesa        ║9) Remover sobremesa            ║\n");
    printf("╠════════════════════════════════╬════════════════════════════════╣\n");
    printf("║5) Cadastro de pedido em lote   ║10) Voltar para o menu          ║\n");
    printf("╚════════════════════════════════╩════════════════════════════════╝\n");
    
}

void apresenta_Catalogo(){
    printf(" ██████╗ █████╗ ████████╗ █████╗ ██╗      ██████╗  ██████╗  ██████╗ \n");
    printf("██╔════╝██╔══██╗╚══██╔══╝██╔══██╗██║     ██╔═══██╗██╔════╝ ██╔═══██╗\n");
    printf("██║     ███████║   ██║   ███████║██║     ██║   ██║██║  ███╗██║   ██║\n");
    printf("██║     ██╔══██║   ██║   ██╔══██║██║     ██║   ██║██║   ██║██║   ██║\n");
    printf("╚██████╗██║  ██║   ██║   ██║  ██║███████╗╚██████╔╝╚██████╔╝╚██████╔╝\n");
    printf(" ╚═════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝  ╚═════╝ \n\n");
    printf("╔════════════════════════════════╗\n");
    printf("║1) Apresentar sanduíches        ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║2) Apresentar bebidas           ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║3) Apresentar extras            ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║4) Apresentar sobremesas        ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║5) Voltar para o menu           ║\n");
    printf("╚════════════════════════════════╝\n");
}

void apresenta_Pedidos(){
    printf("██████╗ ███████╗██████╗ ██╗██████╗  ██████╗ ███████╗\n");
    printf("██╔══██╗██╔════╝██╔══██╗██║██╔══██╗██╔═══██╗██╔════╝\n");
    printf("██████╔╝█████╗  ██║  ██║██║██║  ██║██║   ██║███████╗\n");
    printf("██╔═══╝ ██╔══╝  ██║  ██║██║██║  ██║██║   ██║╚════██║\n");
    printf("██║     ███████╗██████╔╝██║██████╔╝╚██████╔╝███████║\n");
    printf("╚═╝     ╚══════╝╚═════╝ ╚═╝╚═════╝  ╚═════╝ ╚══════╝\n\n");
    printf("╔════════════════════════════════╗\n");
    printf("║1) Adicionar pedido             ║\n");
    printf("╠════════════════════════════════║\n");
    printf("║2) Atender pedido               ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║3) Cancelar pedido              ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║4) Apresentar pedidos pendentes ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║5) Apresentar pedidos atendidos ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║6) Apresentar pedido específico ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║7) Cadastrar pedido em lote     ║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║8) Voltar para o menus          ║\n");
    printf("╚════════════════════════════════╝\n");
}


//Funções de usabilidade e retornos

void menu_Cadastro(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char sistemaOperacional){
    int escolha; // Variável de escolha padrão
    int codigo;

    while(1){
        quebra_Pagina(sistemaOperacional);
        apresenta_Cadastro(); //Função que apresenta a interface, reduzida para evitar poluição visual
        scanf("%d%*c", &escolha);
        if(escolha == 1){
            Lista_Sanduiche* aux = (Lista_Sanduiche* ) malloc(sizeof(Lista_Sanduiche));
            aux = cadastra_Sanduiche(aux);
            Insere_Sanduiche(lsan, aux);
            free(aux);
        }
        if(escolha == 2){
            Lista_Bebidas* aux = (Lista_Bebidas*) malloc(sizeof(Lista_Bebidas));
            aux = cadastra_Bebidas(aux);
            Insere_Bebida(lbe, aux);
            free(aux);
        }    
        if(escolha == 3){
            Lista_Extra* aux = (Lista_Extra*) malloc(sizeof(Lista_Extra));
            aux = cadastra_Extra(aux);
            Insere_Extra(lex, aux);
            free(aux);
        }
        if(escolha == 4) {
            Lista_Sobremesa* aux = (Lista_Sobremesa*) malloc(sizeof(Lista_Sobremesa));
            aux = cadastra_Sobremesas(aux);
            Insere_Sobremesa(lso, aux);
            free(aux);
        }
        if(escolha == 5){
            FILE *fi;
            char tipo[3];

            fi = fopen("Entrada1.txt","r");
            while(fscanf(fi, "%[^;]%*c", tipo) != EOF){
                if(!strcmp(tipo, "SD")){
                    Lista_Sanduiche* aux = (Lista_Sanduiche* ) malloc(sizeof(Lista_Sanduiche)); 
                    aux = cadastra_Sanduiche_Lote(aux, fi);
                    Insere_Sanduiche(lsan, aux);
                    free(aux);
                }
                if(!strcmp(tipo, "BB")){
                    Lista_Bebidas* aux = (Lista_Bebidas* ) malloc(sizeof(Lista_Bebidas)); 
                    aux = cadastra_Bebidas_Lote(aux, fi);
                    Insere_Bebida(lbe, aux);
                    free(aux);
                }
                if(!strcmp(tipo, "EX")) {
                    Lista_Extra* aux = (Lista_Extra* ) malloc(sizeof(Lista_Extra)); 
                    aux = cadastra_Extra_Lote(aux, fi);
                    Insere_Extra(lex, aux);
                    free(aux);
                }
                if(!strcmp(tipo, "SM")){
                    Lista_Sobremesa* aux = (Lista_Sobremesa* ) malloc(sizeof(Lista_Sobremesa)); 
                    aux = cadastra_Sobremesas_Lote(aux, fi);
                    Insere_Sobremesa(lso, aux);
                    free(aux);
                }
            }
            fclose(fi);
        }
        if(escolha == 6){
            printf("Insira o código desejado: ");
            scanf("%d%*c", &codigo);
            quebra_Pagina(sistemaOperacional);
            Retira_Sanduiche(lsan, codigo);
            printf("Aperte Enter para continuar");
            scanf("%*c"); //Permite ver se removeu ou não, esperando o enter do usuário
        }
        if(escolha == 7){
            printf("Insira o código desejado: ");
            scanf("%d%*c", &codigo);
            quebra_Pagina(sistemaOperacional);
            Retira_Bebidas(lbe, codigo);
            printf("Aperte Enter para continuar");
            scanf("%*c"); //Permite ver se removeu ou não, esperando o enter do usuário
        }
        if(escolha == 8){
            printf("Insira o código desejado: ");
            scanf("%d%*c", &codigo);
            quebra_Pagina(sistemaOperacional);
            Retira_Extra(lex, codigo);
            printf("Aperte Enter para continuar");
            scanf("%*c"); //Permite ver se removeu ou não, esperando o enter do usuário
        }
        if(escolha == 9){
            printf("Insira o código desejado: ");
            scanf("%d%*c", &codigo);
            quebra_Pagina(sistemaOperacional);
            Retira_Sobremesa(lso, codigo);
            printf("Aperte Enter para continuar");
            scanf("%*c"); //Permite ver se removeu ou não, esperando o enter do usuário
        }
        if(escolha == 10) break; // Break que finaliza a função e retorna para o loop do menu
    }
}

void menu_Catalogo(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, char sistemaOperacional){
    int escolha;

    while(1){
        quebra_Pagina(sistemaOperacional);
        apresenta_Catalogo();
        scanf("%d%*c", &escolha);
        if(escolha == 1){ 
            quebra_Pagina(sistemaOperacional);
            imprimir_Sanduiche(lsan);
            scanf("%*c");
        }
        if(escolha == 2){
            quebra_Pagina(sistemaOperacional);
            imprimir_Bebida(lbe);
            scanf("%*c");
        }
        if(escolha == 3){
            quebra_Pagina(sistemaOperacional);
            imprimir_Extra(lex);
            scanf("%*c");
        }
        if(escolha == 4){ 
            quebra_Pagina(sistemaOperacional);
            imprimir_Sobremesa(lso);
            scanf("%*c");
        }
        if(escolha == 5) break;
    }
}

void menu_Pedidos(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, FILE* fpeAtendidos, FILE* fpe, char sistemaOperacional){ //Lista Cliente
    int escolha;

    while(1){
        quebra_Pagina(sistemaOperacional);
        apresenta_Pedidos();
        scanf("%d%*c", &escolha);
        if(escolha == 1){ 
            quebra_Pagina(sistemaOperacional);
            cadastrar_Pedidos(fpe, lsan, lbe, lex, lso, sistemaOperacional);
        }
        if(escolha == 2){
            quebra_Pagina(sistemaOperacional);
            atender_Pedido(fpeAtendidos, fpe); //Não faz a troca de filas
            scanf("%*c");
        }
        if(escolha == 3){
            quebra_Pagina(sistemaOperacional);
            cancelar_Pedido(fpe); //Se cancelar não vai ser atendido, mas vai permanecer no histórico do cliente
            scanf("%*c");
        }
        if(escolha == 4){ 
            quebra_Pagina(sistemaOperacional);
            imprimir_Fila_Pedidos(fpe); //Imprime pedidos não atendidos
            scanf("%*c");
        }
        if(escolha == 5){
            quebra_Pagina(sistemaOperacional);
            imprimir_Fila_Pedidos(fpeAtendidos); //Imprime pedidos já atendidos
            scanf("%*c");
        }
        if(escolha == 6){
            quebra_Pagina(sistemaOperacional);
            printf("Deseja realizar com qual fila:\n 1) Fila de pedidos não atendidos  2) Fila de pedidos atendidos\n");
            while(1){
                scanf("%d%*c", &escolha);
                if(escolha == 1){
                    imprimir_Pedido_Desejado(fpe);
                    break;
                }
                if(escolha == 2){ 
                    imprimir_Pedido_Desejado(fpeAtendidos);
                    break;
                }
            }
            scanf("%*c");
        }
        if(escolha == 7){
            FILE *fi;
            char tipo[3]; //Serve só para ler o PD e jogar fora

            fi = fopen("Entrada2.txt","r");
            while(fscanf(fi, "%[^;]%*c", tipo) != EOF){
                cadastrar_Pedidos_Lote(fpe, lsan, lbe, lex, lso, sistemaOperacional, fi); //lcli
            }
            fclose(fi);
            printf("Arquivo carregado!\n");
            scanf("%*c");
        }
        if(escolha == 8) break;
    }
}

void ler_Lote(FILE* lsan, FILE* lbe, FILE* lex, FILE* lso, FILE* fpe, char sistemaOperacional){
    char nomeArquivo[50], tipo[3];
    FILE* fi; //File input

    printf("Insira o nome do arquivo: ");
    scanf("%[^\n]%*c", nomeArquivo);
    strcat(nomeArquivo, ".txt");

    fi = fopen(nomeArquivo, "r");

    while(fscanf(fi, "%[^;]%*c", tipo) != EOF){
        if(!strcmp(tipo, "SD")) {
            Lista_Sanduiche* aux = (Lista_Sanduiche* ) malloc(sizeof(Lista_Sanduiche)); 
            aux = cadastra_Sanduiche_Lote(aux, fi);
            Insere_Sanduiche(lsan, aux);
            free(aux);
        }
        if(!strcmp(tipo, "BB")){
            Lista_Bebidas* aux = (Lista_Bebidas* ) malloc(sizeof(Lista_Bebidas)); 
            aux = cadastra_Bebidas_Lote(aux, fi);
            Insere_Bebida(lbe, aux);
            free(aux);
        }
        if(!strcmp(tipo, "EX")){
            Lista_Extra* aux = (Lista_Extra* ) malloc(sizeof(Lista_Extra)); 
            aux = cadastra_Extra_Lote(aux, fi);
            Insere_Extra(lex, aux);
            free(aux);
        }
        if(!strcmp(tipo, "SM")){
            Lista_Sobremesa* aux = (Lista_Sobremesa* ) malloc(sizeof(Lista_Sobremesa)); 
            aux = cadastra_Sobremesas_Lote(aux, fi);
            Insere_Sobremesa(lso, aux);
            free(aux);
        }
        if(!strcmp(tipo, "PD")) cadastrar_Pedidos_Lote(fpe, lsan, lbe, lex, lso, sistemaOperacional, fi);
    }
    fclose(fi);
}