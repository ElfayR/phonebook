#include <stdlib.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    entry* pRet = pHead;
    while (pRet != NULL) {
        int ret = strcasecmp(pRet->lastName, lastName);
        if (ret < 0) {
            pRet = pRet->pLeft;
        } else if (ret > 0) {
            pRet = pRet->pRight;
        } else { // ret = 0
            return pRet;
        }
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    int ret;
    entry* pRoot;
    entry* pInsert;
    pRoot = e;

    pInsert = (entry *) malloc(sizeof(entry));
    pInsert->pLeft = NULL;
    pInsert->pRight = NULL;
    strcpy(pInsert->lastName, lastName);

    while (e != NULL) {
        ret = strcasecmp(e->lastName, lastName);
        if (ret < 0) {
            ;
            if (e->pLeft != NULL) {
                e = e->pLeft;
            } else {
                e->pLeft = pInsert;
                break;
            }

        } else if (ret > 0) {
            if (e->pRight != NULL) {
                e = e-> pRight;
            } else {
                e->pRight = pInsert;
                break;
            }
        } else {
            return pRoot;
        }
    }
    return pRoot;
}
