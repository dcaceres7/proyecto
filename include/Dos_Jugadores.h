#ifndef DOS_JUGADORES_H
#define DOS_JUGADORES_H
#include <SFML/Graphics.hpp>

class Dos_Jugadores
{
    public:
        Dos_Jugadores();
        sf::Texture cuadro1,cuadro2,cuadro3,cuadro4,cuadro5,cuadro6,cuadro7,cuadro8,cuadro9;
        sf::Sprite sp1,sp2,sp3,sp4,sp5,sp6,sp7,sp8,sp9;
        char tablero[3][3];
        char turno='O';
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
        virtual ~Dos_Jugadores();
    protected:
    private:
};

#endif // DOS_JUGADORES_H
