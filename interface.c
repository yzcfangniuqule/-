// interface.c  
#include "interface.h"  
#include "display.h"  
#include "image_list.h"  
  
void init_interface() {  
    // 初始化界面相关的设置  
    show_main_screen();  
}  
  
void update_display() {  
    // 根据当前状态更新显示  
    // 需要一个全局变量来跟踪当前显示的界面  
}  
  
void show_main_screen() {  
    // 显示主界面，包括图片总数等  
    int total_images = get_image_count();  
    display_text("Total Images: " + total_images);  
}  
  
void show_image_screen(int image_index) {  
    // 显示指定索引的图片  
    const char* image_path = get_image_path(image_index);  
    display_image(image_path);  
}  
  
void show_exit_screen() {  
    // 显示退出界面  
    display_text("Exiting...");  
}