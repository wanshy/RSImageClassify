#ifndef UAV_VIEWER_H
#define UAV_VIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_uav_viewer.h"
#include <QFileInfo>
#include <QLabel>
#include <QDebug>
class UAV_Viewer : public QMainWindow
{
	Q_OBJECT

public:
	UAV_Viewer(QWidget *parent = 0);
	~UAV_Viewer();

	QFileInfoList FindAllFiles(QTreeWidgetItem *root, QString path);

private:
	void InitMenu();
	void InitToolBar();
	void InitConnect();
	void InitTreeWidget();

	QString GetFullPathbyTreeItem(QTreeWidgetItem* treeItem);
public slots:
	void slot_pBtnSelectClicked();
	void slot_pBtnPrevClicked();
	void slot_pBtnNextClicked();

	void slot_ShowMenuofTree(const QPoint &);
	void slot_TreeItemChecked(QTreeWidgetItem*, int);
	void slot_TreeItemDoubleClicked(QTreeWidgetItem*, int);
	
private:
	Ui::UAV_ViewerClass ui;

	QMenu* m_pMenuOfTree;
	QMenu* m_pMenuFile;
	QMenu* m_pMenuEdit;

	QAction* m_pActionFileOpen;
	QAction* m_pActionFileSave;
	QAction* m_pActionEditCopy;
	QAction* m_pActionEditCut;
	QAction* m_pActionDelete;
	QAction* m_pActionRename;

	QToolBar* m_pToolBar;
	QToolBar* m_pEditBar;
	QLabel* m_pLabelFileName;


};

#endif // UAV_VIEWER_H
