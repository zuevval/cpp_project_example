#pragma once

#include <filesystem>

#include "../graph/Graph.h"

namespace fs = std::filesystem;

class Reader
{
protected:
    const fs::path m_path;

public:
    Reader(const fs::path &jsonPath) : m_path(jsonPath) {};
    Graph read() const;
};
