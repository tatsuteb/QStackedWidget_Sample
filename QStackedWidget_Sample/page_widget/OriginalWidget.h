#ifndef ORIGINALWIDGET_H
#define ORIGINALWIDGET_H

#include <QWidget>

namespace Ui {
	class OriginalWidget;
}

class OriginalWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit OriginalWidget(QWidget *parent = 0);
		~OriginalWidget();

		void setWidgetText(const QString &str);

	private:
		Ui::OriginalWidget *ui;
};

#endif // ORIGINALWIDGET_H
