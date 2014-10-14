#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateTimerDisplay();
    void on_pushButtonPomodoro_clicked();
    void on_pushButtonShortBreak_clicked();
    void on_pushButtonLongBreak_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
    void on_pushButtonReset_clicked();
    void on_checkBoxDesktopAlerts_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    int m_countRemaining;
    int m_currentTotal;
};

#endif // MAINWINDOW_H
