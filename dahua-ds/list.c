#define MAXSIZE 20
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

void InitList();

void ListEmpty();

void ClearList();

Status GetElem(SqList L, int i, ElemType *e);

void LocateElem();

Status ListInsert(SqList *L, int i, ElemType e);

Status ListDelete(SqList *L,int i,ElemType *e) {
    int k;
    if (L->length==0) { // list是空的
        return ERROR;
    }
    if (i<1 || i>L->length) {   //位置不正确
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length) {
        for (k=i; k<L->length; k++) {
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}

void ListLength();

Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    if (L->length == MAXSIZE)
        return ERROR;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (i <= L->length) {
        for (k = L->length; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}