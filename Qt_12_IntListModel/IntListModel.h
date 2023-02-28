// ======================================================================
 //  IntListModel.h
 // ======================================================================
 //                   This file is a part of the book
 //             "Qt 5.10 Professional programming with C++"
 //                       http://qt-book.com
 // ======================================================================
 //  Copyright (c) 2017 by Max Schlee
 // ======================================================================

 #pragma once

 #include <QAbstractListModel>

 // ======================================================================
 class IntListModel : public QAbstractListModel {
 Q_OBJECT
 private:
     QList<int> m_list;

 public:
     IntListModel(const QList<int>& list, QObject* pobj = 0);

     QVariant data(const QModelIndex& index, int nRole) const;



     int rowCount(const QModelIndex& parent = QModelIndex()) const;


 };
