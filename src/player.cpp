#include "player.h"

Player::Player() : Ball(START_COLOR, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), START_MASS, 0.5) {
	for (int i = 0; i < KEY_COUNT; i++)
		keys[i] = false;
}

void Player::update() {
	if (keys[KEY_UP])
		velocity.y -= IMPULSE * ofGetLastFrameTime();
	if (keys[KEY_DOWN])
		velocity.y += IMPULSE * ofGetLastFrameTime();
	if (keys[KEY_LEFT])
		velocity.x -= IMPULSE * ofGetLastFrameTime();
	if (keys[KEY_RIGHT])
		velocity.x += IMPULSE * ofGetLastFrameTime();
}

void Player::keyPressed(int keycode) {
	switch (keycode) {
	case OF_KEY_UP:
		keys[KEY_UP] = true;
		break;
	case OF_KEY_DOWN:
		keys[KEY_DOWN] = true;
		break;
	case OF_KEY_LEFT:
		keys[KEY_LEFT] = true;
		break;
	case OF_KEY_RIGHT:
		keys[KEY_RIGHT] = true;
		break;
	}
}

void Player::keyReleased(int keycode) {
	switch (keycode) {
	case OF_KEY_UP:
		keys[KEY_UP] = false;
		break;
	case OF_KEY_DOWN:
		keys[KEY_DOWN] = false;
		break;
	case OF_KEY_LEFT:
		keys[KEY_LEFT] = false;
		break;
	case OF_KEY_RIGHT:
		keys[KEY_RIGHT] = false;
		break;
	}
}

bool Player::score(const Ball* ball) {
	if (ball->color() == b_color) {
		mass += 16;
		return true;
	} else {
		mass = START_MASS;
		b_color = ball->color();
		return false;
	}
}

void Player::reset() {
	mass = START_MASS;
	b_color = START_COLOR;
}
