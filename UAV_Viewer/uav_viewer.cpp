#include "uav_viewer.h"
#include <QFileDialog>
#include <Qstring>
#include <QImage>

UAV_Viewer::UAV_Viewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.qtImageLabel->setImage(QString("E:\\20180612001000.jpg"));
	InitTreeWidget();
	InitMenu();
	InitToolBar();
	InitConnect();
	m_pLabelFileName = new QLabel(this);
	ui.statusBar->addWidget(m_pLabelFileName);
}

UAV_Viewer::~UAV_Viewer()
{

}

void UAV_Viewer::slot_pBtnSelectClicked()
{
	QString filePath= QFileDialog::getExistingDirectory(this, tr("Open File Path"), ".");
	ui.lineEdit->setText(filePath);
	QTreeWidgetItem *root = new QTreeWidgetItem(QStringList() << filePath);
	QFileInfoList qlFileList = FindAllFiles(root, filePath); 
	ui.tree_View->addTopLevelItem(root);
}

void UAV_Viewer::slot_pBtnPrevClicked()
{

}

void UAV_Viewer::slot_pBtnNextClicked()
{
	QTreeWidgetItem *item = ui.tree_View->currentItem();
	return;
}

QFileInfoList UAV_Viewer::FindAllFiles(QTreeWidgetItem *root, QString path)         //参数为主函数中添加的item和路径名  
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
	for (int i = 0; i < list_file.size(); ++i)//将当前目录中所有文件添加到treewidget中  
	{      
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
		QFileInfoList child_file_list = FindAllFiles(childroot, namepath);          //进行递归  
		file_list.append(child_file_list);
		file_list.append(name);
	}
	return file_list;
}

void UAV_Viewer::slot_ShowMenuofTree(const QPoint & pos)
{
	QTreeWidgetItem *item = ui.tree_View->currentItem();
	qDebug() << GetFullPathbyTreeItem(item);
	m_pMenuOfTree->exec(QCursor::pos());
}

void UAV_Viewer::InitMenu()
{
	m_pMenuFile = new QMenu(tr("File"), this);
	m_pActionFileOpen = new QAction("&Open...", this);
	m_pActionFileSave = new QAction("&Save...", this);
	m_pMenuFile->addAction(m_pActionFileOpen);
	m_pMenuFile->addAction(m_pActionFileSave);
	
	m_pMenuEdit = new QMenu(tr("&Edit"), this);
	m_pActionEditCopy = m_pMenuEdit->addAction("&Copy");
	m_pActionEditCut = m_pMenuEdit->addAction("&Cut");

	m_pMenuFile->addMenu(m_pMenuEdit);
	QMenuBar* menuBar = this->menuBar();
	menuBar->addMenu(m_pMenuFile);
	menuBar->addMenu(m_pMenuEdit);

}

void UAV_Viewer::InitToolBar()
{
	
	m_pToolBar = new QToolBar(this);
	m_pToolBar->addAction(m_pActionFileOpen);
	m_pToolBar->addAction(m_pActionFileSave);

	m_pEditBar = new QToolBar(this);
	m_pEditBar->addAction(m_pActionEditCopy);
	m_pEditBar->addAction(m_pActionEditCut);
	addToolBar(Qt::TopToolBarArea, m_pToolBar);
	addToolBar(Qt::TopToolBarArea, m_pEditBar);
	this->setToolButtonStyle(Qt::ToolButtonIconOnly);
}

void UAV_Viewer::InitConnect()
{
	connect(ui.pBtn_Select, SIGNAL(clicked()), this, SLOT(slot_pBtnSelectClicked()));
	connect(ui.pBtn_Next, SIGNAL(clicked()), this, SLOT(slot_pBtnNextClicked()));
	connect(ui.pBtn_Prev, SIGNAL(clicked()), this, SLOT(slot_pBtnPrevClicked()));

	connect(m_pActionFileOpen, SIGNAL(triggered()), this, SLOT(slot_pBtnSelectClicked()));
}

void UAV_Viewer::InitTreeWidget()
{
	//清理并删除树头
	ui.tree_View->setColumnCount(2);
	ui.tree_View->clear();
	ui.tree_View->setHeaderHidden(true);

	m_pActionDelete = new QAction("Delete", this);
	m_pActionRename = new QAction("Rename", this);
	m_pMenuOfTree = new QMenu();
	m_pMenuOfTree->addAction(m_pActionDelete);
	m_pMenuOfTree->addAction(m_pActionDelete);
	ui.tree_View->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(m_pActionDelete, SIGNAL(triggered()), this, SLOT(slot_pBtnNextClicked()));
	connect(ui.tree_View, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slot_ShowMenuofTree(const QPoint &)));
	connect(ui.tree_View, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(slot_TreeItemChecked(QTreeWidgetItem*, int)));
	connect(ui.tree_View, SIGNAL(itemEntered(QTreeWidgetItem*, int)), this, SLOT(slot_TreeItemChecked(QTreeWidgetItem*, int)));
	connect(ui.tree_View, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(slot_TreeItemDoubleClicked(QTreeWidgetItem*, int)));
}

void UAV_Viewer::slot_TreeItemChecked(QTreeWidgetItem* treeItem, int index)
{
	m_pLabelFileName->setText(GetFullPathbyTreeItem(treeItem));
	return;
}

void UAV_Viewer::slot_TreeItemDoubleClicked(QTreeWidgetItem* treeView, int index)
{
	QString filePath = GetFullPathbyTreeItem(treeView);
	ui.qtImageLabel->setImage(filePath);
	return;
}

QString UAV_Viewer::GetFullPathbyTreeItem(QTreeWidgetItem* treeItem)
{
	/*得到文件路径*/
	if (treeItem == NULL)
	{
		return "";
	}
	QStringList filepath;
	QTreeWidgetItem *itemfile = treeItem; //获取被点击的item   
	while (itemfile != NULL)
	{
		filepath << itemfile->text(0); //获取itemfile名称
		itemfile = itemfile->parent(); //将itemfile指向父item
	}

	QString strpath;
	for (int i = (filepath.size() - 1); i >= 0; i--) //QStringlist类filepath反向存着初始item的路径
	{ 
		strpath += filepath.at(i);
		if (i != 0)
		{
			strpath += "/";
		}
	}
	return strpath;
}
