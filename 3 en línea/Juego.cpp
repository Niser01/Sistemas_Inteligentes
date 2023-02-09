#include <iostream>
using namespace std;

void print_board(char tablero[3][3]){   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<tablero[i][j];
        }
        cout<<"\n";
    }
}


void empty(char tablero[3][3]){

}




int main(){


    char tablero[3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
    print_board(tablero);




    return 0;
}