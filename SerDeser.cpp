#include "SerDeser.h"
#include <sstream>

namespace {
void SerializeNodeImpl(std::ostream & os, const Node &root) {

    if (root.HaveOwnVal()) {
        os << root.GetOwnVal();
        return;
    }
    os << "[";
    bool hadOne = false;
    for (const auto & node : root.GetList()) {
        if (hadOne)
            os << ", ";
        hadOne = true;
        SerializeNodeImpl(os, node);
    }
    os << "]";
}

} // namespace

std::string SerializeNode(const Node &root)
{
    std::ostringstream oss;
    if (root.HaveOwnVal())
        throw std::runtime_error("Serialization: root node must be array");

    SerializeNodeImpl(oss, root);
    return oss.str();
}

bool operator==(const Node &a, const Node &b) {
    return a.val == b.val &&
            a.haveOwnVal == b.haveOwnVal &&
            a.list == b.list;
}

bool operator!=(const Node &a, const Node &b) {
    return !(a == b);
}
