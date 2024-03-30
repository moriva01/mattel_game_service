//clase padre video juegos

#include <iostream>

using namespace std;

class video_juego
{

private:
    string nombre;
    int cant_jugadores;
    string categoria; // parametrizar las opciones que puede escoger el usuario
    string desarrollador;
    int anio_lanzamiento;
    string plataforma; // parametrizar las opciones que puede escoger el usuario

public:
    video_juego() {}

     video_juego(string n, int cj, string cat, string dev, int anio, string plat) : nombre(n), cant_jugadores(cj), categoria(cat), desarrollador(dev),
                                                                                   anio_lanzamiento(anio), plataforma(plat) {}

    // ---------------------------------------------------------------------- setters
    void setNombre(const string &n)
    {
        nombre = n;
    }

    void setCantJugadores(int cant)
    {
        cant_jugadores = cant;
    }

    void setCategoria(const string &cat)
    {
        categoria = cat;
    }

    void setDesarrollador(const string &des)
    {
        desarrollador = des;
    }

    void setAnioLanzamiento(int anio)
    {
        anio_lanzamiento = anio;
    }

    void setPlataforma(const string &plat)
    {
        plataforma = plat;
    }

    // ---------------------------------------------------------- getters
    string getNombre() const
    {
        return nombre;
    }

    int getCantJugadores() const
    {
        return cant_jugadores;
    }

    string getCategoria() const
    {
        return categoria;
    }

    string getDesarrollador() const
    {
        return desarrollador;
    }

    int getAnioLanzamiento() const
    {
        return anio_lanzamiento;
    }

    string getPlataforma() const
    {
        return plataforma;
    }
};
