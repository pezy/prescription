#include "mainwindow.h"
#include <QtGui/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("System"); //get system code
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	MainWindow w;
	w.resize(640, 480);
	w.show();
	return a.exec();
}
