#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct BusinessCard {
    std::string companyName;
    std::string address;
    std::string phoneNumber;
    std::string workingHours;
    std::string representative;
    double priceQuoted;

    BusinessCard(std::string name, std::string addr, std::string phone, std::string hours, std::string poc) {
        companyName = name;
        address = addr;
        phoneNumber = phone;
        workingHours = hours;
        representative = poc;
    }
};

int main() {

    srand(static_cast<unsigned int>(time(0)));

    BusinessCard c1("Celsius", "622 Energy Lane", "951-186-8258", "9AM-5PM", "Christian Sanchez");
    BusinessCard c2("Red Bull", "831 Wing Ave", "951-195-5937", "8AM-4PM", "Benito Gonzalez");
    BusinessCard c3("Monster", "525 Jersey Ave", "951-677-2008", "9:30AM-5:30PM", "Becky Alejandro");
    BusinessCard c4("Ghost", "666 Haunted Peak", "951-025-1800", "10AM-6PM", "Miguel Lopez");
    BusinessCard c5("Alani Nu", "903 Sunrise Blvd", "951-413-2974", "8AM-4PM", "Jenifer Maluma");

    std::vector<BusinessCard> companies = {c1, c2, c3, c4, c5};

    std::cout << "Business Card Quotes\n" << std::endl;
    for (int i = 0; i < companies.size(); i++) {
        companies[i].priceQuoted = (rand() % 501) + 50.0;

        std::cout << "Company: " << companies[i].companyName << "\n";
        std::cout << "POC:     " << companies[i].representative << "\n";
        std::cout << "Price:   $" << companies[i].priceQuoted << "\n";
        std::cout << "--------------------------------------\n";
    }

    int bestIndex = 0;
    for (int i = 1; i < companies.size(); i++) {
        if (companies[i].priceQuoted < companies[bestIndex].priceQuoted) {
            bestIndex = i;
        }
    }

    std::cout << "\n>>> The best choice for you: <<<" << std::endl;
    std::cout << "Based on the lowest quote, the best choice for you is: " << companies[bestIndex].companyName << std::endl;
    std::cout << "Contact " << companies[bestIndex].representative << " at " << companies[bestIndex].phoneNumber << std::endl;
    std::cout << "Final Price: $" << companies[bestIndex].priceQuoted << std::endl;

    return 0;
}
