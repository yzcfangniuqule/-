// image_list.h  
#ifndef IMAGE_LIST_H  
#define IMAGE_LIST_H  
  
#include <stdlib.h>  
  
typedef struct ImageNode {  
    char* path;  
    struct ImageNode* next;  
    struct ImageNode* prev;  
} ImageNode;  
  
void init_image_list(const char* directory);  
int get_image_count();  
const char* get_image_path(int index);  
  
#endif // IMAGE_LIST_H