#ifndef GSCREEN_H
#define GSCREEN_H

#include <QMainWindow>
#include <QDebug>
//#include <QChartView>
#include <QLineSeries>
#include <QSplineSeries>
#include <QList>
#include <QToolBar>
#include <QSplitter>
#include "gChartView.h"
#include "chartConfigScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gScreen; }
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE
class gScreen : public QMainWindow
{
    Q_OBJECT

public:
    gScreen(QWidget *parent = nullptr);
    ~gScreen();

public slots:
    void chartAdd();
    void chartdel();
    void configChart(gChartView *cView);

private:
    Ui::gScreen *ui;
    QSplitter *spl;
};
#endif // GSCREEN_H
