#include "chartConfigScreen.h"
#include "ui_chartConfigScreen.h"

chartConfigScreen::chartConfigScreen(gChartView *chart, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chartConfigScreen)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    this->setEnabled(true);

    c = chart;
    ui->le_title->setText(c->chart()->title());

    connect(ui->pb_save, SIGNAL(clicked()), this, SLOT(saveChanges()));
    connect(ui->pb_cancel, SIGNAL(clicked()), this, SLOT(close()));
}

chartConfigScreen::~chartConfigScreen()
{
    delete ui;
}

void chartConfigScreen::saveChanges()
{
    c->chart()->setTitle(ui->le_title->text());
}
