#include "Dos_Jugadores.h"

Dos_Jugadores::Dos_Jugadores()
{
    //ctor
}

Dos_Jugadores::~Dos_Jugadores()
{
    //dtor
}

void Dos_Jugadores::inicializarTablero(){
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        tablero[i][j]=' ';
        }
    }
}

char Dos_Jugadores:: ganar(){
    if(tablero[0][0]=='X'||tablero[0][0]=='O'){
        if(tablero[0][0]==tablero[0][1] && tablero[0][0]==tablero[0][2]){
            if(tablero[0][0]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
        if(tablero[0][0]==tablero[1][0] && tablero[0][0]==tablero[2][0]){
            if(tablero[0][0]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
    }

    if(tablero[1][1]=='X'||tablero[1][1]=='O'){
        if(tablero[1][1]==tablero[0][0] && tablero[1][1]==tablero[2][2]){
            if(tablero[1][1]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
        if(tablero[1][1]==tablero[1][0] && tablero[1][1]==tablero[1][2]){
            if(tablero[1][1]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
        if(tablero[1][1]==tablero[2][0] && tablero[1][1]==tablero[0][2]){
            if(tablero[1][1]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
        if(tablero[1][1]==tablero[0][1] && tablero[1][1]==tablero[2][1]){
            if(tablero[1][1]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
        }
    }

    if(tablero[2][2]=='X'||tablero[2][2]=='O'){
         if(tablero[2][2]==tablero[2][0] && tablero[2][2]==tablero[2][1]){
            if(tablero[2][2]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
         }
         if(tablero[2][2]==tablero[0][2] && tablero[2][2]==tablero[1][2]){
            if(tablero[2][2]=='X'){
                return 'X'; //Ha ganado X
            }
            else{
                return 'O'; //Ha ganado O
            }
         }
    }

    return 'E';

}

bool Dos_Jugadores::cambiarTurno(int x, int y){

    if(tablero[x][y]!=' ')
        return false;

    if(turno=='O'){
            tablero[x][y]='O';
            turno='X';
    }else{

            tablero[x][y]='X';
            turno='O';
    }
    return true;
}

void Dos_Jugadores::primerCuadro(){
        if(turno=='O'){
            if(cambiarTurno(0,0)){
                cuadro1.loadFromFile("img_0.png");
                sp1.setTexture(cuadro1);
                sp1.setPosition(sf::Vector2f(125.f,95.f));
            }
        }
        else{
            if(cambiarTurno(0,0)){
                cuadro1.loadFromFile("img_x.png");
                sp1.setTexture(cuadro1);
                sp1.setPosition(sf::Vector2f(125.f,95.f));
            }
        }
}

void Dos_Jugadores::segundoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(0,1)){
                cuadro2.loadFromFile("img_0.png");
                sp2.setTexture(cuadro2);
                sp2.setPosition(sf::Vector2f(485.f,95.f));
            }
        }
         else{
            if(cambiarTurno(0,1)){
                cuadro2.loadFromFile("img_x.png");
                sp2.setTexture(cuadro2);
                sp2.setPosition(sf::Vector2f(485.f,95.f));
            }
        }
}

void Dos_Jugadores::tercerCuadro(){
        if(turno=='O'){
            if(cambiarTurno(0,2)){
                cuadro3.loadFromFile("img_0.png");
                sp3.setTexture(cuadro3);
                sp3.setPosition(sf::Vector2f(825.f,95.f));
            }
        }
        else{
            if(cambiarTurno(0,2)){
                cuadro3.loadFromFile("img_x.png");
                sp3.setTexture(cuadro3);
                sp3.setPosition(sf::Vector2f(825.f,95.f));
            }
        }
}

void Dos_Jugadores::cuartoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(1,0)){
                cuadro4.loadFromFile("img_0.png");
                sp4.setTexture(cuadro4);
                sp4.setPosition(sf::Vector2f(125.f,360.f));
            }
        }
        else{
            if(cambiarTurno(1,0)){
                cuadro4.loadFromFile("img_x.png");
                sp4.setTexture(cuadro4);
                sp4.setPosition(sf::Vector2f(125.f,360.f));
            }
        }
}

void Dos_Jugadores::quintoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(1,1)){
                cuadro5.loadFromFile("img_0.png");
                sp5.setTexture(cuadro5);
                sp5.setPosition(sf::Vector2f(485.f,360.f));
            }
        }
        else{
            if(cambiarTurno(1,1)){
                cuadro5.loadFromFile("img_x.png");
                sp5.setTexture(cuadro5);
                sp5.setPosition(sf::Vector2f(485.f,360.f));
            }
        }
}

void Dos_Jugadores::sextoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(1,2)){
                cuadro6.loadFromFile("img_0.png");
                sp6.setTexture(cuadro6);
                sp6.setPosition(sf::Vector2f(850.f,360.f));
            }
        }
        else{
            if(cambiarTurno(1,2)){
                cuadro6.loadFromFile("img_x.png");
                sp6.setTexture(cuadro6);
                sp6.setPosition(sf::Vector2f(850.f,360.f));
            }
        }
}

void Dos_Jugadores::septimoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(2,0)){
                cuadro7.loadFromFile("img_0.png");
                sp7.setTexture(cuadro7);
                sp7.setPosition(sf::Vector2f(110.f,650.f));
            }
        }
        else{
            if(cambiarTurno(2,0)){
                cuadro7.loadFromFile("img_x.png");
                sp7.setTexture(cuadro7);
                sp7.setPosition(sf::Vector2f(110.f,650.f));
            }
        }
}

void Dos_Jugadores::octavoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(2,1)){

                cuadro8.loadFromFile("img_0.png");
                sp8.setTexture(cuadro8);
                sp8.setPosition(sf::Vector2f(485.f,650.f));
            }
        }
        else{
            if(cambiarTurno(2,1)){
                cuadro8.loadFromFile("img_x.png");
                sp8.setTexture(cuadro8);
                sp8.setPosition(sf::Vector2f(485.f,650.f));
            }
        }
}

void Dos_Jugadores::novenoCuadro(){
        if(turno=='O'){
            if(cambiarTurno(2,2)){
                cuadro9.loadFromFile("img_0.png");
                sp9.setTexture(cuadro9);
                sp9.setPosition(sf::Vector2f(825.f,650.f));
            }
        }
        else{
            if(cambiarTurno(2,2)){
                cuadro9.loadFromFile("img_x.png");
                sp9.setTexture(cuadro9);
                sp9.setPosition(sf::Vector2f(825.f,650.f));
            }
        }
}


