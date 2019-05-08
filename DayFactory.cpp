/*! \file DayFactory.cpp
    @brief reads in our json file and converts avg, max, and min temperatures from Kelvin to Celsius.
    stores these values into day to return this information onto the GUI
    @authors: Austin, Connor, Curtis, Matthew, Christian
*/
#include "DayFactory.h"

using namespace std;

/* \fn Day ** DayFactory::DayFactory(string city)
   @brief obtains the information for the days weather and returns this information
   @param file the json file being read
*/
DayFactory::DayFactory(string file)
{
    ifstream ifs(file.c_str());                       /*!< read JSON file */
    ifs >> obj;                                       /*!< parse JSON file */
    reader.parse(file, obj);                          /*!< parse JSON file */
    const Json::Value &temp = obj["main"];            /*!< find the main section of JSON file */
    const Json::Value &rain = obj["rain"];            /*!< find the rain section of JSON file */
    const Json::Value &weather = obj["weather"];      /*!<  find the weather section of JSON file */


    time_t now;
    struct tm ts;
    char date[80];
    time(&now);
    ts = *localtime(&now);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S\n", &ts);
    std::string _date = date;

    float avgTemp = temp["temp"].asFloat() - 273.15;   /*!< formats temperature to degree celcius */
    float maxC = temp["temp_max"].asFloat() - 273.15;
    float minC = temp["temp_min"].asFloat() - 273.15;
    string desc = (weather[0]["description"]).asString();
    int hum = temp["humidity"].asInt();
    day = new Day(_date, round(avgTemp), rain["3h"].asDouble(), round(maxC), round(minC), desc, hum); /*!< set day with given parameters */
    day = new Day(_date, round(avgTemp), rain["3h"].asDouble(), round(maxC), round(minC), desc, hum); /*!< set day with given parameters */
}

/* \fn Day *DayFactory::GetDay()
   @brief returns the values stored in day
   @return day information stored for today's weather
*/
Day *DayFactory::GetDay()
{
    return day;
}
