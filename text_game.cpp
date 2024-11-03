
#include <iostream>
#include <string>

void print_board(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                std::cout << "X";
            }
            else if (board[i][j] == 2) {
                std::cout << "O";
            }
            else {
                std::cout << " ";
            }
            std::cout << " ";
        if (j == 0 || j == 1) {
            std::cout << "|";
        }
        std::cout << " ";
        }
        
        std::cout << "\n";
        if (i == 0 || i == 1) {
            std::cout << "---------";
        }
        std::cout << "\n";
    }
}

bool winnerFound(int board[3][3]) {

    // Rows
    for(int i = 0; i < 3; i++) {
        int temp = board[i][0];
        if (temp == 0) {
            continue;
        }
        for(int j = 0; j < 3; j++) {
            if (board[i][j] == temp) {
                if (j == 2) {
                    return true;
                }
                continue;
            }
            else {
                break;
            }
        }
    }

    //Cols
    for(int i = 0; i < 3; i++) {
        int temp = board[0][i];
        if (temp == 0) {
            continue;
        }
        for(int j = 0; j < 3; j++) {
            if (board[j][i] == temp) {
                if (j == 2) {
                    return true;
                }
                continue;
            }
            else {
                break;
            }
        }
    }

    //Diagonal
    int temp = board[0][0];
    for (int i = 1, j = 1; i < 3; i++, j++) {
        if (temp == 0) {
            break;
        }
        if (board[i][j] == temp) {
            if (i == 2) {
                
                return true;
            }
            continue;
        }
        else {
            break;
        }
    }

    temp = board[0][2];
    for (int i = 1, j = 1; i < 3; i++, j--) {
        if (temp == 0) {
            break;
        }
        if (board[i][j] == temp) {
            if (i == 2) {
                std::cout << "diag2 win";
                return true;
            }
            continue;
        }
    }

    return false;
}

bool checkIfValid(int board[3][3], int row, int col) {
    if (row > 2 || row < 0 || col > 2 || col < 0) {
        return false;
    }

    if (board[row][col] == 1 || board[row][col] == 2) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    int board[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }

    
    bool player = true;
    //Game loop
    while (!winnerFound(board)) {

        print_board(board);

        if (player) {
            std::cout << "X's turn\n";
        }
        else {
            std::cout << "O's turn\n";
        }
        
        std::string row;
        std::string col;
        
        std::cin >> row >> col;
        
        while(!checkIfValid(board, std::stoi(row), std::stoi(col))) {
            std::cout << "Invalid position\n";
            std::cin >> row >> col;
        }
        
        std::cout << "\n";

        if (player) {
            board[std::stoi(row)][std::stoi(col)] = 1;
        }
        else {
            board[std::stoi(row)][std::stoi(col)] = 2;
        }
        
        player = !player;
    }

    print_board(board);

    if (!player) {
        std::cout << "X wins!\n";
    }
    else {
        std::cout << "O wins!\n";
    }

    return 0;
}

