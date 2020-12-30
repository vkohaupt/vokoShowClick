/* vokoShowClick
 * Copyright (C) 2017-2021 Volker Kohaupt
 *
 * Author:
 *      Volker Kohaupt <vkohaupt@freenet.de>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * --End_License--
 */

#ifndef QvkShowClickController_H
#define QvkShowClickController_H

#include <QMainWindow>

#include "QvkShowClickDialog.h"
#include "QvkAnimateControl.h"

#include "ui_showclickDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QvkShowClickController : public QDialog
{
    Q_OBJECT

public:
    QvkShowClickController(QWidget *parent = nullptr);
    ~QvkShowClickController();


private slots:
    void slot_afterWindowShown();
    void slot_On();
    void slot_Off();


private:
    Ui::MainWindow *ui;
    QvkAnimateControl *animateControl;
    QvkShowClickDialog *ShowClickDialog;
    Ui::Dialog uiDialog;


protected:
    void showEvent( QShowEvent *event );
    void closeEvent(QCloseEvent *);


};
#endif // QvkShowClickController_H
