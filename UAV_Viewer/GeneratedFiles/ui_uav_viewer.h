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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtimagelabel.h"

QT_BEGIN_NAMESPACE

class Ui_UAV_ViewerClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pBtn_Select;
    QPushButton *pBtn_Prev;
    QPushButton *pBtn_Next;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *tree_View;
    QSpacerItem *horizontalSpacer;
    QtImageLabel *qtImageLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UAV_ViewerClass)
    {
        if (UAV_ViewerClass->objectName().isEmpty())
            UAV_ViewerClass->setObjectName(QStringLiteral("UAV_ViewerClass"));
        UAV_ViewerClass->resize(647, 405);
        centralWidget = new QWidget(UAV_ViewerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 626, 335));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pBtn_Select = new QPushButton(widget);
        pBtn_Select->setObjectName(QStringLiteral("pBtn_Select"));

        horizontalLayout->addWidget(pBtn_Select);

        pBtn_Prev = new QPushButton(widget);
        pBtn_Prev->setObjectName(QStringLiteral("pBtn_Prev"));

        horizontalLayout->addWidget(pBtn_Prev);

        pBtn_Next = new QPushButton(widget);
        pBtn_Next->setObjectName(QStringLiteral("pBtn_Next"));

        horizontalLayout->addWidget(pBtn_Next);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tree_View = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tree_View->setHeaderItem(__qtreewidgetitem);
        tree_View->setObjectName(QStringLiteral("tree_View"));
        tree_View->setMinimumSize(QSize(160, 300));
        tree_View->setMaximumSize(QSize(170, 16777215));

        horizontalLayout_2->addWidget(tree_View);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        qtImageLabel = new QtImageLabel(widget);
        qtImageLabel->setObjectName(QStringLiteral("qtImageLabel"));

        horizontalLayout_2->addWidget(qtImageLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        UAV_ViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UAV_ViewerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 23));
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
    } // retranslateUi

};

namespace Ui {
    class UAV_ViewerClass: public Ui_UAV_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UAV_VIEWER_H
