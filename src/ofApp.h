#pragma once

#include "ofMain.h"
#include "ball.h"
#include "player.h"

#define RANDOM(x) x[(int)ofRandom(0, x.size())]

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
		vector<Ball*> balls;
		Player* player;
		vector<ofColor> colors;
		int points;
		int target;
		ofTrueTypeFont guiFont;
		bool reversed;

		void renderGUI();
};
