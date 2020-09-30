#include "content_widget.h"
/*
content_widget::content_widget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
*/


content_widget::content_widget(QWidget* parent)
    : QWidget(parent)
{
    //初始化
    //setAttribute(Qt::WA_TranslucentBackground); //表示窗口小部件应具有半透明背景，会导致窗口为黑色
    
    main_splitter = new QSplitter();
    main_splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); //Expanding表示缺省是合理的大小，但部件允许缩小并且可用
    main_splitter->setOrientation(Qt::Horizontal);           //水平线
    main_splitter->setHandleWidth(1);                        //设置分界线的宽度

    this->initLeft();
    this->initRight();
    this->initRightTop();
    this->initRightCenter();
    this->initRightCenterFuntion();
    this->initRightButton();

    right_splitter->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);          //缺省大小是唯一可以接收的改变，因此部件不能放大也不能缩小
    right_splitter->setOrientation(Qt::Vertical);            //垂直线
    right_splitter->setHandleWidth(1);

    right_top_widget->setFixedSize(250, 130);                //设置窗体大小
    right_center_widget->setFixedSize(250, 90);
    right_botton_widget->setFixedSize(250, 15);
    right_splitter->addWidget(right_top_widget);
    right_splitter->addWidget(right_center_widget);
    right_splitter->addWidget(right_center_funtion_widget);
    right_splitter->addWidget(right_botton_widget);

    main_splitter->addWidget(left_widget);
    main_splitter->addWidget(right_splitter);

    //禁止拖动？
    for (int i = 0; i < right_splitter->count(); i++)               //？
    {
        //分界线是QSplitterHandle 类对象
        //如果有多条分界线,怎么操作第一条分界线
        QSplitterHandle* handle = right_splitter->handle(i);
        handle->setEnabled(false);
    }

    /*博客中是这样写的*/
    //主分割只有一条分界线
    QSplitterHandle* handle = main_splitter->handle(1);
    handle->setEnabled(false);

    //源码中写法
    //for (int i = 0; i < main_splitter->count(); i++)
    //{
    //    QSplitterHandle* handle = main_splitter->handle(i);
    //    handle->setEnabled(false);
    //}

    //水平
    QHBoxLayout* main_layout = new QHBoxLayout();
    main_layout->addWidget(main_splitter);
    main_layout->setSpacing(0);
    main_layout->getContentsMargins(0, 0, 0, 0);

    this->setLayout(main_layout);
    this->translateLanguage();

}

content_widget::~content_widget()
{
}

void content_widget::initLeft()
{
    left_widget = new QWidget();
    label = new QLabel();
    suggest_label = new QLabel();
    system_safe_label = new QLabel();
    power_button = new QPushButton();

    left_widget->resize(650, 500);

    QPixmap label_pixmap("./Resources/img/contentWidget/computer.png");         //给标签贴图
    label->setPixmap(label_pixmap);
    label->setFixedSize(label_pixmap.size());

    QFont suggest_font = suggest_label->font();                                 //设置字体
    suggest_font.setPointSize(12);
    suggest_font.setBold(true);
    suggest_label->setFont(suggest_font);
    suggest_label->setObjectName("grayLabel");

    QFont system_safe_font = system_safe_label->font();
    system_safe_font.setBold(true);
    system_safe_label->setFont(system_safe_font);
    system_safe_label->setObjectName("grayLabel");

    QPixmap pixmap("./Resources/img/contentWidget/power.png");
    power_button->setIcon(pixmap);
    power_button->setIconSize(pixmap.size());
    power_button->setFixedSize(180, 70);
    power_button->setObjectName("greenButton");
    //改变字体大小
    QFont power_font = power_button->font();
    power_font.setPointSize(16);
    power_button->setFont(power_font);

    //排版
    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addWidget(suggest_label);
    v_layout->addWidget(system_safe_label);
    v_layout->addStretch();
    v_layout->setSpacing(15);
    v_layout->setContentsMargins(0, 20, 0, 0);

    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(label, 0, Qt::AlignTop);
    h_layout->addLayout(v_layout);
    h_layout->addStretch();
    h_layout->setSpacing(20);
    h_layout->setContentsMargins(30, 20, 0, 0);

    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->addLayout(h_layout);
    main_layout->addWidget(power_button, 0, Qt::AlignCenter);
    main_layout->addStretch();
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    left_widget->setLayout(main_layout);
}


void content_widget::initRight()
{
    right_splitter = new QSplitter();
}


void content_widget::initRightTop()
{
    right_top_widget = new QWidget();
    login_button = new QPushButton();
    priv_label = new QLabel();
    info_label = new QLabel();
    privilege_label = new QLabel();
    register_button = new QPushButton();
    safe_button = new QPushButton();
    tab_button = new QPushButton();
    pet_button = new QPushButton();
    lottery_button = new QPushButton();
    cloud_five_button = new QPushButton();
    caipiao_button = new QPushButton();

    login_button->setFixedSize(240, 60);
    login_button->setObjectName("loginButton");
    QFont login_font = login_button->font();
    login_font.setBold(true);
    login_font.setPointSize(12);
    login_button->setFont(login_font);

    priv_label->setPixmap(QPixmap("./Resources/img/contentWidget/priv.png"));
    QPixmap safe_pixmap("./Resources/img/contentWidget/360.png");
    safe_button->setIcon(safe_pixmap);
    safe_button->setFixedSize(safe_pixmap.size());
    QPixmap tab_pixmap("./Resources/img/contentWidget/tab.png");
    tab_button->setIcon(tab_pixmap);
    tab_button->setFixedSize(tab_pixmap.size());
    QPixmap pet_pixmap("./Resources/img/contentWidget/pet.png");
    pet_button->setIcon(pet_pixmap);
    pet_button->setFixedSize(tab_pixmap.size());
    QPixmap lottery_pixmap("./Resources/img/contentWidget/lottery.png");
    lottery_button->setIcon(lottery_pixmap);
    lottery_button->setFixedSize(lottery_pixmap.size());
    QPixmap cloud_five_pixmap("./Resources/img/contentWidget/cloud_five.png");
    cloud_five_button->setIcon(cloud_five_pixmap);
    cloud_five_button->setFixedSize(cloud_five_pixmap.size());
    QPixmap caipiao_pixmap("./Resources/img/contentWidget/caipiao.png");
    caipiao_button->setIcon(caipiao_pixmap);
    caipiao_button->setFixedSize(caipiao_pixmap.size());

    //设置鼠标点击时的状态
    register_button->setCursor(Qt::PointingHandCursor);
    safe_button->setCursor(Qt::PointingHandCursor);
    tab_button->setCursor(Qt::PointingHandCursor);
    pet_button->setCursor(Qt::PointingHandCursor);
    lottery_button->setCursor(Qt::PointingHandCursor);
    cloud_five_button->setCursor(Qt::PointingHandCursor);
    caipiao_button->setCursor(Qt::PointingHandCursor);

    //按钮的样式
    register_button->setObjectName("blueButton");
    safe_button->setObjectName("transparentButton");
    tab_button->setObjectName("transparentButton");
    pet_button->setObjectName("transparentButton");
    lottery_button->setObjectName("transparentButton");
    cloud_five_button->setObjectName("transparentButton");
    caipiao_button->setObjectName("transparentButton");

    //布局
    QHBoxLayout* login_layout = new QHBoxLayout();
    login_layout->addWidget(login_button);
    login_layout->addStretch();           //按比例分配空余空间
    login_layout->setContentsMargins(15, 0, 0, 0);

    QHBoxLayout* register_layout = new QHBoxLayout();
    register_layout->addStretch();
    register_layout->addWidget(priv_label);
    register_layout->addWidget(info_label);
    register_layout->addWidget(register_button);
    register_layout->addStretch();
    register_layout->setSpacing(5);
    register_layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout* privilege_layout = new QHBoxLayout();
    privilege_layout->addStretch();
    privilege_layout->addWidget(privilege_label);
    privilege_layout->addWidget(safe_button);
    privilege_layout->addWidget(tab_button);
    privilege_layout->addWidget(pet_button);
    privilege_layout->addWidget(lottery_button);
    privilege_layout->addWidget(cloud_five_button);
    privilege_layout->addWidget(caipiao_button);
    privilege_layout->addStretch();
    privilege_layout->setSpacing(8);
    privilege_layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->addStretch();
    main_layout->addLayout(login_layout);
    main_layout->addLayout(register_layout);
    main_layout->addLayout(privilege_layout);
    main_layout->addStretch();
    main_layout->setSpacing(5);
    main_layout->setContentsMargins(10, 10, 10, 10);

    //两信号
    //connect(login_button, SIGNAL(clicked()), this, SIGNAL(showLoginDialog()));
    //connect(register_button, SIGNAL(clicked()), this, SIGNAL(showRegisterDialog()));

    right_top_widget->setLayout(main_layout);
}


void content_widget::initRightCenter()
{
    right_center_widget = new QWidget();
    fireproof_button = new QToolButton();
    triggerman_button = new QToolButton();
    net_shop_button = new QToolButton();
    line_label_1 = new QLabel();
    line_label_2 = new QLabel();
    line_label_1->setFixedWidth(10);
    line_label_2->setFixedWidth(10);

    line_label_1->installEventFilter(this);     //事件过滤器就是接收所有被发送到这个对象的事件的对象
    line_label_2->installEventFilter(this);

    fireproof_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);     //文本显示在图标下边
    triggerman_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    net_shop_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QPixmap fireproof_pixmap("./Resources/img/contentWidget/fireproof.png");
    fireproof_button->setIcon(fireproof_pixmap);
    fireproof_button->setIconSize(fireproof_pixmap.size());
    fireproof_button->setFixedSize(fireproof_pixmap.width() + 25, fireproof_pixmap.height() + 25);

    QPixmap triggerman_pixmap("./Resources/img/contentWidget/triggerman.png");
    triggerman_button->setIcon(triggerman_pixmap);
    triggerman_button->setIconSize(triggerman_pixmap.size());
    triggerman_button->setFixedSize(triggerman_pixmap.width() + 25, triggerman_pixmap.height() + 25);

    QPixmap net_shop_pixmap("./Resources/img/contentWidget/net_shop.png");
    net_shop_button->setIcon(net_shop_pixmap);
    net_shop_button->setIconSize(net_shop_pixmap.size());
    net_shop_button->setFixedSize(net_shop_pixmap.width() + 25, net_shop_pixmap.height() + 25);

    fireproof_button->setObjectName("transparentToolButton");
    triggerman_button->setObjectName("transparentToolButton");
    net_shop_button->setObjectName("transparentToolButton");

    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(fireproof_button);
    h_layout->addWidget(line_label_1);
    h_layout->addWidget(triggerman_button);
    h_layout->addWidget(line_label_2);
    h_layout->addWidget(net_shop_button);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(0, 0, 0, 0);

    right_center_widget->setLayout(h_layout);

}

void content_widget::initRightCenterFuntion()
{

    right_center_funtion_widget = new QWidget();
    funtion_label = new QLabel();
    more_button = new QPushButton();

    QFont funtion_font = funtion_label->font();
    funtion_font.setBold(true);
    funtion_label->setFont(funtion_font);
    funtion_label->setObjectName("infoLabel");
    more_button->setFixedSize(50, 25);
    more_button->setObjectName("blueButton");
    more_button->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(funtion_label);
    h_layout->addStretch();
    h_layout->addWidget(more_button);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(10, 5, 0, 0);

    QStringList string_list;
    string_list << "./Resources/img/contentWidget/recovery.png" << "./Resources/img/contentWidget/mobile.png" << "./Resources/img/contentWidget/game_box.png" << "./Resources/img/contentWidget/desktop.png"
        << "./Resources/img/contentWidget/net_repair.png" << "./Resources/img/contentWidget/auto_run.png" << "./Resources/img/contentWidget/net_speed.png" << "./Resources/img/contentWidget/net_pretext.png"
        << "./Resources/img/contentWidget/first_add.png";

    //网格布局
    QGridLayout* grid_layout = new QGridLayout();
    for (int i = 0; i < string_list.size(); i++)
    {
        QToolButton* tool_button = new QToolButton();
        tool_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        QPixmap button_pixmap(string_list.at(i));
        tool_button->setIcon(button_pixmap);
        tool_button->setIconSize(button_pixmap.size());
        tool_button->setFixedSize(button_pixmap.width() + 50, button_pixmap.height() + 35);
        tool_button->setObjectName("functionButton");

        button_list.append(tool_button);
        grid_layout->addWidget(tool_button, i / 3, i % 3);
    }

    grid_layout->setSpacing(0);
    grid_layout->setContentsMargins(5, 0, 5, 5);

    QVBoxLayout* v_layout = new QVBoxLayout();
    v_layout->addLayout(h_layout);
    v_layout->addLayout(grid_layout);
    v_layout->addStretch();
    v_layout->setSpacing(10);
    v_layout->setContentsMargins(0, 0, 0, 0);

    right_center_funtion_widget->setLayout(v_layout);

}

void content_widget::initRightButton()
{
    right_botton_widget = new QWidget();
    icon_label = new QLabel();
    connect_label = new QLabel();
    version_label = new QLabel();
    version_button = new QPushButton();

    QPixmap label_pixmap("./Resources/img/contentWidget/cloud.png");
    icon_label->setPixmap(label_pixmap);
    icon_label->setFixedSize(label_pixmap.size());

    QPixmap pixmap("./Resources/img/contentWidget/version.png");
    version_button->setIcon(pixmap);
    version_button->setIconSize(pixmap.size());
    version_button->setObjectName("transparentButton");

    QHBoxLayout* botton_layout = new QHBoxLayout();
    botton_layout->addWidget(icon_label);
    botton_layout->addWidget(connect_label);
    botton_layout->addStretch();
    botton_layout->addWidget(version_label);
    botton_layout->addWidget(version_button);
    botton_layout->setSpacing(5);
    botton_layout->setContentsMargins(10, 0, 10, 0);
    right_botton_widget->setLayout(botton_layout);

}

void content_widget::translateLanguage()
{
    suggest_label->setText(tr("suggest"));
    system_safe_label->setText(tr("system safe"));
    power_button->setText(tr("power"));

    login_button->setText(tr("login home"));
    info_label->setText(tr("show beautifull icon"));
    register_button->setText(tr("register"));
    privilege_label->setText(tr("privilege power"));

    fireproof_button->setText(tr("fireproof"));
    triggerman_button->setText(tr("triggerman"));
    net_shop_button->setText(tr("net shop"));

    funtion_label->setText(tr("function"));
    more_button->setText(tr("more"));
    button_list.at(0)->setText(tr("recovery"));
    button_list.at(1)->setText(tr("mobile"));
    button_list.at(2)->setText(tr("game box"));
    button_list.at(3)->setText(tr("desktop"));
    button_list.at(4)->setText(tr("net repair"));
    button_list.at(5)->setText(tr("auto run"));
    button_list.at(6)->setText(tr("net speed"));
    button_list.at(7)->setText(tr("net pretext"));
    button_list.at(8)->setText(tr("first add"));

    connect_label->setText(tr("connect success"));
    version_label->setText(tr("version"));
}

bool content_widget::eventFilter(QObject* obj, QEvent* event)
{
    if (obj == line_label_1 || obj == line_label_2)
    {
        if (event->type() == QEvent::Paint)
        {
            int label_height_1 = line_label_1->height();
            int label_width_1 = line_label_1->width();
            QPainter painter(line_label_1);
            painter.setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
            painter.drawLine(label_width_1 / 2, 0, label_width_1 / 2, label_height_1);

            int label_height_2 = line_label_2->height();
            int label_width_2 = line_label_2->width();
            QPainter painter2(line_label_2);
            painter2.setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
            painter2.drawLine(label_width_2 / 2, 0, label_width_2 / 2, label_height_2);
        }
    }
    return QWidget::eventFilter(obj, event);
}