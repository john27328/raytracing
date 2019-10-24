QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++14
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS += -fopenmp

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    distribution.cpp \
    drawoptics.cpp \
    main.cpp \
    new_ray.cpp \
    normal_distribution.cpp \
    normal_spectrum.cpp \
    old_angle.cpp \
    old_arc.cpp \
    old_array_src.cpp \
    old_circle.cpp \
    old_circle_array.cpp \
    old_circle_array_src.cpp \
    old_diod.cpp \
    old_edge.cpp \
    old_line_sector.cpp \
    old_point.cpp \
    old_ray.cpp \
    old_raytracing.cpp \
    old_shader.cpp \
    old_shader_mirror.cpp \
    old_shader_transparent.cpp \
    old_vcsel_source.cpp \
    qcustomplot.cpp \
    screen.cpp \
    source.cpp \
    uniform_int_distribution.cpp \
    uniform_real_distribution.cpp \
    vector.cpp

HEADERS += \
    const.h \
    distribution.h \
    drawoptics.h \
    normal_distribution.h \
    normal_spectrum.h \
    old_angle.h \
    old_arc.h \
    old_array_src.h \
    old_circle.h \
    old_circle_array.h \
    old_circle_array_src.h \
    old_diod.h \
    old_edge.h \
    old_line_sector.h \
    old_point.h \
    old_ray.h \
    old_raytracing.h \
    old_shader.h \
    old_shader_mirror.h \
    old_shader_transparent.h \
    old_source.h \
    old_vcsel_source.h \
    qcustomplot.h \
    ray.h \
    screen.h \
    uniform_int_distribution.h \
    uniform_real_distribution.h \
    vector.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
