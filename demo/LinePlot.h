#ifndef LINE_PLOT_H
#define LINE_PLOT_H

#include <qcustomplot.h>

class LinePlot : public QCustomPlot
{
public:
    LinePlot(QWidget* parent=nullptr) noexcept;
    ~LinePlot() noexcept;
};

#endif