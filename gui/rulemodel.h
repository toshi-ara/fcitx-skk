/***************************************************************************
 *   Copyright (C) 2013~2013 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef RULEMODEL_H
#define RULEMODEL_H
#include <QAbstractListModel>

#include <libskk/libskk.h>

class Rule {
public:
    Rule(const QString& name, const QString& label) :
        m_name(name),
        m_label(label)
    {
    }

    const QString& name() const {
        return m_name;
    }

    const QString& label() const {
        return m_label;
    }

private:
    QString m_name;
    QString m_label;
};

class RuleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit RuleModel(QObject* parent = 0);

    virtual ~RuleModel();

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    void load();
    int findRule(const QString& name);

private:
    QList<Rule> m_rules;
};

#endif // RULEMODEL_H
