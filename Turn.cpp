#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

class Turn {
    public:
        string get_user_input();
        bool valid_cell(int, int, int);
        void toggle_flag(char**, int**, int, int, int);
        int click_cell(char**, int**, int, int, int);

        ~Turn();

    private:


};

Turn::~Turn(){
    cout << "Turn object deleted." << endl;
}

/*
 * function name: get_user_input
 * description: gets the users input
 */
string Turn::get_user_input(){
    cout << ">> ";
    string user_input;
    cin >> user_input;
    return user_input;
}

/*
 * function name: valid_cell
 * description: checks if the coordinates are within the board boundaries
 */
bool Turn::valid_cell(int x, int y, int size){
    if (x >= 0 and x <= (size-1) and y >= 0 and y <= (size-1)){
        return true;
    }
    return false;
}

/*
 * function name: toggle_flag
 * description: toggles a cell to display F for flag
 */
void Turn::toggle_flag(char** user_board, int** board, int size, int x, int y){
    string buffer;
    if (valid_cell(x, y, size)){
        if (user_board[x][y] == 'F'){
            user_board[x][y] = ' ';
        }
        else {
            user_board[x][y] = 'F';
        }
    }
    else {
        cout << "Invalid coordinate... " << endl;
        sleep(1);
    }
}

/*
 * function name: click_cell
 * description: clicks a cell, triggering a possible chain of revelations across the board
 */
int Turn::click_cell(char** user_board, int** board, int size, int x, int y){

    if (valid_cell(x, y, size)){
        if (board[x][y] == 9){
            return 1;
        }
        else if (board[x][y] >= 1 and board[x][y] <= 8){
            char a = '0' + board[x][y];
            user_board[x][y] = a;
        }
        else {
            // begin recursion

        }
    }
    else {
        cout << "Invalid coordinate... " << endl;
        sleep(1);
    }
    return 0;
}