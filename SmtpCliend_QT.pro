QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/Smpt/emailaddress.cpp \
    lib/Smpt/mimeattachment.cpp \
    lib/Smpt/mimecontentformatter.cpp \
    lib/Smpt/mimefile.cpp \
    lib/Smpt/mimehtml.cpp \
    lib/Smpt/mimeinlinefile.cpp \
    lib/Smpt/mimemessage.cpp \
    lib/Smpt/mimemultipart.cpp \
    lib/Smpt/mimepart.cpp \
    lib/Smpt/mimetext.cpp \
    lib/Smpt/quotedprintable.cpp \
    lib/Smpt/smtpclient.cpp \
    main.cpp \
    application.cpp

HEADERS += \
    application.h \
    lib/Smpt/SmtpMime \
    lib/Smpt/emailaddress.h \
    lib/Smpt/mimeattachment.h \
    lib/Smpt/mimecontentformatter.h \
    lib/Smpt/mimefile.h \
    lib/Smpt/mimehtml.h \
    lib/Smpt/mimeinlinefile.h \
    lib/Smpt/mimemessage.h \
    lib/Smpt/mimemultipart.h \
    lib/Smpt/mimepart.h \
    lib/Smpt/mimetext.h \
    lib/Smpt/quotedprintable.h \
    lib/Smpt/smtpclient.h \
    lib/Smpt/smtpexports.h

FORMS += \
    application.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
