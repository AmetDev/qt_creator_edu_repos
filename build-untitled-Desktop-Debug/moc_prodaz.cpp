/****************************************************************************
** Meta object code from reading C++ file 'prodaz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../untitled/prodaz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prodaz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Prodaz_t {
    QByteArrayData data[13];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Prodaz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Prodaz_t qt_meta_stringdata_Prodaz = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Prodaz"
QT_MOC_LITERAL(1, 7, 15), // "deleteObjProdaz"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "addSvedeniya"
QT_MOC_LITERAL(4, 37, 15), // "updateObjProdaz"
QT_MOC_LITERAL(5, 53, 12), // "goBackWindow"
QT_MOC_LITERAL(6, 66, 17), // "displayDataProdaz"
QT_MOC_LITERAL(7, 84, 8), // "queryStr"
QT_MOC_LITERAL(8, 93, 15), // "addNewObjProdaz"
QT_MOC_LITERAL(9, 109, 15), // "addItemNameBook"
QT_MOC_LITERAL(10, 125, 17), // "comboBoxActivated"
QT_MOC_LITERAL(11, 143, 5), // "index"
QT_MOC_LITERAL(12, 149, 21) // "comboBoxActivatedSved"

    },
    "Prodaz\0deleteObjProdaz\0\0addSvedeniya\0"
    "updateObjProdaz\0goBackWindow\0"
    "displayDataProdaz\0queryStr\0addNewObjProdaz\0"
    "addItemNameBook\0comboBoxActivated\0"
    "index\0comboBoxActivatedSved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Prodaz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Prodaz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Prodaz *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deleteObjProdaz(); break;
        case 1: _t->addSvedeniya(); break;
        case 2: _t->updateObjProdaz(); break;
        case 3: _t->goBackWindow(); break;
        case 4: _t->displayDataProdaz((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->addNewObjProdaz(); break;
        case 6: _t->addItemNameBook(); break;
        case 7: _t->comboBoxActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->comboBoxActivatedSved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Prodaz::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Prodaz.data,
    qt_meta_data_Prodaz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Prodaz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Prodaz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Prodaz.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Prodaz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
