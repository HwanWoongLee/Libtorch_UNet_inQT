/****************************************************************************
** Meta object code from reading C++ file 'QSeg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QSeg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSeg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSeg_t {
    QByteArrayData data[17];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSeg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSeg_t qt_meta_stringdata_QSeg = {
    {
QT_MOC_LITERAL(0, 0, 4), // "QSeg"
QT_MOC_LITERAL(1, 5, 13), // "ButtonClicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "RadioClicked"
QT_MOC_LITERAL(4, 33, 20), // "ChangedDataTableItem"
QT_MOC_LITERAL(5, 54, 21), // "ChangedLabelTableItem"
QT_MOC_LITERAL(6, 76, 20), // "ChangedTestTableItem"
QT_MOC_LITERAL(7, 97, 14), // "SetProgressBar"
QT_MOC_LITERAL(8, 112, 4), // "iVal"
QT_MOC_LITERAL(9, 117, 4), // "iMax"
QT_MOC_LITERAL(10, 122, 18), // "SetCustomPlotValue"
QT_MOC_LITERAL(11, 141, 5), // "epoch"
QT_MOC_LITERAL(12, 147, 10), // "train_loss"
QT_MOC_LITERAL(13, 158, 8), // "val_loss"
QT_MOC_LITERAL(14, 167, 9), // "TrainStop"
QT_MOC_LITERAL(15, 177, 10), // "TrainStart"
QT_MOC_LITERAL(16, 188, 12) // "EditFinished"

    },
    "QSeg\0ButtonClicked\0\0RadioClicked\0"
    "ChangedDataTableItem\0ChangedLabelTableItem\0"
    "ChangedTestTableItem\0SetProgressBar\0"
    "iVal\0iMax\0SetCustomPlotValue\0epoch\0"
    "train_loss\0val_loss\0TrainStop\0TrainStart\0"
    "EditFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSeg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    2,   69,    2, 0x08 /* Private */,
      10,    3,   74,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Double,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSeg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSeg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ButtonClicked(); break;
        case 1: _t->RadioClicked(); break;
        case 2: _t->ChangedDataTableItem(); break;
        case 3: _t->ChangedLabelTableItem(); break;
        case 4: _t->ChangedTestTableItem(); break;
        case 5: _t->SetProgressBar((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->SetCustomPlotValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 7: _t->TrainStop(); break;
        case 8: _t->TrainStart(); break;
        case 9: _t->EditFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSeg::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QSeg.data,
    qt_meta_data_QSeg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSeg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSeg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSeg.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QSeg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
