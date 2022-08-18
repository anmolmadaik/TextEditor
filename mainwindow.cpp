#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    path = "";
    changed = false;
    newFile();
    ui->menuEdit->actions().at(0)->setEnabled(false);
    ui->menuEdit->actions().at(1)->setEnabled(false);
    ui->menuFile->actions().at(0)->setEnabled(false);
    ui->menuFile->actions().at(3)->setEnabled(false);
    ui->menuFile->actions().at(4)->setEnabled(false);
    changeText();
    iniTheme();
}

int MainWindow::zoom = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    changed = true;
    changeText();
}


void MainWindow::newFile()
{
     ui->textEdit->clear();
     ui->statusbar->showMessage("New file opened",3000);
     path = "";
     changed = false;

}

void MainWindow::openFile()
{
    QString p = QFileDialog::getOpenFileName(this,"Choose a file to open");
    if (p.isEmpty()){
        return;
    }

    QFile f(p);

    if(!f.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error opening file",f.errorString());
        return;
    }

    QTextStream s(&f);
    ui->textEdit->setHtml(f.readAll());
    f.close();

    path = p;
    ui->statusbar->showMessage("File "+path+ " opened successfully",3000);
    changed = false;
    u = false;

}

void MainWindow::saveFile(QString p)
{
    if(p.isEmpty()){
        saveFileAs();
        return;
    }

    QFile f(p);
    if(!f.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"Error saving file",f.errorString());
        ui->statusbar->showMessage("File cannot be saved",3000);
        saveFileAs();
        return;
    }

    QTextStream s(&f);
    s << ui->textEdit->toHtml();
    f.close();
    path = p;
    ui->statusbar->showMessage("File saved to " + path + "successfully",5000);
    changed = false;

}

void MainWindow::saveFileAs()
{
    QString p = QFileDialog::getSaveFileName(this,"Save File As");
    if(p.isEmpty()){
        return;
    }

    saveFile(p);
}



bool MainWindow::textSelected()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(cursor.hasSelection()){
        return true;
    }
    else{
        return false;
    }
}

QMessageBox::StandardButton MainWindow::checksave()
{
    if(changed == false){
//        c = false;
        return QMessageBox::No;
    }
    QMessageBox::StandardButton v = QMessageBox::question(this,"Save File?","You have unchanged changes. Save changes?",QMessageBox::Yes | QMessageBox::No |QMessageBox::Cancel);
    return v;
//    if(v == QMessageBox::Yes){
//        if(path.isEmpty()){
//            saveFileAs();
//        }
//        else{
//            saveFile(path);
//        }
//        c = false;
//        return;
//    }
//    else if(v == QMessageBox::No){
//        c = true;
//        return;
//    }
//    else{
//      c = false;
//      return;
    //    }
}


bool MainWindow::noText()
{
    if(ui->textEdit->document()->isEmpty()){
        return true;
    }
    else{
        return false;
    }
}

void MainWindow::changeText()
{
    if(noText() == true){
        ui->menuFile->actions().at(0)->setEnabled(false);
        ui->menuFile->actions().at(3)->setEnabled(false);
        ui->menuFile->actions().at(4)->setEnabled(false);
        ui->menuEdit->actions().at(3)->setEnabled(false);
        ui->menuEdit->actions().at(4)->setEnabled(false);
        ui->menuEdit->actions().at(6)->setEnabled(false);
        ui->menuEdit->actions().at(8)->setEnabled(false);
        ui->menuEdit->actions().at(9)->setEnabled(false);
        ui->menuEdit->actions().at(11)->setEnabled(false);
//        ui->menuFormat->actions().at(0)->setEnabled(false);
//        ui->menuFormat->actions().at(1)->setEnabled(false);
//        ui->menuFormat->actions().at(2)->setEnabled(false);
//        ui->menuFormat->actions().at(3)->setEnabled(false);
//        ui->menuFormat->actions().at(6)->setEnabled(false);
    }
    else{
        if(changed == true){
            ui->menuFile->actions().at(0)->setEnabled(true);
            ui->menuFile->actions().at(3)->setEnabled(true);
            ui->menuFile->actions().at(4)->setEnabled(true);
            ui->menuEdit->actions().at(0)->setEnabled(true);
        }
        if(textSelected() == true){
            ui->menuEdit->actions().at(3)->setEnabled(true);
            ui->menuEdit->actions().at(4)->setEnabled(true);
            ui->menuEdit->actions().at(6)->setEnabled(true);
//            ui->menuFormat->actions().at(0)->setEnabled(true);
//            ui->menuFormat->actions().at(1)->setEnabled(true);
//            ui->menuFormat->actions().at(2)->setEnabled(true);
//            ui->menuFormat->actions().at(3)->setEnabled(true);
//            ui->menuFormat->actions().at(6)->setEnabled(true);
        }
        else{
            ui->menuEdit->actions().at(3)->setEnabled(false);
            ui->menuEdit->actions().at(4)->setEnabled(false);
            ui->menuEdit->actions().at(6)->setEnabled(false);
//            ui->menuFormat->actions().at(0)->setEnabled(false);
//            ui->menuFormat->actions().at(1)->setEnabled(false);
//            ui->menuFormat->actions().at(2)->setEnabled(false);
//            ui->menuFormat->actions().at(3)->setEnabled(false);
//            ui->menuFormat->actions().at(6)->setEnabled(false);
        }
        ui->menuEdit->actions().at(8)->setEnabled(true);
        ui->menuEdit->actions().at(9)->setEnabled(true);
        ui->menuEdit->actions().at(11)->setEnabled(true);
    }
}




void MainWindow::on_actionNew_triggered()
{
    QMessageBox::StandardButton v = checksave();
    if(v == QMessageBox::Yes){
        if(path.isEmpty()){
            saveFileAs();
        }
        else{
            saveFile(path);
        }
        newFile();
    }
    else if(v == QMessageBox::No){
        newFile();
    }
    else{
        return;
    }

}


void MainWindow::on_actionOpen_triggered()
{
    if(noText() == false){
        if(changed == true){
            QMessageBox::StandardButton v = checksave();
            if(v == QMessageBox::Yes){
                if(path.isEmpty()){
                    saveFileAs();
                }
                else{
                    saveFile(path);
                }
                openFile();
            }
            else if(v == QMessageBox::No){
                openFile();
            }
            else{
                return;
            }
        }

        else{
            openFile();
        }
    }
    else{
        openFile();
    }
    //  checkSave();
}


void MainWindow::on_actionSave_triggered()
{
    saveFile(path);
}


void MainWindow::on_actionSave_As_triggered()
{
    saveFileAs();
}

void MainWindow::on_actionUndo_triggered()
{
    if(changed == true){
        ui->textEdit->undo();
        ui->statusbar->showMessage("Action undone successfully",3000);
        u = true;
        changed = false;
        ui->menuEdit->actions().at(1)->setEnabled(true);
        ui->menuEdit->actions().at(0)->setEnabled(false);
    }

}


void MainWindow::on_actionRedo_triggered()
{
    if(u == true){
        ui->textEdit->redo();
        ui->statusbar->showMessage("Action redone successfully",3000);
        changed = true;
        u = false;
        ui->menuEdit->actions().at(0)->setEnabled(true);
        ui->menuEdit->actions().at(1)->setEnabled(false);
    }


}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
    ui->statusbar->showMessage("Text cut successfully",3000);

}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
    ui->statusbar->showMessage("Text copied successfully",3000);


}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
    ui->statusbar->showMessage("Text pasted successfully",3000);
}

void MainWindow::on_actionDelete_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    c.removeSelectedText();
    ui->statusbar->showMessage("Text deleted successfully",3000);

}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
    changeText();
}


void MainWindow::closeEvent(QCloseEvent *event)
{

    if(noText()){
        close();
    }
    else{
        QMessageBox::StandardButton v = checksave();
        if(v == QMessageBox::Yes){
            if(path.isEmpty()){
                saveFileAs();
            }
            else{
                saveFile(path);
            }
            event->accept();
        }
        else if(v == QMessageBox::No){
            event->accept();
        }
        else{
            event->ignore();
        }
    }

}

void MainWindow::on_actionExit_triggered()
{
    if(noText()){
        close();
    }
    else{
        QMessageBox::StandardButton v = checksave();
        if(v == QMessageBox::Yes){
            if(path.isEmpty()){
                saveFileAs();
            }
            else{
                saveFile(path);
            }
            close();
        }
        else if(v == QMessageBox::No){
            close();
        }
        else{
            return;
        }
    }

}



void MainWindow::on_textEdit_cursorPositionChanged()
{
    if(textSelected() == true){
        ui->menuEdit->actions().at(3)->setEnabled(true);
        ui->menuEdit->actions().at(4)->setEnabled(true);
        ui->menuEdit->actions().at(6)->setEnabled(true);
        ui->menuEdit->actions().at(11)->setEnabled(true);
//        ui->menuFormat->actions().at(0)->setEnabled(true);
//        ui->menuFormat->actions().at(1)->setEnabled(true);
//        ui->menuFormat->actions().at(2)->setEnabled(true);
//        ui->menuFormat->actions().at(3)->setEnabled(true);
//        ui->menuFormat->actions().at(6)->setEnabled(true);
    }
    else{
        ui->menuEdit->actions().at(3)->setEnabled(false);
        ui->menuEdit->actions().at(4)->setEnabled(false);
        ui->menuEdit->actions().at(6)->setEnabled(false);
        ui->menuEdit->actions().at(11)->setEnabled(false);
//        ui->menuFormat->actions().at(0)->setEnabled(false);
//        ui->menuFormat->actions().at(1)->setEnabled(false);
//        ui->menuFormat->actions().at(2)->setEnabled(false);
//        ui->menuFormat->actions().at(3)->setEnabled(false);
//        ui->menuFormat->actions().at(6)->setEnabled(false);
    }
}


void MainWindow::on_actionFind_triggered()
{
    findtext *f = new findtext(this);
    if(!f->exec()){
        return;
    }
    QTextDocument::FindFlags flags;
    if(f->getCaseSen()){
        flags = flags | QTextDocument::FindCaseSensitively;
    }
    if(f->getBack()){
        flags = flags | QTextDocument::FindBackward;
    }
    bool value = ui->textEdit->find(f->getSearchText(),flags);
    if(value == false){
        QMessageBox::information(this,"Search Results","Unable to find " + f->getSearchText());
    }
}


void MainWindow::on_actionBold_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QFont font = c.charFormat().font();
    QTextCharFormat f;

    if(font.bold() == true){
        font.setBold(false);
        ui->statusbar->showMessage("Bold annonation turned off",3000);
    }
    else{
        font.setBold(true);
        ui->statusbar->showMessage("Bold annonation turned on",3000);
    }
    f.setFont(font);
    c.mergeCharFormat(f);
    ui->textEdit->setTextCursor(c);
    changed = true;
}


void MainWindow::on_actionItalic_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QFont font = c.charFormat().font();
    QTextCharFormat f;
    if(font.italic() == true){
        font.setItalic(false);
        ui->statusbar->showMessage("Italic annonation turned off",3000);
    }
    else{
        font.setItalic(true);
        ui->statusbar->showMessage("Italic annonation turned on",3000);
    }
    f.setFont(font);
    c.mergeCharFormat(f);
    ui->textEdit->setTextCursor(c);
    changed = true;
}


void MainWindow::on_actionUnderline_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QFont font = c.charFormat().font();
    QTextCharFormat f;
    if(font.underline() == true){
        font.setUnderline(false);
        ui->statusbar->showMessage("Underline annonation turned off",3000);
    }
    else{
        font.setUnderline(true);
        ui->statusbar->showMessage("Underline annonation turned on",3000);
    }
    f.setFont(font);
    c.mergeCharFormat(f);
    ui->textEdit->setTextCursor(c);
    changed = true;
}


void MainWindow::on_actionStrike_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QFont font = c.charFormat().font();
    QTextCharFormat f;
    if(font.strikeOut() == true){
        font.setStrikeOut(false);
        ui->statusbar->showMessage("Strikethrough annonation turned off",3000);
    }
    else{
        font.setStrikeOut(true);
        ui->statusbar->showMessage("Strikethrough annonation turned on",3000);
    }
    f.setFont(font);
    c.mergeCharFormat(f);
    ui->textEdit->setTextCursor(c);
    changed = true;
}


void MainWindow::on_actionColor_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QColor current = c.charFormat().foreground().color();
    QTextCharFormat f;
    //QColor current = ui->textEdit->currentCharFormat().foreground().color();
    QColor n = QColorDialog::getColor(current,this,"Select a color");
    f.setForeground(n);
    ui->statusbar->showMessage("Text color changed",3000);
    c.mergeCharFormat(f);
    ui->textEdit->setTextCursor(c);
    changed = true;
}



void MainWindow::on_actionFont_triggered()
{
    QTextCursor c = ui->textEdit->textCursor();
    QFont fo = c.charFormat().font();
    QTextCharFormat f;
    bool ok;
    QFont font = QFontDialog::getFont(&ok,fo,this,"Please choose a font");
    if(ok){
        f.setFont(font);
        c.mergeCharFormat(f);
        ui->statusbar->showMessage("Font changed successfully",3000);
        ui->textEdit->setTextCursor(c);
        changed = true;
    }

}


void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn(5);
    zoom += 5;
    ui->statusbar->showMessage("Zoom level: " + QString::number(zoom)  +"%",3000);
;}


void MainWindow::on_actionZoom_Out_triggered()
{
    if(zoom == -5){
        ui->statusbar->showMessage("Cant zoom out any further",3000);
    }
    else{
        ui->textEdit->zoomOut(5);
        zoom -= 5;
        ui->statusbar->showMessage("Zoom level: " + QString::number(zoom)  +"%" ,3000);
    }
}


void MainWindow::on_actionRestore_Zoom_triggered()
{
    if(zoom > 0){
        ui->textEdit->zoomOut(zoom);
        zoom = 0;
    }
    else if(zoom < 0){
        ui->textEdit->zoomIn(abs(zoom));
        zoom = 0;
    }
    ui->statusbar->showMessage("Zoom level restored",3000);
}


void MainWindow::on_actionLine_Wrap_triggered()
{
    if(ui->textEdit->lineWrapMode() == QTextEdit::NoWrap){
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        ui->statusbar->showMessage("Line wrap enabled",3000);
    }
    else{
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
        ui->statusbar->showMessage("Line wrap disabled",3000);
    }
}


void MainWindow::on_actionReplace_triggered()
{
    replace *r = new replace(this);
    if(!r->exec()){
        return;
    }
    if(r->getAll()){
        QString text = ui->textEdit->toHtml();
        text = text.replace(r->getSearchText(),r->getReplaceText());
        ui->textEdit->setHtml(text);
    }
    else{
        QTextDocument::FindFlags back;
        if(r->getBack() == true){
            back = QTextDocument::FindBackward;
        }
        bool value = ui->textEdit->find(r->getSearchText(),back);
        QTextCursor c = ui->textEdit->textCursor();
        if(!value){
            QMessageBox::information(this,"Not Found", "Unable to find "+ r->getSearchText());
        }
        else{
            c.insertHtml(r->getReplaceText());
        }
    }
}


bool MainWindow::windowsDarkThemeAvailable()
{
    // dark mode supported Windows 10 1809 10.0.17763 onward
    // https://stackoverflow.com/questions/53501268/win10-dark-theme-how-to-use-in-winapi
    if ( QOperatingSystemVersion::current().majorVersion() == 10 )
    {
        return QOperatingSystemVersion::current().microVersion() >= 17763;
    }
    else if ( QOperatingSystemVersion::current().majorVersion() > 10 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool MainWindow::windowsIsInDarkTheme()
{
    QSettings settings( "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat );
    return settings.value( "AppsUseLightTheme", 1 ).toInt() == 0;
}


void MainWindow::toDarkTheme()
{
    QFile f(":/stylesheets/darktheme.qss");
    if ( !f.exists() )
    {
        qWarning() << "Unable to set dark stylesheet, file not found";
    }
    else
    {
        dark = true;
        f.open( QIODevice::ReadOnly | QIODevice::Text );
        QTextStream ts( &f );
        setStyleSheet( ts.readAll() );
        ui->menuView->actions().at(4)->setChecked(true);
        ui->statusbar->showMessage("Dark Theme ON",3000);
        ui->actionChange_Theme->setIcon(QIcon(":/icons/Dark/icons8-light-off-100.png"));
        ui->actionSelect_All->setIcon(QIcon(":/icons/Dark/icons8-select-all-100.png"));
        ui->actionBold->setIcon(QIcon(":/icons/Dark/icons8-bold-100.png"));
        ui->actionItalic->setIcon(QIcon(":/icons/Dark/icons8-italic-100.png"));
        ui->actionUnderline->setIcon(QIcon(":/icons/Dark/icons8-underline-100.png"));
        ui->actionStrike->setIcon(QIcon(":/icons/Dark/icons8-strikethrough-100.png"));
        ui->actionFont->setIcon(QIcon(":/icons/Dark/icons8-font-100.png"));
    }

}

void MainWindow::toLightTheme()
{
    QFile f(":/stylesheets/lighttheme.qss");
    if ( !f.exists() )
    {
        qWarning() << "Unable to set light stylesheet, file not found";
    }
    else
    {
        dark = false;
        f.open( QIODevice::ReadOnly | QIODevice::Text );
        QTextStream ts( &f );
        setStyleSheet( ts.readAll() );
        ui->menuView->actions().at(4)->setChecked(false);
        ui->statusbar->showMessage("Light Theme ON",3000);
        ui->actionChange_Theme->setIcon(QIcon(":/icons/Light/icons8-light-on-100.png"));
        ui->actionSelect_All->setIcon(QIcon(":/icons/Light/icons8-select-all-100.png"));
        ui->actionBold->setIcon(QIcon(":/icons/Light/icons8-bold-100.png"));
        ui->actionItalic->setIcon(QIcon(":/icons/Light/icons8-italic-100.png"));
        ui->actionUnderline->setIcon(QIcon(":/icons/Light/icons8-underline-100.png"));
        ui->actionStrike->setIcon(QIcon(":/icons/Light/icons8-strikethrough-100.png"));
        ui->actionFont->setIcon(QIcon(":/icons/Light/icons8-font-100.png"));
    }
}


void MainWindow::iniTheme()
{
    if(windowsIsInDarkTheme() == true){
        toDarkTheme();
    }
    else{
        toLightTheme();
    }
}





void MainWindow::on_actionChange_Theme_triggered()
{
    if(dark){
        toLightTheme();
    }
    else{
        toDarkTheme();
    }
}


void MainWindow::on_actionAbout_triggered()
{
    about *ab = new about(this);
    ab->exec();
}


void MainWindow::on_actionHelp_triggered()
{
    QDesktopServices::openUrl(QUrl(QApplication::organizationDomain()));
}

