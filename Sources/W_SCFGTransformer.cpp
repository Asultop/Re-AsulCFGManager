#include "../Headers/W_SCFGTransformer.h"
#include "../Headers/BaseScrollpage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Headers/BaseInclude.h"
#include "qapplication.h"
#include "../3rd/QsLog/QsLog.h"
#include "../3rd/qmarkdowntextedit/MarkdownHighlighter.h"
#include <ElaIconButton.h>
#include <QTabBar>
#include <QStackedWidget>
#include "../Headers/GlobalSettings.h"

#define DBG(x) QLOG_DEBUG()<<"[Key] "<<#x<<" : "<<x;
using namespace QsLogging;
W_SCFGTransformer::W_SCFGTransformer(QWidget *parent)
    : ElaWidget{parent}
{
    this->setWindowButtonFlags(ElaAppBarType::CloseButtonHint|ElaAppBarType::MinimizeButtonHint);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);

    this->setIsFixedSize(true);\

    // this->setFixedSize(QSize(488,600));
    this->setWindowTitle("[SCFG] -> [CFG]");
    // connect(this,)
    this->setselfMove(false);
    connect(gSettings,&GlobalSettings::pParentRectChanged,[=](){
        if(this->getselfMove()==true) return;
        programMove=true;
        QRect * rect=gSettings->getParentRect();
        this->move(rect->x()+rect->width()+15,rect->y());
        this->setFixedSize(QSize(488,rect->height()));
        programMove=false;
    });
    geneFunc=new BaseScrollPage();
    geneFunc->hide();

    QVBoxLayout * centerVLayout=new QVBoxLayout(this);


    ElaPushButton *authorBtn=new ElaPushButton("elecCap1taL",this);
    authorBtn->setIcon(QIcon(":/pic/Pic/elecCap1tal_Github.png"));

    authorBtn->setToolTip("GitHub: https://github.com/eLecCap1taL/scfg");
    connect(authorBtn,&ElaPushButton::clicked,[=](){
        QDesktopServices::openUrl(QUrl("https://github.com/eLecCap1taL/scfg"));
    });

    centerVLayout->addWidget(geneFunc->GenerateArea(this,new ElaText(tr("此功能来自"),this),authorBtn));

    ElaPushButton *selectFileBtn=new ElaPushButton(tr("选择"),this);

    // 创建标签栏和堆栈窗口
    QTabBar *tabBar = new QTabBar(this);
    tabBar->setObjectName("cfgTabBar");
    QStackedWidget *stackWidget = new QStackedWidget(this);
    stackWidget->setObjectName("cfgStackWidget");
    stackWidget->setFixedHeight(420);

    // 连接标签栏和堆栈窗口
    connect(tabBar, &QTabBar::currentChanged, stackWidget, &QStackedWidget::setCurrentIndex);

    connect(selectFileBtn,&ElaPushButton::clicked,[=](){
        QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("打开 SCFG 文件"),
            ".",
            tr("SCFG 文件 (*.scfg)")
        );
        if(!fileName.isEmpty()){
            auto gLocation = gSettings->getGLocation()->path();
            QString instancePath = gLocation + "/Instance";

            // 清理旧文件
            if(QFile(gLocation + "/Instance.scfg").exists())
                QFile::remove(gLocation + "/Instance.scfg");
            if(QDir(instancePath).exists()){
                QDir(instancePath).removeRecursively();
            }

            // 复制并处理文件
            QFile::copy(fileName, gLocation + "/Instance.scfg");
            QProcess *process = new QProcess(this);
            process->setProgram(gLocation + "/scfg.exe");
            process->setWorkingDirectory(gLocation);
            process->setArguments({"Instance.scfg"});
            process->start();
            process->waitForFinished(5000);

            // 清除现有标签和页面
            // Clear all tabs from tabBar
            while (tabBar->count() > 0) {
                tabBar->removeTab(0);
            }
            while (stackWidget->count() > 0) {
                QWidget *widget = stackWidget->widget(0);
                stackWidget->removeWidget(widget);
                widget->deleteLater();
            }

            // 加载Instance文件夹中的文件
            QDir instanceDir(instancePath);
            if (instanceDir.exists()) {
                QStringList filters; 
                filters << "*.cfg";
                QStringList files = instanceDir.entryList(filters, QDir::Files);
                foreach (QString file, files) {
                    // 创建页面和文本编辑
                    QWidget *page = new QWidget(stackWidget);
                    QVBoxLayout *pageLayout = new QVBoxLayout(page);
                    ElaPlainTextEdit *edit = new ElaPlainTextEdit(page);
                    edit->setReadOnly(true);
                    pageLayout->addWidget(edit);

                    // 读取文件内容
                    QFile cfgFile(instanceDir.filePath(file));
                    if (cfgFile.open(QIODevice::ReadOnly)) {
                        edit->setPlainText(cfgFile.readAll());
                        cfgFile.close();
                    }

                    // 添加到堆栈窗口和标签栏
                    stackWidget->addWidget(page);
                    tabBar->addTab(file);
                }
            }

            geneFunc->showSuccess(tr("成功"), tr("转换 SCFG 为 CFG 完成"));
        }
    });
    centerVLayout->addWidget(geneFunc->GenerateArea(this, new ElaText(tr("SCFG:"), this), selectFileBtn));
    centerVLayout->addWidget(tabBar);
    centerVLayout->addWidget(stackWidget);

    // QTextEdit *tipsText=new QTextEdit(tr("测试**Markdown**在**ElaText**上的~~应用~~"),this);
    // MarkdownHighlighter *hl=new MarkdownHighlighter(tipsText->document());
    // centerVLayout->addWidget(tipsText);

    ElaPushButton *openDirBtn=new ElaPushButton(tr("打开文件夹"),this);
    connect(openDirBtn,&ElaPushButton::clicked,[=](){
        auto gLocation=gSettings->getGLocation()->path();
        QDesktopServices::openUrl(QUrl::fromLocalFile(gLocation+"/Instance"));
    });
    centerVLayout->addWidget(openDirBtn);

    centerVLayout->addStretch();
}

void W_SCFGTransformer::resizeEvent(QResizeEvent *event)
{
    badges++;
    if(!programMove && badges>5){
        this->setselfMove(true);
    }
    QWidget::resizeEvent(event);

}

void W_SCFGTransformer::moveEvent(QMoveEvent *event)
{
    badges++;
    if(!programMove && badges>4){
        this->setselfMove(true);
    }
    QWidget::moveEvent(event);
}

W_SCFGTransformer::~W_SCFGTransformer()
{
    delete geneFunc;
}
