#include <stdio.h>
#include <stdlib.h>
void setData(int* ptr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int * index = ptr + (i * 3 + j);
			scanf_s("%d", index);
		}
	}
}
void getData(int* ptr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int * index =ptr+ (i*3+j);
			printf("%d\t", *index);
		}
		printf("\n");
	}
}
int main() {
	int* ptr = malloc(sizeof(int)*9);
	setData(ptr);
	getData(ptr);
}
//-------------------------------------------------------------------------------------------------------------------------------//




//-------------------------------------------------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char names[25][25] = { "\0" };
void Insert(char* name,int index,int* elements) {
	for (int i = *elements -1; i >=index; i--) {
		strcpy_s(names[i+1],25,names[i]);
	}
	strcpy_s(names[index],25,name);
	*elements = *elements + 1;
}
void Delete(int index,int* elements) {
	int numsofElements = 4;
	for (int i = index; i < *elements; i++) {
		strcpy_s(names[i], 25, names[i + 1]);
	}
	(*elements)--;
}
void printList(int* nums) {
	for (int i = 0; i < *nums; i++) {
		printf_s("%s\n", names[i]);
	}
}
int Search(int* nums,char* arg) {
	for (int i = 0; i < *nums; i++) {
		if (names[0] == arg) {
			return i;
		}
	}
	return -1;
}
int main() {
	int nums=0;
	int options;
	int wantToInsert = 0;
	printf("Enter nums of student\n");
	scanf_s("%d",&wantToInsert);
	for (int i = 0; i < wantToInsert; i++) {
		char name[25];
		scanf_s("%s",name,25);
		Insert(name, i, &nums);
	}
	printList(&nums);
	for (int i = 0; i < 2; i++) {
		printf_s("Enter option");
		scanf_s("%d", &options);
		char Input[25];
		int InputIndex;
		switch (options)
		{
		case 1:
			scanf_s("%s", Input, 25);
			printf_s("Index\n");
			scanf_s("%d", &InputIndex);
			Insert(Input, InputIndex, &nums);
			printList(&nums);
			break;
		case 2:
			printf_s("Index\n");
			scanf_s("%d", &InputIndex);
			Delete(InputIndex, &nums);
			printList(&nums);
			break;
		case 3:
			printList(&nums);
			break;
		case 4:
			scanf_s("%s", Input, 25);
			printf(Search(&nums, Input));
			printList(&nums);
			break;
		}
	}
}

