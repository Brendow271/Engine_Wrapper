#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <stdexcept>

template<typename T>
class Wrapper{
public:
    template<typename Obj, typename... Args>
    Wrapper(Obj *object, T(Obj::*func)(Args...), std::vector<std::pair<std::string, T>> const & inArgs) {
        for (auto& arg : inArgs) {
            args.insert(arg);
        }
        if (inArgs.size() != args.size())
        {
            throw std::runtime_error("ERROR[wrapper]: The names of the arguments should not be repeated");
        }
        command = [this, object, func](std::vector<T>& argsForFunc) {
            return executeFunc(object, func, argsForFunc, std::make_index_sequence<sizeof...(Args)>{});
        };
    }

    template<typename Obj, typename FuncName, size_t... I>
    T executeFunc(Obj *object, FuncName funcName, std::vector<T>& inArgs, std::index_sequence<I...>) {
        return ((object->*funcName)(inArgs[I]...));
    }

    Wrapper(Wrapper const&) = delete;
    Wrapper& operator=(Wrapper const&) = delete;
    Wrapper(Wrapper&&) = default;
    Wrapper& operator=(Wrapper&&) = default;
    ~Wrapper() = default;
    
private:
    std::function<T(std::vector<T>&)> command;
    std::map<std::string, T> args;
};