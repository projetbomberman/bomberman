
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


#include "Animation.h"




void LoadMap(RenderWindow &Window, string nomimage, int MapFile[10][10], Sprite TableauSprites[10][10],  Sprite Herbe, Sprite Brique1, Sprite Brique2);
void DrawMap(RenderWindow &Window, Sprite TableauSprites[10][10]);

