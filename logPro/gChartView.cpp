#include "gChartView.h"

QT_CHARTS_BEGIN_NAMESPACE
gChartView::gChartView(QWidget *parent) : QChartView(parent)
{

}

#ifndef QT_NO_CONTEXTMENU
void gChartView::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction("Configure");
    //menu.addAction("Delete Chart");
    QAction *act = menu.exec(event->globalPos());

    if(act != NULL){
        if (act->text() == "Configure")
            emit configClicked(this);
        else if (act->text() == "Delete Chart")
            delete this;
    }
}
#endif // QT_NO_CONTEXTMENU
QT_CHARTS_END_NAMESPACE
