#include <iostream>
#include <string.h>
using namespace std;

class Game {
    public:
        int choose_difficulty();
        int** create_game(int);
        char** create_user_board(int);
        int** generate(int**, int);
        int determine_size(int);
        int determine_num_mines(int);
        bool check_if_used(int**, int, int);
        void display_board(int**, int, string);
        void display_board(char**, int, string);
        string get_user_input();

        ~Game();

    private:
        int difficulty;
};

Game::~Game(){
    cout << "Game ended." << endl;
}

/*
 * function name: choose_difficulty
 * description: allows the user to choose a difficulty, calls get_user_input()
 */
int Game::choose_difficulty(){
    int difficulty = 0;
    difficulty = stoi(get_user_input());
    return difficulty;
}

/*
 * function name: create_game
 * description: based on difficulty, creates an easy, medium, or hard game
 */
int** Game::create_game(int difficulty){
    int size;

    switch (difficulty) {
        case 1:
            size = 9;
            break;
        case 2:
            size = 16;
            break;
        case 3:
            size = 25;
            break;
        default: exit(1);
    }

    int** board = new int*[size];
    for(int i = 0; i < size; i++)
        board[i] = new int[size];

    return board;
}

/*
 * function name: create_user_board
 * description: based on difficulty, creates an easy, medium, or hard board for the user to interact with
 */
char** Game::create_user_board(int difficulty){
    int size;

    switch (difficulty) {
        case 1:
            size = 9;
            break;
        case 2:
            size = 16;
            break;
        case 3:
            size = 25;
            break;
        default: exit(1);
    }

    char** user_board = new char*[size];
    for(int i = 0; i < size; i++)
        user_board[i] = new char[size];

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            user_board[i][j] = ' ';
        }
    }

    return user_board;
}

/*
 * function name: generate
 * description: based on difficulty, generates a new board game
 *              easy = 10 mines
 *              medium = 40 mines
 *              hard = 99 mines
 */
int** Game::generate(int** board, int difficulty){

    int size = determine_size(difficulty);
    int num_mines = determine_num_mines(difficulty);


    // initialize the board
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }

    // populate with mines and update counters
    for (int mines_placed = 0; mines_placed < num_mines; mines_placed++){
        // get random x index
        int x_index = rand() % size;

        // get random y index
        int y_index = rand() % size;

        // check if this location already has a mine
        if (check_if_used(board, x_index, y_index)){
            // it does, redo this run
            mines_placed--;
        } else{
            // add the mine
            board[x_index][y_index] = 9;
        }

        // update the surrounding counters

    }
    return board;
}

/*
 * function name: determine_size
 * description: based on difficulty, determines the width (size) of the board
 */
int Game::determine_size(int difficulty){
    switch (difficulty) {
        case 1:
            return 9;
            break;
        case 2:
            return 16;
            break;
        case 3:
            return 25;
            break;
        default: exit(1);
    }
}

/*
 * function name: determine_num_mines
 * description: based on difficulty, determines how many mines to populate the board
 */
int Game::determine_num_mines(int difficulty){
    switch (difficulty) {
        case 1:
            return 10;
            break;
        case 2:
            return 40;
            break;
        case 3:
            return 99;
            break;
        default: exit(1);
    }

}

/*
 * function name: check_if_used
 * description: checks if suggested mine coordinate has already been used
 *              returns true if a mine already exists at that location
 *              returns false if this location is available for a mine
 */
 bool Game::check_if_used(int** board, int x_index, int y_index){
    if (board[x_index][y_index] == 9)
        return true;
    else
        return false;
 }

/*
 * function name: display_board
 * description: shows the unhidden board
 */
void Game::display_board(int** board, int difficulty, string color_on){
    int size = determine_size(difficulty);

    for (int i = 0; i < size; i++){
        // cout << endl << '\t';
        // for (int k = 0; k < size; k++){
        //     cout << " ___ ";
        // }
        cout << endl << endl << '\t';
        for (int j = 0; j < size; j++){
            if (board[i][j] == 9){
                if (color_on == "1")
                    cout << "[ " << "\033[1;31mM\033[0m" << " ]";
                else
                    cout << "[ " << "M" << " ]";
            } else {
                cout << "[ " << board[i][j] << " ]";
            }
        }
    }
    cout << endl << endl;
}

/*
 * function name: display_board
 * description: shows the users board
 */
void Game::display_board(char** board, int difficulty, string color_on){
    int size = determine_size(difficulty);

    for (int i = 0; i < size; i++){
        cout << endl << endl << '\t';
        for (int j = 0; j < size; j++){
            cout << "[ " << board[i][j] << " ]";
        }
    }
    cout << endl << endl;
}

/*
 * function name: get_user_input
 * description: gets the users input
 */
string Game::get_user_input(){
    cout << ">> ";
    string user_input;
    cin >> user_input;
    cout << endl;
    return user_input;
}