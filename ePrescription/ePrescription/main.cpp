#include "eprescription.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ePrescription w;
	w.resize(640, 480);
	w.show();
	return a.exec();
}
