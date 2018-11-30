#include "Common.h"
#include "GradeCounter.h"

GradeCounter* GradeCounter_new(void)
{ // 새로운 GradeCounter 객체를 메모리에 할당해준다.
	GradeCounter* _this = (GradeCounter*)malloc(sizeof(GradeCounter));

	_this->_numberOfA = 0;
	_this->_numberOfB = 0;
	_this->_numberOfC = 0;
	_this->_numberOfD = 0;
	_this->_numberOfF = 0;
	return _this;
}
void GradeCounter_delete(GradeCounter* _this)
{ // GradeCounter 객체를 free해준다. 
	free(_this);
}

void GradeCounter_count(GradeCounter* _this, char aGrade)
{  // aGrade에 해당하는 학점에 Counting을 올려준다.
	switch (aGrade) {
		case 'A':
		_this->_numberOfA++;
		 break;
		case 'B':
		_this->_numberOfB++;
		break;
		case 'C':
		_this->_numberOfC++;
		break;
		case 'D':
		_this->_numberOfD++;
		break;

		default:
			_this->_numberOfF++;
	}
}

int GradeCounter_numberOfA(GradeCounter* _this)
{
	return _this->_numberOfA;
}
int GradeCounter_numberOfB(GradeCounter* _this)
{
	return _this->_numberOfB;
}
int GradeCounter_numberOfC(GradeCounter* _this)
{
	return _this->_numberOfC;
}
int GradeCounter_numberOfD(GradeCounter* _this)
{
	return _this->_numberOfD;
}
int GradeCounter_numberOfF(GradeCounter* _this)
{
	return _this->_numberOfF;
	return 0;
}
