#include "Common.h"
#include "Ban.h"
#include "GradeCounter.h"
#include "AppController.h"
#include "AppIO.h"


#define MAX_NUMBER_OF_STUDENTS 100 // �л��� �ִ� ��

AppController* AppController_new(void) 
// ���ο� AppController ��ü�� �����Ѵ�. 
{
	AppController* _this = (AppController*)malloc(sizeof(AppController)); 
	// �� ��ü�� �޸𸮸� �Ҵ����ش�.
	_this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);
	//AppController ��ü�� Ban ��ü�� �־��ش�.
	return _this;
}void AppController_delete(AppController* _this)
// AppController ��ü�� �޸𸮿��� �����Ѵ�.
{ 
	Ban_delete(_this->_ban);
	// AppController ������ Ban ��ü�� �������ش�.
	free(_this);
	// ����ִ� �޸� ������ free���ش�.
}void AppContorller_run(AppController* _this)
{
	AppIO_out("<<< ���� ó���� �����մϴ� >>>\n");
	// (1) ������ �Է� �޴´�
	Boolean inputAndStoreWasSuccessful;
	inputAndStoreWasSuccessful = AppController_inputAndStoreStudents(_this);
	// ����ڷκ��� ������ �Է¹޴´�, ���������� ������ True.
	if (inputAndStoreWasSuccessful) {
		if (Ban_isEmpty(_this->_ban)) {
			AppIO_out("\n[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
		}
		else {
			// (2) ��հ� ��� �̻��� �л���, �ְ���, �������� ����Ѵ�. 
			AppController_showStatistics(_this);
			// (3) ���������� ����, �׸��� �Է� ���� �л� ������ ����Ѵ�. 
			Ban_sortStudentsByScore(_this->_ban);
			AppController_showStudentsSortedByScore(_this);
		}
	}
	else {
		AppIO_out("[����] ������ ���������� ������� �ʾҽ��ϴ�.");
	}
	AppIO_out("\n<<< ���� ó���� �����մϴ� >>>\n");
}Boolean AppController_inputAndStoreStudents(AppController* _this)
// �л����� ���� ������ �Է¹ް�, �����Ѵ�.
{
	int score;
	Boolean storingAStudentWasSuccessful = TRUE;
	while (storingAStudentWasSuccessful &&
		AppIO_in_doesContinueToInputNextStudent())
		// input�� Y �̸� ��� �����Ѵ�.
	{
		score = AppIO_in_score();
		if (Ban_scoreIsValid(score)) {
			storingAStudentWasSuccessful = Ban_add(_this->_ban, score);
		}
		else {
			AppIO_out("[����] 0 ���� �۰ų� 100 ���� Ŀ��, �������� ������ �ƴմϴ�.\n");
		}
	}
	return storingAStudentWasSuccessful;
}void AppController_showStatistics(AppController* _this)
{
	//������ ó���� ����� ȭ�鿡 ����Ѵ�.
	// �� ������ ���� ó���� ����� Ban ��ü�� ������ �ִ�
	AppIO_out_averageScore(Ban_averageScore(_this->_ban));
	AppIO_out_numberOfStudentsAboveAverage(Ban_numberOfStudentsAboveAverage(_this->_ban));
	AppIO_out_maxScore(Ban_maxScore(_this->_ban));
	AppIO_out_minScore(Ban_minScore(_this->_ban));
	// ���� �� �л����� Ban ��ü�κ��� GradeCounter ��ü ���·� ��´�
	GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
	AppIO_out_gradeCountFor('A', GradeCounter_numberOfA(gradeCounter));
	AppIO_out_gradeCountFor('B', GradeCounter_numberOfB(gradeCounter));
	AppIO_out_gradeCountFor('C', GradeCounter_numberOfC(gradeCounter));
	AppIO_out_gradeCountFor('D', GradeCounter_numberOfD(gradeCounter));
	AppIO_out_gradeCountFor('F', GradeCounter_numberOfF(gradeCounter));
	GradeCounter_delete(gradeCounter); // �� �̻� �ʿ� �����Ƿ� �Ҹ��Ų��
}void AppController_showStudentsSortedByScore(AppController* _this)
{
	//�л����� ���������� ���ĵ� ����� ������ش�.
	AppIO_out("\n�л����� ������ ����Դϴ�.\n");
	int score;
	char grade;
	for (int order = 0; order < Ban_size(_this->_ban); order++) {
		score = Ban_elementAt(_this->_ban, order);
		grade = Ban_scoreToGrade(score);
		AppIO_out_studentInfo(score, grade);
	}
}

