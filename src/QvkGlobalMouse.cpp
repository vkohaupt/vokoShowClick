/* vokoShowClick
 * Copyright (C) 2017-2021 Volker Kohaupt
 *
 * Author:
 *      Volker Kohaupt <vkohaupt@freenet.de>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * --End_License--
 */

#include "QvkGlobalMouse.h"

#include <QCoreApplication>
#include <QThread>
#include <QDebug>

#ifdef Q_OS_WIN
#include <QCursor>
#endif

#ifdef Q_OS_LINUX
#include<X11/Xlib.h>
#include<stdio.h>
#endif

QvkGlobalMouse::QvkGlobalMouse()
{
    onOff = false;
}


QvkGlobalMouse::~QvkGlobalMouse()
{
}


void QvkGlobalMouse::setCursorOn()
{
    onOff = true;
}


void QvkGlobalMouse::setCursorOff()
{
    onOff = false;
}


#ifdef Q_OS_LINUX
void QvkGlobalMouse::mousePressed()
{
    Display* display;
    Window root;
    display = XOpenDisplay( NULL );
    root = DefaultRootWindow( display);
    Window root_return, child_return;
    int x, y;
    int win_x, win_y;
    unsigned int mask;
    int pressed = 0;

    while( onOff )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents );
        XQueryPointer( display, root, &root_return, &child_return, &x, &y, &win_x, &win_y, &mask );
        QThread::msleep( 10 );

        if ( ( mask & Button1Mask) | ( mask & Button2Mask ) | ( mask & Button3Mask ) )
        {
            if ( pressed == 0 )
            {
                QString mouseButton;
                if (  mask & Button1Mask  )
                {
                    mouseButton = "LeftButton";
                }

                if (  mask & Button2Mask  )
                {
                    mouseButton = "MiddleButton";
                }

                if ( mask & Button3Mask )
                {
                    mouseButton = "RightButton";
                }

                pressed = 1;
                emit signal_mousePressed( win_x, win_y, mouseButton );
            }
        }
        else
        {
            pressed = 0;
        }

        fflush(stdout);
    }
    XCloseDisplay( display );
}
#endif


#ifdef Q_OS_WIN
void QvkGlobalMouse::mousePressed()
{
    while( onOff )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents );
        QPoint point = QCursor::pos();
        qDebug() << point;
    }
}
#endif

