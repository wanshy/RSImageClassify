/********************************************************************************
** Form generated from reading UI file 'uav_viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UAV_VIEWER_H
#define UI_UAV_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UAV_ViewerClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pBtn_Select;
    QPushButton *pBtn_Prev;
    QPushButton *pBtn_Next;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *tree_View;
    QLabel *lab_Image;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UAV_ViewerClass)
    {
        if (UAV_ViewerClass->objectName().isEmpty())
            UAV_ViewerClass->setObjectName(QStringLiteral("UAV_ViewerClass"));
        UAV_ViewerClass->resize(603, 408);
        centralWidget = new QWidget(UAV_ViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 581, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pBtn_Select = new QPushButton(layoutWidget);
        pBtn_Select->setObjectName(QStringLiteral("pBtn_Select"));

        horizontalLayout->addWidget(pBtn_Select);

        pBtn_Prev = new QPushButton(layoutWidget);
        pBtn_Prev->setObjectName(QStringLiteral("pBtn_Prev"));

        horizontalLayout->addWidget(pBtn_Prev);

        pBtn_Next = new QPushButton(layoutWidget);
        pBtn_Next->setObjectName(QStringLiteral("pBtn_Next"));

        horizontalLayout->addWidget(pBtn_Next);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 40, 581, 302));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tree_View = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tree_View->setHeaderItem(__qtreewidgetitem);
        tree_View->setObjectName(QStringLiteral("tree_View"));
        tree_View->setMinimumSize(QSize(160, 300));

        horizontalLayout_2->addWidget(tree_View);

        lab_Image = new QLabel(widget);
        lab_Image->setObjectName(QStringLiteral("lab_Image"));
        lab_Image->setMinimumSize(QSize(160, 300));
        lab_Image->setMouseTracking(true);
        lab_Image->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(lab_Image);

        UAV_ViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UAV_ViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 603, 23));
        UAV_ViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UAV_ViewerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UAV_ViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UAV_ViewerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UAV_ViewerClass->setStatusBar(statusBar);

        retranslateUi(UAV_ViewerClass);

        QMetaObject::connectSlotsByName(UAV_ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *UAV_ViewerClass)
    {
        UAV_ViewerClass->setWindowTitle(QApplication::translate("UAV_ViewerClass", "UAV_Viewer", 0));
        pBtn_Select->setText(QApplication::translate("UAV_ViewerClass", "Select", 0));
        pBtn_Prev->setText(QApplication::translate("UAV_ViewerClass", "<<", 0));
        pBtn_Next->setText(QApplication::translate("UAV_ViewerClass", ">>", 0));
        lab_Image->setText(QApplication::translate("UAV_ViewerClass", "00", 0));
    } // retranslateUi

};

namespace Ui {
    class UAV_ViewerClass: public Ui_UAV_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UAV_VIEWER_H
