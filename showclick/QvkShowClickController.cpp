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

#include "QvkShowClickController.h"

QvkShowClickController::QvkShowClickController(QWidget *parent): QMainWindow(parent)
{
/*  Standardard Werte
    Circle=70
    Color=@Variant(\0\0\0\x43\x1\xff\xff\xff\xff\0\0\0\0\0\0)
    OnOff=0
    Opacity=0.5
    Radiant=false
    Showtime=5
*/

    QColor color   = Qt::red; //vkSettings.getShowClickColor();
    double opacity = 0.5; //vkSettings.getShowClickOpacity();

    ShowClickDialog = new QvkShowClickDialog();
    ShowClickDialog->vk_init( color, opacity );
    ShowClickDialog->setVisible( true );

    animateControl = new QvkAnimateControl( (double) ShowClickDialog->uiDialog.horizontalSliderShowtime->value()/10,
                                            ShowClickDialog->uiDialog.horizontalSliderCircle->value(),
                                            (double) ShowClickDialog->uiDialog.horizontalSliderOpacity->value()/100,
                                            color );

    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );

    connect( ShowClickDialog->uiDialog.checkBoxPointerOnOff, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );
    connect( ShowClickDialog, SIGNAL( signal_close() ), this, SLOT( slot_pointerOnOff() ) );

    // In the programm vokoShowClick we want set the checkBox to hide.
    // And we start showclick from start.
    // See in class ShowClickDialog::showEvent and QvkShowClickDialog::slot_afterWindowShown()
    ShowClickDialog->uiDialog.checkBoxPointerOnOff->hide();
}

QvkShowClickController::~QvkShowClickController()
{
}

// Before vokoShowClick is closed, showclick must be switched off.
void QvkShowClickController::slot_pointerOnOff()
{
    animateControl->pointerOnOff( false );
}
