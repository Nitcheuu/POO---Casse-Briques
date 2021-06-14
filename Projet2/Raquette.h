#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
/// <summary>
/// Classe Raquette : modélise une raquette
/// </summary>
class Raquette
{
private:
#pragma region Attributs
	/// <summary>
	/// Hauteur de la raquette
	/// </summary>
	int hauteur = 10;
	/// <summary>
	/// Vélocité/vitesse de la raquette
	/// </summary>
	int velocite = 10;
	/// <summary>
	/// Longueur de la raquette
	/// </summary>
	int longueur = 75;
	/// <summary>
	/// Position en X de la raquette
	/// </summary>
	int pos_x = 400 - longueur / 2;
	/// <summary>
	/// Position en Y de la raquette
	/// </summary>
	int pos_y = 550;
	/// <summary>
	/// Rectangle qui modélise la raquette
	/// </summary>
	RectangleShape corps;
#pragma endregion
	
public:
	
#pragma region Constructeurs
	/// <summary>
	/// Constructeur de la classe Raquette
	/// </summary>
	Raquette() {
		corps.setSize(Vector2f(longueur, hauteur));
		corps.setFillColor(Color(255, 255, 255));
		corps.setPosition(pos_x, pos_y);
	}
#pragma endregion
#pragma region Méthodes
	//Destructeur
	~Raquette() {

	}
	/// <summary>
	/// Retourne le rectangle
	/// </summary>
	/// <returns>RectangleShape corps</returns>
	RectangleShape Me() {
		return corps;
	}
private:
	/// <summary>
	/// Déplace la raquette en fopnction des touches du clavier (Q et D)
	/// </summary>
	/// <param name="largeurEcran"></param>
	void Deplacement(int largeurEcran) {
		if (Keyboard::isKeyPressed(Keyboard::Q) && pos_x > 0) {
			pos_x -= velocite;
			corps.move(-velocite, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D) && pos_x < largeurEcran - longueur) {
			pos_x += velocite;
			corps.move(velocite, 0);
		}
	}
public:
	/// <summary>
	/// Actualise la raquette
	/// </summary>
	/// <param name="largeurEcran">Largeur de l'écran</param>
	void Update(int largeurEcran) {
		Deplacement(largeurEcran);
	}
	/// <summary>
	/// Retourne la longueur de la raquette
	/// </summary>
	/// <returns>int longueur</returns>
	int maLongueur() {
		return longueur;
	}
	/// <summary>
	/// Retourne la position X de la raquette
	/// </summary>
	/// <returns>int pos_x</returns>
	int maPositionX() {
		return pos_x;
	}
	/// <summary>
	/// Retourne la position y de la raquette
	/// </summary>
	/// <returns>int pos_y</returns>
	int maPositionY() {
		return pos_y;
	}
#pragma endregion
};

