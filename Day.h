/*! \file Day.h
    @brief The header file for Day.cpp
    @authors: Matthew, Connor, Christian, Curtis, Austin
*/
#ifndef DAY_H /*! \def Check to see if we have defined a Day.h header file */
#define DAY_H /*! \def Define the Day.h header file */
#include <time.h>
#include <string>

class Day /*! \class Day.h class */
{
  private:
    std::string _date;   /*!< variable storing date */
    int _temp;           /*!< variable storing temperature */
    double _prec;        /*!< variable storing precipitation */
    int _max;            /*!< variable storing daily high temp */
    int _min;            /*!< variable storing daily low temp */
    int hum;             /*!< variable storing humidity */
    std::string _desc;   /*!< variable storing description */

  public:
    /*! \fn Day(char* date, int temp, double prec, int max, int min, string desc, int humidity);
        @brief stores all of the information of today's weather
        @param date current date
        @param temp current temperature
        @param prec amount of precipitation
        @param max daily high temp
        @param min daily low temp
        @param desc description of the current weather
        @param humidity the current humidity
    */
    Day(std::string date, int temp, double prec, int max, int min, std::string desc, int humidity);
    
    /*! \fn void setDay(char* date, int temp, double prec, int max, int min, string desc, int humidity);
        @brief sets all of the information of today's weather
        @param date current date
        @param temp current temperature
        @param prec amount of precipitation
        @param max daily high temp
        @param min daily low temp
        @param desc description of the current weather
        @param humidity the current humidity
    */
    void SetDay(std::string date, int temp, double prec, int max, int min, std::string desc, int humidity);

    /*! \fn getDate();
        @brief getter method for temp */
    std::string getDate();
    /*! \fn getTemp();
        @brief getter method for the temp. */
    int getTemp();
    /*! \fn getPrec();
        @brief getter method for the precipitation. */
    double getPrec();
    /*! \fn getMax();
        @brief getter method for the max. */
    int getMax();
    /*! \fn getMin();
        @brief getter method for the min. */
    int getMin();
    /*! \fn getHumidity();
        @brief getter method for the humidity. */
    int getHumidity();
    /*! \fn getDescription();
        @brief getter method for the description. */
    std::string getDescription();
};

#endif
