#include "PongGame.h"
#include <iostream>

PongGame::PongGame(const std::string& title, int width, int height)
    : window(sf::VideoMode(width, height), title),
      leftPaddle(sf::Vector2f(20, 100)),
      rightPaddle(sf::Vector2f(20, 100)),
      ball(10),
      playerOneScore(0),
      playerTwoScore(0),
      ballSpeedX(0.2f),
      ballSpeedY(0.2f),
      isRunning(true)
{
    // Posicionar y dar color a los paddles
    leftPaddle.setPosition(50, height / 2 - 50);
    leftPaddle.setFillColor(sf::Color::White);

    rightPaddle.setPosition(width - 70, height / 2 - 50);
    rightPaddle.setFillColor(sf::Color::White);

    // Posicionar y dar color a la pelota
    ball.setPosition(width / 2, height / 2);
    ball.setFillColor(sf::Color::White);
}

void PongGame::run()
{
    // Bucle principal del juego
    while (isRunning)
    {
        handleEvents();
        update();
        render();
    }
}

void PongGame::handleEvents()
{
    // Manejar eventos del juego
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            isRunning = false;
    }
}

void PongGame::update()
{
    // ... Código para el movimiento de paddles y pelota ...

    if (ball.getPosition().x <= 0 || ball.getPosition().x >= window.getSize().x)
    {
        // Determinar el jugador ganador y mostrar en la consola
        int winningPlayer = (ball.getPosition().x <= 0) ? 2 : 1;
        displayWinner(winningPlayer);

        // Detener el juego cuando hay un ganador
        isRunning = false;
    }
}

void PongGame::displayWinner(int winningPlayer)
{
    // Mostrar mensaje del jugador ganador en la consola
    std::cout << "¡Jugador " << winningPlayer << " gana!" << std::endl;
}

void PongGame::render()
{
    // Limpiar la ventana y dibujar los objetos del juego
    window.clear();
    window.draw(leftPaddle);
    window.draw(rightPaddle);
    window.draw(ball);
    window.display();
}
