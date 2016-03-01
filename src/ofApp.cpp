#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetWindowTitle("Gravitation (WIP)");
	ofSetCircleResolution(100);
	ofSeedRandom();

	colors = {
		ofColor(255, 127, 127),
		ofColor(127, 255, 127),
		ofColor(127, 127, 255)
	};

	points = 0;
	target = 3;
	reversed = false;
	guiFont.load("arial", 24);
	player = new Player();
	balls.push_back(player);

	for (int i = 0; i < 6; i++) {
		balls.push_back(new Ball(RANDOM(colors)));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	/* run update on all objects */
	player->update();	/* Player::update() called here, Ball::update will be called later on player */

	for (Ball* ball : balls) {
		ball->update(balls, reversed);

		/* check collisions */
		if (ball != player) {
			if (ball->touching(player)) {	/* ball/player collision */
				/* TODO: should move score handling to seperate function */
				if (player->score(ball)) {
					++points;
					if (points > target) {
						player->reset();
						points = 0;
						++target;
					}
				} else
					points = 0;

				/* respawn ball */
				*ball = Ball(RANDOM(colors));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (Ball* ball : balls) {
		ball->draw();
	}

	renderGUI();
}

void ofApp::renderGUI() {
	ofSetColor(ofColor(255, 255, 255));

	float fontWidth = guiFont.stringWidth(ofToString(target));
	guiFont.drawString(
		ofToString(target),
		ofGetWidth() / 2 - fontWidth / 2,
		ofGetHeight() - 64
	);
}

//--------------------------------------------------------------
void ofApp::exit() {
	for (Ball* ball : balls) {
		delete ball;
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ')
		reversed = !reversed;
	else
		player->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == ' ')
		reversed = !reversed;
	else
		player->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
