#ifndef PATHHELPER_H
#define PATHHELPER_H
//----------------------------------------------------------------------
#include <QString>
#include <QFile>
//----------------------------------------------------------------------

class PathHelper
{
public:
    // Возвращаем корректный путь до файла
    static QString GetPath(const QString& path)
    {
        QString temp = path;

        if (QFile(temp).exists())
            return temp;

        if (temp[0] != "/")
            temp.insert(0, '/');

        temp = QDir::currentPath() + temp;
        if (QFile(temp).exists())
            return temp;

        return path;
    }
};
//----------------------------------------------------------------------
#endif // PATHHELPER_H
