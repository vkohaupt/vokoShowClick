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
#include "global.h"

#include <QApplication>
#include <QMessageBox>
#include <QDBusConnection>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ********************************* Application started only once
    if( not QDBusConnection::sessionBus().registerService( "org.vokoShowClick.ShowClick" ) )
    {
        QMessageBox::StandardButton ret = QMessageBox::information( NULL,
                                                                    QObject::tr( "Info" ),
                                                                    QObject::tr( "vokoShowClick can be started only once" ),
                                                                    QMessageBox::Close );
        (void)ret;
        return 0;
    }
    // ******************************************************************


#ifdef Q_OS_LINUX
    if ( qgetenv( "XDG_SESSION_TYPE" ).toLower() == "x11" )
    {
        QvkShowClickController w;
        return a.exec();
    }

    if ( qgetenv( "XDG_SESSION_TYPE" ).toLower() == "wayland" )
    {
        qDebug().noquote() << global::nameOutput << "Desktop session is a Wayland session";

        QMessageBox *messageBox = new QMessageBox();
        QIcon icon( QString::fromUtf8( ":/pictures/logo/logo.png" ) );
        messageBox->setWindowIcon( icon );
        messageBox->setWindowTitle( global::name + " " + global::version );
        messageBox->setIcon( QMessageBox::Critical );
        messageBox->setText( "Wayland desktop session detected" );
        messageBox->setInformativeText( "To time Wayland is not supported. Please close vokoShowClick, logout from your Desktop and start a X11 Desktop session and then start vokoShowClick." );
        messageBox->exec();
    }
#endif

#ifdef Q_OS_WIN
    QvkShowClickController w;
    return a.exec();
#endif
}
