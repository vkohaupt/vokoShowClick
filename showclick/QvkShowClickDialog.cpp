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
    
    myUiDialog.setupUi( this );

    setIconForSideBar();

    setWindowTitle( global::name + " " + global::version );
    vk_setCornerWidget( myUiDialog.tabWidget);

    QPixmap pixmap( ":/pictures/showclick/cursorAbout.png" );
    QCursor cursor( pixmap );
    myUiDialog.toolButtonDonate->setCursor( cursor );
    myUiDialog.toolButtonHomepage->setCursor( cursor );
    myUiDialog.toolButtonSource->setCursor( cursor );
    myUiDialog.pushButtonLicense->setCursor( cursor );
    myUiDialog.toolButtonAuthor->setCursor( cursor );

    QvkLicenses *licenses = new QvkLicenses();

    connect( myUiDialog.toolButtonDonate,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonDonate() ) );
    connect( myUiDialog.toolButtonHomepage, SIGNAL( clicked() ), this, SLOT( slot_toolButtonHomepage() ) );
    connect( myUiDialog.toolButtonSource,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonSource() ) );
    connect( myUiDialog.toolButtonAuthor,   SIGNAL( clicked() ), this, SLOT( slot_toolButtonAuthor() ) );
    connect( myUiDialog.pushButtonLicense,  SIGNAL( clicked() ), licenses, SLOT( show() ) );

    myUiDialog.frame_3->setStyleSheet("background-color:white;");
    myUiDialog.frame_3->resize(100, 100);

    myUiDialog.pushButton_white->setStyleSheet( "background-color: white;" );
    myUiDialog.pushButton_black->setStyleSheet( "background-color: black;" );
    myUiDialog.pushButton_red->setStyleSheet( "background-color: red;" );
    myUiDialog.pushButton_darkRed->setStyleSheet( "background-color: darkRed;" );
    myUiDialog.pushButton_green->setStyleSheet( "background-color: green;" );
    myUiDialog.pushButton_darkGreen->setStyleSheet( "background-color: darkGreen;" );
    myUiDialog.pushButton_blue->setStyleSheet( "background-color: blue;" );
    myUiDialog.pushButton_darkBlue->setStyleSheet( "background-color: darkBlue;" );
    myUiDialog.pushButton_cyan->setStyleSheet( "background-color: cyan;" );
    myUiDialog.pushButton_darkCyan->setStyleSheet( "background-color: darkCyan;" );
    myUiDialog.pushButton_magenta->setStyleSheet( "background-color: magenta;" );
    myUiDialog.pushButton_darkMagenta->setStyleSheet( "background-color: darkMagenta;" );
    myUiDialog.pushButton_yellow->setStyleSheet( "background-color: yellow;" );
    myUiDialog.pushButton_darkYellow->setStyleSheet( "background-color: darkkhaki;" );
    myUiDialog.pushButton_gray->setStyleSheet( "background-color: gray;" );
    myUiDialog.pushButton_darkGray->setStyleSheet( "background-color: darkGray;" );
    
    connect( myUiDialog.pushButton_white, SIGNAL( clicked() ), this, SLOT( white() ) );
    connect( myUiDialog.pushButton_black, SIGNAL( clicked() ), this, SLOT( black() ) );
    connect( myUiDialog.pushButton_red, SIGNAL( clicked() ), this, SLOT( red() ) );
    connect( myUiDialog.pushButton_darkRed, SIGNAL( clicked() ), this, SLOT( darkRed() ) );
    connect( myUiDialog.pushButton_green, SIGNAL( clicked() ), this, SLOT( green() ) );
    connect( myUiDialog.pushButton_darkGreen, SIGNAL( clicked() ), this, SLOT( darkGreen() ) );
    connect( myUiDialog.pushButton_blue, SIGNAL( clicked() ), this, SLOT( blue() ) );
    connect( myUiDialog.pushButton_darkBlue, SIGNAL( clicked() ), this, SLOT( darkBlue() ) );
    connect( myUiDialog.pushButton_cyan, SIGNAL( clicked() ), this, SLOT( cyan() ) );
    connect( myUiDialog.pushButton_darkCyan, SIGNAL( clicked() ), this, SLOT( darkCyan() ) );
    connect( myUiDialog.pushButton_magenta, SIGNAL( clicked() ), this, SLOT( magenta() ) );
    connect( myUiDialog.pushButton_darkMagenta, SIGNAL( clicked() ), this, SLOT( darkMagenta() ) );
    connect( myUiDialog.pushButton_yellow, SIGNAL( clicked() ), this, SLOT( yellow() ) );
    connect( myUiDialog.pushButton_darkYellow, SIGNAL( clicked() ), this, SLOT( darkYellow() ) );
    connect( myUiDialog.pushButton_gray, SIGNAL( clicked() ), this, SLOT( gray() ) );
    connect( myUiDialog.pushButton_darkGray, SIGNAL( clicked() ), this, SLOT( darkGray() ) );
    
//    connect( myUiDialog.buttonBox, SIGNAL( accepted() ), this, SLOT( ok() ) );
//    connect( myUiDialog.buttonBox, SIGNAL( rejected() ), this, SLOT( cancel() ) );
//    connect( myUiDialog.buttonBox->button( QDialogButtonBox::RestoreDefaults ), SIGNAL( clicked() ), this, SLOT( Standard() ) );
    
    circleWidget = new QvkCircleWidget( myUiDialog.frame_3   );
    circleWidget->show();
    valueChangedSliderCircle( myUiDialog.horizontalSliderCircle->value() );
    circleWidget->setColor( color );
    circleWidget->setRadiant( radiant );
    circleWidget->setOpacity( opacity );
    
    connect( myUiDialog.horizontalSliderCircle, SIGNAL( valueChanged( int ) ), this, SLOT( valueChangedSliderCircle( int ) ) );
    
    connect( myUiDialog.checkBoxRadiant, SIGNAL( stateChanged( int ) ), this, SLOT( stateChangedRadiant( int ) ) );
    if ( radiant == true )
        myUiDialog.checkBoxRadiant->setCheckState( Qt::Checked );
    else
        myUiDialog.checkBoxRadiant->setCheckState( Qt::Unchecked );

    connect( myUiDialog.horizontalSliderOpacity, SIGNAL( valueChanged( int ) ), this, SLOT( valueChangedOpacity( int ) ) );
    myUiDialog.horizontalSliderOpacity->setSliderPosition( opacity*100 );
    
    connect( myUiDialog.horizontalSliderShowtime, SIGNAL( valueChanged( int ) ), this, SLOT( ok() ) );
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
    QStringList stringListIcon;
    stringListIcon.append( ":/pictures/showclick/applications-graphics.png" );
    stringListIcon.append( ":/pictures/showclick/help-about.png" );

    for( int x = 0; x < stringListIcon.count(); x++ )
    {
        QPixmap workPixmap( stringListIcon.at( x ) );

        QTransform transform;
        transform.rotate( 90 );
        workPixmap = workPixmap.transformed( transform, Qt::SmoothTransformation );

        myUiDialog.tabWidget->setTabIcon( x, workPixmap );
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

void QvkShowClickDialog::Standard()
{
    myUiDialog.horizontalSliderShowtime->setValue( 5 );
    myUiDialog.pushButton_red->click();
    myUiDialog.horizontalSliderCircle->setValue( 50 );
    myUiDialog.horizontalSliderOpacity->setValue( 50 );
    myUiDialog.checkBoxRadiant->setCheckState( Qt::Unchecked );
}

void QvkShowClickDialog::ok()
{
    emit newCircleWidgetValue( circleWidget->getDiameter(), circleWidget->getColor() );
    emit newShowtime( (double) myUiDialog.horizontalSliderShowtime->value()/10 );
    emit newOpacity( circleWidget->getOpacity() );
    emit newRadiant( circleWidget->getRadiant() );
}

void QvkShowClickDialog::valueChangedSliderCircle( int value )
{
    circleWidget->setDiameter( value );
    ok();
}

void QvkShowClickDialog::valueChangedOpacity( int value )
{
    double value_1 = value;
    circleWidget->setOpacity( value_1 / 100 );
    ok();
}

void QvkShowClickDialog::stateChangedRadiant( int value )
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

void QvkShowClickDialog::white()
{
    circleWidget->setColor( Qt::white );
    myUiDialog.frame_3->setFocus();

    ok();
}

void QvkShowClickDialog::black()
{
    circleWidget->setColor( Qt::black );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::red()
{
    circleWidget->setColor( Qt::red );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkRed()
{
    circleWidget->setColor( Qt::darkRed );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::green()
{
    circleWidget->setColor( Qt::green );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkGreen()
{
    circleWidget->setColor( Qt::darkGreen );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::blue()
{
    circleWidget->setColor( Qt::blue );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkBlue()
{
    circleWidget->setColor( Qt::darkBlue );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::cyan()
{
    circleWidget->setColor( Qt::cyan );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkCyan()
{
    circleWidget->setColor( Qt::darkCyan );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::magenta()
{
    circleWidget->setColor( Qt::magenta );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkMagenta()
{
    circleWidget->setColor( Qt::darkMagenta );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::yellow()
{
    circleWidget->setColor( Qt::yellow );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkYellow()
{
    circleWidget->setColor( Qt::darkYellow );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::gray()
{
    circleWidget->setColor( Qt::gray );
    myUiDialog.frame_3->setFocus();
    ok();
}

void QvkShowClickDialog::darkGray()
{
    circleWidget->setColor( Qt::darkGray );
    myUiDialog.frame_3->setFocus();
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
    myUiDialog.checkBoxPointerOnOff->click();
}

void QvkShowClickDialog::vk_setCornerWidget( QTabWidget *tabWidget )
{
#ifdef Q_OS_LINUX
    QPixmap pixmap( ":/pictures/showclick/linux.png" );
#endif
#ifdef Q_OS_WIN
    QPixmap pixmap( ":/pictures/showclick/windows.png" );
#endif
    pixmap = pixmap.scaled( QSize( 48, 48 ), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    QLabel *label = new QLabel();
    label->setPixmap( pixmap );
    label->setEnabled( false );
//    tabWidget->setCornerWidget( label, Qt::TopRightCorner );
    tabWidget->setCornerWidget( label, Qt::BottomRightCorner );
}
