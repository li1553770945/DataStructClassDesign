#include "MainWindow.h"
#include "Btree.h"
#include <qmessagebox.h>
#include "ui_MainWindow.h"
#include <qevent>
#include <qpainter.h>
#include <qdebug.h>
#include "tree.h"
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	extern BTree* ancestor;
	ui.setupUi(this);
	tree = new Tree(ui.centralWidget);
	tree->setObjectName(QString::fromUtf8("Tree"));
	tree->setMinimumSize(QSize(1000, 850));
	ui.gridLayout_2->addWidget(tree, 1, 0, 1, 1);
	for (int i = 1; i <= 30; i++)
		ancestor->insertion(rand() % 1000);
	draw(ancestor->root);


}
void MainWindow::draw(BTreeNode* p)
{
	if (!p)
		return;
	int dy = 120;
	int width = 50, height = 110;
	extern BTree* ancestor;
	if (p == ancestor->root)
	{
		p->x = tree->width() / 2 - width / 2;
		p->y = 0;
		tree->area.clear();
		p->occupy_width = tree->width();
	}
	QPoint start = QPoint(p->x + width / 2, p->y + height / 2);
	//给控件设置上下文菜单策略
	p->setContextMenuPolicy(Qt::CustomContextMenu);
	p->setParent(tree);
	
	int son_num = p->n  +1;
	string text;
	for (int i = 0; i < p->n; i++)
	{
		text += to_string(p->keys[i]);
		if (i != p->n - 1)
		{
			text += '|\n';
		}
	}
	p->setText(QString(text.data()));
	p->setMaximumWidth(width);
	p->setGeometry(p->x, p->y, width, height);
	p->show();
	int i;
	for (i = 0; i < son_num; i++)
	{
		if (p->leaf == false)	
		{
			BTreeNode* son = p->C[i];
			son->occupy_width = p->occupy_width / son_num;
			son->x = p->x + width / 2 - p->occupy_width / 2 + son->occupy_width / 2 + i * son->occupy_width - width / 2;
			son->y = p->y + dy;
			QPoint end = QPoint(son->x + width / 2, son->y + height / 2);
			tree->area.push_back(Area(start, end));
			draw(son);
		}
		
	}
	if (p == ancestor->root)
	{
		tree->repaint();
	}
}
MainWindow::~MainWindow()
{

}
void MainWindow::resizeEvent(QResizeEvent* event)
{
	//cout << "拖动窗口" << endl;
	extern BTree* ancestor;
	draw(ancestor->root);
}
void mark(BTreeNode* p )
{
	p->setStyleSheet("border:2px solid blue;");
}
bool is_int(string s)
{
	if (s.length() == 0)
		return false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] > '9' || s[i] < '0')
			return false;
	}
	return true;
}
void MainWindow::on_Delete_clicked()
{
	if (is_int(ui.Data->text().toStdString()))
	{

		extern BTree* ancestor;
		BTreeNode* p = ancestor->search(ui.Data->text().toInt());
		if (p == NULL)
		{
			QMessageBox box(QMessageBox::Critical, u8"错误", u8"无法找到");
			box.exec();
		}
		else
		{
			p->deletion(ui.Data->text().toInt());
			draw(ancestor->root);
		}
	}
	else
	{
		QMessageBox box(QMessageBox::Critical, u8"错误", u8"必须输入整数");
		box.exec();
	}
}
void MainWindow::on_Find_clicked()
{
	if (is_int(ui.Data->text().toStdString()))
	{

		extern BTree* ancestor;
		BTreeNode* p = ancestor->search(ui.Data->text().toInt());
		if (p == NULL)
		{
			QMessageBox box(QMessageBox::Critical, u8"错误", u8"无法找到");
			box.exec();
		}
		else
		{
			mark(p);
		}
	}
	else
	{
		QMessageBox box(QMessageBox::Critical, u8"错误", u8"必须输入整数");
		box.exec();
	}
}
void MainWindow::on_Insert_clicked()
{
	if (is_int(ui.Data->text().toStdString()))
	{

		extern BTree* ancestor;
		ancestor->insertion(ui.Data->text().toInt());
		ui.Data->setText("");
		draw(ancestor->root);
	}
	else
	{
		QMessageBox box(QMessageBox::Critical, u8"错误", u8"只能插入整数");
		box.exec();
	}
	
}