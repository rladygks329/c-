/****************************************************
*
* Problem:
*                주어진정수의최대최소구하기
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;

int main(void){
  int numTestcases;
  /* read the number of test cases*/
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int numData, data, max, min;

      cin >> numData;
      cin >> data;

      min = max = data;
      for ( int j=0; j<numData-1; j++){
        cin >> data;
        
        if(data > max) max = data;
        if(data < min) min = data;

      }
      cout << max <<" "<< min << endl;  /* print out the last 1 degit value */
  }
  return 0;
}
