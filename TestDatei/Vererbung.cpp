#include<iostream>
#include<string>
#include<cstdint>

class User {
    private:
    protected:
        std::string name;
        int id;

    public:
        User(std::string name, int id){
            this->name = name;
            this->id = id;
        }
        void printInfo(){
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
        }

};

class Student : public User {
    private:
        int semester;
    public:
        Student()

        void printRole(){
            std::cout << "Semester: " << semester << std::endl;
        }


};


int main(){

    return 0;
}