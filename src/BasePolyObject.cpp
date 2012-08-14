#include "BasePolyObject.h"

BasePolyObject::BasePolyObject()
{
    //ctor
    rotation = 0 ;
}

BasePolyObject::~BasePolyObject()
{
    //dtor
}

void BasePolyObject::setup( int nPts , ofVec2f _pivot )
{
    pivot = _pivot ;
    baseColor = ofColor ( ofRandom( 255 ) , ofRandom( 255 ) , ofRandom( 255 ) ) ;
 }

void BasePolyObject::baseDraw( )
{
    ofFill() ;
    ofBeginShape ( ) ;


        ofSetColor( 255 - baseColor.r , 255 - baseColor.g , 255 - baseColor.b ) ;
        for( int p = 0 ; p < pts.size() ; p++ )
            ofCircle( pts[p] , 4 ) ; //( pts[i].x ,pts[i].y ) ;

        ofSetColor( 125 , 125 ) ;
        for( int i = 0 ; i < pts.size() ; i++ )
            ofVertex( pts[i].x ,pts[i].y ) ;

    ofEndShape(  ) ;
}

void BasePolyObject::randomizePolygon( )
{
    rotation = ofRandom( 360 ) ;
    for( int i = 0 ; i < pts.size() ; i++ )
    {
        //Reset positions of points to normalized around the pivot
        ofVec2f p = pts[i] - pivot ;
        //Rotate the points from the pivot
        p.rotate( rotation ) ;
        pts[i] = p + pivot ;
    }

}


void BasePolyObject::setPoints( vector<ofVec2f> polyPts )
{
    pts.clear() ;
    for ( int i = 0 ; i < polyPts.size() ; i++ )
    {
        //Have to offset the normalizef poly pts by this shape's pivot for rotation
        pts.push_back( pivot + polyPts[i] ) ;
    }
}

void BasePolyObject::addPoint( float x , float y )
{
    addLocalPoint( x , y ) ;
}

void BasePolyObject::addLocalPoint( float x , float y )
{
    pts.push_back( ofVec2f( pivot.x + x , pivot.y + y ) ) ;
}

void BasePolyObject::addGlobalPoint( float x , float y )
{
    pts.push_back( ofVec2f( x , y ) ) ;
}

void BasePolyObject::outputPtsToConsole( )
{
    for ( int p = 0 ; p < pts.size() ; p++ )
    {
        cout << "@ " << p << " x:" << pts[p].x << " , y:" << pts[p].y << endl ;
    }
}

