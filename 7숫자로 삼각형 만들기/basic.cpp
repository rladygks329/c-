/****************************************************
*
* Problem:
*                숫자로 삼각형 만들기기
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
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int numOfLength;
      cin >> numOfLength;
      for(int j = 0; j <numOfLength; j++){
          for( int k =0;k<=j; k++){
              cout << j+1+numOfLength*k - k*(k+1)/2 << " ";
          }
            cout <<"\n";
      }
  }
  return 0;
}
