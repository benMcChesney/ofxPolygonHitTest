#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground( 65 , 65 , 65 ) ;
    polyObject.setup( 4 , ofVec2f( ofGetWidth() / 2 , ofGetHeight() / 2 ) ) ;

    float w = 50 ;
    float h = 100 ;

    //Use helper functions to generate points of common shapes
    polyObject.setPoints( polyHitTest.createRectanglePts( w , h ) ) ;

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

   polyObject.baseDraw( ) ;

   ofSetColor( 215 , 215 , 215 ) ;
   ofDrawBitmapString( "Click on the rotated square to make it rotate!" , 15 , ofGetHeight() - 35 ) ;
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

    //Get our result  false = outside the polygon , true = inside the polygon
    bool bResult = polyHitTest.pointInPoly( polyObject.pts , x , y ) ;

    cout << " bResult from polyLine !" << bResult << endl ;
    if ( bResult == false )
        cout << "exterior point !" << endl ;
    if ( bResult == true )
    {
        cout << "interior point !" << endl ;
        //Mix up the rotation a bit
        polyObject.randomizePolygon();
    }

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
