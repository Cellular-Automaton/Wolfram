/*
** File description:
** main
*/

#include <Plugin/Wolfram.hh>
#include <Wrapper/WrapperWolfram.hh>

std::vector<size_t> Wrapper::simulate_wolfram(int *tab_init_1D, int generation_id, int width)
{
    std::vector<size_t> tab_init_1d{};

    for (size_t i{0}; i < width; i++) {
        tab_init_1d.emplace_back(tab_init_1D[i]);
    }

    PLC::Wolfram wolfram{tab_init_1d, generation_id};
    wolfram.run();

    return wolfram.getTab();
}
/*

Napi::Object Plugin::init(Napi::Env env, Napi::Object exports)
{
    exports.Set("simulate_lenia", Napi::Function::New(env, Plugin::add_wrapped_lenia));
    exports.Set("simulate_gol", Napi::Function::New(env, Plugin::add_wrapped_gol));
    return exports;
}
*/
