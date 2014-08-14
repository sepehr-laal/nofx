#ifndef _NOFX_GLOBALS_H_
#define _NOFX_GLOBALS_H_

// Make sure you always include node.h first. Otherwise you'll
// get random weird errors about mixing C/C++ routines.

#include "node.h"
#include "v8.h"
#include "nan.h"

#define DepNewInstance(name) (NanNew(name)->Call(args.This(), 0, nullptr))

extern v8::Persistent<v8::Function> DEP_floatPtr;

#endif // !_NOFX_GLOBALS_H_