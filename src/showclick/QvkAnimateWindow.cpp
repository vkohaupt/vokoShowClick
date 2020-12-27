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

#include "QvkAnimateWindow.h"
#include <QPainter>
#include <QTest>
#include <QDebug>

QvkAnimateWindow::QvkAnimateWindow()
{
    setAttribute( Qt::WA_TranslucentBackground, true );

    resize( 110, 110 );

    QRegion window( 0,
                    0,
                    width(),
                    height(),
                    QRegion::Rectangle );

    QRegion mouseHole( width() / 2 - 1,
                       height() / 2 - 1,
                       2,
                       2,
                       QRegion::Rectangle );

    QRegion r1 = window.QRegion::subtracted( mouseHole );

    this->setMask( r1 );
}

QvkAnimateWindow::~QvkAnimateWindow()
{
}

void QvkAnimateWindow::paintEvent( QPaintEvent *event ) 
{
    Q_UNUSED(event);

    QPainter painter( this );
    painter.setRenderHints( QPainter::Antialiasing, true );

    qreal penWith = 8.0;
    QPen pen;
    pen.setWidthF( penWith );
    pen.setColor( color );
    pen.setStyle( Qt::SolidLine );
    painter.setPen( pen );
    painter.setBrush( Qt::NoBrush );
    painter.setOpacity( opacity );
    painter.drawEllipse( width()/2-diameter/2, height()/2-diameter/2, diameter, diameter );

    // Paint Button
    pen.setStyle( Qt::SolidLine );
    pen.setWidthF( 3.0 );
    painter.setPen( pen );
    painter.setOpacity( opacity );
    if ( getMouseButton() == "LeftButton" )
    {
        QRectF rectF( width()/2 - diameter/2 + penWith, height()/2 - diameter/2 + penWith, diameter-2*penWith, diameter-2*penWith );
        int startAngle = 90 * 16;
        int spanAngle = 180 * 16;
        painter.drawArc( rectF, startAngle, spanAngle );
    }

    if ( getMouseButton() == "RightButton" )
    {
        QRectF rectF( width()/2 - diameter/2 + penWith, height()/2 - diameter/2 + penWith, diameter-2*penWith, diameter-2*penWith );
        int startAngle = -90 * 16;
        int spanAngle = 180 * 16;
        painter.drawArc( rectF, startAngle, spanAngle );
    }

    if ( getMouseButton() == "MiddleButton" )
    {
        QLineF line( width()/2, height()/2 - diameter/2 + penWith , width()/2, height()/2 + diameter/2 - penWith );
        painter.drawLine( line );
    }

}

void QvkAnimateWindow::setRadiusColor( int valueDiameter, QColor valueColor )
{
    diameter = valueDiameter;
    color = valueColor;
    repaint();
}

void QvkAnimateWindow::setOpacity( double value )
{
    opacity = value;
}

void QvkAnimateWindow::setMouseButton( QString mouseButton )
{
    this->mouseButton = mouseButton;
}

QString QvkAnimateWindow::getMouseButton()
{
    return mouseButton;
}
