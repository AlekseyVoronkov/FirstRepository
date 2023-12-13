/*********************************************************
* Автор:   Воронков.А.А                                  *
* Дата:    13.12.2023                                    *
* Название: Змейка                                       * 
* https://onlinegdb.com/lUjzHilcY                        *
**********************************************************/
#include <conio.h> 
#include <iostream> 
#include <windows.h>
using namespace std;

COORD c = { 0,0 };

const int width = 40;
const int height = 10;

int snakeHeadX, snakeHeadY, fruitX, fruitY;
int playerScore;
int snakeTailX[100], snakeTailY[100], snakeTailLen;
int plusPoints;

enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

snakesDirection sDir;

bool isGameOver;


void GameInit() {
	isGameOver = false;
	sDir = STOP;
	snakeHeadX = width / 2;
	snakeHeadY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	playerScore = 0;
}


void GameRender(string playerName) {
	system("cls");

	for (int index = 0; index < width + 2; ++index) {
		cout << "-";
	}

	cout << endl;

	for (int index = 0; index < height; ++index) {
		for (int indexJ = 0; indexJ <= width; ++indexJ) {
			if (indexJ == 0 || indexJ == width) {
				cout << "|";
			}

			if (index == snakeHeadY && indexJ == snakeHeadX) {
				cout << "O";
			}

			else if (index == fruitY && indexJ == fruitX) {
				cout << "@";
			}

			else {
				bool printTail = false;
				for (int indexK = 0; indexK < snakeTailLen; ++indexK) {
					if (snakeTailX[indexK] == indexJ && snakeTailY[indexK] == index) {
						cout << "o";
						printTail = true;
					}
				}

				if (!printTail) {
					cout << " ";
				}
			}
		}

		cout << endl;
	}

	for (int index = 0; index < width + 2; ++index) {
		cout << "-";
	}

	cout << endl;
	cout << playerName << "'s Score: " << playerScore << endl;
}


void UpdateGame() {
	int prevX = snakeTailX[0];
	int prevY = snakeTailY[0];
	int prev2X, prev2Y;
	snakeTailX[0] = snakeHeadX;
	snakeTailY[0] = snakeHeadY;

	for (int index = 1; index < snakeTailLen; ++index) {
		prev2X = snakeTailX[index];
		prev2Y = snakeTailY[index];
		snakeTailX[index] = prevX;
		snakeTailY[index] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}


	switch (sDir) {
	case LEFT:
		--snakeHeadX;
		break;
	case RIGHT:
		++snakeHeadX;
		break;
	case UP:
		--snakeHeadY;
		break;
	case DOWN:
		++snakeHeadY;
		break;
	}


	if (snakeHeadX >= width || snakeHeadX < 0 || snakeHeadY >= height || snakeHeadY < 0) {
		isGameOver = true;
	}


	for (int index = 0; index < snakeTailLen; ++index) {
		if (snakeTailX[index] == snakeHeadX && snakeTailY[index] == snakeHeadY) {
			isGameOver = true;
		}
	}


	if (snakeHeadX == fruitX && snakeHeadY == fruitY) {
		playerScore += plusPoints;
		fruitX = rand() % width;
		fruitY = rand() % height;
		++snakeTailLen;
	}
}


int SetDifficulty() {
	int dfc, choice;

	cout << endl << "SET DIFFICULTY:" << endl << "1 - Easy" << endl << "2 - Medium" << endl << "3 - Hard" << endl
		 << "4 - Insane" << endl << "If not chosen or pressed any other key, the difficulty will be automatically set to medium"
		 << endl << "Choose the difficulty: ";
	cin >> choice;

	if (choice == 1) {
		dfc = 150;
		plusPoints = 5;
	}

	if (choice == 2) {
		dfc = 10;
		plusPoints = 10;
	}

	if (choice == 3) {
		dfc = 50;
		plusPoints = 15;
	}

	if (choice == 4) {
		dfc = 1;
		plusPoints = 25;
	}

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		dfc = 100;
		plusPoints = 10;
	}

	return dfc;
}


void UserInput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			sDir = LEFT;
			break;
		case 'd':
			sDir = RIGHT;
			break;
		case 'w':
			sDir = UP;
			break;
		case 's':
			sDir = DOWN;
			break;
		}
	}
}


int main() {
	string playerName;
	int dfc = SetDifficulty();

	cout << "Enter your name: ";
	cin >> playerName;

	GameInit();
	while (!isGameOver) {
		GameRender(playerName);
		UserInput();
		UpdateGame();
		Sleep(dfc);
	}

	return 0;
}
