#include "InfoWindow.h"
#include <qmessagebox.h>
#include <qstring.h>
InfoWindow::InfoWindow(QWidget* parent):QDialog(parent)
{
	
	ui.setupUi(this);
	people = NULL;
}
void InfoWindow::Receive(People* _people)
{
	if (_people)
	{
		people = _people;
	}
	set_data();
}
void InfoWindow::set_data()
{
	if (people)
	{
		ui.Name ->setText(QString::fromLocal8Bit(people->name.data()));
		ui.Sex->setText(QString::fromLocal8Bit(people->sex.data()));
		ui.Addr->setText(QString::fromLocal8Bit(people->addr.data()));
		ui.Work->setText(QString::fromLocal8Bit(people->work.data()));
		ui.Birthday->setDate(QDate(people->birthday.year, people->birthday.month, people->birthday.day));
		ui.Deathdate->setDate(QDate(people->death_date.year, people->death_date.month, people->death_date.day));
		ui.Live->setText(QString::fromLocal8Bit(people->live.data()));
	}
	else
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"�޷����ã������˿�ָ��");
		box.exec();
	}

}
void InfoWindow::on_ButtonConfirm_clicked()
{
	string name = ui.Name->text().toLocal8Bit();
	string sex = ui.Sex->text().toLocal8Bit();
	string addr = ui.Addr->text().toLocal8Bit();
	string work = ui.Work->text().toLocal8Bit();
	string live = ui.Live->text().toLocal8Bit();
	QDate bir = ui.Birthday->date();
	QDate dea = ui.Deathdate->date();
	if (name.length() < 1 || name.length() > 20)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"��������ȷ");
		box.exec();
		return;
	}
	if (live != string("��") && live != string("��"))
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"���ڱ���Ϊ���ǡ��򡰷�֮һ");
		box.exec();
		return;
	}
	if (sex != string("��") && sex != string("Ů"))
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"�Ա����Ϊ���С���Ů��֮һ");
		box.exec();
		return;
	}
	if (addr.length() > 100)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"��ַ����");
		box.exec();
		return;
	}
	if (work.length() > 100)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"��������");
		box.exec();
		return;
	}
	if (bir > dea)
	{
		QMessageBox box(QMessageBox::Critical, u8"����", u8"���ܻ�û������ȥ��");
		box.exec();
		return;

	}
	people->name = name;
	people->addr = addr;
	people->sex = sex;
	people->work = work;
	people->live = live;
	people->death_date = Date(dea.year(), dea.month(), dea.day());
	people->birthday = Date(bir.year(), bir.month(), bir.day());
	this->close();
}