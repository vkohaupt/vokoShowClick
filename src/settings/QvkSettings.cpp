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

#include "QvkSettings.h"
#include "global.h"
#include "ui_mainwindow.h"

#include <QFileInfo>
#include <QMouseEvent>
#include <QCheckBox>
#include <QRadioButton>

QvkSettings::QvkSettings()
{
    // Dient nur zum anlegen des Profils damit das log erstellt werden kann
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, global::name, global::name, Q_NULLPTR );
    settings.beginGroup( global::name );
    settings.setValue( "Version", global::version );
    settings.endGroup();
}

QvkSettings::~QvkSettings(){}

void QvkSettings::readAll( Ui_MainWindow *ui_mainwindow, QMainWindow *parent )
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, global::name, global::name, Q_NULLPTR );

    QList<QComboBox *> listComboBox = ui_mainwindow->centralwidget->findChildren<QComboBox *>();
    for ( int i = 0; i < listComboBox.count(); i++ )
    {
        QString valueText = settings.value( listComboBox.at(i)->objectName(), "" ).toString();
        int valueInt = listComboBox.at(i)->findText( valueText );
        if ( valueInt > -1 )
        {
            listComboBox.at(i)->setCurrentIndex( valueInt );
        }
    }

    QList<QCheckBox *> listCheckBox = ui_mainwindow->centralwidget->findChildren<QCheckBox *>();
    for ( int i = 0; i < listCheckBox.count(); i++ )
    {
        // We found a setting, then we want set or not.
        if ( settings.value( listCheckBox.at(i)->objectName(), false ).toBool() == true )
        {
            listCheckBox.at(i)->click();
        }
    }

    QList<QSlider *> listSlider = ui_mainwindow->centralwidget->findChildren<QSlider *>();
    for ( int i = 0; i < listSlider.count(); i++ )
    {
        if ( listSlider.at(i)->objectName().contains( "sliderCircle" ) == true )
        {
            int value = settings.value( listSlider.at(i)->objectName(), 50 ).toInt();
            listSlider.at(i)->setValue( value );
        }

        if ( listSlider.at(i)->objectName().contains( "sliderOpacity" ) == true )
        {
            int value = settings.value( listSlider.at(i)->objectName(), 50 ).toInt();
            listSlider.at(i)->setValue( value );
        }

        if ( listSlider.at(i)->objectName().contains( "sliderShowtime" ) == true )
        {
            int value = settings.value( listSlider.at(i)->objectName(), 10 ).toInt();
            listSlider.at(i)->setValue( value );
        }
    }
}

/*
 *
 */
void QvkSettings::saveAll(Ui_MainWindow *ui_mainwindow , QMainWindow *parent, bool log )
{
    Q_UNUSED(parent);
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, global::name, global::name, Q_NULLPTR );
    if ( log == true )
    {
        // do nothing
    }
    else
        settings.clear();

    settings.beginGroup( global::name );
    if ( log == true )
    {
        // do nothing
    }
    else
        settings.setValue( "Version", global::version );
    settings.endGroup();

    QList<QCheckBox *> listCheckBox = ui_mainwindow->centralwidget->findChildren<QCheckBox *>();
    for ( int i = 0; i < listCheckBox.count(); i++ )
    {
        if ( log == true )
            qDebug().noquote().nospace() << listCheckBox.at(i)->objectName() << "=" << listCheckBox.at(i)->isChecked();
        else
            settings.setValue( listCheckBox.at(i)->objectName(), listCheckBox.at(i)->isChecked() );
    }

    QList<QComboBox *> listComboBox = ui_mainwindow->centralwidget->findChildren<QComboBox *>();
    for ( int i = 0; i < listComboBox.count(); i++ )
    {
        if ( log == true )
            qDebug().noquote().nospace() << listComboBox.at(i)->objectName() << "=" << listComboBox.at(i)->currentText();
        else
            settings.setValue( listComboBox.at(i)->objectName(), listComboBox.at(i)->currentText() );
    }

    QList<QSlider *> listSlider = ui_mainwindow->centralwidget->findChildren<QSlider *>();
    for ( int i = 0; i < listSlider.count(); i++ )
    {
        if ( log == true )
            qDebug().noquote().nospace() << listSlider.at(i)->objectName() << "=" << listSlider.at(i)->value();
        else
            settings.setValue( listSlider.at(i)->objectName(), listSlider.at(i)->value() );
    }

}

QString QvkSettings::getFileName()
{
    QSettings settings( QSettings::IniFormat, QSettings::UserScope, global::name, global::name, Q_NULLPTR );
    return settings.fileName();
}
