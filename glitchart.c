/*
  Matthew Isaac Lean
  11/12/2013
  FDM170A

  *Program Name: 61I7ch @Rt (yeah i used 1337sp34k wanna fight about it?)
  *Description: Just a simple program that glitches images.
  *How to Use: You must pass in an image for it to glitch via the command
    line.

    For example, if I want to glitch "filename.jpg" I would input the command:
    ./glitchart filename.jpg
    This is if I'm currently in the same directory as "glitchart" and
    "filename.jpg" is also located there as well.

    Be careful! The program will destroy the original image that you want to
    glitch, so please remember to back up the original image first! Also there
    is a slight chance that the image may completely break the image rendering
    it unviewable in an image viewer. If that happens just try running the
    program again. That's what you get when you're dealing with glitches dood!
    :D
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE *fileptr;

  if(argc == 2){
    char *filename = argv[1];
    fileptr = fopen(filename, "rb+");
  }else{
    //doesn't actually check for images at the moment
    //only checks if a file is input is all
    //this can be a good or bad thing...? lol
    //will fix this if i have enough time
    printf("ERROR: You must input an image file to read!\nExample: ./glitchart filename.jpg\n");
    exit(1);
  }

  if(fileptr == NULL){
    printf("ERROR: Can't open image!\n");
    exit(1);
  };

  //get length of the image source
  fseek(fileptr, 0, SEEK_END);
  int lengthOfFile = ftell(fileptr);
  //maybe make a debug mode which outputs the debug printfs if i have time?
  //printf("%d\n", lengthOfFile);
  rewind(fileptr);
  
  //plant seeds
  int i = 0; //just a simple iterator outside of a for loop declaration because C :(
  int c = 0; //char that will store the current character being read from the image source

  srand(time(NULL));
  int RANDall = rand() % 26; //RANDomly generate a number like a certain cloud
  char seedupperchar = 65 + RANDall; //set randomly generated uppercase letter
  char seedlowerchar = seedupperchar + 32; //set lowercase letter from uppercase letter
  //printf("seedupperchar: %c\n", seedupperchar);

  for(i = 0; i < lengthOfFile; ++i){
    int pos = ftell(fileptr);
    c = fgetc(fileptr);
    if((i > 4) && ((c == seedlowerchar) || (c == seedupperchar))){
      int input = rand() % 95 + 32; //replace with a random character that is between 32-126 (decimal) on the ASCII table
      //printf("input: %d == %c\n", input, input);

      fseek(fileptr, pos, SEEK_SET);
      fputc(input, fileptr);
    }
  }

  printf("Glitching complete!\n");

  fclose(fileptr);
  return 0;
}
