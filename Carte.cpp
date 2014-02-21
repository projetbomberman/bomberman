
#include "Carte.h"
#include"Animation.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


const int BlockSize = 70;
const int BlockSize2 = 48;

Image image;


	void LoadMap(RenderWindow &Window, string nomimage, int MapFile[10][10], Sprite TableauSprites[10][10], Sprite Herbe, Sprite Brique1, Sprite Brique2)	
	{
		for (int i=0; i<10; i++)
		{
			MapFile[i][0]=2;
			MapFile[i][9]=2;
		}
		for (int i=0; i<10; i++)
		{
			MapFile[0][i]=2;
			MapFile[9][i]=2;
		}

			MapFile[5][6]=1;
			MapFile[7][3]=1;
			MapFile[5][2]=1;
			MapFile[1][6]=1;
			MapFile[8][6]=1;
			MapFile[7][7]=1;
			MapFile[2][2]=1;

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
						TableauSprites[i][j]=Herbe;
						TableauSprites[i][j].SetPosition(i*BlockSize2, j*BlockSize2);
						
						

					}
					else if(MapFile[i][j] == 1)
					{
						TableauSprites[i][j]=Brique1;
						TableauSprites[i][j].SetPosition(i*BlockSize2, j*BlockSize2);
						
						
					}
					else if(MapFile[i][j] == 2)
					{	
						TableauSprites[i][j]=Brique2;
						TableauSprites[i][j].SetPosition(i*BlockSize2, j*BlockSize2);
						
						
					}
				}
			}
		}
	}

void DrawMap(RenderWindow &Window,  Sprite TableauSprites[10][10])
{
	for(int i=0; i<10; i++)	
			{		
				for(int j=0; j<10; j++)
				{
					Window.Draw(TableauSprites[i][j]);
				}
			}
}
