#pragma once
#include "menu.h"
#include <QtWidgets/QMainWindow>
#include "InfoWindow.h"
#include "MainWindow.h"
#include "qmessagebox.h"
#include "familytree.h"
void Menu::del()
{
	void del_fun(Node * p);
	extern Node* ancestor;
	if (node == ancestor)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"ʼ�治�ܱ�ɾ��");
		box.exec();
		return;
	}
	if (node == main_prt->front)
	{
		Node* temp = new Node;
		temp->people = new People;
		temp->people->name = "";
		main_prt->add_front(temp);
		main_prt->front = NULL;
		delete temp;
	}
	if (node == main_prt->back)
	{
		Node* temp = new Node;
		temp->people = new People;
		temp->people->name = "";
		main_prt->add_back(temp);
		main_prt->back = NULL;
		delete temp;
	}
	del_fun(node);
	extern Node* ancestor;
	main_prt->draw(ancestor);
	
}
void Menu::edit()
{
	InfoWindow* window = new InfoWindow(main_prt);
	connect(this, &Menu::Send, window, &InfoWindow::Receive);
	emit Send(node->people);
	window->exec();
	extern Node* ancestor;
	main_prt->draw(ancestor);
	if (node == main_prt->front)
	{
		main_prt->add_front(node);
	}
	if(node==main_prt->back)
	{
		main_prt->add_back(node);
	}
}
Menu::Menu(QWidget* parent = nullptr) :QMenu(parent)
{
	QAction* add_mate_action = new QAction(u8"�����ż", this);
	QAction* add_son_action = new QAction(u8"��Ӻ���", this);
	QAction* edit_action = new QAction(u8"��ϸ��Ϣ���༭", this);
	QAction* de_action = new QAction(u8"ɾ��", this);
	QAction* add_front = new QAction(u8"��Ϊ�Ƚ�ǰ��", this);
	QAction* add_back = new QAction(u8"��Ϊ�ȽϺ���", this);
	this->addAction(add_mate_action);
	this->addAction(add_son_action);
	this->addAction(edit_action);
	this->addAction(de_action);
	this->addAction(add_front);
	this->addAction(add_back);
	connect(add_mate_action, &QAction::triggered, this, &Menu::add_mate);
	connect(add_son_action, &QAction::triggered, this, &Menu::add_son);
	connect(edit_action, &QAction::triggered, this, &Menu::edit);
	connect(de_action, &QAction::triggered, this, &Menu::del);
	connect(add_front, &QAction::triggered, this, &Menu::add_front);
	connect(add_back, &QAction::triggered, this, &Menu::add_back);
}
MainWindow* Menu::main_prt = NULL;
void Menu::add_mate()
{
	if (node->mate != NULL)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"ÿ��ֻ����һ����ż������");
		box.exec();
		return;
	}
	InfoWindow* window = new InfoWindow(main_prt);
	People* temp = new People;
	connect(this, &Menu::Send, window, &InfoWindow::Receive);
	emit Send(temp);
	window->exec();
	if (temp->name != string(""))
	{
		if (!node->add_mate(temp))
		{
			QMessageBox box(QMessageBox::Critical, u8"����", u8"ÿ��ֻ����һ����ż������");
			box.exec();
			delete temp;
		}
	}
	else
	{
		delete temp;
	}
	extern Node* ancestor;
	main_prt->draw(ancestor);

}
void Menu::add_son()
{
	InfoWindow* window = new InfoWindow(main_prt);
	People* temp = new People;
	disconnect(this, &Menu::Send, 0, 0);
	connect(this, &Menu::Send, window, &InfoWindow::Receive);
	emit Send(temp);
	window->exec();
	if (temp->name != string(""))
	{
		if (!node->add_son(temp))
		{
			QMessageBox box(QMessageBox::Critical, u8"����", u8"���ʧ�ܣ����Ӳ������ڸ��׳�����Ҳ�����ڸ���ȥ�������");
			box.exec();
			delete temp;
			return;
		}
	}
	else
	{
		delete temp;
	}
	extern Node* ancestor;
	main_prt->draw(ancestor);
}
void del_fun(Node* p)
{
	if (!p)
		return;
	if (p->father)
	{
		for (vector<Node*>::iterator it =  p->father->son.begin();it!= p->father->son.end();it++)
		{
			if (*it == p)
			{
				p->father->son.erase(it);
				break;
			}
		}
	}
	clear_node(p);
}
void Menu::add_front( )
{
	main_prt->add_front(node);
}
void Menu::add_back()
{
	main_prt->add_back(node);
}