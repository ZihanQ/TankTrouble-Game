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

    this -> ui -> gameView->setFixedSize(500, 500);
    this -> gScene = new gameScene;
    ui->gameView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this -> ui -> gameView -> setScene(gScene);
    gScene->setSceneRect(ui->gameView->rect());
}

