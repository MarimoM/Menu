#include "Menu.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

namespace Menu
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	void Langai::PiesiameLanga(int len, int widh, int coord1, int coord2, int color)
	{
		COORD vieta;
		mygtukuKiekis = 0;

		for (int y = 0; y < len; y++)
			for (int x = 0; x < widh; x++) {
				vieta.X = coord1 + x;
				vieta.Y = coord2 + y;
				SetConsoleTextAttribute(console, color);
				SetConsoleCursorPosition(console, vieta);
				if (y == 0 && x == widh - 1) cout << (char)187;
				if (y == len - 1 && x == widh - 1) cout << (char)188;
				if (y == len - 1 && x == 0) cout << (char)200;
				if (y == 0 && x == 0) cout << (char)201;
				if ((y == 0 && x < widh - 1) || (y == len - 1 && x < widh - 1))cout << (char)205;
				if (x == 0 || (x == widh - 1 && y > 0 && y < len - 1)) cout << (char)186;
				if (x!= widh-1)cout << " ";
			}

	}
	void Langai::Mygtukas(int len, int width, int coord1, int coord2, int color)
	{
		COORD vieta;
		ilgis = len;
		plotis = width;

		for (int y = 0; y < ilgis; y++)
			for (int x = 0; x < plotis; x++) {
				vieta.X = coord1 + x;
				vieta.Y = coord2 + y;
				SetConsoleCursorPosition(console, vieta);
				SetConsoleTextAttribute(console, color);
				if (y == 0 && x == plotis - 1) cout << (char)191;
				if (y == ilgis - 1 && x == plotis - 1) cout << (char)217;
				if (y == ilgis - 1 && x == 0) cout << (char)192;
				if (y == 0 && x == 0) cout << (char)218;
				if ((y == 0 && x < plotis - 1) || (y == ilgis - 1 && x < plotis - 1))cout << (char)196;
				if (x == 0 || (x == plotis - 1 && y > 0 && y < ilgis - 1)) cout << (char)179;
				cout << " ";
			}

		mygtukoLokacijaX[mygtukuKiekis] = coord1;
		mygtukoLokacijaY[mygtukuKiekis] = coord2;
		mygtukuKiekis++;

	}
	void Langai::Uzrasas(char words[], int size, int color)
	{
		int pradzia = (plotis - (size - 1)) / 2;
		for (int i = 0; i < size; i++)
		{
			SetConsoleTextAttribute(console, color);
			vieta.X = mygtukoLokacijaX[mygtukuKiekis - 1] + pradzia + i;
			vieta.Y = mygtukoLokacijaY[mygtukuKiekis - 1] + 1;
			SetConsoleCursorPosition(console, vieta);
			cout << words[i];
		}
	}
	int Langai::Controls(int pranesimoNumeris, int color)
	{
		char key;
		int mygtukas(0), paspaustasPriesTai(0);
		bool paspaustasMygtukas;

		while (1)
		{
			vieta.X = mygtukoLokacijaX[mygtukas];
			vieta.Y = mygtukoLokacijaY[mygtukas];

			SetConsoleCursorPosition(console, vieta);

			for (int y = 0; y < ilgis; y++)
				for (int x = 0; x < plotis; x++) {
					vieta.X = mygtukoLokacijaX[mygtukas] + x;
					vieta.Y = mygtukoLokacijaY[mygtukas] + y;
					SetConsoleCursorPosition(console, vieta);
					SetConsoleTextAttribute(console, color);
					if (y == 0 && x == plotis - 1) cout << (char)187;
					if (y == ilgis - 1 && x == plotis - 1) cout << (char)188;
					if (y == ilgis - 1 && x == 0) cout << (char)200;
					if (y == 0 && x == 0) cout << (char)201;
					if ((y == 0 && x < plotis - 1) || (y == ilgis - 1 && x < plotis - 1))cout << (char)205;
					if (x == 0 || (x == plotis - 1 && y > 0 && y < ilgis - 1)) cout << (char)186;
				}

			paspaustasPriesTai = mygtukas;

			key = _getch();
			switch (key)
			{
			case 72: mygtukas--; break;
			case 77: mygtukas++; break;
			case 75: mygtukas--; break;
			case 80: mygtukas++; break;
			case 13: if (pranesimoNumeris == 0)return mygtukas; 
					 else if (mygtukas == 0) return 1;
					 else return 0;
					break;
			}

			if (mygtukas == mygtukuKiekis) mygtukas = 0;
			else if (mygtukas == -1) mygtukas = mygtukuKiekis-1;

			if (pranesimoNumeris == 1) PradineBusena(paspaustasPriesTai, 23);
			else PradineBusena(paspaustasPriesTai, 3);
		}
		return 0;
	}
	void Langai::PradineBusena(int mygtukas, int color)
	{
		for (int y = 0; y < ilgis; y++)
			for (int x = 0; x < plotis; x++) {
				vieta.X = mygtukoLokacijaX[mygtukas] + x;
				vieta.Y = mygtukoLokacijaY[mygtukas] + y;
				SetConsoleCursorPosition(console, vieta);
				SetConsoleTextAttribute(console, color);
				if (y == 0 && x == plotis - 1) cout << (char)191;
				if (y == ilgis - 1 && x == plotis - 1) cout << (char)217;
				if (y == ilgis - 1 && x == 0) cout << (char)192;
				if (y == 0 && x == 0) cout << (char)218;
				if ((y == 0 && x < plotis - 1) || (y == ilgis - 1 && x < plotis - 1))cout << (char)196;
				if (x == 0 || (x == plotis - 1 && y > 0 && y < ilgis - 1)) cout << (char)179;
			}
	}
	int Langai::Pranesimas(int mygtukas)
	{
		//Jei paspaustas pirmas mygtukas
		if (mygtukas == 0 || mygtukas == 1)
		{
			PiesiameLanga(8, 30, 5, 5, 23);
			SetConsoleCursorPosition(console, { 7, 8 });
			cout << "Sorry, this function is not";
			SetConsoleCursorPosition(console, {7, 9});
			cout << "   avaluable for now." << endl;
			cin.get();
		}
		if (mygtukas == 2)
		{
			PiesiameLanga(8, 30, 5, 5, 23);
			SetConsoleCursorPosition(console, { 7, 8 });
			cout << "     Exit the program?";

			Mygtukas(3, 8, 11, 9, 23);
			char word[] = { "Yes" };
			int size = sizeof(word);
			Uzrasas(word, size, 23);

			//Antras mygtukas
			Mygtukas(3, 8, 21, 9, 23);
			char word1[] = { "No" };
			size = sizeof(word1);
			Uzrasas(word1, size, 23);

			if(Controls(1, 20)==1) return 1;
			else return 0;
		}

		return 0;
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO     cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}
}