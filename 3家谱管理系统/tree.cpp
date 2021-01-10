#pragma once
#include <QtWidgets/QMainWindow>
#include "qevent.h"
#include "tree.h"
#include "qpainter.h"
void Tree::paintEvent(QPaintEvent* event)
{
	QPainter pt(this);
	for (auto a : area)
	{
		pt.drawLine(a.start.x(), a.start.y(), a.end.x(), a.end.y());
	}
	pt.end();
}
Tree::Tree(QWidget* parent = nullptr) : QWidget(parent)
{

}
Area::Area()
{

}
Area::Area(QPoint s, QPoint e)
{
	start = s;
	end = e;
}