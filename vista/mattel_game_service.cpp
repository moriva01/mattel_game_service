// clase main donde se ejecutara finalmente el aplicativo
#include "../controlador/operaciones.cpp" //importar la clase de controlador y todos los metodos

int main() // clase main del sistema
{
    ahorcado bcs; // crear objeto del juego jugable (ahorcado)
    bcs.setNombre("Ahorcado");
    bcs.setCantJugadores(1);
    bcs.setCategoria("Puzzle");
    bcs.setDesarrollador("N/a");
    bcs.setAnioLanzamiento(1978);
    bcs.setPlataforma("Steam");
    bcs.setPartidasGanadas(0);
    bcs.setTiempoJugado(0);

    //------------------------------------- agregar algunos juegos a la lista de juegos

    video_juego juego1("minecraft", 4, "aventura", "Mojang", 2011, "Steam"); // crear objeto del juego
    lista_juegos.push_back(juego1);                                          // agregarlo a la lista
    video_juego juego2("pacman", 1, "arcade", "NA", 1980, "Gforece one");
    lista_juegos.push_back(juego2);
    video_juego juego3("tetris", 1, "puzzle", "NA", 1984, "Ubisoft");
    lista_juegos.push_back(juego3);
    video_juego juego4("leage of legends", 3, "estrategia", "Riot", 2009, "Ea play");
    lista_juegos.push_back(juego4);
    video_juego juego5("fornite", 2, "disparos", "Eoic", 2017, "Epic games");
    lista_juegos.push_back(juego5);

    // -----------------------------------------------------------------------------

    int eleccion;

    while (true) // menu principal del aplicativo
    {
        cout << "------------------------------- Mattel Game Service --------------------------------------" << endl;
        cout << " -- Bienvenido al sistema de juegos y clasificacion de mattel, que deseas hacer hoy ? ----" << endl;
        cout << "-- 1- Lista de juegos                                      -------------------------------" << endl;
        cout << "-- 2- Jugar ahorcado                                               -----------------------" << endl;
        cout << "-- 3- categorias de juegos                                         -----------------------" << endl;
        cout << "-- 4- plataformas de juegos                                        -----------------------" << endl;
        cout << "-- 5- Salir                                                        -----------------------" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;

        cin >> eleccion;
        switch (eleccion)
        {
        case 1:

            mostrar_juegos(); // mostar la lista de juegos
            break;
        case 2:

            jugar_ahorcado(bcs); // juego del ahorcado
            break;
        case 3:
            cambiar_categoria();// cambiar categoria del juego
            break;

        case 4:
            plataforma();//organizar la lista y mostrarla por plataforma
            break;

        case 5:
            return 0; // salir del sistema
            break;
        default: // si la opcion no es valida
            cout << "opcion no valida" << endl;
            break;
        }
    }

    return 0;
}