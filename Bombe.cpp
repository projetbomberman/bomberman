
#include "Bombe.h"
#include"Carte.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

const int BlockSize=70;
const int BlockSize2=48;
 
Bombe::Bombe() : m_degats(10), m_taille(1), m_type("type 1")
{
 
}
 
Bombe::Bombe(int degats, int taille, string type) : m_degats(degats), m_taille(taille), m_type(type)
{
 
}


Image image2;


void Bombe::poser(RenderWindow &Window, string nomimage, int i, int j, Sprite TableauSprites[10][10], int MapFile[10][10] ) 
{
	if(!image2.LoadFromFile(nomimage))
		{
			cout << "Erreur chargement image" << endl;
		}

		else
		{	
			//ici on pose la bombe:
			Sprite Bombe;
			Bombe.SetImage(image2);
			Bombe.SetSubRect(IntRect(BlockSize , BlockSize, 2*BlockSize, 2*BlockSize)); 
			Bombe.Resize(BlockSize2,BlockSize2);
			TableauSprites[i][j]=Bombe;
			TableauSprites[i][j].SetPosition(i*BlockSize2, j*BlockSize2);
			DrawMap(Window, TableauSprites);
	}
}

void Bombe::exploser(RenderWindow &Window, string nomimage, int i, int j, Sprite TableauSprites[10][10], int MapFile[10][10] ) 
{
	if(!image2.LoadFromFile(nomimage))
		{
			cout << "Erreur chargement image" << endl;
		}

		else
		{	

// elle va maintenant détruire ce qui l'entoure:
			
					Sprite Casse;
					Casse.SetImage(image2);
					Casse.SetSubRect(IntRect(2*BlockSize , 2*BlockSize, 3*BlockSize, 3*BlockSize)); 
					Casse.Resize(BlockSize2,BlockSize2);

					TableauSprites[i+1][j]=Casse;
					TableauSprites[i+1][j].SetPosition((i+1)*BlockSize2, j*BlockSize2);


					TableauSprites[i-1][j]=Casse;
					TableauSprites[i-1][j].SetPosition((i-1)*BlockSize2, j*BlockSize2);


					TableauSprites[i][j+1]=Casse;
					TableauSprites[i][j+1].SetPosition(i*BlockSize2, (j+1)*BlockSize2);


					TableauSprites[i][j-1]=Casse;
					TableauSprites[i][j-1].SetPosition(i*BlockSize2, (j-1)*BlockSize2);


					DrawMap(Window, TableauSprites);

// puis les briques vont disparaître: 

			/*Clock clockbombe;
			float elapsedtime2=0;

			while (elapsedtime2<50*Window.GetFrameTime())
			{
				elapsedtime2=clockbombe.GetElapsedTime()+Window.GetFrameTime();
			}

			if (elapsedtime2 >= 50* Window.GetFrameTime())
			{
				Sprite Herbe;
				Herbe.SetImage(image2);
				Herbe.SetSubRect(IntRect(2*BlockSize , 0, 3*BlockSize, BlockSize)); 
				Herbe.Resize(BlockSize2,BlockSize2);

				TableauSprites[i][j]=Herbe;
				TableauSprites[i][j].SetPosition(i*BlockSize2, j*BlockSize2);
				MapFile[i][j]=0;


				TableauSprites[i+1][j]=Herbe;
				TableauSprites[i+1][j].SetPosition((i+1)*BlockSize2, j*BlockSize2);
				MapFile[i+1][j]=0;

				TableauSprites[i-1][j]=Herbe;
				TableauSprites[i][j].SetPosition((i-1)*BlockSize2, j*BlockSize2);
				MapFile[i-1][j]=0;

				TableauSprites[i][j+1]=Herbe;
				TableauSprites[i][j+1].SetPosition(i*BlockSize2, (j+1)*BlockSize2);
				MapFile[i][j+1]=0;

				TableauSprites[i][j-1]=Herbe;
				TableauSprites[i][j-1].SetPosition(i*BlockSize2, (j-1)*BlockSize2);
				MapFile[i][j-1]=0;

				DrawMap(Window, TableauSprites);
			}

			clockbombe.Reset();*/
	}
}



int Bombe::GetDegats() const
{
	return m_degats;
}





