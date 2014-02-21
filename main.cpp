#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

#include "Objet.h"
#include "Carte.h"
#include "Player.h"

int MapFile[10][10];


int main()
{
	RenderWindow Window(VideoMode(480, 480, 32), "Map Bomberban");


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

		Player player;
		player.Initialize();
		player.LoadContent();

		while(Window.IsOpened())
		{
			Event Event;
			while(Window.GetEvent(Event))
			{
				if(Event.Type == Event::Closed || Event.Key.Code == Key::Escape)
					Window.Close();
			}

			player.Update(Window, player, MapFile);
			player.Draw(Window);
			Window.Display();

			Window.Clear();
			DrawMap(Window, "spritesbomberman.png", MapFile);
			player.poserBombe(Window, player,MapFile);
		}

	return 0;
}
