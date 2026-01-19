#pragma once

#include <string>
#include <vector>

class Graph
{
protected:
    const std::vector<std::string> m_vertices;
    const std::vector<std::vector<bool>> m_edges;

public:
    Graph(const std::vector<std::string> &vertices, const std::vector<std::vector<bool>> &edges);
    std::vector<std::pair<std::string, std::string>> get_edge_list() const;
};
