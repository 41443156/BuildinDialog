#include "cbuilitindlg.h"
#include <QDebug>
#include<QFileDialog>

CBuilitinDlg::CBuilitinDlg(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* gridLayout= new QGridLayout;
    displayTextEdit= new QTextEdit("Qt的標準通用對話盒");
    colorPushBtn= new QPushButton ("顏色對話盒");
    errorPushBtn =new QPushButton("錯誤訊息盒");
    filePushBtn= new QPushButton("檔案對話盒");
    fontPushBtn=new QPushButton("字體對話盒");
    inputPushBtn=new QPushButton("輸入對話盒");
    pagePushBtn=new QPushButton("頁面設定對話盒");
    progressPushBtn=new QPushButton("進度對話盒");
    printPushBtn= new QPushButton("列印對話盒");
    textColorPushBtn= new QPushButton("變更文字顏色盒");

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,1,3);
    gridLayout->addWidget(textColorPushBtn,2,2,1,1);


    setLayout(gridLayout);
    setWindowTitle("內建對話盒視窗展示");
    resize(800,600);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(textColorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));

}

CBuilitinDlg::~CBuilitinDlg() = default;

void CBuilitinDlg::doPushBtn()
    {
    QPushButton* btn=qobject_cast<QPushButton*>(sender());
        if (btn == colorPushBtn)
    {
        QPalette palette= displayTextEdit->palette();
        const QColor& color=
            QColorDialog::getColor(palette.color(QPalette::Base),this,QStringLiteral("設定背景顏色"));
        if(color.isValid())
        {
         palette.setColor(QPalette::Base,color);
         displayTextEdit->setPalette(palette);

        }

    }
        if (btn==filePushBtn){
        QString fileName=QFileDialog::getOpenFileName(this,QStringLiteral("打開檔案"),".",QStringLiteral("任何檔案(*.*);;文字檔(*.txt);;XML檔(*.xmL)"));
            displayTextEdit->setText(fileName);
        }
        else if (btn==textColorPushBtn)
        {
        QPalette palette= displayTextEdit->palette();
         const QColor& color=
        QColorDialog::getColor(palette.color(QPalette::Text),this,QStringLiteral("設定文字顏色"));
        if(color.isValid())
        {
            palette.setColor(QPalette::Text,color);
            displayTextEdit->setTextColor(color);
    }
}
    }