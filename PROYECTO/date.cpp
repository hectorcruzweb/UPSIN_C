#include <time.h>
#include <stdio.h>

int main() {
    // Represent the date as struct tm.                                                           
    // The subtractions are necessary for historical reasons.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    /*
    printf("Date and time: %d-%02d-%02d %02d:%02d:%02d\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    */                                                            
    tm.tm_mday += 200;
    mktime(&tm);
    // Print the date in ISO-8601 format.                                                         
    char date[30];
    strftime(date, 30, "%Y-%m-%d", &tm);
    printf("%s",date);
}
