
#include "Player.h"
#include"Carte.h"
#include<math.h>
#include <iostream>
using namespace std;


const int BlockSize2=48;


Player::Player(void) : m_vie(100), m_bombe()
{
}

Player::Player(int vie, Bombe m_bombe) : m_vie(vie)
{
}

Player::~Player(void)
{
}


//Initialise les coordonnées du joeur, sa vitesse, sa position.

void Player::Initialize() 
{
	x=y=BlockSize2;
	moveSpeed = 200;
	currentFrameX = 0;
	currentFrameY = 2;
	playerAnimation.Initialize(x, y ,4, 4);

}

void Player::LoadContent()
{
	if (playerImage.LoadFromFile("Player.png"))
		playerAnimation.setImage(playerImage);

}



// cette fonction renvoie l'abscisse de la case dans laquelle se trouve le joueur.
// On recentre la position du joueur (car la position (x,y) correspond au coin en haut à droite) grâce à la hauteur et à la largeur du Frame.



int Player::CaseX() 
{	
	return floor((x+playerAnimation.getFrameWidth()/2)/BlockSize2);

}

int Player::CaseY()	// de même pour l'ordonnée.
{
	return floor((y+playerAnimation.getFrameHeight()/2)/BlockSize2);
}



//les fonctions suivantes empechent le joueur d'avancer lorsqu'il est face à une brique rouge.
// de la même manière on recentre pour les cotés droit/bas.

bool Player::CollDroite(int MapFile[10][10], Player player, float x, float y) //le joueur se cogne à sa droite
{	
	if ( ((x + playerAnimation.getFrameWidth()>= ( player.CaseX()+1 )*BlockSize2)) && (MapFile[player.CaseX() + 1][player.CaseY()] > 0) )
	{
          return true; 
	}
   else
   {
          return false; 
	}
}

bool Player::CollGauche(int MapFile[10][10], Player player, float x, float y) // le joueur se cogne à sa gauche
{
   if( ((x <= ( player.CaseX())*BlockSize2)) && (MapFile[player.CaseX()-1][player.CaseY()] > 0) )
	{ 
          return true; 
	}
   else
   {
          return false; 
   }
}

bool Player::CollHaut(int MapFile[10][10], Player player, float x, float y)
{
   if( ((y <= ( player.CaseY())*BlockSize2)) && (MapFile[player.CaseX()][player.CaseY()-1]  > 0) )
   {
          return true; 
   }
   else
   {
           return false;
   }
}

bool Player::CollBas(int MapFile[10][10], Player player, float x, float y)
{
   if((y + playerAnimation.getFrameHeight() >= ( player.CaseY()+1)*BlockSize2) && (MapFile[player.CaseX()][player.CaseY()+1] >0) )
   {
          return true;
   }
   else
   {
          return false; 
   }
}



// fonction qui permet au joueur de se déplacer.

void Player::Update(RenderWindow &Window, Player player, int MapFile[10][10]) 
{
	playerAnimation.setActive(true);
	
	if (Window.GetInput().IsKeyDown(Key::Right))
	{	
		currentFrameY = 2;

		if (CollDroite(MapFile, player, x, y)==false)
		{
			x+= moveSpeed * Window.GetFrameTime();
		}
		
	}
	else if(Window.GetInput().IsKeyDown(Key::Left)) 
	{	
		currentFrameY = 1;

		if  (CollGauche(MapFile, player, x, y)==false)
		{
			x-= moveSpeed * Window.GetFrameTime();
		}
		
	}
	else if(Window.GetInput().IsKeyDown(Key::Up))
	{	
		currentFrameY = 3;

		if (CollHaut(MapFile, player, x, y)==false)
		{
		y-= moveSpeed * Window.GetFrameTime();
		}
	}
	else if(Window.GetInput().IsKeyDown(Key::Down)) 
	{
		currentFrameY = 0;

		if (CollBas(MapFile, player, x, y)==false)
		{
		y+= moveSpeed * Window.GetFrameTime();
		}
		
	}
	else 
	playerAnimation.setActive(false);
	playerAnimation.setPosition(1, x);
	playerAnimation.setPosition(2, y);
	playerAnimation.setCurrentFrame(2, currentFrameY);
	playerAnimation.Update(Window);

}

void Player::Draw(RenderWindow &Window)
{
	playerAnimation.Draw(Window);
}

void Player::recevoirDegats(int nbDegats)
{
	m_vie-= nbDegats;

	if (m_vie < 0)
	{
		m_vie = 0;
	}
}



void Player::poserBombe(RenderWindow &Window, string nomimage, Player player, Sprite TableauSprites[10][10], int MapFile[10][10]) // permet au joueur de faire disparaître la brique faceà laquelle il se trouve.
{
	playerAnimation.setActive(true);
	
	if (Window.GetInput().IsKeyDown(Key::Space))
	{	

 		if ((currentFrameY==0) && (CollBas(MapFile, player, x, y)==false))
		{	
			m_bombe.exploser(Window, "spritesbomberman.png", player.CaseX(),player.CaseY()+1, TableauSprites, MapFile); 
		}

		else if ((currentFrameY==1) && (CollGauche(MapFile, player, x, y)==false))
		{	
			m_bombe.exploser(Window, "spritesbomberman.png", player.CaseX()-1,player.CaseY(), TableauSprites, MapFile); 
		}

		else if ((currentFrameY==2) && (CollDroite(MapFile, player, x, y)==false))
		{
			m_bombe.exploser(Window, "spritesbomberman.png", player.CaseX()+1,player.CaseY(), TableauSprites, MapFile); 
		}

		else if ((currentFrameY==3) && (CollHaut(MapFile, player, x, y)==false))
		{
			m_bombe.exploser(Window, "spritesbomberman.png", player.CaseX(),player.CaseY()-1, TableauSprites, MapFile); 
		}

	}
}




bool Player::estVivant()
{
	if ( m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
	}
}
void Player::afficherEtat() const
{
	cout << "Vie : " << m_vie << endl;

}





