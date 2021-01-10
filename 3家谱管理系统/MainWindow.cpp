#include "MainWindow.h"
#include "familytree.h"
#include <qmessagebox.h>
#include "ui_MainWindow.h"
#include <qevent>
#include <qpainter.h>
#include <qdebug.h>
#include "InfoWindow.h"
#include "tree.h"
#include "menu.h"
#include <qslider.h>
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	extern Node* ancestor;
	if (!ancestor)
	{
		QMessageBox box(QMessageBox::Critical, u8"错误", u8"无法打开文件");
		box.exec();
		exit(EXIT_FAILURE);
	}
	ui.setupUi(this);

	tree = new Tree(ui.centralWidget);
	tree->setObjectName(QString::fromUtf8("Tree"));
	tree->setMinimumSize(QSize(1000, 850));
	ui.gridLayout_2->addWidget(tree, 1, 0, 1, 1);
	draw(ancestor);
	front = back = NULL;
	//QSlider *slider = new QSlider(Qt::Horizontal);
	//slider->setMinimum(0);      // 设置滑动条的最小值
	//slider->setMaximum(100);   // 设置滑动条的最大值

	//slider->setValue(50); // 设置滑动条初始值

	////connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setLineEditValue(int)));

	//ui.gridLayout_2->addWidget(slider);

}
void MainWindow::on_ActionSave_triggered()
{
	extern Node* ancestor;
	
	if (save(ancestor))
	{
		QMessageBox box(QMessageBox::Information, u8"成功", u8"保存成功");
		box.exec();
	}
	else
	{
		QMessageBox box(QMessageBox::Critical, u8"错误", u8"无法打开文件");
		box.exec();
	}
}
void MainWindow::draw(Node* p)
{
	int dy = 100;
	int width = 20, height = 70;
	extern Node* ancestor;
	if (p == ancestor)
	{

		p->x = tree->width() / 2 - width / 2;
		p->y = 0;
		tree->area.clear();
		p->occupy_width = tree->width();
	}
	QPoint start = QPoint(p->x + width / 2, p->y + height / 2);
	QAction* a = new QAction;
	a->setText("测试");
	p->addAction(a);
	//给控件设置上下文菜单策略
	p->setContextMenuPolicy(Qt::CustomContextMenu);
	Menu* menu = new Menu(this);
	menu->main_prt = this;
	menu->node = p;
	disconnect(p, &QLabel::customContextMenuRequested,0,0);
	connect(p, &QLabel::customContextMenuRequested, [menu](const QPoint& pos) {menu->exec(QCursor::pos());});

	
	p->setParent(tree);
	
	p->setText(QString::fromLocal8Bit(p->get_name().data()));
	p->setMaximumWidth(width);
	p->setGeometry(p->x, p->y, width, height);
	p->show();
	int son_num = p->son.size();
	for (int i = 0; i < son_num; i++)
	{
		Node* son = p->son[i];
		son->occupy_width = p->occupy_width / son_num;
		son->x = p->x + width / 2 - p->occupy_width / 2 + son->occupy_width / 2 + i * son->occupy_width - width/2;
		son->y = p->y + dy;
		QPoint end = QPoint(son->x + width / 2, son->y + height / 2);
		tree->area.push_back(Area(start, end));
		draw(son);
	}
	if (p->mate && p->father || p->mate && p == ancestor)
	{
		p->mate->x = p->x + width;
		p->mate->y = p->y;
		draw(p->mate);
	}
	if (p == ancestor)
	{
		tree->repaint();
	}

}
void MainWindow::resizeEvent(QResizeEvent* event)
{
	//cout << "拖动窗口" << endl;
	extern Node* ancestor;
	draw(ancestor);
}
void MainWindow::on_ButtonName_clicked()
{

	extern Node* ancestor;
	find_name(ancestor, ui.Name->text().toLocal8Bit().data());
}
void MainWindow::on_ButtonDate_clicked()
{
	extern Node* ancestor;
	find_date(ancestor,ui.Year->text().toInt(), ui.Month->text().toInt(), ui.Day->text().toInt());
}
MainWindow::~MainWindow()
{
	
	extern Node* ancestor;
	clear_node(ancestor);
}
void MainWindow::on_ButtonRelative_clicked()
{
	if (front == NULL || back == NULL)
	{
		QMessageBox box(QMessageBox::Information, u8"提示", u8"请先设置好要比较的人");
		box.exec();
		return;
	}

	ui.Relative->setText(QString::fromLocal8Bit(relative(front,back).data()));
}
void MainWindow::add_front(Node* p)
{
	front = p;
	ui.Front->setText(QString::fromLocal8Bit(p->people->name.data())) ;
}
void MainWindow::add_back(Node* p)
{
	back = p;
	ui.Back->setText(QString::fromLocal8Bit(p->people->name.data()));
}