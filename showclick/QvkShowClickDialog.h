#ifndef QvkShowClickDialog_H
#define QvkShowClickDialog_H

#include "ui_showclickDialog.h"
#include "QvkCircleWidget.h"

//#include "QvkSettings.h"

#include <QDialog>

class QvkShowClickDialog: public QDialog

{
    Q_OBJECT
public:    
    QvkShowClickDialog( QColor color, bool radiant, double opacity );
    virtual ~QvkShowClickDialog();
    Ui_Dialog myUiDialog;


public slots:

    
private:
    QvkCircleWidget *circleWidget;
    //    QvkSettings vkSettings;

    
private slots:
    QColor getColor();
    void ok();
    void valueChangedSliderCircle( int value );
    void valueChangedOpacity( int value );
    void stateChangedRadiant( int );
    void Standard();
    void black();
    void white();
    void red();
    void darkRed();
    void green();
    void darkGreen();
    void blue();
    void darkBlue();
    void cyan();
    void darkCyan();
    void magenta();
    void darkMagenta();
    void yellow();
    void darkYellow();
    void gray();
    void darkGray();


signals:
    void newCircleWidgetValue( int, QColor );
    void newShowtime( double value );
    void newOpacity( double value );
    void newRadiant( bool value);

    void signal_close();
    
protected:
    void closeEvent( QCloseEvent *event );

};

#endif // QvkShowClickDialog_H
