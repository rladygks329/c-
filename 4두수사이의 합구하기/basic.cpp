/****************************************************
*
* Problem:
*               두정수사이의모든정수의합구하기
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
      int a,b;
      int sum = 0;

      cin >> a;
      cin >> b;
      if(a<b){
          sum = (b-a+1)*(a+b)/2;
      }
      else{
           sum = (a-b+1)*(a+b)/2;
      }
            cout << sum  << endl;
  }
  return 0;
}
