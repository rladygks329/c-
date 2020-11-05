/****************************************************
*
* Problem:
*                다각형 면적
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
int Area(int a[2], int b[2]);
int AbsoluteValue(int a);
int main(void){
  int numTestcases;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int angle;
      int area = 0;
      cin >> angle;
      int data[angle][2];
      for ( int x=0; x<angle; x++){
          for( int y =0; y<2;y++){
              cin >> data[x][y];
          }
      }//end data in
      //calculate
      for( int index =0; index <angle-1;index++){
          area += Area(data[index], data[index+1]);
      }
      area += Area(data[angle-1],data[0]);
      //output
      cout << AbsoluteValue(area) <<" ";
      if( area > 0) cout << 1 << endl;
      else cout << -1 << endl;
  }
  return 0;
}
int Area(int a[2], int b[2]){
    //int area = a[0]*b[1] - a[1]*b[0];
    int area = (a[0]+b[0])*(b[1]-a[1]);
    return area;
}
int AbsoluteValue(int a){
    if(a < 0) a *= -1;
    return a;
}
