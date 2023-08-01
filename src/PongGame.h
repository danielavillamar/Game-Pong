#pragma once

#include <SFML/Graphics.hpp>

class PongGame
{
public:
    // Constructor que toma el título de la ventana, ancho y alto como argumentos
    PongGame(const std::string& title, int width, int height);

    // Método para ejecutar el juego
    void run();

private:
    // Métodos privados para manejar eventos, actualizar, renderizar y mostrar al ganador
    void handleEvents();
    void update();
    void render();
    void displayWinner(int winningPlayer);

    // Variables y objetos del juego
    sf::RenderWindow window;
    sf::RectangleShape leftPaddle;
    sf::RectangleShape rightPaddle;
    sf::CircleShape ball;

    int playerOneScore;
    int playerTwoScore;

    float ballSpeedX;
    float ballSpeedY;

    bool isRunning;
};
