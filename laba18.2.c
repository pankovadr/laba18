#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    struct tm* mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);
    int year = mytime->tm_year + 1900;
    int month = mytime->tm_mon;
    int day = mytime->tm_mday;
    int days_in_month[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        days_in_month[1] = 29;
    }

    int start_month;
    const char *season;
    if (month == 11 || month == 0 || month == 1) { start_month = 11; season = "зимы"; }
    else if (month >= 2 && month <= 4) { start_month = 2;  season = "весны"; }
    else if (month >= 5 && month <= 7) { start_month = 5;  season = "лета"; }
    else { start_month = 8;  season = "осени"; }

    int k = day;
    for (int m = start_month; m != month; m = (m + 1) % 12)
        k += days_in_month[m];

    printf("»дЄт %d день %s\n", k, season);
    return 0;
}