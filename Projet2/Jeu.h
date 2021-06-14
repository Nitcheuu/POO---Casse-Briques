#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "Balle.h"
#include "Raquette.h"
#include "Brique.h"
#include <vector>
/// <summary>
/// Classe statique Jeu : Modélise le jeu
/// </summary>
class Jeu
{
public:
	/// <summary>
	/// Permet d'instancier les briques
	/// </summary>
	/// <param name="briques">Vecteur de briques à remplir</param>
	/// <param name="largeurBrique">Largeur des briques</param>
	/// <param name="hauteurBrique">Hauteur des briques</param>
	/// <param name="nbCols">Nombre de colonnes</param>
	/// <param name="nbLignes">Nombre de lignes</param>
	static void InstancierLesBriques(vector<Brique>& briques, int largeurBrique, int hauteurBrique, int nbCols, int nbLignes) {
		int xBrique = 100;
		int yBrique = 100;
		for (int i = 0; i < nbLignes; i++) {
			for (int j = 0; j < nbCols; j++) {
				briques.push_back(Brique(xBrique, yBrique, largeurBrique, hauteurBrique));
				xBrique += largeurBrique;
			}
			xBrique = 100;
			yBrique += hauteurBrique;
		}
	}
	/// <summary>
	/// Afficher les différents éléments sur la fenêtre
	/// </summary>
	/// <param name="window">Fenêtre cible</param>
	/// <param name="balle">Balle</param>
	/// <param name="raquette">Raquette</param>
	/// <param name="briques">Vecteur de briques</param>
	/// <param name="background">Fond d'écran (Sprite)</param>
	static void Dessiner(RenderWindow& window, BalleJeu balle, Raquette raquette, vector<Brique>& briques, Sprite background) {
		window.draw(background);
		window.draw(balle.Me());
		window.draw(raquette.Me());
		for (Brique& brique : briques) {
			window.draw(brique.Me());
		}
	}
	/// <summary>
	/// Fermer la fenêtre
	/// </summary>
	/// <param name="window">Fenêtre à fermer quand le joueur ferme la fenêtre</param>
	static void DetecterFermeture(RenderWindow& window) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}
	}
private:
	/// <summary>
	/// Constructeur par défaut de la classe
	/// </summary>
	Jeu(){}
};

