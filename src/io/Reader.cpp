#include "Reader.h"

#include <fstream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Graph Reader::read() const
{
    if (!fs::exists(m_path))
        throw fs::filesystem_error(
            "Input file missing",
            m_path,
            std::make_error_code(std::errc::no_such_file_or_directory));

    std::ifstream f(m_path);
    json data = json::parse(f);
    json edgesJson = data["edges"];

    std::vector<std::vector<bool>> edges;
    for (const auto &row : edgesJson)
    {
        edges.emplace_back(std::vector<bool>{});
        for (const auto &elem : row)
            edges.back().emplace_back(elem == 1);
    }

    return Graph(data["vertices"], edges);
}
