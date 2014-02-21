#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "Animation.h"
#include "Bombe.h"


class Player
{
public:
	Player(void);
	Player(int vie, Bombe m_bombe);
	~Player(void);

	void Initialize();
	void LoadContent();
	void Update(RenderWindow &Window,Player player, int MapFile[10][10]);
	void Draw(RenderWindow &Window);
	int CaseX();
	int CaseY();

	bool CollDroite (int MapFile[10][10], Player player, float x, float y);
	bool CollGauche (int MapFile[10][10], Player player, float x, float y);
	bool CollBas (int MapFile[10][10], Player player, float x, float y);
	bool CollHaut (int MapFile[10][10], Player player, float x, float y);

	void recevoirDegats(int nbDegats);
	void poserBombe(RenderWindow &Window, Player player, int MapFile[10][10]);
	bool estVivant();
	void afficherEtat() const;

	Animation animate/*[4]*/;

protected: 
	Animation playerAnimation;

private:
	Image playerImage;
	float x, y ;
	int currentFrameX, currentFrameY;
	float moveSpeed;
	int m_vie;
	Bombe m_bombe;

};
