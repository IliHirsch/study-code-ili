#include <iostream>
#include <string>



void Grade::readStudentData(std::string name, uint16_t homework, uint16_t midterm, uint16_t finalexam){
    this->name = name;

    if(homework >= 0 && homework <= 100 && midterm >= 0 && midterm <= 100 && finalexam >= 0 && finalexam <= 100){
        this->homework = homework;
        this->midterm = midterm;
        this->finalexam = finalexam;
    }
    else{
        std::cout << "Invalid Input\n";
    }
}

int main(){



    Grade Person;



    return 0;
}