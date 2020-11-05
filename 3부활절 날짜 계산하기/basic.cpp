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
      int year,n,c,t,i_,j_,o,k,l,p,q,m,day;
      cin >> year;
      c = year/100;
      n = year - year/19*19;
      t = (c-17)/25;
      i_= c-(c/4+(c-t)/3)+n*19+15;
      j_=i_-(i_/30*30);
      k = j_-(j_/28 *(i_-j_)/28 * 29/(j_+i_) * (21-n)/11);
      l = year/4 + year +j_+2-c+c/4;
      p =  l-(l/7*7);
      q = k-p;
      m = (q+40)/44+3;
      day = (q+28)-(m/4*31);
      day = (int)day;
      m = (int)m;
      cout << m << " "<< day << endl;

      }
  return 0;
}
