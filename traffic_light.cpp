// traffic_light.cpp

#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget *parent) : QWidget(parent)
{

  // Add the red traffic light
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle(); // initialize the red light to be ON
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");

  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);

  setLayout(layout);
}

// TO DO: build the light_update() slot function here
void TrafficLight::light_update()
{
  // the order asked is red -> green -> yellow
  // if red go to green
  if (redlight->isChecked())
  {
    greenlight->toggle();
  }
  // if green go to yellow
  else if (greenlight->isChecked())
  {
    yellowlight->toggle();
  }
  // if yellow light go to red
  else
  {
    redlight->toggle();
  }
}
