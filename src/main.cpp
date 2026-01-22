#include <iostream>
#include <filesystem>

#include "io/Reader.h"
#include "io/Writer.h"
#include "graph/Graph.h"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: graphConverter <path/to/input.json> <path/to/output.txt>" << std::endl;
        return 1;
    }

    fs::path inputPath{argv[1]}, outputPath{argv[2]};
    try
    {
        Graph graph = Reader(inputPath).read();
        Writer(graph).write(outputPath);
        std::cout << "Wrote output successfully to " << outputPath << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}