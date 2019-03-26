#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define NOT_FOUND -404

int binarySearch(vector<int> * v, int x);
int seqSearch(vector<int> * v, int x);
int sentinelSeqSearch(vector<int> * v, int x);
int indexSeqSearch(vector<int> * v, int x);
void compareSearchs(vector<int> * v, int x);

int main(){

	srand(time(NULL));  // Intialize srand seed

	vector<int> v;
	for(int i=0; i<1e6; i++){
    v.push_back(rand() % 1000000);
  }

  sort(v.begin(), v.end());

	int findIt = rand() % 1000000;

	compareSearchs(&v, findIt);

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

void compareSearchs(vector<int> * v, int findIt){
	printf("Trying to find: %d\n\n", findIt);

  clock_t t = clock();
  int x = binarySearch(v, findIt);
  t = clock() - t;
  if (x != NOT_FOUND) printf("Binary search: finded on positition %d in %lf seconds\n", x , (double)t / CLOCKS_PER_SEC);
	else printf("Binary search: not found with %lf seconds\n", (double)t / CLOCKS_PER_SEC);

  t = clock();
  x = seqSearch(v, findIt);
  t = clock() - t;
	if (x != NOT_FOUND) printf("Sequential search: finded on positition %d in %lf seconds\n", x , (double)t / CLOCKS_PER_SEC);
	else printf("Sequential search: not found with %lf seconds\n", (double)t / CLOCKS_PER_SEC);

  t = clock();
  x = sentinelSeqSearch(v, findIt);
  t = clock() - t;
	if (x != NOT_FOUND) printf("Sequential search with sentinel: finded on positition %d in %lf seconds\n", x , (double)t / CLOCKS_PER_SEC);
	else printf("Sequential search with sentinel: not found with %lf seconds\n", (double)t / CLOCKS_PER_SEC);

  t = clock();
  x = indexSeqSearch(v, findIt);
  t = clock() - t;
	if (x != NOT_FOUND) printf("Indexed sequential search: finded on positition %d in %lf seconds\n", x , (double)t / CLOCKS_PER_SEC);
	else printf("Indexed sequential search: not found with %lf seconds\n", (double)t / CLOCKS_PER_SEC);
}
