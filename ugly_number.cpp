#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#define SIEVESIZE 1000000

using namespace std;

int sqroot = sqrt(SIEVESIZE) + 1;
vector<int> primes;
vector<int> sieve(SIEVESIZE,1);
void init(){
	printf("Limit is %d\n", sqroot);
	sieve[0] = 0;
	for(int i=2;i<sqroot;++i){
		int temp = i;
		while(temp < sieve.size()){
			sieve[temp] = 0;
			temp += i;
		}
	}
	cout << "Sieving is done " << endl;
	for(int i=0;i<sieve.size();++i){
		if(sieve[i])
			primes.push_back(i);
	}
	for(int i=0;i<primes.size();++i){
		printf("%d ", primes[i]);
	}
}

bool isUgly(int num) { 
	if(num == 0)
		return false;
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	for(int i=0;i<primes.size();++i){
		while(num % primes[i] == 0){
			num /= primes[i];
		}
	}
	return num == 1;
}
int main(){
	cout << isUgly(0);
	cout << isUgly(6);
	cout << isUgly(8);
	cout << isUgly(14);
	return 0;
}

