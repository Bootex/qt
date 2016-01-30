#include "notepad.h"

Notepad::Notepad()
{
	openAction = new QAction(tr("&Open"), this);
	saveAction = new QAction(tr("&Save"), this);
	quitAction = new QAction(tr("&Quit"), this);

	connect(openAction,SIGNAL(triggered()),this, SLOT(open()));
	connect(saveAction,SIGNAL(triggered()),this, SLOT(save()));
	connect(quitAction,SIGNAL(triggered()),qApp, SLOT(quit()));


	editBox = new QTextEdit;
	fileMenu = new QMenu;

	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAction);

	setCentralWidget(editBox);

	setWindowTitle(tr("Notepad"));

}

void Notepad::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Text Files (*.txt;;C== Files (*.cpp *h)"));

	if(fileName != ""){
		QFile file(fileName);
		if(!file.open(QIODevice::ReadOnly)){
			QMessageBox::critical(this,tr("Error"),tr("Could not open file."));
			return;
		}

		QTextStream in(&file);
		editBox->setText(file.readAll());
		file.close();

	}
}


void Notepad::save()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("Text Files (*.txt;;C== Files (*.cpp *h)"));

	if(fileName != ""){
		QFile file(fileName);
		if(!file.open(QIODevice::WriteOnly)){
			QMessageBox::critical(this,tr("Error"),tr("Could not save file."));
		}else{
			QTextStream stream(&file);
			stream << editBox->toPlainText();
			stream.flush();
			file.close();
		}
		
	}
}


void Notepad::quit(){
	QMessageBox messageBox;

	messageBox.setText(tr("Do you really want to quit?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);

	if(messageBox.exec() == QMessageBox::Yes)
		qApp->quit();

}