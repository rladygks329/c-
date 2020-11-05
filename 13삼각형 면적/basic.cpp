/****************************************************
*
* Problem:
*                 삼각형의 면적
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

int main(void){
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      int input[3][2] = {0,0,0,0,0,0};
      //data input
      for(int x = 0; x<3;x++){
          for(int y =0; y<2; y++){
              cin >> input[x][y];
          }
      }

      int d = DoubleArea(input[0],input[1],input[2]);
      //judge
      if( d > 0) cout << d <<" " << 1 << endl;
      else if(d == 0) cout << 0 << " " << 0 << endl;
      else cout << -1*d << " " << -1 << endl;
  }
  return 0;
}
