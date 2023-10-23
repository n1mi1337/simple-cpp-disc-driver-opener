#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>
#include <iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RU");
	string opend;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Если дисковод открыт не вводите '1', также если дисковод закрыт не вводите '2'!" << endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "Если вы хотите открыть дисковод напишите '1', если хотите закрыть напишите '2': ";

	cin >> opend;
	while (true)
	{
		if (opend == "1")
		{
				mciSendStringA("set cdaudio door open", NULL, 0, 0);
				cout << "Дисковод открыт успешно!" << endl;
				cout << "Введите '2' если хотите закрыть: ";
				cin >> opend;
		}
		else if(opend == "2")
		{
			mciSendStringA("set cdaudio door closed", NULL, 0, 0);
			cout << "Дисковод закрыт успешно!" << endl;
			cout << "Введите '1' если хотите открыть: ";
			cin >> opend;
		}
	}
	return 0;
}