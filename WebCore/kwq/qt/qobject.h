/*
 * Copyright (C) 2001, 2002 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef QOBJECT_H_
#define QOBJECT_H_

#include <KWQDef.h>

#include "qnamespace.h"
#include "qstring.h"
#include "qevent.h"
#include "qstringlist.h"
#include "qptrlist.h"

#define slots : public
#define SLOT(x) "SLOT:" #x
#define signals protected
#define SIGNAL(x) "SIGNAL:" #x
#define emit
#define Q_OBJECT
#define Q_PROPERTY(text)

class QEvent;
class QPaintDevice;
class QPaintDeviceMetrics;
class QWidget;
class QColor;
class QColorGroup;
class QPalette;
class QPainter;
class QRegion;
class QSize;
class QSizePolicy;
class QRect;
class QFont;
class QFontMetrics;
class QBrush;
class QBitmap;
class QMovie;
class QTimer;
class QImage;
class QVariant;

class KWQGuardedPtrBase;
class KWQSignal;

class QObject : public Qt {
public:

    enum Actions {
        ACTION_TEXT_AREA_END_EDITING = 5,        
        ACTION_LISTBOX_CLICKED = 6,
        ACTION_COMBOBOX_CLICKED = 7
    };

    QObject(QObject *parent = 0, const char *name = 0);
    virtual ~QObject();

    static void connect(const QObject *sender, const char *signal, const QObject *receiver, const char *member);
    static void disconnect(const QObject *sender, const char *signal, const QObject *receiver, const char *member);
    void connect(const QObject *sender, const char *signal, const char *member) const
        { connect(sender, signal, this, member); }

    bool inherits(const char *className) const;

    int startTimer(int);
    void killTimer(int);
    void killTimers();
    virtual void timerEvent(QTimerEvent *);

    void installEventFilter(const QObject *);
    void removeEventFilter(const QObject *);
    bool eventFilter(QObject *o, QEvent *e);

    void blockSignals(bool b) { m_signalsBlocked = b; }

    virtual bool event(QEvent *);

    void emitAction(Actions action);
    virtual void performAction(Actions action);
    
    static const QObject *sender() { return m_sender; }

private:
    // no copying or assignment
    QObject(const QObject &);
    QObject &operator=(const QObject &);
    
    KWQSignal *findSignal(const char *signalName) const;
    
    mutable QObject *target;
    QPtrList<QObject> guardedPtrDummyList;
    mutable KWQSignal *m_signalListHead;
    bool m_signalsBlocked;
    
    static const QObject *m_sender;

    friend class KWQGuardedPtrBase;
    friend class KWQSignal;
    friend class KWQObjectSenderScope;
};

class KWQObjectSenderScope
{
public:
    KWQObjectSenderScope(const QObject *);
    ~KWQObjectSenderScope();

private:
    const QObject *m_savedSender;
};

#endif
