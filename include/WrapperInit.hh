/*
** FF, 2024
** CAMI-Desktop/src/communication_test/include
** File description:
** Wrapper_init
*/

#pragma once

#include <napi.h>

namespace Wrapper
{
    Napi::Float64Array add_wrapped_wolfram(const Napi::CallbackInfo &info);
    Napi::Array add_get_params(const Napi::CallbackInfo &info);
    Napi::Object init(Napi::Env env, Napi::Object exports);
    NODE_API_MODULE(addon, init)

} // namespace Wrapper
