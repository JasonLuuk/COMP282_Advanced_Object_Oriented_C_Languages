#include "country.h"
#include <iostream>
using namespace std;
Country::Country()
{
    Country::name = "";
    Country::pop = 0;
}
Country::Country(std::string name, long pop)
{
    Country::name = name;
    Country::pop = pop;
}

string Country::getName()
{
    return name;
}
long  Country::getPop()
{
    return pop;
}
bool Country::operator<(const Country& country)
{
    if (pop < country.pop)
    {
        return true;
    }
    return false;
}
bool Country::operator>(const Country& country)
{
    if (pop > country.pop)
    {
        return true;
    }
    return false;
}
bool Country::operator==(const Country& country)
{
    return this->pop == country.pop;
}
ostream& operator<<(ostream& output, const Country& country)
{
    output << country.name << " " << country.pop;
    return output;
}
istream& operator>>(istream& input, Country& country)
{
    input >> country.name >> country.pop;
    return input;
}

