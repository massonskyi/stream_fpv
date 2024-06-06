/****************************************************************************
** Meta object code from reading C++ file 'visorgui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../VisorShowClient/includes/visorgui.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visorgui.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_VisorGUI_t {
    uint offsetsAndSizes[22];
    char stringdata0[9];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[4];
    char stringdata5[13];
    char stringdata6[17];
    char stringdata7[8];
    char stringdata8[13];
    char stringdata9[25];
    char stringdata10[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_VisorGUI_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_VisorGUI_t qt_meta_stringdata_VisorGUI = {
    {
        QT_MOC_LITERAL(0, 8),  // "VisorGUI"
        QT_MOC_LITERAL(9, 13),  // "updateAddress"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 12),  // "QHostAddress"
        QT_MOC_LITERAL(37, 3),  // "_ip"
        QT_MOC_LITERAL(41, 12),  // "resetAddress"
        QT_MOC_LITERAL(54, 16),  // "displayImageData"
        QT_MOC_LITERAL(71, 7),  // "cv::Mat"
        QT_MOC_LITERAL(79, 12),  // "switchLayout"
        QT_MOC_LITERAL(92, 24),  // "onNetworkListItemClicked"
        QT_MOC_LITERAL(117, 16)   // "QListWidgetItem*"
    },
    "VisorGUI",
    "updateAddress",
    "",
    "QHostAddress",
    "_ip",
    "resetAddress",
    "displayImageData",
    "cv::Mat",
    "switchLayout",
    "onNetworkListItemClicked",
    "QListWidgetItem*"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_VisorGUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    0,   47,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   48,    2, 0x08,    4 /* Private */,
       8,    0,   51,    2, 0x08,    6 /* Private */,
       9,    1,   52,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject VisorGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_VisorGUI.offsetsAndSizes,
    qt_meta_data_VisorGUI,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_VisorGUI_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VisorGUI, std::true_type>,
        // method 'updateAddress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QHostAddress, std::false_type>,
        // method 'resetAddress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayImageData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        // method 'switchLayout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNetworkListItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>
    >,
    nullptr
} };

void VisorGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VisorGUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateAddress((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1]))); break;
        case 1: _t->resetAddress(); break;
        case 2: _t->displayImageData((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 3: _t->switchLayout(); break;
        case 4: _t->onNetworkListItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VisorGUI::*)(QHostAddress );
            if (_t _q_method = &VisorGUI::updateAddress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VisorGUI::*)();
            if (_t _q_method = &VisorGUI::resetAddress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *VisorGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisorGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VisorGUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VisorGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void VisorGUI::updateAddress(QHostAddress _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VisorGUI::resetAddress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
