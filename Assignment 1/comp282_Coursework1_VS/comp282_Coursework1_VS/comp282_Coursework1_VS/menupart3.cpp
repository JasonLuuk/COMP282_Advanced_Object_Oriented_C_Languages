#include "menupart3.h"
#include "country.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
void MenuPart3::menu() {
	char choice;
	string country_name;
	long population;
	vector<Country> set;
	vector<Country>::iterator v = set.begin();
	do
	{
		cout << "1. Add country" << endl;
		cout << "2. List countries" << endl;
		cout << "3. Find largest country" << endl;
		cout << "4. Remove country" << endl;
		cout << "5. Sort countries" << endl;
		cout << "Q. Quit" << endl;
		cout << "Enter Option: ";
		cin >> choice;
		if (choice == 'Q') break;
		switch (choice)
		{
		case '1': {
			cout << endl << "Enter details: ";
			cin >> country_name >> population;
			string user_input;
			user_input = country_name + " " + to_string(population);
			Country test(country_name,population);
			set.push_back(test);
			cout << endl;
			break;
		}
		case '2': {
			cout << endl;
			for (int i = 0; i < set.size(); i++)
			{
				cout << "[" << i + 1 << "] " << set[i] << endl;
			}
			break;
		}
		case '3': {
			cout << endl;
			Country max_pop_country;
			if (set.size() == 0) {
				cout << "There are no countries in the index currently" << endl;
			}
			else
			{
				for (int i = 0; i < set.size(); i++)
				{
					if (set[i] > max_pop_country)
					{
						max_pop_country = set[i];
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
			if (set.size() > 0)
			{
				if (index <= 0 || index > set.size())
				{
					cout << "No country has that index" << endl;
					break;
				}
			}
			else
			{
				cout << "No country has that index" << endl;
				break;
			}if (index == set.size())
			{
				v = set.end();
				set.erase(v-1);
			}
			else
			{
				for (int i = index; i < set.size(); i++)
				{
					set[i - 1] = set[i];
				}
				v = set.end();
				set.erase(v - 1);
			}
			break;
		}
		case '5': {
			sort(set.begin(),set.end());
			break;
		}
		}
	} while (choice != 'Q');

}