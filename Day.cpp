/*! \file Day.cpp
    @brief Creates our day type and contains the getter methods to return information about current temperature
    @authors: Matthew, Connor, Curtis, Christian, Austin
*/
#include "Day.h"
#include <string>
#include <ctime>

using namespace std;

/*! \fn Day Day(char* date, int temp, double prec, int max, int min, string desc, int humidity)
    @brief stores all of the information of today's weather
    @param date current date
    @param temp current temperature
    @param prec amount of precipitation
    @param max daily high temp
    @param min daily low temp
    @param desc description of the current weather
    @param humidity the current humidity
*/
Day::Day(string date, int temp, double prec, int max, int min, string desc, int humidity)
{
    SetDay(date, temp, prec, max, min, desc, humidity);
}
/*! \fn Day SetDay(std::string date, int temp, double prec, int max, int min, string desc, int humidity)
    @brief sets all of the information of today's weather
    @param date current date
    @param temp current temperature
    @param prec amount of precipitation
    @param max daily high temp
    @param min daily low temp
    @param desc description of the current weather
    @param humidity the current humidity
*/
void Day::SetDay(string date, int temp, double prec, int max, int min, string desc, int humidity)
{
    _date = date;
    _temp = temp;
    _prec = prec;
    _max = max;
    _min = min;
    hum = humidity;
    _desc = desc;
}
/*! \fn getDate();
    @brief getter method for the date.
    @return _date current date
*/
std::string Day::getDate()
{
    return _date;
}
/*! \fn getTemp();
    @brief getter method for the temp.
    @return _temp current temperature
*/
int Day::getTemp()
{
    return _temp;
}
/*! \fn getPrec();
    @brief getter method for the precipitation.
    @return _prec amount of precipitation
    */
double Day::getPrec()
{
    return _prec;
}
/*! \fn getMax();
    @brief getter method for the max.
    @return _max daily high temp
    */
int Day::getMax()
{
    return _max;
}
/*! \fn getMin();
    @brief getter method for the min.
    @return _min daily low temp
    */
int Day::getMin()
{
    return _min;
}
/*! \fn getHumidity();
    @brief getter method for the humidity.
    @return hum humidity level
    */
int Day::getHumidity()
{
    return hum;
}
/*! \fn getDescription();
    @brief getter method for the description.
    @return _desc description of the wather
    */
string Day::getDescription()
{
    return _desc;
}
