#include "mainwindow.h"
#include "QvkShowClickDialog.h"
#include "QvkAnimateControl.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    QColor color   = Qt::red; //vkSettings.getShowClickColor();
    int radiant    = 20; //vkSettings.getShowClickRadiant();
    double opacity = 20; //vkSettings.getShowClickOpacity();

    QvkShowClickDialog *ShowClickDialog = new QvkShowClickDialog( color, radiant, opacity );
    ShowClickDialog->show();
    


//    connect( myUi.pointerDialogPushButton, SIGNAL( clicked() ), ShowClickDialog, SLOT( show() ) );
  
    QvkAnimateControl *animateControl = new QvkAnimateControl( (double) ShowClickDialog->myUiDialog.horizontalSliderShowtime->value()/10,
					    ShowClickDialog->myUiDialog.horizontalSliderCircle->value(),
					    ShowClickDialog->myUiDialog.checkBoxRadiant->checkState(),
					    (double) ShowClickDialog->myUiDialog.horizontalSliderOpacity->value()/100,
					    color );
    
//    connect( myUi.pointerCheckBox, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );
     
    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );
    connect( ShowClickDialog, SIGNAL( newRadiant( bool ) ), animateControl, SLOT( setRadiant( bool ) ) );

}

MainWindow::~MainWindow()
{
}

