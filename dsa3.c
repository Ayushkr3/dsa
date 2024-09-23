#include <stdio.h>
#include <string.h>
struct Node {
	char name[25];
	struct Node* next;

};
void Insert(struct Node* head, char* name) {
	if (head->next != 0xcccccccc) {
		Insert(head->next, name);
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(&newNode->name, 25, name);
	newNode->next = 0xcccccccc;
	head->next = newNode;
}
void Insert_overload(struct Node* head, char* name, int index, int* current) {
	if (index == 0) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy_s(&newNode->name, 25, name);
		newNode->next = head;
		head = newNode;
	}
	if (head->next != 0xcccccccc) {
		(*current)++;
		if (*current == index) {
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			strcpy_s(&newNode->name, 25, name);
			newNode->next = head->next;
			head->next = newNode;
			return;
		}
		Insert_overload(head->next, name, index, current);
	}
	else {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy_s(&newNode->name, 25, name);
		head->next = newNode;
		newNode->next = 0xcccccccc;
	}
}
void Remove(struct Node* head, int index, int* current) {
	if (index == 0) {
		head = head->next;
	}
	if (head->next != 0xcccccccc) {
		(*current)++;
		if (*current == index) {
			head->next = head->next->next;
			return;
		}
		Remove(head->next, index, current);
		return;
	}
	else {
		head->next = 0xcccccccc;
	}
}
void printList(struct Node* head) {
	if (head != 0xcccccccc) {
		printf("%s\n", head->name);
		printList(head->next);
	}
}
struct Node* Search(struct Node* head, char* name) {
	if (head != 0xcccccccc) {
		if (strcmp(head->name, name)) {
			return head;
		}
		return Search(head->next, name);
	}
	return 0xcccccccc;
}
int main() {
	struct Node head;
	strcpy_s(&head.name, 25, "abc");

	int nums;
	scanf_s("%d", &nums);
	for (int i = 0; i < nums; i++) {
		char name[25];
		scanf_s("%s", name, 25);
		Insert(&head, name);
	}
	int t = 0;
	printf("List is\n");
	printList(&head);
	int options;
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
			Insert_overload(&head, Input, InputIndex, &t);
			t = 0;
			printList(&head);
			break;
		case 2:
			printf_s("Index\n");
			scanf_s("%d", &InputIndex);
			Remove(&head, InputIndex, &t);
			printList(&head);
			break;
		case 3:
			printList(&head);
			break;
		case 4:
			scanf_s("%s", Input, 25);
			printf(Search(&head, Input)->name);
			printList(&head);
			break;
		}
	}
}

//-------------------------------------------------------------------------------------//




//--------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
struct Node {
	char name[25];
	struct Node* next;
	struct Node* back;
	
};
void Insert(struct Node* head, char* name,struct Node** lastNode) {
	if (head->next != 0xcccccccc) {
		Insert(head->next, name,lastNode);
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy_s(&newNode->name, 25, name);
	newNode->next = 0xcccccccc;
	newNode->back = head;
	*lastNode = newNode;
	head->next = newNode;
}
void Insert_overload(struct Node* head, char* name, int index,int* current, struct Node** lastNode) {
	if (index == 0) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy_s(&newNode->name, 25, name);
		newNode->next = head;
		head->back = newNode;
		newNode->back = 0xcccccccc;
		head = newNode;
	}
	if (head->next != 0xcccccccc) {
		(*current)++;
		if (*current == index) {
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			strcpy_s(&newNode->name, 25, name);
			newNode->next = head->next;
			head->next->back = newNode;
			newNode->back = head;
			head->next = newNode;
			return;
		}
		Insert_overload(head->next, name, index, current,lastNode);
	}
	else {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		strcpy_s(&newNode->name, 25, name);
		head->next = newNode;
		*lastNode = newNode;
		newNode->next = 0xcccccccc;
		newNode->back = head;
	}
}
void Remove(struct Node* head, int index, int* current) {
	if (index == 0) {
		head = head->next;
	}
	if (head->next != 0xcccccccc) {
		(*current)++;
		if (*current == index) {
			head->next = head->next->next;
			head->next->back = head;
			return;
		}
		Remove(head->next, index, current);
		return;
	}
	else {
		head->next = 0xcccccccc;
	}
}
void Remove_overload(struct Node* head,char* name) {
	if (head->next != 0xcccccccc) {
		if (strcmp(head->name,name)) {
			head->next = head->next->next;
			head->next->back = head;
			return;
		}
		Remove_overload(head->next, name);
		return;
	}
	else {
		printf("Not Found");
	}
}
void printList(struct Node* head) {
	if (head != 0xcccccccc) {
		printf("%s\n", head->name);
		return printList(head->next);
	}
	return;
}
void printList_overload(struct Node* head) {
	if (head != 0xcccccccc) {
		printf("%s\n", head->name);
		printList_overload(head->back);
	}
	return;
}
int Search(struct Node* head, char* name,int* current) {
	if (head != 0xcccccccc) {
		if (strcmp(head->name, name)) {
			return head;
		}
		(*current)++;
		return Search(head->next, name,current);
	}
	return *current;
}

int main() {
	struct Node head;
	struct Node* lastNode = 0xcccccccc;
	strcpy_s(&head.name, 25, "abc");
	head.back = 0xcccccccc;
	int nums;
	scanf_s("%d", &nums);
	for (int i = 0; i < nums; i++) {
		char name[25];
		scanf_s("%s", name, 25);
		Insert(&head, name,&lastNode);
	}
	int t = 0;
	int option2;
	printf("List is\n");
	printList(&head);
	printf_s("List Backwards\n");
	printList_overload(lastNode);
	int options;
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
			Insert_overload(&head, Input,InputIndex,&t,&lastNode);
			t = 0;
			printList(&head);
			printf_s("List Backwards\n");
			printList_overload(lastNode);
			break;
		case 2:
			printf("Delete by name or position (0,1)");
			scanf("%d",&option2);
			switch (option2)
			{
			case 0:
				scanf_s("%s",Input,25);
				Remove_overload(&head, Input);
				printList(&head);
				printf_s("List Backwards\n");
				printList_overload(lastNode);
				break;	
			case 1:
				printf_s("Index\n");
				scanf_s("%d", &InputIndex);
				Remove(&head, InputIndex, &t);
				t = 0;
				printList(&head);
				printf_s("List Backwards\n");
				printList_overload(lastNode);
				break;
			}
			break;
		case 3:
			printList(&head);
			printf_s("List Backwards\n");
			printList_overload(lastNode);
			break;
		case 4:
			scanf_s("%s", Input, 25);
			printf(Search(&head, Input,&t));
			printList(&head);
			break;
		}
	}
}
