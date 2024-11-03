#ifndef UI_H
#define UI_H

#define START_MESSAGE printf("\e[1;35mPlease enter an initial string consisting a/A-z/Z and space:\e[0m\n");
#define START_ERROR_MESSAGE printf("\e[1;31mError : Invalid Input(a/A-z/Z and space)\e[0m\n");
#define ERROR printf("\e[1;31mError : Unknown Issue Occur\e[0m\n");
#define COMMAND_MESSAGE printf( \
"\e[1;35m0. delete the char at the left of the cursor\n\
1 : Move the cursor to left\n\
2 : Move the cursor to right\n\
3 : Redo\n\
4 : Undo\n\
9 : Backspace\n\
Other Valid Character : insert a character (ex. enter A = insert A , valid for a/A-z/Z and space)\n\
\e[0m"\
);

#define CLEAR printf("\e[H\e[2J");

#define FOOTER printf( \
"\e[1;33m--------------------------------------------\n\
Student ID: 41247001S       \n\
Data Structure Homework II                 \n\
--------------------------------------------\e[0m\n"\
);


#endif