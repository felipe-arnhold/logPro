#ifndef GCHARTVIEW_H
#define GCHARTVIEW_H

#include <QChartView>
#include <QMenu>
#include <QDebug>

QT_CHARTS_BEGIN_NAMESPACE

class gChartView : public QChartView
{
    Q_OBJECT
public:
    gChartView(QWidget *parent = nullptr);

signals:
    void configClicked(gChartView *cView);

protected:
    #ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
    #endif
};

QT_CHARTS_END_NAMESPACE
#endif // GCHARTVIEW_H
