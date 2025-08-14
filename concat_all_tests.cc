#include <list>
#include <gtest/gtest.h>
#include "concat_all.h"

TEST(ConcatAll, Empty) {
    NodeType list[0];
    const char *answer = ConcatAll(list);
    const char* expected = "";
    EXPECT_STREQ(answer, expected);
}

TEST(ConcatAll, IgnoresIntegers) {
    auto * intNode = (NodeType*)malloc(sizeof(NodeType) + sizeof(int));
    intNode[0] = Integer;
    const char *answer = ConcatAll(intNode);
    const char* expected = "";
    EXPECT_STREQ(answer, expected);
    free(intNode);
}



TEST(ConcatAll, OneString) {
    auto stringNode = StringNodeNew("Frodo");
    const char *answer = ConcatAll(stringNode);
    const char* expected = "Frodo";
    EXPECT_STREQ(answer, expected);
    free(stringNode);
}

// TEST(ConcatAll, ListMix) {
//     auto heapString1 = (NodeType *)(strdup("Frodo"));
//     NodeType list[2];
//     list[0] = String;
//     list[1] = *heapString1;
//     const char *answer = ConcatAll(list);
//     const char* expected = "Frodo";
//     EXPECT_STREQ(answer, expected);
//     free(heapString1);
// }


TEST(NodeTypeTest, StringNew) {
    const NodeType * stringNode = StringNodeNew("Frodo");
    EXPECT_EQ(stringNode[0], String);
    const char * expected = "Frodo";
    EXPECT_STREQ((char *)(stringNode+ 1), expected);
}

// NodeType * ListNodeNew(const NodeType* head,  const NodeType* tail) {
//     NodeType * listNode = (NodeType *)malloc(sizeof(NodeType) + sizeof(NodeType *) * 2);
//     listNode[0] = List;
//     listNode[1] = *head;
//     listNode[2] = *tail;
//     return listNode;
// }
// TEST(NodeTypeTest, ListStrings) {
//     const NodeType * stringNode = StringNodeNew("Frodo");
//     const NodeType * stringNode2 = StringNodeNew("Baggins");
//     const NodeType * listStringNode = ListNodeNew(stringNode, stringNode2);
//     EXPECT_EQ(listStringNode[0], List);
//     NodeType** pair = (NodeType**)listStringNode[1];
//     EXPECT_STREQ((char *)pair[0], strdup("Frodo"));
//     EXPECT_STREQ((char *)pair[1], strdup("Baggins"));
// }