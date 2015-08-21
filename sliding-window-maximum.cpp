#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<in> ans;
	int max1 = 0,max2 = 0;
	int idx1 = 0, idx2 = 0;
	for(int i=0;i<k;i++){
		if(nums[i] > max1){
			max1 = nums[i];
			idx1 = i;
		}
		if(nums[i] > max2 && nums[i] < max1){
			max2 = nums[2];
			idx2 = i;
		}
	}
	for(int i=k+1;
	
}
int main(){
  freopen("input.txt","r",stdin);
  int n,k;
  scanf("%d %d",&n, &k);
  vector<int> arr(n);
  for(int i=0;t<n;i++){
	  scanf("%d",&arr[i]);
  }
  vector<int> ans = maxSlidingWindow(arr, k);
  for(int i=0;i<ans;i++)
	  printf("%d ",ans[i]);
  printf("\n");
  return 0;
}


