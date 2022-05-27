#ifndef TTT_ENGINE_HPP
#define TTT_ENGINE_HPP

#include <iostream>

#include "game-piece.hpp"

class GameBoard {

private:
	char t[3][3];
	int piecesInGame;

    bool isEmptyPosition(int row, int collumn);

    bool checkWinnerRow();
    bool checkWinnerCollumn();
    bool checkWinnerDiagonal();

public:
	GameBoard();

	// Retorna 0 se não foi possível colocar a peça nesse local
	// Retorna 1 caso contrário
	int update(int row, int collumn, bool isX);

	// Inicalizar as variaveis da classe
	void build();

	// Retorna 1 se houve um vencedor
	// Retorna 2 se houve empate
	int winner();

	// Imprime o tabuleiro
	void print();
};

#endif /* ifndef TTT_ENGINE_HPP */
