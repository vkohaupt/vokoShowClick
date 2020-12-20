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

#ifndef QvkAnimateControl_H
#define QvkAnimateControl_H

#include "QvkGlobalMouse.h"
#include "QvkAnimateWindow.h"

#include <QObject>

class QvkAnimateControl: public QObject
{
    Q_OBJECT
public:    
    QvkAnimateControl( double time, int diameter, Qt::CheckState radiant, double opacity, QColor color );
    virtual ~QvkAnimateControl();
    

public slots:
    void animateWindowOn();
    void animateWindowOff();
    void setDiameterColor( int diameter, QColor color );
    void setShowTime( double value );
    void setOpacity( double value );
    void setRadiant( bool value );
    void pointerOnOff( bool value );


private:
    QvkGlobalMouse *globalMouse;
    QvkAnimateWindow *animateWindow;
    double showTime;


private slots:
    void mousePressed( int x, int y );
    void closeWindow();


protected:


};

#endif // QvkAnimateControl_H
