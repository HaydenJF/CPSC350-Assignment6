#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

//header class for program
class calling{
  public:
    void call(string s);//gets file
  private:
    void bubble(); //bubble sort
    void selection(); //selection sort
    void insertion(); //insertion sort
    void mergeSort(int s, int e); //merge sort calling class
    void merge(int s, int m, int e); //actuall sorting class

    void quickSort(int s, int e); //quick sort calling class
    int quick(int l, int h); //actuall sorting class

    //arrays for each sort
    double *bArray;
    double *sArray;
    double *iArray;
    double *mArray;
    double *qArray;


    int length; //array length
    int spot; //spot in array



};
