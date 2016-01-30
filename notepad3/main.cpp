#include <QtGui>
#include "notepad.h"

int main(int argc,char **argv)
{
	QApplication app(argc,argv);
	Notepad *myNote = new Notepad;

	myNote->show();

	return app.exec();
}