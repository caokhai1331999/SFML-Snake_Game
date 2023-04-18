#include "Game.h"

Game::Game():m_window("Chapter 2", sf::Vector2u(800,600))
{
    RestartClock();
    srand(time(NULL));

    //Setting up class members
    m_mushroomTexture.loadFromFile("Media/Textures/Mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_increment = sf::Vector2i(200,200);
}

Game::~Game(){}

sf::Time Game::GetElapsed() {return m_elapsed;}
void Game::RestartClock(){m_elapsed += m_clock.restart();}
Window*Game::GetWindow(){return &m_window;}

void Game::MoveMushroom()
{
    sf::Vector2u windSize = m_window.GetWindowSize();
    sf::Vector2u textSize = m_mushroomTexture.getSize();
    
    if ((m_mushroom.getPosition().x > (windSize.x - textSize.x) && m_increment.x > 0) ||
    (m_mushroom.getPosition().x < 0 && m_increment.x < 0))
    {
        m_increment.x = -m_increment.x;
    }

    if ((m_mushroom.getPosition().y > (windSize.y - textSize.y) && m_increment.y > 0) ||
    (m_mushroom.getPosition().y < 0 && m_increment.y < 0))
    {
        m_increment.y = -m_increment.y;
    }

    m_mushroom.setPosition(
        m_mushroom.getPosition().x + m_increment.x*m_elapsed.asSeconds(),
        m_mushroom.getPosition().y + m_increment.y*m_elapsed.asSeconds());

        // whenever real-time running of a frame exceed 1/60 s
        // We substract it to 1/60 s to reset the cycle
        if (m_elapsed.asSeconds()>=Game::frametime)
        {
            // To get elapese time back to 60 frame per second
            m_elapsed -= sf::seconds(frametime);
        }
}

void Game::Update()
{
    m_window.Update();
    MoveMushroom();
}

void Game::Render()
{
    m_window.BeginDraw();//Begin Draw
    m_window.Draw(m_mushroom);
    m_window.EndDraw();//Clear
}

void Game::HandleInput()
{
    //input handle
}