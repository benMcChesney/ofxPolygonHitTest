#ifndef OFXPOLYGONHITTEST_H
#define OFXPOLYGONHITTEST_H
#include "ofMain.h"

class ofxPolygonHitTest
{
    public:
        ofxPolygonHitTest();
        virtual ~ofxPolygonHitTest();


        //C++ can make this a little friendlier
        int pointInPoly ( vector<ofVec2f> pts , float x , float y )
        {
            int i, j, c = 0;
              for (i = 0, j = pts.size()-1 ; i < pts.size() ; j = i++)
              {

                if ( ( ((pts[i].y <= y) && (y < pts[j].y ) ) || ((pts[j].y <= y) && (y < pts[i].y )) ) &&
                     ( x < (pts[j].x - pts[i].x ) * (y - pts[i].y ) / ( pts[j].y - pts[i].y ) + pts[i].x ))
                  c = !c;
              }
              return c;
        }

        vector<ofVec2f> createRectanglePts ( float width , float height )
        {
            vector<ofVec2f> polyPts ;
            polyPts.push_back( ofVec2f(  -width/2 , -height/2 ) ) ;
            polyPts.push_back( ofVec2f(  width/2 , -height/2 ) ) ;
            polyPts.push_back( ofVec2f(  width/2 , height/2 ) ) ;
            polyPts.push_back( ofVec2f(  -width/2 , height/2 ) ) ;

            return polyPts ;
        }

        /*
        From Paul Bourke : http://local.wasp.uwa.edu.au/~pbourke/geometry/insidepoly/

        This specific snippet is by Randolph Franklin

        int pnpoly(int npol, float *xp, float *yp, float x, float y)
    {
      int i, j, c = 0;
      for (i = 0, j = npol-1; i < npol; j = i++) {
        if ((((yp[i] <= y) && (y < yp[j])) ||
             ((yp[j] <= y) && (y < yp[i]))) &&
            (x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
          c = !c;
      }
      return c;
    }

        */
    protected:
    private:
};

#endif // OFXPOLYGONHITTEST_H
