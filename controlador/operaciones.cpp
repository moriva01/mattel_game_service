//aqui se haran los metodos que unen la clase main con las clases del modelo

#include <iostream>
#include <vector>
#include <algorithm>
usign namespace std;

void lista_juegos_favoritos() {
    vector<video_juego> Juegos_favoritos;
    string nombre;
    char option;
    int option2;

    cout << "Digite el nombre del video juego: " << endl;
    cin >> nombre;

    for (video_juego p : lista_juegos) {
        if (nombre == p.getNombre()) {
            // Agregar el juego a la lista de favoritos
            Juegos_favoritos.push_back(p);
            cout << "El juego ha sido agregado a la lista de favoritos." << endl;
            cout << "/------Menú-----/" << endl;
            cout << "1. Agregar otro juego a lista de favoritos " << endl;
            cout << "2. Salir. "<< endl;
            cin >> option2;
            if(option2 == 1){
                lista_juegos_favoritos();
            }else{
            break;
          }
        }
    }
}

// ----------------- Ordenamiento Por Nombre Juego ---------------//
case 3:

  int eleccion_titulo;
  string titulo;
  
  cout << "1. Buscar juegso por Nombre especifico" << endl;
  cout << "2. Ordenar juegos por titulo (Orden alfabetico)" << endl ;
  cin >> eleccion_titulo;

  if(eleccion_titulo == 1){

   cout << "Escribe el año de lanzamiento " << endl;
   cin >> titulo;

   for (video_juego p : lista_juegos)
                {
                    if (p.getNombre()() == titulo)
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

  }
else if(eleccion_titulo == 2){
   ordenarYImprimirNombres();
} else {
  cout << "opcion no valida" << endl;
  mostrar_juegos();
} 
  
 break;
// ----------------- Ordenamiento Por Año ---------------//
case 4:

  int eleccion_anio;
  string fecha;
  
  cout << "1. Buscar juegso por año de lanzamiento especifico" << endl;
  cout << "2. Ordenar juegos por año de lanzamiento (Mas reciente a Mas antiguo)" << endl ;
  cin >> eleccion_anio;

  if(eleccion_anio == 1){

   cout << "Escribe el año de lanzamiento " << endl;
   cin >> fecha;

   for (video_juego p : lista_juegos)
                {
                    if (p.getAnioLanzamiento() == fecha)
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

  }
else if(eleccion_anio == 2){
   analizarAnios();
} else {
  cout << "opcion no valida" << endl;
  mostrar_juegos();
} 
 break;

// ----------------- Ordenamiento Por Numero De Jugadores ---------------//
case 5: 

AnalizarJugadores();
  
 break;

// ----------------- ordenamiento por desarrolador ---------------//
case 6:

cout << "Ingrese el nombre de el desarollador del juego: "
cin >> name_desarollador;

for (video_juego p : lista_juegos)
                {
                    if (p.getDesarrollador() == name_desarrollador)
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }
  break;

//--------------------------- Ejecutador de cuatro en raya ----------------------------//

void jugar_cuatroenraya (){
  
   string nombreJugador;//pide el nombre del jugador
    int eleccion2;
    while (true)
    {
        int partidas = ej.getTotalWins();//partidas ganadas
        clock_t tiempo = ej.getTiempoJuego();//tiempo jugado
        string aux;
        cout << "Top Ganador: " << ej.getNombreJp() << endl;
        cout << "Partidas ganadas: " << partidas << endl;
        cout << "Tiempo total jugado: " << static_cast<double>(tiempo) / CLOCKS_PER_SEC << " segundos" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1- Jugar juego" << endl;
        cout << "2- Salir" << endl;
        cin >> eleccion2;

        switch (eleccion2)
        {
        case 1:
        {
            cout << "Ingrese su nombre: ";
            cin >> nombreJp;
            ej.setNombreJp(NombreJp);//actualiza nombre del jugador
            ej.jugar_cuatroenraya(TotalWins, TiempoJuego);//jugar el juego
            ej.setTotalWins(TotalWins);// actualiza las partidas ganadas
            ej.setTiempoJuego(TiempoJuego);// actualiza el tiempo jugado
            break;
        }
        case 2:
            break;
        default:
            break;
        }
        if (eleccion2 == 2)// cierra el juego
            break;
    }
}


// Función para ordenar y imprimir los nombres de videojuegos de una lista de videojuegos
  void ordenarYImprimirNombres(const vector<video_juego>& lista_juegos) {
    // Vector que contendrá todos los nombres de videojuegos
    vector<string> todosLosNombres;

    // Insertar todos los nombres de videojuegos en uno solo
    for (const auto& juego : lista_juegos) {
        todosLosNombres.push_back(p.getNombre());
    }

    // Ordenar el vector resultante alfabéticamente
    sort(todosLosNombres.begin(), todosLosNombres.end());

    // Imprimir los nombres de videojuegos ordenados
    cout << "Nombres de videojuegos ordenados:" << endl;
    for (const string& nombre : todosLosNombres) {
        cout << nombre << endl;
    }
}


// Función para analizar una lista de vectores que contienen la cantidad de jugadores de videojuegos
void analizarAnios(const vector<video_juego>& lista_juegos) {
    // Vector para almacenar todas las cantidades de jugadores
    vector<int> todasLasCantidades;

    // Recorrer todos los vectores para extraer las cantidades de jugadores
    for (const auto& juego : lista_juegos) {
        todasLasCantidades.push_back(juego.getCantJugadores());
    }

    // Ordenar las cantidades de jugadores de manera descendente
    sort(todasLasCantidades.begin(), todasLasCantidades.end(), greater<int>());
  
}


// Función para analizar una lista de vectores que contienen la cantidad de jugadores de videojuegos
void analizarAnios(const vector<video_juego>& lista_juegos) {
    // Vector para almacenar todas las cantidades de jugadores
    vector<int> todasLasCantidades;

    // Recorrer todos los vectores para extraer las cantidades de jugadores
    for (const auto& juego : lista_juegos) {
        todasLasCantidades.push_back(juego.getCantJugadores());
    }

    // Ordenar las cantidades de jugadores de manera descendente
    sort(todasLasCantidades.begin(), todasLasCantidades.end(), greater<int>());
  
}
