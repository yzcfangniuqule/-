#include "interface.h"  
#include "image_list.h"  
#include "touch_input.h"  
#include "time_thread.h"  
  
int main() {  
    // 初始化各个模块  
    init_interface();  
    init_image_list("path/to/directory");  
    init_touch_input();  
    start_time_thread();  
  
    // 主循环  
    while (1) {  
        handle_touch_input();  
        update_display();  
    }  
  
    return 0;  
}