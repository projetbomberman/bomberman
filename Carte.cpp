#include "Carte.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Objet.h"

const int BlockSize = 70;
const int BlockSize2 = 48;

	Image image;
	

	int loadCounterX=0;
	int loadCounterY=0;
	
	Sprite TableauSprites[10][10];
	Sprite Herbe, Brique1, Brique2;

	//int MapSizeX;
	//int MapSizeY;

	void LoadMap(const char *grille, int MapFile[10][10])
	{
		ifstream openfile(grille);
		if (openfile.is_open())
		{
			//openfile >> MapSizeX >> MapSizeY;
			string line;
			while(!openfile.eof())
			{
				getline(openfile,line);//>> MapFile[loadCounterX][loadCounterY];
				loadCounterX++;
				if(loadCounterX>= 10)
				{
					loadCounterX=0;
					loadCounterY++;
				}
				
			}
		}
	}

	void DrawMap(RenderWindow &Window, string nomimage, int MapFile[10][10])	
	{

		if(!image.LoadFromFile(nomimage))
		{
			cout << "Erreur chargement image" << endl;
		}

		else
		{
			Herbe.SetImage(image);
			Brique1.SetImage(image);
			Brique2.SetImage(image);
			Herbe.SetSubRect(IntRect(2*BlockSize,0,2*BlockSize+BlockSize2,BlockSize2));
			Brique1.SetSubRect(IntRect(0,0,BlockSize2,BlockSize2));
			Brique2.SetSubRect(IntRect(BlockSize , 0, BlockSize+BlockSize2, BlockSize2));


			for(int i=0; i<10; i++)	
			{		
				for(int j=0; j<10; j++)
				{
					if(MapFile[i][j] == 0)
					{

						Herbe.SetPosition(i*BlockSize2, j*BlockSize2);
						Window.Draw(Herbe);
						TableauSprites[i][j]=Herbe;

					}
					else if(MapFile[i][j] == 1)
					{
						Brique1.SetPosition(i*BlockSize2, j*BlockSize2);
						Window.Draw(Brique1);
						TableauSprites[i][j]=Brique1;
					}
					else if(MapFile[i][j] == 2)
					{
						Brique2.SetPosition(i*BlockSize2, j*BlockSize2);
						Window.Draw(Brique2);
						TableauSprites[i][j]=Brique2;

					}
				}
			}
		}
	}

