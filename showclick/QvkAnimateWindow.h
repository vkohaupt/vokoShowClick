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

#ifndef QvkAnimateWindow_H
#define QvkAnimateWindow_H

#include <QDialog>


class QvkAnimateWindow: public QDialog

{
    Q_OBJECT
public:    
    QvkAnimateWindow();
    virtual ~QvkAnimateWindow();
    
public:


public slots:
    void setRadiusColor( int valueRadius, QColor valueColor );
    void setOpacity( double value );
    void setRadiant( bool value );


private:
    int diameter;
    QColor color;
    double opacity;
    bool radiant;

private slots:


protected:
    void paintEvent(QPaintEvent *event);


};

#endif // QvkAnimateWindow_H
