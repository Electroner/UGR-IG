HEADERS += \
  colors.h \
  basic_object3d.h \
  cube.h \
  object3d.h \
  axis.h \
  plyobj.h \
  revobj.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h \
  rueda.h \
  cilindro.h \
  eje.h \
  rueda_eje.h \
  materials.h 

SOURCES += \
  basic_object3d.cc \
  cube.cpp \
  object3d.cc \
  axis.cc \
  plyobj.cpp \
  revobj.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc \
  rueda.cc \
  cilindro.cc \
  eje.cc \
  rueda_eje.cc

LIBS += -L/usr/X11R6/lib64 -lGL

CONFIG += c++11
QT += widgets
