// aqui se haran los metodos que unen la clase main con las clases del modelo

#include "../modelo/ahorcado.cpp"

vector<video_juego> lista_juegos;

void ingresar_nuevos_juegos()
{
    video_juego aux;
    string nombre;
    int cant_jugadores;
    int categoria;
    string desarrollador;
    int anio_lanzamiento;
    int plataforma;

    cout << "Digite el nombre del video juego: " << endl;
    cin >> nombre;

    for (video_juego p : lista_juegos) // recorre la lista
    {

        if (nombre == p.getNombre()) // mira si el documento ya esta registrado
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

    switch (categoria)
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
        cout << "opcion no valida" << endl;
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
    switch (plataforma)
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
        cout << "opcion no valida" << endl;
        break;
    }

    lista_juegos.push_back(aux);
}

void jugar_ahorcado(ahorcado bcs)
{
    string nombreJugador;
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
        cout << "1- Jugar juego" << endl;
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
            break;
        default:
            break;
        }
        if (eleccion2 == 2)
            break;
    }
}