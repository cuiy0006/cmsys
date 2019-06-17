#include "course.h"

int Course::currentId = 0;

Course::Course(const std::string& name)
    : name(name) {
        id = Course::currentId++;
    }

Course::Course(const Course& other){
    name = other.getName();
    id = other.getId();
}

std::ostream& operator << (std::ostream& os, const Course& course){
    return os << course.printInfo() << "\n";
}

// int main(){

//     Course c1("n1");
//     Course c2("n2");
//     Course c3("n3");
//     Course c4(c1);
//     std::cout << c1 << c2 << c3 << c4;


// }