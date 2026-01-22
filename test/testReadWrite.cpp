#include <filesystem>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../src/io/Reader.h"
#include "../src/io/Writer.h"

namespace fs = std::filesystem;


TEST(ReaderTest, Basic)
{
    Reader r("../data/example/input.json");
    const Graph g = r.read();
    ASSERT_EQ(g.get_edge_list().size(), 3);
}

TEST(ReaderTest, NonexistentPath)
{
    Reader r("nonexistent/path.json");
    ASSERT_THROW(r.read(), fs::filesystem_error);
}

TEST(WriterTest, Basic)
{
    Graph g(std::vector<std::string>{}, std::vector<std::vector<bool>>{});
    Writer w(g);
    
    fs::path outPath{"output.txt"};
    w.write(outPath);

    ASSERT_TRUE(fs::exists(outPath));
}
