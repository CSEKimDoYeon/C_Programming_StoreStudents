#include "AppController.h"
#include <stdio.h>

int main(void)
{
	AppController* appController = AppController_new(); 
	// 앱의 실행은 AppController가 관리하기 때문에 새 객체를 만들어준다.
	AppContorller_run(appController);
	// 생성한 AppController를 실행해준다.
	AppController_delete(appController);
	// 작업을 완료한 AppController를 삭제해준다.
	system("pause");
	// 프로그램 종료 후 바로 종료되는 것을 막는다.
	return 0;
} // end of main()