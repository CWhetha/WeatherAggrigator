/*! \file ForecastFactory.h
    @brief builds the forecast for the next couple of days
    @authors: Matthew, Connor, Christian, Curtis, Austin
*/
#ifndef FORECASTFACTORY_H
#define FORECASTFACTORY_H

#include "Day.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <cmath>

#define MAX_ARRAY_WIDTH 8
#define MAX_ARRAY_LENGTH 5

using namespace std;

class ForecastFactory /*! \class ForecastFactory Class */
{
  private:
    string file;                                        /*!< file storing our json */
    Json::Reader reader;                                /*!< reads our json */
    Json::Value obj;                                    /*!< json value object */
    Day *day[MAX_ARRAY_LENGTH][MAX_ARRAY_WIDTH];        /*!< creating our day array */

  public:
     /*! \fn ForecastFactory(string file);
        @brief creates our forecast instances
        @param file reads in the file
    */   
    ForecastFactory(string file);
    
    /*! \fn **GetDayArray();
        @brief gets the day array
    */   
    Day **GetDayArray();
    /*! \fn void CalvAvg();
        @brief calculates the average temperature for each day of the forecast
    */   
    void CalcAvg();
};
#endif
