/*! \file mainwindow.cpp
    @brief The front end userface that displays weather information
    @authors: Christian, Connor, Matthew, Curtis, Austin
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "DataGetter.h"
#include "Day.h"
#include "ForecastFactory.h"
#include <iostream>
#include <sstream>

/*! \fn explicit MainWindow(QWidget *parent = nullptr);
    @brief sets up the main window
    @param *parent null pointer
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Weather Aggregator");
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(20, 170, 255));
    plotGradient.setColorAt(1, QColor(20, 20, 140));
    ui->plot->setBackground(plotGradient);
    ui->plot->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*! \fn void on_GetTodaysForecast_clicked();
    @brief gets today's forecast when clicked on the UI
*/
void MainWindow::on_GetTodaysForecast_clicked()
{
    DataGetter dg = DataGetter();
    stringstream result;
    result << "Weather for Today:\n\n";

    Day *day = dg.GetDayForecast(ui->comboBox->currentText().toUtf8().constData());
    result << "Date: " << day->getDate().substr(0, day->getDate().find(' ')) << "\n";
    result << "Average Temperature: " << day->getTemp() << "\n";
    result << "Precipitation: " << day->getPrec() << "\n";
    result << "Temperature High: " << day->getMax() << "\n";
    result << "Temperature Low: " << day->getMin() << "\n";
    result << "Description: " << day->getDescription() << "\n";
    ui->Forcast->setText(QString::fromStdString(result.str()));
}

/*! \fn void on_GetTomorrowssForecast_clicked();
    @brief gets tomorrows forecast when clicked on the UI
*/
void MainWindow::on_GetTomorrowsForecast_clicked()
{
    DataGetter dg = DataGetter();
    stringstream result;
    result << "Weather for tomorrow:\n\n";

    Day **dayArray = dg.GetForecast(ui->comboBox->currentText().toUtf8().constData());
    Day day = dayArray[0][0];
    result << "Date: " << day.getDate().substr(0, day.getDate().find(' ')) << "\n";
    result << "Average Temperature: " << day.getTemp() << "\n";
    result << "Precipitation: " << day.getPrec() << "\n";
    result << "Temperature High: " << day.getMax() << "\n";
    result << "Temperature Low: " << day.getMin() << "\n";
    result << "Description: " << day.getDescription() << "\n";
    ui->Forcast->setText(QString::fromStdString(result.str()));
}

/*! \fn void on_GetThreeDayForecast_clicked();
    @brief gets the next three days forecast when clicked on the UI
*/
void MainWindow::on_GetThreeDayForecast_clicked()
{
    DataGetter dg = DataGetter();
    stringstream result;

    result << "\t       Min | Max | Rain/Snow | Description\n\n";

    Day **dayArray = dg.GetForecast(ui->comboBox->currentText().toUtf8().constData());
    Day day1= dayArray[0][0];
    Day day2= dayArray[8][0];
    Day day3= dayArray[16][0];

    result <<  day1.getDate().substr(0, day1.getDate().find(' ')) << ":    " << day1.getMin() << "\t   " << day1.getMax();
    result << "\t" << day1.getPrec() << "\t   " << day1.getDescription() << "\n";
    result <<  day2.getDate().substr(0, day2.getDate().find(' ')) << ":    " << day2.getMin() << "\t   " << day2.getMax();
    result << "\t" << day2.getPrec() << "\t   " << day2.getDescription() << "\n";
    result <<  day3.getDate().substr(0, day3.getDate().find(' ')) << ":    " << day3.getMin() << "\t   " << day3.getMax();
    result << "\t" << day3.getPrec() << "\t   " << day3.getDescription() << "\n";

    ui->Forcast->setText(QString::fromStdString(result.str()));
}

/*! \fn void on_Graph24hourforecast_clicked();
    @brief gets the 24hr forecast (every 3 hours) when clicked on the UI
*/
void MainWindow::on_Graph24hourforecast_clicked()
{
    ui->plot->clearPlottables();
    MainWindow::onedaygraph(ui->comboBox->currentText().toUtf8().constData());
}

/*! \fn void onedaygraph(std::string city);
    @brief displays the weather graph for a day
    @param city the city where we're looking at the weather
*/
void MainWindow::onedaygraph(std::string city)
{
    int selection;
    int y;

    if (ui->comboBox_2->currentText() == "Tomorrow") {
        selection = 8;
        y = 1;
    } else if (ui->comboBox_2->currentText() == "Two Days From Now") {
        selection = 16;
        y = 9;
    } else if (ui->comboBox_2->currentText() == "Three Days From Now") {
        selection = 24;
        y = 17;
    }
    DataGetter getter= DataGetter();
    QVector<double> x1(8), y1(8);
    QVector<double> x2(8), y2(8);
    int yMax1=0, yMax2=0,xMax=0,z=1, yMin1=0, yMin2=0;
    Day **list = getter.GetForecast(city);
    while (y<selection)
    {
        x1[z]=list[y][0].getTemp();
        if (x1[z]>yMax1)
        {
            yMax1=x1[z]+3;
        }

        if (x1[z]<yMin1)
        {
            yMin1 = x1[z]-3;
        }

        x2[z]=list[y][0].getPrec();
        if (x2[z]>yMax2)
        {
            yMax2=x2[z]+3;
        }

        if (x2[z]<yMin2)
        {
            yMin2 = x2[z]-3;
        }

        y1[z]=(z*3);
        y2[z]=(z*3);
        z++;
        y++;
    }
    xMax=(z*3);

    MainWindow::makegraph(&x1,&x2,&y1,&y2,yMax1,yMax2,xMax,yMin1,yMin2);
}

/*! \fn void Grapher::makegraph(QVector<double> *x1,QVector<double> *x2,QVector<double> *y1,QVector<double> *y2,int yMax1,int yMax2,Ui::MainWindow* ui);
    @param *x1 tempurature x-axis
    @param *x2 precipitation x-axis
    @param *y1 tempurature y-axis
    @param *y2 precipitation second y-axis
    @param yMax1 max tempurature
    @param yMax2 max precipitation
    @param xMax max value in x-axis (number of hours)
*/
void MainWindow::makegraph(QVector<double> *x1,QVector<double> *x2, QVector<double> *y1,QVector<double> *y2, int yMax1, int yMax2, int xMax, int yMin1, int yMin2)
{
ui->plot->legend->setVisible(true);

/*!< create and configure plottables: */
QCPGraph *graph1 = ui->plot->addGraph();
graph1->setName("Temperature");
graph1->setData(*y1, *x1);
graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
graph1->setPen(QPen(QColor(120, 120, 120), 2));

QCPBars *bars1 = new QCPBars(ui->plot->xAxis, ui->plot->yAxis2);
bars1->setName("Percipitation");
bars1->setWidth(10/(double)x2->size());
bars1->setData(*y2, *x2);
bars1->setPen(Qt::NoPen);
bars1->setBrush(QColor(10, 140, 70, 160));

/*!< move bars above graphs and grid below bars: */
ui->plot->addLayer("abovemain", ui->plot->layer("main"), QCustomPlot::limAbove);
ui->plot->addLayer("belowmain", ui->plot->layer("main"), QCustomPlot::limBelow);
graph1->setLayer("abovemain");
ui->plot->xAxis->grid()->setLayer("belowmain");
ui->plot->yAxis->grid()->setLayer("belowmain");
ui->plot->yAxis2->grid()->setLayer("belowmain");
ui->plot->yAxis2->setVisible(true);
/*!< set some pens, brushes and backgrounds: */
ui->plot->xAxis->setBasePen(QPen(Qt::white, 1));
ui->plot->yAxis->setBasePen(QPen(Qt::white, 1));
ui->plot->yAxis2->setBasePen(QPen(Qt::white, 1));
ui->plot->xAxis->setTickPen(QPen(Qt::white, 1));
ui->plot->yAxis->setTickPen(QPen(Qt::white, 1));
ui->plot->yAxis2->setTickPen(QPen(Qt::white, 1));
ui->plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
ui->plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
ui->plot->yAxis2->setSubTickPen(QPen(Qt::white, 1));
ui->plot->xAxis->setTickLabelColor(Qt::white);
ui->plot->yAxis->setTickLabelColor(Qt::white);
ui->plot->yAxis2->setTickLabelColor(Qt::white);
ui->plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
ui->plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
ui->plot->yAxis2->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
ui->plot->yAxis2->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
ui->plot->xAxis->grid()->setSubGridVisible(true);
ui->plot->yAxis->grid()->setSubGridVisible(true);
ui->plot->yAxis2->grid()->setSubGridVisible(true);
ui->plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
ui->plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
ui->plot->yAxis2->grid()->setZeroLinePen(Qt::NoPen);
ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
ui->plot->yAxis2->setUpperEnding(QCPLineEnding::esSpikeArrow);
QLinearGradient plotGradient;
plotGradient.setStart(0, 0);
plotGradient.setFinalStop(0, 350);
plotGradient.setColorAt(0, QColor(20, 170, 255));
plotGradient.setColorAt(1, QColor(20, 20, 140));
ui->plot->setBackground(plotGradient);
QLinearGradient axisRectGradient;
axisRectGradient.setStart(0, 0);
axisRectGradient.setFinalStop(0, 350);
axisRectGradient.setColorAt(0, QColor(80, 80, 80));
axisRectGradient.setColorAt(1, QColor(30, 30, 30));
ui->plot->axisRect()->setBackground(axisRectGradient);

ui->plot->yAxis->setLabel("Temperature");
ui->plot->yAxis2->setLabel("Percipitation");
ui->plot->xAxis->setLabel("Hours");

ui->plot->rescaleAxes();
ui->plot->xAxis->setRange(0, xMax);
ui->plot->yAxis->setRange(yMin1, yMax1);
ui->plot->yAxis2->setRange(yMin2, yMax2);
ui->plot->replot();
ui->plot->update();
}
