// ������Ʈ��: project#3:Expression Stack using Array
// �ۼ���: 2016400 ���ٿ�(����а�)
// �ۼ���: 2022�� 05�� 16�� (ĸ����: 2022�� 05�� 22��) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100 // ������ �ִ� ũ��
char stack_c[STACK_SIZE];  // ����ǥ������� ��ȯ �� ����� ���� 
double stack_d[STACK_SIZE]; // ����ǥ��� ��� �� ����� ����

// ���ÿ� ���� ���� 
void push(int* top, char item) {
	if (*top >= STACK_SIZE - 1) {  // ������ ������ ���
		printf("Stack is full\n");
		return -1;
	}
	stack_c[++(*top)] = item;  // top�� top+1�� 
}

// ������ ž ���Ҹ� �����Ͽ� ��ȯ
char pop(int* top) {
	if (*top == -1) {  // ������ ������ ���
		printf("Stack is empty\n");
		return -1;
	}
	else return stack_c[(*top)--];  // top�� top-1��
}

// ������ ���������� �˻� 
int isEmpty(int* top) {
	if (*top == -1) return 1;
	else return 0;
}

// �����ڸ� ���ÿ� ���Խ� �켱������ ����ϱ� ���� �Լ�
int priority(char ch) {
	switch (ch) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ����� ���� ǥ������� ��ȯ�ϴ� �Լ�
void ChangetoPostfix(char* infix, char* postfix)
{
	int top = -1;  // stack�� top�� ������ ����
	int i; // for���� ����
	int t = 0;  //postfix�� �ε����� ���󰡴� ���
	int len = strlen(infix);
	char symbol;  // infix���� �����ڿ� �ǿ����� ����  

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
			top--; // �����ִ� '('�� ����
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

// ����� ���� double�� ������ ���� ���� 
// ���ÿ� ���� ����
void pushd(int* top, double item) {
	if (*top >= STACK_SIZE - 1) {  // ������ ������ ���
		printf("Stack is full\n");
		return;
	}
	stack_d[++(*top)] = item;  // top�� top+1�� 
}
// ������ ž ���Ҹ� �����Ͽ� ��ȯ
double popd(int* top) {
	if (*top == -1) {  // ������ ������ ���
		printf("Stack is empty\n");
		return -1;
	}
	else return stack_d[(*top)--];  // top�� top-1��
}

// ����ǥ��� ��� �Լ�
double evalPostfix(char* postfix)
{
	int top = -1;  // stack�� top�� ������ ����
	int i; // for���� ����
	int len = strlen(postfix);
	char symbol;  // postfix���� �����ڿ� �ǿ����� ���� 
	double value;  // �ǿ����� ����ȯ
	double var1, var2;  // ���ÿ��� ������ ����

	for (i = 0; i < len; i++)
	{

		symbol = postfix[i];

		if (symbol != '+' && symbol != '-' && symbol != '/' && symbol != '*') {  // �ǿ������̸� ���ÿ� ����
			value = (double)(symbol - '0');
			pushd(&top, value);
		}
		else { //�������̸� ���ÿ��� ���� 2���� ���� ��� �� �ٽ� ����
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



// ������ �Է� �ް� ���� ǥ������� ��ȯ, ���
int main(void)
{
	printf("�ۼ���: 2022.05.16, ĸ����: 2022.05.22 Project#3 ���ٿ� 2016400\n");
	char F_original[100] = "";
	char F_postfix[100] = "";

	printf("������ �Է��ϼ���: ");
	scanf("%s", F_original);
	ChangetoPostfix(F_original, F_postfix);
	printf("����ǥ������� ��ȯ ��(postfix): ");
	printf("%s\n", F_postfix);
	printf("postfix ��� ���: ");
    printf("%f\n", evalPostfix(F_postfix));

}

//(4+3)*((2+5)/(9-7))*2-3