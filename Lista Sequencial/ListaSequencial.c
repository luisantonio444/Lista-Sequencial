#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} ListaSequencial;

// Função para criar uma lista vazia
void criarLista(ListaSequencial *lista) {
    lista->size = 0;
}

// Verificar se a lista está vazia
bool listaVazia(ListaSequencial *lista) {
    return lista->size == 0;
}

// Verificar se a lista está cheia
bool listaCheia(ListaSequencial *lista) {
    return lista->size == MAX_SIZE;
}

// Obter o tamanho da lista
int obterTamanho(ListaSequencial *lista) {
    return lista->size;
}

// Obter o valor de um elemento em uma posição
int obterElemento(ListaSequencial *lista, int posicao) {
    if (posicao < 1 || posicao > lista->size) {
        printf("Posição inválida!\\n");
        return -1;
    }
    return lista->data[posicao - 1];
}

// Modificar o valor de um elemento em uma posição
void modificarElemento(ListaSequencial *lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->size) {
        printf("Posição inválida!\\n");
        return;
    }
    lista->data[posicao - 1] = valor;
}

// Inserir um elemento em uma posição
void inserirElemento(ListaSequencial *lista, int posicao, int valor) {
    if (listaCheia(lista)) {
        printf("Lista cheia!\\n");
        return;
    }
    if (posicao < 1 || posicao > lista->size + 1) {
        printf("Posição inválida!\\n");
        return;
    }
    for (int i = lista->size; i >= posicao; i--) {
        lista->data[i] = lista->data[i - 1];
    }
    lista->data[posicao - 1] = valor;
    lista->size++;
}

// Retirar um elemento de uma posição
void retirarElemento(ListaSequencial *lista, int posicao) {
    if (listaVazia(lista)) {
        printf("Lista vazia!\\n");
        return;
    }
    if (posicao < 1 || posicao > lista->size) {
        printf("Posição inválida!\\n");
        return;
    }
    for (int i = posicao - 1; i < lista->size - 1; i++) {
        lista->data[i] = lista->data[i + 1];
    }
    lista->size--;
}

// Função para imprimir a lista
void imprimirLista(ListaSequencial *lista) {
    printf("Lista: ");
    for (int i = 0; i < lista->size; i++) {
        printf("%d ", lista->data[i]);
    }
    printf("\\n");
}

int main() {
    ListaSequencial lista;
    criarLista(&lista);

    inserirElemento(&lista, 1, 10);
    inserirElemento(&lista, 2, 20);
    inserirElemento(&lista, 3, 30);
    imprimirLista(&lista);

    retirarElemento(&lista, 2);
    imprimirLista(&lista);

    modificarElemento(&lista, 2, 50);
    imprimirLista(&lista);

    printf("Elemento na posição 1: %d\\n", obterElemento(&lista, 1));
    printf("Tamanho da lista: %d\\n", obterTamanho(&lista));

    return 0;
}
