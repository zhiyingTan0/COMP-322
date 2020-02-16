

#include <iostream>
#include "functions.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    char board[27];
    //char try0[]={'X',' ',' ',' ',' ',' ',' ',' ',' ',
                //' ','X',' ',' ',' ',' ',' ',' ',' ',
                //' ',' ','X',' ',' ',' ',' ',' ',' '};
    //bool legal;
    int cellNbre;
    
    
    greetAndInstruct();
    displayBoard(board);
    // legal = checkIfLegal(cellNbre, board[27]);
    //if valid, then make a movemoment and update the char board[]
    // also call displayBoard() to show the board
    //legal= checkWinner(try0);
     while(true){
        cin >> cellNbre;
        cellNbre=cellNbre-1;
         if(checkIfLegal​(cellNbre, board)==true){
            Move('X', cellNbre, board);
            displayBoard(board);
            checkWinner(board);
            computerMove(board);
            checkWinner(board);
            }
    }

    return 0;
}

