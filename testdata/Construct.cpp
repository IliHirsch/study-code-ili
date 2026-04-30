#include<iostream>
#include<string>

class Notiz {
    private:
    std::string* text;

    public:
    Notiz(std::string text_in){
        text = new std::string;
        *text = text_in;
        std::cout << "Speicher reserviert" << std::endl;
    }

    ~Notiz(){
        delete text;
        text = nullptr;
        std::cout << "Speicher wieder freigegeben" << std::endl;
    }

    void display();
};

void Notiz::display(){
    std::cout << *text << std::endl;

}

int main(){
    Notiz nachricht("Meine nachricht");
    Notiz nachricht2(nachricht);

    nachricht.display();
    nachricht2.display();

    return 0;

}