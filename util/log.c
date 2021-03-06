/**
 * Copyright 2011 Wu Zhu Hua
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "log.h"
#include "malloc2.h"

/**
 *  Create a complete Log Capablity, please setup the logging before using it. 
 **/

/** Global Struct Part **/
typedef struct _LogSetting{
	char* log_file_path;
	int log_level;
}LogSetting; //The Log Will be used both at Master Runtime and Region Runtime.

LogSetting *logSetting = NULL; //Init

public void setup_logging(int log_level, char* log_file_path){
		logSetting = malloc2(sizeof(LogSetting));
		logSetting->log_level = log_level;
		logSetting->log_file_path = mallocs(strlen(log_file_path));
		strncpy(logSetting->log_file_path, log_file_path, strlen(log_file_path));
}

/** There is no need to append a line separator at the end of line **/
public void logg(int level, const char *fmt, ...){
		if(logSetting == NULL){
			printf("Please Setup Logging first before using the logging function!\n");
			return;
		}
		va_list ap;
		FILE *fp;
		char *c = ".-*#";
		char buf[64];
		time_t now;

		if (level < logSetting->log_level) return;

		fp = (logSetting->log_file_path == NULL) ? stdout : fopen(logSetting->log_file_path,"a");
		if (!fp) return;

		va_start(ap, fmt);
		now = time(NULL);
		strftime(buf,64,"%d %b %H:%M:%S",localtime(&now));
		//Write to the log file
		fprintf(fp,"[%d] %s %c ",(int)getpid(),buf,c[level]);
		vfprintf(fp, fmt, ap);
		//Write to the stdout
		printf("[%d] %s %c ",(int)getpid(),buf,c[level]);
		va_start(ap, fmt);
		vprintf(fmt, ap);
		printf("\n");
		fprintf(fp, LINE_SEPARATOR_STRING);
		fflush(fp);
		fflush(stdout);
		va_end(ap);

		if (logSetting->log_file_path != NULL) fclose(fp);
}
