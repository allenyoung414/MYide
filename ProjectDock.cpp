
#include <QTabWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileInfo>

#include "ProjectDock.h"


ProjectDock::ProjectDock(QWidget *parent, Qt::WindowFlags flag) : QDockWidget(parent, flag)
{
    setWindowTitle(tr("项目管理窗体"));
    setObjectName(tr("projectDockWidget"));
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
    setMinimumWidth(150);
    
    openFileManagementListWidget = new QListWidget;
    openFileManagementListWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(openFileManagementListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(ListWidgetRowChanged(int)));

    projectDockTabWidget = new QTabWidget;
    projectDockTabWidget->setTabsClosable(false);
    projectDockTabWidget->addTab(openFileManagementListWidget, tr("文件管理"));
    projectDockTabWidget->setCurrentIndex(0);
    
    setWidget(projectDockTabWidget);
}

void ProjectDock::AddItemToOpenFileManagementListWidget(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName();
    QListWidgetItem *item = new QListWidgetItem;
    item->setData(0, filePath);
    item->setText(fileName);
    openFileManagementListWidget->addItem(item);
}

void ProjectDock::RemoveItemByOpenFileManagementListWidget(int row)
{
    openFileManagementListWidget->takeItem(row);
}

void ProjectDock::SetCurrentRowByOpenFileManagementListWidget(int row)
{
    openFileManagementListWidget->setCurrentRow(row);
}

void ProjectDock::ChangeRowTextByOpenFileManagementListWidget(int row, const QString text)
{
    openFileManagementListWidget->item(row)->setText(text);
}

void ProjectDock::ListWidgetRowChanged(int index)
{
    emit ListWidgetRowChangedSignal(index);
}

void ProjectDock::AddTabToProjectDock(QWidget *widget, const QString &tabName)
{
    projectDockTabWidget->addTab(widget, tabName);
}

void ProjectDock::SetTabCurrentIndex(int index)
{
    projectDockTabWidget->setCurrentIndex(index);
}
