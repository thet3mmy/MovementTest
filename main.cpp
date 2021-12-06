#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(1024,768), "Movement Test");
sf::CircleShape character(25.0f);
sf::RectangleShape box;

sf::Vector2f pos;
sf::Vector2f lpos;

void keyboard() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        pos.x -= 5.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        pos.x += 5.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        pos.y -= 5.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        pos.y += 5.0f;
    }
}

void init() {
    window.setFramerateLimit(30);

    box.setSize(sf::Vector2f(100, 50));
    box.setOutlineColor(sf::Color::Red);
    box.setFillColor(sf::Color::Yellow);
    box.setOutlineThickness(5);
    box.setPosition(500, 250);

    character.setOutlineColor(sf::Color::Red);
    character.setFillColor(sf::Color::White);
    character.setOutlineThickness(5);
    character.setPosition(pos);
}

void update() {
    character.setPosition(pos);
}

void collisions() {
    if(character.getGlobalBounds().intersects(box.getGlobalBounds())) {
        character.setPosition(lpos);
        pos = lpos;
    } else {
        lpos = pos;
    }
}

int main() {
    init();

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                keyboard();
        }

        window.clear();

        update();
        collisions();

        window.draw(box);
        window.draw(character);

        window.display();
    }
}
