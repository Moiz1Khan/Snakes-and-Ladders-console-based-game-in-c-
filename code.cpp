#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<windows.h>

using namespace std;

void menu();
int randomnum();
void move(int[][10], int &, int &, int, int &, bool &, int &);
void move1(int[][10], int &, int &, int, int &, bool &, int &);
void move3(int[][10], int &, int &, int, int &, bool &, int &);
void move4(int[][10], int &, int &, int, int &, bool &, int &);
void plaYer1(char[50], int&, int&, int&, int[4], int[][10], int, bool[], int&, int&, int&, int[]);
void plaYer2(char[50], int&, int&, int&, int[4], int[][10], int, bool[], int&, int&, int&, int[]);
void plaYer3(char[50], int&, int&, int&, int[4], int[][10], int, bool[], int&, int&, int&, int[]);
void plaYer4(char[50], int&, int&, int&, int[4], int[][10], int, bool[], int&, int&, int&, int[]);
void map1(int[][10], int, int&);
void record(int[4]);
void menu1();
void menu();
void menu2SL();
void kill(int&, int&, int&, int&);
void SL(int &);
void menu3();
void snkLD(int &);
void credits();


int main()
{
	ifstream in;
	ifstream record;
	int position1[4];
	char exit = 27; int load[12][40];
	bool turN1[4] = { false };
	const int size = 10; int count = 100; bool end = false; const int size1 = 50;
	int dice, dice1, player1 = 0, temp[4], player2 = 0, player3 = 0, player4 = 0;
	char playeR1[size1], playeR2[size1], playeR3[size1], playeR4[size1];
	int map[size][size]; int position[4];
	menu1();
	menu();
	int num;
	cin >> num;
	char x = _getch();
	while (x != 27)
	{
		switch (num)
		{
		case 1: {

			system("cls");
			system("color 8E");
			cout << "Enter name of Player 1:"; cin.ignore();
			cin.getline(playeR1, size1);
			cout << "Enter name of Player 2:";
			cin.getline(playeR2, size1);
			cout << "Enter name of Player 3:";
			cin.getline(playeR3, size1);
			cout << "Enter name of Player 4:";
			cin.getline(playeR4, size1);
			cout << "\n\n\t\tWelcome to My Game Snake and Ladder\n\n\n";
			cout << "\n\tPress any key to continue...\n";
			x = _getch();
			system("color F5");
			for (int i = 0; i<size; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j<size; j++)
					{
						map[i][j] = count;
						--count;
					}
				}
				else if (i % 2 == 0)
				{
					count -= 11;
					for (int j = 0; j<size; j++)
					{
						map[i][j] = count;
						--count;
					}
				}
				else if (i % 2 != 0)
				{
					count -= 9;
					for (int j = 0; j<size; j++)
					{
						map[i][j] = count;
						++count;
					}
				}
			}
			menu2SL();
			map1(map, size, player4);
			srand(time(0));
			cout << "Start your Game\n";
			while (x != 27)
			{
				plaYer1(playeR1, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer2(playeR2, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer3(playeR3, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer4(playeR4, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				cout << "		Start Next Turn\t\t\tPress any key... \n" << endl;
				x = _getch();
				system("cls");
				map1(map, size, player4);
			}
		}
				break;
		case 2:
		{
			in.open("saveGame.txt");
			for (int i = 0; i<10; i++)
			{
				for (int j = 0; j<10; j++)
				{
					in >> (map[i][j]);
				}
			}
			while (x != 27)
			{
				plaYer1(playeR1, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer2(playeR2, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer3(playeR3, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				plaYer4(playeR4, dice, dice1, player1, temp, map, size, turN1, player2, player3, player4, position);
				cout << "		Start Next Turn\t\t\tPress any key... \n" << endl;
				x = _getch();
				system("cls");
				map1(map, size, player4);
			}
			break;
		}

		case 3:
			record.open("record.txt");
			for (int i = 0; i<4; i++)
			{
				record >> position1[i];
				cout << position1 << endl;
			}
			break;

		case 4:
			credits();
			break;
		case 5: x = _getch(); break;
		default:
			cout << "Enter Correct Key";
		}
		menu();
		cin >> num;
	}
	system("pause");
}
int randomnum()
{
	return rand() % 6 + 1;
}
void map1(int map[][10], int size, int &score)
{
	ofstream save("saveGame.txt");
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
			if (map[i][j] == 102)
			{
				cout << setw(4) << (char)map[i][j]; save << map[i][j] << setw(4);
			}
			else if (map[i][j] == 103)
			{
				cout << setw(4) << (char)map[i][j]; save << map[i][j] << setw(4);
			}
			else if (map[i][j] == 104)
			{
				cout << setw(4) << (char)map[i][j]; save << map[i][j] << setw(4);
			}
			else if (map[i][j] == 105)
			{
				cout << setw(4) << (char)map[i][j]; save << map[i][j];
			}
			else
			{
				cout << setw(4) << map[i][j]; save << map[i][j] << setw(4);
			}
		cout << endl;
		save << "\n";
	}
}
void move(int map[][10], int &dice, int & dice1, int  size, int & player, bool & turN1, int &temp)
{
	int playeR = 102;
	if (turN1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			turN1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			turN1 = true;
		}

	}
	if (turN1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == playeR&&turN1 == true)
			{
				map[i][j] = temp;
			}
		}
	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == player&&turN1 == true)
			{
				temp = map[i][j];
				map[i][j] = playeR;
			}
		}
	}
}
void move1(int map[][10], int &dice, int & dice1, int  size, int & player, bool & turN1, int &temp)
{
	int playeR = 103;
	if (turN1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			turN1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			turN1 = true;
		}

	}
	if (turN1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == playeR&&turN1 == true)
			{

				map[i][j] = temp;
			}
		}
	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == player&&turN1 == true)
			{
				temp = map[i][j];
				map[i][j] = playeR;
			}
		}
	}
}
void move3(int map[][10], int &dice, int & dice1, int  size, int & player, bool & turN1, int & temp)
{
	int playeR = 104;
	if (turN1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			turN1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			turN1 = true;
		}

	}
	if (turN1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == playeR&&turN1 == true)
			{

				map[i][j] = temp;
			}
		}
	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == player&&turN1 == true)
			{
				temp = map[i][j];
				map[i][j] = playeR;
			}
		}
	}
}
void move4(int map[][10], int &dice, int & dice1, int  size, int & player, bool & turN1, int & temp)
{
	int playeR = 105;
	if (turN1 == false)
	{
		if (dice == 6)
		{
			dice = 0;
			turN1 = true;
		}
		else if (dice1 == 6)
		{
			dice1 = 0;
			turN1 = true;
		}

	}
	if (turN1 == true)
	{
		player = player + dice + dice1;

	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == playeR&&turN1 == true)
			{

				map[i][j] = temp;
			}
		}
	}
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (map[i][j] == player&&turN1 == true)
			{
				temp = map[i][j];
				map[i][j] = playeR;
			}
		}
	}
}
void menu1()
{
	system("color 6B");
	cout << "\n\n\t\t........................................................" << endl;
	cout << "\n\n\t\t\t...S"; Sleep(100); cout << "n"; Sleep(100); cout << "a"; Sleep(100); cout << "k"; Sleep(100); cout << "E"; Sleep(100); cout << " &"; Sleep(100); cout << " L"; Sleep(100); cout << "a"; Sleep(100); cout << "d"; Sleep(100); cout << "d"; Sleep(100); cout << "E"; Sleep(100); cout << "r..." << endl;
	cout << "\n\n\t\t........................................................" << endl;
	cout << "\n\n\t\tCredit: H"; Sleep(200); cout << "A"; Sleep(200); cout << "M"; Sleep(200); cout << "Z"; Sleep(200); cout << "A"; Sleep(200); cout << " I"; Sleep(200); cout << "Q"; Sleep(200); cout << "B"; Sleep(200); cout << "A"; Sleep(200); cout << "L";
	cout << "\n\n\n\t\t\tLoading";
	for (int i = 0; i<8; i++)
	{
		Sleep(500);
		cout << ".";

	}

}
void snkLD(int &score)
{
	switch (score)
	{
	case 4:score = 16; break;
	case 19:score = 43; break;
	case 30:score = 86; break;
	case 50:score = 70; break;
	case 82:score = 98; break;
	case 24:score = 7; break;
	case 60:score = 22; break;
	case 75:score = 58; break;
	case 89:score = 69; break;
	case 99:score = 35; break;
	}
}
void menu()
{
	system("cls");
	system("color 7C");
	cout << "\n\n\t\t\tMy SNAKE AND LADDER\n\n";
	cout << "\t\t1.Start New game\n";
	cout << "\t\t2.Continue saved Game\n";
	cout << "\t\t3.Records\n";
	cout << "\t\t4.Credits\n";
}
void menu2SL()
{

	cout << "\n\t\t\t\t\t\t\tLadder Positions are: ";
	cout << "\t\t\t\t\t\t\t\tFrom 4 to 16\n\t\t\t\t\t\t\t19 to 43\n\t\t\t\t\t\t\t30 to 86\n\t\t\t\t\t\t\t50 to 70\n\t\t\t\t\t\t\t82 to 98";
	cout << "\n\t\t\t\t\t\t\tSnakes Position are: ";
	cout << "\n\t\t\t\t\t\t\t24 to 7\n\t\t\t\t\t\t\t60 to 22\n\t\t\t\t\t\t\t75 to 58\n\t\t\t\t\t\t\t89 to 69\n\t\t\t\t\t\t\t99 to 35";

	cout << endl;

}
void SL(int &score)
{
	if (score == 4 || score == 19 || score == 30 || score == 50 || score == 82)
	{
		cout << "Congrats!You got a Ladder\n";
	}
	else if (score == 24 || score == 60 || score == 75 || score == 89 || score == 99)
	{
		cout << "Ooopps!You got a Snake\n";
	}
}
void kill(int &playr1, int& playr2, int& playr3, int& playr4)
{
	if (playr1 == playr2&&playr1 != 100 && playr1 != 0)
	{
		playr2 = 0;
		cout << "You kill Player\n";
	}
	if (playr1 == playr3&&playr1 != 100 && playr1 != 0)
	{
		playr3 = 0;
		cout << "You kill Player\n";
	}
	if (playr1 == playr4&&playr1 != 100 && playr1 != 0)
	{
		playr4 = 0;
		cout << "You kill Player\n";
	}
}
void credits()
{
	system("cls");
	cout << "\n\n\tSnake and Ladder";
	cout << "\n\tThis Game is made by Hamza Iqbal\n";
	cout << "\n\nPress any Key to go back";
	_getch();
}
void plaYer1(char playeR1[50], int& dice, int &dice1, int &player1, int temp[4], int map[][10], int size, bool turN1[4], int &player2, int& player3, int &player4, int position[4])
{
	char x = _getch();
	cout << playeR1 << " Turn:-\t\tPress any key to roll Dices... \n" << endl;
	dice = randomnum();
	dice1 = randomnum();
	x = _getch();
	snkLD(player1);
	menu2SL();
	cout << "Number on dice1: " << dice << endl;
	cout << "Number on dice2: " << dice1 << "\n" << endl;
	while (dice + dice1 == 12)
	{
		move(map, dice, dice1, size, player1, turN1[0], temp[0]);
		map1(map, size, player1);
		x = _getch();
		dice = randomnum();
		dice1 = randomnum();
		snkLD(player1);
		menu2SL();
		cout << "Number on dice1: " << dice << endl;
		cout << "Number on dice2: " << dice1 << "\n" << endl;
	}
	move(map, dice, dice1, size, player1, turN1[0], temp[0]);
	SL(player1);
	if (player1<100)
	{
		cout << playeR1 << " score: " << player1 << endl;
	}
	else  if (player1 == 100 && player2<100 && player3<100 && player4<100)
	{
		cout << playeR1 << ": Congrats. You won the game.You are at 1st Position\n"; position[0] = 1;
	}
	else if (player2 == 100 && player3<100 && player4<100 || player3 == 100 && player2<100 && player4<100 || player4 == 100 && player3<100 && player2<100)
	{
		if (player1 == 100)
		{
			cout << "Congrats, You got Second Position\n"; position[1] = 2;
		}
	}
	else if (player2 == 100 && player3 == 100 && player4<100 || player3 == 100 && player2<100 && player4 == 100 || player4 == 100 && player3 == 100 && player2<100)
	{
		if (player1 == 100)
		{
			cout << "Congrats, You got Third Position\n"; position[2] = 3;
		}
	}
	if (player2 == 100 && player3 == 100 && player4 == 100 && player1<100)
	{
		cout << "Sorry!You lose the Game\n"; position[3] = 4;
	}
	else if (player1>100)
	{
		player1 = player1 - (dice + dice1);
		cout << playeR1 << " score: " << player1 << endl;
	}
	map1(map, size, player1);
	kill(player1, player2, player3, player4);
}
void plaYer2(char playeR2[50], int& dice, int &dice1, int &player1, int temp[4], int map[][10], int size, bool turN1[4], int &player2, int& player3, int &player4, int position[4])
{
	char x = _getch();
	cout << playeR2 << " Turn:- \t\tPress any key to roll Dices...\n" << endl;
	dice = randomnum();
	dice1 = randomnum();
	x = _getch();
	snkLD(player2);
	menu2SL();
	cout << "Number on dice1:   " << dice << endl;
	cout << "Number on dice2:   " << dice1 << "\n" << endl;
	while (dice + dice1 == 12)
	{
		move1(map, dice, dice1, size, player2, turN1[1], temp[1]);
		map1(map, size, player2);
		x = _getch();
		dice = randomnum();
		dice1 = randomnum();
		snkLD(player2);
		menu2SL();
		cout << "Number on dice1: " << dice << endl;
		cout << "Number on dice2: " << dice1 << "\n" << endl;

	}
	move1(map, dice, dice1, size, player2, turN1[1], temp[1]);
	SL(player2);
	if (player2<100)
	{
		cout << playeR2 << " score: " << player2 << endl;
	}
	else  if (player2 == 100 && player1<100 && player3<100 && player4<100)
	{
		cout << playeR2 << ": Congrats. You won the game.You are at 1st Position\n"; position[0] = 1;
	}
	else if (player1 == 100 && player3<100 && player4<100 || player3 == 100 && player1<100 && player4<100 || player4 == 100 && player3<100 && player1<100)
	{
		if (player2 == 100)
		{
			cout << "Congrats, You got Second Position\n"; position[1] = 2;
		}
	}
	else if (player1 == 100 && player3 == 100 && player4<100 || player3 == 100 && player1<100 && player4 == 100 || player4 == 100 && player3 == 100 && player1<100)
	{
		if (player2 == 100)
		{
			cout << "Congrats, You got Third Position\n"; position[2] = 3;
		}
	}
	if (player1 == 100 && player3 == 100 && player4 == 100 && player2<100)
	{
		cout << "Sorry!You lose the Game\n"; position[3] = 4;
	}
	else if (player2>100)
	{
		player2 = player2 - (dice + dice1);
		cout << playeR2 << " score: " << player2 << endl;
	}

	map1(map, size, player2);
	kill(player2, player1, player3, player4);
}
void plaYer3(char playeR3[50], int& dice, int &dice1, int &player1, int temp[4], int map[][10], int size, bool turN1[4], int &player2, int& player3, int &player4, int position[4])
{
	char x = _getch();
	cout << playeR3 << " Turn:- \t\tPress any key to roll Dices...\n" << endl;
	dice = randomnum();
	dice1 = randomnum();
	x = _getch();
	snkLD(player3);
	menu2SL();
	cout << "Number on dice1:   " << dice << endl;
	cout << "Number on dice2:   " << dice1 << "\n" << endl;
	while (dice + dice1 == 12)
	{
		move3(map, dice, dice1, size, player3, turN1[2], temp[2]);
		map1(map, size, player3);
		x = _getch();
		dice = randomnum();
		dice1 = randomnum();
		snkLD(player3);
		menu2SL();
		cout << "Number on dice1: " << dice << endl;
		cout << "Number on dice2: " << dice1 << "\n" << endl;

	}
	move3(map, dice, dice1, size, player3, turN1[2], temp[2]);
	SL(player3);
	if (player3<100)
	{
		cout << playeR3 << " score: " << player3 << endl;
	}
	else  if (player3 == 100 && player2<100 && player1<100 && player4<100)
	{
		cout << playeR3 << ": Congrats. You won the game.You are at 1st Position\n"; position[0] = 1;
	}
	else if (player2 == 100 && player1<100 && player4<100 || player1 == 100 && player2<100 && player4<100 || player4 == 100 && player1<100 && player2<100)
	{
		if (player3 == 100)
		{
			cout << "Congrats, You got Second Position\n"; position[1] = 2;
		}
	}
	else if (player2 == 100 && player1 == 100 && player4<100 || player2 == 100 && player1<100 && player4 == 100 || player4 == 100 && player1 == 100 && player2<100)
	{
		if (player3 == 100)
		{
			cout << "Congrats, You got Third Position\n"; position[2] = 3;
		}
	}
	if (player2 == 100 && player1 == 100 && player4 == 100 && player3<100)
	{
		cout << "Sorry!You lose the Game\n"; position[3] = 4;
	}
	else if (player3>100)
	{
		player3 = player3 - (dice + dice1);
		cout << playeR3 << " score: " << player3 << endl;
	}

	map1(map, size, player3);
	kill(player3, player2, player1, player4);
}
void plaYer4(char playeR4[50], int& dice, int &dice1, int &player1, int temp[4], int map[][10], int size, bool turN1[4], int &player2, int& player3, int &player4, int position[4])
{
	char x = _getch();
	cout << playeR4 << " Turn:- \t\tPress any key to roll Dices..." << endl;
	dice = randomnum();
	dice1 = randomnum();
	x = _getch();
	snkLD(player4);
	menu2SL();
	cout << "Number on dice1:   " << dice << endl;
	cout << "Number on dice2:   " << dice1 << "\n" << endl;
	while (dice + dice1 == 12)
	{
		move4(map, dice, dice1, size, player4, turN1[3], temp[3]);
		map1(map, size, player4);
		x = _getch();
		dice = randomnum();
		dice1 = randomnum();
		snkLD(player4);
		menu2SL();
		cout << "Number on dice1: " << dice << endl;
		cout << "Number on dice2: " << dice1 << "\n" << endl;

	}
	move4(map, dice, dice1, size, player4, turN1[3], temp[3]);
	SL(player4);
	if (player4<100)
	{
		cout << playeR4 << " score:  " << player4 << endl;
	}
	else  if (player4 == 100 && player2<100 && player3<100 && player1<100)
	{
		cout << playeR4 << ": Congrats. You won the game.You are at 1st Position\n"; position[0] = 1;
	}
	else if (player2 == 100 && player3<100 && player1<100 || player3 == 100 && player2<100 && player1<100 || player1 == 100 && player3<100 && player2<100)
	{
		if (player4 == 100)
		{
			cout << "Congrats, You got Second Position\n"; position[1] = 2;
		}
	}
	else if (player2 == 100 && player3 == 100 && player1<100 || player3 == 100 && player2<100 && player1 == 100 || player1 == 100 && player3 == 100 && player2<100)
	{
		if (player4 == 100)
		{
			cout << "Congrats, You got Third Position\n"; position[2] = 3;
		}
	}
	if (player2 == 100 && player3 == 100 && player1 == 100 && player4<100)
	{
		cout << "Sorry!You lose the Game\n"; position[3] = 4;
	}
	else if (player4>100)
	{
		player4 = player4 - (dice + dice1);
		cout << playeR4 << " score:  " << player4 << endl;
	}

	map1(map, size, player4);
	kill(player4, player2, player3, player1);
}
void record(int position[4])
{
	ofstream record("record.txt");
	for (int i = 0; i<4; i++)
	{
		record << position[i] << endl;
	}

}
