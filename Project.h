/****************************************************************************
**      Titles  :   项目类，作为TreeWidget的成员，一个项目就是一个类目类的对象
**
****************************************************************************/
#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QStringList>

class QTreeWidgetItem;

class Project
{
public:
    explicit Project(const QString &pName, const QString &pDir, bool pType = false);
    ~Project();

public:
    bool isCProject;
    QString projectDir;
    QStringList projectName;
    QStringList headFolderName;
    QStringList sourceFolderName;
    QTreeWidgetItem *projcetFolderItem;
    QTreeWidgetItem *headFolderItem;
    QTreeWidgetItem *sourceFolderItem;
};

#endif // PROJECT_H
