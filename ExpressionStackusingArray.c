// 프로젝트명: project#3:Expression Stack using Array
// 작성자: 2016400 정다운(통계학과)
// 작성일: 2022년 05월 16일 (캡쳐일: 2022년 05월 22일) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100 // 스택의 최대 크기
char stack_c[STACK_SIZE];  // 후위표기식으로 변환 시 사용할 스택 
double stack_d[STACK_SIZE]; // 후위표기식 계산 시 사용할 스택

// 스택에 원소 삽입 
void push(int* top, char item) {
	if (*top >= STACK_SIZE - 1) {  // 스택이 만원인 경우
		printf("Stack is full\n");
		return -1;
	}
	stack_c[++(*top)] = item;  // top은 top+1로 
}

// 스택의 탑 원소를 삭제하여 반환
char pop(int* top) {
	if (*top == -1) {  // 스택이 공백인 경우
		printf("Stack is empty\n");
		return -1;
	}
	else return stack_c[(*top)--];  // top은 top-1로
}

// 스택이 공백인지를 검사 
int isEmpty(int* top) {
	if (*top == -1) return 1;
	else return 0;
}

// 연산자를 스택에 삽입시 우선순위를 계산하기 위한 함수
int priority(char ch) {
	switch (ch) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
void ChangetoPostfix(char* infix, char* postfix)
{
	int top = -1;  // stack의 top을 지정할 변수
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
			while (stack_c[top] != '(') {
				postfix[t++] = pop(&top);
			}
			top--; // 남아있는 '('를 없앰
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (priority(symbol) <= priority(stack_c[top])) {
				postfix[t++] = pop(&top);
			}
			push(&top, symbol);
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
// 스택에 원소 삽입
void pushd(int* top, double item) {
	if (*top >= STACK_SIZE - 1) {  // 스택이 만원인 경우
		printf("Stack is full\n");
		return;
	}
	stack_d[++(*top)] = item;  // top은 top+1로 
}
// 스택의 탑 원소를 삭제하여 반환
double popd(int* top) {
	if (*top == -1) {  // 스택이 공백인 경우
		printf("Stack is empty\n");
		return -1;
	}
	else return stack_d[(*top)--];  // top은 top-1로
}

// 후위표기식 계산 함수
double evalPostfix(char* postfix)
{
	int top = -1;  // stack의 top을 지정할 변수
	int i; // for문용 변수
	int len = strlen(postfix);
	char symbol;  // postfix에서 연산자와 피연산자 구분 
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
	return stack_d[top];
}



// 수식을 입력 받고 후위 표기식으로 변환, 계산
int main(void)
{
	printf("작성일: 2022.05.16, 캡쳐일: 2022.05.22 Project#3 정다운 2016400\n");
	char F_original[100] = "";
	char F_postfix[100] = "";

	printf("수식을 입력하세요: ");
	scanf("%s", F_original);
	ChangetoPostfix(F_original, F_postfix);
	printf("후위표기식으로 변환 후(postfix): ");
	printf("%s\n", F_postfix);
	printf("postfix 계산 결과: ");
    printf("%f\n", evalPostfix(F_postfix));

}

//(4+3)*((2+5)/(9-7))*2-3