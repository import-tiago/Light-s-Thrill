#include "Arduino.h"

#include "RGBLed.h"

int RGBLed::RED[3] 			= {255, 0, 0};
int RGBLed::ORANGE_RED[3] 	= {255, 69, 0};
int RGBLed::ORANGE[3] 		= {255, 102, 0};
int RGBLed::CORAL[3] 		= {255, 127, 80};
int RGBLed::YELLOW[3] 		= {255, 255, 0};
int RGBLed::GREEN[3] 		= {0, 128, 0};
int RGBLed::LIME[3] 		= {191, 255, 0};
int RGBLed::CYAN[3] 		= {0, 255, 255};
int RGBLed::BABY_BLUE[3]	= {137, 207, 240};
int RGBLed::CERULEAN[3] 	= {0, 123, 167};
int RGBLed::BLUE[3] 		= {0, 0, 255};
int RGBLed::AZURE[3] 		= {0, 127, 255};
int RGBLed::BLUE_VIOLET[3] 	= {138, 43, 226};
int RGBLed::BYZANTIUM[3] 	= {112, 41, 99};
int RGBLed::PINK[3] 		= {253, 108, 158};
int RGBLed::WHITE[3] 		= {255, 255, 255};


RGBLed::RGBLed(int red, int green, int blue, Mode common):
_red(red), _green(green), _blue(blue), _common(common)
{
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
}

void RGBLed::off() {
	color(0, 0, 0);
}

void RGBLed::brightness(int rgb[3], int brightness) {
	intensity(rgb[0], rgb[1], rgb[2], brightness);
}

void RGBLed::brightness(int red, int green, int blue, int brightness) {
	intensity(red, green, blue, brightness);
}

void RGBLed::brightness(int brightness) {
	Current_Brightness = brightness;
	intensity(Current_Color[0], Current_Color[1], Current_Color[2], brightness);
}

void RGBLed::intensity(int red, int green, int blue, int brightness) {
	red = (red * brightness) / 100;
	green = (green * brightness) / 100;
	blue = (blue * brightness) / 100;
	color(red, green, blue);
}

void RGBLed::flash(int rgb[3], int duration) {
	blink(rgb[0], rgb[1], rgb[2], duration, duration);
}

void RGBLed::flash(int rgb[3], int onDuration, int duration) {
	blink(rgb[0], rgb[1], rgb[2], onDuration, duration);
}

void RGBLed::flash(int red, int green, int blue, int duration) {
	blink(red, green, blue, duration, duration);
}

void RGBLed::flash(int red, int green, int blue, int onDuration, int duration) {
	blink(red, green, blue, onDuration, duration);
}

void RGBLed::blink(int red, int green, int blue, int onDuration, int duration) {
	color(red, green, blue);
	delay(onDuration);
	off();
	delay(duration);
}

void RGBLed::setColor(int rgb[3]) {
	Current_Color[0] = rgb[0];
	Current_Color[1] = rgb[1];
	Current_Color[2] = rgb[2];
	brightness(rgb, Current_Brightness);
	//color(rgb[0], rgb[1], rgb[2]);
}

void RGBLed::setColor(int red, int green, int blue) {
	
	color(red, green, blue);
}

void RGBLed::color(int red, int green, int blue) {
	if (_common == COMMON_ANODE) {
		analogWrite(_red, ~red);
		analogWrite(_green, ~green);
		analogWrite(_blue, ~blue);
	} else {
		analogWrite(_red, red);
		analogWrite(_green, green);
		analogWrite(_blue, blue);
	}
}

void RGBLed::fadeOut(int rgb[3], int steps, int duration) {
	fade(rgb[0], rgb[1], rgb[2], steps, duration, true);
}

void RGBLed::fadeOut(int red, int green, int blue, int steps, int duration) {
	fade(red, green, blue, steps, duration, true);
}

void RGBLed::fadeIn(int rgb[3], int steps, int duration) {
	fade(rgb[0], rgb[1], rgb[2], steps, duration, false);
}

void RGBLed::fadeIn(int red, int green, int blue, int steps, int duration) {
	fade(red, green, blue, steps, duration, false);
}

void RGBLed::fade(int red, int green, int blue, int steps, int duration, bool out) {
	if (out) {
		for (int i = 255; i >= 0; i -= steps) {
			fade(red, green, blue, steps, duration, i);
		}
	} else {
		for (int i = 0; i <= 255; i += steps) {
			fade(red, green, blue, steps, duration, i);
		}
	}
}

void RGBLed::fade(int red, int green, int blue, int steps, int duration, int value) {
	float brightness = float(value) / 255.f;
	if (red > 0 && red <= 255) analogWrite(_red, red * brightness);
	if (green > 0 && green <= 255) analogWrite(_green, green * brightness);
	if (blue > 0 && blue <= 255) analogWrite(_blue, blue * brightness);
	delay((unsigned long) (duration / steps));
}
