#include "Writer.h"

#include <fstream>

void Writer::write(const fs::path &jsonPath) const
{
    const std::vector<std::pair<std::string, std::string>> edgeList = m_graph.get_edge_list();

    std::ofstream f(jsonPath);

    for (const auto &edge : edgeList)
        f << edge.first << "-" << edge.second << std::endl;
}