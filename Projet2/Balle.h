#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Brique.h"
#include "Raquette.h"
using namespace sf;
using namespace std;
/// <summary>
/// Classe Balle : modélise la balle
/// </summary>
class BalleJeu
{
private:
#pragma region Attributs
	/// <summary>
	/// Cercle
	/// </summary>
	CircleShape corps;
	/// <summary>
	/// coefficient auquel on multiplie la vélocité
	/// pour se déplacer vers une certaine direction
	/// sur l'axe des x
	/// </summary>
	int direction_x = -1;
	/// <summary>
	/// coefficient auquel on multiplie la vélocité
	/// pour se déplacer vers une certaine direction
	/// sur l'axe des y
	/// </summary>
	int direction_y = -1;
	/// <summary>
	/// Postion en x de la balle
	/// </summary>
	int pos_x;
	/// <summary>
	/// Position en y de la balle
	/// </summary>
	int pos_y;
	/// <summary>
	/// Rayon/Taille de la balle
	/// </summary>
	int rayon = 10;
	/// <summary>
	/// Vélocité/vitesse de la balle
	/// </summary>
	int velocite = 5;
	/// <summary>
	/// Permet de savoir quand on arrête le jeu
	/// </summary>
	bool game_over = false;
	/// <summary>
	/// Dirige la balle en fonction des murs et de la raquette
	/// </summary>
	/// <param name="largeurEcran">Largeur de l'écran</param>
	/// <param name="hauteurEcran">Hauteur de l'écran</param>
	/// <param name="raquette">Objet raquette</param>
#pragma endregion
#pragma region Méthodes
	void DirectionMursEtRaquette(int largeurEcran, int hauteurEcran, Raquette raquette) {
		if (pos_x == 0) direction_x = 1;
		else if (pos_y == 0) direction_y = 1;
		else if (pos_x == largeurEcran) direction_x = -1;
		//Game over
		else if (pos_y == hauteurEcran) {
			(*this).~BalleJeu();
			game_over = true;
		}
		else if (pos_y + rayon == raquette.maPositionY() && raquette.maPositionX() <= pos_x && raquette.maPositionX() + raquette.maLongueur() >= pos_x) direction_y = -1;
	}
	/// <summary>
	/// Dirige la balle en fonction d'une liste de briques
	/// </summary>
	/// <param name="briques">Vecteur de briques</param>
	void DirectionBriques(vector<Brique>* briques) {
		int pos = 0;
		for (Brique& brique : *briques) {
			pos++;
			if (pos_y + rayon == brique.Position_Y() && pos_x >= brique.Position_X() && pos_x <= brique.Position_X() + brique.LongueurBrique()) { direction_y = direction_y * -1; brique.~Brique(); briques->erase(briques->begin() + pos - 1); }
			else if (pos_y == brique.Position_Y() + brique.HauteurBrique() && pos_x >= brique.Position_X() && pos_x <= brique.Position_X() + brique.LongueurBrique()) {
				direction_y = direction_y * -1; brique.~Brique();brique.~Brique(); briques->erase(briques->begin() + pos - 1);
			}
			else if (pos_x == brique.Position_X() && pos_y >= brique.Position_Y() && pos_y <= brique.Position_Y() + brique.HauteurBrique()) {
				direction_x = direction_x * -1; brique.~Brique(); briques->erase(briques->begin() + pos - 1);
			}
			else if (pos_x == brique.Position_X() + brique.LongueurBrique() && pos_y >= brique.Position_Y() && pos_y <= brique.Position_Y() + brique.HauteurBrique()) {
				direction_x = direction_x * -1;brique.~Brique(); briques->erase(briques->begin() + pos - 1);
			}
		}
	}
	/// <summary>
	/// Déplace la balle
	/// </summary>
	void Deplacement() {
		pos_x += velocite * direction_x;
		pos_y += velocite * direction_y;
		corps.move(velocite * direction_x, velocite * direction_y);
	}
#pragma endregion
#pragma region Constructeurs

public:
	/// <summary>
	/// Constructeur de la classe Balle
	/// </summary>
	BalleJeu() {
		pos_x = 400;
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
	}
		
#pragma endregion
#pragma region Méthodes
	~BalleJeu() {
	}
	/// <summary>
	/// Retiurne le cercle
	/// </summary>
	CircleShape Me() {
		return corps;
	}
	/// <summary>
	/// Actualisation de la balle
	/// </summary>
	/// <param name="largeurEcran">Largeur de l'écran</param>
	/// <param name="hauteurEcran">Hauteur de l'écran</param>
	/// <param name="raquette">Objet raquette</param>
	/// <param name="briques">Vecteur de briques</param>
	void Update(int largeurEcran, int hauteurEcran, Raquette raquette, vector<Brique>* briques) {
		DirectionMursEtRaquette(largeurEcran, hauteurEcran, raquette);
		DirectionBriques(briques);
		Deplacement();
	}
	/// <summary>
	/// Permet de savoir quand le jeu se termine
	/// </summary>
	bool Game_over() {
		if (!game_over) return false;
		if (game_over) return true;
	}
#pragma endregion
};




