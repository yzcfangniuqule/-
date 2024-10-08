// image_list.c  
#include "image_list.h"  
#include <string.h>  
#include <dirent.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
static ImageNode* head = NULL;  
static int count = 0;  
  
void init_image_list(const char* directory) {  
    struct dirent* entry;  
    DIR* dp = opendir(directory);  
  
    if (dp == NULL) {  
        perror("opendir");  
        return;  
    }  
  
    while ((entry = readdir(dp))) {  
        if (strstr(entry->d_name, ".bmp") != NULL) {  
            ImageNode* newNode = (ImageNode*)malloc(sizeof(ImageNode));  
            newNode->path = (char*)malloc((strlen(directory) + strlen(entry->d_name) + 2) * sizeof(char));  
            strcpy(newNode->path, directory);  
            strcat(newNode->path, "/");  
            strcat(newNode->path, entry->d_name);  
  
            newNode->next = head;  
            newNode->prev = NULL;  
  
            if (head != NULL) {  
                head->prev = newNode;  
            }  
  
            head = newNode;  
            count++;  
        }  
    }  
  
    closedir(dp);  
}  
  
int get_image_count() {  
    return count;  
}  
  
const char* get_image_path(int index) {  
    if (index < 0 || index >= count) {  
        return NULL;  
    }  
  
    ImageNode* current = head;  
    for (int i = 0; i < index; i++) {  
        current = current->next;  
    }  
  
    return current->path;  
}