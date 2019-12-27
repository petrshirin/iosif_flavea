// Iosif_Flavea.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

void print_answer(int splitter, int people, int* arr);

int main()
{

	
	setlocale(LC_ALL, "rus");
	int people, splitter, count_people, counter=1, c, count=1;
	int check = true;
	cout << "Введите кол-во человек: ";
	cin >> people;
	count_people = people;
	cout << "с какой периодичностью они должены пить яд: ";
	cin >> splitter;
	int* arr = new int[people];
	for (int i = 0; i < people; i++)
		arr[i] = 1;

	cout << endl;
	int t = people << 1;
	cout << t-people+1 << endl;

	cout << "Первый будет пить яд" << endl;
	cout << "1 - ДА" << endl;
	cout << "2 - Нет" << endl;
	cin >> c;
	
	if (c == 2) {
		while (true) {
			for (int i = 0; i < people; i++) {
				check = splitter - 1;
				if (splitter == 1)
					check = 1;
				if (count_people != check) {
					if (arr[i] == 1) {
						if (counter == splitter) {
							arr[i] = 0;
							count_people -= 1;
							counter = 1;
						}
						else
							counter++;
					}
				}
				else {
					print_answer(splitter, people, arr);
					cout << count << endl;
					return 0;
				}
			}
			count++;
		}
	}
	else {
		arr[0] = 0;
		count_people--;
		while (true) {
			for (int i = 0; i < people; i++) {
				check = splitter - 1;
				if (splitter == 1)
					check = 1;
				if (count_people != check) {
					if (arr[i] == 1) {
						if (counter == splitter) {
							arr[i] = 0;
							count_people -= 1;
							counter = 1;
						}
						else
							counter++;
					}
				}
				else {
					print_answer(splitter, people, arr);
					return 0;
				}
			}
		}
	}
}

void print_answer(int splitter, int people, int* arr) {
	cout << "Кол-во выживших: " << splitter - 1 << endl;
	cout << "Их номер(а)  ";
	for (int i = 0; i < people; i++) {
		if (arr[i] == 1) {
			cout << i+1 << "  ";
		}
	}
	cout << endl;
}