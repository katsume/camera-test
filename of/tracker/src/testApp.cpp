#include "testApp.h"

uint const kWidth	= 320;
uint const kHeight	= 240;

//--------------------------------------------------------------
void testApp::setup(){
	
	videoGrabber.setVerbose(true);
	videoGrabber.setDeviceID(1);
//	videoGrabber.setDesiredFrameRate(30);
	videoGrabber.initGrabber(kWidth, kHeight);

	colorImage.allocate(kWidth, kHeight);
	grayscaleImage.allocate(kWidth, kHeight);
}

//--------------------------------------------------------------
void testApp::update(){

	videoGrabber.update();
	
	if(!videoGrabber.isFrameNew()){
		return;
	}
	
	colorImage.setFromPixels(videoGrabber.getPixels(), kWidth, kHeight);
	
	grayscaleImage= colorImage;
	grayscaleImage.threshold(128);
	
	contourFinder.findContours(grayscaleImage, 5, (kWidth*kHeight)/3, 10, false);

    for (int i = 0; i < contourFinder.nBlobs; i++){
//       contourFinder.blobs[i].boundingRect
    }
}

//--------------------------------------------------------------
void testApp::draw(){

//	colorImage.draw(0, 0);
	grayscaleImage.draw(0, 0);


	ofPushStyle();
	ofSetColor(255);
	contourFinder.draw();
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}