#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<string> possible_ways;

bool isInt(string input){
  for(int i=0;i<input.size();i++){
    if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
      return false;
    }
  }
  return true;
}

int tens[10] = {1,10,100,1000,10000,100000,1000000,10000000, 100000000, 1000000000};

int convertToInt(string a){
  int ret = 0;
  int n = a.size();
  for(int i=0;i<a.size();i++){
    ret += (int(a[n-i-1]) - int('0'))*tens[i];
  }
  //cout << "Converted " << a << " to integer " << ret << endl;
  return ret;
}

vector<int> diffWaysToCompute(string input) {
  vector<int> ans;
  int n = input.size();
  if(isInt(input)){
    ans.push_back(convertToInt(input));
    return ans;
  }

  for(int i=0;i<n;i++){
    if((input[i] == '+' || input[i] == '-' || input[i] == '*')){
      //cout << "Using evaluate for preString:" << input.substr(0,i) << " postString:" << input.substr(i+1) << " at operand:" << input[i] << endl;
      string pre = input.substr(0,i);
      string post = input.substr(i+1);

      int preInt, postInt, temp;
      vector<int> preInts, postInts;

      if(isInt(pre)){
        preInt = convertToInt(pre);
        preInts.push_back(preInt);
      }else{
        preInts = diffWaysToCompute(pre);
      }

      if(isInt(post)){
        postInt = convertToInt(post);
        postInts.push_back(postInt);
      }else{
        postInts = diffWaysToCompute(post);
      }

      //cout << "preInt: " << preInt << " postInt:" << postInt  << endl;
      switch(input[i]){
        case '+':
          for(int i=0;i<preInts.size();i++){
            for(int j=0;j<postInts.size();j++){
              ans.push_back(preInts[i] + postInts[j]);
            }
          }
          break;
        case '*':
          for(int i=0;i<preInts.size();i++){
            for(int j=0;j<postInts.size();j++){
              ans.push_back(preInts[i] * postInts[j]);
            }
          }
          break;
        case '-':
          for(int i=0;i<preInts.size();i++){
            for(int j=0;j<postInts.size();j++){
              ans.push_back(preInts[i] - postInts[j]);
            }
          }
          break;
      }
    }
  }
  return ans;
}

int main(){
  string str = "2*3-4*5";
  string str1 = "0";
  cout << "String is " << str << endl;
  //cout << str.erase(remove(str.begin(), str.end(), ' '), str.end());
  vector<int> ans = diffWaysToCompute(str1);
  for(int i=0;i<ans.size();i++)
    cout << ans[i] << endl;
  //cout << evaluate("100+100*2") << endl;
  return 0;
}
