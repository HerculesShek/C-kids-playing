#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// int day_of_year(int year, int month, int day);
/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}
/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  int day_year = day_of_year(2015, 10, 2);
  printf("day_of_year is %d\n", day_year);

  int m, d;
  month_day(2015, day_year, &m, &d);
  printf("2015-%d-%d\n", m, d);

  return 0;
}


