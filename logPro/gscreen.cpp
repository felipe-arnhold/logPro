#include "gscreen.h"
#include "ui_gscreen.h"

gScreen::gScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gScreen)
{
    ui->setupUi(this);

    connect(ui->pb_addChart, SIGNAL(pressed()), this, SLOT(chartAdd()));
    connect(ui->pb_delChart, SIGNAL(pressed()), this, SLOT(chartdel()));

    spl = new QSplitter(this);
    spl->setOrientation(Qt::Vertical);
    ui->gChartLayout->addWidget(spl);
}

gScreen::~gScreen()
{
    delete ui;
}

void gScreen::chartAdd()
{
    qDebug() << "Add pressed";

    QSplineSeries *s1 = new QSplineSeries();
    s1->append(0, 6); s1->append(2, 4); s1->append(3, 8); s1->append(7, 4); s1->append(10, 5);

    QChart *ch = new QChart();
    ch->addSeries(s1);
    ch->createDefaultAxes();
    ch->setTitle("Simple line chart");

    gChartView *chView = new gChartView(this);
    chView->setChart(ch);
    chView->chart()->setTheme(QChart::ChartThemeDark);
    chView->setRenderHint(QPainter::Antialiasing);

    spl->addWidget(chView);

    connect(chView, SIGNAL(configClicked(gChartView *)), this, SLOT(configChart(gChartView *)));

}

void gScreen::chartdel()
{
    qDebug() << "Del pressed";

    qDebug() << spl->count();

    //ui->gChartLayout->removeWidget(ui->gChartLayout->widget());
    if(spl->count() != 0) {
        delete spl->widget(spl->count() - 1);
        //delete spl->takeAt(ui->gChartLayout->count() - 1)->widget();
        //ui->gChartLayout->removeWidget(ui->gChartLayout->takeAt(ui->gChartLayout->count() - 1));
    }
}

void gScreen::configChart(gChartView *cView)
{
    this->setEnabled(false);
    chartConfigScreen *conf = new chartConfigScreen(cView, this);
    conf->show();


    QEventLoop loop;
    connect(conf, SIGNAL(destroyed()), &loop, SLOT(quit()));
    loop.exec();

    qDebug() << "Config screen closed!";
    this->setEnabled(true);
}

