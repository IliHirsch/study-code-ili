#include <iostream>
#include <string>
#include <iomanip>
using namespace std; //kein using name space verwenden

class Article {
public:             //nur public ?? kein private vorallem für sensible daten
    string name;    //
    double price;   //
    int stock;      //
    string* category;// kein sinn
    int id;         //

    Article(string name, double price, int stock, string category, int id) {
        name = name;
        price = price;
        stock = stock;
        this->id = id; // uneinheitlich? warum pointer ?
        this->category = new string;
        *this->category = category;
    }

    void setPrice(double price) {
        price = price;
    }

    void sell(int amount) {
        stock = stock - amount; //vereinheitlichen -= oder = ... - ...
    }

    void restock(int amount) {
        this->stock += amount; //hier pointer ??
    }

    double applyDiscount(double percent) { //keine beschreibung
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price; //const weil es verändert nichts
    }

    bool isAvailable() {
        if (stock > 0)
            return true; //Klammern??
        else
            return false;
    }

    void printInfo() { // außerhalb schreiben wegen größe
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101); //magic numbers

    a.sell(15);
    a.restock(-5);  //keine validierung
    a.price = -100; //zugriff direkt auf price?? + falsche werte?
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}