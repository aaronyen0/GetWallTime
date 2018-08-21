#include <Windows.h>

static __int64 gTime = 0;

void GetWallTimeStart(){
    LARGE_INTEGER time;
    if (!QueryPerformanceCounter(&time)){
        return;
    }
    gTime = time.QuadPart;
}

double GetWallTimeEnd(){
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceCounter(&time)){
        return -1;
    }
	if (!QueryPerformanceFrequency(&freq)){
        return -2;
    }
    gTime = time.QuadPart - gTime;
	return (double)gTime / freq.QuadPart;
}



double get_wall_time(){
    LARGE_INTEGER time, freq;
    if (!QueryPerformanceFrequency(&freq)){
        //  Handle error
        return 0;
    }
    if (!QueryPerformanceCounter(&time)){
        //  Handle error
        return 0;
    }
    return (double)time.QuadPart / freq.QuadPart;
}
