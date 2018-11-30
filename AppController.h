#pragma once
#include "Common.h"
#include "Ban.h"

typedef struct {
	Ban* _ban;
} AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppContorller_run(AppController* _this);
Boolean AppController_inputAndStoreStudents(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_showStudentsSortedByScore(AppController* _this);
