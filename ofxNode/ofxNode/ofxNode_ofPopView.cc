#include "ofxNode_ofPopView.h"
#include "ofGraphics.h"

namespace ofxNode
{
    NAN_METHOD(ofxNode_ofPopView) {
        ofPopView();
        NanReturnValue(args.This());
    } // !{ofxNode_ofPopView}
} // !namespace ofxNode