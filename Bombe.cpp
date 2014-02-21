#include "Bombe.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

const int BlockSize=70;
const int BlockSize2=48;
 
Bombe::Bombe() : m_degats(10), m_taille(1), m_type("type 1")
{
 
}
 
Bombe::Bombe(int degats, int taille, string type) : m_degats(degats), m_taille(taille), m_type(type)
{
 
}

void Bombe::LoadContent()
{	
	if (BombeImage.LoadFromFile("spritesbomberman.png"))
		BombeSprite.SetImage(BombeImage);
		BombeSprite.SetSubRect(IntRect(BlockSize,BlockSize,2*BlockSize,2*BlockSize));
		BombeSprite.SetScale(48/70,48/70);

}
 
Sprite Bombe::GetSprite()
{
	return BombeSprite;
}

void Bombe::exploser(int taille, int degats, string type)
{
	
}

 
void Bombe::afficher() const
{
	cout << "Bombe : " << m_type << " (Degats : " << m_degats << ", Taille : " << m_taille << " ) " << endl;
}

int Bombe::GetDegats() const
{
	return m_degats;
}
