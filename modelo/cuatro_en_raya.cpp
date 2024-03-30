#include <iostream> // lbreria para imprimir 
#include <ctime> // libreria para el contador
#include "video_juego.cpp"//importar la clase padre

using namespace std;

class CuatroEnLinea {
private:
// Matriz para crear el tablero de juego 
    char tablero[8][9] = {
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', '1', '2', '3', '4', '5', '6', '7', ' '}
    };
    clock_t tiempoTotalJugado; // variable tiempo total jugado
    int totalwins = win_x; // variable correspondiente a partidas ganadas por el jugador
    double tiempojuego; // variable contador total de juego (en segundos)
    int win_x, win_o; // contador victorias 
    char turno; // variable para identificar si juega el jugador (x) o (O)
    int colT, colD; // Variables para identificar la posicion en la que se coloca la ficha 
    int indD; // Variable para registrar la fila donde se coloca la ficha del jugador 
    int cont = 0; // Variable para contar el número de fichas del mismo jugador en una línea
    int indice_f, indice_c; // Vaibles para representar los indices de las filas y las columnas
    bool listo = false; // Variable para controlar bucles xd
    
    // ----------------------------------------------- setters

    void setTotalins (int partidas) {
        
        totalwins = partidas;
    }
    void setTiempojuego (clock_t tiempo){
        tiempojuego = tiempo;
    }
    
    // ------------------------------------------------- getters

    int getTotalwins () const
    {
        return totalwins;
    }
    clock_t getTiempojuego() const
    {
        return tiempojuego;
    }

   // funcion para limpiar la terminal (para comodidad basicamente)
    void limpiarPantalla() {
        if (system("cls") == -1) {
            cout << "Error al limpiar la pantalla." << endl; // mensaje por si el proceso falla
            limpiarPantalla();
        }
    }
    
	// funcion para limpiar el tablero (para poder jugar denuevo)
    void limpiarTablero() {
        for (int i = 0; i < 6; i++) {
            for (int j = 1; j < 8; j++) {
                tablero[i][j] = ' ';
            }
        }
    }
    // funcion para imprimir la matriz
    void mostrarTablero() {
        cout << " --- CUATRO EN RAYA---" <<endl;
        for (int i = 0; i < 8; i++) {
            cout << endl << "\t";
            for (int j = 0; j < 9; j++) {
                cout << tablero[i][j] << " ";
            }
        }
    }
    //Funcion para posicionar una pieza
	void ubicarFicha() {
        for (int i = 0; i < 6; i++) {
            if (tablero[i][colD] == ' ') {
                if (i > 0) {
                    tablero[i - 1][colD] = ' ';
                }
                tablero[i][colD] = turno;
                indD = i;
            }
        }
    }
    //Funcion para revisar posicion de las fichas y condiccion de victoria (eje horizontal) 
    bool revisarHorizontal(int i, int j, char t) {
        cont = 1;
        indice_f = j;
        listo = false;
        // Izquierda
        while (!listo) {
            indice_f--;
            if (indice_f > 0) {
                if (tablero[i][indice_f] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
        indice_f = j;
        listo = false;
        // Derecha
        while (!listo) {
            indice_f++;
            if (indice_f < 8) {
                if (tablero[i][indice_f] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
		// Verifica si hay 4 fichas consecutivas del mismo jugador en la línea horizontal
        if (cont >= 4) {
            cout << "\n\tGano el jugador " << t << endl;
			(t == 'X') ? win_x++ : win_o++; // Incrementar contador de victorias
            return true;
        }
        return false;
    }
    //Funcion para revisar posicion de las fichas y condiccion de victoria (eje vertical)
    bool revisarVertical(int i, int j, char t) {
        cont = 1;
        indice_f = i;
        listo = false;
        while (!listo) {
            indice_f++;
            if (indice_f < 6) {
                if (tablero[indice_f][j] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
		// Verifica si hay 4 fichas consecutivas del mismo jugador en la línea horizontal
        if (cont >= 4) {
            cout << "\n\tGano el jugador " << t << endl;
			(t == 'X') ? win_x++ : win_o++; // Incrementar contador de victorias
            return true;
        }
        return false;
    }
    //Funcion para revisar posicion de las fichas y condiccion de victoria (eje diagonal)
    bool revisarDiagonal(int i, int j, char t) {
        cont = 1;
        indice_f = i;
        indice_c = j;
        listo = false;
        // Izquierda
        while (!listo) {
            indice_f++;
            indice_c--;
            if ( indice_f< 6 && indice_c > 0) {
                if (tablero[indice_f][indice_c] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
        indice_f = i;
        indice_c = j;
        listo = false;
        // Derecha
        while (!listo) {
            indice_f--;
            indice_c++;
            if (indice_f > 0 && indice_c < 8) {
                if (tablero[indice_f][indice_c] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
		// Verifica si hay 4 fichas consecutivas del mismo jugador en la línea horizontal
        if (cont >= 4) {
            cout << "\n\tGano el jugador " << t << endl;
			(t == 'X') ? win_x++ : win_o++; // Incrementar contador de victorias
            return true;
        }
        return false;
    }
	//Funcion para revisar posicion de las fichas y condiccion de victoria (eje diagonal)
    bool revisarDiagonalInvertida(int i, int j, char t) {
        cont = 1;
        indice_f = i;
        indice_c = j;
        listo = false;
        // Derecha
        while (!listo) {
            indice_f++;
            indice_c++;
            if (indice_f < 6 && indice_c < 8) {
                if (tablero[indice_f][indice_c] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
        indice_f = i;
        indice_c = j;
        listo = false;
        // Izquierda
        while (!listo) {
            indice_f--;
            indice_c--;
            if (indice_f >= 0 && indice_c >= 0) {
                if (tablero[indice_f][indice_c] == t) {
                    cont++;
                } else {
                    listo = true;
                }
            } else {
                listo = true;
            }
        }
		// Verifica si hay 4 fichas consecutivas del mismo jugador en la línea horizontal
        if (cont >= 4) {
            cout << "\n\tGano el jugador " << t << endl;
			(t == 'X') ? win_x++ : win_o++; // Incrementar contador de victorias
            return true;
        }
        return false;
    }
public:
    // Mensaje para los jugadores de inicio 
    CuatroEnLinea() {
        turno = 'X'; // Comienza el jugador 'X'
    }
	// funcion para ejecutar el juego 
    void jugarPartida() {
        clock_t inicioPartida = clock();
        tiempoTotalJugado = 0; // para reiniciar el contador de la partida 
        limpiarPantalla();
        mostrarTablero();
        
        if (revisarHorizontal(indD, colD, turno) || revisarVertical(indD, colD, turno) ||
            revisarDiagonal(indD, colD, turno) || revisarDiagonalInvertida(indD, colD, turno)) {
            clock_t finPartida = clock();
            double tiempoPartida = static_cast<double>(finPartida - inicioPartida) / CLOCKS_PER_SEC;
            tiempojuego += finPartida - inicioPartida; // toma el tiempo de la partida y lo suma a su total
            tiempoTotalJugado += finPartida - inicioPartida; // toma el tiempo de la partida
            mostrarResultados();
            cout << "\n\tQuiere jugar otra vez si(1)/no(0): "; //inicio para ciclo de volver a jugar
            int eleccion;
            cin >> eleccion;
            if(eleccion == 1){
                reiniciarJuego();
			}else{ 
				return;
			}
        }
        turno = (turno == 'X') ? 'O' : 'X'; // Cambia el turno del jugador
        cout << "\n\tTurno de " << turno << endl;
        cout << "\tElija una columna: ";
        cin >> colT;
		// Condicional para verificar que la posicion sea valida
        if (colT > 7 || colT < 1) {
            cout << "\n\tColumna Inexistente." << endl;
            cout << "\tIngrese algun caracter para continuar: ";
            char eleccion;
            cin >> eleccion;
            jugarPartida();
        } else {
            colD = colT;
            ubicarFicha();
        }
        jugarPartida();
    }
    // Funcion para reiniciar el juego 
	void reiniciarJuego() {
    limpiarTablero(); 
    cont = 0; 
	jugarPartida();
   }
   // Funcion para mostar resultado
   void mostrarResultados() {
        cout << "\n\tTiempo de partida jugado: " << tiempoTotalJugado << " segundos" << endl;
        cout << "\n\t Tiempo jugado: "<< tiempojuego << "segundos" << endl;
        cout << "\n\tVictorias de X: " << win_x << endl;
        cout << "\tVictorias de O: " << win_o << endl;
    }
};   

