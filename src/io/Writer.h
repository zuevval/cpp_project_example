#pragma once

#include <filesystem>

#include "../graph/Graph.h"

namespace fs = std::filesystem;

class Writer
{
protected:
    Graph m_graph;

public:
    Writer(const Graph &graph) : m_graph(graph) {};
    void write(const fs::path &jsonPath) const;
};
