#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void resize_and_threshold(unsigned char* input, int input_width, int input_height, char* output, int output_width, int output_height, float threshold);

int main(int argc, char* argv[]){
    if(argc <= 1){
        printf("Specify the path to your image after the command!\n");
        return 1;
    }
    
    char* image_path = argv[1];
    int width, height, channels;
    unsigned char* image = stbi_load(image_path, &width, &height, &channels, 1);
    
    if(!image){ printf("Could not load <%s>!\n", image_path); return 1; }
    
    char bitmap[25];
    
    resize_and_threshold(image, width, height, bitmap, 5, 5, 0.01);
    
    char bitmap_string[100] = {0};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            printf("%u ", bitmap[i * 5 + j]);
            snprintf(bitmap_string + strlen(bitmap_string), sizeof(bitmap_string) - strlen(bitmap_string), "%d, ", bitmap[i * 5 + j]);
        }
        if(i != 4) snprintf(bitmap_string + strlen(bitmap_string), sizeof(bitmap_string) - strlen(bitmap_string), "\n");
    }
    
    if(OpenClipboard(0)){
        EmptyClipboard();
        size_t len = strlen(bitmap_string) + 1;
        HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), bitmap_string, len);
        GlobalUnlock(hMem);
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
        GlobalFree(hMem);
    }
    
    stbi_image_free(image);
    return 0;
}

void resize_and_threshold(unsigned char* input, int input_width, int input_height, char* output, int output_width, int output_height, float threshold) {
    int x_ratio = input_width / output_width;
    int y_ratio = input_height / output_height;
    
    for(int i = 0; i < output_height; i++) {
        for(int j = 0; j < output_width; j++) {
            long int darkness = 0;
            for(int y = i * y_ratio; y < (i + 1) * y_ratio; y++){
                for(int x = j * x_ratio; x < (j + 1) * x_ratio; x++){
                    darkness += (input[y * input_width + x] <= 96);
                }
            }
            
            output[i * output_width + j] = darkness >= (threshold * x_ratio * y_ratio);
        }
    }
}
