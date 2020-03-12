#include "QtGuiApplication4.h"
#include <string>
QtGuiApplication4::QtGuiApplication4(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void QtGuiApplication4::window_build2() {
	ui.label->deleteLater();
	ui.label_2->deleteLater();
	ui.label_3->deleteLater();
}
void QtGuiApplication4::click_confirm() {
	//std::string s = text_generate();
	ui.textBrowser->setText(QApplication::translate("QtGuiApplication4Class", "haha", nullptr));
}

void QtGuiApplication4::page_changed(int page) {
	switch (page) {
	case(0):
	case(1):
		ui.textBrowser->setText(QApplication::translate("QtGuiApplication4Class", "0/1", nullptr));
		break;
	case(2):
		ui.textBrowser->setText(QApplication::translate("QtGuiApplication4Class", "2", nullptr));
		this->window_build2();
		break;
	}
}