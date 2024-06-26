// aqui se haran los metodos que unen la clase main con las clases del modelo

#include "../modelo/ahorcado.cpp" // hereda todo lo del ahorcado

//---------------------------------------------------------------------------------------------------------------------------------------- branch deivy

#include "../modelo/cuatro_en_raya.cpp"

void lista_juegos_favoritos()
{
    vector<video_juego> Juegos_favoritos;
    string nombre;
    char option;
    int option2;

    cout << "Digite el nombre del video juego: " << endl;
    cin >> nombre;

    for (video_juego p : Juegos_favoritos)
    {
        if (nombre == p.getNombre())
        {
            // Agregar el juego a la lista de favoritos
            Juegos_favoritos.push_back(p);
            cout << "El juego ha sido agregado a la lista de favoritos." << endl;
            cout << "/------Menú-----/" << endl;
            cout << "1. Agregar otro juego a lista de favoritos " << endl;
            cout << "2. Salir. " << endl;
            cin >> option2;
            if (option2 == 1)
            {
                lista_juegos_favoritos();
            }
            else
            {
                break;
            }
        }
    }
}

/*


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

*/

//--------------------------- Ejecutador de cuatro en raya ----------------------------//

void jugar_cuatroenraya(CuatroEnLinea ej)
{

    string nombreJugador; // pide el nombre del jugador
    int eleccion2;
    while (true)
    {
        //  int partidas = ej.getTotalWins();//partidas ganadas
        // clock_t tiempo = ej.getTiempoJuego();//tiempo jugado
        string aux;
        // cout << "Top Ganador: " << ej.getNombreJp() << endl;
        //  cout << "Partidas ganadas: " << partidas << endl;
        //   cout << "Tiempo total jugado: " << static_cast<double>(tiempo) / CLOCKS_PER_SEC << " segundos" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1- Jugar juego" << endl;
        cout << "2- Salir" << endl;
        cin >> eleccion2;

        switch (eleccion2)
        {
        case 1:
        {
            cout << "Ingrese su nombre: ";
            //   cin >> nombreJp;
            //    ej.setNombreJp(NombreJp);//actualiza nombre del jugador
            //    ej.jugar_cuatroenraya(TotalWins, TiempoJuego);//jugar el juego
            //    ej.setTotalWins(TotalWins);// actualiza las partidas ganadas
            //    ej.setTiempoJuego(TiempoJuego);// actualiza el tiempo jugado
            break;
        }
        case 2:
            break;
        default:
            break;
        }
        if (eleccion2 == 2) // cierra el juego
            break;
    }
}

// Función para ordenar y imprimir los nombres de videojuegos de una lista de videojuegos
void ordenarYImprimirNombres(const vector<video_juego> &lista_juegos)
{
    // Vector que contendrá todos los nombres de videojuegos
    vector<string> todosLosNombres;

    // Insertar todos los nombres de videojuegos en uno solo
    for (const auto &juego : lista_juegos)
    {
        todosLosNombres.push_back(juego.getNombre());
    }

    // Ordenar el vector resultante alfabéticamente
    sort(todosLosNombres.begin(), todosLosNombres.end());

    // Imprimir los nombres de videojuegos ordenados
    cout << "Nombres de videojuegos ordenados:" << endl;
    for (const string &nombre : todosLosNombres)
    {
        cout << nombre << endl;
    }
}

// Función para analizar una lista de vectores que contienen la cantidad de jugadores de videojuegos
/*void analizarAnios(const vector<video_juego> &lista_juegos)
{
    // Vector para almacenar todas las cantidades de jugadores
    vector<int> todasLasCantidades;

    // Recorrer todos los vectores para extraer las cantidades de jugadores
    for (const auto &juego : lista_juegos)
    {
        todasLasCantidades.push_back(juego.getCantJugadores());
    }

    // Ordenar las cantidades de jugadores de manera descendente
    sort(todasLasCantidades.begin(), todasLasCantidades.end(), greater<int>());
}*/

// Función para analizar una lista de vectores que contienen la cantidad de jugadores de videojuegos
void analizarAnios(const vector<video_juego> &lista_juegos)
{
    // Vector para almacenar todas las cantidades de jugadores
    vector<int> todasLasCantidades;

    // Recorrer todos los vectores para extraer las cantidades de jugadores
    for (const auto &juego : lista_juegos)
    {
        todasLasCantidades.push_back(juego.getCantJugadores());
    }

    // Ordenar las cantidades de jugadores de manera descendente
    sort(todasLasCantidades.begin(), todasLasCantidades.end(), greater<int>());
}

//-----------------------------------------------------------------------------------

vector<video_juego> lista_juegos; // lista de juegos

void ingresar_nuevos_juegos() // metodo para ingresar juegos a la lista
{
    video_juego aux; // crea objeto auxiliar
    string nombre;
    int cant_jugadores;
    int categoria;
    string desarrollador;
    int anio_lanzamiento;
    int plataforma;

    cout << "Digite el nombre del video juego: " << endl;
    cin >> nombre; // pide los datos por entrada del teclado

    for (video_juego p : lista_juegos) // recorre la lista
    {

        if (nombre == p.getNombre()) // mira si el juego ya esta registrado
        {
            cout << "el juego ya se encuentra registrado" << endl;
            break;
        }
    }
    aux.setNombre(nombre);
    cout << "Digite la canditad de jugadores: " << endl;
    cin >> cant_jugadores;
    aux.setCantJugadores(cant_jugadores);
    cout << "Digite la categoria del video juego: \n"
         << "1- arcade \n 2- aventura \n 3- puzzle \n 4- estrategia \n 5- disparos" << endl;
    cin >> categoria;

    switch (categoria) // pone la categoria -- solo usaremos 5 categorias por ahora
    {
    case 1:
        aux.setCategoria("arcade");
        break;
    case 2:
        aux.setCategoria("aventura");
        break;
    case 3:
        aux.setCategoria("puzzle");
        break;
    case 4:
        aux.setCategoria("estrategia");
        break;
    case 5:
        aux.setCategoria("disparos");
        break;

    default:
        cout << "categoria no disponible, pongase en contacto con el adminsitrador para que la agregue" << endl; // si la categoria no esta disponible
        break;
    }

    cout << "Digite el nombre del desarrollador del video juego: " << endl;
    cin >> desarrollador;
    aux.setDesarrollador(desarrollador);
    cout << "Digite el año de lanzamiento del video juego: " << endl;
    cin >> anio_lanzamiento;
    aux.setAnioLanzamiento(anio_lanzamiento);
    cout << "Digite la plataforma en la que se almacena el video juego: " << endl;
    cout << "1- steam \n 2- Ea play \n 3- Ubisoft \n 4- Epic games \n 5- Gforece one" << endl;
    cin >> plataforma;
    switch (plataforma) // pone la plataforma -- solo usaremos 5 plataformas por ahora
    {
    case 1:
        aux.setPlataforma("Steam");
        break;
    case 2:
        aux.setPlataforma("Ea play");
        break;
    case 3:
        aux.setPlataforma("Ubisoft");
        break;
    case 4:
        aux.setPlataforma("Epic games");
        break;
    case 5:
        aux.setPlataforma("Gforece one");
        break;

    default:
        cout << "plataforma no disponible, pongase en contacto con el adminsitrador para que la agregue" << endl; // si la plataforma no esta disponible
        break;
    }

    lista_juegos.push_back(aux); // agrega el juego a la lista
}

void mostrar_juegos() // metodo mostrar los juegos que hay en la lista
{

    int eleccion, eleccion2, eleccion3;
    cout
        << "------------------------------------------ Bienvenido a las listas de juegos, que deseas hacer?" << endl
        << "1- ingresar un juego" << endl
        << "2- ver lista de juegos" << endl
        << "3- salir" << endl;
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:
        ingresar_nuevos_juegos(); // ingresar los juegos
        break;

    case 2:
        cout
            << "------------------------------------------ Como quieres visualizar tus juegos?" << endl
            << "1- ver lista completa de juegos" << endl;
        cout << "2- ver lista por categorias" << endl;
        cout << "3- salir" << endl;
        cin >> eleccion2;
        switch (eleccion2)
        {
        case 1: // imprimir toda la lista

            cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
            for (video_juego p : lista_juegos)
            {

                cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
            }

            break;

        case 2: // por si se quiere filtrar por categoria
            cout << "----------------- por favor seleccione la categoria por la que quiere filtrar la lista: " << endl;
            cout << "1- arcade" << endl
                 << "2- aventura" << endl
                 << "3- puzzle" << endl
                 << "4- estrategia" << endl
                 << "5- disparos" << endl
                 << "6- salir" << endl;

            cin >> eleccion3;

            switch (eleccion3)
            {
            case 1:
                cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
                for (video_juego p : lista_juegos)
                {
                    if (p.getCategoria() == "arcade")
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

                break;

            case 2:

                cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
                for (video_juego p : lista_juegos)
                {
                    if (p.getCategoria() == "aventura")
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

                break;

            case 3:

                cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
                for (video_juego p : lista_juegos)
                {
                    if (p.getCategoria() == "puzzle")
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

                break;

            case 4:

                cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
                for (video_juego p : lista_juegos)
                {
                    if (p.getCategoria() == "estrategia")
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

                break;

            case 5:

                cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
                for (video_juego p : lista_juegos)
                {
                    if (p.getCategoria() == "disparos")
                    {

                        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
                    }
                }

                break;

            case 6:
                return;
                break;

            default:
                cout << "opcion no valida" << endl;
                break;
            }
            break;
        case 3:
            return;
            break;
        default:
            cout << "opcion no valida" << endl;
            break;
        }

        break;
    case 3:
        return;
        break;
    default:
        cout << "opcion no valida" << endl;
        break;
    }
}

void jugar_ahorcado(ahorcado bcs) // metodo para jugar al ahorcado
{
    string nombreJugador; // pide el nombre del jugador
    int eleccion2;
    while (true)
    {
        int partidas = bcs.getPartidasGanadas(); // partidas gabadas
        clock_t tiempo = bcs.getTiempoJugado();  // tiempo jugado
        string aux;
        cout << "------------------------- Juego del ahorcado ------------------------------" << endl;
        cout << "Top Ganador: " << bcs.getNombreJugador() << endl;
        cout << "Partidas ganadas: " << partidas << endl;
        cout << "Tiempo total jugado: " << static_cast<double>(tiempo) / CLOCKS_PER_SEC << " segundos" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "-------------- Que deseas hacer hoy?" << endl;
        cout << "1- Jugar juego" << endl;
        cout << "2- Salir" << endl;
        cin >> eleccion2;

        switch (eleccion2)
        {
        case 1:
        {
            cout << "Ingrese su nombre: ";
            cin >> nombreJugador;
            bcs.setNombreJugador(nombreJugador);  // actualiza nombre del jugador
            bcs.jugar_ahorcado(partidas, tiempo); // jugar el juego
            bcs.setPartidasGanadas(partidas);     // actualiza las partidas ganadas
            bcs.setTiempoJugado(tiempo);          // actualiza el tiempo jugado
            break;
        }
        case 2:
            break;
        default:
            break;
        }
        if (eleccion2 == 2) // cierra el juego
            break;
    }
}

bool comparar_nombres(const video_juego &juego1, const video_juego &juego2) // busca el nombre dentro de la lista
{
    return juego1.getNombre() < juego2.getNombre();
}

bool comparar_plataforma(const video_juego &juego1, const video_juego &juego2) // busca la plataforma dentro de la lista
{
    return juego1.getPlataforma() < juego2.getPlataforma();
}

int busqueda_binaria(const vector<video_juego> &lista, const string &nombre) // metodo de busqueda binaria
{
    int inicio = 0;
    int fin = lista.size() - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        // Si encontramos el nombre
        if (lista[medio].getNombre() == nombre)
        {
            return medio;
        }
        // Si el nombre está en la mitad inferior
        else if (lista[medio].getNombre() < nombre)
        {
            inicio = medio + 1;
        }
        // Si el nombre está en la mitad superior
        else
        {
            fin = medio - 1;
        }
    }

    // Si no se encuentra el nombre
    return -1;
}

void cambiar_categoria() // metodo cambiar categoria
{
    string aux; // guarda nombre el juego
    int categoria;

    cout << "bienvenido al sistema para reasignar categorias; a continuacion va a ver la lista de juegos y su actual categoria;" << endl;

    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "----- Nombre:       ----------- Categoria: " << endl;

    for (video_juego p : lista_juegos) // recorre toda la lista de juegos
    {

        cout << p.getNombre() << "-----" << p.getCategoria() << "-----" << endl;
    }

    cout << "--------------------------------------------------------------------------------------------" << endl;

    cout << "por favor digite el nombre del juego para el que quiere cambiar la categoria: " << endl;
    cin >> aux; // toma el nombre del juego

    int indice = busqueda_binaria(lista_juegos, aux); // busca el nombre en la lista

    if (indice != -1)
    { // si lo encuentra nos deja cambiar la categoria

        cout << "Digite la categoria del video juego: \n"
             << "1- arcade \n 2- aventura \n 3- puzzle \n 4- estrategia \n 5- disparos" << endl;
        cin >> categoria;

        switch (categoria) // pone la categoria -- solo usaremos 5 categorias por ahora
        {
        case 1:
            lista_juegos[indice].setCategoria("arcade");
            break;
        case 2:
            lista_juegos[indice].setCategoria("aventura");
            break;
        case 3:
            lista_juegos[indice].setCategoria("puzzle"); // cambia la categoria del objeto en el indice
            break;
        case 4:
            lista_juegos[indice].setCategoria("estrategia");
            break;
        case 5:
            lista_juegos[indice].setCategoria("disparos");
            break;

        default:
            cout << "categoria no disponible, pongase en contacto con el adminsitrador para que la agregue" << endl; // si la categoria no esta disponible
            break;
        }

        cout << "categoria actualizada correctamente" << endl;
    }
    else
    { // si no lo encuentra nos lo dice y sale del metodo
        cout << "el juego no se encontró en la lista." << endl;
    }
}

void plataforma() // muestra organixado por plataforma
{

    sort(lista_juegos.begin(), lista_juegos.end(), comparar_plataforma); // organiza la lista por plataforma

    string plataforma_actual = ""; // guarda el titulo de la plataforma

    cout << "Nombre ----- # jugadores ----- categoria ----- desarrollador ----- año lanzamiento ----- plataforma" << endl;
    for (video_juego p : lista_juegos)
    {

        if (p.getPlataforma() != plataforma_actual) // si cambia d eplataforma cambia el subtitulo
        {
            plataforma_actual = p.getPlataforma();
            cout << "--------------------------------------------------------------------------------------------" << endl;
            cout << "Plataforma: " << plataforma_actual << endl; // titulo de l aplataforma
            cout << "--------------------------------------------------------------------------------------------" << endl;
        }

        cout << p.getNombre() << "-----" << p.getCantJugadores() << "-----" << p.getCategoria() << "-----" << p.getDesarrollador() << "-----" << p.getAnioLanzamiento() << "-----" << p.getPlataforma() << endl;
    }
}