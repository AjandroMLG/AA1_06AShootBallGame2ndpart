#include "Ball.h"
#pragma once

int randomNumber(int min, int max);

struct Panel {

	Ball* panel;
	int size;

	void init() {
		std::cout << "Which is the length of the panel?" << std::endl;
		std::cin >> size;
		std::cout << std::endl;

		panel = new Ball[size];

		for (int i = 0; i < size; i++)
		{
			panel[i] = randomBall();
			
			if (i >= 2 && panel[i] == panel[i - 1] && panel[i] == panel[i - 2])
				i--;
		}
	}
	

	void insert(int position, Ball ball)
	{
		size++;
		for (int i = size; i > position; i--)
		{
			panel[i] = panel[i - 1];
		}
		panel[position] = ball;
	}

	int verifier(int position, Ball ball)
	{
		int first = position;
		int counter = 0;

		/*if (position == 1)
			position += 1;
		//Cutre 
		else if (position == 0)
			position += 2;

		if (ball == panel[position - 1]) {
			a++;
			first = position - 1;
			if (ball == panel[position - 2]) {
				a++;
				first = position - 2;
			}
		}
		else
			first = position; xd

		if (ball == panel[position + 1]) {
			a++;
			if (ball == panel[position + 2] )
				a++;
		}

		if (a == 3)
			return first;
		else
			return -1;*/

		if (position <= size - 2) 
		{
			for (int i = position - 2; i <= position + 1; i++)
			{
				if (i < first && panel[i] == ball)
				{
					first = i;
				}
				if (panel[i] == ball && panel[i] == panel[i + 1])
				{
					counter++;
				}
			}
			if (counter == 2)
			{
				return first;
			}
			else
			{
				return -1;
			}
		}

		else
		{
			for (int i = position - 2; i <= size - 1; i++)
			{
				if (i < first && panel[i] == ball)
				{
					first = i;
				}
				if (panel[i] == ball && panel[i] == panel[i + 1])
				{
					counter++;
				}
			}
			if (counter >= 2)
			{
				return first;
			}
			else
			{
				return -1;
			}
		}


	}

	void deleteThree(int position)
	{
		size -= 3;

		Ball* newPanel = new Ball[size];

		for (int i = 0; i < 3; i++)
		{
			panel[position + i] = panel[position + i + 3];
		}

		for (int i = 0; i < size; i++)
		{
			newPanel[i] = panel[i];
		}

		//delete[] panel; el delete explotaba por todos lados :(
		panel = nullptr;
		panel = newPanel;
	}

	void insertThree()
	{
		Ball* newPanel = new Ball[size + 3];

		for (int i = 0; i < size; i++)
		{
			newPanel[i] = panel[i];
		}
		
		for (int i = size + 1; i < size + 3; i++)
		{
			newPanel[i] = randomBall();
		}
		//delete[] panel;
		panel = nullptr;
		panel = newPanel;
		size += 3;
	}
	
	void printPanel()
	{
		std::cout << "Panel[" << size << "]:" << std::endl;


		for (int i = 0; i < size; i++)
		{
			switch (panel[i])
			{
			case Ball::BLUE:
				std::cout << "B  ";
				break;
			case Ball::GREEN:
				std::cout << "G  ";
				break;
			case Ball::ORANGE:
				std::cout << "O  ";
				break;
			case Ball::RED:
				std::cout << "R  ";
				break;
			case Ball::YELLOW:
				std::cout << "Y  ";
				break;
			}
		}

		std::cout << std::endl << std::endl << std::endl << std::endl;
	}
};