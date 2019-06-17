#include "course_manager.h"

CourseManager::CourseManager(){

}

void CourseManager::addCourse(const Course& course){
    CoursePtr coursePtr(new Course(course));
    courses.push_back(std::move(coursePtr));
}

void CourseManager::addCourse(const std::string& courseName){
    CoursePtr coursePtr(new Course(courseName));
    courses.push_back(std::move(coursePtr));
}

void CourseManager::removeCourse(int id){
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getId() == id){
            courses.erase(it);
            return;
        }
    }
}

void CourseManager::removeCourse(const std::string& courseName){
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getName() == courseName){
            courses.erase(it);
            return;
        }
    }
}

void CourseManager::removeLastCourse(){
    if(courses.size() != 0){
        courses.pop_back();
    }
}

void CourseManager::printAllCourses() const{
    for(auto it = courses.begin(); it != courses.end(); ++it){
        std::cout << (**it);
    }
}

void CourseManager::printCourse(int id) const{
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getId() == id){
            std::cout << (**it);
            return;
        }
    }
}

void CourseManager::printCourse(const std::string& courseName) const{
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getName() == courseName){
            std::cout << (**it);
            return;
        }
    }
}

void CourseManager::printLongestNameCourse() const{
    auto longestIt = courses.begin();
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getName().size() > (*longestIt)->getName().size()){
            longestIt = it;
        }
    }
    if(longestIt == courses.end()){
        std::cout << "Empty Course List\n";
    }
    for(auto it = courses.begin(); it != courses.end(); ++it){
        if((*it)->getName().size() == (*longestIt)->getName().size()){
            std::cout << (**it);
        }
    }
}