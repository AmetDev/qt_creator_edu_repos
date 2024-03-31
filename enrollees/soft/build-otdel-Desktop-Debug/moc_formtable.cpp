/****************************************************************************
** Meta object code from reading C++ file 'formtable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../otdel/formtable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formtable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormTable_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormTable_t qt_meta_stringdata_FormTable = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FormTable"
QT_MOC_LITERAL(1, 10, 14), // "deleteDataById"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "tableName"
QT_MOC_LITERAL(4, 36, 2), // "id"
QT_MOC_LITERAL(5, 39, 11), // "connectToDB"
QT_MOC_LITERAL(6, 51, 10), // "deleteData"
QT_MOC_LITERAL(7, 62, 18), // "tableButtonClicked"
QT_MOC_LITERAL(8, 81, 10), // "updateData"
QT_MOC_LITERAL(9, 92, 31), // "QList<QPair<QString,QWidget*> >"
QT_MOC_LITERAL(10, 124, 12), // "inputWidgets"
QT_MOC_LITERAL(11, 137, 15), // "updateTableView"
QT_MOC_LITERAL(12, 153, 7) // "addData"

    },
    "FormTable\0deleteDataById\0\0tableName\0"
    "id\0connectToDB\0deleteData\0tableButtonClicked\0"
    "updateData\0QList<QPair<QString,QWidget*> >\0"
    "inputWidgets\0updateTableView\0addData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormTable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    2,   57,    2, 0x08 /* Private */,
      11,    1,   62,    2, 0x08 /* Private */,
      12,    2,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,    3,

       0        // eod
};

void FormTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormTable *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deleteDataById((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->connectToDB(); break;
        case 2: _t->deleteData(); break;
        case 3: _t->tableButtonClicked(); break;
        case 4: _t->updateData((*reinterpret_cast< const QList<QPair<QString,QWidget*> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->updateTableView((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->addData((*reinterpret_cast< const QList<QPair<QString,QWidget*> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormTable.data,
    qt_meta_data_FormTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormTable.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
