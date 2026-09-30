#include "../includes/front.hpp"
#include <SFML/Window/Event.hpp>

void Frontend::ActionPause()
{
}

void Frontend::ActionMain()
{
}

void Frontend::DrawStatistics()
{
}

void Frontend::DrawCarriers()
{
}

void Frontend::DrawBranch()
{
}

void Frontend::ActionEnd()
{
}

void Frontend::ProcessEvent(std::optional<sf::Event> ev) {
    ImGui::SFML::ProcessEvent(*main_window, *ev);
    if (ev->is<sf::Event::Closed>()) {
      main_window->close();
    }
}

void Frontend::DrawAll() {
   main_window->clear(background_color);
   ImGui::SFML::Render(*main_window);
   main_window->display();
}