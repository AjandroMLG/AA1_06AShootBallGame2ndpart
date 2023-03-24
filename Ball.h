#include <windows.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#pragma once

#ifndef EJEMPLO_H

#define EJEMPLO_H

enum class Ball
{
	YELLOW,
	RED,
	GREEN,
	BLUE,
	ORANGE
};
#endif // EJEMPLO_H

Ball randomBall();


