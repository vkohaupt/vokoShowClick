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
#include "ui_showclickDialog.h"
#include "QvkSpezialSlider.h"
#include "QvkSpezialCheckbox.h"

QvkShowClickController::QvkShowClickController(QWidget *parent): QDialog(parent)
{
/*  Standardard Werte
    Circle=70
    Color=@Variant(\0\0\0\x43\x1\xff\xff\xff\xff\0\0\0\0\0\0)
    OnOff=0
    Opacity=0.5
    Radiant=false
    Showtime=5
*/

    uiDialog.setupUi( this );
    show();

    QvkSpezialSlider *sliderCircle = new QvkSpezialSlider( Qt::Horizontal );
    uiDialog.horizontalLayoutCircle->insertWidget( 0, sliderCircle );
    sliderCircle->setObjectName( "sliderCircle" );
    sliderCircle->setTracking( true );
    sliderCircle->setMinimum( 40 );
    sliderCircle->setMaximum( 80 );
    sliderCircle->setValue( 50 );
    sliderCircle->setShowValue( false );
    sliderCircle->show();

    QvkSpezialSlider *sliderOpacity = new QvkSpezialSlider( Qt::Horizontal );
    uiDialog.horizontalLayoutOpacity->insertWidget( 0, sliderOpacity );
    sliderOpacity->setObjectName( "sliderOpacity" );
    sliderOpacity->setTracking( true );
    sliderOpacity->setMinimum( 1 );
    sliderOpacity->setMaximum( 100 );
    sliderOpacity->setValue( 50 );
    sliderOpacity->setShowValue( false );
    sliderOpacity->show();

    QvkSpezialSlider *sliderShowtime = new QvkSpezialSlider( Qt::Horizontal );
    uiDialog.horizontalLayoutShowtime->insertWidget( 0, sliderShowtime );
    sliderShowtime->setObjectName( "sliderShowtime" );
    sliderShowtime->setTracking( true );
    sliderShowtime->setMinimum( 1 );
    sliderShowtime->setMaximum( 20 );
    sliderShowtime->setValue( 10 );
    sliderShowtime->setShowValue( false );
    sliderShowtime->show();

    vkSpezialCheckbox = new QvkSpezialCheckbox( this );
    uiDialog.horizontalLayout_2->insertWidget( 0, vkSpezialCheckbox );
    connect( vkSpezialCheckbox, SIGNAL( clicked( bool ) ), uiDialog.checkBoxPointerOnOff, SLOT( click() ) );

    QColor color   = Qt::red; //vkSettings.getShowClickColor();
    double opacity = 0.5; //vkSettings.getShowClickOpacity();

    ShowClickDialog = new QvkShowClickDialog( uiDialog );
    ShowClickDialog->setSpezialSliders( sliderCircle, sliderOpacity, sliderShowtime );
    ShowClickDialog->vk_init( color, opacity );

    animateControl = new QvkAnimateControl( (double) sliderShowtime->value()/10,
                                            sliderCircle->value(),
                                            (double) sliderOpacity->value()/100,
                                            color );

    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );

    connect( uiDialog.checkBoxPointerOnOff, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );

    // In the programm vokoShowClick we want set the checkBox to hide.
    // And we start showclick from start.
    // See in showEvent and slot_afterWindowShown()
    uiDialog.checkBoxPointerOnOff->hide();
}

QvkShowClickController::~QvkShowClickController()
{
}


void QvkShowClickController::closeEvent(QCloseEvent *)
{
    if ( vkSpezialCheckbox->checkState() == Qt::Checked )
    {
         vkSpezialCheckbox->click();
    }
    ShowClickDialog->vkhelp->close();
    ShowClickDialog->vkhelp->temporaryDirLocal.remove();
}


void QvkShowClickController::showEvent( QShowEvent *event )
{
    Q_UNUSED(event);
    // Call slot "slot_afterWindowShown" after the window has been shown
    QMetaObject::invokeMethod( this, "slot_afterWindowShown", Qt::ConnectionType::QueuedConnection );
}


void QvkShowClickController::slot_afterWindowShown()
{
    // In the program vokoShowClick, the checkBox is hide and showclick started from the beginning.
    vkSpezialCheckbox->click();
}
