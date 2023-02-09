#include <iostream>
#include <list>
using namespace std;


char incializacion(){
    while (true)
    {
        cout<<"Ingrese el simbolo con el que desea jugar 'X' ó 'O'"<<endl;
        char simbolo;
        cin>>simbolo;
        if (simbolo == 'X'||simbolo == 'O'||simbolo =='x'||simbolo =='o'||simbolo =='0')
        {
            return simbolo;
            
        }else{
            cout<<"El simbolo ingresado no es válido, intentelo de nuevo."<<endl;
        }
    }    
}

void print_board(char tablero[9]){   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<tablero[i];
        }
        cout<<"\n";
    }
}



list<int> empty(char tablero[9]){
    list<int> posiciones;
    for (int i = 0; i < 9; i++)
    {        
            if (tablero[i]=='*')
            {
                posiciones.push_back(i);

            }      
        
    }



    list<int>::iterator it_pos=posiciones.begin();
    while (it_pos!=posiciones.end())
    {
        cout<<*it_pos++<<endl;
    }


    return posiciones;
}

int pos_juego(){
    int pos;
    cout<<"Ingrese la posición donde desea jugar"<<endl;
    cin>>pos;
    return pos;
}


int main(){
    incializacion();
    char tablero[9]={'*','*','*','*','*','*','*','*','*'};
    print_board(tablero);


    return 0;
}