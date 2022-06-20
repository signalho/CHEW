#include <stdio.h>
/*
char* Condition_String1(int condition) {
    switch (condition) {
    case 0:
        return "EQ";
    case 1:
        return "NE";
    case 2:
        return "CS";
    case 3:
        return "CC";
    case 4:
        return "MI";
    case 5:
        return "PL";
    case 6:
        return "VS";
    case 7:
        return "VC";
    case 8:
        return "HI";
    case 9:
        return "LS";
    case 10:
        return "GE";
    case 11:
        return "LT";
    case 12:
        return "GT";
    case 13:
        return "LE";
    case 14:
        return "";
    default:
        return 0;
    }
}
*/
//이렇게 바뀔 수 있음
/*
char* Condition_String2(int condition) {
    if ((unsigned)condition >= 15) {
        return 0;
    }
    char* table[] = {
    "EQ", "NE", "CS", "CC", "MI", "PL", "VS","VC", "HI", "LS", "GE", "LT", "GT", "LE" };

    return table[condition];
}
*/
