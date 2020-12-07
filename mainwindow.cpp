#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
                                       , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    
    
    
/*    
    QColor color   = vkSettings.getShowClickColor();
    int radiant    = vkSettings.getShowClickRadiant();
    double opacity = vkSettings.getShowClickOpacity();
    
    ShowClickDialog = new QvkShowClickDialog( color, radiant, opacity );
    connect( myUi.pointerDialogPushButton, SIGNAL( clicked() ), ShowClickDialog, SLOT( show() ) );
  
    animateControl = new QvkAnimateControl( (double) ShowClickDialog->myUiDialog.horizontalSliderShowtime->value()/10,
					    ShowClickDialog->myUiDialog.horizontalSliderCircle->value(),
					    ShowClickDialog->myUiDialog.checkBoxRadiant->checkState(),
					    (double) ShowClickDialog->myUiDialog.horizontalSliderOpacity->value()/100,
					    color );
    
    connect( myUi.pointerCheckBox, SIGNAL( clicked( bool ) ), animateControl, SLOT( pointerOnOff( bool ) ) );
     
    connect( ShowClickDialog, SIGNAL( newCircleWidgetValue( int, QColor ) ), animateControl, SLOT( setDiameterColor( int, QColor ) ) );
    connect( ShowClickDialog, SIGNAL( newShowtime( double ) ), animateControl, SLOT( setShowTime( double ) ) );
    connect( ShowClickDialog, SIGNAL( newOpacity( double ) ), animateControl, SLOT( setOpacity( double ) ) );
    connect( ShowClickDialog, SIGNAL( newRadiant( bool ) ), animateControl, SLOT( setRadiant( bool ) ) );
*/      
}

MainWindow::~MainWindow()
{
    delete ui;
}

