#include "qknobwidget.h"
#include "qknobwidgetplugin.h"

#include <QtPlugin>

QKnobWidgetPlugin::QKnobWidgetPlugin(QObject *parent)
  : QObject(parent)
{
  m_initialized = false;
}

void QKnobWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
  if (m_initialized)
    return;

  // Add extension registrations, etc. here

  m_initialized = true;
}

bool QKnobWidgetPlugin::isInitialized() const
{
  return m_initialized;
}

QWidget *QKnobWidgetPlugin::createWidget(QWidget *parent)
{
  return new QKnobWidget(parent);
}

QString QKnobWidgetPlugin::name() const
{
  return QLatin1String("QKnobWidget");
}

QString QKnobWidgetPlugin::group() const
{
  return QLatin1String("Custom Widget");
}

QIcon QKnobWidgetPlugin::icon() const
{
  return QIcon(QLatin1String(":/QKnobWidget.png"));
}

QString QKnobWidgetPlugin::toolTip() const
{
  return QLatin1String("");
}

QString QKnobWidgetPlugin::whatsThis() const
{
  return QLatin1String("");
}

bool QKnobWidgetPlugin::isContainer() const
{
  return false;
}

QString QKnobWidgetPlugin::domXml() const
{
  return QLatin1String("<widget class=\"QKnobWidget\" name=\"qKnobWidget\">\n</widget>\n");
}

QString QKnobWidgetPlugin::includeFile() const
{
  return QLatin1String("qknobwidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qknobwidgetplugin, QKnobWidgetPlugin)
#endif // QT_VERSION < 0x050000
