#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "Balle.h"
#include "Raquette.h"
#include "Brique.h"
#include "Jeu.h"
#include <vector>

using namespace sf;
using namespace std;

#pragma region Variables
int hauteur = 600;
int largeur = 800;
vector<Brique> briques;
BalleJeu balle = BalleJeu();
Raquette raquette = Raquette();
RenderWindow window(VideoMode(largeur, hauteur), "Casse-Briques");
Texture back;
#pragma endregion

int main() {
	Jeu::InstancierLesBriques(briques, 50, 30, 12, 6);
	back.loadFromFile("../background.jpg");
	Sprite background(back);
	window.setFramerateLimit(60);
	bool run = balle.Game_over();
	while (window.isOpen() && !run) {
		Jeu::Dessiner(window, balle, raquette, briques, background);
		raquette.Update(largeur);
		balle.Update(largeur, hauteur, raquette, &briques);
		//Afficher ce qui se trouve dans la fenêtre
		window.display();
		// Raffraichir la fenêtre
		window.clear();
		Jeu::DetecterFermeture(window);
		run = balle.Game_over();
	}

	return 0;
}