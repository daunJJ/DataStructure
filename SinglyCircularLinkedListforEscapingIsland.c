// 프로젝트명: project#5:Singly Circular Linked List for Escaping Island
// 작성자: 2016400 정다운(통계학과)
// 작성일: 2022년 05월 18일 (캡쳐일: 2022년 05월 22일) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 11명의 번호와 이름을 저장하는 구조체 배열 생성
struct content {
	int num;
	char name[20];
};

struct content person[]={
	{1,"Kim Soo Dong"}, {2, "Jeong Da Un"}, {3, "Mark"}, {4, "Alice"}, {5, "Hyo Jin"},
	{6, "Kim Dong Ju"}, {7, "Hong Gil Dong"}, {8, "Dana"}, {9, "Tom"}, {10, "Su Ji"}, {11, "So Ra"}
};

// Skip number로 쓸 랜덤 숫자를 뽑음
int Random_Num() {
	int n;
	n = rand() % 9 + 1;
	return n;
}

typedef struct { 	// 리스트 노드 구조
	int data;
	struct ListNode* link;
} ListNode;

// 첫 번째 노드로 삽입 
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
// 뒷부분 삽입
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
	return head;	// 변경된 헤드 포인터 반환
}

// 링크따라 순회하는 함수
void circle(int skipnum, ListNode* head, struct content* pt)
{
	head = head->link;  // 현재 header가 11번째 노드를 가리키므로 1번째 노드를 가리키도록 변경
	int i,j;
	ListNode* t = (ListNode*)malloc(sizeof(ListNode));  //head를 따라가며 전노드를 가리키는 포인터
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));  //남아있는 사람의 리스트를 출력할 때 쓸 포인터
	t = head;
	s = head;  // 현재 head가 가리키는 노드는 11번째 이므로 1번으로 이동 
	int rest = 11;  // 남은 수의 초기값

	while (rest != 3) {
		for (i = 0; i < skipnum; i++) {
			t = head;
			head = head->link;  // head 이동
		}
		printf("빠지는 사람: %d-%s\n", pt[(head->data)-1].num, pt[(head->data)-1].name);  // 배열의 인덱스는 num보다 1 작으므로
		t->link = head->link; // t가 다음 노드로 header 후노드를 가리키게 함 (현재 header가 가리키는 노드를 없앰)
		head = t->link; // header 전진 
		rest = rest - 1;
		printf("남아있는 사람: ");
		for (j = 0; j < rest; j++) {
			printf("%d-%s  ", pt[(s->data)-1].num, pt[(s->data)-1].name);  // 배열의 인덱스는 num보다 1 작으므로 
			s = s->link;
		}
		printf("\n");
	}
	printf("남은 세사람 탈출!\n");

}

int main(void)
{
	printf("작성일: 2022.05.18, 캡쳐일: 2022.05.22 Project#5 정다운 2016400\n");
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
	printf("1번이 뽑은 skip number: %d\n", SkipNumber);
	circle(SkipNumber, head, &person);
}

