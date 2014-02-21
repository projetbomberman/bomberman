

//int main()
//{
	//Personnage Madjer(100, 10,2,"type1");
	//Madjer.afficherEtat();
//}
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

#include "Carte.h"
#include "Player.h"

int MapFile[10][10];
Sprite Herbe, Brique1, Brique2;
Sprite TableauSprites[10][10];




int main()
{
	RenderWindow Window(VideoMode(480, 480, 32), "Map Bomberban");



		Player player;
		player.Initialize();
		player.LoadContent();
		LoadMap(Window, "spritesbomberman.png", MapFile, TableauSprites, Herbe, Brique1, Brique2);


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

			DrawMap(Window, TableauSprites);
			player.poserBombe(Window, "spritesbomberman.png", player, TableauSprites, MapFile);

			
		}

	return 0;
}

