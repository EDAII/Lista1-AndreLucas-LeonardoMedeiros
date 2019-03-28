#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define NOT_FOUND -404
#define BINARY_SEARCH 0
#define SEQUENTIAL_SEARCH 1
#define SENTINEL_SEQUENTIAL_SEARCH 2
#define INDEXED_SEQUENTIAL_SEARCH 3

double times[4] = {0,0,0,0};

int binarySearch(vector<int> * v, int x);
int seqSearch(vector<int> * v, int x);
int sentinelSeqSearch(vector<int> * v, int x);
int indexSeqSearch(vector<int> * v, int x);
void searchs(vector<int> * v, int x);
void fullRandom();
void middleConcentraded();
void printResults();

int main(){
	srand(time(NULL));  // Intialize srand seed
	string aux;
	// Full random
	system("clear");
	cout << "Searching for a random number in a random generated vector.\n\n";
	fullRandom();
	cout << "\nPress [ENTER] to continue.\n";
	getline(cin, aux);
	// Concentrated in middle
	system("clear");
	cout << "Searching for a random number in a random generated vector, with 80% concentraded in middle.\n\n";
	middleConcentraded();
	cout << "\nPress [ENTER] to continue.\n";
	getline(cin, aux);
	// Super concentrado no comeco
	// Super concentrado no final

  return 0;
}

void middleConcentraded(){
	vector<int> v;
	for(int i=0; i<1e4; i++){
    v.push_back(rand() % 45000);
  }
	for(int i=0; i<8*1e4; i++){
    v.push_back((rand()%(55000-45000)) + 45000 );
  }
	for(int i=0; i<1e4; i++){
    v.push_back((rand() % (100000 - 55000)) + 55000);
  }

  sort(v.begin(), v.end());

	for(int i = 0; i<100; i++){
		int findIt = rand() % 100000;
		searchs(&v, findIt);
	}
	printResults();
}

void fullRandom(){
	vector<int> v;
	for(int i=0; i<1e5; i++){
    v.push_back(rand() % 100000);
  }

  sort(v.begin(), v.end());

	for(int i = 0; i<100; i++){
		int findIt = rand() % 100000;
		searchs(&v, findIt);
	}
	printResults();
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

void printResults(){
	printf("Binary search average time: %lf seconds;\n", times[BINARY_SEARCH]/100);
	printf("Sequential search average time: %lf seconds;\n", times[SEQUENTIAL_SEARCH]/100);
	printf("Sequential search with sentinel average time: %lf seconds;\n", times[SENTINEL_SEQUENTIAL_SEARCH]/100);
	printf("Indexed sequential search average time: %lf seconds;\n", times[INDEXED_SEQUENTIAL_SEARCH]/100);

	times[BINARY_SEARCH] = 0;
	times[SEQUENTIAL_SEARCH] = 0;
	times[INDEXED_SEQUENTIAL_SEARCH] = 0;
	times[SENTINEL_SEQUENTIAL_SEARCH] = 0;
}

void searchs(vector<int> * v, int findIt){
  clock_t t = clock();
  int x = binarySearch(v, findIt);
  t = clock() - t;
	times[BINARY_SEARCH]+=(double)t/CLOCKS_PER_SEC;

  t = clock();
  x = seqSearch(v, findIt);
  t = clock() - t;
	times[SEQUENTIAL_SEARCH]+=(double)t/CLOCKS_PER_SEC;

  t = clock();
  x = sentinelSeqSearch(v, findIt);
  t = clock() - t;
	times[SENTINEL_SEQUENTIAL_SEARCH]+=(double)t/CLOCKS_PER_SEC;

  t = clock();
  x = indexSeqSearch(v, findIt);
  t = clock() - t;
	times[INDEXED_SEQUENTIAL_SEARCH]+=(double)t/CLOCKS_PER_SEC;
}
