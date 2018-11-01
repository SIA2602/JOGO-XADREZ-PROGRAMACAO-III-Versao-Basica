
#include <iostream>
#include <stdio.h>

#include "tabuleiro.h"

using namespace std;

int main() {

	Tabuleiro t;		

	while(true)
	{

		for(int i = 0 ; i < 8 ; i++) {

			for(int j = 0; j < 8 ; j++) {

				string nome_peca = t.getMatriz(i, j);
				char tipo = nome_peca[0];
				char cor = nome_peca[nome_peca.size() - 1];				

				std::cout.width(4);				

				if( cor == 'P')
				{
					switch(tipo)
					{

						case 'T':				
							std::cout << " \u265C" << ' ';
							break;
						case 'C':				
							std::cout << " \u265E" << ' ';
							break;
						case 'B':				
							std::cout << " \u265D" << ' ';
							break;					
						case 'P':				
							std::cout << " \u265F" << ' ';
							break;				
						case 'R':				
							std::cout << " \u265A" << ' ';
							break;					
						case 'D':				
							std::cout << " \u265B" << ' ';
							break;								
					}			
				}

				else if( cor == 'B')
				{
					switch(tipo)
					{

						case 'T':				
							std::cout << " \u2656" << ' ';
							break;
						case 'C':				
							std::cout << " \u2658" << ' ';
							break;
						case 'B':				
							std::cout << " \u2657" << ' ';
							break;					
						case 'P':				
							std::cout << " \u2659" << ' ';
							break;					
						case 'R':				
							std::cout << " \u2654" << ' ';
							break;					
						case 'D':				
							std::cout << " \u2655" << ' ';
							break;								
					}			
				}							
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