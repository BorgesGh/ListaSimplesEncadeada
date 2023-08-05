#include <iostream>
#include <cstdlib>
#include "Lista.h"

int main() {
	bool fator = true;
	int escolha;

	ListaEncadeada L;
	while (fator) {
		system("CLS");
		std::cout << "\n1 - Inserir valor";
		std::cout << "\n2 - Deletar valor";
		std::cout << "\n3 - Exibir valores";
		std::cout << "\n4 - Buscar valor";
		std::cout << "\n5 - Sair";
		escolha = inputValor();
		switch (escolha) {

		case 1:
			L.inserirNodo(inputValor());
			break;
		case 2:
			L.removerNodo(inputValor());
			break;
		case 3:
			L.listarNodos();
			break;
		case 4:
			L.buscarNodo(inputValor());
			break;
		case 5:
			fator = false;
			std::cout << "\n\tFim do programa!!";
			break;
		default:
			std::cout << "\n\n\tOpcao invalida!";
			break;
		}
		std::cout << "\n\n";
		system("PAUSE");
	}
	return 0;
}