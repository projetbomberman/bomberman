#pragma once

#include <iostream>
#include <string>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

 
class Bombe
{
    public:
 
    Bombe();
    Bombe(int degats, int taille, std::string type);
	void LoadContent();
	void exploser(int degats, int taille, std::string type);
    void afficher() const;
	int GetDegats() const;
	Sprite GetSprite();
 
    private:
	
	Image BombeImage;
	Sprite BombeSprite;
	float x, y ;
	string m_type;
	int m_degats;
	int m_taille;

};
 



