#include "video_juego.cpp"//importar la clase padre
#include <vector>// poder crear listas dinamicas
#include <ctime> // para el tiempo de juego

class ahorcado : public video_juego//herencia de la clase
{
private:
    string nombre_jugador;//atributos de la clase
    clock_t tiempo_jugado;
    int partidas_ganadas;

public:
    ahorcado() {}//constructor de la clase

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

    void imprimir_palabra(const string &palabra, const vector<bool> &letrasAdivinadas)//toma la palabra de juego y vector de booleanos de letras adivinadas
    {
        for (size_t i = 0; i < palabra.length(); ++i)//recorre toda la palabra
        {
            if (letrasAdivinadas[i])//si letras adivinadas verdad
            {
                cout << palabra[i] << " ";//muestra solo las letras adivinadas
            }
            else
            {
                cout << "_ ";//no la muestra
            }
        }
        cout << endl;
    }

    void jugar_ahorcado(int &partidasGanadas, clock_t &tiempoTotalJugado)//partidas y tiempo para poder actualizar
    {

        vector<string> palabras = {"perro", "gato", "pollo", "tigre", "cocodrilo"};//palabras del jeugo

        while (true)
        {

            srand(static_cast<unsigned int>(time(0)));//genera los indices aleatorios
            int indiceAleatorio = rand() % palabras.size();//los pasa aqui para que tenga en cuenta las palabras
            string palabraSeleccionada = palabras[indiceAleatorio];//toma una palabra aleatoria de la lista

            vector<bool> letrasAdivinadas(palabraSeleccionada.length(), false);//crea el vector de letras adivinadas (funcion anterior)

            int intentosRestantes = 7;//deja un maximo de 7 intentos de adivinar
            bool ganado = false;

            cout << "¡Bienvenido al juego del ahorcado!" << endl;

            clock_t inicioPartida = clock();//inicia a contar el tiempo de la partida

            while (intentosRestantes > 0 && !ganado)
            {
                cout << "Palabra a adivinar: ";
                imprimir_palabra(palabraSeleccionada, letrasAdivinadas);

                
                char letra;//solicita letra al usuario
                cout << "Ingresa una letra: ";
                cin >> letra;

                
                bool encontrada = false;//mira si la letra esta en la palabra
                for (size_t i = 0; i < palabraSeleccionada.length(); ++i)
                {
                    if (palabraSeleccionada[i] == letra)//recorre la palabra y busca la letra
                    {
                        letrasAdivinadas[i] = true;//la pasa a true y lo devuelve al vector
                        encontrada = true;
                    }
                }

                if (!encontrada)
                {
                    cout << "Incorrecto. Te quedan " << --intentosRestantes << " intentos." << endl;// si no es correcta la letra
                }
                else
                {
                    cout << "¡Correcto!" << endl;//si lo es
                }

                
                ganado = true;// si se gana la aprtida
                for (bool letraAdivinada : letrasAdivinadas)
                {
                    if (!letraAdivinada)
                    {
                        ganado = false;//solo si no logra adivinar en los intentos permitidos
                        break;
                    }
                }
            }

         
            if (ganado)
            {
                clock_t finPartida = clock(); //hora de inicio de la partidad                                                            
                double tiempoPartida = static_cast<double>(finPartida - inicioPartida) / CLOCKS_PER_SEC; //tiempo total de la partida
                tiempoTotalJugado += finPartida - inicioPartida;  //acumula tiempo total del juego                                       
                cout << "¡Felicidades! Has ganado. La palabra era: " << palabraSeleccionada << endl;
                cout << "Tiempo de partida: " << tiempoPartida << " segundos" << endl;
                ++partidasGanadas; //cuenta las partidas
            }
            else
            {
                cout << "¡Has perdido! La palabra era: " << palabraSeleccionada << endl;
            }

           
            char respuesta;
            cout << "¿Deseas jugar de nuevo? (s/n): ";// si quiere volver a jugar
            cin >> respuesta;
            if (respuesta != 's' && respuesta != 'S')
            {
                break;
            }
        }
    }
};