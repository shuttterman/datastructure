#include "Dictionary.h"
#include "getch.h"
void help() {
    printf("[사용법] i-추가 d-삭제 w-단어검색 m-의미검색 p-출력 q-종료 ==>");
}

int main() {
    char command;
    char word[80];
    char meaning[200];
    Dictionary tree;
    
    do {
        help();
        command = getche();
        printf("\n");
        
        switch(command) {
            case 'i' : printf("\t > 삽입 단어 : "); gets(word);
                       printf("\t > 단어 설명 : "); gets(meaning);
                       tree.insert(new BinaryNode(word, meaning));
                       break;
            case 'd' : printf("\t > 삭제 단어 : "); gets(word);
                       tree.remove(word);
                       break;
            case 'p' : tree.printAllwords();
                       printf("\n");
                       break;
            case 'w' : printf("\t > 검색 단어 : "); gets(word);
                       tree.searchWord(word);
                       break;
            case 'm' : printf("\t > 검색 의미 : "); gets(word);
                       tree.searchMeaning(word);
                       break;
        }
    }while(command != 'q');

    return 0;
}

