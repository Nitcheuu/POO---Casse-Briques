#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class BalleJeu
{
private:
	CircleShape corps;
	int direction;
	int direction_x = -1;
	int direction_y = -1;
	int hauteurEcran;
	int largeurEcran;
	int pos_x;
	int pos_y;
	int rayon = 10;
	int velocite = 5;
public:
	BalleJeu(int h, int l) {
		hauteurEcran = h;
		largeurEcran = l;
		pos_x = largeurEcran / 2 - rayon;
		pos_y = 520;
		// Couleur de remplissage
		corps.setFillColor(Color(255, 0, 0));
		// Rayon
		corps.setRadius(rayon);
		// Position
		corps.setPosition(pos_x - rayon, pos_y);
		// couleur des contours
		corps.setOutlineColor(Color(0, 0, 0));
		// taille des contours
		corps.setOutlineThickness(1);
		// direction par défaut nord-ouest
		direction = 0;
	}
	~BalleJeu() {
		/*delete(this);*/
	}
	CircleShape Me() {
		return corps;
	}
	void Direction(int coos_x_raquette, int coos_y_raquette) {
		if (pos_x == 0) direction_x = 1;
		else if (pos_y == 0) direction_y = 1;
		else if (pos_x == largeurEcran) direction_x = -1;
		else if (pos_y == hauteurEcran) direction_y = -1;
		else if (pos_y + rayon == coos_y_raquette &&  coos_x_raquette <= pos_x && coos_x_raquette + 75 >= pos_x) direction_y = -1;
	}
	void Deplacement() {
		pos_x += velocite * direction_x;
		pos_y += velocite * direction_y;
		corps.move(velocite * direction_x, velocite * direction_y);
	}
	void Update(int coos_x_raquette, int coos_y_raquette) {
		Direction(coos_x_raquette, coos_y_raquette);
		Deplacement();
	};
};




