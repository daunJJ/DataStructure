// 프로젝트명: project#4:Expression Stack using Linked List
// 작성자: 2016400 정다운(통계학과)
// 작성일: 2022년 05월 17일 (캡쳐일: 2022년 05월 22일) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{  // char형 데이터를 받는 리스트 노드 구조
	char data;
	struct stackNode* link;
}stackNode;

typedef struct {  // double형 데이터를 받는 리스트 노드 구조
	double data;
	struct stackNoded* link;
}stackNoded;

// 스택이 공백인지를 검사 
int isEmpty(stackNode** top) {
	if (*top == NULL) return 1;
	else return 0;
}

// 스택에 원소 삽입 
void push(stackNode** top, char data1) {
	stackNode* temp;
	temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = data1;
	temp->link = *top;
	*top = temp;
}

// 스택의 탑 원소를 삭제하여 반환
char pop(stackNode** top) {
	stackNode* temp;
	temp = *top;
	char data1;
	data1 = temp->data;
	*top = temp->link;
	free(temp);
	return data1;
	if (isEmpty(&top)) {
		printf("Stack is empty\n");
		return -1;
	}
}

// 연산자를 스택에 삽입시 우선순위를 계산하기 위한 함수
int priority(char ch) {
	switch (ch) {
	case '(': case ')': return 1;
	case '+': case '-': return 2;
	case '*': case '/': return 3;
	}
	return -1;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
void ChangetoPostfix(char* infix, char* postfix)
{
	stackNode* top = NULL;
	int i; // for문용 변수
	int t = 0;  //postfix의 인덱스를 따라가는 담당
	int len = strlen(infix);
	char symbol;  // infix에서 연산자와 피연산자 구분 

	for (i = 0; i < len; i++)
	{

		symbol = infix[i];

		switch (symbol)
		{
		case '(':
			push(&top, symbol);
			break;
		case ')':
			while (top->data != '(') {
				postfix[t++] = pop(&top);
			}
			top = top->link;// 남아있는 '('를 없앰
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			if (top != NULL) {
				while ((priority(symbol) < priority(top->data)) || (priority(symbol) == priority(top->data))) {
					postfix[t++] = pop(&top);
					if (top == NULL) break;
				}
				push(&top, symbol);
			}
			else {
				push(&top, symbol);
			}
			break;
		default:
			postfix[t++] = symbol;
			break;
		}
	}
	while (!isEmpty(&top)) {
		postfix[t++] = pop(&top);
	}
}

// 계산을 위해 double형 스택을 새로 만듬 
// 스택이 공백인지를 검사 
int isEmptyd(stackNoded** top) {
	if (*top == NULL) return 1;
	else return 0;
}

// 스택에 원소 삽입 
void pushd(stackNoded** top, double data1) {
	stackNoded* temp;
	temp = (stackNoded*)malloc(sizeof(stackNoded));
	temp->data = data1;
	temp->link = *top;
	*top = temp;
}

// 스택의 탑 원소를 삭제하여 반환
double popd(stackNoded** top) {
	stackNoded* temp;
	temp = *top;
	double data1;
	data1 = temp->data;
	*top = temp->link;
	free(temp);
	return data1;
	if (isEmpty(&top)) {
		printf("Stack is empty\n");
		return -1;
	}
}

//후위표기식 계산 함수
double evalPostfix(char* postfix)
{
	stackNoded* top = NULL;
	int i; // for문용 변수
	int len = strlen(postfix);
	char symbol;  // infix에서 연산자와 피연산자 구분 
	double value;  // 피연산자 형변환
	double var1, var2;  // 스택에서 꺼내올 숫자

	for (i = 0; i < len; i++)
	{

		symbol = postfix[i];

		if (symbol != '+' && symbol != '-' && symbol != '/' && symbol != '*') {  // 피연산자이면 스택에 삽입
			value = (double)(symbol - '0');
			pushd(&top, value);
		}
		else { //연산자이면 스택에서 숫자 2개를 꺼내 계산 후 다시 삽입
			var2 = popd(&top);
			var1 = popd(&top);
			switch (symbol) {
			case '+':
				pushd(&top, var1 + var2); break;
			case '-':
				pushd(&top, var1 - var2); break;
			case '*':
				pushd(&top, var1 * var2); break;
			case '/':
				pushd(&top, var1 / var2); break;
			}
		}
	}
	return top->data;
}


// 수식을 입력 받고 후위 표기식으로 변환, 계산
int main(void)
{
	printf("작성일: 2022.05.17, 캡쳐일: 2022.05.22 Project#4 정다운 2016400\n");
	char F_original[100] = "";
	char F_postfix[100] = "";

	printf("수식을 입력하세요: ");
	scanf("%s", F_original);
	ChangetoPostfix(F_original, F_postfix);
	printf("후위표기식으로 변환 후(postfix): ");
	ChangetoPostfix(F_original, F_postfix);
	printf("%s\n", F_postfix);
	printf("postfix 계산 결과: ");
	printf("%f\n", evalPostfix(F_postfix));

}

//(3+5)*((2+6)/(9-7))-1

