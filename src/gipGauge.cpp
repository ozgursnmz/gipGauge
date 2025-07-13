/*
 * gipEmptyPlugin.cpp
 *
 *  Created on: Mar 11, 2023
 *      Author: Noyan Culum
 *      Created by: kayra
 */

#include "gipGauge.h"


gipGauge::gipGauge() {
}

gipGauge::~gipGauge() {
}

void gipGauge::setup() {
	gaugewidth[GLASS_GAUGE] = 876;
	gaugeheight[GLASS_GAUGE] = 454;

	gaugewidth[RED_GAUGE] = 840;
	gaugeheight[RED_GAUGE] = 431;

	gaugewidth[METALLIC_GAUGE] = 900;
	gaugeheight[METALLIC_GAUGE] = 460;

	needlewidth[RED_NEEDLE] = 75;
	needleheight[RED_NEEDLE] = 494;

	needlewidth[BLACK_NEEDLE] = 110;
	needleheight[BLACK_NEEDLE] = 570;

	setAnimation(false);

	calculate(0, 100, 20);

	setLocation(0, 0);
	imgLoad();


	setGaugeType(RED_GAUGE, BLACK_NEEDLE);
	textSettings();

}

void gipGauge::update() {
	if(animationvalue == true){
		if(degree < finalvalue){
			degree++;
		}
		else{
			animationvalue = false;
		}
	}
;
}

void gipGauge::draw() {
	int nw = needlewidth[needleselect] * 6 / 10;
	int nh = needleheight[needleselect] * 6 / 10;

	gauges[gaugeselect].draw(gaugex, gaugey, gaugewidth[gaugeselect], gaugeheight[gaugeselect]);

	textfont.drawText(mintext, (float)gaugex + 20, (float)gaugey + gaugeheight[gaugeselect] + 40);
	textfont.drawText(maxtext, (float)gaugex + gaugewidth[gaugeselect] - 70, (float)gaugey + gaugeheight[gaugeselect] + 40);
	textfont.drawText(valuetext, (float)needlex, (float)needley + needleheight[needleselect] / 5);

	if(animationvalue){
		needles[needleselect].draw(needlex - nw/2,needley - nh,nw, nh,nw/2, nh, degree);
	}
	else{
		needles[needleselect].draw(needlex - nw/2,needley - nh,nw, nh,nw/2, nh, finalvalue);
	}


}

void gipGauge::setValue(int uservalue) {
	value = uservalue;
}

int gipGauge::getValue() {
	return value;
}

void gipGauge::setMin(int min) {
	minvalue = min;
}

void gipGauge::setMax(int max) {
	maxvalue = max;
}

void gipGauge::calculate(int min, int max, int val) {
    minvalue = min;
    maxvalue = max;
    value = val;

    float tempvalue = 180.0f / (maxvalue - minvalue);
    finalvalue = (value - minvalue) * tempvalue - 90.0f;
}

void gipGauge::imgLoad() {
	for (int gauge = 0; gauge < gaugetype; ++gauge) {
		gauges[gauge].loadImage("gauge_" + gToStr(gauge) + ".png");
	}
	for (int needle = 0; needle < needletype; ++needle) {
		needles[needle].loadImage("needle_" + gToStr(needle) + ".png");
	}
}

void gipGauge::setGaugeType(int userselectedgauge, int userselectedneedle) {
	gaugeselect = userselectedgauge;
	needleselect = userselectedneedle;
}

void gipGauge::textSettings() {
	textfont.loadFont("FreeSans.ttf", 25);


	mintext = gToStr(minvalue);
	maxtext = gToStr(maxvalue);
	valuetext = gToStr(value);
}

void gipGauge::setLocation(int x, int y) {
	gaugex = x;
	gaugey = y;
	needlex = gaugex + gaugewidth[gaugeselect] / 2;
	needley = gaugey + gaugeheight[gaugeselect];


}

void gipGauge::setAnimation(bool a) {
	animationvalue = a;
}
