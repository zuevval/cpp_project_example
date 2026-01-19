#include <algorithm>
#include <stdexcept>

#include "Graph.h"

Graph::Graph(const std::vector<std::string> &vertices, const std::vector<std::vector<bool>> &edges)
    : m_vertices(vertices), m_edges(edges)
{
    const size_t nVertices = vertices.size();

    if (nVertices != edges.size())
    {
        throw std::invalid_argument("Number of edge rows must match number of vertices");
    }

    for (const auto &row : edges)
    {
        if (row.size() != nVertices)
        {
            throw std::invalid_argument("The `edges` matrix is not square");
        }
    }
}

std::vector<std::pair<std::string, std::string>> Graph::get_edge_list() const
{
    std::vector<std::pair<std::string, std::string>> result;
    const size_t nVertices = m_vertices.size();

    for (size_t i = 0; i < nVertices; i++)
    {
        for (size_t j = i; j < nVertices; j++)
        {
            if (m_edges[i][j])
            {
                result.emplace_back(m_vertices[i], m_vertices[j]);
            }
        }
    }

    std::sort(result.begin(), result.end());
    return result;
}
