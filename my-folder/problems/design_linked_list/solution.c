typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;

    for(int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* n = malloc(sizeof(Node));

    n->val = val;
    n->next = obj->head;
    obj->head = n;

    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* n = malloc(sizeof(Node));

    n->val = val;
    n->next = NULL;

    if(obj->head == NULL) {
        obj->head = n;
    } else {
        Node* temp = obj->head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)
        return;

    if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* temp = obj->head;

    for(int i = 0; i < index - 1; i++)
        temp = temp->next;

    Node* n = malloc(sizeof(Node));
    n->val = val;
    n->next = temp->next;
    temp->next = n;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return;

    if(index == 0) {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        obj->size--;
        return;
    }

    Node* temp = obj->head;

    for(int i = 0; i < index - 1; i++)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = del->next;

    free(del);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* temp = obj->head;

    while(temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    free(obj);
}