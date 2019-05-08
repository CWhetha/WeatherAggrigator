/*! \file mainwindow.h
    @brief sets up the front end user interface window
    @authors: Christian, Connor, Curtis, Matthew, Austin
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui 
{
    class MainWindow;
}

class MainWindow : public QMainWindow /*! \class MainWindow class */
{
    Q_OBJECT

public:
    
    /*! \fn explicit MainWindow(QWidget *parent = nullptr);
        @brief sets up the main window
        @param *parent null pointer
    */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    
    /*! \fn void on_GetTodaysForecast_clicked();
        @brief gets today's forecast when clicked on the UI
    */
    void on_GetTodaysForecast_clicked();
    
    /*! \fn void on_GetTomorrowssForecast_clicked();
        @brief gets tomorrows forecast when clicked on the UI
    */
    void on_GetTomorrowsForecast_clicked();

    /*! \fn void on_GetThreeDayForecast_clicked();
        @brief gets the next three days forecast when clicked on the UI
    */
    void on_GetThreeDayForecast_clicked();

    /*! \fn void on_Graph24hourforecast_clicked();
        \brief gets the 24hr forecast (every 3 hours) when clicked on the UI
    */
    void on_Graph24hourforecast_clicked();

    /*! \fn void onedaygraph(std::string city);
        @brief displays the weather graph for a day
        @param city the city where we're looking at the weather
    */
    void onedaygraph(std::string city);

    /*! \fn void Grapher::makegraph(QVector<double> *x1,QVector<double> *x2,QVector<double> *y1,QVector<double> *y2,int yMax1,int yMax2,Ui::MainWindow* ui);
        @param *x1 tempurature x-axis
        @param *x2 precipitation x-axis
        @param *y1 tempurature y-axis
        @param *y2 precipitation y-axis
        @param yMax1 max tempurature
        @param yMax2 max precipitation
        @param xMax max value in x-axis (number of hours)
    */
    void makegraph(QVector<double> *x1,QVector<double> *x2, QVector<double> *y1,QVector<double> *y2, int yMax1, int yMax2,int xMax, int yMin1, int yMin2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
