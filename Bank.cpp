#include<iostream>

class bankacc {

private:
    std::string owner;
    double balance;

public:
    void setOwner();
    std::string getOwner();
    void desposit(double);
    void withdraw(double);
    void getBalance();
    double getAccountInfo();
};

void setOwner(std::string owner){
    owner = ownerName;
}

std::string getOwner(){
    return owner;
}

void desposit(double amount){
    if(amount <= 0){
        std::cout << "ungültige Eingabe/Fehler mit Account" << std::endl;
    }
    balance = balance + amount;
    std::cout << "Ihr neuer Kontostand" << getBalance()
}

void bankacc::withdraw(double){
        if(bankacc::balance < money){
        std::cout << "Sie haben nicht genügend Geld" << std::endl;
    }
    else if (balance >= money)
    {
        balance = balance - money;
    }
}

double bankacc::getBalance();

void bankacc::getAccountInfo();

int main(){
    bankacc MyAccount;

    MyAccount 












}