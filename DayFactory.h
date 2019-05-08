/*! \file DayFactory.h
    @brief The header file for DayFactorycpp
    @authors: Matthew, Connor, Curtis, Austin, Christian
*/
#ifndef DAYFACTORY_H
#define DAYFACTORY_H

#include "Day.h"
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <time.h>
#include <string>

using namespace std;

class DayFactory /*! \class DayFactory */
{

  private:
    string file;            /*!< file variable */
    Json::Reader reader;    /*!< reads the json */
    Json::Value obj;        /*!< assigns the object */
    Day *day;               /*!< day variable */

  public:
    /*! \fn DayFactory(string file);
        @brief creates day instances
        @param file reads in the file
    */    
    DayFactory(string file);
    /*! \fn Day *GetDay();
        @brief gets the current day
    */
    Day *GetDay();
};

#endif
