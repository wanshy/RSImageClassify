#ifndef QTIMAGELABEL_H
#define QTIMAGELABEL_H

#include <QWidget>
#include <QImage>
#include <QPixmap>

namespace Ui {
class QtImageLabel;
}

class QtImageLabel : public QWidget
{
    Q_OBJECT

public:
    explicit QtImageLabel(QWidget *parent = 0);
    ~QtImageLabel();

    enum PB_MODE {FIXED_SIZE, FIX_SIZE_CENTRED, AUTO_ZOOM, AUTO_SIZE};
    void setMode(PB_MODE mode);
private:
    Ui::QtImageLabel *ui;

    QPixmap m_pixmap;
    double m_scale;
    PB_MODE m_mode;
    QBrush m_brush;

protected:
    void paintEvent(QPaintEvent * event);
signals:

public slots:
    bool setImage(QImage &image, double scale = 1.0);
    void setBackground(QBrush brush);
};

#endif // QTIMAGELABEL_H
