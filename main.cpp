#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dos_Jugadores.h"
#include "UnJugador.h"
#include <string>
#include <sstream>
#include <fstream>
#include <SFML/Audio.hpp>

using namespace std;

    int pmouse_x=0,pmouse_y=0, contador=0;
    sf::Music musicm,music1,music2;
    sf::Texture textura;
    sf::Sprite sp;
    sf::Font letra,g_O,g_X,g_E,ftO,ftX,ftE,ltm,lscore;
    sf::Text miTexto,tg_O,tg_X,tg_E,tO,tX,tE,ttm,tscore;
    int ganar2_X=0,ganar2_O=0,empate2=0,ganar1_X=0,ganar1_O=0,empate1=0;
    double score1,score2,score3,scoreJugador;
    bool empezar=true;
    string nombre1=" ",nombre2=" ";
    Dos_Jugadores *dj=new Dos_Jugadores();
    UnJugador *uj=new UnJugador();


void ganar(){
    if(dj->ganar()=='X'){
    ganar2_X++;
    empezar=false;
    }
    else if(dj->ganar()=='O'){
    ganar2_O++;
    empezar=false;
    }
    if(contador>=9){
    if(dj->ganar()=='E'){
    empate2++;
    empezar=false;
    }
    }
}

void ganarUnJugador(){
  if(uj->ganar()=='X'){
    ganar1_X++;
    empezar=false;
    }
    else if(uj->ganar()=='O'){
    ganar1_O++;
    empezar=false;
    }
    if(contador>=5){
    if(uj->ganar()=='E'){
    empezar=false;
    empate1++;
    }
    }
}



void dibujarUnJugador(){
  if(empezar){
    if(pmouse_y>=0 && pmouse_y<=213){

        if(pmouse_x>=0 && pmouse_x<=327){
            uj->primerCuadro();
            contador++;
        }
        else if(pmouse_x>=348 && pmouse_x<=697){
            uj->segundoCuadro();
            contador++;
        }
        else if(pmouse_x>=719 && pmouse_x<=1054){
        contador++;
            uj->tercerCuadro();
        }
    }

    if(pmouse_y>=234 && pmouse_y<=453){

         if(pmouse_x>=0 && pmouse_x<=322){
         uj->cuartoCuadro();
         contador++;
         }
         else if(pmouse_x>=348 && pmouse_x<=696){
         uj->quintoCuadro();
         contador++;
         }
         else if(pmouse_x>=722 && pmouse_x<=1053){
         uj->sextoCuadro();
         contador++;
         }
    }

    if(pmouse_y>=480 && pmouse_y<=713){

         if(pmouse_x>=0 && pmouse_x<=324){
         uj->septimoCuadro();
         contador++;
         }
         else if(pmouse_x>=348 && pmouse_x<=696){
         uj->octavoCuadro();
         contador++;
         }
         else if(pmouse_x>=722 && pmouse_x<=1053){
         uj->novenoCuadro();
         contador++;
         }
    }

    ganarUnJugador();
    }
}



void dibujarUnJugadorM(){
if(empezar){
  if(uj->maquina()==1){
    uj->primerCuadro();
    }
  if(uj->maquina()==2){
    uj->segundoCuadro();
    }
  if(uj->maquina()==3){
    uj->tercerCuadro();
    }
  if(uj->maquina()==4){
    uj->cuartoCuadro();
    }
  if(uj->maquina()==5){
    uj->quintoCuadro();
    }
  if(uj->maquina()==6){
    uj->sextoCuadro();
    }

  if(uj->maquina()==7){
    uj->septimoCuadro();
    }
  if(uj->maquina()==8){
    uj->octavoCuadro();
    }
  if(uj->maquina()==9){
    uj->novenoCuadro();
    }
  ganarUnJugador();

 }
}


void dibujarDosJugadores(){

if(empezar){
    if(pmouse_y>=0 && pmouse_y<=213){

        if(pmouse_x>=0 && pmouse_x<=327){
            dj->primerCuadro();
            contador++;
        }
        else if(pmouse_x>=348 && pmouse_x<=697){
            dj->segundoCuadro();
            contador++;
        }
        else if(pmouse_x>=719 && pmouse_x<=1054){
        contador++;
            dj->tercerCuadro();
        }
    }

    if(pmouse_y>=234 && pmouse_y<=453){

         if(pmouse_x>=0 && pmouse_x<=322){
         dj->cuartoCuadro();
         contador++;
         }
         else if(pmouse_x>=348 && pmouse_x<=696){
         dj->quintoCuadro();
         contador++;
         }
         else if(pmouse_x>=722 && pmouse_x<=1053){
         dj->sextoCuadro();
         contador++;
         }
    }

    if(pmouse_y>=480 && pmouse_y<=713){

         if(pmouse_x>=0 && pmouse_x<=324){
         dj->septimoCuadro();
         contador++;
         }
         else if(pmouse_x>=348 && pmouse_x<=696){
         contador++;
         dj->octavoCuadro();
         }
         else if(pmouse_x>=722 && pmouse_x<=1053){
         contador++;
         dj->novenoCuadro();
         }
    }

    ganar();
    }

}

void scoresGuardar(){
    if(scoreJugador==score1 || scoreJugador==score2 ||scoreJugador==score3){
    }
    else if(scoreJugador<score1){
        score3=score2;
        score2=score1;
        score1=scoreJugador;
    }
    else if(scoreJugador<score2){
        score3=score2;
        score2=scoreJugador;
    }
    else if(scoreJugador<score3){
        score3=scoreJugador;
    }

    ofstream of("scores.txt");
        of<<score1<<'/n';
        of<<score2<<'/n';
        of<<score3<<'/n';
        of.close();

}

void scoresImprimir(){
ifstream in("scores.txt");
in>>score1;
in>>score2;
in>>score3;
in.close();
}

void loopUnJugador()
{

    sf::Clock clock;
    sf::Time time;
    sf::RenderWindow window(sf::VideoMode(1380,801), "X-O");
    bool clic=false;
    uj->inicializarTablero();
    textura.loadFromFile("fondo_x-0.png");
    sp.setTexture(textura);


    letra.loadFromFile("orangejuice.ttf");
    g_X.loadFromFile("orangejuice.ttf");
    g_E.loadFromFile("orangejuice.ttf");
    ftO.loadFromFile("orangejuice.ttf");
    ftE.loadFromFile("orangejuice.ttf");
    ftX.loadFromFile("orangejuice.ttf");
    ltm.loadFromFile("orangejuice.ttf");

    tO.setFont(ftO);
    tO.setCharacterSize(43);
    tO.setString("Gano O :");
    tO.setColor(sf::Color(180,189,134));
    tO.setPosition(sf::Vector2f(1095.f,250.f));

    tX.setFont(ftX);
    tX.setCharacterSize(43);
    tX.setString("Gano X :");
    tX.setColor(sf::Color(180,189,134));
    tX.setPosition(sf::Vector2f(1095.f,350.f));

    tE.setFont(ftE);
    tE.setCharacterSize(43);
    tE.setString("Empate :");
    tE.setColor(sf::Color(180,189,134));
    tE.setPosition(sf::Vector2f(1095.f,450.f));

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
    stringstream t;
    t<<time.asSeconds();
    string tmString=t.str();

    stringstream so;
    so<<ganar1_O;
    string newString=so.str();

    stringstream sx;
    sx<<ganar1_X;
    string nString=sx.str();

    stringstream se;
    se<<empate1;
    string Stringn=se.str();

    ttm.setFont(ltm);
    ttm.setCharacterSize(35);
    ttm.setString(tmString);
    ttm.setColor(sf::Color(180,189,134));
    ttm.setPosition(sf::Vector2f(1130.f,185.f));

    miTexto.setFont(letra);
    miTexto.setCharacterSize(30);
    miTexto.setString(newString);
    miTexto.setColor(sf::Color(180,189,134));
    miTexto.setPosition(sf::Vector2f(1130.f,305.f));

    tg_X.setFont(g_X);
    tg_X.setCharacterSize(30);
    tg_X.setString(nString);
    tg_X.setColor(sf::Color(180,189,134));
    tg_X.setPosition(sf::Vector2f(1130.f,405.f));

    tg_E.setFont(g_E);
    tg_E.setCharacterSize(30);
    tg_E.setString(Stringn);
    tg_E.setColor(sf::Color(180,189,134));
    tg_E.setPosition(sf::Vector2f(1130.f,505.f));
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                music1.stop();
            }

            if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left){
                clic=true;
            }

            if(event.type==sf::Event::MouseMoved){
                pmouse_x=event.mouseMove.x;
                pmouse_y=event.mouseMove.y;

            }

        }
        time=clock.getElapsedTime();
        window.clear();
         if(clic==true && uj->turno=='X'){
          dibujarUnJugador();

          clic=false;
         }

        if(empezar==false){
        scoresImprimir();
        scoreJugador=time.asSeconds();
        scoresGuardar();
        }

        if(uj->turno=='O')
        dibujarUnJugadorM();
       window.draw(sp);
       window.draw(uj->sp1);
       window.draw(uj->sp2);
       window.draw(uj->sp3);
       window.draw(uj->sp4);
       window.draw(uj->sp5);
       window.draw(uj->sp6);
       window.draw(uj->sp7);
       window.draw(uj->sp8);
       window.draw(uj->sp9);
       window.draw(miTexto);
       window.draw(tO);
       window.draw(tX);
       window.draw(tE);
       window.draw(tg_X);
       window.draw(tg_E);
       window.draw(ttm);
       window.display();
    }
}


void loopDosJugadores()
{
    sf::Clock clock;
    sf::Time time;
    sf::RenderWindow window(sf::VideoMode(1380,801), "X-O");
    bool clic=false;
    dj->inicializarTablero();
    textura.loadFromFile("fondo_x-0.png");
    sp.setTexture(textura);

    letra.loadFromFile("orangejuice.ttf");
    g_X.loadFromFile("orangejuice.ttf");
    g_E.loadFromFile("orangejuice.ttf");
    ftO.loadFromFile("orangejuice.ttf");
    ftE.loadFromFile("orangejuice.ttf");
    ftX.loadFromFile("orangejuice.ttf");
    ltm.loadFromFile("orangejuice.ttf");

    tO.setFont(ftO);
    tO.setCharacterSize(43);
    tO.setString("Gano O :");
    tO.setColor(sf::Color(180,189,134));
    tO.setPosition(sf::Vector2f(1095.f,250.f));

    tX.setFont(ftX);
    tX.setCharacterSize(43);
    tX.setString("Gano X :");
    tX.setColor(sf::Color(180,189,134));
    tX.setPosition(sf::Vector2f(1095.f,350.f));

    tE.setFont(ftE);
    tE.setCharacterSize(43);
    tE.setString("Empate :");
    tE.setColor(sf::Color(180,189,134));
    tE.setPosition(sf::Vector2f(1095.f,450.f));

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
    stringstream so;
    so<<ganar2_O;
    string newString=so.str();

    stringstream sx;
    sx<<ganar2_X;
    string nString=sx.str();

    stringstream se;
    se<<empate2;
    string Stringn=se.str();

    stringstream t;
    t<<time.asSeconds();
    string tmString=t.str();

    miTexto.setFont(letra);
    miTexto.setCharacterSize(30);
    miTexto.setString(newString);
    miTexto.setColor(sf::Color(180,189,134));
    miTexto.setPosition(sf::Vector2f(1130.f,305.f));

    tg_X.setFont(g_X);
    tg_X.setCharacterSize(30);
    tg_X.setString(nString);
    tg_X.setColor(sf::Color(180,189,134));
    tg_X.setPosition(sf::Vector2f(1130.f,405.f));

    tg_E.setFont(g_E);
    tg_E.setCharacterSize(30);
    tg_E.setString(Stringn);
    tg_E.setColor(sf::Color(180,189,134));
    tg_E.setPosition(sf::Vector2f(1130.f,505.f));

    ttm.setFont(ltm);
    ttm.setCharacterSize(35);
    ttm.setString(tmString);
    ttm.setColor(sf::Color(180,189,134));
    ttm.setPosition(sf::Vector2f(1130.f,185.f));

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                music2.stop();
                window.close();
            }

            if(event.type==sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left){
                clic=true;
            }

            if(event.type==sf::Event::MouseMoved){
                pmouse_x=event.mouseMove.x;
                pmouse_y=event.mouseMove.y;
                }
        }
        time=clock.getElapsedTime();
        window.clear();
        if(clic){
          dibujarDosJugadores();

          clic=false;
        }

        if(empezar==false){
        scoresImprimir();
        scoreJugador=time.asSeconds();
        scoresGuardar();
        }


//    if(empezar==false){
//    escribir(time.asSeconds());
//    }
       window.draw(sp);
       window.draw(dj->sp1);
       window.draw(dj->sp2);
       window.draw(dj->sp3);
       window.draw(dj->sp4);
       window.draw(dj->sp5);
       window.draw(dj->sp6);
       window.draw(dj->sp7);
       window.draw(dj->sp8);
       window.draw(dj->sp9);
       window.draw(miTexto);
       window.draw(tO);
       window.draw(tX);
       window.draw(tE);
       window.draw(tg_X);
       window.draw(tg_E);
       window.draw(ttm);
       window.display();
    }

}



void instrucciones(){

sf::RenderWindow window(sf::VideoMode(452,256), "X-O");
sf::Texture instrucciones;
sf::Sprite inst;

    instrucciones.loadFromFile("Jinstrucciones.png");
    inst.setTexture(instrucciones);

    while (window.isOpen()){
       sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;

       }
       window.clear();
       window.draw(inst);
       window.display();
    }
}

void bScore(){

sf::RenderWindow window(sf::VideoMode(452,256), "X-O");
lscore.loadFromFile("orangejuice.ttf");

    while (window.isOpen()){

//    stringstream t;
//    t<<time.asSeconds();
//    string tmString=t.str();
       sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;

       }

       window.clear();
       //window.draw(inst);
       window.display();
    }
}


void mainMenu()
{

    sf::RenderWindow window(sf::VideoMode(1075,650), "X-O");
    sf::Texture menu,b1,b2,b3,b4,b5;
    sf::Sprite mn,spb1,spb2,spb3,spb4,spb5;
    music2.openFromFile("Is this supposed to be here.ogg");
    music1.openFromFile("FragileCeiling.ogg");
    int opcion = 1;
    menu.loadFromFile("menu.png");
    mn.setTexture(menu);
    b1.loadFromFile("un_jugador.png");
    spb1.setTexture(b1);
    spb1.setPosition(sf::Vector2f(93.f,250.f));
    b2.loadFromFile("dos_jugadores.png");
    spb2.setTexture(b2);
    spb2.setPosition(sf::Vector2f(600.f,250.f));
    b3.loadFromFile("instrucciones.png");
    spb3.setTexture(b3);
    spb3.setPosition(sf::Vector2f(93.f,440.f));
    b4.loadFromFile("salir.png");
    spb4.setTexture(b4);
    spb4.setPosition(sf::Vector2f(610.f,440.f));
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                return;


                if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Numpad1)
                {
                    music1.play();
                    loopUnJugador();
                }
                if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Numpad2)
                {
                    music2.play();
                    loopDosJugadores();
                }
                if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Numpad3)
                {
                    instrucciones();
                }
                if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Numpad4)
                {
                    exit(0);
                }

                if(event.type==sf::Event::MouseMoved){
                 pmouse_x=event.mouseMove.x;
                 pmouse_y=event.mouseMove.y;

                }

            }
            window.clear();
            window.draw(mn);
            window.draw(spb1);
            window.draw(spb2);
            window.draw(spb3);
            window.draw(spb4);
            window.display();
        }
    }


int main(){

mainMenu();

return 0;
}
