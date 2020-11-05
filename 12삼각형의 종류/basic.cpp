/****************************************************
*
* Problem:
*                 삼각형의 종류
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;

int main(void){
  int numTestcases,a,b,c;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
          cin >> a;
          cin >> b;
          cin >> c;
          if( a+b <= c ) cout << 0 << endl;
          else if( (a == b) && ( b== c)) cout <<1 << endl;
          else if(a*a + b*b == c*c)  cout << 2 << endl;
          else if((a == b) || (b == c) ) cout <<3 << endl;
          else cout <<4 << endl;
      }
  return 0;
}
