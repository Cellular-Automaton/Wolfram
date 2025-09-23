/*
** EPITECH PROJECT, 2023
** CAMI-Desktop/src/communication_test/src
** File description:
** init
*/

#include <Wrapper/WrapperWolfram.hh>
#include <WrapperInit.hh>
#include <array>
#include <iostream>
#include <string>

Napi::Uint32Array Wrapper::add_wrapped_wolfram(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env(); // check if arguments are integer only.
    /*    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
            Napi::TypeError::New(env, "arg1::Number, arg2::Number expected")
                .ThrowAsJavaScriptException();
        }*/ // convert javascripts datatype to c++,
    Napi::Uint32Array first = info[0].As<Napi::Uint32Array>();
    Napi::Number second = info[1].As<Napi::Number>();
    Napi::Number third = info[2].As<Napi::Number>();

    Napi::Uint32Array return_value = Napi::Uint32Array::New(env, first.ByteLength() / 8);

    std::vector<size_t> val{Wrapper::simulate_wolfram(
        first.Data(), second.Int32Value(), third.Int32Value())};
    for (size_t i{0}; i < val.size(); i++)
        return_value.Set(i, val[i]);
    /*api::Array Napi::Array returnValue = Napi::Array::New(
        env,
        Plugin::simulate_lenia(first.Float32Array(), second.Float32Value(),
       third.Float32Value(), fourth.Float32Value(), fifth.Float32Value(), six.Float32Value(),
                               seven.Float32Value(), ));

                               */
    return return_value;
}

Napi::Array Wrapper::add_get_params(const Napi::CallbackInfo &info)
{

    /*
     *
     *    Napi::Float64Array first = info[0].As<Napi::Float64Array>();
    Napi::Number second =
        info[1].As<Napi::Number>(); // run c++ function return value and return it in javascript
    Napi::Number third = info[2].As<Napi::Number>();
    Napi::Number fourth = info[3].As<Napi::Number>();
    Napi::Number fifth = info[4].As<Napi::Number>();
    Napi::Number six = info[5].As<Napi::Number>();
    Napi::Number seven = info[6].As<Napi::Number>();
    Napi::Number eight = info[7].As<Napi::Number>();
     *
     * */

    Napi::Env env = info.Env(); // check if arguments are integer only.
    std::array<std::string, 3> tmp{"tab_init:Float64Array", " generation_id:Number", "width:Number"};
    //    std::cout << sizeof(*tmp.data()) << '\n';
    Napi::Array return_value = Napi::Array::New(env, tmp.size());
    for (size_t i{0}; i < tmp.size(); i++)
        return_value[i] = Napi::String::New(env, tmp[i]);
    return return_value;
}

Napi::Object Wrapper::init(Napi::Env env, Napi::Object exports)
{

    exports.Set("simulate", Napi::Function::New(env, Wrapper::add_wrapped_wolfram));
    exports.Set("get_params", Napi::Function::New(env, Wrapper::add_get_params));
    return exports;
}
