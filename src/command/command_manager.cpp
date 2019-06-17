#include "command_manager.h"

CommandManager::CommandManager(){
    Init();
}

void CommandManager::Init(){
    courseMgrPtr = std::shared_ptr<CourseManager>(new CourseManager());
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintHelp, "Help Info"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintAllCourses, "Print All Courses"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintCourseById, "Print Course By Name"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintCourseByName, "Print Course By Id"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintCourseNum, "Print Course Number"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_PrintLongName, "Print longest-name Course"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_RemoveLastCourse, "Remove Last Course"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_AddCourseByName, "Add Course By Name"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_RemoveCourseById, "Remove Course By Id"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_RemoveCourseByName, "Remove Course By Name"));
    cmdMap.insert(std::pair<CourseCmd, std::string>(Cmd_Exit, "Exit"));
}

void CommandManager::PrintAllHelp() const{
    for(auto it = cmdMap.begin(); it != cmdMap.end(); ++it){
        std::cout << it->first << ": " << it->second << "\n";
    }
    std::cout << "Input Command Index:\n>";
}

void CommandManager::PrintCmdHelp() const{

}

bool CommandManager::HandleCmd(const CourseCmd cmd){
    auto it = cmdMap.find(cmd);
    if(it == cmdMap.end()){
        std::cout << "No Command Found\n";
        return false;
    }

    switch (it->first)
    {
    case Cmd_PrintHelp:
        std::cout << "Input Command ------------\n";
        break;
    
    case Cmd_PrintAllCourses:
        courseMgrPtr->printAllCourses();
        break;

    case Cmd_PrintCourseNum:
        courseMgrPtr->getCourseCount();
        break;
    
    case Cmd_PrintLongName:
        courseMgrPtr->printLongestNameCourse();
        break;
    
    case Cmd_RemoveLastCourse:
        courseMgrPtr->removeLastCourse();
        break;

    case Cmd_Exit:
        break;

    default:
        HandleInputCmd(cmd);
    }
    return true;
}

bool CommandManager::HandleInputCmd(const CourseCmd cmd){
    std::string input;
    std::cout << "Input BACK to Main Menu, or ";
    switch (cmd)
    {
    case Cmd_PrintCourseById:
        std::cout << "Input Course Id to Print Course:\n";
        std::cin >> input;
        if(input == "BACK"){
            break;
        }
        courseMgrPtr->printCourse(std::stoi(input));
        break;

    case Cmd_PrintCourseByName:
        std::cout << "Input Course Name to Print Course:\n";
        std::cin >> input;
        if(input == "BACK"){
            break;
        }
        courseMgrPtr->printCourse(input);
        break;
    
    case Cmd_AddCourseByName:
        std::cout << "Input Course Name to Add Course:\n";
        std::cin >> input;
        if(input == "BACK"){
            break;
        }
        courseMgrPtr->addCourse(input);
        break;
    
    case Cmd_RemoveCourseById:
        std::cout << "Input Course Id to Remove Course:\n";
        std::cin >> input;
        if(input == "BACK"){
            break;
        }
        courseMgrPtr->removeCourse(std::stoi(input));
        break;

    case Cmd_RemoveCourseByName:
        std::cout << "Input Course Name to Remove Course:\n";
        std::cin >> input;
        if(input == "BACK"){
            break;
        }
        courseMgrPtr->removeCourse(input);
        break;
    
    default:
        break;
    }
    return true;
}