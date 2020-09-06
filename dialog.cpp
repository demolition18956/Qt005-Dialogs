
#include "echodialog.h"
#include <QDialog>
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	QDialog* dptr = new EchoDialog();
	dptr->show();
	return app.exec();
}
