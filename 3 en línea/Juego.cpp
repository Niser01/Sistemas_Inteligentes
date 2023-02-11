#include <iostream>
#include <list>
#include<stdlib.h>
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

char juego_maquina(char tablero[9],char letra_jugador){
    char letra_maquina;
    if (letra_jugador == 'X' || letra_jugador =='x')
    {
        letra_maquina='O';
        
    }else{
        letra_maquina='X';
    }
    return letra_maquina;
}

char *jugadas_victoria(char tablero[9], int contador_jugadas, char letra_jugador){
    srand(time(NULL));
    char letra = juego_maquina(tablero,letra_jugador);
    int victoria[9][3]={{0, 1, 2},{3, 4, 5},{6, 7, 8},{0, 3, 6},{1, 4, 7},{2, 5, 8},{0, 4, 8},{2, 4, 6}};
    int pos_juego;

    if(contador_jugadas<1){
        while (true)
        {
            pos_juego = 1+rand()%9;
            if (tablero[pos_juego-1]==' ')
            {
                tablero= tablero_juego(tablero,letra,pos_juego);
                cout<<"Primer ciclo aleatorio"<<endl;
                return tablero;
            }

        }
        

    }else{
        if(tablero[0] == letra_jugador){
            if(tablero[1]==letra_jugador){
                if (tablero[2]==' ')
                {
                    tablero= tablero_juego(tablero,letra,3);
                    cout<<3.1<<endl;
                    return tablero;
                }
            }else{
                if (tablero[2]==letra_jugador){
                    if (tablero[1]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,2);
                        cout<<2.1<<endl;
                        return tablero;
                    }                                    
                }
            }             
            if(tablero[3]==letra_jugador){
                if (tablero[6]==' ')
                {
                    tablero= tablero_juego(tablero,letra,7);
                    cout<<7.1<<endl;
                    return tablero;
                }
            }else{
                if (tablero[6]==letra_jugador){
                    if (tablero[3]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,4);
                        cout<<4.1<<endl;
                        return tablero;
                    }                    
                }
            }

            if(tablero[4]==letra_jugador){
                if (tablero[8]==' ')
                {
                    tablero= tablero_juego(tablero,letra,9);
                    cout<<9.1<<endl;
                    return tablero;
                } 

            }else{
                if (tablero[8]==letra_jugador){
                    if (tablero[4]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<5.1<<endl;
                        return tablero;
                    }                     
                }
            }
            
        }else if(tablero[1] == letra_jugador){
            if(tablero[2]==letra_jugador){
                if (tablero[0]==' ')
                {
                    tablero= tablero_juego(tablero,letra,1);
                    cout<<1.1<<endl;
                    return tablero;
                }                 

            }
             
            if(tablero[4]==letra_jugador){
                    if (tablero[7]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,8);
                        cout<<8.1<<endl;
                        return tablero;
                    }             
            }else{
                if (tablero[7]==letra_jugador){
                    if (tablero[4]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<5.2<<endl;
                        return tablero;
                    } 
                }
            }

        }else if(tablero[2] == letra_jugador){
            if(tablero[5]==letra_jugador){
                if (tablero[8]==' ')
                {
                    tablero= tablero_juego(tablero,letra,9);
                    cout<<9.2<<endl;
                    return tablero;
                } 
            }else{
                if (tablero[8]==letra_jugador){
                    if (tablero[5]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,6);
                        cout<<6.1<<endl;
                        return tablero;
                    }                     
                }
            }
             
            if(tablero[4]==letra_jugador){
                if (tablero[6]==' ')
                {
                    tablero= tablero_juego(tablero,letra,7);
                    cout<<7.2<<endl;
                    return tablero;
                }                 
            }else{
                if (tablero[6]==letra_jugador){
                    if (tablero[4]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<5.3<<endl;
                        return tablero;
                    }                     
                }
            }
        }else if(tablero[3] == letra_jugador){
            if(tablero[6]==letra_jugador){
                if (tablero[0]==' ')
                {
                    tablero= tablero_juego(tablero,letra,1);
                    cout<<1.2<<endl;
                    return tablero;
                }                
            }
             
            if(tablero[4]==letra_jugador){
                if (tablero[5]==' ')
                {
                    tablero= tablero_juego(tablero,letra,6);
                    cout<<6.2<<endl;
                    return tablero;
                }
            }else{
                if (tablero[5]==letra_jugador){
                    if (tablero[4]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<5.4<<endl;
                        return tablero;
                    }
                }
            }
        }else if(tablero[4] == letra_jugador){
            if(tablero[5]==letra_jugador){
                if (tablero[3]==' ')
                {
                    tablero= tablero_juego(tablero,letra,4);
                    cout<<4.2<<endl;
                    return tablero;
                }
            }          
            
        }else if(tablero[5] == letra_jugador){
            if(tablero[8]==letra_jugador){
                if (tablero[2]==' ')
                {
                    tablero= tablero_juego(tablero,letra,3);
                    cout<<3.2<<endl;
                    return tablero;
                }
            }          
            
        }else if(tablero[6] == letra_jugador){
            if(tablero[7]==letra_jugador){
                if (tablero[8]==' ')
                {
                    tablero= tablero_juego(tablero,letra,9);
                    cout<<9.3<<endl;
                    return tablero;
                }                

            }else{
                if (tablero[8]==letra_jugador){
                    if (tablero[7]==' ')
                    {
                        tablero= tablero_juego(tablero,letra,8);
                        cout<<8.2<<endl;
                        return tablero;
                    }
                }
            }
            if(tablero[4]==letra_jugador){
                if (tablero[2]==' ')
                {
                    tablero= tablero_juego(tablero,letra,3);
                    cout<<3.3<<endl;
                    return tablero;
                }
            }
             
            
        }else if(tablero[8] == letra_jugador){
            if(tablero[7]==letra_jugador){
                if (tablero[6]==' ')
                {
                    tablero= tablero_juego(tablero,letra,7);
                    cout<<7.3<<endl;
                    return tablero;
                }

            }
            if(tablero[4]==letra_jugador){
                if (tablero[0]==' ')
                {
                    tablero= tablero_juego(tablero,letra,1);
                    cout<<1.3<<endl;
                    return tablero;
                }
            }
             
            
        }


    }
    while (true)
    {
        pos_juego = 1+rand()%9;
        if (tablero[pos_juego-1]==' ')
        {
            tablero= tablero_juego(tablero,letra,pos_juego);
            cout<<"segundo ciclo aleatorio"<<endl;
            return tablero;
        }

    }    
}


char *jugadas_victoria_2(char tablero[9], int contador_jugadas, char letra_jugador){

}


int main(){
    char letra_jugador = incializacion();
    char tablero_blanco[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int contador_jugadas=0;
    print_first_board();

    while(contador_jugadas<9){
        int pos_oponente = pos_juego();
        char *tablero = tablero_juego(tablero_blanco,letra_jugador,pos_oponente);
        print_board(tablero);
        cout<<"--------------"<<endl;
        cout<<"Jugada máquina: "<<endl;
        tablero = jugadas_victoria(tablero,contador_jugadas,letra_jugador);        
        print_board(tablero);
        contador_jugadas=contador_jugadas+1;
    }




    return 0;
}