#include <SFML/Graphics.hpp>
#include <iostream>
#include "Balle.h"
#include "Raquette.h"


using namespace sf;
using namespace std;

int hauteur = 600;
int largeur = 800;

BalleJeu balle = BalleJeu(hauteur, largeur);
Raquette raquette = Raquette(largeur, hauteur);

int main() {
	cout << "Lancement du jeu" << endl;
	RenderWindow window(VideoMode(largeur, hauteur), "Jeu");
	window.setFramerateLimit(60);
	
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			
			if (e.type == Event::Closed) {
				window.close();
			}

		}
		window.draw(balle.Me());
		window.draw(raquette.Me());
		raquette.Update();
		balle.Update(raquette.pos_x, raquette.pos_y);
		//Afficher ce qui se trouve dans la fenêtre
		window.display();
		// Raffraichir la fenêtre
		window.clear();
	}

	return 0;
}