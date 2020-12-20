#include "mainwindow.h"
#include "global.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

#ifdef Q_OS_LINUX
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
