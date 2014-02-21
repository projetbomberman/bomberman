#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

#include "Objet.h"
#include "Animation.h"


void LoadMap(const char *grille, int MapFile[10][10]);
void DrawMap(RenderWindow &Window, string nomimage, int MapFile[10][10]);
