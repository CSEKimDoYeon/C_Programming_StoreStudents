#include "Common.h"
#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

Boolean AppIO_in_doesContinueToInputNextStudent()
{
	//사용자로부터 성적 입력 여부를 입력받는다.
	printf("\n? 성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오: ");
	char answer = getcharDirectlyFromKeyboard();
	// 다음에 나오는 “Keyboard 에서 직접 문자 입력 받기” 설명을 참고하시오.
	if (answer == 'Y' || answer == 'y')
		return TRUE;
	else
		printf("\n입력을 종료합니다.\n");
		return FALSE;
}

char getcharDirectlyFromKeyboard(void)
{ /*기존 엔터를 누르는 방식이 아닌 키보드에서
  누르는 순간 바로 인식하도록 하는 함수*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

int AppIO_in_score()
{
	// 입력받은 점수를 반환하는 함수.
	int score;
	printf("\n- 점수를 입력하시오: ");
	scanf("%d", &score);
	return score;
}

void AppIO_out(char* aString) {
	// 메시지 출력 함수.
	printf(aString);
}
void AppIO_out_averageScore(float anAverageScore) {
	// 평균점수는 소수점 첫 번 째 자리까지 반올림한다.
	printf("\n평균점수는 %.1f 입니다.\n", anAverageScore);
}
/*기타 출력함수 목록*/
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("평균 이상인 학생은 모두 %d명 입니다.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("최고점은 %d 점 입니다.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("최저점은 %d 점 입니다.\n\n", aMinScore);
}
void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c 학점인 학생은 %d명 입니다.\n",aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore, char aGrade) {
	printf("점수 : %d	학점 : %c\n", aScore, aGrade);
}
/*기타 출력함수 목록*/