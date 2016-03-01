#ifndef BALL_H
#define BALL_H

#include "ofMain.h"

#define G 10		// gravitational constant
#define MAX_VELOCITY 10

class Ball {
public:
	Ball(ofColor _color, ofVec2f _pos = ofVec2f(ofRandomWidth(), ofRandomHeight()), int _mass = 16, float _density = 1.0);
	void draw();
	void update(const vector<Ball*>& balls, bool reversed);
	bool touching(const Ball* ball) const;
	void respawn();

	/* accessors */
	float radius() const;
	ofColor color() const;

protected:
	int mass;
	float density;
	ofVec2f pos;
	ofVec2f velocity;
	ofColor b_color;
};

#endif
