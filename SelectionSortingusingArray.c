// ������Ʈ��: project#1: Selection Sort using Array
// �ۼ���: 2016400 ���ٿ�(����а�)
// �ۼ���: 2022�� 05�� 15�� (ĸ����: 2022�� 05�� 21��) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// �迭�� ���Ҹ� ����ϴ� �Լ�
void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	printf("�ۼ���: 2022.05.15, ĸ����: 2022.05.21 Project#1 ���ٿ� 2016400\n");
	// ArrL �迭�� ����(�ʱ�ġ�� ���� ����)
	int ArrL[12];
	// for���� ����
	int i, j;
	//�迭 ������ ����
	int temp, index_min; 
	//�հ� ����� �޴� ����
	int hap = 0; double mean = 0; 

	//ArrL �迭�� �ʱ� �Է��ϰ� 12�ܰ�� ����Ʈ 
	for (i = 0; i < 12; i++)
	{
		printf("%d��° �Է°�: ", i + 1);
		scanf("%d", &ArrL[i]);

		printf("���� �Է� ����: ");
		for (j = 0; j < i + 1; j++)
			printf("%d ", ArrL[j]);

		printf("\n");
	}
	printf("\n");

	//������������ ����
	for (i = 0; i < 11; i++) {
		index_min = i;
		//ArrL[m]�� �� ������ ������ ���Ͽ� ���� ���� ���� �ε����� ��� ����
		for (j = i + 1; j < 12; j++) {
			if (ArrL[index_min] > ArrL[j])
				index_min = j;
		}
		// m�� ���� ���� ���� �ƴ� ���, ������ �ʿ�
		if (i != index_min) {
			temp = ArrL[i];
			ArrL[i] = ArrL[index_min];
			ArrL[index_min] = temp;
			// ������ �ٲ������ print
			printf("������ �ٲ� �� ���� ����: ");
			print_array(ArrL, 12);
		}
	}
	// �������� ������ �Ϸ� �Ǿ����� Ȯ��
	printf("�������� ���� �Ϸ�");
	printf("\n");
	printf("\n");

	// �������� ���İ� ���ÿ� �հ� ��� ���ϱ�
	printf("����(��������) ���� ��: ");
	for (i = 11; i >= 0; i--) {
		printf("%d ", ArrL[i]);
		hap = hap + ArrL[i];
		mean = (double) hap / 12;
	}
	printf("\n");
	printf("��: %d, ���: %f", hap, mean);
	printf("\n");
}