#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Box");

	int span = 70;
	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += span) {
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += span) {
			for (int z = -ofGetWidth() / 2; z < ofGetWidth() / 2; z += span) {
				Particle p = Particle(x, y, z);
				this->particles.push_back(p);
			}
		}
	}

	this->noise_x = ofRandom(10);
	this->noise_y = ofRandom(10);
	this->noise_z = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	this->light.setPosition(this->cam.getPosition());

	this->hate_x = ofMap(ofNoise(noise_x), 0, 1, -ofGetWidth(), ofGetWidth());
	this->hate_y = ofMap(ofNoise(noise_y), 0, 1, -ofGetHeight(), ofGetHeight());
	this->hate_z = ofMap(ofNoise(noise_z), 0, 1, -ofGetWidth(), ofGetWidth());
	
	this->noise_x += 0.025;
	this->noise_y += 0.025;
	this->noise_z += 0.025;

	for (Particle& p : this->particles) {
		p.escape(ofVec3f(this->hate_x, this->hate_y, this->hate_z));
		p.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableDepthTest();
	ofEnableLighting();
	this->light.enable();

	cam.begin();

	for (Particle& p : this->particles) {
		p.draw();
	}

	ofSetColor(0);
	ofSphere(ofVec3f(this->hate_x, this->hate_y, this->hate_z), 30);

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
