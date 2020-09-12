#include <iostream>
#include <string.h>
using namespace std;

class Turn {
    public:
        string get_user_input();
        

    private:


};

Turn::~Turn(){

}

/*
 * function name: get_user_input
 * description: gets the users input
 */
string Turn::get_user_input(){
    cout << ">> ";
    string user_input;
    cin >> user_input;
    cout << endl;
    return user_input;
}