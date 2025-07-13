/*
 * gipEmptyPlugin.h
 *
 *  Created on: Mar 11, 2023
 *      Author: Noyan Culum
 *      Created by: kayra
 */

#ifndef SRC_GIPGAUGE_H_
#define SRC_GIPGAUGE_H_

#include "gBasePlugin.h"
#include <string>



class gipGauge : public gBasePlugin{
public:
	gipGauge();
	virtual ~gipGauge();
	void setup() override;
	void update() override;
	void draw();
	//void keyPressed(int key) override;

	void setValue(int value);
	int getValue();
	void setMin(int minvalue);
	void setMax(int maxvalue);
	void calculate(int min, int max, int val);
	void imgLoad();
	void setGaugeType(int userselectedgauge, int userselectedneedle);
	void textSettings();
	void setLocation(int x, int y);
	void setAnimation(bool a);
	void indicatorDraw();

private:
	static const int needletype = 2;
	static const int gaugetype = 3;
	int gaugex, gaugey;
	int gaugew, gaugeh;
	int needlex, needley;
	int needlew, needleh;
	int value, minvalue, maxvalue;
	static const int BLACK_NEEDLE = 0, RED_NEEDLE = 1;
	static const int GLASS_GAUGE = 0, RED_GAUGE = 1, METALLIC_GAUGE = 2;
	int gaugeselect, needleselect;
	int finalvalue;

	gImage gauges[gaugetype];
	gImage needles[needletype];

	gFont textfont;
	std::string mintext;
	std::string maxtext;
	std::string valuetext;

	int gaugewidth[gaugetype];
	int gaugeheight[gaugetype];
	int needlewidth[needletype];
	int needleheight[needletype];

	bool animationvalue = false;
	int degree = -90;

};

#endif /* SRC_GIPGAUGE_H_ */
