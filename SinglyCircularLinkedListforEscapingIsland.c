// ������Ʈ��: project#5:Singly Circular Linked List for Escaping Island
// �ۼ���: 2016400 ���ٿ�(����а�)
// �ۼ���: 2022�� 05�� 18�� (ĸ����: 2022�� 05�� 22��) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 11���� ��ȣ�� �̸��� �����ϴ� ����ü �迭 ����
struct content {
	int num;
	char name[20];
};

struct content person[]={
	{1,"Kim Soo Dong"}, {2, "Jeong Da Un"}, {3, "Mark"}, {4, "Alice"}, {5, "Hyo Jin"},
	{6, "Kim Dong Ju"}, {7, "Hong Gil Dong"}, {8, "Dana"}, {9, "Tom"}, {10, "Su Ji"}, {11, "So Ra"}
};

// Skip number�� �� ���� ���ڸ� ����
int Random_Num() {
	int n;
	n = rand() % 9 + 1;
	return n;
}

typedef struct { 	// ����Ʈ ��� ����
	int data;
	struct ListNode* link;
} ListNode;

// ù ��° ���� ���� 
ListNode* insertFront(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
// �޺κ� ����
ListNode* insertRear(ListNode* head, int data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;	// ����� ��� ������ ��ȯ
}

// ��ũ���� ��ȸ�ϴ� �Լ�
void circle(int skipnum, ListNode* head, struct content* pt)
{
	head = head->link;  // ���� header�� 11��° ��带 ����Ű�Ƿ� 1��° ��带 ����Ű���� ����
	int i,j;
	ListNode* t = (ListNode*)malloc(sizeof(ListNode));  //head�� ���󰡸� ����带 ����Ű�� ������
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));  //�����ִ� ����� ����Ʈ�� ����� �� �� ������
	t = head;
	s = head;  // ���� head�� ����Ű�� ���� 11��° �̹Ƿ� 1������ �̵� 
	int rest = 11;  // ���� ���� �ʱⰪ

	while (rest != 3) {
		for (i = 0; i < skipnum; i++) {
			t = head;
			head = head->link;  // head �̵�
		}
		printf("������ ���: %d-%s\n", pt[(head->data)-1].num, pt[(head->data)-1].name);  // �迭�� �ε����� num���� 1 �����Ƿ�
		t->link = head->link; // t�� ���� ���� header �ĳ�带 ����Ű�� �� (���� header�� ����Ű�� ��带 ����)
		head = t->link; // header ���� 
		rest = rest - 1;
		printf("�����ִ� ���: ");
		for (j = 0; j < rest; j++) {
			printf("%d-%s  ", pt[(s->data)-1].num, pt[(s->data)-1].name);  // �迭�� �ε����� num���� 1 �����Ƿ� 
			s = s->link;
		}
		printf("\n");
	}
	printf("���� ����� Ż��!\n");

}

int main(void)
{
	printf("�ۼ���: 2022.05.18, ĸ����: 2022.05.22 Project#5 ���ٿ� 2016400\n");
	ListNode* head = NULL;
	int SkipNumber;

	// 1->2->3-> ... ->11->1
	head = insertRear(head, 2);
	head = insertRear(head, 3);
	head = insertRear(head, 4);
	head = insertRear(head, 5);
	head = insertRear(head, 6);
	head = insertRear(head, 7);
	head = insertRear(head, 8);
	head = insertRear(head, 9);
	head = insertRear(head,10);
	head = insertRear(head, 11);
	head = insertFront(head, 1);

	SkipNumber = Random_Num();
	printf("1���� ���� skip number: %d\n", SkipNumber);
	circle(SkipNumber, head, &person);
}

