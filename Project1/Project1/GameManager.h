#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Car.h"

using namespace sf;
class GameManager
{
	private:
	int windowWidth = 960;
	int windowHeight = 800;
	float multiplier = 10;
	RenderWindow window;
	Sprite background;
	Texture backgroundText;
	Player* player;
	std::vector<Car*> cars;
	int lives = 3;
	int score = 0;

	public:
	float dt;
	GameManager();
	void Start();
	void Update(float dt);
	void Draw();

	void InitializeGame();
	RenderWindow& GetWindow();
	void ScrollingBackground();
	void DrawEntities();
	
	void SpawnCars();
	void ManageCars(float dt);
	void DeleteCar(Car* cartoRemove);
	void UpdateMultiplier();

	bool KeepPlaying();
	void DisplayScore();
	void DisplayEndScreen();
};

