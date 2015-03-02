#include "eprescription.h"
#include <QTabWidget>
#include <QTextEdit>
#include <QTextCursor>
#include <QTextFrame>
#include <QTextTable>
#include <QTextFrameFormat>
#include <QTextTableFormat>
#include <QPrinter>
#include <QPrintDialog>

ePrescription::ePrescription(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Init();
	InitData();

	setWindowTitle(QStringLiteral("���Ӵ��� V0.01"));

	connect(ui.m_actionPrint, SIGNAL(triggered()), this, SLOT(PrintFile()));
}

void ePrescription::Init()
{
	m_pTabPrescription = new QTabWidget;
	setCentralWidget(m_pTabPrescription);
}

void ePrescription::InitData()
{
	QTextEdit *pTextEdit = new QTextEdit;
	int tabIndex = m_pTabPrescription->addTab(pTextEdit, QStringLiteral("��̨ҽԺ"));
	m_pTabPrescription->setCurrentIndex(tabIndex);

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

	cursor.insertText(QStringLiteral("������̨ҽԺ�����㣨����"), titleFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat typeFrameFormat;
	typeFrameFormat.setLeftMargin(520);
	cursor.insertFrame(typeFrameFormat);

	cursor.insertText(QStringLiteral("[����]"));

	QTextCharFormat drugTypeFormat;
	drugTypeFormat.setFontPointSize(12.0);
	drugTypeFormat.setFontWeight(QFont::Bold);
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("��ҩ"), drugTypeFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat frontFrameFormat;
	//frontFrameFormat.setMargin(8);
	cursor.insertFrame(frontFrameFormat);

	cursor.insertText(QStringLiteral("����ҽ�ƻ�������:06110002\t\t\t�������:\t42018237"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("�Ʊ�:N��������\t2014��12��17��\t�ѱ�:�Է�\t���ﲡ����:N13504446"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("����:С����\t�Ա�:Ů\t����:2��\t��λ:��̨"));
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
	cursor.insertText(QStringLiteral("�ٴ����:"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("���Ա�������"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("����"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("��������"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("Ƥ������"));
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("����ʵ��:"));

	cursor = pTable->cellAt(0, 1).firstCursorPosition();
	cursor.insertText(QStringLiteral("ͷ��������ɢƬ(100mg*6Ƭ\t\t����:54.53\t\tС��:54.53)"));

	cursor.setPosition(pFrameTop->lastPosition());

	cursor.insertText(QStringLiteral("ҩƷ���: 151.12\t���/����ǩ��(ǩ��):\t�˶�/��ҩǩ��(ǩ��):"));
	cursor.insertBlock();
	cursor.insertText(QStringLiteral("ҩʦ��ʾ: 1��������ҽ����ҩ��2�����ڴ��ڵ���ҩƷ��3������������Ч��4������ҩƷ�����˻�"));
}

void ePrescription::PrintFile()
{
	QTextEdit *pEditor = static_cast<QTextEdit*>(m_pTabPrescription->currentWidget());
	QPrinter printer;
	QPrintDialog dialog(&printer, this);
	dialog.setWindowTitle(QStringLiteral("��ӡ����"));
	if (pEditor->textCursor().hasSelection())
		dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
	if (dialog.exec() != QDialog::Accepted)
		return;

	pEditor->print(&printer);
}