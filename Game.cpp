#include <iostream>
#include <string.h>
using namespace std;

class Game {
    public:
        int choose_difficulty();
        int** create_game(int);
        int** generate(int**, int);
        int determine_size(int);
        void display_board(int**, int);
        string get_user_input();

    private:
        int difficulty;
};

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

int** Game::generate(int** board, int difficulty){

    int size = determine_size(difficulty);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }
    return board;
}

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

void Game::display_board(int** board, int difficulty){
    int size = determine_size(difficulty);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
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