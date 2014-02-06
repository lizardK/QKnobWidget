#ifndef QKNOBWIDGET_H
#define QKNOBWIDGET_H

#include <QWidget>

class QKnobWidget : public QWidget
{
  Q_OBJECT

  Q_PROPERTY(QColor color READ color WRITE setColor)
  Q_PROPERTY(QColor selectedColor READ selectedColor WRITE setSelectedColor)
  Q_PROPERTY(int value READ value WRITE setValue)
  Q_PROPERTY(int minValue READ minValue WRITE setMinValue)
  Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue)
  Q_PROPERTY(int borderSize READ borderSize WRITE setBorderSize)

public:
  QKnobWidget(QWidget *parent = 0);

  QColor color() const;
  void setColor(const QColor& color);

  QColor selectedColor() const;
  void setSelectedColor(const QColor& selectedColor);

  int value() const;

  int minValue() const;
  void setMinValue(int minValue);

  int maxValue() const;
  void setMaxValue(int maxValue);

  int borderSize() const;
  void setBorderSize(int borderSize);

public slots:
  void setValue(int value);

signals :
  void valueChanged(int value);

protected:
  void paintEvent(QPaintEvent* event);

private:
  QColor m_color;
  QColor m_selectedColor;
  int m_value;
  int m_minValue;
  int m_maxValue;
  int m_borderSize;
};

#endif
