#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../src/graph/Graph.h"

TEST(GraphTest, GetEdgeList)
{
  const std::vector<std::string> v{"a", "b"};
  std::vector<std::vector<bool>> e;
  e.emplace_back(std::vector{false, true});
  e.emplace_back(std::vector{true, false});

  const Graph g(v, e);
  const auto eList = g.get_edge_list();

  EXPECT_EQ(eList.size(), 1);
  EXPECT_TRUE(eList[0].first == "a" || eList[0].second == "b");
}
