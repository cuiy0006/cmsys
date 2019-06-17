#ifndef CMSYS_COURSE_MANAGER
#define CMSYS_COURSE_MANAGER

#include <vector>
#include <memory>
#include "course.h"

class CourseManager{
    private:
        typedef std::unique_ptr<Course> CoursePtr;
        std::vector<CoursePtr> courses;
    public:
        CourseManager();
        void addCourse(const Course& course);
        void addCourse(const std::string& courseName);
        void removeCourse(int id);
        void removeCourse(const std::string& courseName);
        void removeLastCourse();
        int getCourseCount() const{
            return courses.size();
        }
        void printAllCourses() const;
        void printCourse(int id) const;
        void printCourse(const std::string& courseName) const;
        void printLongestNameCourse() const;

};

#endif