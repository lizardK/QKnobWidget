#include "qknobwidget.h"
#include <QPainter>

QKnobWidget::QKnobWidget(QWidget *parent) :
  QWidget(parent),
  m_color("#FFFFFF"),
  m_selectedColor("#87CEEB"),
  m_value(5),
  m_minValue(0),
  m_maxValue(100),
  m_borderSize(4)
{
}

QColor QKnobWidget::color() const
{
  return m_color;
}

void QKnobWidget::setColor(const QColor &color)
{
  m_color = color;
  update();
}

QColor QKnobWidget::selectedColor() const
{
  return m_selectedColor;
}

void QKnobWidget::setSelectedColor(const QColor &selectedColor)
{
  m_selectedColor = selectedColor;
  update();
}

int QKnobWidget::value() const
{
  return m_value;
}

void QKnobWidget::setValue(int value)
{
  if(value < m_minValue)
    {
      m_value = m_minValue;
      emit valueChanged(m_value);
      update();
      return;
    }

  if(value > m_maxValue)
    {
      m_value = m_maxValue;
      emit valueChanged(m_value);
      update();
      return;
    }

  if(m_value == value)
    return;

  m_value = value;
  emit valueChanged(m_value);
  update();
}

int QKnobWidget::minValue() const
{
  return m_minValue;
}

void QKnobWidget::setMinValue(int minValue)
{
  m_minValue = minValue;
  update();
}

int QKnobWidget::maxValue() const
{
  return m_maxValue;
}

void QKnobWidget::setMaxValue(int maxValue)
{
  m_maxValue = maxValue;
  update();
}

int QKnobWidget::borderSize() const
{
  return m_borderSize;
}

void QKnobWidget::setBorderSize(int borderSize)
{
  m_borderSize = borderSize;
  update();
}

void QKnobWidget::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing, true);

  // Draw circle centered in circle
  int extent;
  if (width()>height())
    extent = height()-5;
  else
    extent = width()-5;

  p.translate((width()-extent)/2, (height()-extent)/2);

  QPen pen (m_color);
  pen.setWidth(m_borderSize);
  p.setPen(pen);
  p.setBrush(Qt::transparent);

  QRect r(0, 0, extent, extent);
  p.drawEllipse(r);

  // Draw value centered in circle
  QPen penText(m_selectedColor);
  p.setPen(penText);
  p.drawText(r,Qt::AlignCenter, QString::number(m_value));

  // Draw arc value
  QPen penArc(m_selectedColor);
  penArc.setWidth(m_borderSize);
  p.setPen(penArc);
  p.drawArc(r, 90 * 16, -(m_value * 360 / m_maxValue) * 16);
}
