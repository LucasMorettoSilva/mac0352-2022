#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <iostream>

#include <game-piece.h>

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

#endif /* ifndef GAME_BOARD_H */
