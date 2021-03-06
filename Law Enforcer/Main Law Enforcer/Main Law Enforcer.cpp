// Main Law Enforcer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../Law Enforcer/Level.h"
#include "../Law Enforcer/global_definitions.h"

int main()
{
    std::cout << "Hello World!\n";
    std::chrono::time_point<std::chrono::system_clock> current_time;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../xml/level.xml");
    if (!result) return EXIT_FAILURE;
    Level level(doc.child("Level"));
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Level");
    sf::Event event;
	window.pollEvent(event);
    while(window.isOpen()) {
        current_time = std::chrono::system_clock::now();
        level.update(event);
        window.clear();
        level.draw(window);
        window.display();
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        std::this_thread::sleep_until(current_time + std::chrono::milliseconds(16));
    }
    return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
