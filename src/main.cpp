#include "command_manager.h"

int main(){
    CommandManager cmdMgr;
    int input;
    cmdMgr.PrintAllHelp();
    while(std::cin >> input){
        std::cout << "---------------Results Start----------------\n";
        cmdMgr.HandleCmd((CourseCmd)input);
        std::cout << "done\n";
        std::cout << "----------------Results End-----------------\n";
        cmdMgr.PrintAllHelp();
    }
    return 0;
}