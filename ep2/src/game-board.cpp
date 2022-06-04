#ifndef GAME_BOARD_CPP
#define GAME_BOARD_CPP

#include <game-board.h>

GameBoard::GameBoard() {
    this->build();
}

void GameBoard::build() {
    piecesInGame = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t[i][j] = GamePiece::EMPTY;
        }
    }
}

bool GameBoard::isEmptyPosition(int row, int collumn) {
    return t[row][collumn] == GamePiece::EMPTY
        && row < 3
        && collumn < 3
        & row >= 0
        && collumn >= 0;
}

int GameBoard::update(int row, int collumn, bool isX) {
    --row;
    --collumn;

    if (!isEmptyPosition(row, collumn)) {
        return 0;
    }

    char piece;

    if (isX) {
        piece = GamePiece::X;
    } else {
        piece = GamePiece::O;
    }

    t[row][collumn] = piece;

    ++piecesInGame;

    return 1;
}

bool GameBoard::checkWinnerRow() {
    for (int r = 0; r < 3; r++) {
        if (t[r][0] == t[r][1] && t[r][1] == t[r][2] && t[r][0] != GamePiece::EMPTY)
            return true;
    }
    return false;
}

bool GameBoard::checkWinnerCollumn() {
    for (int c = 0; c < 3; c++) {
        if (t[0][c] == t[1][c] && t[1][c] == t[2][c] && t[0][c] != GamePiece::EMPTY)
            return true;
    }
    return false;
}

bool GameBoard::checkWinnerDiagonal() {
    if (t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[1][1] != GamePiece::EMPTY)
        return true;
    if (t[0][2] == t[1][1] && t[1][1] == t[2][0] && t[1][1] != GamePiece::EMPTY)
        return true;
    return false;
}

int GameBoard::winner() {
    checkWinnerRow();
    checkWinnerCollumn();
    checkWinnerDiagonal();

    // empate
    if (piecesInGame == 9)
        return 2;

    return 0;
}

void GameBoard::print() {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "| " << t[i][0] << " | " << t[i][1] << " | " << t[i][2] << " |" << std::endl;
        std::cout << "-------------" << std::endl;
    }
}

#endif /* ifndef GAME_BOARD_CPP */
