/****************************************************************************
** Meta object code from reading C++ file 'kupagui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kupa-gui-2/kupagui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kupagui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_kupagui_t {
    QByteArrayData data[11];
    char stringdata[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_kupagui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_kupagui_t qt_meta_stringdata_kupagui = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 21),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 34),
QT_MOC_LITERAL(4, 66, 31),
QT_MOC_LITERAL(5, 98, 27),
QT_MOC_LITERAL(6, 126, 22),
QT_MOC_LITERAL(7, 149, 30),
QT_MOC_LITERAL(8, 180, 27),
QT_MOC_LITERAL(9, 208, 24),
QT_MOC_LITERAL(10, 233, 31)
    },
    "kupagui\0on_button_run_clicked\0\0"
    "on_button_generate_command_clicked\0"
    "on_actionLoad_Command_triggered\0"
    "on_button_getResult_clicked\0"
    "on_actionRUN_triggered\0"
    "on_actionSave_Result_triggered\0"
    "on_actionEdit_XML_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionSave_Command_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_kupagui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    0,   65,    2, 0x08,
       9,    0,   66,    2, 0x08,
      10,    0,   67,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void kupagui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        kupagui *_t = static_cast<kupagui *>(_o);
        switch (_id) {
        case 0: _t->on_button_run_clicked(); break;
        case 1: _t->on_button_generate_command_clicked(); break;
        case 2: _t->on_actionLoad_Command_triggered(); break;
        case 3: _t->on_button_getResult_clicked(); break;
        case 4: _t->on_actionRUN_triggered(); break;
        case 5: _t->on_actionSave_Result_triggered(); break;
        case 6: _t->on_actionEdit_XML_triggered(); break;
        case 7: _t->on_actionAbout_triggered(); break;
        case 8: _t->on_actionSave_Command_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject kupagui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_kupagui.data,
      qt_meta_data_kupagui,  qt_static_metacall, 0, 0}
};


const QMetaObject *kupagui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *kupagui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_kupagui.stringdata))
        return static_cast<void*>(const_cast< kupagui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int kupagui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
