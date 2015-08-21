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
bool binarySearch(vector<int> &vec, int tar){
  int start=0, end=vec.size()-1,mid;
  mid = vec.size()/2;
  while(start <= end){
    if(vec[mid] == tar){
      return true;
    }else if(vec[mid] > tar){
      end = mid - 1;
    }else{
      start = mid + 1;
    }
    mid = (start+end)/2;
  }

    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  for(int i=0;i<matrix.size();i++){
    if(binarySearch(matrix[i], target))
      return true;
  }
  return false;
}
int main(){
  freopen("input.txt","r",stdin);
  int m,n;
  scanf("%d %d",&m,&n);
  vector<vector<int> > matrix(m);
  for(int i=0;i<n;i++)
    matrix[i].resize(n);

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%d", &matrix[i][j]);
    }
  }
  cout << searchMatrix(matrix, 5);
  return 0;
}


