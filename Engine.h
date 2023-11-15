#pragma once
#include "Wrapper.h"
class Engine{
public:
    template<typename T>
    void register_command(Wrapper<T>* wrapper, std::string const& command)
    {
        if (commands.find(command) != commands.end())
        {
            std::string error = "ERROR[engine]: Command " + command + " already exist";
            throw std::runtime_error(error.c_str());
        }
        commands.insert({ command, wrapper });
    }
    Engine() = default;
    Engine(Engine const&) = delete;
    Engine& operator =(Engine const&) = delete;
    Engine(Engine&&) = default;
    Engine& operator =(Engine&&) = default;
    ~Engine() = default;
private:
    std::map<std::string, void*> commands;
};

