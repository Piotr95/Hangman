#include "decorate.h"
#include<QApplication>
#include<QProgressBar>
Decorate::Decorate()
{

}
 void Decorate::decorateLetter(QTextEdit *TE)
 {
      TE->setReadOnly(true);
      TE->setMaximumSize(31,42);
      TE->setMinimumSize(31,42);
      TE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      TE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      TE->setGeometry(148,42,944,494);
      TE->setHtml(QApplication::translate("Game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
     "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
     "p, li { white-space: pre-wrap; }\n"
     "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
     "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">_</span></p></body></html>", Q_NULLPTR));
 }

 void Decorate::decorateTextBoard(QTextBrowser *TB)
 {
     TB->setHtml(QApplication::translate("Game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
         "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
         "p, li { white-space: pre-wrap; }\n"
         "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
         "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Enter your guess letter:</span></p></body></html>", Q_NULLPTR));
 }
void Decorate::decoreteProgressBar(QProgressBar* health_points, int attemps)
{
    health_points->setOrientation(Qt::Vertical);
    health_points->setTextDirection(QProgressBar::BottomToTop);
    health_points->setRange(0, attemps);
    health_points->setValue(attemps);
    health_points->setTextVisible(false);
    health_points->setStyleSheet("::chunk {""background-color: red}");
}
