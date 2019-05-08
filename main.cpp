/*! \file main.cpp
    @brief executes the compiler
    @authors: Christian, Connor, Matthew, Austin, Curtis
*/
#include "mainwindow.h"
#include <QApplication>
#include "DataGetter.h"
#include "Day.h"
#include "ForecastFactory.h"
#include <strings.h>
#include <iostream>
#include <sstream>
#include <cstring>
/* \fn int main(int argc, char *argv[])
 * @brief main executes the compiler
 * @return a.exec(); executes the compiler
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
