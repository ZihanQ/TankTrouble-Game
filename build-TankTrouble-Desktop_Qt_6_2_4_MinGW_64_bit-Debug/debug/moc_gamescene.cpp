/****************************************************************************
** Meta object code from reading C++ file 'gamescene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TankTrouble/gamescene.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gameScene_t {
    const uint offsetsAndSize[16];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_gameScene_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_gameScene_t qt_meta_stringdata_gameScene = {
    {
QT_MOC_LITERAL(0, 9), // "gameScene"
QT_MOC_LITERAL(10, 10), // "moveTank_1"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 10), // "moveTank_2"
QT_MOC_LITERAL(33, 10), // "moveBullet"
QT_MOC_LITERAL(44, 11), // "bulletItem*"
QT_MOC_LITERAL(56, 6), // "bullet"
QT_MOC_LITERAL(63, 7) // "radians"

    },
    "gameScene\0moveTank_1\0\0moveTank_2\0"
    "moveBullet\0bulletItem*\0bullet\0radians"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameScene[] = {

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
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    2,   34,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QReal,    6,    7,

       0        // eod
};

void gameScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<gameScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->moveTank_1(); break;
        case 1: _t->moveTank_2(); break;
        case 2: _t->moveBullet((*reinterpret_cast< std::add_pointer_t<bulletItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject gameScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_gameScene.offsetsAndSize,
    qt_meta_data_gameScene,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_gameScene_t
, QtPrivate::TypeAndForceComplete<gameScene, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bulletItem *, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>


>,
    nullptr
} };


const QMetaObject *gameScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int gameScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
