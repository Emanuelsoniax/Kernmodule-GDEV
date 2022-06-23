#include "GameManager.h"
#include "Player.h"
#include "Car.h"


using namespace sf;

GameManager::GameManager() {

    player = new Player(windowWidth / 2, windowHeight - 140);

    if (!backgroundText.loadFromFile("assets/Achtergrond.png")) {
        cout << "Could not load texture" << endl;
        return;
    }
    background.setTexture(backgroundText);
}

void GameManager::Start()
{
    InitializeGame();
    //SpawnCars();
}

void GameManager::Update(float dt)
{
    Event event;
    while (GetWindow().pollEvent(event)) {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player->moveLeft(dt);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player->moveRight(dt);
        }
        else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            GetWindow().close();
        }

        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Left) {
                player->rigidbody->sidewaysForce = player->rigidbody->AddForce(player->rigidbody->sidewaysForce, 1) * dt;
                if (player->rigidbody->sidewaysForce <= 0) {
                    player->rigidbody->sidewaysForce = 0;
                }
            }
            if (event.key.code == sf::Keyboard::Right) {
                player->rigidbody->sidewaysForce = player->rigidbody->AddForce(player->rigidbody->sidewaysForce, -1) * dt;
                if (player->rigidbody->sidewaysForce <= 0) {
                    player->rigidbody->sidewaysForce = 0;
                }
            }
        }
    }

    if (KeepPlaying()) {
        player->update(dt);
        ManageCars(dt);
        ScrollingBackground();
        Draw();
    }
    if(!KeepPlaying()) {
        DisplayEndScreen();
    }

}

void GameManager::Draw()
{
    GetWindow().clear(Color(26, 128, 182, 255));

    window.draw(background);
    DrawEntities();
    DisplayScore();

    GetWindow().display();
}

void GameManager::InitializeGame()
{
    window.create(VideoMode(windowWidth, windowHeight), "Kernmodule GDEV");
    background.setPosition(0, -windowHeight);
}

RenderWindow& GameManager::GetWindow()
{
    return window;
}


void GameManager::ScrollingBackground()
{
    Vector2D backgroundPosition = Vector2D(background.getPosition().x, background.getPosition().y);
    player->rigidbody->forwardsForce = player->rigidbody->AddForce(player->rigidbody->forwardsForce, multiplier);
    backgroundPosition.y += player->rigidbody->CalculateVelocity(player->rigidbody->yVelocity, player->rigidbody->mass, player->rigidbody->forwardsForce, dt);
    background.setPosition(Vector2f(backgroundPosition.x, backgroundPosition.y));
    if (backgroundPosition.y >= 0) {
        background.setPosition(0, -windowHeight);
    }
}

void GameManager::DrawEntities()
{
    window.draw(player->getShape());

    for (int i = 0; i < cars.size(); i++) {
        window.draw(cars[i]->getShape());
    }
}

void GameManager::SpawnCars()
{
     Car* car = new Car(70 + multiplier);
     cars.push_back(car);
}

void GameManager::ManageCars(float dt)
{
    float amountofCars = 1;
    while (cars.size() < amountofCars) {
        SpawnCars();
    }

    for (int i = 0; i < cars.size(); i++) {
        cars[i]->update(dt);
        if (cars[i]->getPosition().top > windowHeight) {
            UpdateMultiplier();
            score++;
            DeleteCar(cars[i]);
            return;
        }

        if (cars[i]->getPosition().Intersection(player->getPosition())) {
            lives--;
            DeleteCar(cars[i]);
            return;
        }
    }
}

void GameManager::DeleteCar(Car* cartoRemove) {
    cars.erase(remove(cars.begin(), cars.end(), cartoRemove), cars.end());
}

void GameManager::UpdateMultiplier() {
    multiplier = multiplier * 1.5f;
}

bool GameManager::KeepPlaying()
{
    if (lives <= 0) {
        return false;
    }
    
    return true;
}

void GameManager::DisplayEndScreen()
{
    GetWindow().clear(Color::Black);
    Font font;
    if (!font.loadFromFile("assets/pixel.ttf"))
    {
        cout << "Could not load font" << endl;
        return;
    }
    Text gameoverText;
    gameoverText.setFont(font);
    gameoverText.setOrigin(175, 75 / 2);
    gameoverText.setPosition(Vector2f((windowWidth/2) -30, (windowHeight/2)-75));
    gameoverText.setCharacterSize(75);
    gameoverText.setFillColor(sf::Color::Red);
    gameoverText.setString("GAME OVER");

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setOrigin(175, 75 / 2);
    scoreText.setPosition(Vector2f((windowWidth / 2) - 30, (windowHeight / 2)));
    scoreText.setCharacterSize(75);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setString("end score: "+ to_string(score));

    window.draw(scoreText);
    window.draw(gameoverText);
    GetWindow().display();
}

void GameManager::DisplayScore()
{
    RectangleShape bg;
    bg.setFillColor(Color::White);
    bg.setSize(Vector2f(windowWidth, 60));
    
    Font font;
    if (!font.loadFromFile("assets/pixel.ttf"))
    {
        cout << "Could not load font" << endl;
        return;
    }
    Text livesText;
    livesText.setFont(font);
    livesText.setCharacterSize(50);
    livesText.setPosition(20, 0);
    livesText.setFillColor(sf::Color::Black);
    livesText.setString("lives: " + to_string(lives));

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setPosition(480, 0);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setString("score: " + to_string(score));
   
    window.draw(bg);
    window.draw(livesText);
    window.draw(scoreText);
}



