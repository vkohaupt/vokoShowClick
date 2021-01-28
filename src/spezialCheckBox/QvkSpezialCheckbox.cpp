
#include <QtWidgets>

#include "QvkSpezialCheckbox.h"

QvkSpezialCheckbox::QvkSpezialCheckbox( QWidget *parent ) : QCheckBox( parent )
{
    setBackgroundRole( QPalette::Midlight );
    setAutoFillBackground( true );

    setObjectName( "spezialCheckBox" );
    setText( "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" );
    setMinimumWidth( 100 );
    setMinimumHeight( 35 );
    setMaximumWidth( 100 );
}

void QvkSpezialCheckbox::paintEvent( QPaintEvent *event )
{
    Q_UNUSED( event );
    QPainter painter( this );
    painter.setRenderHints( QPainter::Antialiasing, true );

    button_x = 2;
    button_y = 2;
    button_width = width() - 2 * button_x;
    button_height = height() - 2 * button_y;
    penWidth = 1;
    radius = 11;
    margin = 3;
    fontPixelSize = 14;

    if ( isChecked() == false )
    {
        paintUnChecked( painter );
    }

    if ( isChecked() == true )
    {
        paintChecked( painter );
    }
}

void QvkSpezialCheckbox::paintChecked( QPainter &painter )
{
    QPen pen;
    pen.setColor( Qt::black );
    pen.setWidthF( penWidth );
    painter.setPen( pen );
    QBrush brushButton( Qt::darkGreen );
    painter.setBrush( brushButton );
    QRectF rectButton( button_x, button_y, button_width, button_height );
    painter.setBrush( brushButton );
    QPainterPath painterPathButton;
    painterPathButton.addRoundedRect( rectButton, radius, radius, Qt::AbsoluteSize );
    painter.drawPath( painterPathButton );

    QPen penSlider;
    penSlider.setColor( Qt::black );
    painter.setPen( penSlider );
    qreal slider_x = ( button_width / 3 ) + margin;
    qreal slider_y = button_y + margin;
    qreal slider_width = ( button_width / 3 * 2 ) - ( 2 * margin ) + button_x;
    qreal slider_height = button_height - ( 2 * margin );
    QRectF rectSlider( slider_x, slider_y, slider_width, slider_height );
    QBrush brushSlider( Qt::lightGray );
    painter.setBrush( brushSlider );
    QPainterPath painterPathSlider;
    painterPathSlider.addRoundedRect( rectSlider, radius - margin, radius - margin, Qt::AbsoluteSize );
    painter.drawPath( painterPathSlider );

    QPixmap pixmap( ":/spezialCheckBox/on.png" );
    pixmap.setDevicePixelRatio( devicePixelRatioF() );
    pixmap = pixmap.scaled( slider_height / 5 * 3 * devicePixelRatioF(), slider_height / 5 * 3 * devicePixelRatioF(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    painter.drawPixmap( button_x + margin + ( ( slider_x - button_x - margin ) / 2 ) - ( pixmap.width() / 2 / devicePixelRatioF() ),
                        button_y + margin + ( slider_height / 5 ),
                        pixmap );
}


void QvkSpezialCheckbox::paintUnChecked( QPainter &painter )
{
    QPen pen;
    pen.setWidthF( penWidth );
    pen.setColor( Qt::black );
    painter.setPen( pen );
    QBrush brushButton( Qt::red );
    painter.setBrush( brushButton );
    QRectF rectButton( button_x, button_y, button_width, button_height );
    painter.setBrush( brushButton );
    QPainterPath painterPathButton;
    painterPathButton.addRoundedRect( rectButton, radius, radius, Qt::AbsoluteSize );
    painter.drawPath( painterPathButton );

    QPen penSlider;
    penSlider.setColor( Qt::black );
    painter.setPen( penSlider );
    qreal slider_x = button_x + margin;
    qreal slider_y = button_y + margin;
    qreal slider_width = ( button_width / 3 * 2 )  - ( 2 * margin );
    qreal slider_height = button_height - ( 2 * margin );
    QRectF rectSlider( slider_x, slider_y, slider_width, slider_height );
    QBrush brushSlider( Qt::lightGray );
    painter.setBrush( brushSlider );
    QPainterPath painterPathSlider;
    painterPathSlider.addRoundedRect( rectSlider, radius - margin, radius - margin, Qt::AbsoluteSize );
    painter.drawPath( painterPathSlider );

    QPixmap pixmap( ":/spezialCheckBox/off.png" );
    pixmap.setDevicePixelRatio(  devicePixelRatioF() );
    pixmap = pixmap.scaled( slider_height / 5 * 3 * devicePixelRatioF(),
                            slider_height / 5 * 3 * devicePixelRatioF(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    painter.drawPixmap( slider_x+slider_width + ( button_width - slider_x - slider_width) / 2 - pixmap.width() / 2 / devicePixelRatioF(),
                        button_y + margin + ( slider_height / 5 ),
                        pixmap );
}
