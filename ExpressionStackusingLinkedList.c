// ������Ʈ��: project#4:Expression Stack using Linked List
// �ۼ���: 2016400 ���ٿ�(����а�)
// �ۼ���: 2022�� 05�� 17�� (ĸ����: 2022�� 05�� 22��) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{  // char�� �����͸� �޴� ����Ʈ ��� ����
	char data;
	struct stackNode* link;
}stackNode;

typedef struct {  // double�� �����͸� �޴� ����Ʈ ��� ����
	double data;
	struct stackNoded* link;
}stackNoded;

// ������ ���������� �˻� 
int isEmpty(stackNode** top) {
	if (*top == NULL) return 1;
	else return 0;
}

// ���ÿ� ���� ���� 
void push(stackNode** top, char data1) {
	stackNode* temp;
	temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = data1;
	temp->link = *top;
	*top = temp;
}

// ������ ž ���Ҹ� �����Ͽ� ��ȯ
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

// �����ڸ� ���ÿ� ���Խ� �켱������ ����ϱ� ���� �Լ�
int priority(char ch) {
	switch (ch) {
	case '(': case ')': return 1;
	case '+': case '-': return 2;
	case '*': case '/': return 3;
	}
	return -1;
}

// ���� ǥ����� ���� ǥ������� ��ȯ�ϴ� �Լ�
void ChangetoPostfix(char* infix, char* postfix)
{
	stackNode* top = NULL;
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
			while (top->data != '(') {
				postfix[t++] = pop(&top);
			}
			top = top->link;// �����ִ� '('�� ����
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

// ����� ���� double�� ������ ���� ���� 
// ������ ���������� �˻� 
int isEmptyd(stackNoded** top) {
	if (*top == NULL) return 1;
	else return 0;
}

// ���ÿ� ���� ���� 
void pushd(stackNoded** top, double data1) {
	stackNoded* temp;
	temp = (stackNoded*)malloc(sizeof(stackNoded));
	temp->data = data1;
	temp->link = *top;
	*top = temp;
}

// ������ ž ���Ҹ� �����Ͽ� ��ȯ
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

//����ǥ��� ��� �Լ�
double evalPostfix(char* postfix)
{
	stackNoded* top = NULL;
	int i; // for���� ����
	int len = strlen(postfix);
	char symbol;  // infix���� �����ڿ� �ǿ����� ���� 
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
	return top->data;
}


// ������ �Է� �ް� ���� ǥ������� ��ȯ, ���
int main(void)
{
	printf("�ۼ���: 2022.05.17, ĸ����: 2022.05.22 Project#4 ���ٿ� 2016400\n");
	char F_original[100] = "";
	char F_postfix[100] = "";

	printf("������ �Է��ϼ���: ");
	scanf("%s", F_original);
	ChangetoPostfix(F_original, F_postfix);
	printf("����ǥ������� ��ȯ ��(postfix): ");
	ChangetoPostfix(F_original, F_postfix);
	printf("%s\n", F_postfix);
	printf("postfix ��� ���: ");
	printf("%f\n", evalPostfix(F_postfix));

}

//(3+5)*((2+6)/(9-7))-1

