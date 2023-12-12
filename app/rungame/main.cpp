#include <iostream>
#include <fstream>
#include <cstdlib>
#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <commonlib_argument_parser.h>
#include <commonlib_validator.h>
#include <tankapp_rungame_app.h>

using namespace mcdane::commonlib;
using namespace mcdane::tankapp;

struct Arguments {
    std::string appConfigFile_;
    std::string appDir_;
    std::string mapFile_;
    std::string logFile_;
    std::string logLevel_;
};

void initArguments(Arguments &args, int argc, char *argv[])
{
    ArgumentParser parser;

    parser.init({
        Argument::create(args.appConfigFile_,
                         "appConfig",
                         "c",
                         "appConfig",
                         "Config file for app",
                         false,
                         k_nonEmptyStrV),
        Argument::create(args.appDir_,
                         "appDir",
                         "a",
                         "appDir",
                         "App directory",
                         false,
                         k_nonEmptyStrV),
        Argument::create(args.mapFile_,
                         "mapFile",
                         "m",
                         "mapFile",
                         "Map file",
                         true,
                         k_nonEmptyStrV),
        Argument::create(args.logFile_,
                         "logFile",
                         "l",
                         "logFile",
                         "Log file",
                         false,
                         k_nonEmptyStrV),
        Argument::create(args.logLevel_,
                         "logLevel",
                         "v",
                         "logLevel",
                         "Log level",
                         true,
                         k_nonEmptyStrV),
    });

    parser.parse(argc, argv);
}

void initLog(std::ofstream &logStream,
             const std::string &logFile,
             const std::string &logLevelStr)
{
    logStream.open(logFile);

    if (!logStream.good())
    {
        THROW_EXCEPT(FileException, "Failed to open file " + logFile);
    }

    Logger::LogLevel level = Logger::LEVEL_DEBUG;

    if (!logLevelStr.empty())
    {
        level = Logger::strToLevel(logLevelStr);
    }

    Logger::initInstance(logStream, level);
}

int main(int argc, char *argv[])
{
    Arguments args;
    std::ofstream logStream;

    try
    {
        initArguments(args, argc - 1, argv + 1);
        initLog(logStream, args.logFile_, args.logLevel_);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception happened: " << e.what() << std::endl;
        exit(1);
    }


    try
    {
        RunGameApp app;
        app.init(args.appConfigFile_, args.appDir_, args.mapFile_);
        app.run();
    }
    catch (const std::exception &e)
    {
        LOG_ERROR << "Exception happended: " << e.what() << LOG_END;
        exit(1);
    }
}

