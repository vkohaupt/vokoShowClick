#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QvkSpezialSlider.h>
#include "QvkLicenses.h"
#include "QvkGlobalMouse.h"
#include "QvkSpezialCheckbox.h"
#include "QvkAnimateWindow.h"
#include "QvkCircleWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QvkSpezialSlider *vkSpezialSliderCircle;
    QvkSpezialSlider *vkSpezialSliderOpacity;
    QvkSpezialSlider *vkSpezialSliderShowtime;
    QvkLicenses *vkLicenses;
    QvkGlobalMouse *vkGlobalMouse;
    QvkSpezialCheckbox *vkSpezialCheckbox;
    QvkCircleWidget *vkCircleWidget;

    void setIconSideBar();
    void setPictureOperatingSystem();
    void setColorButtons();
    void setSpezialSlider();
    void setSpezialCheckBox();
    void setToolButtonDefaultValues();
    void setMouseClick();
    void setAbout();
    void setCircleWidget();
    void setHelp();


private slots:
    void slot_vkPushButton_white();
    void slot_vkPushButton_black();
    void slot_vkPushButton_red();
    void slot_vkPushButton_darkRed();
    void slot_vkPushButton_green();
    void slot_vkPushButton_darkGreen();
    void slot_vkPushButton_blue();
    void slot_vkPushButton_darkBlue();
    void slot_vkPushButton_cyan();
    void slot_vkPushButton_darkCyan();
    void slot_vkPushButton_magenta();
    void slot_vkPushButton_darkMagenta();
    void slot_vkPushButton_yellow();
    void slot_vkPushButton_darkYellow();
    void slot_vkPushButton_gray();
    void slot_vkPushButton_darkGray();

    void slot_toolButtonColorDefault();
    void slot_SliderCircleDefault();
    void slot_SliderOpacityDefault();
    void slot_SlidershowTimeDefault();
    void slot_toolButtonDonate();
    void slot_toolButtonHomepage();
    void slot_toolButtonSource();
    void slot_toolButtonAuthor();
    void slot_mousePressed( int, int, QString );
    void slot_pointerOnOff( bool value );
    void slot_valueChanged_SpezialSliderCircle( int value );
    void slot_valueChanged_SpezialSliderOpacity( int value );


protected:
    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
