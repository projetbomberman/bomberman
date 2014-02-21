#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}


int Animation::getFrameWidth()
{
	return spriteImage.GetImage()->GetWidth() / amountOfFramesX;
}

int Animation::getFrameHeight()
{
	return spriteImage.GetImage()->GetHeight() / amountOfFramesX;
}


bool Animation::getActive()
{
	return active;
}

void Animation::setActive(bool value)
{
	active = value;
}


int Animation::getCurrentFrame(int axis)
{
	if (axis==1)
		return currentFrameX;
	else 
		return currentFrameY;
}

void Animation::setCurrentFrame(int axis, int value)
{
	if (axis==1)
		currentFrameX= value;
	else 
		currentFrameY = value;
}

float Animation::getPosition(int axis)
{
	if (axis==1)
		 return x;
	else 
		return y;
}

void Animation::setPosition(int axis, int value)
{
	if (axis==1)
		 x = value;
	else 
		y = value;
}


void Animation::setImage(Image &tempImage)
{
	spriteImage.SetImage(tempImage);
}


void Animation::Initialize( float x, float y, int FrameX, int FrameY)
{
	frameCounter=0;
	switchFrame = 1;

	active = false;

	this -> x=x;
	this -> y=y;
	this -> amountOfFramesX = FrameX;
	this -> amountOfFramesY = FrameY;
	
}

void Animation::Update(RenderWindow &Window)
{
	if (active)
		frameCounter += Clock.GetElapsedTime();
	else
		frameCounter=0;

	if (frameCounter >= switchFrame)
	{
		frameCounter=0;
		Clock.Reset();
		currentFrameX += getFrameWidth();

		if (currentFrameX >= spriteImage.GetImage()->GetWidth())
			currentFrameX= 0;
	}
	spriteImage.SetSubRect(IntRect(currentFrameX, currentFrameY * getFrameHeight(), currentFrameX + getFrameWidth() , currentFrameY * getFrameHeight() + getFrameHeight()));
	spriteImage.SetPosition(x,y);
}

void Animation::Draw(RenderWindow &Window)
{
	Window.Draw(spriteImage);
}



