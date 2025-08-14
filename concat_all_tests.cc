#include <list>
#include <gtest/gtest.h>
#include "concat_all.h"

TEST(ConcatAll, ListOfString) {
    NodeType * heapString1 = (NodeType*)strdup("Frodo");
    NodeType * heapString2 = (NodeType*)strdup("Baggins");
    NodeType list[3];
    list[0] = String;
    list[1] = *heapString1;
    list[2] = *heapString2;
    char *answer = ConcatAll(list);
    const char* expected = "FrodoBaggins";
    EXPECT_STREQ(answer, expected);
    free(heapString1);
    free(heapString2);


}
TEST(ConcatAll, IgnoresIntegers) {
    NodeType * memInt = (NodeType*)malloc(sizeof(int));
    NodeType list[2];
    list[0] = Integer;
    list[1] = *memInt;
    char *answer = ConcatAll(list);
    const char* expected = "";
    EXPECT_STREQ(answer, expected);
    free(memInt);
}

TEST(ConcatAll, Empty) {
    NodeType list[0];
    char *answer = ConcatAll(list);
    const char* expected = "";
    EXPECT_STREQ(answer, expected);
}