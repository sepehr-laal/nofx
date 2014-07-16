#pragma once

#include "globals.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofGraphics.h"

// All API ports will go here
// Please keep this convention in mind:
// ALWAYS HAVE THE PRIORITY TO RETURN args.This() from your methods!
// If the original OF API returns a value, return that if it's a void
// always return args.This()
// This is really important because in Javascript
// domain one can do "this dot that dot this" kinda
// routines (aka chaining). Like jQuery.

#include "ofxNode_ofRunApp.h"
#include "ofxNode_ofSetupOpenGL.h"
#include "ofxNode_ofCircle.h"
#include "ofxNode_ofFill.h"
#include "ofxNode_ofClear.h"
#include "ofxNode_ofGetElapsedTimeMillis.h"
#include "ofxNode_ofSetColor.h"

// self_ is a reference to the loaded module across all ported API's
v8::Persistent<v8::Object> self_;

namespace ofxNode {

	NAN_METHOD(Draw) {
		NanScope();
		//to be overridden at user's will
		NanReturnUndefined();
	}

	void Initialize(v8::Handle<v8::Object> target,
		v8::Handle<v8::Value> unused,
		v8::Handle<v8::Context> context) {
			// First let's check if these two elements exist.
			// We absolutely require these two variables.
			ASSERT_TRUE(!target.IsEmpty());
			ASSERT_TRUE(!context.IsEmpty());
			// We also have to make sure self_ is empty by now
			ASSERT_TRUE(self_.IsEmpty());
			// Assigning target (what's being returned by Node's "require") to self_
			// for future reference.
			NanAssignPersistent(self_, target);
			// Checking if it happened successfully
			ASSERT_TRUE(!self_.IsEmpty());
			
			// Assertions are passed, let's initialize the module with assigning its methods
			target->Set(NanNew<v8::String>("ofSetupOpenGL"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetupOpenGL)->GetFunction());
			target->Set(NanNew<v8::String>("ofRunApp"), NanNew<v8::FunctionTemplate>(ofxNode_ofRunApp)->GetFunction());
			target->Set(NanNew<v8::String>("ofCircle"), NanNew<v8::FunctionTemplate>(ofxNode_ofCircle)->GetFunction());
			target->Set(NanNew<v8::String>("ofFill"), NanNew<v8::FunctionTemplate>(ofxNode_ofFill)->GetFunction());
			target->Set(NanNew<v8::String>("ofClear"), NanNew<v8::FunctionTemplate>(ofxNode_ofClear)->GetFunction());
			target->Set(NanNew<v8::String>("ofGetElapsedTimeMillis"), NanNew<v8::FunctionTemplate>(ofxNode_ofGetElapsedTimeMillis)->GetFunction());
			target->Set(NanNew<v8::String>("ofSetColor"), NanNew<v8::FunctionTemplate>(ofxNode_ofSetColor)->GetFunction());
			target->Set(NanNew<v8::String>("draw"), NanNew<v8::FunctionTemplate>(Draw)->GetFunction());
	}

}

// We're using Context Aware initializer, for forward compatibility with Node 0.10+
// Although at the time it's note possible to have multiple instacnces of OF
// On the same Node instance due to OF's internals. Maybe this requires a patch to OF
// Will look at this later. TODO(sepehr)
// Consult http://strongloop.com/strongblog/whats-new-node-js-v0-12-multiple-context-execution/
NODE_MODULE_CONTEXT_AWARE(ofxNode, ofxNode::Initialize)