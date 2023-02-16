#include <iostream>
using namespace std;


/*Clase Agente-------------------------------------------------------*/
class Agente{
    private:
        char tablero[9];
    public:
        Agente(char[9]);
        int jugada();
};

Agente::Agente(char _tablero[9]){
    tablero[9] = _tablero[9];
}

int Agente::jugada(){


    return 0;
}

/*----------------------------------------------------------------------*/



/*Clase Entorno--------------------------------------------------------*/

class Entorno{
    private:
        char tablero[9];
        char ficha_human;
        char ficha_mquina;
        int turno;
    public:
        Entorno(char[9],char,char,int);
        void inicializar_entorno();
        void ganador();
        void print_board();
        char juego_maquina();
};

Entorno::Entorno(char _tablero[9],char _ficha_human,char _ficha_mquina,int _turno){
    tablero[9]=_tablero[9];
    ficha_human=_ficha_human;
    ficha_mquina=_ficha_mquina;
    turno=_turno;
}

void Entorno::inicializar_entorno(){

}

void Entorno::ganador(){

}

void Entorno::print_board(){

}

/*----------------------------------------------------------------------*/

int main(){



    return 0;
}