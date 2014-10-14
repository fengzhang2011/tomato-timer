#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent, flags),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    m_currentTotal = 25*60; // 25 minutes;
    m_countRemaining = m_currentTotal;
    ui->lineEditTimerDisplay->setAlignment(Qt::AlignCenter);
    updateTimerDisplay();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTimerDisplay()));
}

MainWindow::~MainWindow()
{
    m_timer->stop();
    delete ui;
    delete m_timer;
}

void MainWindow::updateTimerDisplay()
{
    int minutes = m_countRemaining/60;
    int seconds = m_countRemaining%60;
    QString strMin = QString("%1").arg(minutes, 2, 10, QLatin1Char('0')).mid(0, 2);
    if(minutes==0) strMin = "00";
    QString strSec = QString("%1").arg(seconds, 2, 10, QLatin1Char('0')).mid(0, 2);
    if(seconds==0) strSec = "00";
    ui->lineEditTimerDisplay->setText(QString("%1:%2").arg(strMin).arg(strSec));
    if(m_countRemaining==0)
    {
        QMessageBox::warning(this, "Time is out", "Your time is out.");
        m_countRemaining = m_currentTotal;
        m_timer->stop();
    }
    else
    {
        m_countRemaining --;
    }
//    qDebug()<<"count remaining"<<m_countRemaining;
}

void MainWindow::on_pushButtonPomodoro_clicked()
{
    m_timer->stop();
    m_currentTotal = 25*60; // 25 minutes;
    m_countRemaining = m_currentTotal;
    updateTimerDisplay();
    m_timer->start();
}

void MainWindow::on_pushButtonShortBreak_clicked()
{
    m_timer->stop();
    m_currentTotal = 5*60; // 5 minutes;
    m_countRemaining = m_currentTotal;
    updateTimerDisplay();
    m_timer->start();
}

void MainWindow::on_pushButtonLongBreak_clicked()
{
    m_timer->stop();
    m_currentTotal = 10*60; // 10 minutes;
    m_countRemaining = m_currentTotal;
    updateTimerDisplay();
    m_timer->start();
}

void MainWindow::on_pushButtonStart_clicked()
{
    m_timer->start();
}

void MainWindow::on_pushButtonStop_clicked()
{
    m_timer->stop();
}

void MainWindow::on_pushButtonReset_clicked()
{
    m_countRemaining = m_currentTotal;
    m_timer->start();
}

void MainWindow::on_checkBoxDesktopAlerts_clicked(bool checked)
{

}
