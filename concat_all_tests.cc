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



TEST(ConcatAll, StringList) {
    auto *stringNode = StringNodeNew("Frodo");
    auto *stringNode2 = StringNodeNew("Baggins");
    auto *nillNode = NilNodeNew();
    auto *tail = ListNodeNew(stringNode2, nillNode);
    auto *head = ListNodeNew(stringNode, tail);
    const char* answer = ConcatAll(head);
    const char* expected = "FrodoBaggins";
    EXPECT_STREQ(answer, expected);
    if (answer) {
        free((char *)answer);
    }
    free(stringNode);
    free(stringNode2);
    free(nillNode);
}


TEST(NodeTypeTest, StringNew) {
    const NodeType * stringNode = StringNodeNew("Frodo");
    EXPECT_EQ(stringNode[0], String);
    const char * expected = "Frodo";
    EXPECT_STREQ((char *)(stringNode+ 1), expected);
}


TEST(NodeTypeTest, ListStrings) {
    NodeType * stringNode = StringNodeNew("Frodo");
    NodeType * stringNode2 = StringNodeNew("Baggins");
    NodeType * listStringNode = ListNodeNew(stringNode, stringNode2);
    EXPECT_EQ(listStringNode[0], List);
    auto **payload = (NodeType**)(listStringNode + 1);
    auto *headPtr = payload[0];
    const char * expected = "Frodo";
    EXPECT_STREQ((char *)(headPtr + 1), expected);
    auto *tailPtr = payload[1];
    expected = "Baggins";
    EXPECT_STREQ((char *)(tailPtr + 1), expected);
    free(stringNode);
    free(stringNode2);
    free(listStringNode);
}