#ifndef BASEPOLYOBJECT_H
#define BASEPOLYOBJECT_H

#include "ofMain.h"

class BasePolyObject
{
    public:
        BasePolyObject();
        virtual ~BasePolyObject();

        vector<ofVec2f> pts ;
        ofVec2f pivot ;     //This is the spot from which the object will rotate from. All points are adjusted to be relative to this number

        void randomizePolygon ( )  ;

        void setup ( int npts , ofVec2f center ) ;
        void addPoint ( float x , float y ) ;
        void setPoints( vector<ofVec2f> _points ) ;

        void baseDraw( ) ;
        ofColor baseColor ;



    protected:
    private:
};

#endif // BASEPOLYOBJECT_H
