/****************************************************
*
* Problem:
*                끝자리 숫자 계산하기
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
      int numData,data;
      int answer = 1;   //teacher use name lastDegit

      cin >> numData;
      for ( int j=0; j<numData; j++){
        cin >> data;
        answer *= data;
        answer %= 10;
      }
      cout << answer  << endl;  /* print out the last 1 degit value */
  }
  return 0;
}
