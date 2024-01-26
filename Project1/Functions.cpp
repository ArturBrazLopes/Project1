#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<char>> position;
std::vector<int> v;
char player1 = 'x';
char player2 = 'o';
int pos;

void gridPosition() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "|" << ((i * 3) + j + 1) << "|";
        }
        std::cout << "\n";
    }
}

void resetGrid() {
    position.clear(); 
    for (int i = 0; i < 3; i++) {
        std::vector<char> temp;
        for (int j = 0; j < 3; j++) {
            temp.push_back('_');
        }
        position.push_back(temp);
    }
}

void playerInput(int pos, char p) {
    int rows = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    position[rows][col] = p;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "|" << position[i][j] << "|";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}

int chk(int ck){
	if (v.size() > 0)
	{
		for (int i = 0; i < 100; i++)
		{
			std::vector<int>::iterator it;
			it = std::find(v.begin(), v.end(), ck);
			if (it != v.end())
			{
				std::cout << "\nPlayer already enter value at " << ck << " position please enter another value\n";
				std::cin >> ck;
				
			}
			else
			{
				v.push_back(ck);
				return ck;
				break;
			}
		}
	}
	else
	{
		v.push_back(ck);		
		return ck;
	}	
}


bool chkwin()
{
	for (int i = 0; i < 3; i++)
	{
		if (((position[i][0] == position[i][1]) && (position[i][1] == position[i][2])) && (position[i][0] != '_')) {
			if (position[i][0] == 'x') {
				std::cout << "winner is User1=x\n";
				return true;
			}
			else {
				std::cout << "winner is User2=o\n";
				return true;
			}
		}

		else if (((position[0][i] == position[1][i]) && (position[1][i] == position[2][i])) && (position[0][i] != '_')) {
			if (position[0][i] == 'x') {
				std::cout << "winner is User1=x\n";
				return true;
			}
			else {
				std::cout << "winner is User2=o\n";
				return true;
			}
		}

	}


	if (((position[0][0] == position[1][1]) && (position[1][1] == position[2][2])) && (position[0][0] != '_')) {
		if (position[0][0] == 'x') {
			std::cout << "winner is User1=x\n";
			return true;
		}
		else {
			std::cout << "winner is User2=o\n";
			return true;
		}
	}
	else if (((position[2][0] == position[1][1]) && (position[1][1] == position[0][2])) && (position[2][0] != '_')) {
		if (position[2][0] == 'x') {
			std::cout << "winner is User1=x\n";
			return true;
		}
		else {
			std::cout << "winner is User2=o\n";
			return true;
		}
	}
}


void gamePlay()
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << "Please select position\n";
		gridPosition();
		std::cin >> pos;
		if (i % 2 == 0)
		{
			playerInput(chk(pos), player1);
		}
		else
		{
			playerInput(chk(pos), player2);
		}
		if (chkwin() == true)
		{
			break;
		}
		if (i == 8)
		{
			std::cout << "match tie\n";
		}
	}
}
