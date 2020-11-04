/****************************************************************************
** Meta object code from reading C++ file 'boolcalc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../laba5_03_10_20_bool_calc/boolcalc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boolcalc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_boolcalc_t {
    QByteArrayData data[9];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_boolcalc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_boolcalc_t qt_meta_stringdata_boolcalc = {
    {
QT_MOC_LITERAL(0, 0, 8), // "boolcalc"
QT_MOC_LITERAL(1, 9, 12), // "updateWindow"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 22), // "on_operation_activated"
QT_MOC_LITERAL(4, 46, 5), // "index"
QT_MOC_LITERAL(5, 52, 16), // "on_op1_activated"
QT_MOC_LITERAL(6, 69, 16), // "on_op2_activated"
QT_MOC_LITERAL(7, 86, 31), // "on_demonstration_button_clicked"
QT_MOC_LITERAL(8, 118, 15) // "updateDemoState"

    },
    "boolcalc\0updateWindow\0\0on_operation_activated\0"
    "index\0on_op1_activated\0on_op2_activated\0"
    "on_demonstration_button_clicked\0"
    "updateDemoState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_boolcalc[] = {

 // content:
       8,       // revision
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
       3,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void boolcalc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<boolcalc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateWindow(); break;
        case 1: _t->on_operation_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_op1_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_op2_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_demonstration_button_clicked(); break;
        case 5: _t->updateDemoState(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject boolcalc::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_boolcalc.data,
    qt_meta_data_boolcalc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *boolcalc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *boolcalc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_boolcalc.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int boolcalc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
