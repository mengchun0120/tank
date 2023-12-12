#include <fstream>
#include <sstream>
#include <memory>
#include <commonlib_log.h>
#include <commonlib_exception.h>
#include <commonlib_file_utils.h>

namespace mcdane {
namespace commonlib {

std::string getFileSeparator()
{
#ifdef _WIN32
    return "\\";
#elif __linux__
    return "/";
#endif
}

std::string readText(const std::string &path)
{
    std::ifstream in(path);

    if (!in)
    {
        THROW_EXCEPT(FileException, "Failed to open file " + path);
    }

    std::stringstream ss;
    ss << in.rdbuf();

    if (in.bad())
    {
        THROW_EXCEPT(FileException, "Failed to read file " + path);
    }

    return ss.str();
}

std::string constructPath(std::initializer_list<std::string> pathParts)
{
    return constructPath(std::vector<std::string>(pathParts));
}

std::string constructPath(const std::string &dir,
                          const std::vector<std::string> &path)
{
    std::vector<std::string> tmpPath;
    tmpPath.push_back(dir);
    tmpPath.insert(tmpPath.end(), path.begin(), path.end());
    return constructPath(tmpPath);
}

std::string constructPath(const std::vector<std::string> &path)
{
    if (path.size() == 0) {
        return "";
    }

    std::ostringstream oss;
    std::string separator = getFileSeparator();
    bool empty = true;

    for (auto it = path.begin(); it != path.end(); ++it) {
        if (it->empty())
        {
            continue;
        }

        if (!empty)
        {
            oss << separator;
        }

        oss << *it;
        empty = false;
    }

    return oss.str();
}

} // end of namespace commonlib
} // end of namespace mcdane
