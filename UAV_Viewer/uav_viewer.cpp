#include "uav_viewer.h"
#include <QFileDialog>
#include <Qstring>
#include <QImage>

UAV_Viewer::UAV_Viewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pBtn_Select, SIGNAL(clicked()), this, SLOT(slot_pBtnSelectClicked()));
	connect(ui.pBtn_Next, SIGNAL(clicked()), this, SLOT(slot_pBtnNextClicked()));
	connect(ui.pBtn_Prev, SIGNAL(clicked()), this, SLOT(slot_pBtnPrevClicked()));
	ui.tree_View->clear();
	ui.tree_View->setHeaderHidden(true);

	m_pMenuOfTree = new QMenu();
	m_pMenuOfTree->addAction(QString::fromLocal8Bit("菜单子项1"), this, SLOT(slot_pBtnNextClicked()));
	m_pMenuOfTree->addAction(QString::fromLocal8Bit("菜单子项2"), this, SLOT(slot_pBtnNextClicked()));
	ui.tree_View->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.tree_View, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slot_ShowMenuofTree()));
	ui.qtImageLabel->setImage(QString("E:\\20180612001000.jpg"));
	//m_pMenuOfTree->popup(ui.tree_View->mapToGlobal(pos));
}

UAV_Viewer::~UAV_Viewer()
{

}

void UAV_Viewer::slot_pBtnSelectClicked()
{
	QString filePath= QFileDialog::getExistingDirectory(this, tr("打开db数据目录"), ".");
	ui.lineEdit->setText(filePath);
	QTreeWidgetItem *root = new QTreeWidgetItem(QStringList() << filePath);
	allfile(root, filePath);
	ui.tree_View->addTopLevelItem(root);
}

void UAV_Viewer::slot_pBtnPrevClicked()
{

}

void UAV_Viewer::slot_pBtnNextClicked()
{
	return;
}

QFileInfoList UAV_Viewer::allfile(QTreeWidgetItem *root, QString path)         //参数为主函数中添加的item和路径名  
{
	QFileInfoList te;
	if (NULL == root)
	{
		return te;
	}
	root->setIcon(0, QIcon(":/UAV_Viewer/Resources/folder.png"));

	/*添加path路径文件*/
	QDir dir(path);          //遍历各级子目录  
	QDir dir_file(path);    //遍历子目录中所有文件  
	dir_file.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);        //获取当前所有文件  
	dir_file.setSorting(QDir::Size | QDir::Reversed);
	QFileInfoList list_file = dir_file.entryInfoList();
	for (int i = 0; i < list_file.size(); ++i) {       //将当前目录中所有文件添加到treewidget中  
		QFileInfo fileInfo = list_file.at(i);
		QString name2 = fileInfo.fileName();
		QTreeWidgetItem* child = new QTreeWidgetItem(QStringList() << name2);
		child->setIcon(0, QIcon(":/UAV_Viewer/Resources/doc.png"));
		child->setCheckState(1, Qt::Checked);
		root->addChild(child);
	}


	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);   //获取当前所有目录  

	for (int i = 0; i != folder_list.size(); i++)         //自动递归添加各目录到上一级目录  
	{

		QString namepath = folder_list.at(i).absoluteFilePath();    //获取路径  
		QFileInfo folderinfo = folder_list.at(i);
		QString name = folderinfo.fileName();      //获取目录名  
		QTreeWidgetItem* childroot = new QTreeWidgetItem(QStringList() << name);
		childroot->setIcon(0, QIcon(":/UAV_Viewer/Resources/folder.png"));
		childroot->setCheckState(1, Qt::Checked);
		root->addChild(childroot);              //将当前目录添加成path的子项  
		QFileInfoList child_file_list = allfile(childroot, namepath);          //进行递归  
		file_list.append(child_file_list);
		file_list.append(name);
	}
	return file_list;
}

void UAV_Viewer::slot_ShowMenuofTree()
{
// 	QMenu *menu = new QMenu(ui.tree_View);
// 	QAction *addAction = new QAction("add", this);
// 	QAction *delAction = new QAction("del", this);
// 	QAction *modAction = new QAction("mod", this);
// 
// 	menu->addAction(addAction);
// 	menu->addAction(delAction);
// 	menu->addAction(modAction);

	m_pMenuOfTree->exec(QCursor::pos());
}
