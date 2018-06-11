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
    this->resize(400, 300);
    ui->label->resize(400,300);

    m_pixmap = QPixmap(IMAGE_SIZE);
    m_pixmap.fill();
    m_scale = 1.0;
    m_mode = FIXED_SIZE;
    m_brush = QBrush(Qt::white);
}

QtImageLabel::~QtImageLabel()
{
    delete ui;
}

void QtImageLabel::setBackground(QBrush brush)
{
    m_brush = brush;
    update();
}

void QtImageLabel::setMode(PB_MODE mode)
{
    m_mode = mode;
    if(m_mode == AUTO_SIZE)
    {
        setFixedSize(m_pixmap.size() * m_scale);
    }
    else
    {
        setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        setMinimumSize(0, 0);
    }
    update();
}

bool QtImageLabel::setImage(QImage &image, double scale)
{
    if(image.isNull())
    {
        return false;
    }
    m_pixmap = QPixmap::fromImage(image);
    m_scale = qBound(0.01, scale, 100.0);
    if(m_mode == AUTO_SIZE)
    {
        setFixedSize(m_pixmap.size() * m_scale);
    }
    update();
    return true;
}

void QtImageLabel::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBackground(m_brush);
    painter.eraseRect(rect());

    double window_width, window_height;
    double image_width, image_height;
    double r1, r2, r;
    int offset_x, offset_y;
    switch (m_mode)
    {
    case FIXED_SIZE:
    case AUTO_SIZE:
        painter.scale(m_scale, m_scale);
        painter.drawPixmap(0, 0, m_pixmap);
        break;
    case FIX_SIZE_CENTRED:
        window_width = width();
        window_height = height();
        image_width = m_pixmap.width();
        image_height = m_pixmap.height();
        offset_x = (window_width - m_scale * image_width) / 2;
        offset_y = (window_height - m_scale * image_height) / 2;
        painter.translate(offset_x, offset_y);
        painter.scale(m_scale, m_scale);
        painter.drawPixmap(0, 0, m_pixmap);
        break;
    case AUTO_ZOOM:
        window_width = width();
        window_height = height();
        image_width = m_pixmap.width();
        image_height = m_pixmap.height();
        r1 = window_width / image_width;
        r2 = window_height / image_height;
        r = qMin(r1, r2);
        offset_x = (window_width - r * image_width) / 2;
        offset_y = (window_height - r * image_height) / 2;
        painter.translate(offset_x, offset_y);
        painter.scale(r, r);
        painter.drawPixmap(0, 0, m_pixmap);
        break;
    }
}
