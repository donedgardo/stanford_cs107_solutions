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
            return strdup("");
        case Nil:
            return strdup("");
        case String:
            return strdup((char *)(list + 1));
        case List:
            auto payload = (NodeType**)(list + 1);
            char* head = ConcatAll(payload[0]);
            char* tail = ConcatAll(payload[1]);
            char* result = (char *)malloc(strlen(head) + strlen(tail) + 1);
            strcpy(result, head);
            strcat(result, tail);
            free(head);
            free(tail);
            return result;
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

static NodeType * ListNodeNew(NodeType* head,  NodeType* tail) {
    char * nodeMemory = (char *)malloc(sizeof(NodeType) + 2  * sizeof(NodeType *));
    if (!nodeMemory) return NULL;
    NodeType *node = (NodeType *)nodeMemory;
    *node = List;
    auto payload = (NodeType**)(node + 1);
    payload[0] = head;
    payload[1] = tail;
    return node;
}

static NodeType* NilNodeNew() {
    auto *nilNode = (NodeType *)(malloc(sizeof(NodeType)));
    *nilNode = Nil;
    return nilNode;
}

#ifdef __cplusplus
}
#endif