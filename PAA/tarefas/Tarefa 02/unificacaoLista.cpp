#include <stdlib.h>
struct Celula {
    Celula* prox;
    Celula* ant;
    int elemento;
};
class Lista{
    public:
    Celula* primeiro;
    Lista(){
        primeiro = (Celula *)malloc(sizeof(Celula));
        primeiro->prox = NULL;
        primeiro->ant = NULL;
    }
    int remove(int position){

    }
    void inserir(int position, int valor){

    }
    void inserirFinal(int valor){

    }
};

void unificacaoLista(int tamLista, Lista lista){
    int a, b;
    for(int i = 0; i < (tamLista-1); i++){  
        a = lista.remove(1);
        b = lista.remove(2);
        int valor = a+b;
        bool menor = true;
        bool inserido = false;
        Celula* count = lista.primeiro; //celula
        int count2 = 0;                 // position
        while(menor && count !=NULL){
            if(count->elemento > valor ){
                menor = false;
                lista.inserir(count2, valor);
                inserido = true;
            }
            count2++;
        }
        if(!inserido){
            lista.inserirFinal(valor);
        }
    }

}

int main(){

}