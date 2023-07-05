#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{
    this -> setFixedSize(1000,1000);
    this->ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this -> ui -> gameView -> setGeometry(0,100,1000,850);
    //this -> ui -> gameView->setFixedSize(500, 500);
    this -> gScene = new gameScene;
    ui->gameView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    gScene->setSceneRect(ui->gameView->rect());
    this -> ui -> gameView -> setScene(gScene);

}

