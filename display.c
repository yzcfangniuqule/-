// display.c  
#include "display.h"  
  
// 假设有一个硬件相关的显示函数  
extern void hardware_display_text(const char* text);  
extern void hardware_display_image(const char* path);  
  
void display_text(const char* text) {  
    hardware_display_text(text);  
}  
  
void display_image(const char* path) {  
    hardware_display_image(path);  
}