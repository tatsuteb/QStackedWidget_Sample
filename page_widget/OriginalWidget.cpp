#include "OriginalWidget.h"
#include "ui_OriginalWidget.h"

OriginalWidget::OriginalWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::OriginalWidget)
{
	ui->setupUi(this);
}

OriginalWidget::~OriginalWidget()
{
	delete ui;
}

void OriginalWidget::setWidgetText(const QString &str)
{
	ui->label->setText(str);
}
