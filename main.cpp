#include "Executive.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    cout << "\nInvalid number of parameters passed at command line! Please include the program executable and the file name.\n\n";
  }
  else
  {
    Executive exec(argv[1]);
    exec.Run();
  }
  return 0;
}
