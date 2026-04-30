#include<iostream>
#include<string>
#include<iomanip>


class drinkbuilder{
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;
    
        public:
        void setName(const std::string& name){
            this->name = name;
        }

        std::string getName(){
        return this->name;
        }

        int setSugar(int sugar){
            this->sugar = sugar;
            return this->sugar; 
        }   

        int setTemperature(int temperature){
            this->temperature = temperature;
            return this->temperature;
        }

        bool setWithMilk(bool withMilk){
            this->withMilk = withMilk;
            return this->withMilk;
        }

        void print();
};

void drinkbuilder::print(){
    std::cout << "Drink: " << name << std::endl;
    std::cout << "Sugar(g): " << sugar << std::endl;
    std::cout << "Temperature(*C): " << temperature << std::endl;
    std::cout << "Milk: " << std::boolalpha << withMilk << std::endl;
}


int main(){
    drinkbuilder builder;
    builder.setName("Mojito");
    builder.setSugar(5);
    builder.setTemperature(20);
    builder.setWithMilk(false);
    builder.print();

    return 0;
}