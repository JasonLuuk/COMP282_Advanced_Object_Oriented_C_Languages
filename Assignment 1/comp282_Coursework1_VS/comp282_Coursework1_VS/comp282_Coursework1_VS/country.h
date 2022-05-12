#include <string>
class Country {
private:
    std::string name;
    long pop;
public:
    Country(std::string name, long pop);
    Country();
    std::string getName();
    long getPop();
    friend std::ostream& operator<<(std::ostream& output, const Country& country);
    friend std::istream& operator>>(std::istream& input, Country& country);
    bool operator< (const Country& country);
    bool operator> (const Country& country);
    bool operator== (const Country& country);
};
