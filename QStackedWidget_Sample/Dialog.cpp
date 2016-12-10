#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	ui->stackedWidget->setCurrentIndex(0);

	updateState();
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::on_pushButton_prev_clicked()
{
	auto idx = ui->stackedWidget->currentIndex();
	ui->stackedWidget->setCurrentIndex(--idx);

	updateState();
}

void Dialog::on_pushButton_next_clicked()
{
	auto idx = ui->stackedWidget->currentIndex();
	ui->stackedWidget->setCurrentIndex(++idx);

	updateState();
}

void Dialog::on_pushButton_addPage_clicked()
{
	OriginalWidget *widget = new OriginalWidget();

	auto idx = ui->stackedWidget->addWidget(widget);
	ui->stackedWidget->setCurrentIndex(idx);

	// Set text on the new widget.
	QString str(tr("Added Widget."));
	if (!ui->textEdit_pageText->toPlainText().isEmpty())
	{
		str = ui->textEdit_pageText->toPlainText();
	}
	widget->setWidgetText(str);

	updateState();
}

void Dialog::on_pushButton_insertPage_clicked()
{
	OriginalWidget *widget = new OriginalWidget();

	auto currIdx = ui->stackedWidget->currentIndex();
	auto idx = ui->stackedWidget->insertWidget(currIdx, widget);
	ui->stackedWidget->setCurrentIndex(idx);

	// Set text on the new widget.
	QString str(tr("Inserted Widget."));
	if (!ui->textEdit_pageText->toPlainText().isEmpty())
	{
		str = ui->textEdit_pageText->toPlainText();
	}
	widget->setWidgetText(str);

	updateState();
}

void Dialog::on_pushButton_removePage_clicked()
{
	auto widget = ui->stackedWidget->currentWidget();
	ui->stackedWidget->removeWidget(widget);

	updateState();
}

void Dialog::updateState()
{
	auto idx = ui->stackedWidget->currentIndex();
	auto cnt = ui->stackedWidget->count();

	// Update page indicator text.
	QString str(tr("%1/%2").arg(idx+1).arg(cnt));
	ui->label_pageIndicator->setText(str);

	// Update buttons depending on the page count.
	auto hasPage = cnt > 0;
	if (!hasPage)
	{
		ui->pushButton_removePage->setEnabled(false);
		ui->pushButton_next->setEnabled(false);
		ui->pushButton_prev->setEnabled(false);

		return;
	}

	ui->pushButton_removePage->setEnabled(true);


	// Update buttons depending on the current page index.
	auto isLastPage = idx == cnt-1;
	auto isFirstPage = idx == 0;

	if (isLastPage && isFirstPage)
	{
		ui->pushButton_next->setEnabled(false);
		ui->pushButton_prev->setEnabled(false);
		return;
	}

	if (isLastPage)
	{
		ui->pushButton_next->setEnabled(false);
		ui->pushButton_prev->setEnabled(true);
		return;
	}

	if (isFirstPage)
	{
		ui->pushButton_next->setEnabled(true);
		ui->pushButton_prev->setEnabled(false);
		return;
	}

	ui->pushButton_next->setEnabled(true);
	ui->pushButton_prev->setEnabled(true);
}



