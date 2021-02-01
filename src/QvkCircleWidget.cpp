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

#include "QvkCircleWidget.h"

QvkCircleWidget::QvkCircleWidget( QWidget *parent ) : QWidget( parent )
{
    parentWidget = parent;

    pointerColor = Qt::red;
    diameter = 50;
    pointerOpacity = 0.5;
}


QvkCircleWidget::~QvkCircleWidget()
{
}


void QvkCircleWidget::paintEvent( QPaintEvent *event )
{
    Q_UNUSED(event);

    QPainter painter;
    painter.begin( this );
    painter.setRenderHints( QPainter::Antialiasing, true );

    qreal penWith = 6;
    QPen pen;
    pen.setWidthF( penWith );
    pen.setColor( pointerColor );
    pen.setStyle( Qt::SolidLine );
    painter.setPen( pen );
    painter.setBrush( Qt::NoBrush );
    painter.setOpacity( pointerOpacity );
    resize( parentWidget->width(), parentWidget->height());
    painter.drawEllipse( parentWidget->width()/2-diameter/2, parentWidget->height()/2-diameter/2, diameter, diameter );

    painter.end();
}


void QvkCircleWidget::setColor( QColor value )
{
    pointerColor = value;
    repaint();
}


QColor QvkCircleWidget::getColor()
{
    return pointerColor;
}


void QvkCircleWidget::setDiameter( int value )
{
    diameter = value;
    repaint();
}


int QvkCircleWidget::getDiameter()
{
    return diameter;
}


void QvkCircleWidget::setOpacity( double value )
{
    pointerOpacity = value;;
    repaint();
}


double QvkCircleWidget::getOpacity()
{
    return pointerOpacity;
}
