#include <stdio.h>
#include <string.h>
#include "prototipo dos alimentos.h"
#include "prototipo de pedidos.h"
#include "prototipo de interface.h"

int main(){
//     Lista_Clientes* lcli = criaLista_Clientes(lcli); 
//     Fila_Pedidos* filaPedidos = criaFila_Pedidos(filaPedidos);
//     Fila_Pedidos* filaPedidos_Atendidos = criaFila_Pedidos(filaPedidos_Atendidos);
    
    char OS, AB; //Variável responsável por guardar o sistema operacional e carregamenteo de Arquivo Binário
    char operacao[5];
    int escolha;
    inicializa_Programa(&OS, &AB);
    quebra_Pagina(OS);
    
    FILE *lsan, *lbe, *lso, *lex, *filaPedidos, *filaPedidos_Atendidos;
    inicializa_ArquivoBinario(AB, &lsan, &lbe, &lso, &lex, &filaPedidos, &filaPedidos_Atendidos);
    

    while(1){
        apresenta_Menu();
        scanf("%d%*c", &escolha);

        if(escolha == 1){ //Escolha que guia para o menu de cadastro
                menu_Cadastro(lsan, lbe, lex, lso, OS);
        }
        else if(escolha == 2){//Ecolha que guia para o menu de catálogo
                menu_Catalogo(lsan, lbe, lex, lso, OS);
        }
        else if(escolha == 3){
                menu_Pedidos(lsan, lbe, lex, lso, filaPedidos_Atendidos, filaPedidos, OS); //&lcli
        }
        else if(escolha == 4){
                ler_Lote(lsan, lbe, lex, lso, filaPedidos, OS);
                printf("Arquivo carregado!\n");
                scanf("%*c");
        }
        else if(escolha == 5){
                break;
        }
        quebra_Pagina(OS);        
    }

    fclose(lsan);
    fclose(lbe);
    fclose(lex);
    fclose(lso);
    return 0;
}
