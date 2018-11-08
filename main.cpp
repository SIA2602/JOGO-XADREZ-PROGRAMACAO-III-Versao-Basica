
#include <iostream>
#include <stdio.h>

#include "tabuleiro.h"

using namespace std;

int main() {

	static const bool printar_caracteres_especiais = false;

	Tabuleiro t;		
	
	while(true)
	{

		if(!printar_caracteres_especiais)
		{
			std::cout << "   a  b  c  d  e  f  g  h  " << std::endl;
			std::cout << "---------------------------" << std::endl;
		}
		for(int i = 0 ; i < 8 ; i++) {

			if(printar_caracteres_especiais == false) std::cout << 8-i << "|";

			for(int j = 0; j < 8 ; j++) {
				
				if(printar_caracteres_especiais)
				{				
					std::cout.width(3);
					std::cout << t.getMatriz(i, j) << ' ';
					continue;
				}

				string nome_peca = t.getMatriz(i, j);
				char tipo = nome_peca[0];
				char cor = nome_peca[nome_peca.size() - 1];				

				//std::cout.width(4);
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
				else std::cout << " - ";	
			}
			
			if(printar_caracteres_especiais == false) std::cout << "|" << 8-i << std::endl;
			else std::cout << std::endl;
		}
		if(printar_caracteres_especiais == false)
		{
			std::cout << "---------------------------" << std::endl;
			std::cout << "   a  b  c  d  e  f  g  h  " << std::endl;		
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
