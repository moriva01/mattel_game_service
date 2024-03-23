// clase main donde se ejecutara finalmente el aplicativo
#include "../controlador/operaciones.cpp"

int main()
{
    ahorcado bcs;
    bcs.setNombre("Ahorcado");
    bcs.setCantJugadores(1);
    bcs.setCategoria("Puzzle");
    bcs.setDesarrollador("N/a");
    bcs.setAnioLanzamiento(1978);
    bcs.setPlataforma("Steam");
    bcs.setPartidasGanadas(0);
    bcs.setTiempoJugado(0);
    string nombreJugador;
    int eleccion;

    while (true)
    {
        cout << "------------------------------- Mattel Game Service --------------------------------------" << endl;
        cout << " -- Bienvenido al sistema de juegos y clasificacion de mattel, que deseas hacer hoy ? ----" << endl;
        cout << "-- 1- Jugar Ahorcado                                      --------------------------------" << endl;
        cout << "-- 2- Salir                                               --------------------------------" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;

        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            int eleccion2;
            while (true)
            {
                int partidas = bcs.getPartidasGanadas();
                clock_t tiempo = bcs.getTiempoJugado();
                string aux;
                cout << "Top Ganador: " << bcs.getNombreJugador() << endl;
                cout << "Partidas ganadas: " << partidas << endl;
                cout << "Tiempo total jugado: " << static_cast<double>(tiempo) / CLOCKS_PER_SEC << " segundos" << endl;
                cout << "-------------------------------------------------------" << endl;
                cout << "1- Jugar al ahorcado" << endl;
                cout << "2- Salir" << endl;
                cin >> eleccion2;

                switch (eleccion2)
                {
                case 1:
                {
                    cout << "Ingrese su nombre: ";
                    cin >> nombreJugador;
                    bcs.setNombreJugador(nombreJugador);
                    bcs.jugar_ahorcado(partidas, tiempo);
                    bcs.setPartidasGanadas(partidas);
                    bcs.setTiempoJugado(tiempo);
                    break;
                }
                case 2:
                    break; // Sal del bucle del juego sin salir del bucle principal
                default:
                    break;
                }
                if (eleccion2 == 2) // Si el jugador eligió salir desde el juego
                    break;
            }

            break;
        case 2:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}