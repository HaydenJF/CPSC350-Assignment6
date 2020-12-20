#include "calling.h"

//main method
int main (int argc, char **argv) {
  if (argc > 1){
    calling d;
    d.call(string(argv[1]));
  } else {
    cout << "You need to enter a file name." << endl;
  }
  return 0;
}
