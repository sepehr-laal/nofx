#include "globals.h"
#include "nofx_ofStyle.h"
#include "nofx_dependencies.h"

namespace nofx
{
    namespace OfStyle
    {
        using namespace v8;

        void Initialize(v8::Handle<Object> target,
            v8::Handle<Value> unused,
            v8::Handle<Context> context)
        {

            target->Set(NanNew<v8::String>("dependencies"), NanNew<v8::FunctionTemplate>(nofx_dependencies)->GetFunction());
            OfStyleWrap::Initialize(target);

        } //!Initialize
    } //!namespace OfStyle
} //!namespace nofx

NODE_MODULE_CONTEXT_AWARE(nofx_ofStyle, nofx::OfStyle::Initialize)