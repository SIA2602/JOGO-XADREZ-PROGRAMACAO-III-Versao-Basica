#include <iostream>
#include <stdio.h>

#include "tabuleiro.h"
#include "impressaoTerminal.hpp"

// bibliotecas Zabot
#include "aborta.hpp"
#include "dataFileReader.hpp"

using namespace std;

enum{jogo_via_arquivo, via_terminal};

int main( int argc, char *argv[] )
{
	// Parâmetro de entrada
	//if( argc!=2 ) aborta( "Numero de parametros de entrada errado!" );

	static const bool printar_caracteres_especiais = false;

	Tabuleiro t;		
	
	while(true)
	{
		impressao(t, printar_caracteres_especiais);
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
