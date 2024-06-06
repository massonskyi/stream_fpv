/****************************************************************************
** Meta object code from reading C++ file 'updateipsarray.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../VisorShowClient/includes/updateipsarray.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updateipsarray.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_UpdateIpsArray_t {
    uint offsetsAndSizes[10];
    char stringdata0[15];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[38];
    char stringdata4[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_UpdateIpsArray_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_UpdateIpsArray_t qt_meta_stringdata_UpdateIpsArray = {
    {
        QT_MOC_LITERAL(0, 14),  // "UpdateIpsArray"
        QT_MOC_LITERAL(15, 15),  // "sendNetworkList"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 37),  // "QList<std::vector<CmdUtils::A..."
        QT_MOC_LITERAL(70, 14)   // "getNetworkList"
    },
    "UpdateIpsArray",
    "sendNetworkList",
    "",
    "QList<std::vector<CmdUtils::ArpInfo>>",
    "getNetworkList"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_UpdateIpsArray[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UpdateIpsArray::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UpdateIpsArray.offsetsAndSizes,
    qt_meta_data_UpdateIpsArray,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_UpdateIpsArray_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UpdateIpsArray, std::true_type>,
        // method 'sendNetworkList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<std::vector<CmdUtils::ArpInfo>>, std::false_type>,
        // method 'getNetworkList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UpdateIpsArray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UpdateIpsArray *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendNetworkList((*reinterpret_cast< std::add_pointer_t<QList<std::vector<CmdUtils::ArpInfo>>>>(_a[1]))); break;
        case 1: _t->getNetworkList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UpdateIpsArray::*)(QVector<std::vector<CmdUtils::ArpInfo>> );
            if (_t _q_method = &UpdateIpsArray::sendNetworkList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *UpdateIpsArray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpdateIpsArray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateIpsArray.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UpdateIpsArray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void UpdateIpsArray::sendNetworkList(QVector<std::vector<CmdUtils::ArpInfo>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
