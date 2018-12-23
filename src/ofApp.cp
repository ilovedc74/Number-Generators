#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);
  ofSetFrameRate(60);
  font.load("Arial", 100, false, false, true);

  sentence = "Happy";
  stringPoints = getStringPoints(sentence);

  // YOUR CODE STARTS HERE
    for (int i=0; i<stringPoints.size(); i++) {
        noiseSeeds.push_back(ofRandom(1000));
    }
//    cout << stringPoints.size() <<endl;

    // YOUR CODE ENDS HERE
}

//--------------------------------------------------------------
void ofApp::update(){
  // YOUR CODE STARTS HERE


  // YOUR CODE ENDS HERE
}

//--------------------------------------------------------------
void ofApp::draw(){
    

  ofPushMatrix();
  ofTranslate(ofGetWidth()/2 - font.stringWidth(sentence)/2, ofGetHeight()/2 + font.stringHeight(sentence)/2);

  // YOU CODE STARTS HERE
    float noiseSize;
    noiseSize = ofMap(mouseX, 0, ofGetWidth(), 0, 40);
    for (int i=0; i<stringPoints.size(); i++) {

//        ofPoint offset;

        float x = ofSignedNoise(noiseSeeds[i]) * noiseSize;
        float y = ofSignedNoise(noiseSeeds[i] + 55) * noiseSize;
        ofPoint offset = ofPoint(x, y);
        ofPoint newPoint = stringPoints[i] + offset;

        
        float  pointSize;
        pointSize = ofSignedNoise(noiseSeeds[i])*6;
        
            ofDrawCircle(newPoint, pointSize);
        
        noiseSeeds[i]+=0.01;
        ofColor g(0,255,0);
        ofColor yellow(255,255,0);
        
        ofSetColor(g.getLerped(yellow, noiseSeeds[i]));

//        ofSetColor(getLerped(noiseSeeds[i]));
    }
  // END OF YOUR CODE

  ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

vector<ofPoint> ofApp::getStringPoints(string s){
  vector<ofPath> paths;
  vector<ofPoint> resultingPoints;
  string str = s;
  for(char& c : str) {
    paths.push_back(font.getCharacterAsPoints(c, true, false));
    paths[paths.size()-1].setMode(ofPath::POLYLINES);
  }

  ofPoint charOffset = ofPoint(0, 0);;
  for (int i = 0; i < paths.size(); i++){
     vector <ofPolyline> polylines = paths[i].getOutline();
     for (int j = 0; j < polylines.size(); j++){
        int numOfPoints = ofMap(polylines[j].getPerimeter(), 46, 574, 10, 100);
         for (int k=0; k<numOfPoints; k++){
             ofPoint letterPoint = ofPoint(polylines[j].getPointAtPercent(float(k+1)/numOfPoints));
             letterPoint += charOffset;
            resultingPoints.push_back(letterPoint);
        }
    }
    string letter = ofToString(str[i]);
    charOffset += ofPoint(font.stringWidth(letter), 0);
  }

  return resultingPoints;
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
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
