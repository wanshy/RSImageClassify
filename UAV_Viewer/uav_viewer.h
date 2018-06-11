#ifndef UAV_VIEWER_H
#define UAV_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_uav_viewer.h"
#include <QFileInfo>
class UAV_Viewer : public QMainWindow
{
	Q_OBJECT

public:
	UAV_Viewer(QWidget *parent = 0);
	~UAV_Viewer();

	QFileInfoList allfile(QTreeWidgetItem *root, QString path);

public slots:
	void slot_pBtnSelectClicked();
	void slot_pBtnPrevClicked();
	void slot_pBtnNextClicked();

private:
	Ui::UAV_ViewerClass ui;
};

#endif // UAV_VIEWER_H
