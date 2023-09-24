#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	SqList *sqList = (SqList *) malloc(sizeof(SqList));
	int getElem_index = 1;
	ElemType elem;
	ElemType elems[10];
	int elems_index = 0;
	int status = 0;
	int append_num = 0;
	int locate_index = 8;
	int index = 0;
	int insert_index = 11;
	ElemType insert_elem = 99;
	int delete_index = 0;
	ElemType delete_elem;

	printf("SqList::SqList_Init()\n");
	if (sqList != NULL) {
		SqList_Init(sqList);
		printf("List's length: %d\n", sqList->length);
	}

	printf("SqList::SqList_GetElem()\n");
	status = SqList_GetElem(sqList, &getElem_index, &elem);
	if (status == OutOfBound) {
		printf("OutOfBound\n");
	}
	else if (status == ERROR) {
		printf("ERROR\n");
	}
	else {
		printf("The %d's elem of List is %d\n", getElem_index, elem);
	}

	printf("SqList::SqList_Append()\n");
	for (; elems_index < 10; elems_index++) {
		elems[elems_index] = elems_index;
	}
	append_num = SqList_Append(sqList, elems, 10);
	printf("Append_num is %d\n", append_num);
	printf("Now the List'length is %d\n", sqList->length);
	SqList_Print(sqList);
	
	printf("SqList::SqList_GetElem()\n");
	status = SqList_GetElem(sqList, &getElem_index, &elem);
	if (status == OutOfBound) {
		printf("OutOfBound\n");
	}
	else if (status == ERROR) {
		printf("ERROR\n");
	}
	else {
		printf("The %d's elem of List is %d\n", getElem_index, elem);
	}

	printf("SqList::SqList_LocateByElem()\n");
	index = SqList_LocateByElem(sqList, &locate_index);
	printf("The number %d is at %d\n", locate_index, index);

	printf("SqList::SqList_InsertElemByIndex()\n");
	status = SqList_InsertElemByIndex(sqList, &insert_index, &insert_elem);
	if (status == OK) SqList_Print(sqList);
	
	insert_index = 1;
	insert_elem = 111;
	status = SqList_InsertElemByIndex(sqList, &insert_index, &insert_elem);
	if (status == OK) SqList_Print(sqList);

	insert_index = 3;
	insert_elem = 333;
	status = SqList_InsertElemByIndex(sqList, &insert_index, &insert_elem);
	if (status == OK) SqList_Print(sqList);

	printf("SqList::SqList_DeleteElemByIndex()\n");
	delete_index = 1;
	SqList_DeleteElemByIndex(sqList, &delete_index, &delete_elem);
	SqList_Print(sqList);
	printf("%d\n", delete_elem);

	delete_index = 3;
	SqList_DeleteElemByIndex(sqList, &delete_index, &delete_elem);
	SqList_Print(sqList);
	printf("%d\n", delete_elem);

	delete_index = 5;
	SqList_DeleteElemByIndex(sqList, &delete_index, &delete_elem);
	SqList_Print(sqList);
	printf("%d\n", delete_elem);

	delete_index = sqList->length;
	SqList_DeleteElemByIndex(sqList, &delete_index, &delete_elem);
	SqList_Print(sqList);
	printf("%d\n", delete_elem);

	insert_index = sqList->length+1;
	insert_elem = 88;
	SqList_InsertElemByIndex(sqList, &insert_index, &insert_elem);
	SqList_Print(sqList);

	return 0;
}
