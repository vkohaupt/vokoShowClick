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

#include "QvkLicenses.h"

#include <QSettings>
#include <QDirIterator>
#include <QFontDatabase>
#include <QFont>

QvkLicenses::QvkLicenses() : ui( new Ui::license )
{
    ui->setupUi( this );

    QIcon icon;
    icon.addFile( QString::fromUtf8( ":/pictures/logo/vokoShowClick.png" ), QSize(), QIcon::Normal, QIcon::Off );
    setWindowIcon( icon );

    const QFont fixedFont = QFontDatabase::systemFont( QFontDatabase::FixedFont );

    ui->label_dummy_1->hide();
    ui->label_dummy_2->hide();
    ui->label_dummy_3->hide();
    ui->label_dummy_4->hide();
    int row = 0;
    QDirIterator dirIterator( ":/pictures/", QDir::Files, QDirIterator::Subdirectories );
    while ( dirIterator.hasNext() )
    {
        QString string = dirIterator.next();
        if ( ( string.contains( ".license" ) == true ) and ( string.contains( "template" ) == false ) )
        {
            QSettings settings( dirIterator.filePath(), QSettings::IniFormat );
            settings.beginGroup( "license" );

            QPixmap pixmapSpace_0( ":/pictures/showclick/space.png" );
            pixmapSpace_0 = pixmapSpace_0.scaled( 10, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QLabel *labelSpace_0 = new QLabel;
            labelSpace_0->setPixmap( pixmapSpace_0 );
            ui->gridLayout->addWidget( labelSpace_0, row, 0, Qt::AlignCenter );

            QPixmap pixmap( dirIterator.filePath().replace( "license", "png" ) );
            pixmap = pixmap.scaled( 50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            QLabel *label = new QLabel;
            label->setPixmap( pixmap );
            ui->gridLayout->addWidget( label, row, 1, Qt::AlignCenter );

            QPixmap pixmapSpace_1( ":/pictures/showclick/space.png" );
            pixmapSpace_1 = pixmapSpace_1.scaled( 10, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QLabel *labelSpace_1 = new QLabel;
            labelSpace_1->setPixmap( pixmapSpace_1 );
            ui->gridLayout->addWidget( labelSpace_1, row, 2, Qt::AlignCenter );

            QLabel *labelAuthor = new QLabel;
            labelAuthor->setText( "Author : (C) " + settings.value( "author" ).toString() +
                                  "\n" +
                                  "License: " + settings.value( "license" ).toString() +
                                  "\n" +
                                  "Source : " + settings.value( "url" ).toString() );
            ui->gridLayout->addWidget( labelAuthor, row, 3 );

            QPixmap pixmapSpaceRow( ":/pictures/showclick/space.png" );
            pixmapSpaceRow = pixmapSpaceRow.scaled( 50, 10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            QLabel *labelSpaceRow = new QLabel;
            labelSpaceRow->setPixmap( pixmapSpaceRow );
            row++;
            ui->gridLayout->addWidget( labelSpaceRow, row, 1 );
            row++;

            settings.endGroup();
        }
    }
}


QvkLicenses::~QvkLicenses(){}
