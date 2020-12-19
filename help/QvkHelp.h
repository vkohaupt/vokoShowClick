/* vokoscreenNG - A desktop recorder
 * Copyright (C) 2017-2019 Volker Kohaupt
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

#ifndef QVKHELP_H
#define QVKHELP_H

#include "ui_showclickDialog.h"
#include "ui_help.h"
#include "QvkDownloader.h"

#include <QObject>
#include <QTemporaryDir>

#include <QMouseEvent>
#include <QEvent>

#include <QMainWindow>

class QvkHelp: public QWidget
{
    Q_OBJECT
    
public:
    QvkHelp(QMainWindow *mainWindow, Ui_Dialog *ui_mainwindow);
    virtual ~QvkHelp() override;
    

public slots:

  
private:
    Ui_Dialog *ui;
    Ui_help *uiHelp;

    QStringList toDownloadFiles = { ".png", ".svg", ".css", ".jpg" };
    bool isFileInLine( QString line );

    QvkDownloader *vkDownloadHTML;
    QvkDownloader *vkDownloadFiles;

    void loadHTML( QString value );
    QString remotePath;
    QString remoteBasename;
    int getCountFileToDownload( QString tempPathFileName );
    QStringList localFiles;
    QString tempPath;
    QString vk_helpPath;

    QTemporaryDir temporaryDirLocal;
    QNetworkAccessManager networkAccessManager;


private slots:
    void slot_parseHTML( QString tempPathFileName );
    void slot_showHelp( QString tempPathFileName );

    void slot_cleanUp();
    void slot_NetworkAccessibility( QNetworkAccessManager::NetworkAccessibility accessible );

    void slot_parse_locale( QStringList list );


protected:
    bool eventFilter(QObject *object, QEvent *ev) override;


signals:

    
};

#endif
