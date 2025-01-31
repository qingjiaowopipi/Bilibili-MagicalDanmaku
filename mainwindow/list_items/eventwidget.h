#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextDocument>
#include <QDebug>
#include "livedanmaku.h"
#include "listiteminterface.h"

#define CODE_EVENT_ACTION_KEY (QApplication::applicationName() + ":EventAction")

class EventWidget : public ListItemInterface
{
    Q_OBJECT
public:
    EventWidget(QWidget *parent = nullptr);

    virtual void fromJson(MyJson json) override;
    virtual MyJson toJson() const override;

    virtual bool isEnabled() const override;
    virtual QString title() const override;
    virtual QString body() const override;

signals:
    void signalEventMsgs(QString msgs, LiveDanmaku danmaku, bool manual);

public slots:
    void triggerCmdEvent(QString cmd, LiveDanmaku danmaku);
    void triggerAction(LiveDanmaku danmaku);
    void autoResizeEdit() override;

public:
    QLineEdit* eventEdit;
    QPlainTextEdit* actionEdit;

    QString cmdKey;
};

#endif // EVENTWIDGET_H
