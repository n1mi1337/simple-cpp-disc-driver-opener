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
	cout << "���� �������� ������ �� ������� '1', ����� ���� �������� ������ �� ������� '2'!" << endl;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "���� �� ������ ������� �������� �������� '1', ���� ������ ������� �������� '2': ";

	cin >> opend;
	while (true)
	{
		if (opend == "1")
		{
				mciSendStringA("set cdaudio door open", NULL, 0, 0);
				cout << "�������� ������ �������!" << endl;
				cout << "������� '2' ���� ������ �������: ";
				cin >> opend;
		}
		else if(opend == "2")
		{
			mciSendStringA("set cdaudio door closed", NULL, 0, 0);
			cout << "�������� ������ �������!" << endl;
			cout << "������� '1' ���� ������ �������: ";
			cin >> opend;
		}
	}
	return 0;
}