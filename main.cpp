#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

#define NOT_FOUND -404;

int binarySearch(vector<int> * v, int x);
int seqSearch(vector<int> * v, int x);
int sentinelSeqSearch(vector<int> * v, int x);
// int indexSeqSearch();

int main(){

  vector<int> v = {1,2,3,4,5};
  int x = binarySearch(&v, 1);
  int y = seqSearch(&v, 1);
  int z = sentinelSeqSearch(&v, 1);
  cout << x << endl;
  cout << y << endl;
  cout << z << endl;

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

int sentinelSeqSearch(vector<int> * v, int x){
  v->push_back(x);
  int i;
  for (i=0; x!=v->at(i); i++);
  v->pop_back();
  if ((size_t)i < v->size()){
    return i;
  }
  else{
    return NOT_FOUND;
  }
}

int indexSeqSearch(vector<int> * v, int x){
  int block_size = v->size()/5; 
  int i,j;
  for (i = block_size; i < (int) v->size(); i += block_size){
		if (v->at(i) >= x) break;
  }
	for (j = i - block_size; j < i; j++){
	  if( v->at(j) == x) return j;
  }

  return NOT_FOUND;
}
