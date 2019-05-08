/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../repo/group11/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "on_GetTodaysForecast_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 31), // "on_GetTomorrowsForecast_clicked"
QT_MOC_LITERAL(4, 73, 30), // "on_GetThreeDayForecast_clicked"
QT_MOC_LITERAL(5, 104, 30), // "on_Graph24hourforecast_clicked"
QT_MOC_LITERAL(6, 135, 11), // "onedaygraph"
QT_MOC_LITERAL(7, 147, 11), // "std::string"
QT_MOC_LITERAL(8, 159, 4), // "city"
QT_MOC_LITERAL(9, 164, 9), // "makegraph"
QT_MOC_LITERAL(10, 174, 16), // "QVector<double>*"
QT_MOC_LITERAL(11, 191, 2), // "x1"
QT_MOC_LITERAL(12, 194, 2), // "x2"
QT_MOC_LITERAL(13, 197, 2), // "y1"
QT_MOC_LITERAL(14, 200, 2), // "y2"
QT_MOC_LITERAL(15, 203, 5), // "yMax1"
QT_MOC_LITERAL(16, 209, 5), // "yMax2"
QT_MOC_LITERAL(17, 215, 4), // "xMax"
QT_MOC_LITERAL(18, 220, 5), // "yMin1"
QT_MOC_LITERAL(19, 226, 5) // "yMin2"

    },
    "MainWindow\0on_GetTodaysForecast_clicked\0"
    "\0on_GetTomorrowsForecast_clicked\0"
    "on_GetThreeDayForecast_clicked\0"
    "on_Graph24hourforecast_clicked\0"
    "onedaygraph\0std::string\0city\0makegraph\0"
    "QVector<double>*\0x1\0x2\0y1\0y2\0yMax1\0"
    "yMax2\0xMax\0yMin1\0yMin2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       9,    9,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,   15,   16,   17,   18,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_GetTodaysForecast_clicked(); break;
        case 1: _t->on_GetTomorrowsForecast_clicked(); break;
        case 2: _t->on_GetThreeDayForecast_clicked(); break;
        case 3: _t->on_Graph24hourforecast_clicked(); break;
        case 4: _t->onedaygraph((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->makegraph((*reinterpret_cast< QVector<double>*(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< QVector<double>*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
