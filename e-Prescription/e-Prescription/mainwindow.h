#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"

class QTabWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow() {}

	void Init();
	void InitData();

private:
	Ui::MainWindowClass ui;
	QTabWidget *m_tabPrescription;
};

#endif // MAINWINDOW_H
