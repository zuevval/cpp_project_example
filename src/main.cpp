#include <iostream>
#include <filesystem>

#include "io/Reader.h"
#include "io/Writer.h"
#include "graph/Graph.h"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: graphConverter <path/to/input.json>" << std::endl;
        return 1;
    }

    fs::path inputPath{argv[1]};
    try
    {
        Reader reader(inputPath);
        Graph graph = reader.read();
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}