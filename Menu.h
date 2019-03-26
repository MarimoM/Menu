#include <windows.h>
#include <string>

namespace Menu
{
	class Langai
	{
	private:
		int ilgis, plotis;
		int mygtukuKiekis;
		int mygtukoLokacijaX[10];
		int mygtukoLokacijaY[10];
		COORD vieta;

	public:
		void PiesiameLanga(int ilgis, int plotis, int coord1, int coord2, int color);
		void Mygtukas(int len, int width, int coord1, int coord2, int color);
		void Uzrasas(char words[], int size, int color);
		int Controls(int pranesimoNumeris, int color);
		void PradineBusena(int mygtukas, int color);
		int Pranesimas(int mygtukas);
	};

	void ShowConsoleCursor(bool showFlag);
}