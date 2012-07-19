#ifndef OFXPOLYGONHITTEST_H
#define OFXPOLYGONHITTEST_H
#include "ofMain.h"

class ofxPolygonHitTest
{
    public:
        ofxPolygonHitTest();
        virtual ~ofxPolygonHitTest();


        //C++ can make this a little friendlier
        bool pointInPoly ( vector<ofVec2f> pts , float x , float y ) ;

        //Common shape generation
        vector<ofVec2f> createRectanglePts ( float width , float height ) ;

         static ofxPolygonHitTest* Instance()
         {
             static ofxPolygonHitTest inst ;
             return &inst ;
         }


    protected:
    private:
};

#endif // OFXPOLYGONHITTEST_H
