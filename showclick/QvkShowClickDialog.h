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

#ifndef QvkShowClickDialog_H
#define QvkShowClickDialog_H

#include "ui_showclickDialog.h"
#include "QvkCircleWidget.h"

//#include "QvkSettings.h"

#include <QDialog>
#include <QTabWidget>

class QvkShowClickDialog: public QDialog

{
    Q_OBJECT
public:    
    QvkShowClickDialog( QColor color, bool radiant, double opacity );
    virtual ~QvkShowClickDialog();
    Ui_Dialog uiDialog;


public slots:

    
private:
    QvkCircleWidget *circleWidget;
    //    QvkSettings vkSettings;
    void setIconForSideBar();
    QColor getColor();
    void ok();

    
private slots:
    void slot_valueChangedSliderCircle( int value );
    void slot_valueChangedOpacity( int value );
    void slot_stateChangedRadiant( int );
    void slot_black();
    void slot_white();
    void slot_red();
    void slot_darkRed();
    void slot_green();
    void slot_darkGreen();
    void slot_blue();
    void slot_darkBlue();
    void slot_cyan();
    void slot_darkCyan();
    void slot_magenta();
    void slot_darkMagenta();
    void slot_yellow();
    void slot_darkYellow();
    void slot_gray();
    void slot_darkGray();
    void slot_afterWindowShown();

    void slot_toolButtonAuthor();
    void slot_toolButtonSource();
    void slot_toolButtonHomepage();
    void slot_toolButtonDonate();

    void slot_toolButtonColorDefault();
    void slot_SliderCircleDefault();
    void slot_SliderOpacityDefault();
    void slot_SlidershowTimeDefault();
    void slot_checkBoxRadiantDefault();


signals:
    void newCircleWidgetValue( int, QColor );
    void newShowtime( double value );
    void newOpacity( double value );
    void newRadiant( bool value);
    void signal_close();
    
protected:
    void closeEvent( QCloseEvent *event );
    void showEvent( QShowEvent *event );

};

#endif // QvkShowClickDialog_H
