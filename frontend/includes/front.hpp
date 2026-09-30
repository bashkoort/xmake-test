#pragma once

#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Frontend {
public:
    Frontend(sf::RenderWindow* win) {
        main_window = win;
        if (!ImGui::SFML::Init(*main_window)) {
            throw("SFMLLLL");
        }
        return;
    }
    void ProcessEvent(std::optional<sf::Event> ev);
    void UpdateImgui(sf::Clock& delta) {
        ImGui::SFML::Update(*main_window, delta.restart());
    }
    void ActionPause();
    void ActionMain();
    void DrawStatistics();
    void DrawCarriers();
    void DrawBranch();
    void ActionEnd();
    void DrawAll();

private:
    sf::RenderWindow* main_window;
    sf::Color background_color = sf::Color(209, 226, 229);
    bool is_paused = true;
};