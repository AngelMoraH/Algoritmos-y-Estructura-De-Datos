#include "menu.h"
#include <SFML/Graphics.hpp>
using namespace std;
void Menu(Blockchain *block_coin);

int main()
{
    //Blockchain *block_coin = new Blockchain();
    //Menu(block_coin);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML App");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Agrega tu código de dibujo y actualización aquí
        window.display();
    }
    return 0;
}
