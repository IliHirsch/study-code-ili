#include <iostream>
#include <cstdint>
#include <limits>

class Age {
    private:

    public:
        int userInput();
        bool isAdult(std::uint8_t age);
        bool isSenior(std::uint8_t age);
};

int Age::userInput(){
    int var_age;
    std::cout << "Bitte geben Sie ihr Alter ein:";
    std::cin >> var_age;
    std::cin >> std::ws;
    return var_age;
}

bool Age::isAdult(std::uint8_t age){
    if(age >= 18){
        std::cout << "Sie sind" << age << "Jahre alt\n";
        std::cout << "Das heißt Sie sind erwachsen\n";
    }

    else if(age < 18 && age > 0){
        std::cout << "Sie sind" << age << "Jahre alt\n";
        std::cout << "Das heißt Sie sind jugendlich oder noch ein Kind\n";
    }

    else if(age <= 0){
        std::cout << "ungueltige Eingabe\n";
    }
}

bool Age::isSenior(std::uint8_t age){
    if(age >= 65 && age < 110){
        std::cout << "Sie sind" << age << "Jahre alt\n";
        std::cout << "Das heißt Sie sind ein Renter\n";
    }
    else if(age >= 110){
        std::cout << "ungueltige Eingabe\n";
    }
}

int main (){

    Age person;
    uint8_t age = person.userInput();
    person.isAdult(age);
    person.isSenior(age);

    return 0;
}