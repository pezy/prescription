//
//  main.cpp
//  e-Prescription
//
//  Created by pezy on 1/7/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}
