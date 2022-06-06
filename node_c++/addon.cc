//#include <node_modules\node-addon-api\napi.h>
#include <napi.h>
#include "./demo/demo.h"
#include "./testDLL/TestClass.h"


Napi::String Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "world");
}

Napi::String Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    TestClass *test = new TestClass(1, 2);
    int res = test->add(2, 5);

    std::string strRes = std::to_string(res);

    return Napi::String::New(env, strRes);
    //return Napi::String::New(env, "cgf");
}

Napi::String getInfo(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();

    std::string age;
    std::string name;
    CGF::getInfo(age, name);

    return Napi::String::New(env, name);
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello1"),
              Napi::Function::New(env, Method));//设置函数名和函数指针
  exports.Set(Napi::String::New(env, "add"),
              Napi::Function::New(env, Add));//设置函数名和函数指针         
  exports.Set(Napi::String::New(env, "getInfo"),
              Napi::Function::New(env, getInfo));//设置函数名和函数指针         
  return exports;
}

NODE_API_MODULE(addon, Init)