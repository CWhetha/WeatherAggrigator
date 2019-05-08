/*! \file DataGetter.h
    @brief The header file for DataGetter.cpp
    @authors: Connor, Curtis, Austin, Christian, Matthew
*/
#ifndef DATAGETTER_H    /*! \def Check to see if we have defined a DataGetter.h header file */
#define DATAGETTER_H    /*! \def Define the DataGetter.h header file */

#include <iostream>
#include <fstream>
#include <string.h>
#include <curl/curl.h>
#include "Day.h"
#include "ForecastFactory.h"

class DataGetter    /*! \class DataGetter Class */
{
private:
	const std::string API_KEY = "d13db0315007162f6db694f6cd5016c0";    /*!< references the API Key */
    /*! \fn size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);;
        @brief writes the callback needed in curl
        @param contents contents of the url
        @param size size of one data item
        @param nmemb number of data members
        @param userp used for server authentication when accessing API
    */    
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
	void GetUrlContents(char *url);

public:
    /*! \fn DataGetter();
        @brief gathers all the data from the API*/
	DataGetter();
    Day * GetDayForecast(string city);
    /*! \fn Day ** GetForecast(std:string city)
        @brief gets the weather forecast for a specific; city
        @param city the city we want to know the weather in
    */
	Day ** GetForecast(std::string city);
    /*! \fn std::string GetUrlContents(char *url);
        @brief gets the URL contents
        @param *url the url where we get our contents from
    */
};

#endif
