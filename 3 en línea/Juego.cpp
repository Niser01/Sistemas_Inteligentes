#include <iostream>
#include <list>
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


list<int> empty(char tablero[3][3]){
    list<int> posiciones;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j]=='*')
            {
                posiciones.push_back(i);
                posiciones.push_back(j);
            }
            
        }
    }

/*

    list<int> posiciones=empty(tablero);
    list<int>::iterator it_pos=posiciones.begin();
    while (it_pos!=posiciones.end())
    {
        cout<<*it_pos++<<endl;
    }
*/

    return posiciones;
}




int main(){

    char tablero[3][3]={{'*','*','*'},{'*','*','*'},{'*','*','*'}};
    print_board(tablero);

    
    


    return 0;
}