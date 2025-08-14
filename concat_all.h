#pragma once
#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
    Integer, String, List, Nil
   } NodeType;

static char *ConcatAll(const NodeType *list) {
    switch (*list) {
        case Integer:
        case String:
            return strdup((char *)(list + 1));
    }
    return strdup("");
}

static NodeType * StringNodeNew(const char * str) {
    const size_t len = strlen(str) + 1;
    auto * stringNode = (NodeType *)malloc(sizeof(NodeType) + len);
    if (!stringNode) return NULL;
    stringNode[0] = String;
    memcpy((char *)(stringNode+1), str, len);
    return stringNode;
}

#ifdef __cplusplus
}
#endif