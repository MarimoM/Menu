#include "Menu.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleTitle("Menu");
	while (true)
	{
		Menu::ShowConsoleCursor(false);

		int mygtukas;

		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		Menu::Langai naujasLangas;
		
		//Paduodam dydi, koordinates ir spalva
		naujasLangas.PiesiameLanga(15, 30, 5, 2, 3);
		
		//Pirmas mygtukas
		naujasLangas.Mygtukas(3, 15, 13, 5, 3);
		char word[] = { "Start" };
		int size = sizeof(word);
		naujasLangas.Uzrasas(word, size, 7);

		//Antras mygtukas
		naujasLangas.Mygtukas(3, 15, 13, 8, 3);
		char word1[] = { "Continue" };
		size = sizeof(word1);
		naujasLangas.Uzrasas(word1, size, 7);

		//Trecias mygtukas
		naujasLangas.Mygtukas(3, 15, 13, 11, 3);
		char word2[] = { "Exit" };
		size = sizeof(word2);
		naujasLangas.Uzrasas(word2, size, 7);

		//Valdymas
		mygtukas = naujasLangas.Controls(0, 9);
		if(naujasLangas.Pranesimas(mygtukas) == 1) break;
	}
}