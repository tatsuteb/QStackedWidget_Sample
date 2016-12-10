#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
		Q_OBJECT

	public:
		explicit Dialog(QWidget *parent = 0);
		~Dialog();

	private slots:
		void on_pushButton_prev_clicked();
		void on_pushButton_next_clicked();
		void on_pushButton_addPage_clicked();
		void on_pushButton_insertPage_clicked();
		void on_pushButton_removePage_clicked();

	private:
		Ui::Dialog *ui;

		void updateState();
};


#endif // DIALOG_H
