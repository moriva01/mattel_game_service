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

    int eleccion;

    while (true)
    {
        cout << "------------------------------- Mattel Game Service --------------------------------------" << endl;
        cout << " -- Bienvenido al sistema de juegos y clasificacion de mattel, que deseas hacer hoy ? ----" << endl;
        cout << "-- 1- Lista de juegos                                      -------------------------------" << endl;
        cout << "-- 2- Jugar ahorcado                                               -----------------------" << endl;
        cout << "-- 2- Salir                                                        -----------------------" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;

        cin >> eleccion;

        switch (eleccion)
        {
        case 1:

            break;
        case 2:
            jugar_ahorcado(bcs);
            break;
        case 3:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}