#ifndef QTIMAGELABEL_H
#define QTIMAGELABEL_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QtUiPlugin/QDesignerExportWidget>
namespace Ui {
class QtImageLabel;
}

class QDESIGNER_WIDGET_EXPORT QtImageLabel : public QWidget
{
    Q_OBJECT

public:
    explicit QtImageLabel(QWidget *parent = 0);
    ~QtImageLabel();

    bool setImage(QString& imgPath);

private:
    Ui::QtImageLabel *ui;

    QPixmap m_pixmap;
};

#endif // QTIMAGELABEL_H
