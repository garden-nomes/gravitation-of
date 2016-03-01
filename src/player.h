#ifndef PLAYER_H
#define PLAYER_H

#include "ball.h"

#define IMPULSE 2

#define KEY_COUNT	4
#define KEY_UP		0
#define KEY_DOWN	1
#define KEY_LEFT	2
#define KEY_RIGHT	3

#define START_MASS	48
#define START_COLOR	ofColor(127, 127, 127)

class Player : public Ball {
public:
	Player();
	void update();

	void keyPressed(int keycode);
	void keyReleased(int keycode);
	bool score(const Ball* ball);
	void reset();

private:
	bool keys[KEY_COUNT];
};

#endif
