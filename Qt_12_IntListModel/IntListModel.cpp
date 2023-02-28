// ======================================================================
 //  IntListModel.cpp
 // ======================================================================
 //                   This file is a part of the book
 //             "Qt 5.10 Professional programming with C++"
 //                       http://qt-book.com
 // ======================================================================
 //  Copyright (c) 2017 by Max Schlee
 // ======================================================================

 #include <QtGui>
 #include "IntListModel.h"

 // ----------------------------------------------------------------------
 IntListModel::IntListModel(const QList<int>& list, QObject* pobj/*=0*/)
         : QAbstractListModel(pobj)
         , m_list(list)
 {
 }


 // ----------------------------------------------------------------------
 QVariant IntListModel::data(const QModelIndex& index, int nRole) const
 {
     if (!index.isValid()) {
         return QVariant();
     }
    if (index.row() < 0 || index.row() >= m_list.size()) {
         return QVariant();
     }
     return (nRole == Qt::DisplayRole)
            ? m_list.at(index.row())
            : QVariant();
 }




 // ----------------------------------------------------------------------
 int IntListModel::rowCount(const QModelIndex& parent/*=QModelIndex()*/
                           ) const
 {
     if (parent.isValid()) {
         return 0;
     }

     return m_list.size();
 }




