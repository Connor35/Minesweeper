//////////////////////////////////////////////////////////////////////////////////////////// HEADER FILES
//////////////////////////////////////////////////////////////////////////////////////////
#include "Game.cpp"
#include "Turn.cpp"


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
    Turn turn;

    // set up color preferences
    string color_on = color_display_on();

    // print a welcome message to the user
    welcome();

    // choose difficulty
    int difficulty = game.choose_difficulty();

    // determine size based on difficulty
    int size = game.determine_size(difficulty);

    // create new game
    int** board = game.create_game(size);

    // create the user's board that they see
    char** user_board = game.create_user_board(size);

    // generate a random 2d field
    board = game.generate(board, difficulty, size);

    // fill in the numbers for each cell
    game.fill_in_board(board, size);

    // while loop which runs the game
    bool game_running = true;
    int hit_mine = 0;
    while (game_running){
        // clear the terminal to get a fresh view after each user input
        system("./echo.bs");

        // display the user board
        game.display_user_board(user_board, board, size, color_on);

        // get user input for their next move
        cout << "Enter mode (F = Flag, C = Click): ";
        string mode = turn.get_user_input();
        if (mode == "q") {
            game_running = false;
            break;
        }

        // these coordinates are flipped so that the board works visually for user
        cout << "Enter X coordinate: ";
        int y = stoi(turn.get_user_input());
        cout << "Enter Y coordinate: ";
        int x = stoi(turn.get_user_input());

        // execute their move
        if (mode == "f"){
            turn.toggle_flag(user_board, board, size, x, y);
        }
        else if (mode == "c"){
            hit_mine = turn.click_cell(user_board, board, size, x, y);
        }
        else {
            continue;
        }

        if (hit_mine == 1){
            cout << "You lost!" << endl;
            game_running = false;
            break;
        }

    }

    // calculate score and display it

    // lost or win
    game.display_board(board, size, color_on);


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

/*
 * function name: get_all_inputs
 * description: gets all user inputs (mode, x, y)
 */









