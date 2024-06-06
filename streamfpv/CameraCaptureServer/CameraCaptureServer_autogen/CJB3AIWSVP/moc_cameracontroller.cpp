/****************************************************************************
** Meta object code from reading C++ file 'cameracontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../includes/cameracontroller.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameracontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CameraController_t {
    uint offsetsAndSizes[12];
    char stringdata0[17];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[8];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CameraController_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CameraController_t qt_meta_stringdata_CameraController = {
    {
        QT_MOC_LITERAL(0, 16),  // "CameraController"
        QT_MOC_LITERAL(17, 20),  // "setDestinationAddres"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 12),  // "QHostAddress"
        QT_MOC_LITERAL(52, 7),  // "control"
        QT_MOC_LITERAL(60, 14)   // "lostConnection"
    },
    "CameraController",
    "setDestinationAddres",
    "",
    "QHostAddress",
    "control",
    "lostConnection"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CameraController[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   37,    2, 0x09,    4 /* Protected */,
       5,    0,   38,    2, 0x09,    5 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CameraController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CameraController.offsetsAndSizes,
    qt_meta_data_CameraController,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CameraController_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CameraController, std::true_type>,
        // method 'setDestinationAddres'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned short, std::false_type>,
        // method 'control'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lostConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CameraController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CameraController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setDestinationAddres((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ushort>>(_a[2]))); break;
        case 1: _t->control(); break;
        case 2: _t->lostConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CameraController::*)(QHostAddress , unsigned short );
            if (_t _q_method = &CameraController::setDestinationAddres; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *CameraController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CameraController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CameraController::setDestinationAddres(QHostAddress _t1, unsigned short _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
