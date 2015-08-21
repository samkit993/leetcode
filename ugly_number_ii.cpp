#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#define SIEVESIZE 1000000

using namespace std;
int nthUglyNumber(int n) {
	set<int> uglies;
	
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);

	for(int i=0;i<primes.size();++i){
		int temp = primes[i];
		while(temp < n){
			uglies.insert(temp);
			temp += primes[i];
		}
	}
}

int main(){
	cout << nthUglyNumber(100) << endl;
	return 0;
}

