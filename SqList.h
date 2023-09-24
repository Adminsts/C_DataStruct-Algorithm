#define MAXSIZE 30
#define OK 1
#define ERROR 0
#define OutOfBound -1

typedef int Status;
typedef int ElemType;
typedef struct SqList {
	ElemType datas[MAXSIZE];
	int length;
} SqList;

Status SqList_Init(SqList *sqList);
Status SqList_GetElem(const SqList *sqList, const int *index, ElemType *elem);
Status SqList_SetElem(SqList *sqList, const int *index, const ElemType *elem);
Status SqList_AppendOne(SqList *sqList, const ElemType *elem);
int SqList_Append(SqList *sqList, const ElemType *array, int len);
int SqList_LocateByElem(const SqList *sqList, const ElemType *elem);
Status SqList_InsertElemByIndex(SqList *sqList, const int *index, const ElemType *elem);
Status SqList_DeleteElemByIndex(SqList *sqList, const int *index, ElemType *elem);
void SqList_Print(const SqList *sqList);