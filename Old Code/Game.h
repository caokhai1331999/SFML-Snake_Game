#pragma once
#include "Window.h"

class Game
{
    public:
        Game();
        ~Game();

        void HandleInput();
        void Update();
        void Render();

        Window* GetWindow();
        
        sf::Time GetElapsed();
        void RestartClock();

    private:
         void MoveMushroom();
         
         Window m_window;
        sf::Clock m_clock;
        // m_elapsed is time run by
        // it is affected by the cpu power and variate among
        // different pc, So we constraint it by substract it to frame time
        sf::Time m_elapsed = m_clock.getElapsedTime();
        const float frametime = 1.0f/60.0f;

        sf::Texture m_mushroomTexture;
        sf::Sprite m_mushroom;
        sf::Vector2i m_increment;
};