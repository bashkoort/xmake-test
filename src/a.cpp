//#include"../frontend/includes/front.hpp"
#include <SFML/System/Clock.hpp>
#include <vector>
#include "branch.hpp"
#include "carrier.hpp"
#include"manager.hpp"
#include"generator.hpp"
#include<iostream>

int main() {

    sf::Clock deltaClock;
    Generator gen;
    std::vector<TMP_Letter> arr = gen.generate_letters(10);
    std::vector<std::vector<int>> g(10, std::vector<int>(10, 20));
    Manager manager(10, 5, g);
    
    int all = 0;
    int i = 0;
    while(all < 500) {
        all++;
        manager.Update(1);
        if (i < arr.size() && arr[i].time_start_branch == all) {
            manager.GetLetter(arr[i]);
            ++i;
        }
        manager.Check();
        std::vector<BranchView> br;
        std::vector<CarrierView> car;
        br = manager.GetBranchesView();
        car = manager.GetCarrierView();
        std::cout << "GLOBAL_TIME:" << ' ' << all << "\n\n";
        // for (auto& x : br) {
        //     if (x.start_letters.size() + x.end_letters.size() == 0) continue;
        //     std::cout << x << '\n';
        // } 
        for (auto& x : car) {
            if (x.current_letters.size() > 0) {
                 std::cout << x << '\n';
            }
        }
        std::cout << "\n\n";

    }


    // sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Carriers model");
    // window.setFramerateLimit(60);
    // Frontend frontend(&window);
    // sf::Clock deltaClock;
    // //Scene1

    // while (window.isOpen()) {
    //     while (const auto event = window.pollEvent()) {
    //         frontend.ProcessEvent(event);
    //     }
    //     frontend.UpdateImgui(deltaClock);
       
    //     frontend.DrawAll();
    // }

    // ImGui::SFML::Shutdown();
}