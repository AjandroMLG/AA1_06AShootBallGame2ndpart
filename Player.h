#pragma once
#include "Panel.h"

struct Player 
{
	int position = -1;
	std::string name;
	int numberOfBalls = -1;
	int score = -1;
	Ball* myCharger;


	void init(std::string& myName, int& pos)
	{
		position = pos;
		score = 0;
		numberOfBalls = 20;
		name = myName;
		myCharger = new Ball[numberOfBalls] ;
		for (int i = 0; i < numberOfBalls - 1; i++)
		{
			myCharger[i] = randomBall();
		}

	}

	Ball shoot()
	{
		Ball primera = myCharger[0];

		numberOfBalls--;

		for (int i = 0; i < numberOfBalls; i++)
		{
			myCharger[i] = myCharger[i + 1];
		}
		
		Ball* secondCharger = new Ball[numberOfBalls];

		for (int i = 0; i < numberOfBalls; i++)
		{
			secondCharger[i] = myCharger[i];
		}
		
		delete[] myCharger;
		myCharger = secondCharger;

		return primera;
	}
};

