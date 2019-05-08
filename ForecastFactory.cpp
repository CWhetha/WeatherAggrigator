/*! \file ForecastFactory.cpp
    @brief creates and returns information for the weather forecast of the next week
    @authors: Matthew, Curtis, Austin, Connor, Christian
*/
#include "ForecastFactory.h"

/* \fn ForecastFactory::ForecastFactory(string file)
   @brief obtains information for the future weather forecast
   @param file stores our JSON file
   @fn CalcAvg(); calculates the average temperature of each day for one week
*/
ForecastFactory::ForecastFactory(string file)
{
    ifstream ifs(file.c_str());
    ifs >> obj;                                             /*!< parse JSON file */
    const Json::Value &list = obj["list"];                  /*!< find the list section of the JSON file */
    int x = 0, y = 1;
    int i;
    for (i = 0; i < list.size(); i++)
    {
        const Json::Value &temp = list[i]["main"];          /*!< find the main section of JSON file */
        const Json::Value &rain = list[i]["rain"];          /*!< find the rain section of JSON file */
        const Json::Value &time = list[i]["dt_txt"];        /*!< find the date section of JSON file */
        const Json::Value &weather = list[i]["weather"];    /*!< find the weather section of JSON file */

        float avgTemp = temp["temp"].asFloat() - 273.15;    /*!< formats temperature from kelvin to celcius */
        float maxC = temp["temp_max"].asFloat() - 273.15;
        float minC = temp["temp_min"].asFloat() - 273.15;
        string date = (list[i]["dt_txt"]).asString();
        int hum = temp["humidity"].asInt();
        string desc = (weather[0]["description"]).asString();
        day[x][y] = new Day(date, round(avgTemp), rain["3h"].asDouble(), round(maxC), round(minC), desc, hum);                                  /*!< set day with given parameters */
        if (((y + 1) % 8) == 0)
        {
            x++;
            y = 0;
            i++;
        }
        y++;
    }
    CalcAvg();
}

/* \fn Day **ForecastFactory::GetDayArray()
   @brief returns our information with our forecast
   @return *day weather information for today
*/
Day **ForecastFactory::GetDayArray()
{
    return *day;
}

/* \fn void ForecastFactory::CalcAvg()
   @brief calculates the average weather (temp, precip, humidity) for each day in the future as well as the  daily high and low temperature for each day
*/
void ForecastFactory::CalcAvg()
{
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
    {
        float avgTemp = 0;
        float max = 0;
        float min = day[i][1]->getMin();
        float totPrec = 0;
        std::string date;
        int j = 1;
        int avgHum = 0;
        string desc;
        for (j = 1; j < MAX_ARRAY_WIDTH; j++)
        {
            avgTemp = avgTemp + day[i][j]->getTemp();   /*!< calculate avg temp for day */
            totPrec = totPrec + day[i][j]->getPrec();   /*!< calculate total precipitation for day */
            avgHum = avgHum + day[i][j]->getHumidity(); /*!< calculate average humidity for day */
            if (day[i][j]->getMax() >= max)
            {
                max = day[i][j]->getMax();              /*!< get max temp if warmer than previous max */
            }
            if (day[i][j]->getMin() <= min)
            {
                min = day[i][j]->getMin();              /*!< get min temp if colder than previous min */
            }
            if(j == 4)
            {
                date = day[i][j]->getDate();            /*!< set the average day's time to noon */
                desc = day[i][j]->getDescription();     /*!< set the average day's description to the weather at noon */
            }
        }
        avgTemp = (avgTemp/7);
        avgHum = avgHum/7;
        day[i][0] = new Day(date, avgTemp, totPrec, max, min, desc, avgHum);
    }
}
