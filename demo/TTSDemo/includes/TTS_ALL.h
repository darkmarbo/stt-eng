
#ifndef  __TTS_ALL_H_
#define  __TTS_ALL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "inter_lib.h"
#include "pre_pro.h"

#pragma comment(lib, "lib/ttsdll.lib")


const int MAX_LINE_SIZE = 10000;
const int WAV_SIZE = 60000000;	//10+min  44100*600*2=6000 0000



inline int str_trim(char *c)
{
	if (strlen(c)>0 && c[strlen(c) - 1] == 0x0A)
	{
		c[strlen(c) - 1] = '\0';
	}
	if (strlen(c)>0 && c[strlen(c) - 1] == 0x0D)
	{
		c[strlen(c) - 1] = '\0';
	}
	return 0;
}

class TTS_ALL
{

public:
	TTS_ALL();
	~TTS_ALL();
	/*
	传入 model\LC\model-like-77  直接就是声学模型
	只有ttsdll用到了此 目录
	其他 tn str_pro 分词 都写死在data里面了
	*/
	int init(const char* model_dir);

	/*
	// 处理首尾静音 找到第一个value值大于min_val的点  然后往左移动400ms(0.4*44100)
	//buff: buff数据  长度为len
	// left:左侧端点的idx   right:右侧端点的idx
	// min_val: 判定静音的阈值 400
	*/
	int silence_pro(const short *buff, int len, int &left, int &right, short min_val);

	int tts(const char *input, short *buff, int buff_size);
	int del();

private:

	TTS m_tts;

	// 没有NLPIR 控制jieba的
	int nlpir_flag;
	FILE *fp_log;

	PreProClass m_pp;

};




#endif