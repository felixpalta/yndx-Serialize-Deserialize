#ifndef SERDESER_H
#define SERDESER_H

#include <vector>
#include <stdexcept>

struct Node;
using NodeList = std::vector<Node>;

struct Node
{
private:
    int val;
    bool haveOwnVal;
    NodeList list;
public:

    bool HaveOwnVal() const { return haveOwnVal; }
    int GetOwnVal() const { return haveOwnVal ? val : throw std::runtime_error("Node does not have value");}
    NodeList * GetList() { return haveOwnVal ? throw std::runtime_error("Node does not have list") : &list; }


    Node() : val(0), haveOwnVal(false) {}
    Node(int n) : val(n), haveOwnVal(true) {}

    Node(const NodeList & nl) : val(0), haveOwnVal(false), list(nl) {}
    Node(const Node & other) = default;
    Node (Node && other) = default;
    Node & operator=(const Node & other) = default;
    Node & operator=(Node && other) = default;

    friend
    bool operator==(const Node & a, const Node & b);

    friend
    bool operator!=(const Node & a, const Node & b);
};

bool operator==(const Node & a, const Node & b);

bool operator!=(const Node & a, const Node & b);

std::string SerializeNode(const Node & root);

#endif // SERDESER_H
