#ifndef CBUILITINDLG_H
#define CBUILITINDLG_H

#include <QDialog>
#include <QtWidgets>

class CBuilitinDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CBuilitinDlg(QWidget *parent = nullptr);
    ~CBuilitinDlg() override;
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
    QPushButton* textColorPushBtn;

private slots:
    void doPushBtn();
};
#endif // CBUILITINDLG_H
