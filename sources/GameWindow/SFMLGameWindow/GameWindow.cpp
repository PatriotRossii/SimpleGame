#include "GameWindow.h"

GameWindow::GameWindow(): window(sf::VideoMode(800, 600), "SimpleGame") {
    this->loadResources();

    this->guiBorder = {sf::Vertex(sf::Vector2f(0.0f, 500.0f)), sf::Vertex(sf::Vector2f(800.0f, 500.0f)), sf::Vertex(sf::Vector2f(600.0f, 500.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(800.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 200.0f)), sf::Vertex(sf::Vector2f(600.0f, 0.0f)), sf::Vertex(sf::Vector2f(600.0f, 220.0f)), sf::Vertex(sf::Vector2f(800.0f, 220.0f))};

    inventoryLabel.setFont(font);
    inventoryLabel.setString("Inventory");
    inventoryLabel.setCharacterSize(15);
    inventoryLabel.setFillColor(sf::Color::White);
    inventoryLabel.setPosition(675.0f, 200.0f);
}

GameWindow::~GameWindow() {
}

void GameWindow::drawGUIBorders() {
    window.draw(guiBorder);
}

void GameWindow::drawLabels() {
    window.draw(inventoryLabel);
}

void GameWindow::show() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Num0) {
                    this->game.attackYourselfWithDamageSpell();
                }
            }
        }
        window.clear(sf::Color::Black);

        if(clock.getElapsedTime().asMilliseconds() > 500) {
            this->everyTick();
            clock.restart();
        }
        this->drawGUIBorders();
        this->drawLabels();

        window.display();
    }
}

void GameWindow::loadResources() {
    if(!font.loadFromFile("/home/user/Программирование/SimpleGame/resources/fonts/Cantarell-Regular.otf")) {
        throw std::runtime_error("Can't load font");
    }
}
