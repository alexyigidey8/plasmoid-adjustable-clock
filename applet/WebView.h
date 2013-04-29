/***********************************************************************************
* Adjustable Clock: Plasmoid to show date and time in adjustable format.
* Copyright (C) 2008 - 2013 Michal Dutkiewicz aka Emdek <emdeck@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
***********************************************************************************/

#ifndef ADJUSTABLECLOCKWEBVIEW_HEADER
#define ADJUSTABLECLOCKWEBVIEW_HEADER

#include "Clock.h"

#include <QtDeclarative/QDeclarativeItem>
#include <QtWebKit/QWebPage>

namespace AdjustableClock
{

class WebView : public QDeclarativeItem
{
    Q_OBJECT

    public:
        explicit WebView(QDeclarativeItem *parent = NULL);

        static void setupClock(QWebFrame *document, ClockObject *clock, const QString &html, const QString &css = QString());
        static void setupTheme(QWebFrame *document, const QString &css = QString());
        Q_INVOKABLE void setTheme(Clock *clock, const QString &theme, const QString &html, bool constant);
        Q_INVOKABLE QSize getPreferredSize(const QSize &constraints);
        Q_INVOKABLE bool getBackgroundFlag() const;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = NULL);
        void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry);
        static void updateComponent(QWebFrame *document, ClockComponent component);
        void updateZoom();

    protected slots:
        void repaint(const QRect &rectangle);
        void updateComponent(ClockComponent component);
        void updateTheme();

    private:
        QWebPage m_page;
        Clock *m_clock;
};

}

#endif