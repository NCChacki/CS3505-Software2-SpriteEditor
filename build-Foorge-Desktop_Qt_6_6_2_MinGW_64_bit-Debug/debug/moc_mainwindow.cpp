/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Foorge/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
<<<<<<< HEAD
    "fileLoadedSignal",
    "",
    "image",
    "pixelChanged",
    "point",
    "onSaveClicked",
    "onLoadClicked",
    "updateLabelImage",
    "updatePreviewImage",
    "updateFramePreview",
    "std::vector<QImage>",
    "previewImages"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[13];
    char stringdata5[6];
    char stringdata6[14];
    char stringdata7[14];
    char stringdata8[17];
    char stringdata9[19];
    char stringdata10[19];
    char stringdata11[20];
    char stringdata12[14];
=======
    "pixelChanged",
    "",
    "point",
    "onSaveClicked",
    "receiveOnionFrame",
    "onionImage",
    "disableOnionFrame",
    "updateLabelImage",
    "image",
    "onLoadClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[18];
    char stringdata6[11];
    char stringdata7[18];
    char stringdata8[17];
    char stringdata9[6];
    char stringdata10[14];
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
<<<<<<< HEAD
        QT_MOC_LITERAL(11, 16),  // "fileLoadedSignal"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "image"
        QT_MOC_LITERAL(35, 12),  // "pixelChanged"
        QT_MOC_LITERAL(48, 5),  // "point"
        QT_MOC_LITERAL(54, 13),  // "onSaveClicked"
        QT_MOC_LITERAL(68, 13),  // "onLoadClicked"
        QT_MOC_LITERAL(82, 16),  // "updateLabelImage"
        QT_MOC_LITERAL(99, 18),  // "updatePreviewImage"
        QT_MOC_LITERAL(118, 18),  // "updateFramePreview"
        QT_MOC_LITERAL(137, 19),  // "std::vector<QImage>"
        QT_MOC_LITERAL(157, 13)   // "previewImages"
    },
    "MainWindow",
    "fileLoadedSignal",
    "",
    "image",
    "pixelChanged",
    "point",
    "onSaveClicked",
    "onLoadClicked",
    "updateLabelImage",
    "updatePreviewImage",
    "updateFramePreview",
    "std::vector<QImage>",
    "previewImages"
=======
        QT_MOC_LITERAL(11, 12),  // "pixelChanged"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 5),  // "point"
        QT_MOC_LITERAL(31, 13),  // "onSaveClicked"
        QT_MOC_LITERAL(45, 17),  // "receiveOnionFrame"
        QT_MOC_LITERAL(63, 10),  // "onionImage"
        QT_MOC_LITERAL(74, 17),  // "disableOnionFrame"
        QT_MOC_LITERAL(92, 16),  // "updateLabelImage"
        QT_MOC_LITERAL(109, 5),  // "image"
        QT_MOC_LITERAL(115, 13)   // "onLoadClicked"
    },
    "MainWindow",
    "pixelChanged",
    "",
    "point",
    "onSaveClicked",
    "receiveOnionFrame",
    "onionImage",
    "disableOnionFrame",
    "updateLabelImage",
    "image",
    "onLoadClicked"
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       7,   14, // methods
=======
       6,   14, // methods
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
<<<<<<< HEAD
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   59,    2, 0x0a,    3 /* Public */,
       6,    0,   62,    2, 0x0a,    5 /* Public */,
       7,    0,   63,    2, 0x0a,    6 /* Public */,
       8,    1,   64,    2, 0x0a,    7 /* Public */,
       9,    1,   67,    2, 0x0a,    9 /* Public */,
      10,    1,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 11,   12,
=======
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    0,   53,    2, 0x0a,    3 /* Public */,
       5,    1,   54,    2, 0x0a,    4 /* Public */,
       7,    1,   57,    2, 0x0a,    6 /* Public */,
       8,    1,   60,    2, 0x0a,    8 /* Public */,
      10,    0,   63,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::QImage,    9,
    QMetaType::Void,
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
<<<<<<< HEAD
        // method 'fileLoadedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
=======
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
        // method 'pixelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPointF, std::false_type>,
        // method 'onSaveClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
<<<<<<< HEAD
        // method 'onLoadClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLabelImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'updatePreviewImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'updateFramePreview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<QImage>, std::false_type>
=======
        // method 'receiveOnionFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'disableOnionFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'updateLabelImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'onLoadClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
<<<<<<< HEAD
        case 0: _t->fileLoadedSignal((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->pixelChanged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 2: _t->onSaveClicked(); break;
        case 3: _t->onLoadClicked(); break;
        case 4: _t->updateLabelImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 5: _t->updatePreviewImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 6: _t->updateFramePreview((*reinterpret_cast< std::add_pointer_t<std::vector<QImage>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QImage );
            if (_t _q_method = &MainWindow::fileLoadedSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
=======
        case 0: _t->pixelChanged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 1: _t->onSaveClicked(); break;
        case 2: _t->receiveOnionFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 3: _t->disableOnionFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 4: _t->updateLabelImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 5: _t->onLoadClicked(); break;
        default: ;
        }
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::fileLoadedSignal(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
=======
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
>>>>>>> 4db0a34eff9898ab77d0ddd7188137ddd4b9b36d
QT_WARNING_POP
