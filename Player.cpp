#include "Player.h"
#include<math.h>
#include"Carte.h"
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


void Player::Initialize()
{
	x=y=10;
	moveSpeed = 200;
	currentFrameX = currentFrameY = 0;
	playerAnimation.Initialize(x, y ,4, 4);

}

void Player::LoadContent()
{
	if (playerImage.LoadFromFile("Player.png"))
		playerAnimation.setImage(playerImage);

}

int Player::CaseX()
{	
	return floor((x+16)/48);

}

int Player::CaseY()
{
	return floor((y+24)/48);
}

bool Player::CollDroite(int MapFile[10][10], Player player, float x, float y)
{	
	if ( ((x + 32 >= ( player.CaseX()+1 )*BlockSize2)) && (MapFile[player.CaseX() + 1][player.CaseY()] == 1) )
	{
          return true; 
	}
   else
   {
          return false; 
	}
}

bool Player::CollGauche(int MapFile[10][10], Player player, float x, float y)
{
   if( ((x <= ( player.CaseX())*BlockSize2)) && (MapFile[player.CaseX()-1][player.CaseY()] == 1) )
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
   if( ((y <= ( player.CaseY())*BlockSize2)) && (MapFile[player.CaseX()][player.CaseY()-1] == 1) )
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
   if((y + 48 >= ( player.CaseY()+1)*BlockSize2) && (MapFile[player.CaseX()][player.CaseY()+1] == 1) )
   {
          return true;
   }
   else
   {
          return false; 
   }
}

void Player::Update(RenderWindow &Window, Player player, int MapFile[10][10])
{
	playerAnimation.setActive(true);
	
	if ((Window.GetInput().IsKeyDown(Key::Right)) && (CollDroite(MapFile, player, x, y)==false))
	{
		x+= moveSpeed * Window.GetFrameTime();
		currentFrameY = 2;
	}
	else if((Window.GetInput().IsKeyDown(Key::Left)) && (CollGauche(MapFile, player, x, y)==false))
	{
		x-= moveSpeed * Window.GetFrameTime();
		currentFrameY = 1;
	}
	else if((Window.GetInput().IsKeyDown(Key::Up)) && (CollHaut(MapFile, player, x, y)==false))
	{
		y-= moveSpeed * Window.GetFrameTime();
		currentFrameY = 3;
	}
	else if((Window.GetInput().IsKeyDown(Key::Down)) && (CollBas(MapFile, player, x, y)==false))
	{
		y+= moveSpeed * Window.GetFrameTime();
		currentFrameY = 0;
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

void Player::poserBombe(RenderWindow &Window, Player player, int MapFile[10][10])
{
	//playerAnimation.setActive(true);
	
	if ((Window.GetInput().IsKeyDown(Key::Space)))
	{
		m_bombe.GetSprite().SetPosition(CaseX()*BlockSize2,CaseY()*BlockSize2);
		Sprite sprite =  m_bombe.GetSprite();
		Window.Draw(sprite);
		
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
	m_bombe.afficher();

}


