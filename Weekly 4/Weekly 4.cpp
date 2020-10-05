#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>

void task1();
void task2();
void task3();
void task4();
char ToCapital(char); //converts chars to uppercase
char ToCapital(char ch) {
	return toupper(ch);
}
void printboard(); //pritns status of the game
void move(char); // moves the player
void randgen(); //generates random pos for \\, /, G
void condition(); // check if player has interacted with \\, /, G
void roll(); //rolls fice dices
int countdice(); //counts nr of 6's rolled
void findpair(); //find a pair in the five dice

const int lenght = 10;
const int height = 10;
char board[height][lenght]{
	{'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};
int taskchoise;
char input;
bool run = true;
int posx = 0;
int posy = 0;
struct randompos {
	int rposx;
	int rposy;
}up, down, G;
int dice[5] = { 0, 0, 0, 0, 0 };
int dicehold[5] = { 0, 0, 0, 0, 0 };
int nrof6;

int main()
{
	randgen();
	std::cout << "Choose task 1-4: ";
	std::cin >> taskchoise;
	switch (taskchoise) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		}
}


// Make a function that converts lower case letters to capitals. Use data type char.
void task1() {

	std::string senttoupper;

	std::cout << "Enter something: ";
	std::getline(std::cin, senttoupper); //it skips the code if i do not do this 2 times. i dont know why but this soloution works
	std::getline(std::cin, senttoupper);

	for (int i = 0; i < senttoupper.size(); i++) {
		if (senttoupper.at(i) != ' ')
			senttoupper.at(i) = ToCapital(senttoupper.at(i));
		std::cout << senttoupper.at(i);
	}
}

void task2() {
	while (run == true) {
		printboard();
		char input = _getch();
		move(input);
		condition();
	}
}

void printboard() {
	std::cout << "------------------------------------------" << std::endl;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < lenght; i++) {
			std::cout << " | ";
			std::cout << board[j][i];
			if (i == 9) {
				std::cout << " | " << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

//moves player according to w,a,s,d
void move(char input) {

	board[posy][posx] = ' ';

	switch (input) {
	case 'w': case 'W':
		if (posy != 0){
			posy = posy - 1;
		}
		break;

	case 'a': case 'A':
		if (posx != 0) {
		posx = posx - 1;
		}
		break;

	case 's': case 'S':
		if (posy != 9) {
		posy = posy + 1;
		}
		break;

	case 'd': case 'D':
		if (posx != 9) {
		posx = posx + 1;
		}
		break;
	}

	board[posy][posx] = 'O';

}

//generates random pos for '\\', '/' and 'G'
void randgen() {

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	up.rposx = rand() % 10;
	up.rposy = rand() % 10;
	down.rposx = rand() % 10;
	down.rposy = rand() % 10;
	G.rposx = rand() % 10;
	G.rposy = rand() % 10;

	if ((up.rposx == 0 && up.rposy == 0) || (down.rposx == 0 && down.rposy == 0) || (G.rposx == 0 && G.rposy == 0)) {
		randgen();
	}

	board[up.rposy][up.rposx] = 'U';
	board[down.rposy][down.rposx] = 'D';
	board[G.rposy][G.rposx] = 'G';
}

void condition() {

	if ((posx == up.rposx) && (posy == up.rposy)) {
		move('w');
		board[up.rposy][up.rposx] = 'U';
	}
	else if ((posx == down.rposx) && (posy == down.rposy)) {
		move('s');
		board[down.rposy][down.rposx] = 'D';
	}
	else if ((posx == G.rposx) && (posy == G.rposy)) {
		run = false;
	}
}

void task3() {

	struct person {
		std::string name;
		int phone;
	};
	std::vector<person> plist = {};

}

void task4() {
	int num;
	bool con = true;
	bool rollagain = true;
	char again;
	char conroll;

	do {
		std::cout << "-------------------------------- \n";
		roll();
		std::cout << "-------------------------------- \n";

		std::cout << "Number of 6's: " << countdice() << std::endl;
		do {
			std::cout << "\nDice currently held: \n";
			for (int i = 0; i < sizeof(dicehold) / sizeof(dicehold[0]); i++) {
				if (dicehold[i] != 0) {
					std::cout << "Dice " << i + 1 << ": " << dicehold[i] << std::endl;
				}
			}
			std::cout << "\nDo you want to hold any (more) dice? (Y/N): ";
			std::cin >> again;
			switch (again) {
			case 'Y': case 'y':
				con = true;
				std::cout << "\nWhat dice do you want to hold: ";
				std::cin >> num;
				switch (num) {
				case 1:
					dicehold[0] = dice[num - 1];
					break;
				case 2:
					dicehold[1] = dice[num - 1];
					break;
				case 3:
					dicehold[2] = dice[num - 1];
					break;
				case 4:
					dicehold[3] = dice[num - 1];
					break;
				case 5:
					dicehold[4] = dice[num - 1];
					break;
				}
				break;
			case 'N': case 'n':
				con = false;
				break;
			}
		} while (con == true);
		std::cout << "Do you wanna roll again? (Y/N): ";
		std::cin >> conroll;
		switch (conroll) {
		case 'Y': case 'y':
			rollagain = true;
			break;
		case 'N': case 'n':
			rollagain = false;
			break;
		}
		std::cout << std::endl;
	}while (rollagain == true);
}

void roll() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < sizeof(dice) / sizeof(dice[0]); i++) {
		dice[i] = rand() % 6 + 1;
		std::cout << "Dice " << i + 1 << ": " << dice[i] << std::endl;
	}
	std::cout << std::endl;
}

int countdice() {
	for (int i = 0; i < sizeof(dicehold) / sizeof(dicehold[0]); i++) {
		if (dicehold[i] == 6) {
			nrof6++;
		}
	}
	return nrof6;
}

//void findpair() {
//	for (int i = 0; i < sizeof(dice) / sizeof(dice[0]); i++) {
//		if (dice[i] == )
//	}
//
//
//}