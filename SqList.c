#include "SqList.h"
#include <stdio.h>

Status SqList_Init(SqList *sqList) {
	if (sqList == NULL) {
		return ERROR;
	}
	sqList->length = 0;
	return OK;
}

Status SqList_GetElem(const SqList *sqList, const int *index, ElemType *elem) {
	if (sqList == NULL || index == NULL || elem == NULL) {
		return ERROR;
	}
	if (*index < 1 || *index > sqList->length) {
		return OutOfBound;
	}

	*elem = sqList->datas[*index-1];
	return OK;
}

Status SqList_SetElem(SqList *sqList, const int *index, const ElemType *elem) {
	if (sqList == NULL || index == NULL || elem == NULL) {
		return ERROR;
	}
	if (*index < 1 || *index > sqList->length) {
		return OutOfBound;
	}
	
	sqList->datas[*index-1] = *elem;
	return OK;
}

Status SqList_AppendOne(SqList *sqList, const ElemType *elem) {
	if (sqList == NULL || elem == NULL) {
		return ERROR;
	}
	if (sqList->length >= MAXSIZE) {
		return ERROR;
	}

	sqList->datas[sqList->length] = *elem;
	++sqList->length;
	return OK;
}

int SqList_Append(SqList *sqList, const ElemType *array, int len) {
	int available_append_num = 0;
	int i = 0;

	if (sqList == NULL || array == NULL) {
		return ERROR;
	}

	available_append_num = MAXSIZE - sqList->length;
	for (; i <= available_append_num && i < len; i++) {
		SqList_AppendOne(sqList, &array[i]);
	}
	
	return i;
}

int SqList_LocateByElem(const SqList *sqList, const ElemType *elem) {
	int i = 0;
	for (; i < sqList->length; i++) {
		if (sqList->datas[i] == *elem) {
			return i;
		}
	}
	return -1;
}

void SqList_Print(const SqList *sqList) {
	int i = 0;
	for (; i < sqList->length-1; i++) {
		printf("%d ", sqList->datas[i]);
	}
	printf("%d\n", sqList->datas[i]);
}

Status SqList_InsertElemByIndex(SqList *sqList, const int *index, const ElemType *elem) {
	int i = 0;
	if (sqList == NULL || index == NULL || elem == NULL) {
		return ERROR;
	}
	if (sqList->length >= MAXSIZE) {
		return ERROR;
	}
	if (*index < 1 || *index > sqList->length+1) {
		return ERROR;
	}
	if (*index <= sqList->length) {
		for (i = sqList->length; i >= *index; i--) {
			sqList->datas[i] = sqList->datas[i-1];
		}
	}
	sqList->datas[*index-1] = *elem;
	++sqList->length;
	return OK;
}

Status SqList_DeleteElemByIndex(SqList *sqList, const int *index, ElemType *elem) {
	int i = 0;
	if (sqList == NULL || index == NULL || elem == NULL) {
		return ERROR;
	}
	if (sqList->length == 0) {
		return ERROR;
	}
	if (*index < 1 || *index > sqList->length) {
		return ERROR;
	}

	*elem = sqList->datas[*index-1];
	if (*index < sqList->length) {
		for (i = *index-1; i < sqList->length-1; i++) {
			sqList->datas[i] = sqList->datas[i+1];
		}
	}
	--sqList->length;
	return OK;
}