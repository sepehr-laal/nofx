#include "ofxNode_ofGetFill.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofGetFill) {
		NanReturnValue(NanNew(ofGetFill()));
    } // !{ofxNode_ofGetFill}
} // !namespace ofxNode