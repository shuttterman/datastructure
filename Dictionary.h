//Dictionary.h
#include "BinarySrchTree.h"
class Dictionary : public BinarySrchTree {
public:
    void printAllwords() {
        printf("\t>>나의 단어장:\n");
        if(!isEmpty()) inorder(root);
    }
    void searchWord(char *word) {
        BinaryNode *node = search(word);
        if(node != NULL) {
            printf("\t>> ");
            node->display();
        }
        else printf("\t>> 등록되지 않은 단어 : %s\n", word);
    }
    void searchMeaning(char *m) {
        BinaryNode *node = (isEmpty()) ? NULL : searchByMeaning(root, m);
        if(node != NULL) {
            printf("\t >> ");
            node->display();
        }
        else printf("\t>> 등록되지 않은 의미 : %s\n", m);
    }
    BinaryNode* searchByMeaning(BinaryNode *node, char *m) {
        if(node==NULL || node->compareMeaning(m)==0) return node;
        BinaryNode *theNode = searchByMeaning(node->getLeft(), m);
        if(the != NULL) return theNode;
        return searchByMeaning(node->getRight(), m);
    }
};
