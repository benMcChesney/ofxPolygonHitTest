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

        void setup ( int npts , ofVec2f _pivot ) ;
        void addPoint ( float x , float y ) ;           //calls add LocalPoint( ) ;
        void addLocalPoint( float x , float y ) ;       //With the pivot point added to it
        void addGlobalPoint ( float x , float y ) ;     //without adding it to the pivot point
        void setPoints( vector<ofVec2f> _points ) ;



        void baseDraw( ) ;
        ofColor baseColor ;

        float rotation ;

        void outputPtsToConsole( ) ;



    protected:
    private:
};

#endif // BASEPOLYOBJECT_H
