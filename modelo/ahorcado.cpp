#include "video_juego.cpp"
#include <vector>
#include <ctime> // para el tiempo de juego

class ahorcado : public video_juego
{
private:
    string nombre_jugador;
    clock_t tiempo_jugado;
    int partidas_ganadas;

public:
    ahorcado() {}

    // ----------------------------------------------- setters
    void setNombreJugador(const string &nombre)
    {
        nombre_jugador = nombre;
    }

    void setTiempoJugado(clock_t tiempo)
    {
        tiempo_jugado = tiempo;
    }

    void setPartidasGanadas(int partidas)
    {
        partidas_ganadas = partidas;
    }

    // ------------------------------------------------- getters
    string getNombreJugador() const
    {
        return nombre_jugador;
    }

    clock_t getTiempoJugado() const
    {
        return tiempo_jugado;
    }

    int getPartidasGanadas() const
    {
        return partidas_ganadas;
    }

    // ---------------------------------------------- juego

    void imprimir_palabra(const string &palabra, const vector<bool> &letrasAdivinadas)
    {
        for (size_t i = 0; i < palabra.length(); ++i)
        {
            if (letrasAdivinadas[i])
            {
                cout << palabra[i] << " ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }

    void jugar_ahorcado(int &partidasGanadas, clock_t &tiempoTotalJugado)
    {

        vector<string> palabras = {"perro", "gato", "pollo", "tigre", "cocodrilo"};

        while (true)
        {

            srand(static_cast<unsigned int>(time(0)));
            int indiceAleatorio = rand() % palabras.size();
            string palabraSeleccionada = palabras[indiceAleatorio];

            vector<bool> letrasAdivinadas(palabraSeleccionada.length(), false);

            int intentosRestantes = 7;
            bool ganado = false;

            cout << "¡Bienvenido al juego del ahorcado!" << endl;

            clock_t inicioPartida = clock();

            while (intentosRestantes > 0 && !ganado)
            {
                cout << "Palabra a adivinar: ";
                imprimir_palabra(palabraSeleccionada, letrasAdivinadas);

                // Solicitar al usuario una letra
                char letra;
                cout << "Ingresa una letra: ";
                cin >> letra;

                // Verificar si la letra está en la palabra seleccionada
                bool encontrada = false;
                for (size_t i = 0; i < palabraSeleccionada.length(); ++i)
                {
                    if (palabraSeleccionada[i] == letra)
                    {
                        letrasAdivinadas[i] = true;
                        encontrada = true;
                    }
                }

                if (!encontrada)
                {
                    cout << "Incorrecto. Te quedan " << --intentosRestantes << " intentos." << endl;
                }
                else
                {
                    cout << "¡Correcto!" << endl;
                }

                // Verificar si se ha ganado el juego
                ganado = true;
                for (bool letraAdivinada : letrasAdivinadas)
                {
                    if (!letraAdivinada)
                    {
                        ganado = false;
                        break;
                    }
                }
            }

            // Mostrar resultado final
            if (ganado)
            {
                clock_t finPartida = clock();                                                            // Hora de fin de la partida
                double tiempoPartida = static_cast<double>(finPartida - inicioPartida) / CLOCKS_PER_SEC; // Tiempo de partida en segundos
                tiempoTotalJugado += finPartida - inicioPartida;                                         // Acumular tiempo total jugado
                cout << "¡Felicidades! Has ganado. La palabra era: " << palabraSeleccionada << endl;
                cout << "Tiempo de partida: " << tiempoPartida << " segundos" << endl;
                ++partidasGanadas; // Incrementar contador de partidas ganadas
            }
            else
            {
                cout << "¡Has perdido! La palabra era: " << palabraSeleccionada << endl;
            }

            // Preguntar al usuario si desea jugar de nuevo
            char respuesta;
            cout << "¿Deseas jugar de nuevo? (s/n): ";
            cin >> respuesta;
            if (respuesta != 's' && respuesta != 'S')
            {
                break;
            }
        }
    }
};