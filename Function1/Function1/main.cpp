#include "window2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	window2 w;
	w.show();
	return a.exec();
}
