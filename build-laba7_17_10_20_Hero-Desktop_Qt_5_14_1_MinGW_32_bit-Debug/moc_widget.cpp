/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../laba7_17_10_20_Hero/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[19];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 21), // "on_maleButton_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 23), // "on_femaleButton_clicked"
QT_MOC_LITERAL(4, 54, 18), // "on_age_textChanged"
QT_MOC_LITERAL(5, 73, 4), // "arg1"
QT_MOC_LITERAL(6, 78, 19), // "on_name_textChanged"
QT_MOC_LITERAL(7, 98, 22), // "on_plusButton1_clicked"
QT_MOC_LITERAL(8, 121, 22), // "on_plusButton2_clicked"
QT_MOC_LITERAL(9, 144, 22), // "on_plusButton3_clicked"
QT_MOC_LITERAL(10, 167, 22), // "on_plusButton4_clicked"
QT_MOC_LITERAL(11, 190, 23), // "on_minusButton1_clicked"
QT_MOC_LITERAL(12, 214, 23), // "on_minusButton2_clicked"
QT_MOC_LITERAL(13, 238, 23), // "on_minusButton3_clicked"
QT_MOC_LITERAL(14, 262, 23), // "on_minusButton4_clicked"
QT_MOC_LITERAL(15, 286, 23), // "on_creataButton_clicked"
QT_MOC_LITERAL(16, 310, 19), // "onPlusButtonClicked"
QT_MOC_LITERAL(17, 330, 5), // "score"
QT_MOC_LITERAL(18, 336, 20) // "onMinusButtonClicked"

    },
    "Widget\0on_maleButton_clicked\0\0"
    "on_femaleButton_clicked\0on_age_textChanged\0"
    "arg1\0on_name_textChanged\0"
    "on_plusButton1_clicked\0on_plusButton2_clicked\0"
    "on_plusButton3_clicked\0on_plusButton4_clicked\0"
    "on_minusButton1_clicked\0on_minusButton2_clicked\0"
    "on_minusButton3_clicked\0on_minusButton4_clicked\0"
    "on_creataButton_clicked\0onPlusButtonClicked\0"
    "score\0onMinusButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       7,    0,   97,    2, 0x08 /* Private */,
       8,    0,   98,    2, 0x08 /* Private */,
       9,    0,   99,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    1,  106,    2, 0x08 /* Private */,
      18,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_maleButton_clicked(); break;
        case 1: _t->on_femaleButton_clicked(); break;
        case 2: _t->on_age_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_plusButton1_clicked(); break;
        case 5: _t->on_plusButton2_clicked(); break;
        case 6: _t->on_plusButton3_clicked(); break;
        case 7: _t->on_plusButton4_clicked(); break;
        case 8: _t->on_minusButton1_clicked(); break;
        case 9: _t->on_minusButton2_clicked(); break;
        case 10: _t->on_minusButton3_clicked(); break;
        case 11: _t->on_minusButton4_clicked(); break;
        case 12: _t->on_creataButton_clicked(); break;
        case 13: _t->onPlusButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->onMinusButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
