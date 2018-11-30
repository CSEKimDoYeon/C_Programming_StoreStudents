#include "Common.h"
#include "AppIO.h"

#include <stdio.h>
#include <conio.h>

Boolean AppIO_in_doesContinueToInputNextStudent()
{
	//����ڷκ��� ���� �Է� ���θ� �Է¹޴´�.
	printf("\n? ������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
	char answer = getcharDirectlyFromKeyboard();
	// ������ ������ ��Keyboard ���� ���� ���� �Է� �ޱ⡱ ������ �����Ͻÿ�.
	if (answer == 'Y' || answer == 'y')
		return TRUE;
	else
		printf("\n�Է��� �����մϴ�.\n");
		return FALSE;
}

char getcharDirectlyFromKeyboard(void)
{ /*���� ���͸� ������ ����� �ƴ� Ű���忡��
  ������ ���� �ٷ� �ν��ϵ��� �ϴ� �Լ�*/
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

int AppIO_in_score()
{
	// �Է¹��� ������ ��ȯ�ϴ� �Լ�.
	int score;
	printf("\n- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	return score;
}

void AppIO_out(char* aString) {
	// �޽��� ��� �Լ�.
	printf(aString);
}
void AppIO_out_averageScore(float anAverageScore) {
	// ��������� �Ҽ��� ù �� ° �ڸ����� �ݿø��Ѵ�.
	printf("\n��������� %.1f �Դϴ�.\n", anAverageScore);
}
/*��Ÿ ����Լ� ���*/
void AppIO_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}
void AppIO_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d �� �Դϴ�.\n", aMaxScore);
}
void AppIO_out_minScore(int aMinScore) {
	printf("�������� %d �� �Դϴ�.\n\n", aMinScore);
}
void AppIO_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c ������ �л��� %d�� �Դϴ�.\n",aGrade, aCount);
}
void AppIO_out_studentInfo(int aScore, char aGrade) {
	printf("���� : %d	���� : %c\n", aScore, aGrade);
}
/*��Ÿ ����Լ� ���*/