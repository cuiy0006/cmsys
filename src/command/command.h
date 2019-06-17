#ifndef CMSYS_COMMAND
#define CMSYS_COMMAND

enum CourseCmd{
    Cmd_PrintHelp = 0,
    Cmd_PrintAllCourses = 1,
    Cmd_PrintCourseById = 2,
    Cmd_PrintCourseByName = 3,
    Cmd_PrintCourseNum = 4,
    Cmd_PrintLongName = 5,
    Cmd_RemoveLastCourse = 6,
    Cmd_AddCourseByName = 7,
    Cmd_RemoveCourseById = 8,
    Cmd_RemoveCourseByName = 9,
    Cmd_Exit = 10,
};

#endif