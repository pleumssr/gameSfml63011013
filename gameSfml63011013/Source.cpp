#include <SFML/Graphics.hpp>
#include <iostream>
#include"player.h"
#include"projectile.h"
#include"enemy.h"
using namespace std;
//random function
int generateRandom(int max)
{
	int randomNumber = rand();
	int  random = (randomNumber % max) + 1;
	int myRandom = random;
	return myRandom;
}

int main()
{
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	window.setFramerateLimit(500);
	///////////////////////////-----------Set---------////////////////////////////////////////////////////////
	int counter, counter2,counter3;
	sf::Texture textureSprite,textureEnemy;
	textureSprite.loadFromFile("sprite.png");
	textureEnemy.loadFromFile("TextureEnemy.png");
	            //----Class objec player---//
	class player player1;
	
	player1.sprite.setTexture(textureSprite);
	//Projectile   VectorArray 
	vector<projectile>::const_iterator iter;
	vector<projectile> projectileArray;
	          //----Class objec Projectile----//
	class projectile projectile1;
	//Enemy   VectorArray 
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;
	         //----Class objec Enemy----//
	class enemy enemy1;
	enemy1.rect.setPosition(600, 200);
	enemy1.sprite.setTexture(textureEnemy);
	enemyArray.push_back(enemy1);
	


	

	
	/////////////////////////////////-------------Window loop--------------//////////////////////////////////////
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////---------------Clear Screen--------------///////////////////////////////////////
		window.clear();
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();

		//////Projectile collision with Enemy////
		counter=0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					cout << "Collision" << endl;
					enemyArray[counter2].hp--;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
				}
				counter2++;
			}
			counter++;
		}
		//////-------------------------////

		//CHECK Enemy Alive
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].alive == false)
			{
				cout << "alive false" << endl;
				enemyArray.erase(iter4);
				counter = 0;
				break;
			}
			counter++;
		}
		//CHECK DESTROY
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter].destroy == true)
			{
				cout << "destroy" << endl;
				projectileArray.erase(iter);
				break;
			}
			counter++;
		}
		//When press space it'll fire
		if (elapsed1.asSeconds() >= 0.15)
		{
			clock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				projectile1.rect.setPosition(player1.rect.getPosition().x + 40, player1.rect.getPosition().y + 60);
				projectile1.direction = player1.direction;
				projectileArray.push_back(projectile1);
			}
		}
		if (elapsed2.asSeconds() >= 0.1)
		{
			clock2.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				enemy1.rect.setPosition(generateRandom(window.getPosition().x),generateRandom(window.getPosition().y));
				enemyArray.push_back(enemy1);
			}
		}
		//Draw Projectile
		int counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter].update();
			window.draw(projectileArray[counter].rect);
			counter++;
		}
		//Drqw Enemy
		 counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);
			counter++;
		}
		//Update player
		player1.update();
		player1.updateMovement();
		//Draw player
		window.draw(player1.sprite);
		//Update window
		window.display();
	}
	return 0;
}

//Draw vertorarray thing
/*
int counter = 0;
for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
{
	projectileArray[counter].update();
	window.draw(projectileArray[counter].rect);
	counter++;
}
*/