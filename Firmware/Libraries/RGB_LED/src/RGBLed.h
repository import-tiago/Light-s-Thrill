#ifndef RGBLed_h
#define RGBLed_h

#include "Arduino.h"

enum Mode { 
	COMMON_ANODE, 
	COMMON_CATHODE 
};

class RGBLed {

	public:
		RGBLed(int red, int green, int blue, Mode common);

		void off();

		void brightness(int rgb[3], int brightness);
		void brightness(int red, int green, int blue, int brightness);
		void brightness(int brightness);

		void flash(int rgb[3], int duration);
		void flash(int rgb[3], int onDuration, int duration);

		void flash(int red, int green, int blue, int duration);
		void flash(int red, int green, int blue, int onDuration, int duration);

		void setColor(int rgb[3]);
		void setColor(int red, int green, int blue);

		void fadeOut(int rgb[3], int steps, int duration);
		void fadeOut(int red, int green, int blue, int steps, int duration);

		void fadeIn(int rgb[3], int steps, int duration);
		void fadeIn(int red, int green, int blue, int steps, int duration);

		static int RED[3];
		static int ORANGE_RED[3];
		static int ORANGE[3];
		static int CORAL[3];
		static int YELLOW[3];
		static int GREEN[3];
		static int LIME[3];
		static int CYAN[3];
		static int BABY_BLUE[3];
		static int CERULEAN[3];
		static int BLUE[3];
		static int AZURE[3];
		static int BLUE_VIOLET[3];
		static int BYZANTIUM[3];
		static int PINK[3];
		static int WHITE[3];
		
		int Current_Color[3];
		int Current_Brightness;

		

		
		
		

	private:
		int _red, _green, _blue, _common;
		void color(int red, int green, int blue);
		void blink(int red, int green, int blue, int onDuration, int duration);
		void intensity(int red, int green, int blue, int brightness);
		void fade(int red, int green, int blue, int steps, int duration, bool out);
		void fade(int red, int green, int blue, int steps, int duration, int value);

};

#endif
