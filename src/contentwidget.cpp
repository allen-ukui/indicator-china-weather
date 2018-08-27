/*
 * Copyright (C) 2013 ~ 2018 National University of Defense Technology(NUDT) & Tianjin Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    lixiang@kylinos.cn/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "contentwidget.h"
#include "nowweatherwidget.h"
#include "forecastweatherwidget.h"
//#include "indexweatherwidget.h"

#include <QVBoxLayout>

ContentWidget::ContentWidget(QWidget *parent) :
    QFrame(parent)
{
    m_layout = new QVBoxLayout(this);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
//    m_layout->setSpacing(1);

    m_nowWidget = new NowWeatherWidget(this);//this->setFixedSize(355, 180);
    m_forecastWidget = new ForecastWeatherWidget(this);//this->setFixedSize(355, 340);

    m_layout->addWidget(m_nowWidget, 0, Qt::AlignTop);
    m_layout->addWidget(m_forecastWidget);
}

ContentWidget::~ContentWidget()
{
    QLayoutItem *child;
    while ((child = m_layout->takeAt(0)) != 0) {
        if (child->widget())
            child->widget()->deleteLater();
        delete child;
    }
}
