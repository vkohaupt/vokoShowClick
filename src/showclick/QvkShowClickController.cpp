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

    QColor color   = Qt::red; //vkSettings.getShowClickColor();
    double opacity = 0.5; //vkSettings.getShowClickOpacity();

    ShowClickDialog = new QvkShowClickDialog( uiDialog );
    ShowClickDialog->setSpezialSliders( sliderCircle, sliderOpacity, sliderShowtime );
    ShowClickDialog->vk_init( color, opacity );

    animateControl = new QvkAnimateControl( (double) sliderShowtime->value()/10,
                                            sliderCircle->value(),
                                            (double) sliderOpacity->value()/100,
                                            color );

    vkSpezialCheckbox = new QvkSpezialCheckbox( this );
    uiDialog.horizontalLayout_2->insertWidget( 0, vkSpezialCheckbox );
    connect( vkSpezialCheckbox, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );

    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );
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

    ShowClickDialog->vkLicenses->close();
    ShowClickDialog->vkhelp->close();
    ShowClickDialog->vkhelp->temporaryDirLocal.remove();
}


void QvkShowClickController::showEvent( QShowEvent * )
{
    // Call slot "slot_afterWindowShown" after the window has been shown
    QMetaObject::invokeMethod( this, "slot_afterWindowShown", Qt::ConnectionType::QueuedConnection );
}


void QvkShowClickController::slot_afterWindowShown()
{
    // In the program vokoShowClick, the checkBox is hide and showclick started from the beginning.
    vkSpezialCheckbox->click();
}
