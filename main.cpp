//////////////////////////////////////////////////////////////////////////////////////////// HEADER FILES
//////////////////////////////////////////////////////////////////////////////////////////
#include "Game.cpp"


//////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////////////////////////////////////
void welcome();


//////////////////////////////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////////////////////////////
int main(){

    // print a welcome message to the user
    welcome();

    // create objects
    Game game;
    // Board board;

    // choose difficulty
    int difficulty = game.choose_difficulty();

    // create new game
    int** board = game.create_game(difficulty);

    // generate a random 2d field
    board = game.generate(board, difficulty);

    // while loop which runs the game
    game.display_board(board, difficulty);


    // lost or win


    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION DEFINITIONS
//////////////////////////////////////////////////////////////////////////////////////////
/*
 * function name: welcome
 * description: Prints a welcoming message to the user
 */
void welcome(){
    cout << "Welcome to Minesweeper! Please select a difficulty:" << endl;
    cout << "\t(1) Easy\n\t(2) Medium\n\t(3) Hard" << endl;
}







