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

#include "QvkAnimateControl.h"

#include <QTest>
#include <QTimer>
#include <QDebug>

QvkAnimateControl::QvkAnimateControl( double time, int diameter,  double opacity, QColor color )
{
    showTime = time * 1000;

    globalMouse = new QvkGlobalMouse();
    connect( globalMouse, SIGNAL( mousePressed( int, int ) ), this, SLOT( mousePressed( int, int ) ) );

    animateWindow = new QvkAnimateWindow();
    setDiameterColor( diameter, color );
    setOpacity( opacity );
}

QvkAnimateControl::~QvkAnimateControl()
{
}

void QvkAnimateControl::pointerOnOff( bool value )
{
    if ( value == true )
    {
        animateWindowOn();
    }

    if ( value == false )
    {
        animateWindowOff();
    }
}

void QvkAnimateControl::animateWindowOn()
{
    globalMouse->setCursorOn();
    globalMouse->mousePressed();
}

void QvkAnimateControl::animateWindowOff()
{
    globalMouse->setCursorOff();
}

void QvkAnimateControl::mousePressed( int x, int y )
{
    animateWindow->setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::ToolTip );
    animateWindow->move( x - animateWindow->width() / 2, y - animateWindow->height() / 2 );
    animateWindow->show();
    QTimer::singleShot( showTime, this, SLOT( closeWindow() ) );
}

void QvkAnimateControl::closeWindow()
{
    animateWindow->close();
}

void QvkAnimateControl::setDiameterColor( int diameter, QColor color)
{
    animateWindow->setRadiusColor( diameter, color );
}

void QvkAnimateControl::setShowTime( double value )
{
    showTime = value * 1000;
}

void QvkAnimateControl::setOpacity( double value )
{
    animateWindow->setOpacity( value );
}
