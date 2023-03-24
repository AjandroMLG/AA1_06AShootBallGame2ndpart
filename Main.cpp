#include "Player.h"

int randomNumber(int min, int max) {//generador random
	return rand() % (max - min + 1) + min;
}

Ball randomBall()
{
	int a;
	 a = randomNumber(0, 4);

	 switch (a)
	 {
	 case 0:
		 return Ball::BLUE;
		 break;

	 case 1:
		 return Ball::GREEN;
		 break;

	 case 2:
		 return Ball::ORANGE;
		 break;

	 case 3:
		 return Ball::RED;
		 break;

	 case 4:
		 return Ball::YELLOW;
		 break;

	 default:
		 break;
	 }
}

void playerStats(Ball shoot, Player myPlayer, Panel myPanel)
{
	for (int i = 0; i < myPanel.size; i++)
	{
		if (myPlayer.position == i)
		{
			std::cout << "P  ";
		}
		else
			std::cout << "-  ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "Next ball in charger: ";
	switch (shoot)
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
	std::cout << std::endl << "Score: " << myPlayer.score << std::endl;
}


int main()
{
	srand(time(NULL));

	bool gameOver = false;
	int position = 3;

	std::string myName;

	std::cout << "What's your name?" << std::endl;
	std::cin >> myName;

	system("cls");

	Player myPlayer;
	Panel myPanel;
	
	myPlayer.init(myName, position);
	myPanel.init();

	//Game Loop

	while (myPlayer.numberOfBalls > 0)
	{
		system("cls");

		myPanel.printPanel();
		playerStats(myPlayer.myCharger[0], myPlayer, myPanel);

		std::cout << myPlayer.name << ", What's your next move?" << std::endl;
		system("pause");
		if (GetAsyncKeyState(VK_SPACE)) //Da error siempre
		{
			Ball shoot = myPlayer.shoot();
			myPanel.insert(myPlayer.position, shoot);
			int verifier = myPanel.verifier(myPlayer.position, shoot);
			if (verifier != -1)
			{
				myPanel.deleteThree(verifier);
				myPanel.insertThree();
				myPlayer.score += 1;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			myPlayer.position -= 1;
			if (myPlayer.position < 0)
				myPlayer.position += 1;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			myPlayer.position += 1;
			if (myPlayer.position > myPanel.size - 1)
				myPlayer.position -= 1;
		}

	}
}