/*Considere uma pilha P vazia e uma fila F não vazia.
Utilizando apenas as operações inserir/enfileirar e remover/desenfileirar
de ambas as estruturas, escreva uma função que inverta a ordem dos elementos da fila.*/

#include<stdio.h>
struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(int valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }
};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

};


int main() {

    Pilha p;
    Fila f;
    
    f.enfileirar(1);
    f.enfileirar(2);
    f.enfileirar(3);
    f.enfileirar(4);
    f.enfileirar(5);
    printf("Frente da fila inicial: %d\n", f.frente());
    while(f.n !=0){
        p.inserir(f.inicio->valor);
        f.desenfileirar();
    }
    printf("Topo da pilha apos insercao: %d\n", p.topoPilha());
   
    while(p.n != 0){
        f.enfileirar(p.topo->valor);
        p.remover();
    }
    printf("Frente da fila final: %d\n", f.frente());


    return 0;
}