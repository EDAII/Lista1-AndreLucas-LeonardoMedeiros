#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

#define NOT_FOUND -404; // Easter Egg

int binarySearch(vector<int> * v, int x);
int seqSearch(vector<int> * v, int x);
// int sentinelSeqSearch();
// int indexSeqSearch();

int main(){

  vector<int> v = {1,2,3,4,5};
  int y = binarySearch(&v, 4);
  cout << y << endl;

  return 0;
}

int binarySearch(vector<int> * v, int x){
  int left = 0;
  int right = v->size()-1;
  while(left <= right){
    int mid = (right+left)/2;
    if(v->at(mid) == x) return mid;
    if(v->at(mid) > x) right = mid - 1;
    else left = mid + 1;
  }
  return NOT_FOUND;
}

int seqSearch(vector<int> * v, int x){
  for (size_t i = 0; i < v->size(); i++) {
    if (v->at(i) == x){
      return i;
    }
  }
  return NOT_FOUND;
}
