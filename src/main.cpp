#include "mainwindow.h"

#include <QApplication>
#include <QDBusConnection>
#include <QMessageBox>

#include <global.h>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);

    QIcon icon( ":/pictures/logo/vokoShowClick.png" );
    a.setWindowIcon( icon );

#ifdef Q_OS_LINUX
    // For Windows wie need a other code !!!!!!!!!!!!!!!!!!
    if( not QDBusConnection::sessionBus().registerService( "org.vokoShowClick.ShowClick" ) )
    {
        QString titel = global::name + " " + global::version;
        QMessageBox::StandardButton ret = QMessageBox::information( NULL,
                                                                    QObject::tr( titel.toLatin1() ),
                                                                    QObject::tr( global::name.toLatin1() + " " + "can be started only once" ),
                                                                    QMessageBox::Close );
        Q_UNUSED(ret);
        return 0;
    }

    if ( qgetenv( "XDG_SESSION_TYPE" ).toLower() == "x11" )
    {
        MainWindow w;
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
    MainWindow w;
    return a.exec();
#endif

}
