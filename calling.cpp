//cpp class for program
#include "calling.h"


void calling::call(string s){//creates arrays for each sort
  ifstream file(s);
  bool firstLine = true;
  if (file.is_open()) {
    string tempLine;
    while (getline(file, tempLine)) {
      if (firstLine){
        length = stoi(tempLine);
        bArray = new double[length];
        sArray = new double[length];
        iArray = new double[length];
        mArray = new double[length];
        qArray = new double[length];
        spot = 0;
        firstLine = false;
      } else {
        bArray[spot] = stod(tempLine);
        sArray[spot] = stod(tempLine);
        iArray[spot] = stod(tempLine);
        mArray[spot] = stod(tempLine);
        qArray[spot] = stod(tempLine);
        spot++;
      }
    }
  }

  clock_t start;
  clock_t end;
  double mili = (double)(CLOCKS_PER_SEC / 1000);

  start = clock();
  bubble();
  end = clock();
  cout << "BubbleSort Time: " << (end - start) / mili << " miliseconds" << endl;

  start = clock();
  selection();
  end = clock();
  cout << "SelectionSort Time: " << (end - start) / mili << " miliseconds" << endl;

  start = clock();
  insertion();
  end = clock();
  cout << "InsertionSort Time: " << (end - start) / mili << " miliseconds" << endl;

  start = clock();
  mergeSort(0, length-1);
  end = clock();
  cout << "MergeSort Time: " << (end - start) / mili << " miliseconds" << endl;

  start = clock();
  quickSort(0, length-1);
  end = clock();
  cout << "QuickSort Time: " << (end - start) / mili << " miliseconds" << endl;
  //Print loops to check if the lists are sorted.
  /*for (int i = 0; i < length; ++i){
    cout << bArray[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < length; ++i){
    cout << sArray[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < length; ++i){
    cout << iArray[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < length; ++i){
    cout << mArray[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < length; ++i){
    cout << qArray[i] << " ";
  }
  cout << endl;*/


}

void calling::bubble(){//sorts using bubble sort
  for (int i = 0; i < length; ++i){
    for (int j = 0; j < length-1; ++j){
      if (bArray[j] > bArray[j+1]){
        double temp = bArray[j];
        bArray[j] = bArray[j+1];
        bArray[j+1] = temp;
      }
    }
  }
}

void calling::selection(){//sorts using selction sort
  for (int i = 0; i < length; ++i){
    int min = i;
    for (int j = i; j < length; ++j){
      if (sArray[min] > sArray[j]){
        min = j;
      }
    }
    double temp = sArray[min];
    sArray[min] = sArray[i];
    sArray[i] = temp;
  }
}

void calling::insertion(){//sorts using insertion sort
  for (int i = 1; i < length; ++i){
    int j = i;
    while (j >= 0 && iArray[j] < iArray[j - 1]){
      double temp = iArray[j];
      iArray[j] = iArray[j-1];
      iArray[j-1] = temp;
      j--;
    }


  }
}

void calling::mergeSort(int start, int end){//recusion for merge sort
  int mid = (start+end)/2;
  if (start < end){
    mergeSort(start, mid);
    mergeSort(mid+1, end);

    merge(start, mid, end);
  }
}

void calling::merge(int start, int mid, int end){//sorting for merge sort
  double *newArray = new double[end-start+1];
  int pos = 0;
  int left = start;
  int right = mid+1;

  while (left <= mid && right <= end){
    if (mArray[left] <= mArray[right]){
      newArray[pos] = mArray[left];
      left++;
    } else {
      newArray[pos] = mArray[right];
      right++;
    }
    pos++;
  }

  while (left <= mid){
    newArray[pos] = mArray[left];
    left++;
    pos++;
  }

  while (right <= end){
    newArray[pos] = mArray[right];
    right++;
    pos++;
  }

  for (int i = 0; i < end-start+1; ++i){
    mArray[start+i] = newArray[i];
  }
  delete newArray;
}

void calling::quickSort(int start, int end){//recusion for quicksort
  if (start < end){
    int lowMid = quick(start, end);
    quickSort(start, lowMid);
    quickSort(lowMid+1, end);
  }
}

int calling::quick(int bot, int top){//sorting for quicksort
   int mid = bot + (top - bot) / 2;
   bool done = false;
   while (!done) {
      while (qArray[bot] < qArray[mid]) {
         bot += 1;
      }

      while (qArray[mid] < qArray[top]) {
         top -= 1;
      }

      if (bot >= top) {
         done = true;
      }
      else {
         double temp = qArray[bot];
         qArray[bot] = qArray[top];
         qArray[top] = temp;

         bot += 1;
         top -= 1;
      }
   }

   return top;
}
