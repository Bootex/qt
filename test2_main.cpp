#include <QtGui>
#include "notepad.h"


Notepad::Notepad()
{
	textEdit =new QTextEdit;
	exitButton = new QPushButton(tr("Quit"));

	connect( exitButton, SIGNAL(clicked()), this, SLOT(quit()));

	QVBoxLayout *layout;
    layout = new QVBoxLayout;

	layout->addWidget(textEdit);
	layout->addWidget(exitButton);

	setLayout(layout);

	show();
}

void Notepad::quit()
{
	QMessageBox messagebox;
	messagebox.setText("Do you real want to quit");
	messagebox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messagebox.setDefaultButton(QMessageBox::No);
	if (messagebox.exec() == QMessageBox::Yes)
		qApp->quit();

}


int main(int argc,char **argv)
{
	QApplication myNotepad(argc, argv);

	Notepad mynote;

	return myNotepad.exec();
}
