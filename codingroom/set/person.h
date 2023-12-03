#include <string>

struct Person
{
    std::string nombre;
    int edad;    
    
    Person(std::string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }

    Person(std::string nombre){
        this->nombre = nombre;
        this->edad = 0;
    }

    Person(){
        this->nombre = "";
        this->edad = 0;
    }

    bool operator==(const Person& other) const{
        return this->nombre == other.nombre;
    }

    bool operator<(const Person& other) const{
        return this->nombre < other.nombre;
    }

    bool operator>(const Person& other) const{
        return this->nombre > other.nombre;
    }

    bool operator<=(const Person& other) const{
        return this->nombre <= other.nombre;
    }

    bool operator>=(const Person& other) const{
        return this->nombre >= other.nombre;
    }

    bool operator!=(const Person& other) const{
        return this->nombre != other.nombre;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person){
        os << "(" << person.nombre << ", " << person.edad << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& person){
        is >> person.nombre >> person.edad;
        return is;
    }

    ~Person(){
        //std::cout << "Destructor called" << std::endl;
    }

};