#include <gtest/gtest.h>
#include "SerDeser.h"

TEST(Tests, FirstTest) {
    Node n;
    ASSERT_FALSE(n.HaveOwnVal());
    ASSERT_NE(n.GetList(), nullptr);
    ASSERT_TRUE(n.GetList()->empty());
    ASSERT_THROW(n.GetOwnVal(), std::runtime_error);

    n = 1;
    ASSERT_TRUE(n.HaveOwnVal());
    ASSERT_EQ(n.GetOwnVal(), 1);
    ASSERT_THROW(n.GetList(), std::runtime_error);

    NodeList newList = NodeList{1, 2, 3};

    n = newList;

    ASSERT_FALSE(n.HaveOwnVal());
    ASSERT_NE(n.GetList(), nullptr);
    ASSERT_EQ(n.GetList()->size(), 3);
    ASSERT_EQ(*n.GetList(), newList);



}
