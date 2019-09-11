#include <gtest/gtest.h>
#include "SerDeser.h"

TEST(Tests, NodeTest) {
    Node n;
    ASSERT_FALSE(n.HaveOwnVal());
    ASSERT_TRUE(n.GetList().empty());
    ASSERT_THROW(n.GetOwnVal(), std::runtime_error);

    n = 1;
    ASSERT_TRUE(n.HaveOwnVal());
    ASSERT_EQ(n.GetOwnVal(), 1);
    ASSERT_THROW(n.GetList(), std::runtime_error);

    NodeList newList = NodeList{1, 2, 3};

    n = newList;

    ASSERT_FALSE(n.HaveOwnVal());
    ASSERT_EQ(n.GetList().size(), 3);
    ASSERT_EQ(n.GetList(), newList);
}

TEST(Tests, SerializeTests) {
    std::vector<std::pair<Node, std::string>> testNodes{
        {NodeList{}, "[]"},
        {NodeList{NodeList{}}, "[[]]"},
        {NodeList{NodeList{1}}, "[[1]]"},
        {NodeList{1}, "[1]"},
        {NodeList{1, 2, 3}, "[1, 2, 3]"},
        {NodeList{1, 2, NodeList{3}, 4}, "[1, 2, [3], 4]"},
        {NodeList{1, 2, NodeList{3, 4}, 5}, "[1, 2, [3, 4], 5]"},
        {NodeList{1, 2, NodeList{3, 4}, 5, NodeList{}}, "[1, 2, [3, 4], 5, []]"}
    };

    for (auto testCase : testNodes) {
        std::string result = SerializeNode(testCase.first);
        ASSERT_EQ(testCase.second, result);
    }

    ASSERT_THROW(SerializeNode(1), std::runtime_error);
}
