
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



void Bombe::exploser(RenderWindow &Window, string nomimage, int i, int j, Sprite TableauSprites[10][10], int MapFile[10][10] ) 
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

// elle va maintenant détruire ce qui l'entoure:
			Clock clock;
			float elapsedtime=0;/*
			float elapsedtime2=0;*/

			while (elapsedtime<0.1)
			{
				elapsedtime=clock.GetElapsedTime()+Window.GetFrameTime();
			}

			if (elapsedtime >= 0.1)
			{

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
			}


// désormais on voudrait que les briques cassées disparaissent et laissent place à de l'herbe.
// de plus elle deviendraient traversables grâce à "MapFile [i][j]=0".
// seulement cela fait bugger le jeu.
// nous vous laissons la deuxieme étape en commentaire (avec float elapsedtime2 au début et la boucle ci-dessous) 
// si vous l'éxécutez vous verrez à peu près à quoi cela aurait pu ressembler (d'abord on affiche la bombe puis les sprites autour changent)



			/*while (elapsedtime2<30*Window.GetFrameTime())
			{
				elapsedtime2=clock.GetElapsedTime()+Window.GetFrameTime();
			}

			if (elapsedtime2>=30*Window.GetFrameTime())
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
				}*/

			clock.Reset();

		}

}




int Bombe::GetDegats() const
{
	return m_degats;
}





