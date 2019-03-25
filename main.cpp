#include <iostream>
#include <time.h>
#include <array>

using namespace std;

#define NOT_FOUND -1;

int binarySearch(int * v, int left, int right, int x);
int seqSearch();
int sentinelSeqSearch();
int indexSeqSearch();

int main(){



  return 0;
}

int binarySearch(int * v, int left, int right, int x){
  int mid = (right+left)/2;
  while(left<right){
    if(v[mid]==x) return mid;
    if(v[mid]>x) mid=left;
    else mid=right;
  }
  return NOT_FOUND;
}
