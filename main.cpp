#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QtGui/QApplication>
#include "QTextCodec"


int main(int argc, char *argv[])
{
		//解决中文乱码
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

	QApplication a(argc, argv);
	MainWindow w;
	w.showMaximized();
// 	w.show();
	return a.exec();
}
