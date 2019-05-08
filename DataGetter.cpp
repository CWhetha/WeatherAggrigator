/*! \file DataGetter.cpp
    @brief program that gets the weather information we are using from an API
    @authors: Matthew, Austin, Curtis, Connor, Christian
*/
#include "DataGetter.h"
#include "DayFactory.h"

using namespace std;

DataGetter::DataGetter() {}

/* \fn Day ** DataGetter::GetDayForecast(string city)
   @brief Gets the weather forecast from a URL and API key
   @param city The city for which to get the forecast for.
   @return df.GetDay the weather forecast information
*/
Day * DataGetter::GetDayForecast(string city)
{
    string strUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + city + ",ca&APPID=" + API_KEY;
    char url[strUrl.length() + 1];
    strcpy(url, strUrl.c_str());

    GetUrlContents(url);

    DayFactory df = DayFactory("urlContents.json");
    return df.GetDay();
}

/* \fn Day ** DataGetter::GetForecast(string city)
   @brief Gets the forecast for the next 5 days.
   @param city The city for which to get the forecast for.
   @return ff.GetDayArray An array of the Days in the forecast.
*/
Day ** DataGetter::GetForecast(string city)
{
    string strUrl = "http://api.openweathermap.org/data/2.5/forecast?q=" + city + ",ca&APPID=" + API_KEY;
    char url[strUrl.length() + 1];
    strcpy(url, strUrl.c_str());

    GetUrlContents(url);

    ForecastFactory ff = ForecastFactory("urlContents.json");
    return ff.GetDayArray();
}

/*! \fn string DataGetter::GetUrlContents(char *url)
    @brief Gets the contents from the given URL.
    @param url The URL to access.
    @return output The contents of the page as a string.
*/
void DataGetter::GetUrlContents(char *url)
{    
    CURL *curl;
    CURLcode res;
    string output;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        ofstream out("urlContents.json");
        out << output;
    }
}
/*! \fn size_t DataGetter::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    @brief Gets the total data size of the contents
    @param contents contents of the url
    @param size size of one data item
    @param nmemb number of data members
    @param userp used for server authentication when accessing API
    @return size * nmemb The total size of the contents.
*/
size_t DataGetter::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
