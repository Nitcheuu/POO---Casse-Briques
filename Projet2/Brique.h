#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>

#include <list>
#include <random>
using namespace std;
using namespace sf;
/// <summary>
/// Classe brique : Modélise une brique
/// </summary>
class Brique
{
#pragma region Attributs
private:
	/// <summary>
	/// Position x de la brique
	/// </summary>
	int pos_x;
	/// <summary>
	/// Position y de la brique
	/// </summary>
	int pos_y;
	/// <summary>
	/// longueur de la brique
	/// </summary>
	int longueur;
	/// <summary>
	/// hauteur de la brique
	/// </summary>
	int hauteur;
	/// <summary>
	/// Valeur 8bits du rouge
	/// </summary>
	int R;
	/// <summary>
	/// Valeur 8bits du vert
	/// </summary>
	int G;
	/// <summary>
	/// Valeur 8bits du bleu
	/// </summary>
	int B;
	/// <summary>
	/// Rectangle qui modélise la brique
	/// </summary>
	RectangleShape corps;
#pragma endregion
public:
#pragma region Constructeurs
	/// <summary>
	/// Constructeur de la classe Brique
	/// </summary>
	/// <param name="x">Position en x de la brique</param>
	/// <param name="y">Position en y de la brique</param>
	/// <param name="l">Largeur de la brique</param>
	/// <param name="h">Hauteur de la brique</param>
	Brique(int x, int y, int l, int h) {
		pos_x = x;
		pos_y = y;
		longueur = l;
		hauteur = h;
		// Couleur aléatoire
		R = rand() % 256;
		G = rand() % 256;
		B = rand() % 256;
		// Définition du rectangle
		corps.setSize(Vector2f(longueur, hauteur));
		corps.setFillColor(Color(R, G, B));
		corps.setPosition(pos_x, pos_y);
		corps.setOutlineColor(Color(0, 0, 0));
		corps.setOutlineThickness(1);
	}
#pragma endregion
#pragma region Méthodes
	// Destructeur
	~Brique() {
		cout << "Detruit";
	}
	/// <summary>
	/// Retorune le rectangle
	/// </summary>
	/// <returns>RectangleShape corps</returns>
	RectangleShape Me() {
		return corps;
	}
	/// <summary>
	/// Retourne la position X de la brique
	/// </summary>
	/// <returns>int pos_x</returns>
	int Position_X() {
		return pos_x;
	}
	/// <summary>
	/// Retourne la position Y de la brique
	/// </summary>
	/// <returns>int pos_y</returns>
	int Position_Y() {
		return pos_y;
	}
	/// <summary>
	/// Retourne la longueur de la brique
	/// </summary>
	/// <returns>int longueur</returns>
	int LongueurBrique() {
		return longueur;
	}
	/// <summary>
	/// Retourne la hauteur de la brique
	/// </summary>
	/// <returns>int hauteur</returns>
	int HauteurBrique() {
		return hauteur;
	}
#pragma endregion
};

