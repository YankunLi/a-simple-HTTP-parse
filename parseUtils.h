//#include <assert.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#ifndef PARSE_UTILS 201411251555

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

enum CHECK_STATE { CHECK_STATE_REQUESTLINE = 0, CHECK_STATE_HEADER, CHECK_STATE_CONTENT };

enum LINE_STATUS { LINE_OK = 0, LINE_BAD, LINE_OPEN };

enum HTTP_CODE { NO_REQUEST, GET_REQUEST, BAD_REQUEST, FORBIDDEN_REQUEST, INTERNAL_ERROR, CLOSED_CONNECTION };

static const char* szret[] = { "I get a correct result\n", "Something wrong\n" };

/* 从状态机，用于分析一行的内容 */
lINE_STATUS parse_line( char* buffer, int& checked_index, int& read_index );

/* 分析请求行 */
HTTP_CODE parse_requestline( char* temp, CHECK_STATE& checkstate );

/* 分析头部字段 */
HTTP_CODE parse_headers( char* temp );

/* 分析http请求的入口函数 */
HTTP_CODE parse_content( char* buffer, int& checked_index, CHECK_STATE& checkstate, int& read_index, int& start_line);

#endif
