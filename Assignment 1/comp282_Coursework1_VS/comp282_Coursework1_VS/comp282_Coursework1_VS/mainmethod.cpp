// COMP282
// Project Template: Coursework 1

// - Create all your files in the same folder as this one
// - Submit your X.h and X.cpp for X being country and main


#include "country.h"
#include "menupart2.h"
#include "menupart3.h"
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

//Task 1 tests
bool Task1Test1() {
    Country c("UK", 67081234);
    return c.getName() == "UK" && c.getPop() == 67081234;
}

bool Task1Test2() {
    Country c("Germany", 83222442);
    return c.getName() == "Germany" && c.getPop() == 83222442;
}

bool Task1Test3() {
    Country c;
    return c.getName() == "" && c.getPop() == 0;
}

//Task 2 tests
bool Task2Test1() {
    Country c("UK", 67081234);
    stringstream ss;
    ss << c;
    return ss.str() == "UK 67081234";
}

bool Task2Test2() {
    Country c("Germany", 83222442);
    stringstream ss;
    ss << c;
    return ss.str() == "Germany 83222442";
}


bool Task2Test3() {
    stringstream ss("UK 67081234");
    Country c;
    ss >> c;
    return c.getName() == "UK" && c.getPop() == 67081234;
}

bool Task2Test4() {
    stringstream ss("Germany 83222442");
    Country c;
    ss >> c;
    return c.getName() == "Germany" && c.getPop() == 83222442;
}

//Task 3 tests
class Cos {
public:
    virtual bool comp(Country c1, Country c2) { return true; };
    virtual string type() { return ""; };
};

class Sm : public Cos {
public:
    bool comp(Country c1, Country c2) { return c1 < c2; };
    string type() { return "<"; }
};

class Eq : public Cos {
public:
    bool comp(Country c1, Country c2) { return c1 == c2; };
    string type() { return "=="; }
};

class Gr : public Cos {
public:
    bool comp(Country c1, Country c2) { return c1 > c2; };
    string type() { return ">"; }
};


string Task3Tester(vector<Country> arr, vector<Cos*> comp) {
    stringstream ss;
    for (Cos* c : comp) {
        ss << "Test for " << c->type() << ":";
        int i = 0;
        for (auto f : arr) {
            ss << i << ":";
            for (auto s : arr) {
                ss << c->comp(f, s);
            }
            ss << ", ";
            i++;
        }
    }
    return ss.str();
}

void Task3Test() {
    vector<Cos*> comp;
    Sm s;
    Eq e;
    Gr g;

    comp.push_back(&s);
    comp.push_back(&e);
    comp.push_back(&g);

    vector<Country> countries;
    countries.push_back(Country("Germany", 83222442));
    countries.push_back(Country("UK", 67081234));
    countries.push_back(Country("France", 67813000));
    countries.push_back(Country("United_Kingdom", 67081234));
    cout << "Task 3 tests: " << Task3Tester(countries, comp) << endl;

    countries.clear();
    countries.push_back(Country("c", 83222442));
    countries.push_back(Country("c", 67081234));
    countries.push_back(Country("c", 67813000));
    countries.push_back(Country("c", 67081234));

    cout << Task3Tester(countries, comp);
}

int main() {
    int i1;
    cin >> i1;
    if (i1 == 1) {
        int i2;
        cin >> i2;
        if (i2 == 1) cout << Task1Test1();
        if (i2 == 2) cout << Task1Test2();
        if (i2 == 3) cout << Task1Test3();
    }
    if (i1 == 2) {
        int i2;
        cin >> i2;
        if (i2 == 1) cout << Task2Test1();
        if (i2 == 2) cout << Task2Test2();
        if (i2 == 3) cout << Task2Test3();
        if (i2 == 4) cout << Task2Test4();
    }

    if (i1 == 3) Task3Test();

    if (3 < i1 && i1 < 7) {
        MenuPart2 m;
        m.menu();
    }
    if (6 < i1 && i1 < 9) {
        MenuPart3 m;
        m.menu();
    }
}
