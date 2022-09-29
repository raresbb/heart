#include<iostream>
#include<cmath>
#include <windows.h>

using namespace std;

int main()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// TO MODIFY
	SetConsoleTextAttribute(hConsole, 12);  // colors between 1-15 (12 is red) 
	double size = 15; // adjust heart size
	string message("INSERT TEXT HERE");

	double x, y;
	char ch = 3;
	int print_line = 4;
	if (message.length() % 2 != 0)
		message += " ";
	for (x = 0; x < size; x++)
	{
		for (y = 0; y <= 4 * size; y++)
		{
			double dist1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
			double dist2 = sqrt(pow(x - size, 2) + pow(y - 3 * size, 2));
			if (dist1 < size + 0.5 || dist2 < size + 0.5) {
				cout << ch;
			}
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (x = 1; x < 2 * size; x++)
	{
		for (y = 0; y < x; y++)
			cout << " ";
		for (y = 0; y < 4 * size + 1 - 2 * x; y++)
		{
			if (x >= print_line - 1 && x <= print_line + 1) {
				int idx = y - (4 * size - 2 * x - message.length()) / 2;
				if (idx < message.length() && idx >= 0) {
					if (x == print_line)
						cout << message[idx];
					else cout << " ";
				}
				else
					cout << ch;
			}
			else
				cout << ch;
		}
		cout << endl;
	}
	std::cin.get();
}
