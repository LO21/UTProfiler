/****************************************************************************
** Meta object code from reading C++ file 'UTProfiler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UTProfiler/UTProfiler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UTProfiler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewUVWindow_t {
    QByteArrayData data[5];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewUVWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewUVWindow_t qt_meta_stringdata_NewUVWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 15),
QT_MOC_LITERAL(4, 45, 15)
    },
    "NewUVWindow\0pbvaliderEnable\0\0"
    "nouveau_annuler\0nouveau_valider\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewUVWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x0a,
       4,    0,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewUVWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewUVWindow *_t = static_cast<NewUVWindow *>(_o);
        switch (_id) {
        case 0: _t->pbvaliderEnable(); break;
        case 1: _t->nouveau_annuler(); break;
        case 2: _t->nouveau_valider(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NewUVWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewUVWindow.data,
      qt_meta_data_NewUVWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewUVWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewUVWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewUVWindow.stringdata))
        return static_cast<void*>(const_cast< NewUVWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int NewUVWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_UVWindow_t {
    QByteArrayData data[8];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UVWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UVWindow_t qt_meta_stringdata_UVWindow = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 6),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 7),
QT_MOC_LITERAL(4, 25, 9),
QT_MOC_LITERAL(5, 35, 14),
QT_MOC_LITERAL(6, 50, 10),
QT_MOC_LITERAL(7, 61, 7)
    },
    "UVWindow\0sauver\0\0annuler\0supprimer\0"
    "pbsauverEnable\0rechercher\0nouveau\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UVWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    0,   47,    2, 0x0a,
       6,    0,   48,    2, 0x0a,
       7,    0,   49,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UVWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UVWindow *_t = static_cast<UVWindow *>(_o);
        switch (_id) {
        case 0: _t->sauver(); break;
        case 1: _t->annuler(); break;
        case 2: _t->supprimer(); break;
        case 3: _t->pbsauverEnable(); break;
        case 4: _t->rechercher(); break;
        case 5: _t->nouveau(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UVWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UVWindow.data,
      qt_meta_data_UVWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *UVWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UVWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UVWindow.stringdata))
        return static_cast<void*>(const_cast< UVWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int UVWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_DossierWindow_t {
    QByteArrayData data[12];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DossierWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DossierWindow_t qt_meta_stringdata_DossierWindow = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 6),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 14),
QT_MOC_LITERAL(4, 37, 10),
QT_MOC_LITERAL(5, 48, 14),
QT_MOC_LITERAL(6, 63, 12),
QT_MOC_LITERAL(7, 76, 1),
QT_MOC_LITERAL(8, 78, 1),
QT_MOC_LITERAL(9, 80, 15),
QT_MOC_LITERAL(10, 96, 13),
QT_MOC_LITERAL(11, 110, 9)
    },
    "DossierWindow\0sauver\0\0pbsauverEnable\0"
    "rechercher\0ajouterFormExt\0supprFormExt\0"
    "r\0c\0ajouterSemestre\0supprSemestre\0"
    "supprimer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DossierWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a,
       3,    0,   55,    2, 0x0a,
       4,    0,   56,    2, 0x0a,
       5,    0,   57,    2, 0x0a,
       6,    2,   58,    2, 0x0a,
       9,    0,   63,    2, 0x0a,
      10,    2,   64,    2, 0x0a,
      11,    0,   69,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void DossierWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DossierWindow *_t = static_cast<DossierWindow *>(_o);
        switch (_id) {
        case 0: _t->sauver(); break;
        case 1: _t->pbsauverEnable(); break;
        case 2: _t->rechercher(); break;
        case 3: _t->ajouterFormExt(); break;
        case 4: _t->supprFormExt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->ajouterSemestre(); break;
        case 6: _t->supprSemestre((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->supprimer(); break;
        default: ;
        }
    }
}

const QMetaObject DossierWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DossierWindow.data,
      qt_meta_data_DossierWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *DossierWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DossierWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DossierWindow.stringdata))
        return static_cast<void*>(const_cast< DossierWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int DossierWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
struct qt_meta_stringdata_FormationExtWindow_t {
    QByteArrayData data[3];
    char stringdata[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FormationExtWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FormationExtWindow_t qt_meta_stringdata_FormationExtWindow = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 7),
QT_MOC_LITERAL(2, 27, 0)
    },
    "FormationExtWindow\0ajouter\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormationExtWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FormationExtWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormationExtWindow *_t = static_cast<FormationExtWindow *>(_o);
        switch (_id) {
        case 0: _t->ajouter(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FormationExtWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormationExtWindow.data,
      qt_meta_data_FormationExtWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *FormationExtWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormationExtWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormationExtWindow.stringdata))
        return static_cast<void*>(const_cast< FormationExtWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormationExtWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SemestreWindow_t {
    QByteArrayData data[3];
    char stringdata[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SemestreWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SemestreWindow_t qt_meta_stringdata_SemestreWindow = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 7),
QT_MOC_LITERAL(2, 23, 0)
    },
    "SemestreWindow\0ajouter\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SemestreWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SemestreWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SemestreWindow *_t = static_cast<SemestreWindow *>(_o);
        switch (_id) {
        case 0: _t->ajouter(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SemestreWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SemestreWindow.data,
      qt_meta_data_SemestreWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *SemestreWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SemestreWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SemestreWindow.stringdata))
        return static_cast<void*>(const_cast< SemestreWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SemestreWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_NewFormationWindow_t {
    QByteArrayData data[5];
    char stringdata[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewFormationWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewFormationWindow_t qt_meta_stringdata_NewFormationWindow = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 10),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 7),
QT_MOC_LITERAL(4, 39, 7)
    },
    "NewFormationWindow\0setenabled\0\0ajouter\0"
    "annuler\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewFormationWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x0a,
       4,    0,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewFormationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewFormationWindow *_t = static_cast<NewFormationWindow *>(_o);
        switch (_id) {
        case 0: _t->setenabled(); break;
        case 1: _t->ajouter(); break;
        case 2: _t->annuler(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NewFormationWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewFormationWindow.data,
      qt_meta_data_NewFormationWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewFormationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewFormationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewFormationWindow.stringdata))
        return static_cast<void*>(const_cast< NewFormationWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int NewFormationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_FormationWindow_t {
    QByteArrayData data[13];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FormationWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FormationWindow_t qt_meta_stringdata_FormationWindow = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 10),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 10),
QT_MOC_LITERAL(4, 39, 7),
QT_MOC_LITERAL(5, 47, 9),
QT_MOC_LITERAL(6, 57, 6),
QT_MOC_LITERAL(7, 64, 8),
QT_MOC_LITERAL(8, 73, 1),
QT_MOC_LITERAL(9, 75, 1),
QT_MOC_LITERAL(10, 77, 9),
QT_MOC_LITERAL(11, 87, 9),
QT_MOC_LITERAL(12, 97, 10)
    },
    "FormationWindow\0setenabled\0\0rechercher\0"
    "nouveau\0supprimer\0sauver\0sauveruv\0r\0"
    "c\0ajouteruv\0sauverfil\0ajouterfil\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormationWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a,
       3,    0,   60,    2, 0x0a,
       4,    0,   61,    2, 0x0a,
       5,    0,   62,    2, 0x0a,
       6,    0,   63,    2, 0x0a,
       7,    2,   64,    2, 0x0a,
      10,    0,   69,    2, 0x0a,
      11,    2,   70,    2, 0x0a,
      12,    0,   75,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void FormationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormationWindow *_t = static_cast<FormationWindow *>(_o);
        switch (_id) {
        case 0: _t->setenabled(); break;
        case 1: _t->rechercher(); break;
        case 2: _t->nouveau(); break;
        case 3: _t->supprimer(); break;
        case 4: _t->sauver(); break;
        case 5: _t->sauveruv((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->ajouteruv(); break;
        case 7: _t->sauverfil((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->ajouterfil(); break;
        default: ;
        }
    }
}

const QMetaObject FormationWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormationWindow.data,
      qt_meta_data_FormationWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *FormationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FormationWindow.stringdata))
        return static_cast<void*>(const_cast< FormationWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int FormationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
struct qt_meta_stringdata_SearchDossierWindow_t {
    QByteArrayData data[5];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SearchDossierWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SearchDossierWindow_t qt_meta_stringdata_SearchDossierWindow = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 10),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 9),
QT_MOC_LITERAL(4, 42, 7)
    },
    "SearchDossierWindow\0rechercher\0\0"
    "retrouver\0annuler\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchDossierWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x0a,
       4,    0,   31,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchDossierWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchDossierWindow *_t = static_cast<SearchDossierWindow *>(_o);
        switch (_id) {
        case 0: _t->rechercher(); break;
        case 1: _t->retrouver(); break;
        case 2: _t->annuler(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SearchDossierWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SearchDossierWindow.data,
      qt_meta_data_SearchDossierWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchDossierWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchDossierWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchDossierWindow.stringdata))
        return static_cast<void*>(const_cast< SearchDossierWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SearchDossierWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_RetrouverCompletionWindow_t {
    QByteArrayData data[4];
    char stringdata[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RetrouverCompletionWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RetrouverCompletionWindow_t qt_meta_stringdata_RetrouverCompletionWindow = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 9),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 7)
    },
    "RetrouverCompletionWindow\0precedent\0"
    "\0suivant\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RetrouverCompletionWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a,
       3,    0,   25,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RetrouverCompletionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RetrouverCompletionWindow *_t = static_cast<RetrouverCompletionWindow *>(_o);
        switch (_id) {
        case 0: _t->precedent(); break;
        case 1: _t->suivant(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RetrouverCompletionWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RetrouverCompletionWindow.data,
      qt_meta_data_RetrouverCompletionWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *RetrouverCompletionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RetrouverCompletionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RetrouverCompletionWindow.stringdata))
        return static_cast<void*>(const_cast< RetrouverCompletionWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int RetrouverCompletionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_CompletionProfilWindow_t {
    QByteArrayData data[16];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CompletionProfilWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CompletionProfilWindow_t qt_meta_stringdata_CompletionProfilWindow = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 10),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 11),
QT_MOC_LITERAL(4, 47, 10),
QT_MOC_LITERAL(5, 58, 10),
QT_MOC_LITERAL(6, 69, 10),
QT_MOC_LITERAL(7, 80, 10),
QT_MOC_LITERAL(8, 91, 10),
QT_MOC_LITERAL(9, 102, 10),
QT_MOC_LITERAL(10, 113, 8),
QT_MOC_LITERAL(11, 122, 8),
QT_MOC_LITERAL(12, 131, 8),
QT_MOC_LITERAL(13, 140, 8),
QT_MOC_LITERAL(14, 149, 8),
QT_MOC_LITERAL(15, 158, 8)
    },
    "CompletionProfilWindow\0rechercher\0\0"
    "enregistrer\0confirmer1\0confirmer2\0"
    "confirmer3\0confirmer4\0confirmer5\0"
    "confirmer6\0refuser1\0refuser2\0refuser3\0"
    "refuser4\0refuser5\0refuser6\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompletionProfilWindow[] = {

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
       1,    0,   84,    2, 0x0a,
       3,    0,   85,    2, 0x0a,
       4,    0,   86,    2, 0x0a,
       5,    0,   87,    2, 0x0a,
       6,    0,   88,    2, 0x0a,
       7,    0,   89,    2, 0x0a,
       8,    0,   90,    2, 0x0a,
       9,    0,   91,    2, 0x0a,
      10,    0,   92,    2, 0x0a,
      11,    0,   93,    2, 0x0a,
      12,    0,   94,    2, 0x0a,
      13,    0,   95,    2, 0x0a,
      14,    0,   96,    2, 0x0a,
      15,    0,   97,    2, 0x0a,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CompletionProfilWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CompletionProfilWindow *_t = static_cast<CompletionProfilWindow *>(_o);
        switch (_id) {
        case 0: _t->rechercher(); break;
        case 1: _t->enregistrer(); break;
        case 2: _t->confirmer1(); break;
        case 3: _t->confirmer2(); break;
        case 4: _t->confirmer3(); break;
        case 5: _t->confirmer4(); break;
        case 6: _t->confirmer5(); break;
        case 7: _t->confirmer6(); break;
        case 8: _t->refuser1(); break;
        case 9: _t->refuser2(); break;
        case 10: _t->refuser3(); break;
        case 11: _t->refuser4(); break;
        case 12: _t->refuser5(); break;
        case 13: _t->refuser6(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CompletionProfilWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CompletionProfilWindow.data,
      qt_meta_data_CompletionProfilWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *CompletionProfilWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompletionProfilWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CompletionProfilWindow.stringdata))
        return static_cast<void*>(const_cast< CompletionProfilWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int CompletionProfilWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_HomeWindow_t {
    QByteArrayData data[1];
    char stringdata[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_HomeWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_HomeWindow_t qt_meta_stringdata_HomeWindow = {
    {
QT_MOC_LITERAL(0, 0, 10)
    },
    "HomeWindow\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void HomeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject HomeWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomeWindow.data,
      qt_meta_data_HomeWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *HomeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomeWindow.stringdata))
        return static_cast<void*>(const_cast< HomeWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int HomeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AssocierUVWindow_t {
    QByteArrayData data[3];
    char stringdata[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AssocierUVWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AssocierUVWindow_t qt_meta_stringdata_AssocierUVWindow = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 7),
QT_MOC_LITERAL(2, 25, 0)
    },
    "AssocierUVWindow\0ajouter\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AssocierUVWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AssocierUVWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AssocierUVWindow *_t = static_cast<AssocierUVWindow *>(_o);
        switch (_id) {
        case 0: _t->ajouter(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AssocierUVWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AssocierUVWindow.data,
      qt_meta_data_AssocierUVWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *AssocierUVWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AssocierUVWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AssocierUVWindow.stringdata))
        return static_cast<void*>(const_cast< AssocierUVWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AssocierUVWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_AssocierFiliereWindow_t {
    QByteArrayData data[3];
    char stringdata[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AssocierFiliereWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AssocierFiliereWindow_t qt_meta_stringdata_AssocierFiliereWindow = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 7),
QT_MOC_LITERAL(2, 30, 0)
    },
    "AssocierFiliereWindow\0ajouter\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AssocierFiliereWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AssocierFiliereWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AssocierFiliereWindow *_t = static_cast<AssocierFiliereWindow *>(_o);
        switch (_id) {
        case 0: _t->ajouter(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AssocierFiliereWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AssocierFiliereWindow.data,
      qt_meta_data_AssocierFiliereWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *AssocierFiliereWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AssocierFiliereWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AssocierFiliereWindow.stringdata))
        return static_cast<void*>(const_cast< AssocierFiliereWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AssocierFiliereWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
