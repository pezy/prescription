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

	setWindowTitle(tr("电子处方 V0.01"));
}

void MainWindow::Init()
{
	m_tabPrescription = new QTabWidget;
	setCentralWidget(m_tabPrescription);
}

void MainWindow::InitData()
{
	QTextEdit *pTextEdit = new QTextEdit;
	int tabIndex = m_tabPrescription->addTab(pTextEdit, tr("某某医院"));
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

	cursor.insertText(tr("北京某某医院处方笺（副）"), titleFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat typeFrameFormat;
	typeFrameFormat.setLeftMargin(520);
	cursor.insertFrame(typeFrameFormat);

	cursor.insertText(tr("[儿科]"));

	QTextCharFormat drugTypeFormat;
	drugTypeFormat.setFontPointSize(12.0);
	drugTypeFormat.setFontWeight(QFont::Bold);
	cursor.insertBlock();
	cursor.insertText(tr("成药"), drugTypeFormat);

	cursor.setPosition(pFrameTop->lastPosition());

	QTextFrameFormat frontFrameFormat;
	//frontFrameFormat.setMargin(8);
	cursor.insertFrame(frontFrameFormat);

	cursor.insertText(tr("定点医疗机构编码:06110002\t\t\t处方编号:\t42018237"));
	cursor.insertBlock();
	cursor.insertText(tr("科别:N儿科门诊\t2014年12月17日\t费别:自费\t门诊病历号:N13504446"));
	cursor.insertBlock();
	cursor.insertText(tr("姓名:小柯南\t性别:女\t年龄:2岁\t单位:丰台"));
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
	cursor.insertText(tr("临床诊断:"));
	cursor.insertBlock();
	cursor.insertText(tr("急性扁桃体炎"));
	cursor.insertBlock();
	cursor.insertText(tr("发热"));
	cursor.insertBlock();
	cursor.insertText(tr("烟气管炎"));
	cursor.insertBlock();
	cursor.insertText(tr("皮试阴性"));
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertBlock();
	cursor.insertText(tr("过敏实验:"));

	cursor = pTable->cellAt(0, 1).firstCursorPosition();
	cursor.insertText(tr("头孢拉丁分散片(100mg*6片\t\t单价:54.53\t\t小计:54.53)"));

	cursor.setPosition(pFrameTop->lastPosition());

	cursor.insertText(tr("药品金额: 151.12\t审核/调配签名(签章):\t核对/发药签名(签章):"));
	cursor.insertBlock();
	cursor.insertText(tr("药师提示: 1、请遵守医嘱服药；2、请在窗口点清药品；3、处方当日有效；4、发出药品不予退换"));
}