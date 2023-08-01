#include <SFML/Graphics.hpp>
#include "PongGame.h"

int main()
{
    // Crear una instancia del juego Pong
    PongGame game("Pong", 800, 600);

    // Iniciar el juego
    game.run();
    
    return 0;
}
