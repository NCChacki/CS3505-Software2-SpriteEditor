/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Foorge/model.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSModelENDCLASS = QtMocHelpers::stringData(
    "Model",
    "imageUpdated",
    "",
    "image",
<<<<<<< HEAD
    "previewUpdated",
    "sendPreviewFrames",
    "std::vector<QImage>",
    "imageVector",
    "imageChanged",
    "point",
    "timeToUpdatePreview",
    "addNewFrame",
    "nextFrame",
    "previousFrame",
    "colorChanged",
    "newColor",
    "eraseClicked",
    "eraseScreen"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSModelENDCLASS_t {
    uint offsetsAndSizes[36];
=======
    "enableOnion",
    "disableOnion",
    "imageChanged",
    "point",
    "toggleOnion"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSModelENDCLASS_t {
    uint offsetsAndSizes[18];
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    char stringdata0[6];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
<<<<<<< HEAD
    char stringdata4[15];
    char stringdata5[18];
    char stringdata6[20];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[6];
    char stringdata10[20];
    char stringdata11[12];
    char stringdata12[10];
    char stringdata13[14];
    char stringdata14[13];
    char stringdata15[9];
    char stringdata16[13];
    char stringdata17[12];
=======
    char stringdata4[12];
    char stringdata5[13];
    char stringdata6[13];
    char stringdata7[6];
    char stringdata8[12];
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSModelENDCLASS_t qt_meta_stringdata_CLASSModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 12),  // "imageUpdated"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 5),  // "image"
<<<<<<< HEAD
        QT_MOC_LITERAL(26, 14),  // "previewUpdated"
        QT_MOC_LITERAL(41, 17),  // "sendPreviewFrames"
        QT_MOC_LITERAL(59, 19),  // "std::vector<QImage>"
        QT_MOC_LITERAL(79, 11),  // "imageVector"
        QT_MOC_LITERAL(91, 12),  // "imageChanged"
        QT_MOC_LITERAL(104, 5),  // "point"
        QT_MOC_LITERAL(110, 19),  // "timeToUpdatePreview"
        QT_MOC_LITERAL(130, 11),  // "addNewFrame"
        QT_MOC_LITERAL(142, 9),  // "nextFrame"
        QT_MOC_LITERAL(152, 13),  // "previousFrame"
        QT_MOC_LITERAL(166, 12),  // "colorChanged"
        QT_MOC_LITERAL(179, 8),  // "newColor"
        QT_MOC_LITERAL(188, 12),  // "eraseClicked"
        QT_MOC_LITERAL(201, 11)   // "eraseScreen"
=======
        QT_MOC_LITERAL(26, 11),  // "enableOnion"
        QT_MOC_LITERAL(38, 12),  // "disableOnion"
        QT_MOC_LITERAL(51, 12),  // "imageChanged"
        QT_MOC_LITERAL(64, 5),  // "point"
        QT_MOC_LITERAL(70, 11)   // "toggleOnion"
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    },
    "Model",
    "imageUpdated",
    "",
    "image",
<<<<<<< HEAD
    "previewUpdated",
    "sendPreviewFrames",
    "std::vector<QImage>",
    "imageVector",
    "imageChanged",
    "point",
    "timeToUpdatePreview",
    "addNewFrame",
    "nextFrame",
    "previousFrame",
    "colorChanged",
    "newColor",
    "eraseClicked",
    "eraseScreen"
=======
    "enableOnion",
    "disableOnion",
    "imageChanged",
    "point",
    "toggleOnion"
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
      11,   14, // methods
=======
       5,   14, // methods
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
<<<<<<< HEAD
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,
       5,    1,   86,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   89,    2, 0x0a,    7 /* Public */,
      10,    0,   92,    2, 0x0a,    9 /* Public */,
      11,    0,   93,    2, 0x0a,   10 /* Public */,
      12,    0,   94,    2, 0x0a,   11 /* Public */,
      13,    0,   95,    2, 0x0a,   12 /* Public */,
      14,    1,   96,    2, 0x0a,   13 /* Public */,
      16,    0,   99,    2, 0x0a,   15 /* Public */,
      17,    0,  100,    2, 0x0a,   16 /* Public */,
=======
       1,    1,   44,    2, 0x06,    1 /* Public */,
       4,    1,   47,    2, 0x06,    3 /* Public */,
       5,    1,   50,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   53,    2, 0x0a,    7 /* Public */,
       8,    0,   56,    2, 0x0a,    9 /* Public */,
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
<<<<<<< HEAD
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   15,
    QMetaType::Void,
=======
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    7,
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Model, std::true_type>,
        // method 'imageUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
<<<<<<< HEAD
        // method 'previewUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'sendPreviewFrames'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<QImage>, std::false_type>,
        // method 'imageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPointF, std::false_type>,
        // method 'timeToUpdatePreview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNewFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previousFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'eraseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eraseScreen'
=======
        // method 'enableOnion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'disableOnion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'imageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPointF, std::false_type>,
        // method 'toggleOnion'
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->imageUpdated((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
<<<<<<< HEAD
        case 1: _t->previewUpdated((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->sendPreviewFrames((*reinterpret_cast< std::add_pointer_t<std::vector<QImage>>>(_a[1]))); break;
        case 3: _t->imageChanged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 4: _t->timeToUpdatePreview(); break;
        case 5: _t->addNewFrame(); break;
        case 6: _t->nextFrame(); break;
        case 7: _t->previousFrame(); break;
        case 8: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 9: _t->eraseClicked(); break;
        case 10: _t->eraseScreen(); break;
=======
        case 1: _t->enableOnion((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->disableOnion((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 3: _t->imageChanged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 4: _t->toggleOnion(); break;
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(QImage );
            if (_t _q_method = &Model::imageUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(QImage );
<<<<<<< HEAD
            if (_t _q_method = &Model::previewUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
=======
            if (_t _q_method = &Model::enableOnion; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
                *result = 1;
                return;
            }
        }
        {
<<<<<<< HEAD
            using _t = void (Model::*)(std::vector<QImage> );
            if (_t _q_method = &Model::sendPreviewFrames; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
=======
            using _t = void (Model::*)(QImage );
            if (_t _q_method = &Model::disableOnion; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
=======
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    }
    return _id;
}

// SIGNAL 0
void Model::imageUpdated(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
<<<<<<< HEAD
void Model::previewUpdated(QImage _t1)
=======
void Model::enableOnion(QImage _t1)
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
<<<<<<< HEAD
void Model::sendPreviewFrames(std::vector<QImage> _t1)
=======
void Model::disableOnion(QImage _t1)
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
