#include "testApp.h"

static uint const kOSCPort			= 12345;

static int const kWidth				= 320;
static int const kHeight			= 480;

static int const kButtonMargin		= 65;
static int const kButtonWidth		= 70;
static int const kButtonHeight		= 70;

static float const kDefaultRotateX	= -90.0f;
static float const kDefaultRotateY	= 0.0f;
static float const kDefaultRotateZ	= 150.0f;

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	
	glEnable(GL_DEPTH_TEST);
	
	receiver.setup(kOSCPort);
	
	camera.setDistance(1000);
//	camera.setNearClip(0.01f);
//	camera.setFarClip(500.0f);
	camera.setPosition(-400, 400, 400);
	camera.lookAt(ofVec3f(0, 0, 0));
	
	angle= 0;
	vec= ofVec3f();
}

//--------------------------------------------------------------
void testApp::update(){
	
	while(receiver.hasWaitingMessages()){
		
		ofxOscMessage message;
		receiver.getNextMessage(&message);
		
		string address= message.getAddress();
		if(address=="/attitude"){
			
			ofQuaternion quaternion= ofQuaternion(message.getArgAsFloat(0),
												  message.getArgAsFloat(1),
												  message.getArgAsFloat(2),
												  message.getArgAsFloat(3));
			
			quaternion=	quaternion*
						ofQuaternion(kDefaultRotateZ, ofVec3f(0.0f, 0.0f, 1.0f))*
						ofQuaternion(kDefaultRotateX, ofVec3f(1.0f, 0.0f, 0.0f));
			
			quaternion.getRotate(angle, vec);
		}
	}
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	camera.begin();
	

	
	ofPushStyle();
	ofDrawGrid(1000);
	ofPopStyle();
	

	
	ofPushStyle();
	ofPushMatrix();
	
	ofScale(-1, -1, -1);
	ofRotate(angle, vec.x, vec.y, vec.z);
	
//	ofNoFill();
//	ofSetLineWidth(5);
	ofSetColor(255, 0, 255);
	ofRect(-kWidth/2, -kHeight/2, kWidth, kHeight);
	ofEllipse(0, kHeight/2+kButtonMargin, kButtonWidth, kButtonHeight);
	
	ofPopMatrix();
	ofPopStyle();
	

	
	camera.end();
	
//	string message= "";
//	message+= "z : "+ofToString(camera.z)+"\n";
//	ofSetColor(255, 255, 255);
//	ofDrawBitmapString(message, 0, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key=='f'){
		ofToggleFullscreen();
	}
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
