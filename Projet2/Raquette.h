#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Raquette
{
private:
	int longueur = 75;
	int hauteur = 10;
	int largeurEcran;
	int hauteurEcran;
	int velocite = 5;
	RectangleShape corps;
public:

	int pos_x = 400 - longueur / 2;
	int pos_y = 550;

	Raquette(int l, int h) {
		corps.setSize(Vector2f(longueur, hauteur));
		corps.setFillColor(Color(255, 255, 255));
		corps.setPosition(pos_x, pos_y);
		largeurEcran = l;
		hauteurEcran = h;

	}
	~Raquette() {

	}
	RectangleShape Me() {
		return corps;
	}
	void Deplacement() {
		if (Keyboard::isKeyPressed(Keyboard::Q) && pos_x > 0) {
			pos_x -= velocite;
			corps.move(-velocite, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D) && pos_x < largeurEcran - longueur) {
			pos_x += velocite;
			corps.move(velocite, 0);
		}
	}
	void Update() {
		Deplacement();
	}
};

