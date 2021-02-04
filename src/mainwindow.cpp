#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QvkPushButton.h"
#include "global.h"

#include <QDebug>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

    setWindowTitle( global::name + " " + global::version );
    setIconSideBar();
    setPictureOperatingSystem();
    setColorButtons();
    setSpezialSlider();
    setSpezialCheckBox();
    setToolButtonDefaultValues();
    setMouseClick();
    setAbout();
    setCircleWidget();
    setHelp();
    setSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    vkSettings->saveAll( ui, this );
    vkSpezialCheckbox->signal_clicked( false );
    vkLicenses->close();
    vkHelp->close();
}


void MainWindow::setIconSideBar()
{
    for ( int x = 0; x < ui->tabWidget->count(); x++ )
    {
        QIcon icon = ui->tabWidget->tabIcon( x );
        QPixmap workPixmap = icon.pixmap( ui->tabWidget->iconSize() );
        QTransform transform;
        transform.rotate( 90 );
        workPixmap = workPixmap.transformed( transform, Qt::SmoothTransformation );
        ui->tabWidget->setTabIcon( x, workPixmap );
    }
}


void MainWindow::setPictureOperatingSystem()
{
#ifdef Q_OS_WIN
    QPixmap pixmapOS( ":/pictures/showclick/windows.png" );
#endif
#ifdef Q_OS_LINUX
    QPixmap pixmapOS( ":/pictures/showclick/linux.png" );
#endif
    pixmapOS.setDevicePixelRatio( devicePixelRatioF() );
    pixmapOS = pixmapOS.scaled( 70 * devicePixelRatioF(), 70 * devicePixelRatioF(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    ui->labelOS->setPixmap( pixmapOS );
    ui->labelOS->setMinimumSize( 70, 70);
}


void MainWindow::setColorButtons()
{
    int minimumHeight = 34;
    QvkPushButton *vkPushButton_white = new QvkPushButton( Qt::white );
    vkPushButton_white->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_white, 0, 0 );
    connect( vkPushButton_white, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_white() ) );

    QvkPushButton *vkPushButton_black = new QvkPushButton( Qt::black );
    vkPushButton_black->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_black, 0, 1 );
    connect( vkPushButton_black, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_black() ) );

    QvkPushButton *vkPushButton_red = new QvkPushButton( Qt::red );
    vkPushButton_red->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_red, 0, 2 );
    connect( vkPushButton_red, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_red() ) );

    QvkPushButton *vkPushButton_darkRed = new QvkPushButton( Qt::darkRed );
    vkPushButton_darkRed->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkRed, 0, 3 );
    connect( vkPushButton_darkRed, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkRed() ) );

    QvkPushButton *vkPushButton_green = new QvkPushButton( Qt::green );
    vkPushButton_green->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_green, 1, 0 );
    connect( vkPushButton_green, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_green() ) );

    QvkPushButton *vkPushButton_darkGreen = new QvkPushButton( Qt::darkGreen );
    vkPushButton_darkGreen->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkGreen, 1, 1 );
    connect( vkPushButton_darkGreen, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkGreen() ) );

    QvkPushButton *vkPushButton_blue = new QvkPushButton( Qt::blue );
    vkPushButton_blue->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_blue, 1, 2 );
    connect( vkPushButton_blue, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_blue() ) );

    QvkPushButton *vkPushButton_darkBlue = new QvkPushButton( Qt::darkBlue );
    vkPushButton_darkBlue->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkBlue, 1, 3 );
    connect( vkPushButton_darkBlue, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkBlue() ) );

    QvkPushButton *vkPushButton_cyan = new QvkPushButton( Qt::cyan );
    vkPushButton_cyan->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_cyan, 2, 0 );
    connect( vkPushButton_cyan, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_cyan() ) );

    QvkPushButton *vkPushButton_darkCyan = new QvkPushButton( Qt::darkCyan );
    vkPushButton_darkCyan->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkCyan, 2, 1 );
    connect( vkPushButton_darkCyan, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkCyan() ) );

    QvkPushButton *vkPushButton_magenta = new QvkPushButton( Qt::magenta );
    vkPushButton_magenta->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_magenta, 2, 2 );
    connect( vkPushButton_magenta, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_magenta() ) );

    QvkPushButton *vkPushButton_darkMagenta = new QvkPushButton( Qt::darkMagenta );
    vkPushButton_darkMagenta->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkMagenta, 2, 3 );
    connect( vkPushButton_darkMagenta, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkMagenta() ) );

    QvkPushButton *vkPushButton_yellow = new QvkPushButton( Qt::yellow );
    vkPushButton_yellow->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_yellow, 3, 0 );
    connect( vkPushButton_yellow, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_yellow() ) );

    QvkPushButton *vkPushButton_darkYellow = new QvkPushButton( Qt::darkYellow );
    vkPushButton_darkYellow->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkYellow, 3, 1 );
    connect( vkPushButton_darkYellow, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkYellow() ) );

    QvkPushButton *vkPushButton_gray = new QvkPushButton( Qt::gray );
    vkPushButton_gray->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_gray, 3, 2 );
    connect( vkPushButton_gray, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_gray() ) );

    QvkPushButton *vkPushButton_darkGray = new QvkPushButton( Qt::darkGray );
    vkPushButton_darkGray->setMinimumHeight( minimumHeight );
    ui->gridLayout->addWidget( vkPushButton_darkGray, 3, 3 );
    connect( vkPushButton_darkGray, SIGNAL( clicked() ), this, SLOT( slot_vkPushButton_darkGray() ) );
}


void MainWindow::slot_vkPushButton_white()
{
    vkCircleWidget->setColor( Qt::white );
}

void MainWindow::slot_vkPushButton_black()
{
    vkCircleWidget->setColor( Qt::black );
}

void MainWindow::slot_vkPushButton_red()
{
    vkCircleWidget->setColor( Qt::red );
}

void MainWindow::slot_vkPushButton_darkRed()
{
    vkCircleWidget->setColor( Qt::darkRed );
}

void MainWindow::slot_vkPushButton_green()
{
    vkCircleWidget->setColor( Qt::green );
}

void MainWindow::slot_vkPushButton_darkGreen()
{
    vkCircleWidget->setColor( Qt::darkGreen );
}

void MainWindow::slot_vkPushButton_blue()
{
    vkCircleWidget->setColor( Qt::blue );
}

void MainWindow::slot_vkPushButton_darkBlue()
{
    vkCircleWidget->setColor( Qt::darkBlue );
}

void MainWindow::slot_vkPushButton_cyan()
{
    vkCircleWidget->setColor( Qt::cyan );
}

void MainWindow::slot_vkPushButton_darkCyan()
{
    vkCircleWidget->setColor( Qt::darkCyan );
}

void MainWindow::slot_vkPushButton_magenta()
{
    vkCircleWidget->setColor( Qt::magenta );
}

void MainWindow::slot_vkPushButton_darkMagenta()
{
    vkCircleWidget->setColor( Qt::darkMagenta );
}

void MainWindow::slot_vkPushButton_yellow()
{
    vkCircleWidget->setColor( Qt::yellow );
}

void MainWindow::slot_vkPushButton_darkYellow()
{
    vkCircleWidget->setColor( Qt::darkYellow );
}

void MainWindow::slot_vkPushButton_gray()
{
    vkCircleWidget->setColor( Qt::gray );
}

void MainWindow::slot_vkPushButton_darkGray()
{
    vkCircleWidget->setColor( Qt::darkGray );
}

void MainWindow::setSpezialSlider()
{
    vkSpezialSliderCircle = new QvkSpezialSlider( Qt::Horizontal );
    ui->horizontalLayoutCircle->insertWidget( 0, vkSpezialSliderCircle );
    vkSpezialSliderCircle->setObjectName( "sliderCircle" );
    vkSpezialSliderCircle->setTracking( true );
    vkSpezialSliderCircle->setMinimum( 40 );
    vkSpezialSliderCircle->setMaximum( 80 );
    vkSpezialSliderCircle->setValue( 50 );
    vkSpezialSliderCircle->setShowValue( false );
    vkSpezialSliderCircle->show();

    vkSpezialSliderOpacity = new QvkSpezialSlider( Qt::Horizontal );
    ui->horizontalLayoutOpacity->insertWidget( 0, vkSpezialSliderOpacity );
    vkSpezialSliderOpacity->setObjectName( "sliderOpacity" );
    vkSpezialSliderOpacity->setTracking( true );
    vkSpezialSliderOpacity->setMinimum( 1 );
    vkSpezialSliderOpacity->setMaximum( 100 );
    vkSpezialSliderOpacity->setValue( 70 );
    vkSpezialSliderOpacity->setShowValue( false );
    vkSpezialSliderOpacity->show();

    vkSpezialSliderShowtime = new QvkSpezialSlider( Qt::Horizontal );
    ui->horizontalLayoutShowtime->insertWidget( 0, vkSpezialSliderShowtime );
    vkSpezialSliderShowtime->setObjectName( "sliderShowtime" );
    vkSpezialSliderShowtime->setTracking( true );
    vkSpezialSliderShowtime->setMinimum( 1 );
    vkSpezialSliderShowtime->setMaximum( 20 );
    vkSpezialSliderShowtime->setValue( 10 );
    vkSpezialSliderShowtime->setShowValue( false );
    vkSpezialSliderShowtime->show();
}


void MainWindow::setSpezialCheckBox()
{
    vkSpezialCheckbox = new QvkSpezialCheckbox();
    ui->horizontalLayout_2->insertWidget( 0, vkSpezialCheckbox );
    connect( vkSpezialCheckbox, SIGNAL( signal_clicked( bool ) ), this, SLOT( slot_pointerOnOff( bool ) ) );
}


void MainWindow::slot_pointerOnOff( bool value )
{
    if ( value == true )
    {
        vkGlobalMouse->setCursorOn();
        vkGlobalMouse->mousePressed();
    }

    if ( value == false )
    {
        vkGlobalMouse->setCursorOff();
    }
}


void MainWindow::setToolButtonDefaultValues()
{
    connect( ui->toolButtonColorDefault,         SIGNAL( clicked() ), this, SLOT( slot_toolButtonColorDefault() ) );
    connect( ui->toolButtonSliderCircleDefault,  SIGNAL( clicked() ), this, SLOT( slot_SliderCircleDefault() ) );
    connect( ui->toolButtonSliderOpacityDefault, SIGNAL( clicked() ), this, SLOT( slot_SliderOpacityDefault() ) );
    connect( ui->toolButtonShowTimeDefault,      SIGNAL( clicked() ), this, SLOT( slot_SlidershowTimeDefault() ) );
}


void MainWindow::slot_toolButtonColorDefault()
{
    vkCircleWidget->setColor( Qt::red );
}


void MainWindow::slot_SliderCircleDefault()
{
    vkSpezialSliderCircle->setValue( 50 );
}


void MainWindow::slot_SliderOpacityDefault()
{
    vkSpezialSliderOpacity->setValue( 70 );
}


void MainWindow::slot_SlidershowTimeDefault()
{
    vkSpezialSliderShowtime->setValue( 10 );
}


void MainWindow::setMouseClick()
{
    vkGlobalMouse = new QvkGlobalMouse();
    connect( vkGlobalMouse, SIGNAL( signal_mousePressed( int, int, QString ) ), this, SLOT( slot_mousePressed( int, int, QString ) ) );
}

void MainWindow::slot_mousePressed( int x, int y, QString mouseButton )
{
    QvkAnimateWindow *animateWindow = new QvkAnimateWindow( this );
    animateWindow->init( x, y, vkSpezialSliderShowtime->value() * 100, mouseButton, vkSpezialSliderCircle->value(), vkSpezialSliderOpacity->value(), vkCircleWidget->getColor() );
    animateWindow->setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::ToolTip );
    animateWindow->show();
}


void MainWindow::setAbout()
{
    QPixmap pixmap( ":/pictures/showclick/cursorAbout.png" );
    pixmap = pixmap.scaled( 30 * devicePixelRatioF(), 30 * devicePixelRatioF() );
    QCursor cursor( pixmap );
    ui->toolButtonDonate->setCursor( cursor );
    ui->toolButtonHomepage->setCursor( cursor );
    ui->toolButtonSource->setCursor( cursor );
    ui->toolButtonLicense->setCursor( cursor );
    ui->toolButtonAuthor->setCursor( cursor );

    connect( ui->toolButtonDonate,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonDonate() ) );
    connect( ui->toolButtonHomepage, SIGNAL( clicked() ), this, SLOT( slot_toolButtonHomepage() ) );
    connect( ui->toolButtonSource,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonSource() ) );
    connect( ui->toolButtonAuthor,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonAuthor() ) );

    vkLicenses = new QvkLicenses();
    connect( ui->toolButtonLicense,  SIGNAL( clicked() ), vkLicenses, SLOT( show() ) );
}


void MainWindow::slot_toolButtonDonate()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-donate.html" ) );
}


void MainWindow::slot_toolButtonHomepage()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen.html" ) );
}


void MainWindow::slot_toolButtonSource()
{
    QDesktopServices::openUrl( QUrl( "https://github.com/vkohaupt/vokoShowClick" ) );
}


void MainWindow::slot_toolButtonAuthor()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-contact.html" ) );
}


void MainWindow::setCircleWidget()
{
    vkCircleWidget = new QvkCircleWidget( ui->frame_3 );
    vkCircleWidget->setObjectName( "widgetCircle" );
    vkCircleWidget->show();
    connect( vkSpezialSliderCircle, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChanged_SpezialSliderCircle( int ) ) );
    connect( vkSpezialSliderOpacity, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChanged_SpezialSliderOpacity( int ) ) );
}


void MainWindow::slot_valueChanged_SpezialSliderCircle( int value )
{
    vkCircleWidget->setDiameter( value );
}


void MainWindow::slot_valueChanged_SpezialSliderOpacity( int value )
{
    double value_1 = value;
    vkCircleWidget->setOpacity( value_1 / 100 );
}


void MainWindow::setHelp()
{
   vkHelp = new QvkHelp( this, ui );
   Q_UNUSED(vkHelp);
}

void MainWindow::setSettings()
{
    vkSettings = new QvkSettings;
    vkSettings->readAll( ui, this );
}

