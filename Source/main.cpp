#include <stdio.h>

#include "RBTree.hpp"
#include "Map.hpp"

template<typename T>
struct GenericCompare {
    int operator ()(const T& left, const T& right) const {
        if (left < right) {
            return -1;
        }
        else if (left > right) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

using DataNode_t = RBTreeNode<int>;
using Compare_t = GenericCompare<int>;
using RBTree_t = RBTree<DataNode_t, Compare_t>;

void PrintRBTree(RBTree_t& rbTree) {
    ::printf("PrintRBTree\n");
    ::printf("Size: %d\n", rbTree.GetSize());
    
    DataNode_t* node = rbTree.First();
    while (!IsNull(node)) {
        ::printf("Value: %d\n", node->m_value);
        node = rbTree.Forward(node);
    }
}

void TestRBTree() {
    ::printf("PrintRBTree\n");

    DataNode_t a, b, c;
    a.m_value = 1;

    b.m_value = 3;

    c.m_value = 2;

    RBTree<DataNode_t, Compare_t> rbTree;
    rbTree.InsertUnique(&a);
    rbTree.InsertUnique(&b);
    rbTree.InsertUnique(&c);

    PrintRBTree(rbTree);

    auto first = rbTree.First();
    auto last = rbTree.Last();

    auto target = rbTree.Search(2);
    auto backward = rbTree.Backward(target);
    auto forward = rbTree.Forward(target);

    rbTree.Remove(&c);
    first = rbTree.First();
    last = rbTree.Last();

    PrintRBTree(rbTree);
}

using Map_t = Map<int, int, Compare_t>;

void PrintMap(Map_t& map) {
    ::printf("PrintMap\n");
    ::printf("Size: %d\n", map.GetSize());

    for (auto iter = map.Begin(); iter != map.End(); ++iter) {
        ::printf("Key: %d, Value: %d\n", iter->first, iter->second);
    }
}

void TestMap() {
    ::printf("TestMap\n");

    Map_t map;
    map.Insert(1, 101);
    map.Insert(1, 1001);
    map.Insert(-2, -2);
    map.Insert(252, 252);
    map.Insert(33, 33);
    map.Insert(3342, 3342);
    map.Insert(-9, -9);

    PrintMap(map);

    auto iter = map.Find(-2);

    map.Erase(iter);
    map.Erase(3342);

    map.Insert(44, 44);
    map.Insert(-65, -65);

    PrintMap(map);
}

int main() {
    TestRBTree();
    TestMap();

    return 0;
}