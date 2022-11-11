#include <stdio.h>
#include <limits.h>

int bin[32];
int get_num;
void binary1(int get_num);
void binary2(int get_num);
void oct_8(int get_num);
void hex_16(int get_num);

int main() {
	printf("정수를 입력해 주세요: "); //정수를 입력받는다
	scanf_s("%d", &get_num);//숫자를 입력받음
	if (get_num >= 0) { //양수일 경우
		printf("2진수: ");binary1(get_num); printf("\n");
		printf("8진수: ");oct_8(get_num);printf("\n");
		printf("16진수: ");hex_16(get_num);printf("\n");
	}
	else { //음수일 경우
		printf("2진수: "); binary2(get_num); printf("\n");
		printf("16진수: "); hex_16(get_num); printf("\n");
	}
	return 0;
}

void binary1(int get_num) { //양수-이진수
	int k = 0;
	while (get_num > 0) {
		bin[k] = get_num % 2;
		get_num /= 2;
		k++;
	}
	for (k = 31; k >= 0; k--) {
		printf("%d", bin[k]);
	}
}

void binary2(int get_num) {//음수-이진수
	int k = 0;
	get_num++;
	get_num *= -1;
	while (get_num > 0) {
		bin[k] = get_num % 2;
		get_num /= 2;
		k++;
	}
	for (k = 31; k >= 0; k--) {
		printf("%d", !(bin[k]));
	}
}

void oct_8(int get_num) //8진수 출력
{
	int cnt = 0;
	int k;
	if (get_num > 0) {
		for (k = 0; k < 32; k += 3) {
			if ((get_num >> k) > 0) {
				cnt = k / 3;
			}
		}

		for (k = cnt * 3; k >= 0; k -= 3) {
			printf("%d", (get_num >> k) & 7);
		}
	}
}


void hex_16(int get_num) //16진수 출력
{
	int cnt = 0;
	int k;
	int h;
	if (get_num > 0) {
		for (k = 0; k < 32; k += 4)
			if ((get_num >> k) > 0)
				cnt = k / 4;

	}

	for (k = cnt * 4; k >= 0; k -= 4) {
		h = ((get_num >> k) & 15);
		if (h < 10) 
			printf("%d", h);
		
		else 
			printf("%c", h + 55);
		
	}
}