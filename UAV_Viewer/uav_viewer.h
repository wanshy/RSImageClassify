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
	void slot_ShowMenuofTree();
private:
	Ui::UAV_ViewerClass ui;
	QMenu* m_pMenuOfTree;
};

#endif // UAV_VIEWER_H
