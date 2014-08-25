#ifndef _NOFX_TYPES_H_
#define _NOFX_TYPES_H_

enum NOFX_TYPES
{
	OFVEC3F = 0,
	OFVEC2F,
	OFVEC4F,
	OFSTYLE,
	OFCOLOR,
	OFIMAGE,
	OFBASEAPP,
	OFMATRIX4X4,
	OFMATRIX3X3,
	OFRECTANGLE,
	OFQUATERNION,
	OFTRUETYPEFONT,
	OFAPPBASEWINDOW,
	NUMBERPOINTER,
	OFPIXELS,
	OFTEXTURE,
	OFTEXTUREDATA,
	FLOATPTR,
	INTPTR,
	DOUBLEPTR,
	UNSIGNEDCHARPTR,
	UNSIGNEDSHORTPTR,
	VOIDPTR,
	OFBUFFER,
	OFFILE,
	CHARPTR
};

#define DepNewInstance(name) (NanNew(name)->Call(args.This(), 0, nullptr))

#endif // !_NOFX_TYPES_H_