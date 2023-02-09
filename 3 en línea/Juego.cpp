#include <iostream>
#include <list>
using namespace std;


char incializacion(){
    char simbolo;
    while (true)
    {
        cout<<"Ingrese el simbolo con el que desea jugar 'X' ó 'O'"<<endl;
        
        cin>>simbolo;
        if (simbolo == 'X'||simbolo == 'O'||simbolo =='x'||simbolo =='o'||simbolo =='0')
        {
            return simbolo;
            
        }else{
            cout<<"El simbolo ingresado no es válido, intentelo de nuevo."<<endl;
        }
    } 
    return simbolo;
}

void print_board(char tablero[9]){  
    int a = 0; 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(j!= 2){
                cout<<tablero[a]<<"|";
            }else{
                cout<<tablero[a];
            }            
            a++;
        }
        if(i!= 2){
            cout<<endl<<"-----"<<endl;
        }else{
            cout<<endl;
        }
    }
}

void print_first_board(){
    cout<<"El orden del tablero es el siguiente: "<<endl;
    char f_tablero[9]={'1','2','3','4','5','6','7','8','9'};
    print_board(f_tablero);
}

list<int> empty(char tablero[9]){
    list<int> posiciones;
    for (int i = 0; i < 9; i++)
    {        
        if (tablero[i]==' ')
        {
            posiciones.push_back(i);
        }              
    }
    return posiciones;
}

int pos_juego(){
    int pos;
     while (true)
    {
        cout<<"Ingrese la posición donde desea jugar del 1 al 9"<<endl;        
        cin>>pos;
        if (pos>0 && pos<10)
        {
            return pos;            
        }else{
            cout<<"El numero ingresado no es válido, intentelo de nuevo."<<endl;
        }
    } 
}

char *tablero_juego(char tablero[9],char letra_jugador,int pos_oponente){
    if (tablero[pos_oponente-1]==' '){
        tablero[pos_oponente-1]=letra_jugador;
    }else{
        cout<< "La posicion ya se encuentra ocupada"<<endl;
    }
    return tablero;
}



int main(){
    char letra_jugador = incializacion();
    char tablero_blanco[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    print_first_board();
    int pos_oponente = pos_juego();
    char *tablero = tablero_juego(tablero_blanco,letra_jugador,pos_oponente);

   


    return 0;
}