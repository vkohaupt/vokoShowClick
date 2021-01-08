
#ifndef QVKSPEZIALCHECKBOX_H
#define QVKSPEZIALCHECKBOX_H

#include <QBasicTimer>
#include <QWidget>
#include <QCheckBox>
#include <QPainter>

class QvkSpezialCheckbox : public QCheckBox
{
    Q_OBJECT

public:
    QvkSpezialCheckbox(QWidget *parent = 0);

    
public slots:


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int step;
    int fontPixelSize;
    qreal button_x;
    qreal button_y;
    qreal button_width;
    qreal button_height;
    qreal penWidth;
    qreal radius;
    qreal margin;
    
    void paintChecked( QPainter &painter );
    void paintUnChecked( QPainter &painter );


signals:

    
};
#endif
