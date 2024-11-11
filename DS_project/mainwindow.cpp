#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "info_dialog.h"

/* Qt头文件 */
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegularExpressionValidator>
#include <QDebug>

#define Infinity 2000
#define MAX 40
#define key 22

mgraph initgraph();
int locatevex(mgraph c,int v);
int allpath(mgraph c, int start, int end);
void path(mgraph c,int m,int n,int k);
QString transtring;

mgraph campus;  // 图变量（校园）
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];   // 定义全局变量存储最小路径
int pathh[MaxVertexNum][MaxVertexNum];      // 定义存储路径



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::initUI()
{
    ui->CB_departure->addItem("大学城校区(1-16)");
    ui->CB_departure->addItem("国际校区(17-33)");
    ui->CB_destination->addItem("大学城校区(1-16)");
    ui->CB_destination->addItem("国际校区(17-33)");


}


void MainWindow::on_btn1_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C12到C17宿舍,高校学生宿舍是在校大学生学习生活的重要场所，是落实立德树人根本任务、开展全员全过程全方位育人的重要阵地。"));    // 设置介绍文字

    infoWindow->exec();


}


void MainWindow::on_CB_departure_currentTextChanged(const QString &arg1)
{
    if (arg1=="大学城校区(1-16)")
    {
        QRegularExpression ediName("^(?:[1-9]|1[0-6])$");
        ui->departureEdit->setValidator(new QRegularExpressionValidator(ediName,this));
        ui->departureEdit->setPlaceholderText("请输入1-16的数字");
    }
    else if (arg1=="国际校区(17-33)")
    {
        QRegularExpression ediName("^(?:1[7-9]|2[0-9]|3[0-3])$");
        ui->departureEdit->setValidator(new QRegularExpressionValidator(ediName,this));
        ui->departureEdit->setPlaceholderText("请输入17-33的数字");
    }


}


void MainWindow::on_CB_destination_currentTextChanged(const QString &arg1)
{
    if (arg1=="大学城校区(1-16)")
    {
        QRegularExpression ediName("^(?:[1-9]|1[0-6])$");
        ui->destinationEdit->setValidator(new QRegularExpressionValidator(ediName,this));
        ui->destinationEdit->setPlaceholderText("请输入1-16的数字");
    }
    else if (arg1=="国际校区(17-33)")
    {
        QRegularExpression ediName("^(?:1[7-9]|2[0-9]|3[0-3])$");
        ui->destinationEdit->setValidator(new QRegularExpressionValidator(ediName,this));
        ui->destinationEdit->setPlaceholderText("请输入17-33的数字");
    }

}


void MainWindow::on_btn2_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C9到C11宿舍,高校学生宿舍是在校大学生学习生活的重要场所，是落实立德树人根本任务、开展全员全过程全方位育人的重要阵地。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn3_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("第二食堂：食堂不仅提供多样化的菜品选择，还以价格合理、卫生安全为特色，满足师生的日常饮食需求。"
                            "医疗保健中心：医疗保健中心是学校为学生和教职工提供基本医疗和健康服务的场所，通常由校医和护士团队负责。医疗保健中心在校园内，方便师生在日常生活中获得基础医疗支持和紧急处理。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn4_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("生活区运动场："
                            "第一食堂：食堂不仅提供多样化的菜品选择，还以价格合理、卫生安全为特色，满足师生的日常饮食需求。"));    // 设置介绍文字

    infoWindow->exec();
}
void MainWindow::on_btn5_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("C6到C8宿舍：高校学生宿舍是在校大学生学习生活的重要场所，是落实立德树人根本任务、开展全员全过程全方位育人的重要阵地。"
                            "超市："));    // 设置介绍文字

    infoWindow->exec();
}
void MainWindow::on_btn6_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("教师公寓。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn7_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("体育馆："
                            "游泳馆："
                            "网球馆："));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn8_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("教学区运动场：运动场是学校为学生和教职工提供体育锻炼和运动比赛的场所。它通常包括多种运动设施，是校园生活中重要的健身和社交空间。"
                            "篮球场：打篮球的场所。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn9_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("图书馆：是搜集、整理、收藏图书资料以供人阅览、参考的场所。"
                            "音乐厅：是举行音乐会及音乐相关活动的场所，是人们感受音乐魅力的地方。通常是由音乐大厅和小剧场等组成，装潢典雅，布局合适。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn10_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("A1到A5教学楼：关系到学校人才培养的质量，同时它作为载体还是一个社会的教育思想与价值观念、经济与文化面貌等的具体体现者，因此其重要性不言而喻。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn11_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B9到B11教学楼："));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn12_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("情人岛："));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn13_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("学术报告厅："
                            "B3:"
                            "B5:"
                            "B7:"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn14_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B4:广州市行业工程技术研究中心 水资源与水环境、华南理工大学环境科学与工程学院、教育部重点实验室 工业聚集区污染控制与生态修复、广东省高等学校重点实验室 污染控制与生态修复、环境科学与工程 广东省一级重点学科、华南理工大学粤海水技术研究中心、中国环境科学学会 挥发性有机物污染防治专业委员会、博士后科研流动站 环境科学与工程、广东省科学技术厅 国际科技合作基地。"
                            "B6:"
                            "B8:"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn15_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B12:华南理工大学分析测试中心（南校区）、广东省生物医学工程重点实验室、特种功能材料教育部重点实验室、千人计划“前孵化器”、医用植入器械国家工程实验室、材料科学与工程学院-生物医学工程系、国家人体组织功能重建工程技术研究中心、国家重点实验室。"
                            "B2:医学院。"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn16_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B1:南校区后勤办公室、南校区人事组织办公室、南校区管委会办公室、档案馆、南校区教学与实验室管理办公室、师生服务中心（大学城）、华南理工大学国际教育学院。"));    // 设置介绍文字

    infoWindow->exec();
}

///////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_btn17_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("A3运动场"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn18_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("A1公交站"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn19_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B1,C1"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn20_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("B2运动场"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn21_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("D1,E1"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn22_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("D3公共实验楼，E3图书馆"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn23_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("A4："
                            "A5校医院："));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn24_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("D5餐厅"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn25_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("E5双创中心"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn26_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("体育馆："));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn27_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("附属小学幼儿园"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn28_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("F5书院区"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn29_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("G5教师公寓"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn30_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("F3"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn31_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("F1"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn32_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("G2,G3,G3餐厅"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_btn33_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("G1"));    // 设置介绍文字

    infoWindow->exec();
}


void MainWindow::on_ExitBtn_clicked()
{
    this->close();
}


void MainWindow::on_CampusIntroBtn_clicked()
{
    QDialog *infoWindow = new info_dialog(this);
    QTextBrowser *textBrowser = infoWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/administration_building.jpeg");                             // 加载照片
    QLabel *label = infoWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

    label->setPixmap(*img);
        // 设置介绍图片
    textBrowser->setText(tr("华南理工大学（South China University of Technology），简称“华南理工（SCUT）”，位于广东省广州市，学校为全日制普通高等学校，主管部门是国务院教育行政部门，由国务院教育行政部门与广东省人民政府共建 。位列国家“双一流” ，“211工程”，“985工程” ，入选高等学校学科创新引智计划， 卓越工程师教育培养计划 ，101计划 ，首批高等学校科技成果转化和技术转移基地 [102]，是中国政府奖学金来华留学生接收院校 ，教育部来华留学示范基地 ；为建筑老八校、中英大学工程教育与研究联盟成员 ，首批“未来技术学院”建设高校 。"
"华南理工大学原名华南工学院，办学历史最早可追溯至1918年成立的广东省立第一甲种工业学校，几经调整，于1938年并入国立中山大学工学院，后与1944年复办的广东省立工业专科学校一并调整至华南工学院。正式组建于1952年全国高等院校调整时期，是新中国“四大工学院”之一；1960年成为全国重点大学；1981年经国务院批准为首批博士和硕士学位授予单位；1988年1月，更名为华南理工大学 。"
"学校分为五山校区、大学城校区和广州国际校区三个校区 ；截至2023年12月，学校占地学校占地面积388.05万平方米，学校教学科研仪器设备总值41.47亿元 ；截至2024年8月，学校有39个学院，3个附属医院 [31]。截至2024年4月，学校有90个专业，有博士学位授权一级学科点34个，硕士学位授权一级学科点39个，国家重点学科7个，国家级一流专业建设点60个。学校有全日制在校本科生27557人，研究生23767人 "));    // 设置介绍文字

    infoWindow->exec();
}

// /**
//  * @brief 图初始化函数
//  * @return mgraph 地图数据结构
//  */
// mgraph initgraph()
// {
//     int i,j;
//     mgraph c;
//     c.vexnum=?????????;            // 顶点个数，即地点个数
//     c.arcnum=?????????;            // 边的个数，即路径个数

//     for(i=1; i<=key; i++)   // 依次设置顶点编号
//     {
//         c.vexs[i].position = i;
//     }

//     /* 依次输入顶点信息 */
//     strcpy(c.vexs[1].name,"行政楼");
//     strcpy(c.vexs[2].name,"第二行政办公区");
//     strcpy(c.vexs[3].name,"第一教学楼");
//     strcpy(c.vexs[4].name,"第二教学楼");
//     strcpy(c.vexs[5].name,"第三教学楼");
//     strcpy(c.vexs[6].name,"第四教学楼");
//     strcpy(c.vexs[7].name,"第五教学楼");
//     strcpy(c.vexs[8].name,"第六教学楼");
//     strcpy(c.vexs[9].name,"艺术大楼");
//     strcpy(c.vexs[10].name,"实训大楼");
//     strcpy(c.vexs[11].name,"红砖楼");
//     strcpy(c.vexs[12].name,"体育馆");
//     strcpy(c.vexs[13].name,"图书馆");
//     strcpy(c.vexs[14].name,"校史馆");
//     strcpy(c.vexs[15].name,"学术交流中心");
//     strcpy(c.vexs[16].name,"高水平运动中心");
//     strcpy(c.vexs[17].name,"通用实验厂房");
//     strcpy(c.vexs[18].name,"附属实验学校");
//     strcpy(c.vexs[19].name,"xx苑");
//     strcpy(c.vexs[20].name,"xx苑");
//     strcpy(c.vexs[21].name,"xx苑");
//     strcpy(c.vexs[22].name,"xx苑");

//     for (i=1; i<=key; i++) {
//         for (j=1;j<=key;j++) {
//             c.arcs[i][j].adj=Infinity;  // 先初始化图的邻接矩阵
//         }

//         c.arcs[1][2].adj=30;c.arcs[1][4].adj=30;c.arcs[1][19].adj=35;c.arcs[2][5].adj=5;c.arcs[3][5].adj=10;
//         c.arcs[3][4].adj=10;c.arcs[3][11].adj=10;c.arcs[4][6].adj=15;c.arcs[5][12].adj=30;c.arcs[6][7].adj=55;
//         c.arcs[6][15].adj=30;c.arcs[6][18].adj=15;c.arcs[6][22].adj=60;c.arcs[7][8].adj=30;c.arcs[7][13].adj=35;
//         c.arcs[7][22].adj=40;c.arcs[8][13].adj=40;c.arcs[8][15].adj=35;c.arcs[8][20].adj=30;c.arcs[9][10].adj=20;
//         c.arcs[9][13].adj=45;c.arcs[9][20].adj=60;c.arcs[10][17].adj=70;c.arcs[11][14].adj=10;c.arcs[12][20].adj=45;
//         c.arcs[13][17].adj=35;c.arcs[14][15].adj=10;c.arcs[16][18].adj=10;c.arcs[16][19].adj=15;c.arcs[17][21].adj=55;
//         c.arcs[21][22].adj=50;
//     }

//     /* 邻接矩阵是对称矩阵，对称赋值(无向图需要对称赋值) */
//     for(i=1;i<=key;i++)
//     {
//         for(j=1;j<=key;j++)
//         {
//             c.arcs[j][i].adj=c.arcs[i][j].adj;
//         }
//     }

//     return c;
// }


/**
 * @brief 查找景点在图中的序号
 * @param c
 * @param v
 * @return i 顶点序号; -1 没有找到该顶点
 */
int locatevex(mgraph c,int v)
{
    int i;
    for (i=1;i<=c.vexnum;i++)
        if (v==c.vexs[i].position)  return i;  // 找到，返回顶点序号i
    return -1;  // 没有找到该顶点
}


/**
 * @brief 查找并输出序号为m,n景点间的长度不超过8个景点的路径
 * @param c
 * @param m
 * @param n
 * @param k
 */
void MainWindow::path(mgraph c, int m, int n, int k)
{
    int s, t=k+1, length=0;      // t用于存放路径上下一个顶点对应的d[]数组元素的下标

    if (d[k] == n && k<8) {      // 若d[k]是终点n且景点个数<=8,则输出该路径
        for (s=0; s<k; s++) {    // 计算路径长度
            length = length+c.arcs[d[s]][d[s+1]].adj;
        }

        if (length <= 250) {        // 打印路径长度小于定长的路径
            for (s=0; s<k; s++) {   // 输出该路径。s=0时为起点m
                transtring.append(QString::number(c.vexs[d[s]].position) + "-->");
            }

            transtring.append(QString::number(c.vexs[d[s]].position));  // 输出最后一个景点名（即顶点n的名字，此时s==k）
            ui->textBrowser_2->append(transtring);
            ui->textBrowser_2->append("总路线长为" + QString::number(length));
        }

        transtring.clear();

    } else {
        s = 1;

        while (s <= c.vexnum) {                                       // 从第m个顶点，试探所有顶点是否有路径
            if ((c.arcs[d[k]][s].adj<Infinity) && (visited[s]==0)) {  // 顶点m到顶点s有边(权值不为无穷大)，且未被访问
                visited[s]=1;
                d[k+1]=s;       // 存储顶点编号
                path(c,m,n,t);
                visited[s]=0;   // 将找到的路径上顶点的访问标志重新设置为0，以用于试探新的路径
            }

            s++;    // 试探从下一个顶点s开始是否有到终点的路径
        }
    }
}


/**
 * @brief 查找两景点间的所有路径
 * @param c     地图数据结构
 * @param start 起点序号
 * @param end   终点序号
 */
void MainWindow::allpath(mgraph c, int start, int end)
{
    int k, m, n;
    m=locatevex(c, start);   // locatevex 确定该顶点是否存在。若存在，返回该顶点编号。
    n=locatevex(c, end);
    d[0] = m;                 // 存储路径起点m（int d[]数组是全局变量）

    for (k=0; k<key; k++) {    // 全部顶点访问标志初值设为0
        visited[k] = 0;
    }

    visited[m] = 1;           // 第m个顶点访问标志设置为1
    path(c, m, n, 0);          // 调用程序。k=1，对应起点d[1]==m。k为d[]数组下标
}


/**
 * @brief 任意两点间最短距离
 * @param c     地图数据结构
 * @param start 起点序号
 * @param end   终点序号
 */
void MainWindow::shortdistance(mgraph c, int start, int end)
{
    int i, j;
    i = start;
    j = end;

    floyd(c);   // 调用floyd算法

    transtring.append(QString::number(start) + "-->");

    while (pathh[start][end] != end) {
        transtring.append(QString::number(pathh[start][end]) + "-->");
        start = pathh[start][end];
    }

    transtring.append(QString::number(end));
    ui->textBrowser_2->append(transtring);
    ui->textBrowser_2->append("最短路线长为" + QString::number(shortest[i][j]));

    transtring.clear();
}


/**
 * @brief 弗洛伊德算法
 * @param c 地图数据结构
 */
void MainWindow::floyd(mgraph c)
{
    int i, j, k;
    for (i=1; i<=key; i++) {   // 将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1
        for (j=1; j<=key; j++) {
            shortest[i][j] = c.arcs[i][j].adj;
            pathh[i][j] = j;
        }
    }

    for (k=1; k<=key; k++) {   // 核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改
        for (i=1; i<=key; i++) {
            for (j=1; j<=key; j++) {
                if (shortest[i][j] > shortest[i][k]+shortest[k][j]) {
                    shortest[i][j] = shortest[i][k]+shortest[k][j];
                    pathh[i][j] = pathh[i][k];  // 记录一下所走的路，P数组用来存放前驱顶点
                }
            }
        }
    }
}


/**
 * @brief 可选路径按钮实现，显示从起点到终点的所有可达路径
 */
void MainWindow::on_searchRouteBtn_clicked()
{
        int start = ui->departureEdit->text().toInt();   // 获取起点位置
        int end = ui->destinationEdit->text().toInt();    // 获取终点位置

        ui->textBrowser_2->clear();                   // 清除浏览框里的文本

        if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
            allpath(campus, start, end);    // 可选路径搜索
        }
}

/**
 * @brief 最短路径按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_seachShortestBtn_clicked()
{
        int start = ui->departureEdit->text().toInt();   // 获取起点位置
        int end = ui->destinationEdit->text().toInt();    // 获取终点位置

        ui->textBrowser_2->clear();                  // 清除浏览框里的文本

        if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
            shortdistance(campus, start, end);
}
}

