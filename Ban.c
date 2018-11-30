#include "Common.h"
#include "GradeCounter.h"
#include "Ban.h"

Boolean Ban_scoreIsValid(int aScore) {
	// 점수가 0~100 사이인지 검사한다.
	return (aScore >= 0 && aScore <= 100);
}

char Ban_scoreToGrade(int aScore) {
	// 성적에 따라 학점을 return한다 (Char)
	if (aScore >= 90) {
		return 'A';
	}
	else if (aScore >= 80) {
		return 'B';
	}
	else if (aScore >= 70) {
		return 'C';
	}
	else if (aScore >= 60) {
		return 'D';
	}
	else
	{
		return 'F';
	}
}

Ban* Ban_new(void)
{
	// 새로운 Ban 객체를 메모리에 할당한다.
	Ban* _this = (Ban*)malloc(sizeof(Ban));
	_this->_capacity = DEFAULT_CAPACITY; // 최대 학생 수 설정
	_this->_size = 0; // 객체를 생성한 직후의 학생수는 0 명
	_this->_elements = NewVector(int, _this->_capacity);
	// 성적을 저장할 배열 생성 (NewVector)
	return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity)
{
	// givenCapacity에 따라 Ban 객체를 생성한다.
	Ban* _this = (Ban*)malloc(sizeof(Ban));
	_this->_capacity = givenCapacity; // 최대 학생 수 설정
	_this->_size = 0;// 객체를 생성한 직후의 학생수는 0 명
	_this->_elements = NewVector(int, _this->_capacity); // 성적을 저장할 배열
	return _this;
}

void Ban_delete(Ban* _this)
{ // Ban 객체를 삭제한다. elements 먼저 삭제해서 free시켜준다.
	free(_this->_elements);
	free(_this);
}

int Ban_capacity(Ban* _this)
{
	// Ban의 Capacity를 return한다.
	return (_this->_capacity);
}
int Ban_size(Ban* _this)
{
	// Ban의 size를 return한다.
	return (_this->_size);
}
Boolean Ban_isEmpty(Ban* _this)
{
	// Ban 이 비어있는지 검사한다.
	return (_this->_size == 0);
}
Boolean Ban_isFull(Ban* _this)
{
	// Ban 이 차있는지 검사한다.
	return (_this->_size >= _this->_capacity);
}Boolean Ban_add(Ban* _this, int aScore)
{
	// 성적을 배열에 저장
	if (Ban_isFull(_this)) {
		return FALSE; // 저장 공간이 부족
	}
	else {
		// 배열의 맨 마지막 위치에 넣는다.
		_this->_elements[_this->_size] = aScore;
		_this->_size++;
		return TRUE;
	}
}int Ban_elementAt(Ban* _this, int anOrder)
{
	if (anOrder >= _this->_size) {
		// 주어진 위치에 원소가 존재하지 않는다
		return -1; // 음수로 존재하지 않음을 표시하기로 한다
	}
	else {
		// 원소가 정상적으로 존재한다
		return (_this->_elements[anOrder]);
	}
}void Ban_sortStudentsByScore(Ban* _this)
{
	int size = _this->_size;
	// 정렬할 데이터는 _this->_elements[0] 부터 _this->_elements[size-1] 까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) { // 개수가 2 이상이면
					 // 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (_this->_elements[i] < _this->_elements[minPosition]) {
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다.
		SWAP(int, _this->_elements[minPosition], _this->_elements[size - 1]);
		// 정렬을 시작한다
		Ban_quickSortRecursively(_this, 0, size - 2);
	}
}void Ban_quickSortRecursively(Ban* _this, int left, int right)
{ // Ban에 있는 Element들을 QuickSort로 정렬한다.
	if (left < right) {
		int mid = Ban_partition(_this, left, right);
		Ban_quickSortRecursively(_this, left, mid - 1);
		Ban_quickSortRecursively(_this, mid + 1, right);
	}
}

int Ban_partition(Ban* _this, int left, int right)
{
	int pivot = left;
	int pivotScore = _this->_elements[pivot];
	right++;
	do {
		do { left++; } while (_this->_elements[left] > pivotScore);
		do { right--; } while (_this->_elements[right] < pivotScore);
		if (left < right) {
			SWAP(int, _this->_elements[left], _this->_elements[right]);
		}
	} while (left < right);
	SWAP(int, _this->_elements[pivot], _this->_elements[right]);
	return right;
}float Ban_averageScore(Ban* _this)
{
	// 평균을 계산하여 return 값으로 돌려준다.
	float sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size - 1);
	float average = sumOfScores / (float)_this->_size;
	return average;
}
int Ban_maxScore(Ban* _this)
{
	// 최고점을 찾아서 return 값으로 돌려준다.
	return Ban_maxScoreRecursively(_this, 0, _this->_size - 1);
}
int Ban_minScore(Ban* _this)
{
	// 최저점을 찾아서 return 값으로 돌려준다.
	return Ban_minScoreRecursively(_this, 0, _this->_size - 1);
}int Ban_sumOfScoresRecursively(Ban* _this, int left, int right)
{
	// 성적 합계를 계산하여 return 값으로 돌려준다.
	// 크기를 (N-1)로 줄이는 재귀함수로 작성하시오.
	if (left > right) {
		return 0;
	}
	else {
		return (_this->_elements[left] + Ban_sumOfScoresRecursively(_this, left + 1, right));
	}
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right)
{
	int maxOfLeftPart; // 파트의 왼쪽 위치.
	int maxOfRightPart; // 파트의 오른쪽 위치.
	int mid; // 가운데 위치
	if (left == right) { // 좌우가 같다면
		return _this->_elements[left]; // 해당 값이 최대값.
	}
	else {
		mid = (left + right) / 2;
		// 좌, 우르를 반으로 나누어 mid를 설정한다.
		maxOfLeftPart = Ban_maxScoreRecursively(_this, left, mid);
		// 왼쪽 기준 1번 파트에서 최대값을 구하고
		maxOfRightPart = Ban_maxScoreRecursively(_this, mid + 1, right);
		// 오른쪽 기준 2번 파트에서 최대값을 구해서
		if (maxOfLeftPart >= maxOfRightPart)
			// 비교 후 더 큰 것을 return 한다.
			return maxOfLeftPart;
		else
			return maxOfRightPart;
	}
}
int Ban_minScoreRecursively(Ban* _this, int left, int right)
{
	int minOfSubPart;
	if (left == right) // 좌우가 같다면
		return _this->_elements[left];
		// 해당 값이 최소값이된다.
	else {
		minOfSubPart = Ban_minScoreRecursively(_this, left + 1, right);
		// 아니라면 left를 1씩 늘려서 크기를 하나씩 줄여가면서 다시 비교한다.
		if (_this->_elements[left] < minOfSubPart) {
			return _this->_elements[left];
		}
		else {
			return minOfSubPart;
		}
		// 크기 계산 후 return
	}
}int Ban_numberOfStudentsAboveAverage(Ban* _this) 
// 평균 이상인 학생 수를 세는 함수.
{
	float average = Ban_averageScore(_this);
	int numberOfStudentsAboveAverage = 0;
	for (int i = 0; i < _this->_size; i++) {
		if (((float)_this->_elements[i]) >= average) {
			numberOfStudentsAboveAverage++;
		}
	}
	return numberOfStudentsAboveAverage;
}GradeCounter* Ban_countGrades(Ban* _this) 
// 학점 별 학생의 수를 세는 함수.
{
	char currentGrade;
	GradeCounter* gradeCounter = GradeCounter_new();
	for (int i = 0; i < _this->_size; i++) {
		currentGrade = Ban_scoreToGrade(_this->_elements[i]);
		GradeCounter_count(gradeCounter, currentGrade);
	}
	return gradeCounter;
}