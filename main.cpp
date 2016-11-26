#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>

class MainWindowSetOpacity: public QMainWindow
{

public:
    MainWindowSetOpacity()
    {
        this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    };
    ~ MainWindowSetOpacity(){};

};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QApplication::setWindowIcon(QIcon("dimmer.png"));
    MainWindow *window = new MainWindow();
    window->show();
    return app.exec();
}

void MainWindow::changeBrightness(double Brightness){

    this->close();

    MainWindowSetOpacity *windowSetOp = new MainWindowSetOpacity();
    windowSetOp->resize(50000, 50000);
    windowSetOp->setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
    windowSetOp->setWindowOpacity(Brightness);
    windowSetOp->setWindowState(Qt::WindowFullScreen );
    QPalette pal2 = windowSetOp->palette();
    pal2.setColor(QPalette::Window, Qt::black);
    windowSetOp->setPalette(pal2);

    QWidget *centralWidget = new QWidget(windowSetOp);

    windowSetOp->setCentralWidget(centralWidget);
    windowSetOp->show();
}

