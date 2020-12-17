// SPDX-License-Identifier: GPL-2.0
#ifndef STATSWIDGET_H
#define STATSWIDGET_H

#include "stats/statsstate.h"
#include "stats/chartlistmodel.h"
#include "ui_statswidget.h"
#include <vector>
#include <memory>

class QCheckBox;

class StatsWidget : public QWidget {
	Q_OBJECT
public:
	StatsWidget(QWidget *parent = 0);
private
slots:
	void closeStats();
	void chartTypeChanged(int);
	void var1Changed(int);
	void var2Changed(int);
	void var1BinnerChanged(int);
	void var2BinnerChanged(int);
	void var2OperationChanged(int);
	void featureChanged(int, bool);
private:
	Ui::StatsWidget ui;
	StatsState state;
	void updateUi();
	std::vector<std::unique_ptr<QCheckBox>> features;

	ChartListModel charts;
	//QStringListModel charts;
	void showEvent(QShowEvent *) override;
};

#endif // STATSWIDGET_H
