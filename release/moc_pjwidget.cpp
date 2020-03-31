/****************************************************************************
** Meta object code from reading C++ file 'pjwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/dh/Desktop/pjlink/epsonControl-master/pjwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pjwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pjWidget_t {
    QByteArrayData data[14];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pjWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pjWidget_t qt_meta_stringdata_pjWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "pjWidget"
QT_MOC_LITERAL(1, 9, 14), // "sigPjConnected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "sigPjDisconnected"
QT_MOC_LITERAL(4, 43, 11), // "pjConnected"
QT_MOC_LITERAL(5, 55, 14), // "pjDisconnected"
QT_MOC_LITERAL(6, 70, 13), // "on_on_clicked"
QT_MOC_LITERAL(7, 84, 14), // "on_off_clicked"
QT_MOC_LITERAL(8, 99, 17), // "updateLampStatus1"
QT_MOC_LITERAL(9, 117, 17), // "updateLampStatus2"
QT_MOC_LITERAL(10, 135, 17), // "updateLampStatus3"
QT_MOC_LITERAL(11, 153, 17), // "updateLampStatus4"
QT_MOC_LITERAL(12, 171, 9), // "reconnect"
QT_MOC_LITERAL(13, 181, 13) // "reconnectSlot"

    },
    "pjWidget\0sigPjConnected\0\0sigPjDisconnected\0"
    "pjConnected\0pjDisconnected\0on_on_clicked\0"
    "on_off_clicked\0updateLampStatus1\0"
    "updateLampStatus2\0updateLampStatus3\0"
    "updateLampStatus4\0reconnect\0reconnectSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pjWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void,

       0        // eod
};

void pjWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pjWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigPjConnected(); break;
        case 1: _t->sigPjDisconnected(); break;
        case 2: _t->pjConnected(); break;
        case 3: _t->pjDisconnected(); break;
        case 4: _t->on_on_clicked(); break;
        case 5: _t->on_off_clicked(); break;
        case 6: _t->updateLampStatus1(); break;
        case 7: _t->updateLampStatus2(); break;
        case 8: _t->updateLampStatus3(); break;
        case 9: _t->updateLampStatus4(); break;
        case 10: _t->reconnect(); break;
        case 11: _t->reconnectSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pjWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pjWidget::sigPjConnected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pjWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pjWidget::sigPjDisconnected)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject pjWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_pjWidget.data,
    qt_meta_data_pjWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pjWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pjWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pjWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int pjWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void pjWidget::sigPjConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pjWidget::sigPjDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
