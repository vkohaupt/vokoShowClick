#include "QvkShowClickDialog.h"
#include "global.h"
#include "QvkLicenses.h"

#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QCursor>

QvkShowClickDialog::QvkShowClickDialog( QColor color, bool radiant, double opacity )
{
    //    vkSettings.readAll();
    
    uiDialog.setupUi( this );

    setIconForSideBar();

    setWindowTitle( global::name + " " + global::version );

#ifdef Q_OS_WIN
    QIcon icon( ":/pictures/showclick/windows.png" );
    uiDialog.toolButtonBS->setIcon( icon );
#endif

#ifdef Q_OS_LINUX
    QIcon icon( ":/pictures/showclick/linux.png" );
    uiDialog.toolButtonBS->setIcon( icon );
#endif

    QPixmap pixmap( ":/pictures/showclick/cursorAbout.png" );
    QCursor cursor( pixmap );
    uiDialog.toolButtonDonate->setCursor( cursor );
    uiDialog.toolButtonHomepage->setCursor( cursor );
    uiDialog.toolButtonSource->setCursor( cursor );
    uiDialog.toolButtonLicense->setCursor( cursor );
    uiDialog.toolButtonAuthor->setCursor( cursor );

    QvkLicenses *licenses = new QvkLicenses();

    connect( uiDialog.toolButtonDonate,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonDonate() ) );
    connect( uiDialog.toolButtonHomepage, SIGNAL( clicked() ), this, SLOT( slot_toolButtonHomepage() ) );
    connect( uiDialog.toolButtonSource,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonSource() ) );
    connect( uiDialog.toolButtonAuthor,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonAuthor() ) );
    connect( uiDialog.toolButtonLicense,  SIGNAL( clicked() ), licenses, SLOT( show() ) );

    uiDialog.frame_3->setStyleSheet("background-color:white;");
    uiDialog.frame_3->resize(100, 100);

    uiDialog.pushButton_white->setStyleSheet( "background-color: white;" );
    uiDialog.pushButton_black->setStyleSheet( "background-color: black;" );
    uiDialog.pushButton_red->setStyleSheet( "background-color: red;" );
    uiDialog.pushButton_darkRed->setStyleSheet( "background-color: darkRed;" );
    uiDialog.pushButton_green->setStyleSheet( "background-color: green;" );
    uiDialog.pushButton_darkGreen->setStyleSheet( "background-color: darkGreen;" );
    uiDialog.pushButton_blue->setStyleSheet( "background-color: blue;" );
    uiDialog.pushButton_darkBlue->setStyleSheet( "background-color: darkBlue;" );
    uiDialog.pushButton_cyan->setStyleSheet( "background-color: cyan;" );
    uiDialog.pushButton_darkCyan->setStyleSheet( "background-color: darkCyan;" );
    uiDialog.pushButton_magenta->setStyleSheet( "background-color: magenta;" );
    uiDialog.pushButton_darkMagenta->setStyleSheet( "background-color: darkMagenta;" );
    uiDialog.pushButton_yellow->setStyleSheet( "background-color: yellow;" );
    uiDialog.pushButton_darkYellow->setStyleSheet( "background-color: darkkhaki;" );
    uiDialog.pushButton_gray->setStyleSheet( "background-color: gray;" );
    uiDialog.pushButton_darkGray->setStyleSheet( "background-color: darkGray;" );
    
    connect( uiDialog.pushButton_white, SIGNAL( clicked() ), this, SLOT( slot_white() ) );
    connect( uiDialog.pushButton_black, SIGNAL( clicked() ), this, SLOT( slot_black() ) );
    connect( uiDialog.pushButton_red, SIGNAL( clicked() ), this, SLOT( slot_red() ) );
    connect( uiDialog.pushButton_darkRed, SIGNAL( clicked() ), this, SLOT( slot_darkRed() ) );
    connect( uiDialog.pushButton_green, SIGNAL( clicked() ), this, SLOT( slot_green() ) );
    connect( uiDialog.pushButton_darkGreen, SIGNAL( clicked() ), this, SLOT( slot_darkGreen() ) );
    connect( uiDialog.pushButton_blue, SIGNAL( clicked() ), this, SLOT( slot_blue() ) );
    connect( uiDialog.pushButton_darkBlue, SIGNAL( clicked() ), this, SLOT( slot_darkBlue() ) );
    connect( uiDialog.pushButton_cyan, SIGNAL( clicked() ), this, SLOT( slot_cyan() ) );
    connect( uiDialog.pushButton_darkCyan, SIGNAL( clicked() ), this, SLOT( slot_darkCyan() ) );
    connect( uiDialog.pushButton_magenta, SIGNAL( clicked() ), this, SLOT( slot_magenta() ) );
    connect( uiDialog.pushButton_darkMagenta, SIGNAL( clicked() ), this, SLOT( slot_darkMagenta() ) );
    connect( uiDialog.pushButton_yellow, SIGNAL( clicked() ), this, SLOT( slot_yellow() ) );
    connect( uiDialog.pushButton_darkYellow, SIGNAL( clicked() ), this, SLOT( slot_darkYellow() ) );
    connect( uiDialog.pushButton_gray, SIGNAL( clicked() ), this, SLOT( slot_gray() ) );
    connect( uiDialog.pushButton_darkGray, SIGNAL( clicked() ), this, SLOT( slot_darkGray() ) );

    connect( uiDialog.toolButtonColorDefault, SIGNAL( clicked() ), this, SLOT( slot_toolButtonColorDefault() ) );
    connect( uiDialog.toolButtonSliderCircleDefault, SIGNAL( clicked() ), this, SLOT( slot_SliderCircleDefault() ) );
    connect( uiDialog.toolButtonSliderOpacityDefault, SIGNAL( clicked() ), this, SLOT(slot_SliderOpacityDefault() ) );
    connect( uiDialog.toolButtonShowTimeDefault, SIGNAL( clicked() ), this, SLOT(slot_SlidershowTimeDefault() ) );
    connect( uiDialog.toolButtonRadiantDefault, SIGNAL( clicked() ), this, SLOT( slot_checkBoxRadiantDefault() ) );
    
    circleWidget = new QvkCircleWidget( uiDialog.frame_3   );
    circleWidget->show();
    slot_valueChangedSliderCircle( uiDialog.horizontalSliderCircle->value() );
    circleWidget->setColor( color );
    circleWidget->setRadiant( radiant );
    circleWidget->setOpacity( opacity );
    
    connect( uiDialog.horizontalSliderCircle, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChangedSliderCircle( int ) ) );
    
    connect( uiDialog.checkBoxRadiant, SIGNAL( stateChanged( int ) ), this, SLOT( slot_stateChangedRadiant( int ) ) );
    if ( radiant == true )
        uiDialog.checkBoxRadiant->setCheckState( Qt::Checked );
    else
        uiDialog.checkBoxRadiant->setCheckState( Qt::Unchecked );

    connect( uiDialog.horizontalSliderOpacity, SIGNAL( valueChanged( int ) ), this, SLOT( slot_valueChangedOpacity( int ) ) );
    uiDialog.horizontalSliderOpacity->setSliderPosition( opacity*100 );
    
    connect( uiDialog.horizontalSliderShowtime, SIGNAL( valueChanged( int ) ), this, SLOT( ok() ) );
}

QvkShowClickDialog::~QvkShowClickDialog()
{
}

void QvkShowClickDialog::closeEvent( QCloseEvent *event )
{
    Q_UNUSED(event);
    emit signal_close();
}

void QvkShowClickDialog::setIconForSideBar()
{
    for ( int x = 0; x < uiDialog.tabWidget->count(); x++ )
    {
        QIcon icon = uiDialog.tabWidget->tabIcon( x );
        QPixmap workPixmap = icon.pixmap( uiDialog.tabWidget->iconSize() );
        QTransform transform;
        transform.rotate( 90 );
        workPixmap = workPixmap.transformed( transform, Qt::SmoothTransformation );
        uiDialog.tabWidget->setTabIcon( x, workPixmap );
    }
}

void QvkShowClickDialog::slot_toolButtonDonate()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-donate.html" ) );
}

void QvkShowClickDialog::slot_toolButtonHomepage()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen.html" ) );
}

void QvkShowClickDialog::slot_toolButtonSource()
{
    QDesktopServices::openUrl( QUrl( "https://github.com/vkohaupt/vokoShowClick" ) );
}

void QvkShowClickDialog::slot_toolButtonAuthor()
{
    QDesktopServices::openUrl( QUrl( "https://linuxecke.volkoh.de/vokoscreen/vokoscreen-contact.html" ) );
}

QColor QvkShowClickDialog::getColor()
{
    return circleWidget->getColor();
}

void QvkShowClickDialog::slot_toolButtonColorDefault()
{
    uiDialog.pushButton_red->click();
}

void QvkShowClickDialog::slot_SliderCircleDefault()
{
    uiDialog.horizontalSliderCircle->setValue( 50 );
}

void QvkShowClickDialog::slot_SliderOpacityDefault()
{
    uiDialog.horizontalSliderOpacity->setValue( 50 );
}

void QvkShowClickDialog::slot_SlidershowTimeDefault()
{
    uiDialog.horizontalSliderShowtime->setValue( 5 );
}

void QvkShowClickDialog::slot_checkBoxRadiantDefault()
{
    uiDialog.checkBoxRadiant->setCheckState( Qt::Unchecked );
}


void QvkShowClickDialog::ok()
{
    emit newCircleWidgetValue( circleWidget->getDiameter(), circleWidget->getColor() );
    emit newShowtime( (double) uiDialog.horizontalSliderShowtime->value()/10 );
    emit newOpacity( circleWidget->getOpacity() );
    emit newRadiant( circleWidget->getRadiant() );
}

void QvkShowClickDialog::slot_valueChangedSliderCircle( int value )
{
    circleWidget->setDiameter( value );
    ok();
}

void QvkShowClickDialog::slot_valueChangedOpacity( int value )
{
    double value_1 = value;
    circleWidget->setOpacity( value_1 / 100 );
    ok();
}

void QvkShowClickDialog::slot_stateChangedRadiant( int value )
{
    if ( value == Qt::Unchecked )
    {
        circleWidget->setRadiant( false );
        ok();
    }
    else
    {
        circleWidget->setRadiant( true );
        ok();
    }
}

void QvkShowClickDialog::slot_white()
{
    circleWidget->setColor( Qt::white );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_black()
{
    circleWidget->setColor( Qt::black );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_red()
{
    circleWidget->setColor( Qt::red );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkRed()
{
    circleWidget->setColor( Qt::darkRed );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_green()
{
    circleWidget->setColor( Qt::green );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkGreen()
{
    circleWidget->setColor( Qt::darkGreen );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_blue()
{
    circleWidget->setColor( Qt::blue );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkBlue()
{
    circleWidget->setColor( Qt::darkBlue );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_cyan()
{
    circleWidget->setColor( Qt::cyan );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkCyan()
{
    circleWidget->setColor( Qt::darkCyan );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_magenta()
{
    circleWidget->setColor( Qt::magenta );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkMagenta()
{
    circleWidget->setColor( Qt::darkMagenta );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_yellow()
{
    circleWidget->setColor( Qt::yellow );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkYellow()
{
    circleWidget->setColor( Qt::darkYellow );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_gray()
{
    circleWidget->setColor( Qt::gray );
    uiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::slot_darkGray()
{
    circleWidget->setColor( Qt::darkGray );
    uiDialog.frame_3->setFocus();
    ok();
}


// This is need, so that we can
void QvkShowClickDialog::showEvent( QShowEvent *event )
{
    Q_UNUSED(event);
    // Call slot "afterWindowShown" after the window has been shown
    QMetaObject::invokeMethod( this, "slot_afterWindowShown", Qt::ConnectionType::QueuedConnection );
}

void QvkShowClickDialog::slot_afterWindowShown()
{
    // In the program vokoShowClick, the checkBox is hide and showclick started from the beginning.
    uiDialog.checkBoxPointerOnOff->click();
}
