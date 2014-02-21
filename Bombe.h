
#pragma once

#include <iostream>
#include <string>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

#include"Animation.h"
#include"Carte.h"
 
class Bombe
{
    public:
 
    Bombe();
    Bombe(int degats, int taille, std::string type);
	void poser(RenderWindow &Window, string nomimage, int i, int j,Sprite TableauSprites[10][10], int MapFile[10][10]);
	void exploser(RenderWindow &Window, string nomimage, int i, int j,Sprite TableauSprites[10][10], int MapFile[10][10]);
	int GetDegats() const;

	Animation bombeAnimation;
 
    private:
	
	Image BombeImage;
	Sprite BombeSprite;
	float x, y ;
	string m_type;
	int m_degats;
	int m_taille;
};
 




