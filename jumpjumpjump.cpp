#include <iostream>
#include <string.h>

char newStr [10];

char * strcat_str(void) // generates flag
{
  int m;
  
  newStr[0] = 0x21;
  m = 1;
  while (m < 10) {
    newStr[m] = (char)m + newStr[m - 1] + '\x01';
    m = m + 1;
  }
  return newStr;
}

int main(void)
{
  int inStrLen;
  char inStr [112];
  char *flag;
  int n;
  int counter;
  
  counter = 0;
  printf("enter the magic string");
  fgets(inStr,100,stdin);
  inStrLen = strlen(inStr);
                   
  if (inStrLen < 0xc) { // string length <= 10 
    n = 0;
    while( true ) { // for loop that iterates through inStr  
      // std::cout << "\nbigN: " << n;
      // std::cout << "\ncounter: " << counter;
      // std::cout << "\ninStr[n]: " << inStr[n]; 
      // std::cout << "\n(int)inStr[n]: " << (int)inStr[n];
      inStrLen = strlen(inStr);
      if (inStrLen <= n) break;
      counter = counter + inStr[n];
      n = n + 1;
    }
    // std::cout << "\n\n\n" << counter;
    if (counter == 1000) {
      flag = strcat_str();
      printf("flag is flag{");
      n = 0;
      while (n < 10) {
        std::cout << flag[n];
        //printf((char)flag[n]);
        n = n + 1;
      }
      puts("}");
    }
    else {
      puts("wrong string\nNo flag for you.");
    }
  }
  else {
    puts("too long...sorry no flag for you!!!");
  }
  return 0;
}
