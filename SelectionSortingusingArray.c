// 프로젝트명: project#1: Selection Sort using Array
// 작성자: 2016400 정다운(통계학과)
// 작성일: 2022년 05월 15일 (캡쳐일: 2022년 05월 21일) 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 배열의 원소를 출력하는 함수
void print_array(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	printf("작성일: 2022.05.15, 캡쳐일: 2022.05.21 Project#1 정다운 2016400\n");
	// ArrL 배열의 선언(초기치를 주지 않음)
	int ArrL[12];
	// for문용 변수
	int i, j;
	//배열 정렬을 위함
	int temp, index_min; 
	//합과 평균을 받는 변수
	int hap = 0; double mean = 0; 

	//ArrL 배열을 초기 입력하고 12단계로 프린트 
	for (i = 0; i < 12; i++)
	{
		printf("%d번째 입력값: ", i + 1);
		scanf("%d", &ArrL[i]);

		printf("현재 입력 상태: ");
		for (j = 0; j < i + 1; j++)
			printf("%d ", ArrL[j]);

		printf("\n");
	}
	printf("\n");

	//오름차순으로 정렬
	for (i = 0; i < 11; i++) {
		index_min = i;
		//ArrL[m]과 그 오른쪽 수들을 비교하여 가장 작은 값의 인덱스를 골라 저장
		for (j = i + 1; j < 12; j++) {
			if (ArrL[index_min] > ArrL[j])
				index_min = j;
		}
		// m이 가장 작은 값이 아닌 경우, 정렬이 필요
		if (i != index_min) {
			temp = ArrL[i];
			ArrL[i] = ArrL[index_min];
			ArrL[index_min] = temp;
			// 순서가 바뀌었으니 print
			printf("순서가 바뀐 후 현재 상태: ");
			print_array(ArrL, 12);
		}
	}
	// 오름차순 정렬이 완료 되었는지 확인
	printf("오름차순 정렬 완료");
	printf("\n");
	printf("\n");

	// 내림차순 정렬과 동시에 합과 평균 구하기
	printf("역순(내림차순) 정렬 후: ");
	for (i = 11; i >= 0; i--) {
		printf("%d ", ArrL[i]);
		hap = hap + ArrL[i];
		mean = (double) hap / 12;
	}
	printf("\n");
	printf("합: %d, 평균: %f", hap, mean);
	printf("\n");
}