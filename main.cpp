
#include <iostream>

#include "tabuleiro.h"

using namespace std;

int main() {

	Tabuleiro t;

	while(true) {

		for(int i = 0 ; i < 8 ; i++) {

			for(int j = 0; j < 8 ; j++) {

				std::cout.width(3);
				std::cout << t.getMatriz(i, j) << ' ';

			}

			std::cout << std::endl;
		}
		

		std::cout << "Entrada: ";
		int x, y;
		std::string peca;
		
		std::cin >> peca;
		std::cin >> x >> y;

		if(!t.jogada(peca, x, y)) {

			std::cout << "Jogada Invalida" << std::endl;
		}
	}

	return 0;
}