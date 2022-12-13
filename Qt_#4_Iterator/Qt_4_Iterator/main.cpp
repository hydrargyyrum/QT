#include <QCoreApplication>
#include <QDebug>
#include <QMutableListIterator>
#include <QMutableMapIterator>
#include <QLinkedList>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //List
    QList<QString> list;
     list << "A" << "B" << "C" << "D";

    QListIterator<QString> i(list); //Прямой
     while (i.hasNext())
         qDebug() << i.next();
            qDebug () << Qt::endl;

    QListIterator<QString> i1(list); //Обратный
     i1.toBack();
     while (i1.hasPrevious())
         qDebug() << i1.previous();
        qDebug () << Qt::endl;

    QList<int> listInt;
     listInt << 1 << 2 << 3 << 4;

     /*
      * QListIterator не предоставляет функций для вставки или удаления элементов перебираемого списка.
      * Для того, чтобы сделать это, вы должны использовать QMutableListIterator.
     */

    QMutableListIterator<int> i2(listInt); //Удаление нечетных элементов
     while (i2.hasNext()) {
         if (i2.next() % 2 != 0)
             i2.remove();
     }
        qDebug () << listInt;

     //Map
     QMap<QString, QString> map;
     map.insert("Paris", "France");
     map.insert("Guatemala City", "Guatemala");
     map.insert("Mexico City", "Mexico");
     map.insert("Moscow", "Russia");

     QMutableMapIterator<QString, QString> i3(map); //Удаляются все пары (столица, государство), в которых название столицы оканчивается на "City"
     while (i3.hasNext()) {
         if (i3.next().key().endsWith("City"))
             i3.remove();
     }
     qDebug() << map;
        qDebug () << Qt::endl;

     //Hash
     QMap<int, QWidget *> map1;
     QHash<int, QWidget *> hash;

     QMapIterator<int, QWidget *> i4(map1); //Копирование содержимого QMap в QHash
     while (i4.hasNext()) {
         i4.next();
         hash.insert(i4.key(), i4.value());
     }

    //Итератор через foreach
     QString str;
     foreach (str, list)
         qDebug() << str;
     qDebug() << "OK" << Qt::endl;

    return a.exec();
}
