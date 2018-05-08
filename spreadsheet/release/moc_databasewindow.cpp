/****************************************************************************
** Meta object code from reading C++ file 'databasewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../databasewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseWindow_t {
    QByteArrayData data[19];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseWindow_t qt_meta_stringdata_DatabaseWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DatabaseWindow"
QT_MOC_LITERAL(1, 15, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "on_allButton_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(5, 82, 26), // "on_archiveCheckBox_toggled"
QT_MOC_LITERAL(6, 109, 7), // "checked"
QT_MOC_LITERAL(7, 117, 29), // "on_cancelSearchButton_clicked"
QT_MOC_LITERAL(8, 147, 20), // "on_fmrButton_clicked"
QT_MOC_LITERAL(9, 168, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(10, 194, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(11, 217, 26), // "on_motostyleButton_clicked"
QT_MOC_LITERAL(12, 244, 23), // "on_removeButton_clicked"
QT_MOC_LITERAL(13, 268, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(14, 290, 14), // "recordSelected"
QT_MOC_LITERAL(15, 305, 13), // "onDataChanged"
QT_MOC_LITERAL(16, 319, 7), // "topLeft"
QT_MOC_LITERAL(17, 327, 11), // "bottomRight"
QT_MOC_LITERAL(18, 339, 21) // "on_pushButton_clicked"

    },
    "DatabaseWindow\0on_addButton_clicked\0"
    "\0on_allButton_clicked\0on_cancelButton_clicked\0"
    "on_archiveCheckBox_toggled\0checked\0"
    "on_cancelSearchButton_clicked\0"
    "on_fmrButton_clicked\0on_lineEdit_returnPressed\0"
    "on_lineEdit_textEdited\0"
    "on_motostyleButton_clicked\0"
    "on_removeButton_clicked\0on_saveButton_clicked\0"
    "recordSelected\0onDataChanged\0topLeft\0"
    "bottomRight\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    2,   98,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   16,   17,
    QMetaType::Void,

       0        // eod
};

void DatabaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseWindow *_t = static_cast<DatabaseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addButton_clicked(); break;
        case 1: _t->on_allButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->on_archiveCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_cancelSearchButton_clicked(); break;
        case 5: _t->on_fmrButton_clicked(); break;
        case 6: _t->on_lineEdit_returnPressed(); break;
        case 7: _t->on_lineEdit_textEdited(); break;
        case 8: _t->on_motostyleButton_clicked(); break;
        case 9: _t->on_removeButton_clicked(); break;
        case 10: _t->on_saveButton_clicked(); break;
        case 11: _t->recordSelected(); break;
        case 12: _t->onDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 13: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DatabaseWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DatabaseWindow.data,
      qt_meta_data_DatabaseWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseWindow.stringdata0))
        return static_cast<void*>(const_cast< DatabaseWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DatabaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
