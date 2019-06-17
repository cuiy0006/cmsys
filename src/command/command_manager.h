#ifndef CMSYS_COMMAND_MANAGER
#define CMSYS_COMMAND_MANAGER

#include <map>
#include <string>
#include "course_manager.h"
#include "command.h"

class CommandManager{
    private:
        std::shared_ptr<CourseManager> courseMgrPtr;
        std::map<CourseCmd, std::string> cmdMap;
        void Init();

        bool HandleInputCmd(const CourseCmd cmd);
    public:
        CommandManager();

        void PrintAllHelp() const;

        void PrintCmdHelp() const;

        bool HandleCmd(const CourseCmd cmd);
};

#endif