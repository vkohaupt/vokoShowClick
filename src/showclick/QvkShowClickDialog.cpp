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

#include "QvkShowClickDialog.h"
#include "global.h"
#include "QvkLicenses.h"

#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QCursor>

QvkShowClickDialog::QvkShowClickDialog( Ui_Dialog ui_Dialog)
{
    uiDialog = ui_Dialog;
}


void QvkShowClickDialog::setSpezialSliders( QvkSpezialSlider *vk_sliderCircle, QvkSpezialSlider *vk_sliderOpacity, QvkSpezialSlider *vk_sliderShowtime )
{
    sliderCircle = vk_sliderCircle;
    sliderOpacity = vk_sliderOpacity;
    sliderShowtime = vk_sliderShowtime;
}


void QvkShowClickDialog::vk_init( QColor color, double opacity )
{
    //    vkSettings.readAll();

    setIconForSideBar();

    setWindowTitle( global::name + " " + global::version );

    vkhelp = new QvkHelp( uiDialog );

#ifdef Q_OS_WIN
    QPixmap pixmap_1( ":/pictures/showclick/windows.png" );
#endif
#ifdef Q_OS_LINUX
    QPixmap pixmapOS( ":/pictures/showclick/linux.png" );
#endif
    pixmapOS = pixmapOS.scaled( 70, 70, Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    uiDialog.labelOS->setPixmap( pixmapOS );
    uiDialog.labelOS->setMinimumSize( 70, 70);

    QPixmap pixmap( ":/pictures/showclick/cursorAbout.png" );
    pixmap = pixmap.scaled( 30, 30 );
    QCursor cursor( pixmap );
    uiDialog.toolButtonDonate->setCursor( cursor );
    uiDialog.toolButtonHomepage->setCursor( cursor );
    uiDialog.toolButtonSource->setCursor( cursor );
    uiDialog.toolButtonLicense->setCursor( cursor );
    uiDialog.toolButtonAuthor->setCursor( cursor );

    QvkLicenses *licenses = new QvkLicenses();

    connect( uiDialog.toolButtonDonate,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonDonate() ) );
    connect( uiDialog.toolButtonHomepage, SIGNAL( clicked() ), this, SLOT( slot_toolButtonHomepage() ) );
    connect( uiDialog.toolButtonSource,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonSource() ) );
    connect( uiDialog.toolButtonAuthor,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonAuthor() ) );
    connect( uiDialog.toolButtonLicense,  SIGNAL( clicked() ), licenses, SLOT( show() ) );

    uiDialog.frame_3->setStyleSheet("background-color:white;");
    uiDialog.frame_3->resize(100, 100);

    uiDialog.pushButton_white->setStyleSheet( "background-color: white;" );
    uiDialog.pushButton_black->setStyleSheet( "background-color: black;" );
    uiDialog.pushButton_red->setStyleSheet( "background-color: red;" );
    uiDialog.pushButton_darkRed->setStyleSheet( "background-color: darkRed;" );
    uiDialog.pushButton_green->setStyleSheet( "background-color: green;" );
    uiDialog.pushButton_darkGreen->setStyleSheet( "background-color: darkGreen;" );
    uiDialog.pushButton_blue->setStyleSheet( "background-color: blue;" );
    uiDialog.pushButton_darkBlue->setStyleSheet( "background-color: darkBlue;" );
    uiDialog.pushButton_cyan->setStyleSheet( "background-color: cyan;" );
    uiDialog.pushButton_darkCyan->setStyleSheet( "background-color: darkCyan;" );
    uiDialog.pushButton_magenta->setStyleSheet( "background-color: magenta;" );
    uiDialog.pushButton_darkMagenta->setStyleSheet( "background-color: darkMagenta;" );
    uiDialog.pushButton_yellow->setStyleSheet( "background-color: yellow;" );
    uiDialog.pushButton_darkYellow->setStyleSheet( "background-color: darkkhaki;" );
    uiDialog.pushButton_gray->setStyleSheet( "background-color: gray;" );
    uiDialog.pushButton_darkGray->setStyleSheet( "background-color: darkGray;" );
    
    connect( uiDialog.pushButton_white, SIGNAL( clicked() ), this, SLOT( slot_white() ) );
    connect( uiDialog.pushButton_black, SIGNAL( clicked() ), this, SLOT( slot_black() ) );
    connect( uiDialog.pushButton_red, SIGNAL( clicked() ), this, SLOT( slot_red() ) );
    connect( uiDialog.pushButton_darkRed, SIGNAL( clicked() ), this, SLOT( slot_darkRed() ) );
    connect( uiDialog.pushButton_green, SIGNAL( clicked() ), this, SLOT( slot_green() ) );
    connect( uiDialog.pushButton_darkGreen, SIGNAL( clicked() ), this, SLOT( slot_darkGreen() ) );
    connect( uiDialog.pushButton_blue, SIGNAL( clicked() ), this, SLOT( slot_blue() ) );
    connect( uiDialog.pushButton_darkBlue, SIGNAL( clicked() ), this, SLOT( slot_darkBlue() ) );
    connect( uiDialog.pushButton_cyan, SIGNAL( clicked() ), this, SLOT( slot_cyan() ) );
    connect( uiDialog.pushButton_darkCyan, SIGNAL( clicked() ), this, SLOT( slot_darkCyan() ) );
    connect( uiDialog.pushButton_magenta, SIGNAL( clicked() ), this, SLOT( slot_magenta() ) );
    connect( uiDialog.pushButton_darkMagenta, SIGNAL( clicked() ), this, SLOT( slot_darkMagenta() ) );
    connect( uiDialog.pushButton_yellow, SIGNAL( clicked() ), this, SLOT( slot_yellow() ) );
    connect( uiDialog.pushButton_darkYellow, SIGNAL( clicked() ), this, SLOT( slot_darkYellow() ) );
    connect( uiDialog.pushButton_gray, SIGNAL( clicked() ), this, SLOT( slot_gray() ) );
    connect( uiDialog.pushButton_darkGray, SIGNAL( clicked() ), this, SLOT( slot_darkGray() ) );

    connect( uiDialog.toolButtonColorDefault, SIGNAL( clicked() ), this, SLOT( slot_toolButtonColorDefault() ) );
    connect( uiDialog.toolButtonSliderCircleDefault, SIGNAL( clicked() ), this, SLOT( slot_SliderCircleDefault() ) );
    connect( uiDialog.toolButtonSliderOpacityDefault, SIGNAL( clicked() ), this, SLOT(slot_SliderOpacityDefault() ) );
    connect( uiDialog.toolButtonShowTimeDefault, SIGNAL( clicked() ), this, SLOT(slot_SlidershowTimeDefault() ) );
    
    circleWidget = new QvkCircleWidget( uiDialog.frame_3   );
    circleWidget->show();
    slot_valueChangedSliderCircle( sliderCircle->value() );
    circleWidget->setColor( color );
    circleWidget->setOpacity( opacity );
    
    connect( sliderCircle, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChangedSliderCircle( int ) ) );
    
    connect( sliderOpacity, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChangedOpacity( int ) ) );
    sliderOpacity->setSliderPosition( opacity*100 );
    
    connect( sliderShowtime, SIGNAL( valueChanged( int ) ), this, SLOT( ok() ) );
}

QvkShowClickDialog::~QvkShowClickDialog()
{
}


void QvkShowClickDialog::setIconForSideBar()
{
    for ( int x = 0; x < uiDialog.tabWidget->count(); x++ )
    {
        QIcon icon = uiDialog.tabWidget->tabIcon( x );
        QPixmap workPixmap = icon.pixmap( uiDialog.tabWidget->iconSize() );
        QTransform transform;
        transform.rotate( 90 );
        workPixmap = workPixmap.transformed( transform, Qt::SmoothTransformation );
        uiDialog.tabWidget->setTabIcon( x, workPixmap );
    }
}

void QvkShowClickDialog::slot_toolButtonDonate()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-donate.html" ) );
}

void QvkShowClickDialog::slot_toolButtonHomepage()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen.html" ) );
}

void QvkShowClickDialog::slot_toolButtonSource()
{
    QDesktopServices::openUrl( QUrl( "https://github.com/vkohaupt/vokoShowClick" ) );
}

void QvkShowClickDialog::slot_toolButtonAuthor()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-contact.html" ) );
}

QColor QvkShowClickDialog::getColor()
{
    return circleWidget->getColor();
}

void QvkShowClickDialog::slot_toolButtonColorDefault()
{
    uiDialog.pushButton_red->click();
}

void QvkShowClickDialog::slot_SliderCircleDefault()
{
    sliderCircle->setValue( 50 );
}

void QvkShowClickDialog::slot_SliderOpacityDefault()
{
    sliderOpacity->setValue( 50 );
}

void QvkShowClickDialog::slot_SlidershowTimeDefault()
{
    sliderShowtime->setValue( 10 );
}

void QvkShowClickDialog::ok()
{
    emit newCircleWidgetValue( circleWidget->getDiameter(), circleWidget->getColor() );
    emit newShowtime( (double) sliderShowtime->value()/10 );
    emit newOpacity( circleWidget->getOpacity() );
}

void QvkShowClickDialog::slot_valueChangedSliderCircle( int value )
{
    circleWidget->setDiameter( value );
    ok();
}

void QvkShowClickDialog::slot_valueChangedOpacity( int value )
{
    double value_1 = value;
    circleWidget->setOpacity( value_1 / 100 );
    ok();
}

void QvkShowClickDialog::slot_white()
{
    circleWidget->setColor( Qt::white );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_black()
{
    circleWidget->setColor( Qt::black );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_red()
{
    circleWidget->setColor( Qt::red );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkRed()
{
    circleWidget->setColor( Qt::darkRed );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_green()
{
    circleWidget->setColor( Qt::green );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkGreen()
{
    circleWidget->setColor( Qt::darkGreen );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_blue()
{
    circleWidget->setColor( Qt::blue );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkBlue()
{
    circleWidget->setColor( Qt::darkBlue );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_cyan()
{
    circleWidget->setColor( Qt::cyan );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkCyan()
{
    circleWidget->setColor( Qt::darkCyan );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_magenta()
{
    circleWidget->setColor( Qt::magenta );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkMagenta()
{
    circleWidget->setColor( Qt::darkMagenta );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_yellow()
{
    circleWidget->setColor( Qt::yellow );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkYellow()
{
    circleWidget->setColor( Qt::darkYellow );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_gray()
{
    circleWidget->setColor( Qt::gray );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkGray()
{
    circleWidget->setColor( Qt::darkGray );
    uiDialog.frame_3->setFocus();
    ok();
}
