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

char *jugadas_victoria_2(char tablero[9], int contador_jugadas, char letra_jugador){
    int rand_juego = 0;
    srand(time(NULL));
    char letra = juego_maquina(tablero,letra_jugador);
    for (int i = 1; i < 10; i++)
    {
        if(tablero[i-1]==letra_jugador)
        {
            switch (i)
            {
                case 1:                    
                    if(tablero[1]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[3]==letra_jugador){
                        rand_juego=2;
                    }else if(tablero[4]==letra_jugador){
                        rand_juego=3;
                    }else if(tablero[2]==letra_jugador){
                        rand_juego=4;
                    }else if(tablero[6]==letra_jugador){
                        rand_juego=6;
                    }else if(tablero[8]==letra_jugador){
                        rand_juego=5;
                    }else{
                        rand_juego=1+rand()%(6-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[2]==' '){
                        tablero= tablero_juego(tablero,letra,3);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[6]==' '){
                        tablero= tablero_juego(tablero,letra,7);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break;
                    case 3:
                        if (tablero[8]==' '){
                        tablero= tablero_juego(tablero,letra,9);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break; 
                    
                    case 4:
                        if (tablero[1]==' '){
                        tablero= tablero_juego(tablero,letra,2);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break;
                    case 5:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break;
                    case 6:
                        if (tablero[3]==' '){
                        tablero= tablero_juego(tablero,letra,4);
                        cout<<"caso: "<<1<<endl;
                        return tablero;
                        }
                        break; 
                    default:
                        break;
                    }
                
                case 2:                    
                    if(tablero[4]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[7]==letra_jugador){
                        rand_juego=2;
                    }else{
                        rand_juego=1+rand()%(2-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[7]==' '){
                        tablero= tablero_juego(tablero,letra,8);
                        cout<<"caso: "<<2<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<2<<endl;
                        return tablero;
                        }
                        break;                    
                    default:
                        break;
                    }

                
                case 3:
                    if(tablero[1]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[4]==letra_jugador){
                        rand_juego=2;
                    }else if(tablero[5]==letra_jugador){
                        rand_juego=3;
                    }else if(tablero[0]==letra_jugador){
                        rand_juego=4;
                    }else if(tablero[6]==letra_jugador){
                        rand_juego=5;
                    }else if(tablero[8]==letra_jugador){
                        rand_juego=6;
                    }else{
                        rand_juego=1+rand()%(6-1);
                    }

                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[0]==' '){
                        tablero= tablero_juego(tablero,letra,1);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[6]==' '){
                        tablero= tablero_juego(tablero,letra,7);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break;
                    case 3:
                        if (tablero[8]==' '){
                        tablero= tablero_juego(tablero,letra,9);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break; 
                    case 4:
                        if (tablero[1]==' '){
                        tablero= tablero_juego(tablero,letra,2);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break;
                    case 5:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break;
                    case 6:
                        if (tablero[5]==' '){
                        tablero= tablero_juego(tablero,letra,6);
                        cout<<"caso: "<<3<<endl;
                        return tablero;
                        }
                        break;                    
                    default:
                        break;
                    }


                case 4:                    
                    if(tablero[4]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[5]==letra_jugador){
                        rand_juego=2;
                    }else{
                        rand_juego=1+rand()%(2-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[5]==' '){
                        tablero= tablero_juego(tablero,letra,6);
                        cout<<"caso: "<<4<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<4<<endl;
                        return tablero;
                        }
                        break;                    
                    default:
                        break;
                    }                    
                
                case 5:
                    if(tablero[0]==letra_jugador){
                        rand_juego=4;
                    }else if(tablero[2]==letra_jugador){
                        rand_juego=3;
                    }else if(tablero[6]==letra_jugador){
                        rand_juego=2;
                    }else if(tablero[8]==letra_jugador){
                        rand_juego=1;
                    }else{
                        rand_juego=1+rand()%(4-1);
                    }

                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[0]==' '){
                        tablero= tablero_juego(tablero,letra,1);
                        cout<<"caso: "<<5<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[2]==' '){
                        tablero= tablero_juego(tablero,letra,3);
                        cout<<"caso: "<<5<<endl;
                        return tablero;
                        }
                        break;                    
                    case 3:
                        if (tablero[6]==' '){
                        tablero= tablero_juego(tablero,letra,7);
                        cout<<"caso: "<<5<<endl;
                        return tablero;
                        }
                        break;
                    case 4:
                        if (tablero[8]==' '){
                        tablero= tablero_juego(tablero,letra,9);
                        cout<<"caso: "<<5<<endl;
                        return tablero;
                        }
                        break; 
                    
                    default:
                        break;
                    }

                case 6:                    
                    if(tablero[4]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[3]==letra_jugador){
                        rand_juego=2;
                    }else{
                        rand_juego=1+rand()%(2-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[3]==' '){
                        tablero= tablero_juego(tablero,letra,4);
                        cout<<"caso: "<<6<<endl;                        
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<6<<endl;
                        return tablero;
                        }
                        break;                    
                    default:
                        break;
                    }   
                
                case 7:
                    if(tablero[3]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[4]==letra_jugador){
                        rand_juego=2;
                    }else if(tablero[7]==letra_jugador){
                        rand_juego=3;
                    }else if(tablero[0]==letra_jugador){
                        rand_juego=4;
                    }else if(tablero[2]==letra_jugador){
                        rand_juego=5;
                    }else if(tablero[8]==letra_jugador){
                        rand_juego=6;
                    }else{
                        rand_juego=1+rand()%(3-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[0]==' '){
                        tablero= tablero_juego(tablero,letra,1);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[2]==' '){
                        tablero= tablero_juego(tablero,letra,3);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break;
                    case 3:
                        if (tablero[8]==' '){
                        tablero= tablero_juego(tablero,letra,9);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break; 
                    case 4:
                        if (tablero[3]==' '){
                        tablero= tablero_juego(tablero,letra,4);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break;
                    case 5:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break;
                    case 6:
                        if (tablero[7]==' '){
                        tablero= tablero_juego(tablero,letra,8);
                        cout<<"caso: "<<7<<endl;
                        return tablero;
                        }
                        break;                     
                    default:
                        break; 
                    }

                case 8:                    
                    if(tablero[4]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[1]==letra_jugador){
                        rand_juego=2;
                    }else{
                        rand_juego=1+rand()%(2-1);
                    }
                    
                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[1]==' '){
                        tablero= tablero_juego(tablero,letra,2);
                        cout<<"caso: "<<8<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<8<<endl;
                        return tablero;
                        }
                        break;                    
                    default:
                        break;
                    }  

                case 9:
                    if(tablero[4]==letra_jugador){
                        rand_juego=1;
                    }else if(tablero[5]==letra_jugador){
                        rand_juego=2;
                    }else if(tablero[7]==letra_jugador){
                        rand_juego=3;
                    }else if(tablero[0]==letra_jugador){
                        rand_juego=4;
                    }else if(tablero[6]==letra_jugador){
                        rand_juego=5;
                    }else if(tablero[2]==letra_jugador){
                        rand_juego=6;
                    }else{
                        rand_juego=1+rand()%(6-1);
                    }                

                    switch (rand_juego)
                    {
                    case 1:
                        if (tablero[0]==' '){
                        tablero= tablero_juego(tablero,letra,1);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break;
                    case 2:
                        if (tablero[2]==' '){
                        tablero= tablero_juego(tablero,letra,3);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break;
                    case 3:
                        if (tablero[6]==' '){
                        tablero= tablero_juego(tablero,letra,7);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break; 

                    case 4:
                        if (tablero[4]==' '){
                        tablero= tablero_juego(tablero,letra,5);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break;
                    case 5:
                        if (tablero[7]==' '){
                        tablero= tablero_juego(tablero,letra,8);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break;
                    case 6:
                        if (tablero[5]==' '){
                        tablero= tablero_juego(tablero,letra,6);
                        cout<<"caso: "<<9<<endl;
                        return tablero;
                        }
                        break; 

                    default:
                        break; 
                    }

            default:
               
                break;
            }
        }
    }
    
    while (true)
    {
        rand_juego = 1+rand()%(9-1);
        if (tablero[rand_juego-1]==' ')
        {
            tablero= tablero_juego(tablero,letra,rand_juego);
            return tablero;
        }
    }    
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
        tablero = jugadas_victoria_2(tablero,contador_jugadas,letra_jugador);        
        print_board(tablero);
        contador_jugadas=contador_jugadas+1;
    }




    return 0;
}