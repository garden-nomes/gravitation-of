#include "ball.h"

Ball::Ball(ofColor _color, ofVec2f _pos, int _mass, float _density) {
	pos = _pos;
	mass = _mass;
	b_color = _color;
	density = _density;
}

void Ball::draw() {
	ofSetColor(b_color);
	ofDrawCircle(pos.x, pos.y, radius());
}

void Ball::update(const vector<Ball*>& balls, bool reversed) {
	int screen_padding;
	float force;

	// update position
	pos += velocity;

	// wrap screen
	screen_padding = radius();
	if (pos.x < -screen_padding) {
		pos.x += ofGetWidth() + screen_padding * 2;
	} else if (pos.x > ofGetWidth() + screen_padding) {
		pos.x -= ofGetWidth() + screen_padding * 2;
	}
	if (pos.y < -screen_padding) {
		pos.y += ofGetHeight() + screen_padding * 2;
	} else if (pos.y > ofGetHeight() + screen_padding) {
		pos.y -= ofGetHeight() + screen_padding * 2;
	}

	// apply gravity
	for (const Ball* b : balls) {
		if (b != this) {
			// apply gravitational attraction
			force = G * (mass + b->mass) / pos.squareDistance(b->pos);
			if (reversed)
				force = -force;
			velocity += (b->pos - pos).normalize() * force;
		}
	}

	if (velocity.squareDistance(ofVec2f(0, 0)) > MAX_VELOCITY * MAX_VELOCITY)
		velocity = velocity.normalize() * MAX_VELOCITY;
}

bool Ball::touching(const Ball* ball) const {
	if (pos.squareDistance(ball->pos)
		< (radius() + ball->radius()) * (radius() + ball->radius()))
		return true;
	else
		return false;
}

void Ball::respawn() {
	pos = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f();
}

float Ball::radius() const { return mass * density; }
ofColor Ball::color() const { return b_color; }
