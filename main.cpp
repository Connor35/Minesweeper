//////////////////////////////////////////////////////////////////////////////////////////// HEADER FILES
//////////////////////////////////////////////////////////////////////////////////////////
#include "Game.cpp"


//////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////////////////////////////////////
void welcome();
string color_display_on();


//////////////////////////////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////////////////////////////
int main(){

    // initialize the random seed
    srand (time(0));

    // create objects
    Game game;

    // set up color preferences
    string color_on = color_display_on();

    // print a welcome message to the user
    welcome();

    // choose difficulty
    int difficulty = game.choose_difficulty();

    // create new game
    int** board = game.create_game(difficulty);

    // create the user's board that they see
    char** user_board = game.create_user_board(difficulty);

    // generate a random 2d field
    board = game.generate(board, difficulty);

    // while loop which runs the game
    int game_running = true;
    while (game_running){
        game.display_board(user_board, difficulty, color_on);
        game_running = false;
    }

    // clear the terminal to get a fresh view after each user input

    // lost or win
    game.display_board(board, difficulty, color_on);


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

/*
 * function name: color_display_on
 * description: asks the user if they want color on or off
 *              gets the user's input
 */
string color_display_on(){
    cout << endl;
    cout << "If your terminal does not support ANSI escape sequences, " << endl;
    cout << "please enter 0. Otherwise, enter 1 to see color " << endl;
    cout << "(most terminals support ANSI escape sequences): " << endl;

    cout << ">> ";
    string user_input;
    cin >> user_input;
    cout << endl;
    return user_input;
}








