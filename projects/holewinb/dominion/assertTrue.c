/*Bryce Holewinski
  CS362, Section 400
  This assert statement will replace the standard C
  library version for testing in this assignment
  */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assertTrue.h"

//This will continue to run in case of failed tests. It will
//be used in conjunction with gcov for testing analysis

int assertTrue(int testBool, char* text)
{
  //display testing results
  if (testBool)
    printf("PASSED\n");
  else
    printf("FAILED\n");
  printf(" : %s", text); //print the section being tested
  //quit the testing
  return testBool;
}
