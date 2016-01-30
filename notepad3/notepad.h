#include <QtGui>

class Notepad : public QMainWindow
{
	Q_OBJECT

	public:
			Notepad();
	private slots:
			void open();
			void save();
			void quit();
	private:
			QTextEdit *editBox;
			QMenu *fileMenu;
			QAction *openAction;
			QAction *saveAction;
			QAction *quitAction;
};