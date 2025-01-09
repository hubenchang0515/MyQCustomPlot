#include "dialog.h"
#include "LinePlot.h"
#include <QLayout>

Dialog::Dialog(QWidget* parent) noexcept:
    QDialog{parent}
{
    auto plot = new LinePlot;
    auto layout = new QVBoxLayout;
    layout->addWidget(plot);
    setLayout(layout);
}

Dialog::~Dialog() noexcept
{

}