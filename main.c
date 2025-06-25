// NB: Most of this code was not written by me. It was taken from Kaan Alpar's
// YouTube video: "Coding an Image to ASCII Converter in C" [https://www.youtube.com/@KaanAlparGameDev]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image_headers/stb_image.h"


int main() {
  const char ascii_chars[] = " .`'^\",:;Il!i~+_-?][}{1)(|\\tfjrxnuvczXYUJCLQ08OZmwqpdbkhao*#MW&8%B@$";
  int ascii_len = strlen(ascii_chars);

  char imgPathInp[255];
  printf("\nplease keep no gap in the image name.\nexp: 'abc.<fileformate>' / 'a-b-c.<fileformate>'. Not 'a b c.<fileformate>'");
  printf("\nEnter image path: ");
  scanf("%s", imgPathInp);

  imgPathInp[strlen(imgPathInp)] = '\0';

  int width, height, channels;

  unsigned char *img_data = stbi_load(imgPathInp, &width, &height, &channels, 0);

  if(img_data == NULL){
    printf("Error: Unable to load image\n");
    return 1;
  }

  //ascii conversion
  unsigned char *pixels = img_data;
  for(int rowIndex = 0; rowIndex < height; rowIndex++){
    for(int columnIndex = 0; columnIndex < width; columnIndex++){

      unsigned char r = *pixels++;
      unsigned char g = *pixels++;
      unsigned char b = *pixels++;
      if(channels == 4){
        unsigned char A = *pixels++;
      }

      float grayScal = (r + g + b) / 3.0f;

      int ascii_char_index = (int)(ascii_len * (grayScal / 255.0));

      putchar(ascii_chars[ascii_char_index]);
    }
    putchar('\n');
  }

  stbi_image_free(img_data);
  stbi_image_free(pixels);
}

