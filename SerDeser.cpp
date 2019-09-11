#include "SerDeser.h"


std::string SerializeNode(const Node &root)
{
    return "";
}

bool operator==(const Node &a, const Node &b) {
    return a.val == b.val &&
            a.haveOwnVal == b.haveOwnVal &&
            a.list == b.list;
}

bool operator!=(const Node &a, const Node &b) {
    return !(a == b);
}
