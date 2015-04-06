#ifndef UNJUGADOR_H
#define UNJUGADOR_H
#include "Dos_Jugadores.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <cstdlib>

class UnJugador
{
    public:
        UnJugador();
        virtual ~UnJugador();
        sf::Texture cuadro1,cuadro2,cuadro3,cuadro4,cuadro5,cuadro6,cuadro7,cuadro8,cuadro9;
        sf::Sprite sp1,sp2,sp3,sp4,sp5,sp6,sp7,sp8,sp9;
        char tablero[3][3];
        char turno='X';
        bool cambiarTurno(int x,int y);
        void inicializarTablero();
        void texturas();
        void primerCuadro();
        void segundoCuadro();
        void tercerCuadro();
        void cuartoCuadro();
        void quintoCuadro();
        void sextoCuadro();
        void septimoCuadro();
        void octavoCuadro();
        void novenoCuadro();
        char ganar();
        int maquina();
    protected:
    private:
};

#endif // UNJUGADOR_H
