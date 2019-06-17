#ifndef CMSYS_COURSE
#define CMSYS_COURSE

#include <string>
#include <iostream>

class Course{
    static int currentId;
    private:
        int id;
        std::string name;
    public:
        Course();

        Course(const std::string& name);

        Course(const Course& other);

        const int getId() const{
            return id;
        }

        const std::string getName() const{
            return name;
        }

        void setName(const std::string& name){
            this->name = name;
        }

        virtual std::string printInfo() const{
            return "Course Name: " + name + ", Course ID: " + std::to_string(id);
        }
};

std::ostream& operator << (std::ostream& os, const Course& course);

#endif