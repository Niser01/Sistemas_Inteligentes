#include <iostream>
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
            cout<<"El número ingresado no es válido, intentelo de nuevo."<<endl;
        }
    } 
}

char *tablero_juego(char tablero[9],char letra_jugador,int pos_oponente){
    if (tablero[pos_oponente-1]==' '){
        tablero[pos_oponente-1]=letra_jugador;
        
    }else{
        cout<< tablero[pos_oponente-1]<<endl;
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

int victoria_maqu(char tablero[9], char letra_jugador, int i){
    char letra_maq = juego_maquina(tablero,letra_jugador);
    switch (i)
    {
    case 0:
        if (tablero[0]==letra_maq && tablero[1]==letra_maq && tablero[2]==' '){
            return 3;                       
        }else if(tablero[1]==letra_maq && tablero[2]==letra_maq && tablero[0]==' '){
            return 1;
        }else if(tablero[0]==letra_maq && tablero[2]==letra_maq && tablero[1]==' '){
            return 2;
        }
        break;    
    case 1:
        if (tablero[3]==letra_maq && tablero[4]==letra_maq && tablero[5]==' '){
            return 6;                       
        }else if(tablero[4]==letra_maq && tablero[5]==letra_maq && tablero[3]==' '){
            return 4;
        }else if(tablero[3]==letra_maq && tablero[5]==letra_maq && tablero[4]==' '){
            return 5;
        }
        break;   
    case 2:
        if (tablero[6]==letra_maq && tablero[7]==letra_maq && tablero[8]==' '){
            return 9;                       
        }else if(tablero[7]==letra_maq && tablero[8]==letra_maq && tablero[6]==' '){
            return 7;
        }else if(tablero[6]==letra_maq && tablero[8]==letra_maq && tablero[7]==' '){
            return 8;
        }
        break;   
    case 3:
        if (tablero[0]==letra_maq && tablero[3]==letra_maq && tablero[6]==' '){
            return 7;                       
        }else if(tablero[3]==letra_maq && tablero[6]==letra_maq && tablero[0]==' '){
            return 1;
        }else if(tablero[0]==letra_maq && tablero[6]==letra_maq && tablero[3]==' '){
            return 4;
        }
        break;   
    case 4:
        if (tablero[1]==letra_maq && tablero[4]==letra_maq && tablero[7]==' '){
            return 8;                       
        }else if(tablero[4]==letra_maq && tablero[7]==letra_maq && tablero[1]==' '){
            return 2;
        }else if(tablero[1]==letra_maq && tablero[7]==letra_maq && tablero[4]==' '){
            return 5;
        }
        break;   
    case 5:
        if (tablero[2]==letra_maq && tablero[5]==letra_maq && tablero[8]==' '){
            return 9;                       
        }else if(tablero[5]==letra_maq && tablero[8]==letra_maq && tablero[2]==' '){
            return 3;
        }else if(tablero[2]==letra_maq && tablero[8]==letra_maq && tablero[5]==' '){
            return 6;
        }
        break;   
    case 6:
        if (tablero[0]==letra_maq && tablero[4]==letra_maq && tablero[8]==' '){
            return 9;                       
        }else if(tablero[4]==letra_maq && tablero[8]==letra_maq && tablero[0]==' '){
            return 1;
        }else if(tablero[0]==letra_maq && tablero[8]==letra_maq && tablero[4]==' '){
            return 5;
        }
        break;   
    case 7:
        if (tablero[6]==letra_maq && tablero[4]==letra_maq && tablero[2]==' '){
            return 3;                       
        }else if(tablero[4]==letra_maq && tablero[2]==letra_maq && tablero[6]==' '){
            return 7;
        }else if(tablero[6]==letra_maq && tablero[2]==letra_maq && tablero[4]==' '){
            return 5;
        }
        break; 
    
    default:
        break;
    }
    return 800;
}

char *jugadas_victoria_2(char tablero[9], int contador_jugadas, char letra_jugador){
    int rand_juego = 0;
    srand(time(NULL));
    char letra = juego_maquina(tablero,letra_jugador);
    int num_vic1=200,num_vic2=200,num_vic3=200;
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
            case 0: 
                num_vic1=victoria_maqu(tablero,letra_jugador,0);
                num_vic2=victoria_maqu(tablero,letra_jugador,3);
                num_vic3=victoria_maqu(tablero,letra_jugador,6);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }else if(num_vic3<10){
                    tablero= tablero_juego(tablero,letra,num_vic3);
                    return tablero;
                }
                
                if (tablero[0]==letra_jugador && tablero[1]==letra_jugador&&tablero[2]==' '){
                tablero= tablero_juego(tablero,letra,3);
                return tablero;
                }

                if (tablero[0]==letra_jugador && tablero[3]==letra_jugador&&tablero[6]==' '){
                tablero= tablero_juego(tablero,letra,7);
                return tablero;
                }

                if (tablero[0]==letra_jugador && tablero[4]==letra_jugador&&tablero[8]==' '){
                tablero= tablero_juego(tablero,letra,9);
                return tablero;
                }

                if (tablero[0]==letra_jugador && tablero[2]==letra_jugador&&tablero[1]==' '){
                tablero= tablero_juego(tablero,letra,2);
                return tablero;
                }

                if (tablero[0]==letra_jugador && tablero[6]==letra_jugador&&tablero[3]==' '){
                tablero= tablero_juego(tablero,letra,4);
                return tablero;
                }

                if (tablero[0]==letra_jugador && tablero[8]==letra_jugador&&tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }

            case 1:     

                num_vic1=victoria_maqu(tablero,letra_jugador,0);
                num_vic2=victoria_maqu(tablero,letra_jugador,4);
                
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }                              
                
                if (tablero[1]==letra_jugador && tablero[4]==letra_jugador && tablero[7]==' '){
                tablero= tablero_juego(tablero,letra,8);
                return tablero;
                }

                if (tablero[1]==letra_jugador && tablero[7]==letra_jugador && tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }
            
            case 2:
                num_vic1=victoria_maqu(tablero,letra_jugador,0);
                num_vic2=victoria_maqu(tablero,letra_jugador,5);
                num_vic3=victoria_maqu(tablero,letra_jugador,7);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }else if(num_vic3<10){
                    tablero= tablero_juego(tablero,letra,num_vic3);
                    return tablero;
                }                

                if (tablero[2]==letra_jugador && tablero[1]==letra_jugador&&tablero[0]==' '){
                tablero= tablero_juego(tablero,letra,1);
                return tablero;
                }

                if (tablero[2]==letra_jugador && tablero[4]==letra_jugador&&tablero[6]==' '){
                tablero= tablero_juego(tablero,letra,7);
                return tablero;
                }

                if (tablero[2]==letra_jugador && tablero[5]==letra_jugador&&tablero[8]==' '){
                tablero= tablero_juego(tablero,letra,9);
                return tablero;
                }

                if (tablero[2]==letra_jugador && tablero[0]==letra_jugador&&tablero[1]==' '){
                tablero= tablero_juego(tablero,letra,2);
                return tablero;
                }

                if (tablero[2]==letra_jugador && tablero[6]==letra_jugador&&tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }

                if (tablero[2]==letra_jugador && tablero[8]==letra_jugador&&tablero[5]==' '){
                tablero= tablero_juego(tablero,letra,6);
                return tablero;
                }

            case 3:   
                num_vic1=victoria_maqu(tablero,letra_jugador,0);
                num_vic2=victoria_maqu(tablero,letra_jugador,1);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }                                 

                if (tablero[3]==letra_jugador && tablero[4]==letra_jugador && tablero[5]==' '){
                tablero= tablero_juego(tablero,letra,6);
                return tablero;
                }

                if (tablero[3]==letra_jugador && tablero[5]==letra_jugador && tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }
                  
            case 4:
                num_vic1=victoria_maqu(tablero,letra_jugador,6);
                num_vic2=victoria_maqu(tablero,letra_jugador,7);                    
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }           

                if (tablero[4]==letra_jugador && tablero[8]==letra_jugador &&tablero[0]==' '){
                tablero= tablero_juego(tablero,letra,1);
                return tablero;
                }

                if (tablero[4]==letra_jugador && tablero[6]==letra_jugador &&tablero[2]==' '){
                tablero= tablero_juego(tablero,letra,3);
                return tablero;
                }

                if (tablero[4]==letra_jugador && tablero[2]==letra_jugador &&tablero[6]==' '){
                tablero= tablero_juego(tablero,letra,7);
                return tablero;
                }

                if (tablero[4]==letra_jugador && tablero[0]==letra_jugador &&tablero[8]==' '){
                tablero= tablero_juego(tablero,letra,9);
                return tablero;
                }

            case 5:    
                num_vic1=victoria_maqu(tablero,letra_jugador,5);
                num_vic2=victoria_maqu(tablero,letra_jugador,2);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }                              

                if (tablero[5]==letra_jugador && tablero[4]==letra_jugador &&tablero[3]==' '){
                tablero= tablero_juego(tablero,letra,4);                       
                return tablero;
                }

                if (tablero[5]==letra_jugador && tablero[3]==letra_jugador &&tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }
 
            case 6:
                num_vic1=victoria_maqu(tablero,letra_jugador,0);
                num_vic2=victoria_maqu(tablero,letra_jugador,2);
                num_vic3=victoria_maqu(tablero,letra_jugador,7);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }else if(num_vic3<10){
                    tablero= tablero_juego(tablero,letra,num_vic3);
                    return tablero;
                }
                
                if (tablero[6]==letra_jugador && tablero[3]==letra_jugador&&tablero[0]==' '){
                tablero= tablero_juego(tablero,letra,1);
                return tablero;
                }

                if (tablero[6]==letra_jugador && tablero[4]==letra_jugador&&tablero[2]==' '){
                tablero= tablero_juego(tablero,letra,3);
                return tablero;
                }

                if (tablero[6]==letra_jugador && tablero[7]==letra_jugador&&tablero[8]==' '){
                tablero= tablero_juego(tablero,letra,9);
                return tablero;
                }

                if (tablero[6]==letra_jugador && tablero[0]==letra_jugador&&tablero[3]==' '){
                tablero= tablero_juego(tablero,letra,4);
                return tablero;
                }

                if (tablero[6]==letra_jugador && tablero[2]==letra_jugador&&tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }

                if (tablero[6]==letra_jugador && tablero[8]==letra_jugador&&tablero[7]==' '){
                tablero= tablero_juego(tablero,letra,8);
                return tablero;
                }

            case 7: 
                num_vic1=victoria_maqu(tablero,letra_jugador,2);
                num_vic2=victoria_maqu(tablero,letra_jugador,4);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }                            

                if (tablero[7]==letra_jugador && tablero[4]==letra_jugador && tablero[1]==' '){
                tablero= tablero_juego(tablero,letra,2);
                return tablero;
                }

                if (tablero[7]==letra_jugador && tablero[1]==letra_jugador &&tablero[4]==' '){
                tablero= tablero_juego(tablero,letra,5);
                return tablero;
                }

            case 8:
                num_vic1=victoria_maqu(tablero,letra_jugador,2);
                num_vic2=victoria_maqu(tablero,letra_jugador,5);
                num_vic3=victoria_maqu(tablero,letra_jugador,6);
                if(num_vic1<10){
                    tablero= tablero_juego(tablero,letra,num_vic1);
                    return tablero;
                }else if(num_vic2<10){
                    tablero= tablero_juego(tablero,letra,num_vic2);
                    return tablero;
                }else if(num_vic3<10){
                    tablero= tablero_juego(tablero,letra,num_vic3);
                    return tablero;
                }                

                    if (tablero[8]==letra_jugador && tablero[4]==letra_jugador&&tablero[0]==' '){
                    tablero= tablero_juego(tablero,letra,1);
                    return tablero;
                    }

                    if (tablero[8]==letra_jugador && tablero[5]==letra_jugador&&tablero[2]==' '){
                    tablero= tablero_juego(tablero,letra,3);
                    return tablero;
                    }

                    if (tablero[8]==letra_jugador && tablero[7]==letra_jugador&&tablero[6]==' '){
                    tablero= tablero_juego(tablero,letra,7);
                    return tablero;
                    }

                    if (tablero[8]==letra_jugador && tablero[0]==letra_jugador&&tablero[4]==' '){
                    tablero= tablero_juego(tablero,letra,5);
                    return tablero;
                    }

                    if (tablero[8]==letra_jugador && tablero[6]==letra_jugador&&tablero[7]==' '){
                    tablero= tablero_juego(tablero,letra,8);
                    return tablero;
                    }

                    if (tablero[8]==letra_jugador && tablero[2]==letra_jugador&&tablero[5]==' '){
                    tablero= tablero_juego(tablero,letra,6);
                    return tablero;
                    }

        default:            
            break;
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

int victoria(char tablero[9], char letra_jugador){
    char letra_maq = juego_maquina(tablero,letra_jugador);
    for (int i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
            if (tablero[0]==letra_jugador && tablero[1]==letra_jugador && tablero[2]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[0]==letra_maq && tablero[1]==letra_maq && tablero[2]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 1:
            if (tablero[3]==letra_jugador && tablero[4]==letra_jugador && tablero[5]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[3]==letra_maq && tablero[4]==letra_maq && tablero[5]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 2:
            if (tablero[6]==letra_jugador && tablero[7]==letra_jugador && tablero[8]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[6]==letra_maq && tablero[7]==letra_maq && tablero[8]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 3:
            if (tablero[0]==letra_jugador && tablero[3]==letra_jugador && tablero[6]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[0]==letra_maq && tablero[3]==letra_maq && tablero[6]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 4:
            if (tablero[1]==letra_jugador && tablero[4]==letra_jugador && tablero[7]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[1]==letra_maq && tablero[4]==letra_maq && tablero[7]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 5:
            if (tablero[2]==letra_jugador && tablero[5]==letra_jugador && tablero[8]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[2]==letra_maq && tablero[5]==letra_maq && tablero[8]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 6:
            if (tablero[0]==letra_jugador && tablero[4]==letra_jugador && tablero[8]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[0]==letra_maq && tablero[4]==letra_maq && tablero[8]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        case 7:
            if (tablero[2]==letra_jugador && tablero[4]==letra_jugador && tablero[6]==letra_jugador){
                cout<<"El ganador es el jugador. "<< letra_jugador<<endl;
                return 20;                       
            }else if (tablero[2]==letra_maq && tablero[4]==letra_maq && tablero[6]==letra_maq){
                cout<<"Gana la maquina. "<< letra_maq<<endl;
                return 20;                       
            }
            break;
        
        default:
            break;
        }
        
    }
    return 0;
}


int juego_o(char tablero_blanco[9]){
        char letra_jugador = 'o';
        int contador_jugadas=0;
        for (int j = 0; j < 9; j++)
        {
            if (tablero_blanco[j]==' ')
            {
                contador_jugadas++;
            }        
        }
        
        int rev_victoria = 0;
        int pos_oponente = pos_juego();
        char *tablero = tablero_juego(tablero_blanco,letra_jugador,pos_oponente);
        print_board(tablero);
        rev_victoria = victoria(tablero, letra_jugador);
        if(rev_victoria==20){
            return 1;
        }
        if(contador_jugadas==9){
            cout<<"Se ha llegado a un empate. "<<endl;
            return 0;
        }  
        cout<<"--------------"<<endl;
        cout<<"Jugada máquina: "<<endl;
        tablero = jugadas_victoria_2(tablero,contador_jugadas,letra_jugador);        
        print_board(tablero);
        rev_victoria = victoria(tablero, letra_jugador);
        if(rev_victoria==20){
            return 1;
        }
        return -1;
}

int juego_x(char tablero_blanco[9]){
        char letra_jugador='x';
        int contador_jugadas=0;
        for (int j = 0; j < 9; j++)
        {
            if (tablero_blanco[j]==' ')
            {
                contador_jugadas++;
            }        
        }
        
        int rev_victoria = 0;
        int pos_oponente = pos_juego();
        char *tablero = tablero_juego(tablero_blanco,letra_jugador,pos_oponente);
        print_board(tablero);
        rev_victoria = victoria(tablero, letra_jugador);
        if(rev_victoria==20){
            return 1;
        }
        if(contador_jugadas==9){
            cout<<"Se ha llegado a un empate. "<<endl;
            return 0;
        }  
        cout<<"--------------"<<endl;
        cout<<"Jugada máquina: "<<endl;
        tablero = jugadas_victoria_2(tablero,contador_jugadas,letra_jugador);        
        print_board(tablero);
        rev_victoria = victoria(tablero, letra_jugador);
        if(rev_victoria==20){
            return 1;
        }
        return -1;
}

int main(){
    char letra_jugador = incializacion();
    char tablero_blanco[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int cont_juego =-1;
    print_first_board();


    if (letra_jugador == 'X' || letra_jugador =='x')
    {
        while(true){
            cont_juego = juego_x(tablero_blanco);
            if(cont_juego==1){
                break;
            }else if(cont_juego==0){
                break;
            }
        }
    }else{
        while(true){
            cont_juego = juego_o(tablero_blanco);
            if(cont_juego==1){
                break;
            }else if(cont_juego==0){
                break;
            }
        }        
    }
    

    

    return 0;
}