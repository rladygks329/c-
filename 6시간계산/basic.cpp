/****************************************************
*
* Problem:
*                시간계산
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;

int secondCalculator(int a, int b, int c){
    int second = 0;
    second += a*3600 + b*60 + c;
    return second;
}
void secondConvertor( int second){
    int a,b,c,day;
    day = second/3600/24;
    a = second/3600%24;
    b = (second%3600)/60;
    c = (second%3600)%60;
    cout << day <<" "<< a << " " << b << " " << c <<endl;
    //cout << a << b << c << endl;
}

int main(void){
  int numTestcases;
  /* read the number of test cases*/
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int numOfPeople,fh,fm,fs,h,m,s;
      cin >> numOfPeople;
      int seconds = 0;
      for ( int j=0; j<numOfPeople; j++){
          //cout <<"k";
          cin >> fh;
          cin >> fm;
          cin >> fs;
          cin >> h;
          cin >> m;
          cin >> s;
          seconds += secondCalculator(h,m,s)-secondCalculator(fh,fm,fs);
      }
      secondConvertor(seconds);
  }
  return 0;
}
