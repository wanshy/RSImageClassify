#include "qtimagelabel.h"
#include "qtimagelabelplugin.h"

#include <QtPlugin>

QtImageLabelPlugin::QtImageLabelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QtImageLabelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QtImageLabelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QtImageLabelPlugin::createWidget(QWidget *parent)
{
    return new QtImageLabel(parent);
}

QString QtImageLabelPlugin::name() const
{
    return QLatin1String("QtImageLabel");
}

QString QtImageLabelPlugin::group() const
{
    return QLatin1String("");
}

QIcon QtImageLabelPlugin::icon() const
{
    return QIcon(QLatin1String(":/bg.png"));
}

QString QtImageLabelPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QtImageLabelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QtImageLabelPlugin::isContainer() const
{
    return false;
}

QString QtImageLabelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QtImageLabel\" name=\"qtImageLabel\">\n</widget>\n");
}

QString QtImageLabelPlugin::includeFile() const
{
    return QLatin1String("qtimagelabel.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qtimagelabelplugin, QtImageLabelPlugin)
#endif // QT_VERSION < 0x050000
