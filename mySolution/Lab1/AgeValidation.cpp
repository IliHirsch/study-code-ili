#include <iostream>
#include <string>

class Age{
    private:

    public:
        bool isAdult(int age){
            return(age >= 18 && age < 65);
        }

        bool isSenior(int age){
            return(age >= 65 && age < 110);
        }

};

int main(){
    int age = 0;

    Age Person;
    std::cout << "Please enter your Age: ";
    std::cin >> age;

    if(age > 0 && age < 150){
        if(Person.isAdult(age)){
        std::cout << "Your age is " << age << "\n";
        std::cout << "That means you are an Adult";
        }
        if(Person.isSenior(age)){
        std::cout << "Your age is " << age << "\n";
        std::cout << "That means you are a Senior";
        }
        else{
        std::cout << "Your age is " << age << "\n";
        std::cout << "That means you are a Child";
        }
    }
    else{
        std::cout << "This is not a valid number.\n";
        std::cout << "Please try again\n";
    }

    return 0;
}