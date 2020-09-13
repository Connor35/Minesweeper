#include <iostream>
#include <string.h>
using namespace std;

class Game {
    public:
        int choose_difficulty();
        int** create_game(int);
        char** create_user_board(int);
        int** generate(int**, int, int);
        int determine_size(int);
        int determine_num_mines(int);
        bool check_if_used(int**, int, int);
        void display_board(int**, int, string);
        void display_user_board(char**, int**, int, string);
        string get_user_input();
        void fill_in_board(int**, int);
        int count_surr_mines(int**, int, int, int);
        bool valid_cell(int, int, int);
        int calculate_score(char**, int**, int);

        ~Game();

    private:
        int difficulty;
};

Game::~Game(){

}

/*
 * function name: choose_difficulty
 * description: allows the user to choose a difficulty, calls get_user_input()
 */
int Game::choose_difficulty(){
    string user_input = "";
    while (user_input != "1" and user_input != "2"  and user_input != "3"){
        user_input = get_user_input();
    }
    int difficulty = stoi(user_input);
    return difficulty;
}

/*
 * function name: create_game
 * description: based on difficulty, creates an easy, medium, or hard game
 */
int** Game::create_game(int size){
    int** board = new int*[size];
    for(int i = 0; i < size; i++)
        board[i] = new int[size];

    return board;
}

/*
 * function name: create_user_board
 * description: based on difficulty, creates an easy, medium, or hard board for the user to interact with
 */
char** Game::create_user_board(int size){
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
int** Game::generate(int** board, int difficulty, int size){
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
        }
        else{
            // add the mine
            board[x_index][y_index] = 9;
        }
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
void Game::display_board(int** board, int size, string color_on){
    cout << endl << endl << "Y/X \t";
    for (int i = 0; i < size; i++){
        if (i < 10) cout << "  " << i << "  ";
        else cout << "  " << i << " ";
    }
    for (int i = 0; i < size; i++){
        cout << endl << endl << i << '\t';
        for (int j = 0; j < size; j++){
            if (board[i][j] == 9){
                // mine
                if (color_on == "1")
                    cout << "[ " << "\033[1;31mM\033[0m" << " ]";
                else
                    cout << "[ M ]";
            }
            else if (board[i][j] == 0 or board[i][j] == -1){
                // empty
                if (color_on == "1")
                    cout << "[ " << "\033[1;37m*\033[0m" << " ]";
                else
                    cout << "[ * ]";
            }
            else {
                // number (1-8)
                if (color_on == "1"){
                    if (board[i][j] == 1) cout << "[ \033[1;34m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 2) cout << "[ \033[1;32m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 3) cout << "[ \033[1;31m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 4) cout << "[ \033[1;35m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 5) cout << "[ \033[4;34m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 6) cout << "[ \033[4;32m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 7) cout << "[ \033[4;31m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 8) cout << "[ \033[4;35m" << board[i][j] << "\033[0m ]";
                }
                else {
                    cout << "[ " << board[i][j] << " ]";
                }
            }
        }
    }
    cout << endl << endl;
}

/*
 * function name: display_user_board
 * description: shows the users board
 */
void Game::display_user_board(char** user_board, int** board, int size, string color_on){
    cout << endl << endl << "Y/X \t";
    for (int i = 0; i < size; i++){
        if (i < 10) cout << "  " << i << "  ";
        else cout << "  " << i << " ";
    }
    for (int i = 0; i < size; i++){
        cout << endl << endl << i << '\t';
        for (int j = 0; j < size; j++){
            if (user_board[i][j] == 'F'){
                // Flag
                if (color_on == "1")
                    cout << "[ " << "\033[1;31mF\033[0m" << " ]";
                else
                    cout << "[ F ]";
            }
            else if (user_board[i][j] == '*'){
                // empty
                if (color_on == "1")
                    cout << "[ " << "\033[1;37m*\033[0m" << " ]";
                else
                    cout << "[ * ]";
            }
            else if (user_board[i][j] == ' '){
                // not yet clicked cell
                cout << "[ " << user_board[i][j] << " ]";
            }
            else {
                // revealed number
                if (color_on == "1"){
                    if (board[i][j] == 1) cout << "[ \033[1;34m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 2) cout << "[ \033[1;32m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 3) cout << "[ \033[1;31m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 4) cout << "[ \033[1;35m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 5) cout << "[ \033[4;34m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 6) cout << "[ \033[4;32m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 7) cout << "[ \033[4;31m" << board[i][j] << "\033[0m ]";
                    if (board[i][j] == 8) cout << "[ \033[4;35m" << board[i][j] << "\033[0m ]";
                }
                else {
                    cout << "[ " << user_board[i][j] << " ]";
                }
            }
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
    return user_input;
}

/*
 * function name: fill_in_board
 * description: calculates the number for each cell. each cell number represents the number of surrounding mines.
 */
void Game::fill_in_board(int** board, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int number = count_surr_mines(board, i, j, size);
            board[i][j] = number;
        }
    }
    return;
}

/*
 * function name: count_surr_mines
 * description: counts the surrounding cells and returns number of mines
 */
int Game::count_surr_mines(int** board, int x, int y, int size){
    int number = 0;

    if (board[x][y] == 9){
        return 9;
    }
    else {
        // Up left
        if (valid_cell(x-1, y-1, size)){
            if (board[x-1][y-1] == 9){
                number++;
            }
        }

        // Up
        if (valid_cell(x, y-1, size)){
            if (board[x][y-1] == 9){
                number++;
            }
        }

        // Up right
        if (valid_cell(x+1, y-1, size)){
            if (board[x+1][y-1] == 9){
                number++;
            }
        }

        // Left
        if (valid_cell(x-1, y, size)){
            if (board[x-1][y] == 9){
                number++;
            }
        }

        // Right
        if (valid_cell(x+1, y, size)){
            if (board[x+1][y] == 9){
                number++;
            }
        }

        // Down Left
        if (valid_cell(x-1, y+1, size)){
            if (board[x-1][y+1] == 9){
                number++;
            }
        }

        // Down
        if (valid_cell(x, y+1, size)){
            if (board[x][y+1] == 9){
                number++;
            }
        }

        // Down right
        if (valid_cell(x+1, y+1, size)){
            if (board[x+1][y+1] == 9){
                number++;
            }
        }
    }
    return number;
}

/*
 * function name: valid_cell
 * description: checks if the coordinates are within the board boundaries
 */
bool Game::valid_cell(int x, int y, int size){
    if (x >= 0 and x <= (size-1) and y >= 0 and y <= (size-1)){
        return true;
    }
    return false;
}

/*
 * function name: calculate_score
 * description: runs through the user board and compares flags with mines on hidden board
 */
 int Game::calculate_score(char** user_board, int** board, int size){
     int score = 0;
     for (int i = 0; i < size; i++){
         for (int j = 0; j < size; j++){
             if (user_board[i][j] == 'F' and board[i][j] == 9){
                 score++;
             }
         }
     }
     return score;
 }

