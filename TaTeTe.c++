#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "conio.h"
#include <windows.h>
#include <ctime>
#include <sstream>

using namespace std;

char tabla[9] ;


void clearTerminal()
{
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << endl;
        cout << endl;
}
bool comprobarSiHayUnGanador()
{

    if (tabla[0] == tabla[1] && tabla[1] == tabla[2])
    {
        return 1;
    }
    else if (tabla[3] == tabla[4] && tabla[4] == tabla[5])
    {
        return 1;
    }
    else if (tabla[6] == tabla[7] && tabla[7] == tabla[8])
    {
        return 1;
    }
    else if (tabla[0] == tabla[3] && tabla[3] == tabla[6])
    {
        return 1;
    }
    else if (tabla[1] == tabla[4] && tabla[4] == tabla[7])
    {
        return 1;
    }
    else if (tabla[2] == tabla[5] && tabla[5] == tabla[8])
    {
        return 1;
    }
    else if (tabla[0] == tabla[4] && tabla[4] == tabla[8])
    {
        return 1;
    }
    else if (tabla[2] == tabla[4] && tabla[4] == tabla[6])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tableroDeJuego (char player, int num)
{
    clearTerminal();
    while ((tabla[num-1] == 'X' || tabla [num-1] == '0' ) || (num < 1 || num >9))
    {
        cout << "DATO INGRESADO INVALIDO \nIngrese un nuevo numero"<< endl;
        cin >> num;
        clearTerminal();
    }
    
    if (player ==0)
    {
        tabla [num-1] = 'X';
    }else{
        tabla[num - 1] = '0';
    }
    
    for (int i = 0; i < 9; i++)
    {
        if ((i + 1) % 3 == 0)
        {
            cout << " | " << tabla[i] << " | "<< endl;
        }
        else
        {
            cout << " | " << tabla[i] ;
        }
    }
    cout << endl;
}
void gameMode1 ()
{
    // turno =0 --> turno del jugador 1      turno =1 --> turno del jugador 2
    char n_player1;
    char n_player2;
    int num=0;
    stringstream nn;
    int turno = 0;
    int lugaresdisponibles =9;
    cout << "Ingrese el nombre del nombre jugador 1" << endl;
    cin >> n_player1;
    cout << "Ingrese el nombre del nombre jugador 2" << endl;
    cin >> n_player2;

    for (int i = 0; i < 9; i++)
    {
        num++;
        nn << num;
        nn >> tabla[i];
        if ((i + 1) % 3 == 0)
        {
            cout << " | " << tabla[i] << " | " << endl;
        }
        else
        {
            cout << " | " << tabla[i];
        }
    }
    while (lugaresdisponibles > 0)
    {
        cout << n_player1<<" coloca tu posicion" << endl;
        cin >> num;
        tableroDeJuego(turno, num);
        turno++;
        lugaresdisponibles--;
        if (comprobarSiHayUnGanador())
        {
            cout << n_player1 << " gano la partida"<< endl;
            lugaresdisponibles -= 10;
        }else{
            cout << n_player2 << " coloca tu pocicion" << endl;
            cin >> num;
            tableroDeJuego(turno, num);
            turno--;
            lugaresdisponibles--;
            cout << endl;
            if (comprobarSiHayUnGanador())
            {
                cout << n_player2 << " gano la partida" << endl;
                lugaresdisponibles -= 10;
            }
        }
    }
    if (lugaresdisponibles ==0)
    {
        cout << "El juego termino en empate " << endl;
    }
}
void gameMode2 ()
{
    // turno =0 --> turno del jugador 1      turno =1 --> turno del jugador 2
    char n_player1;
    int num = 0;
    int turno = 0;
    int lugaresdisponibles = 9;
    stringstream nn;
    cout << "Ingrese el nombre del nombre jugador 1" << endl;
    cin >> n_player1;

    for (int i = 0; i < 9; i++)
    {
        num++;
        nn << num;
        nn >> tabla[i];
        if ((i + 1) % 3 == 0)
        {
            cout << " | " << tabla[i] << " | "<< endl;
        }
        else
        {
            cout << " | " << tabla[i] ;
        }
    }
    while (lugaresdisponibles > 0)
    {
        

        cout << n_player1 << " coloca tu posicion" << endl;
        cin >> num;
        tableroDeJuego(turno, num);
        turno++;
        lugaresdisponibles--;
        cout << endl;
        if (comprobarSiHayUnGanador())
        {
            cout << n_player1 << " gano la partida" << endl;
            lugaresdisponibles -= 10;
        }
        else
        {
            srand (time(0));
            do{
                num = 1+(rand() % 9);
            }while (tabla[num-1] == 'X' || tabla[num-1] == '0');

            tableroDeJuego(turno, num);
            turno--;
            lugaresdisponibles--;
            cout << endl;
            if (comprobarSiHayUnGanador())
            {
                lugaresdisponibles -= 10;
                cout << "bot gano la partida" << endl;
            }
        }
    }
    if (lugaresdisponibles == 0)
    {
        cout << "El juego termino en empate " << endl;
    }
}
int pantallaPrincipal(int op)
{
    int opcion ;
    cout << "\t TA-TE-TI" <<endl;
    cout << "1.JUGAR" << endl;
    cout << "2.SALIR" << endl;
    cin >> opcion;
    op = opcion;
    return op;
}
int main (){
    int opcion ;
    int modo;

    system("color 0A");
    opcion = pantallaPrincipal (opcion);
    while (opcion  ==1 || opcion ==2)
    {
        if (opcion == 1)
        {
            cout << "Ingrese el modo de juego" << endl;
            cout << "1. p1 vs p2" << endl;
            cout << "2. p1 vs pc" << endl;
            cin >> modo;
            if (modo == 1)
            {
                gameMode1 ();
            }else if (modo ==2)
            {
                gameMode2 ();
            }else
            {
                cout << "Error al colocar el modo " << endl;
                getche ();
                return 0;
            }
        }else if (opcion ==2)
        {
            cout << "Gracias por jugar :D" << endl;
            getche();
            return 0;
        }
        cout << endl;
        cout << "\tQueres seguir jugando?" << endl;
        cout << "\t1. si" << endl;
        cout << "\t2. no" << endl;
        cin >> opcion;
        clearTerminal ();
    }
    cout << "ERROR" <<endl;
    getche ();
    return 0;
}