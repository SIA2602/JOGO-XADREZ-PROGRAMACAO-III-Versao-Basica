#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctype.h>

#include "tabuleiro.h"
#include "impressaoTerminal.hpp"

// bibliotecas Zabot
#include "aborta.hpp"
#include "dataFileReader.hpp"

using namespace std;

enum{jogo_via_arquivo, via_terminal};
void carrega_dados( vector<string> &jogadas_times, char *argv[] );
int decodifica_main(Tabuleiro &t, string jogadas_times, bool printar_caracteres_especiais, int posicao);
int switch_para_letra(char letra);
int switch_para_numero(char numero);
std::string switch_char_string(char letra);


int main( int argc, char *argv[] )
{
	// Parâmetros de entrada
	bool tipo_leitura = via_terminal; //entrada manual ou por arquivo
	static const bool printar_caracteres_especiais = false;



	Tabuleiro t;
	int retorno = 0, cont=-1;

	if(tipo_leitura == jogo_via_arquivo)
	{
		if( argc!=2 ) aborta( "Numero de parametros de entrada errado!" );
		std::vector<string> jogadas_times;
		carrega_dados(jogadas_times, argv);

		int tamanho = jogadas_times.size();

		for(int i=0; i < tamanho; i++)
		{
			impressao(t, printar_caracteres_especiais);
			retorno = decodifica_main(t, jogadas_times[std::size_t(i)], printar_caracteres_especiais, i);
			if(retorno==0 && cont!=-1 )
			{
				--cont;
			}
		}
		impressao(t, printar_caracteres_especiais);
	}

	else
	{
		cont = 0;
		for(;;)
		{
			impressao(t, printar_caracteres_especiais);
			if( cont%2 == 0 ) std::cout << "Entrada Time Branco: ";
			else std::cout << "Entrada Time Preto: ";
			std::string jogada;
			std::cin >> jogada;
			if(jogada == "fim") break;

			retorno = decodifica_main(t, jogada, printar_caracteres_especiais, cont);
			if(retorno==1)
			{
				cont++;
			}
		}
	}
	return 0;
}


void carrega_dados( vector<string> &jogadas_times, char *argv[] )
{
	DataFileReader dfr(argv[1]);
	// Lê os dados
	int jogada;
	string time_branco, time_preto;

	for(;;)
	{
		++dfr;
		dfr >> jogada >> time_branco >> time_preto;
		if( time_branco == "fim" || time_preto == "fim" ) break;
		//cout << jogada << " " << time_branco << " " << time_preto << endl;
		jogadas_times.push_back(time_branco);
		jogadas_times.push_back(time_preto);
	}

	return;
}



int decodifica_main(Tabuleiro &t, string jogadas_times, bool printar_caracteres_especiais, int posicao)
{
	char cor_time;
	if(posicao%2 == 0) cor_time = 'B';
	else cor_time = 'P';

	std::string jogada_atual = jogadas_times;
	std::string peca;
	//caso letras sejam miusculas significa que sera apenas peao
	if(islower(jogada_atual[0]) != 0)
	{
		if(jogada_atual.size() == 2) //apenas movimentacao
		{
			peca = std::string("P") + char('1' + switch_para_letra(jogada_atual[0])) + cor_time;
			int linha = switch_para_numero(jogada_atual[1]);
			int coluna = switch_para_letra(jogada_atual[0]);
			cout << peca << " " << linha << " " << coluna << endl;

			if(!t.jogada(peca, linha, coluna, jogada_atual))
			{
				std::cout << "Jogada Invalida" << std::endl;
				return 0;
			}
			else return 1;
		}

		else if(jogada_atual.size() == 4) //movimentacao seguida de comida de peca
		{
			peca = std::string("P") + char('1' + switch_para_letra(jogada_atual[0])) + cor_time;
			int linha = switch_para_numero(jogada_atual[3]);
			int coluna = switch_para_letra(jogada_atual[2]);
			cout << peca << " " << linha << " " << coluna << endl;

			if(!t.jogada(peca, linha, coluna, jogada_atual))
			{
				std::cout << "Jogada Invalida" << std::endl;
				return 0;
			}
			else return 1;
		}
	}

	//caso seja minuscula sera as pecas restantes
	else if(isupper(jogada_atual[0]) != 0)
	{
		if(jogada_atual.size() == 3) //apenas movimentacao para cavalos
		{
			peca = switch_char_string(jogada_atual[0]) + std::string("1") + cor_time;
			if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
			int linha = switch_para_numero(jogada_atual[2]);
			int coluna = switch_para_letra(jogada_atual[1]);

			if(!t.jogada(peca, linha, coluna, jogada_atual))
			{
				peca = switch_char_string(jogada_atual[0]) + std::string("2") + cor_time;
				if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
				if(!t.jogada(peca, linha, coluna, jogada_atual))
				{
					std::cout << "Jogada Invalida" << std::endl;
					return 0;
				}
				std::cout << peca << " " << linha << " " << coluna << endl;
				return 1;
			}
			cout << peca << " " << linha << " " << coluna << endl;
		}

		if(jogada_atual.size() == 4) //apenas movimentacao para cavalos
		{
    	if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
    	int linha = switch_para_numero(jogada_atual[3]);
    	int coluna = switch_para_letra(jogada_atual[2]);

    	cout << peca << " " << linha << " " << coluna << endl;
    	if(!t.jogada(peca, linha, coluna, jogada_atual))
    	{
        	return 0;
    	}

    	else
    	{
        	peca = switch_char_string(jogada_atual[0]) + std::string("2") + cor_time;
        	if(jogada_atual[0] == 'R' || jogada_atual[0] == 'D' ) peca = switch_char_string(jogada_atual[0]) + cor_time;
        	else return 1;
    	}
    }
		else return 0;
	}
	return 0;
}



int switch_para_letra(char letra)
{
	switch(letra)
	{
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 4;
		case 'f':
			return 5;
		case 'g':
			return 6;
		case 'h':
			return 7;
		default:
			return -1;
	}

	return -1;
}

int switch_para_numero(char numero)
{
	switch(numero)
	{
		case '1':
			return 7;
		case '2':
			return 6;
		case '3':
			return 5;
		case '4':
			return 4;
		case '5':
			return 3;
		case '6':
			return 2;
		case '7':
			return 1;
		case '8':
			return 0;
		default:
			return -1;
	}

	return -1;
}

std::string switch_char_string(char letra)
{
	switch(letra)
	{
		case 'C':
			return std::string("C");
		case 'T':
			return std::string("T");
		case 'B':
			return std::string("B");
		case 'D':
			return std::string("D");
		case 'R':
			return std::string("R");
		default:
			return std::string("erro");
	}

	return std::string("erro");;
}
