#include "nofx_ofVec3f.h"
#include "nofx_noop.h"
#include "..\nofx\nofx_types.h"

namespace nofx
{
	namespace OfVec3f
	{
		Persistent<Function> OfVec3fWrap::constructor;

		OfVec3fWrap::OfVec3fWrap()
			: internal_(nullptr)
		{}

		//--------------------------------------------------------------
		OfVec3fWrap::OfVec3fWrap(ofVec3f* aInternal)
			: internal_(aInternal)
		{}

		//--------------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::New)
		{
			NanScope();
			if (args.IsConstructCall()) {
				OfVec3fWrap* obj;

				//depends on ofVec4f
				//depends on ofVec2f
				if (args.Length() == 0)
				{
					obj = new OfVec3fWrap(new ofVec3f());
				}
				else if (args.Length() == 1)
				{
					obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue()));
				}
				else if (args.Length() == 2)
				{
					obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue(), args[1]->NumberValue(), 0));
				}
				else if (args.Length() == 3)
				{
					obj = new OfVec3fWrap(new ofVec3f(args[0]->NumberValue(), args[1]->NumberValue(), args[2]->NumberValue()));
				}
				else if (args[0]->IsNull())
				{
					obj = new OfVec3fWrap(nullptr);
				}
				else
				{
					//copy constructor
					obj = new OfVec3fWrap(ObjectWrap::Unwrap<OfVec3fWrap>(args[0]->ToObject())->GetWrapped());
				}
				obj->Wrap(args.This());
				NanReturnValue(args.This());
			}
			else
			{
				// Invoked as plain function `MyObject(...)`, turn into construct call.
				std::vector<v8::Handle<v8::Value>> lArgvVec;
				for (int i = 0; i < args.Length(); ++i) { lArgvVec.push_back(args[i]); }
				NanReturnValue(NanNew<v8::Function>(constructor)->NewInstance(lArgvVec.size(), (lArgvVec.size() == 0) ? nullptr : &lArgvVec[0]));
			}
		}

		//--------------------------------------------------------------
		void OfVec3fWrap::Initialize(v8::Handle<Object> exports)
		{
			auto tpl = NanNew<v8::FunctionTemplate>(New);
			tpl->SetClassName(NanNew("ofVec3f"));

			auto inst = tpl->InstanceTemplate();
			inst->SetInternalFieldCount(1);


			inst->SetAccessor(NanNew("DIM"), OfVec3fWrap::GetDIM, 0, v8::Handle<v8::Value>(), v8::PROHIBITS_OVERWRITING);
			inst->SetAccessor(NanNew("x"), OfVec3fWrap::GetX, OfVec3fWrap::SetX);
			inst->SetAccessor(NanNew("y"), OfVec3fWrap::GetY, OfVec3fWrap::SetY);
			inst->SetAccessor(NanNew("z"), OfVec3fWrap::GetZ, OfVec3fWrap::SetZ);

			NanSetPrototypeTemplate(tpl, NanNew("align"), NanNew<v8::FunctionTemplate>(Align), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("alignRad"), NanNew<v8::FunctionTemplate>(AlignRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angle"), NanNew<v8::FunctionTemplate>(Angle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("angleRad"), NanNew<v8::FunctionTemplate>(AngleRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("average"), NanNew<v8::FunctionTemplate>(Average), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("cross"), NanNew<v8::FunctionTemplate>(Cross), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("distance"), NanNew<v8::FunctionTemplate>(Distance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("dot"), NanNew<v8::FunctionTemplate>(Dot), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getCrossed"), NanNew<v8::FunctionTemplate>(GetCrossed), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getInterpolated"), NanNew<v8::FunctionTemplate>(GetInterpolated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getLimited"), NanNew<v8::FunctionTemplate>(GetLimited), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMapped"), NanNew<v8::FunctionTemplate>(GetMapped), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getMiddle"), NanNew<v8::FunctionTemplate>(GetMiddle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getNormalized"), NanNew<v8::FunctionTemplate>(GetNormalized), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPerpendicular"), NanNew<v8::FunctionTemplate>(GetPerpendicular), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getPtr"), NanNew<v8::FunctionTemplate>(GetPtr), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRotated"), NanNew<v8::FunctionTemplate>(GetRotated), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getRotatedRad"), NanNew<v8::FunctionTemplate>(GetRotatedRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("getScaled"), NanNew<v8::FunctionTemplate>(GetScaled), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("interpolate"), NanNew<v8::FunctionTemplate>(Interpolate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAligned"), NanNew<v8::FunctionTemplate>(IsAligned), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("isAlignedRad"), NanNew<v8::FunctionTemplate>(IsAlignedRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("length"), NanNew<v8::FunctionTemplate>(Length), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("limit"), NanNew<v8::FunctionTemplate>(Limit), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("map"), NanNew<v8::FunctionTemplate>(Map), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("match"), NanNew<v8::FunctionTemplate>(Match), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("middle"), NanNew<v8::FunctionTemplate>(Middle), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("normalize"), NanNew<v8::FunctionTemplate>(Normalize), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("one"), NanNew<v8::FunctionTemplate>(One), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("perpendicular"), NanNew<v8::FunctionTemplate>(Perpendicular), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotate"), NanNew<v8::FunctionTemplate>(Rotate), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("rotateRad"), NanNew<v8::FunctionTemplate>(RotateRad), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("scale"), NanNew<v8::FunctionTemplate>(Scale), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("set"), NanNew<v8::FunctionTemplate>(Set), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("squareDistance"), NanNew<v8::FunctionTemplate>(SquareDistance), v8::ReadOnly);
			NanSetPrototypeTemplate(tpl, NanNew("zero"), NanNew<v8::FunctionTemplate>(Zero), v8::ReadOnly);

			NanSetPrototypeTemplate(tpl, NanNew("NOFX_TYPE"), NanNew(NOFX_TYPES::OFVEC3F), v8::ReadOnly);
			NanAssignPersistent(constructor, tpl->GetFunction());
			exports->Set(NanNew<String>("ofVec3f"), tpl->GetFunction());
		}


		NAN_GETTER(OfVec3fWrap::GetDIM)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				NanReturnValue(self->DIM);
			}
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetX)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				NanReturnValue(self->x);
			}
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetY)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				NanReturnValue(self->y);
			}
		}
		//----------------------------------------------------

		NAN_GETTER(OfVec3fWrap::GetZ)
		{
			const auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				NanReturnValue(self->z);
			}
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetX)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				self->x = value->NumberValue();
			}
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetY)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				self->y = value->NumberValue();
			}
		}
		//----------------------------------------------------

		NAN_SETTER(OfVec3fWrap::SetZ)
		{
			auto self = ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr) {
				self->z = value->NumberValue();
			}
		}
		//----------------------------------------------------


		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Align)
		{
			auto self = node::ObjectWrap::Unwrap<OfVec3fWrap>(args.This())->GetWrapped();
			if (self != nullptr)
			{
				//self->align();
			}
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::AlignRad)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Angle)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::AngleRad)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Average)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Cross)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Distance)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Dot)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetCrossed)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetInterpolated)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetLimited)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetMapped)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetMiddle)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetNormalized)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetPerpendicular)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetPtr)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetRotated)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetRotatedRad)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::GetScaled)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Interpolate)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::IsAligned)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::IsAlignedRad)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Length)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Limit)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Map)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Match)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Middle)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Normalize)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::One)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Perpendicular)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Rotate)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::RotateRad)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Scale)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Set)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::SquareDistance)
		{
			//implementation
		}

		//---------------------------------------------------------
		NAN_METHOD(OfVec3fWrap::Zero)
		{
			//implementation
		}

	} //!namespace OfVec3f
} //!namespace nofx