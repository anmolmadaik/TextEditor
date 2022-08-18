#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QResource>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include  <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include "findtext.h"
#include "replace.h"
#include "about.h"
#include <QDialog>
#include <QSettings>
#include <QOperatingSystemVersion>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
//    QAction *fontinc = new QAction(QIcon(":/icons/Favorites (1)/icons8-increase-font-100.png"),"Increase Font",this);
//    QAction *fontdec = new QAction(QIcon(":/icons/Favorites (1)/icons8-decrease-font-100.png"),"Decrease Font",this);
//    QAction *fontsize = new QAction(QIcon(":/icons/Favorites (1)/icons8-font-100.png"),"Change Font Size",this);
//    QAction *fontchng = new QAction(QIcon(":/icons/Favorites (1)/icons8-choose-font-100.png"),"Change Font",this);
//    QAction *fontcolor = new QAction(QIcon(":/icons/Favorites (1)/icons8-color-100.png"),"Change Font Color",this);
//    void fonti();
//    void fontd();
//    void fontc();
//    void fontcol();

private:
    Ui::MainWindow *ui;
    static int zoom;
    bool changed;
    QString path;
    bool u;
    void newFile();
    void openFile();
    void saveFile(QString p);;
    void saveFileAs();
    bool textSelected();
    QMessageBox::StandardButton checksave();
    void check();
    bool noText();
    void changeText();
    bool windowsDarkThemeAvailable();
    bool windowsIsInDarkTheme();
    void toDarkTheme();
    void toLightTheme();
    bool dark;
    void iniTheme();
//    QMenu *font;
signals:

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();

    void on_actionSave_triggered();
    void on_actionSave_As_triggered();


    void on_textEdit_textChanged();


    void on_actionUndo_triggered();
    void on_actionRedo_triggered();

    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionDelete_triggered();

    void on_actionSelect_All_triggered();
    void on_actionExit_triggered();

    void on_textEdit_cursorPositionChanged();


    void on_actionFind_triggered();
    void on_actionReplace_triggered();

    void on_actionBold_triggered();
    void on_actionItalic_triggered();
    void on_actionUnderline_triggered();
    void on_actionStrike_triggered();


    void on_actionColor_triggered();
    void on_actionFont_triggered();


    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionRestore_Zoom_triggered();
    void on_actionLine_Wrap_triggered();




    void on_actionChange_Theme_triggered();

    void on_actionAbout_triggered();

    void on_actionHelp_triggered();

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
