#include <iostream>
/*
Lista Simplesmente encadeada
Que deve inserir em ordem crescente vários números

*/

int inputValor(void) { // Função simples apenas para a leitura do valor inserido pelo usuario
	int valor;
	std::cout << "\n\nDigite o VALOR: ";
	std::cin >> valor;
	return valor;
}
typedef struct Nodo {

	int valor;
	struct Nodo* prox;

}Nodo;

class ListaEncadeada {

private:
	//Atributos da classe
	int qtdNodo; // Contador para saber a quantidade de numero que existem dentro da lista
	Nodo* inicio; // Ponteiro para o inicio da lista
	Nodo* fim; // Ponteiro para o fim

public:
	//Metodos
	ListaEncadeada(void);//Construtor
	void inserirNodo(int valor);
	void removerNodo(int valor);
	void buscarNodo(int valor);
	void listarNodos(void);

private:

	Nodo* criarNodo(int valor);
	Nodo* buscarPosicao(int valor);
	Nodo* pesquisarNodo(int valor);
};

//================================| Declarações da classe |=====================

////====================================| Metodos Privados |==============================
ListaEncadeada::ListaEncadeada(void) {

	qtdNodo = 0;
	inicio = NULL;
	fim = NULL;

}
Nodo* ListaEncadeada::criarNodo(int valor) {
	Nodo* novo = new Nodo;
	novo->prox = NULL;
	novo->valor = valor;
	return novo;

}
Nodo* ListaEncadeada::buscarPosicao(int valor) {
	Nodo* atual = inicio;
	while (atual != NULL) {
		if (atual->prox->valor >= valor) {
			return atual;
		}
		atual = atual->prox;
	}
	return NULL;
}
Nodo* ListaEncadeada::pesquisarNodo(int valor) {
	Nodo* aux = inicio;
	while (aux != NULL) {
		if(aux->valor == valor){
			//O valor foi encontrado na lista
			return aux;
		}
		aux = aux->prox;
	}//while
	return NULL;;
}
//====================================| Metodos Publicos |==============================

void ListaEncadeada::inserirNodo(int valor) {
	Nodo* novo = criarNodo(valor);
	Nodo* ante;
	if (inicio == NULL) {
		//A lista está vazia
		inicio = novo;
		fim = novo;

	}
	else{
	//Existe algum Nodo na lista
		if(valor <= inicio->valor){
			//O valor a ser inserido é o menor da Lista
			novo->prox = inicio;
			inicio = novo;
				
		}
		else if(valor >= fim->valor){
			//O valor a ser inserido é o maior de todos
			fim->prox = novo;
			fim = novo;
			
		}
		else{	
			//O valor deverá ser colocado no meio da Lista
			ante = buscarPosicao(valor);
			novo->prox = ante->prox;
			ante->prox = novo;
		}	
	}
	qtdNodo++;
}

void ListaEncadeada::removerNodo(int valor) {
	Nodo* aux;
	Nodo* removido;//Ponteiro para marcar o Nodo que será excluido
	removido = pesquisarNodo(valor);
	if (inicio == NULL || removido ==NULL) {
		std::cout << "\n\n\tA lista esta vazia ou Elemento nao existe!!";

	}
	else {
		if(inicio == fim){
			//Existe só 1 elemento da lista
			inicio = NULL;
			fim = NULL;
		}
		else if(valor == fim->valor){
			//Ultimo da lista
			aux = buscarPosicao(valor);
			removido = fim;
			fim = aux;
			fim->prox = NULL;
			delete(removido);
			
		}
		else if(valor == inicio->valor){
			//Primeiro da lista
			removido = inicio;
			inicio = inicio->prox;
			delete(removido);
		}
		else{
			//Esta no meio da lista
			aux = buscarPosicao(valor);
			removido = aux->prox;
			aux->prox = removido->prox;
			delete(removido);
			
		}
		std::cout << "\n\n\tNodo excluido com sucesso!!";
		qtdNodo--;
	}
	
}

void ListaEncadeada::buscarNodo(int valor) {
	Nodo* encontrado;
	if (inicio == NULL) {
		std::cout << "\n\n\tA Lista esta vazia!!";
	}
	else{
		encontrado = pesquisarNodo(valor);
		if (encontrado == NULL) {
			std::cout << "\n\n\tValor nao encontrado!!";
		}
		else {
			std::cout << "\n\n\tValor encontrado!!";
		}
	}
}

void ListaEncadeada::listarNodos(void) {
	Nodo* aux;
	aux = inicio;
	if(inicio == NULL){
		std::cout << "\n\n\tA lista esta vazia!!";
	}
	else{
		std::cout << "\n\tExistem: " << qtdNodo << " elementos\n\n";
		while (aux != NULL) {
			std::cout << "\n\tValor: " << aux->valor;
			aux = aux->prox;
		}
	}
}
