#ifndef EPRESCRIPTION_H
#define EPRESCRIPTION_H

#include <QtWidgets/QMainWindow>
#include "ui_eprescription.h"

class QTabWidget;

class ePrescription : public QMainWindow
{
	Q_OBJECT

public:
	ePrescription(QWidget *parent = 0);
	~ePrescription() {}

	void Init();
	void InitData();

public slots:
	void PrintFile();

private:
	Ui::ePrescriptionClass ui;
	QTabWidget *m_pTabPrescription;
};

#endif // EPRESCRIPTION_H
