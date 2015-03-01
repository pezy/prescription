#include "mainwindow.h"
#include <qtabwidget.h>
#include <qtextedit.h>
#include <qtextcursor.h>
#include <QTextFrame>
#include <QTextTable>
#include <QTextFrameFormat>
#include <QTextTableFormat>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	Init();
	InitData();

	setWindowTitle(tr("���Ӵ��� V0.01"));
}

void MainWindow::Init()
{
	m_tabPrescription = new QTabWidget;
	setCentralWidget(m_tabPrescription);
}

void MainWindow::InitData()
{
	QTextEdit *pTextEdit = new QTextEdit;
	int tabIndex = m_tabPrescription->addTab(pTextEdit, tr("ĳĳҽԺ"));
	m_tabPrescription->setCurrentIndex(tabIndex);

	QTextCursor cursor(pTextEdit->textCursor());
	cursor.movePosition(QTextCursor::Start);

	QTextFrame *pFrameTop = cursor.currentFrame();

	QTextFrameFormat topFrameFormat = pFrameTop->frameFormat();
	topFrameFormat.setPadding(16);
	pFrameTop->setFrameFormat(topFrameFormat);

	QTextFrameFormat titleFrameFormat;
	titleFrameFormat.setLeftMargin(150);
	cursor.insertFrame(titleFrameFormat);

	QTextCharFormat titleFormat;
	titleFormat.setFontPointSize(14.0);
    titleFormat.setFontWeight(QFont::Bold);

	cursor.insertText(tr("����ĳĳҽԺ�����㣨����"), titleFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat typeFrameFormat;
	typeFrameFormat.setLeftMargin(520);
	cursor.insertFrame(typeFrameFormat);

	cursor.insertText(tr("[����]"));

	QTextCharFormat drugTypeFormat;
	drugTypeFormat.setFontPointSize(12.0);
	drugTypeFormat.setFontWeight(QFont::Bold);
	cursor.insertBlock();
	cursor.insertText(tr("��ҩ"), drugTypeFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat frontFrameFormat;
	//frontFrameFormat.setMargin(8);
	cursor.insertFrame(frontFrameFormat);

	cursor.insertText(tr("����ҽ�ƻ�������:06110002\t\t\t�������:\t42018237"));
	cursor.insertBlock();
	cursor.insertText(tr("�Ʊ�:N��������\t2014��12��17��\t�ѱ�:�Է�\t���ﲡ����:N13504446"));
	cursor.insertBlock();
	cursor.insertText(tr("����:С����\t�Ա�:Ů\t����:2��\t��λ:��̨"));
	cursor.insertBlock();

	QTextTableFormat tableFormat;
	tableFormat.setAlignment(Qt::AlignLeft);
	tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
	tableFormat.setCellSpacing(0);
	tableFormat.setWidth(570);
	QTextTable *pTable = cursor.insertTable(1, 2, tableFormat);

	//QTextFrameFormat tableFrameFormat = cursor.currentFrame()->frameFormat();
 //   tableFrameFormat.setBorder(1);
 //   cursor.currentFrame()->setFrameFormat(tableFrameFormat);

	cursor = pTable->cellAt(0, 0).firstCursorPosition();
	cursor.insertText(tr("�ٴ����:"));
	cursor.insertBlock();
	cursor.insertText(tr("���Ա�������"));
	cursor.insertBlock();
	cursor.insertText(tr("����"));
	cursor.insertBlock();
	cursor.insertText(tr("��������"));
	cursor.insertBlock();
	cursor.insertText(tr("Ƥ������"));
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertText(tr("����ʵ��:"));

	cursor = pTable->cellAt(0, 1).firstCursorPosition();
	cursor.insertText(tr("ͷ��������ɢƬ(100mg*6Ƭ\t\t����:54.53\t\tС��:54.53)"));

	cursor.setPosition(pFrameTop->lastPosition());

	cursor.insertText(tr("ҩƷ���: 151.12\t���/����ǩ��(ǩ��):\t�˶�/��ҩǩ��(ǩ��):"));
	cursor.insertBlock();
	cursor.insertText(tr("ҩʦ��ʾ: 1��������ҽ����ҩ��2�����ڴ��ڵ���ҩƷ��3������������Ч��4������ҩƷ�����˻�"));
}