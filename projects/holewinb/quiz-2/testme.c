#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//This function will produce a random char based on the available ones below
char inputChar()
{
    //rewrite this function
    char randomChars[34] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                          's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ']',
                          '{', '}', '.', ';', ':', '/', '['};

    return randomChars[(rand() % 34)];
}

//This will produce a random string
char *inputString()
{
    // rewrite this function -- string setup
    int randLength = (rand() % 8);
    char randomChars[5] = {'r', 'e', 's', 't', '\0'};
    int i;
    char *testString;

    testString = (char*) malloc((randLength+1)*sizeof(char));
    //build string
    for (i = 0; i < randLength; i++)
    {
      testString[i] = randomChars[(rand() % 8)];
    }

    return testString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
