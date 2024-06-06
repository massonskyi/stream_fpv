/****************************************************************************
** Meta object code from reading C++ file 'capturesender.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../includes/capturesender.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capturesender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_CaptureSender_t {
    uint offsetsAndSizes[20];
    char stringdata0[14];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[13];
    char stringdata5[4];
    char stringdata6[6];
    char stringdata7[5];
    char stringdata8[8];
    char stringdata9[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CaptureSender_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CaptureSender_t qt_meta_stringdata_CaptureSender = {
    {
        QT_MOC_LITERAL(0, 13),  // "CaptureSender"
        QT_MOC_LITERAL(14, 4),  // "init"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 14),  // "setDestination"
        QT_MOC_LITERAL(35, 12),  // "QHostAddress"
        QT_MOC_LITERAL(48, 3),  // "_ip"
        QT_MOC_LITERAL(52, 5),  // "_port"
        QT_MOC_LITERAL(58, 4),  // "send"
        QT_MOC_LITERAL(63, 7),  // "cv::Mat"
        QT_MOC_LITERAL(71, 6)   // "_frame"
    },
    "CaptureSender",
    "init",
    "",
    "setDestination",
    "QHostAddress",
    "_ip",
    "_port",
    "send",
    "cv::Mat",
    "_frame"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CaptureSender[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    2,   33,    2, 0x0a,    2 /* Public */,
       7,    1,   38,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Short,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject CaptureSender::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CaptureSender.offsetsAndSizes,
    qt_meta_data_CaptureSender,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CaptureSender_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CaptureSender, std::true_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setDestination'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<short, std::false_type>,
        // method 'send'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>
    >,
    nullptr
} };

void CaptureSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaptureSender *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->setDestination((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<short>>(_a[2]))); break;
        case 2: _t->send((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *CaptureSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CaptureSender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CaptureSender.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CaptureSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
