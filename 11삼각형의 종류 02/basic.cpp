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
int DoubleArea(int a[2], int b[2],int c[2]){
     int d = (b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1]);
    return d;
}
int Distance( int a[2],int b[2]){
    int distance = (a[0] - b[0])*(a[0] - b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    return distance;
}
int Max(int a, int b, int c){
    int max = a;
    if( b > max) max = b;
    if(c > max) max = c;
    return max;
}
int main(void) {
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      int input[3][2] = {0,0,0,0,0,0};
      for(int x = 0; x<3;x++){
          for(int y =0; y<2; y++){
              cin >> input[x][y];
          }
      }
      int d = DoubleArea(input[0],input[1],input[2]);
      if( d == 0 ){
           cout << 0 << endl;
           continue;
       }
      int a = Distance(input[0],input[1]);
      int b = Distance(input[0],input[2]);
      int c = Distance(input[1],input[2]);
      int max = Max(a,b,c);
      if(a+b+c == 2*max) cout << 1 <<endl;
      else if(a+b+c < 2*max) cout << 2 <<endl;
      else  cout << 3 <<endl;
  }
  return 0;
}
