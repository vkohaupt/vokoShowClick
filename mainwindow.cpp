#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
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
    bool radiant   = false; //vkSettings.getShowClickRadiant();

    ShowClickDialog = new QvkShowClickDialog( color, radiant, opacity );
    ShowClickDialog->setVisible( true );

    animateControl = new QvkAnimateControl( (double) ShowClickDialog->myUiDialog.horizontalSliderShowtime->value()/10,
                                            ShowClickDialog->myUiDialog.horizontalSliderCircle->value(),
                                            ShowClickDialog->myUiDialog.checkBoxRadiant->checkState(),
                                            (double) ShowClickDialog->myUiDialog.horizontalSliderOpacity->value()/100,
                                            color );

    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );
    connect( ShowClickDialog, SIGNAL( newRadiant( bool ) ), animateControl, SLOT( setRadiant( bool ) ) );

    connect( ShowClickDialog->myUiDialog.checkBoxPointerOnOff, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );
    connect( ShowClickDialog, SIGNAL( signal_close() ), this, SLOT( slot_pointerOnOff() ) );

    // In the programm vokoShowClick we want set the checkBox to hide.
    // And we start showclick from start.
    // See in class ShowClickDialog::showEvent and QvkShowClickDialog::slot_afterWindowShown()
    ShowClickDialog->myUiDialog.checkBoxPointerOnOff->hide();
}

MainWindow::~MainWindow()
{
}

// Before vokoShowClick is closed, showclick must be switched off.
void MainWindow::slot_pointerOnOff()
{
    animateControl->pointerOnOff( false );
}
