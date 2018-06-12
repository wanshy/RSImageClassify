#include "qtimagelabel.h"
#include "ui_qtimagelabel.h"
#include <QPainter>
static const int IMAGE_WIDTH = 160;
static const int IMAGE_HEIGHT = 120;
static const QSize IMAGE_SIZE = QSize(IMAGE_WIDTH, IMAGE_HEIGHT);

QtImageLabel::QtImageLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtImageLabel)
{
    ui->setupUi(this);
}

QtImageLabel::~QtImageLabel()
{
    delete ui;
}


bool QtImageLabel::setImage(QString& imgPath)
{
    QImage image;
    image.load(imgPath);
    if(image.isNull())
    {
        return false;
    }
    m_pixmap = QPixmap::fromImage(image);
    ui->label->setPixmap(m_pixmap);

    update();
    return true;
}

