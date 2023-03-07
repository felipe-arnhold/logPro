#ifndef CHARTCONFIGSCREEN_H
#define CHARTCONFIGSCREEN_H

#include "gChartView.h"
#include <QMainWindow>

namespace Ui {
class chartConfigScreen;
}

QT_CHARTS_USE_NAMESPACE
class chartConfigScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit chartConfigScreen(gChartView *chart, QWidget *parent = nullptr);
    ~chartConfigScreen();

public slots:

    void saveChanges();

private:
    Ui::chartConfigScreen *ui;
    gChartView *c;
};

#endif // CHARTCONFIGSCREEN_H
