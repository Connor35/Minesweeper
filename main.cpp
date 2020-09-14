//////////////////////////////////////////////////////////////////////////////////////////// HEADER FILES
//////////////////////////////////////////////////////////////////////////////////////////
#include "Game.cpp"
#include "Turn.cpp"


//////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
//////////////////////////////////////////////////////////////////////////////////////////
void welcome();
string color_display_on();
bool valid_int(string);


//////////////////////////////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////////////////////////////
int main(){

    // clear the screen
    system("./clear_screen.bs");

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
        system("./clear_screen.bs");

        // display the user board
        // uncomment the following line to see the hidden board
        // game.display_board(board, size, color_on);
        game.display_user_board(user_board, board, size, color_on);

        // get user input for their next move
        cout << "Enter mode (f/c/q): ";
        string mode = turn.get_user_input();
        if (mode == "q") {
            game_running = false;
            break;
        }
        if (mode != "f" and mode != "c"){
            cout << "Invalid mode... " << endl;
            sleep(1);
            continue;
        }

        // these coordinates are flipped so that the board works visually for user
        // get X and Y coordinates
        string x_str = "";
        string y_str = "";
        while (!(valid_int(y_str))){
            cout << "Enter X coordinate: ";
            y_str = turn.get_user_input();
        }
        int y = stoi(y_str);

        while (!(valid_int(x_str))){
            cout << "Enter Y coordinate: ";
            x_str = turn.get_user_input();
        }
        int x = stoi(x_str);

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
            cout << endl << endl << "\tYou lost!" << endl;
            game_running = false;
            break;
        }

    }

    // calculate score and display it
    int score = game.calculate_score(user_board, board, size);
    int num_mines = game.determine_num_mines(difficulty);
    cout << endl << endl << "You scored: " << score << "/" << num_mines << endl;

    // check if user won the game
    if (score == num_mines){
        cout << endl << "You won!!!" << endl;
    }

    // lost or win, display the hidden board
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
    cout << "Welcome to Minesweeper! " << endl << endl;
    cout << "Controls:" << endl;
    cout << "\tf = Flag, \tc = Click, \tq = Quit and calculate score" << endl << endl;
    cout << "Please select a difficulty:" << endl;
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

    string user_input = "";
    while (user_input != "1" and user_input != "0"){
        cout << ">> ";
        cin >> user_input;
    }
    cout << endl;
    return user_input;
}

bool valid_int(string str){
    if (str == "0" or str == "1" or str == "2" or str == "3" or str == "4" or str == "5" or str == "6" or str == "7" or str == "8" or str == "9" or str == "10" or str == "11" or str == "12" or str == "13" or str == "14" or str == "15" or str == "16" or str == "17" or str == "18" or str == "19" or str == "20" or str == "21" or str == "22" or str == "23" or str == "24") {
        return true;
    }
    return false;
}

