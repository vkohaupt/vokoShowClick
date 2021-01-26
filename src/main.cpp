#include "mainwindow.h"

#include <QApplication>
#include <QDBusConnection>
#include <QMessageBox>

#include <global.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QIcon icon( ":/pictures/logo/vokoClick.png" );
    a.setWindowIcon( icon );

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

#ifdef Q_OS_LINUX
    if ( qgetenv( "XDG_SESSION_TYPE" ).toLower() == "x11" )
    {
        MainWindow w;
        w.show();
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
    w.show();
    return a.exec();
#endif

}
