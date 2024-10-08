// time_thread.c  
#include "time_thread.h"  
#include "display.h"  
#include <pthread.h>  
#include <time.h>  
  
void* display_time(void* arg) {  
    while (1) {  
        time_t now = time(NULL);  
        char* time_str = ctime(&now);  
        display_text(time_str);  
        sleep(1); // 每秒更新一次时间  
    }  
    return NULL;  
}  
  
void start_time_thread() {  
    pthread_t thread;  
    pthread_create(&thread, NULL, display_time, NULL);  
    pthread_detach(thread);  
}