#include "ofxNode_ofPushMatrix.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPushMatrix) {
        ofPushMatrix();
        NanReturnValue(args.This());
    } // !{ofxNode_ofPushMatrix}
} // !namespace ofxNode