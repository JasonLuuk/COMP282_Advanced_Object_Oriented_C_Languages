#include "menupart2.h"
#include "country.h"
#include <iostream>
#include <sstream>
using namespace std;
void MenuPart2::menu() {
	char choice;
	int size = 0;
	string country_name;
	long population;
	Country array[9];
	do
	{
		cout << "1. Add country" << endl;
		cout << "2. List countries" << endl;
		cout << "3. Find largest country" << endl;
		cout << "4. Remove country" << endl;
		cout << "Q. Quit" << endl;
		cout << "Enter Option: ";
		cin >> choice;
		if (choice == 'Q') break;
		switch (choice)
		{
		case '1': {
			if (size < 9)
			{
				cout << endl << "Enter details: ";
				cin >> country_name >> population;
				string user_input;
				user_input = country_name + " " + to_string(population);
				stringstream ss;
				ss << user_input;
				ss >> array[size];
				size++;
				cout << endl;
			}
			else{
				cout << "Can not add country: There are already 9 countries"<<endl;
			}
			break;
		}
		case '2': {
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				cout <<"[" << i + 1 << "] " << array[i] << endl;
			}
			break;
		}
		case '3': {
			cout << endl;
			Country max_pop_country;
			if (size == 0) {
				cout << "There are no countries in the index currently"<<endl;
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (array[i] > max_pop_country)
					{
						max_pop_country = array[i];
					}
				}
				cout << "Largest: " << max_pop_country << endl;
			}
			break;
		}
		case '4': {
			int index;
			cout << endl << "Enter Index: ";
			cin >> index;
			if (size > 0)
			{
				if (index <= 0 || index > size)
				{
					cout << "No country has that index" << endl;
					break;
				}
			}
			else
			{
				cout << "No country has that index" << endl;
				break;
			}
			if (index == size)
			{
				size--;
			}
			else 
			{
				for (int i = index; i < size; i++)
				{
					array[i - 1] = array[i];
				}
				size--;
			}
			cout << endl;
			break;
		}
		}
	} while (choice != 'Q');

}