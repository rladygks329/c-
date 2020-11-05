/****************************************************
*
* Problem:
                    이동평균
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
void MovingAvg(int *data, int k,int size);
int main(void){
  int numTestcases;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int numData,input,k;
      cin >> numData;

      int *data = nullptr;
      data = new int[numData];
      for(int j=0;j<numData;j++){
          cin >> input;
          data[j] = input;
      }
      /*for(int j=0;j<numData;j++){
          cout << data[j] << " ";
      }
      cout <<endl;*/
      cin >> k;
      MovingAvg(data, k, numData);
      delete data;
 }
  return 0;
}
 void MovingAvg(int *data, int k,int size){
     int count = size - k +1;
     int avg = 0;
     cout << count <<" ";
     for(int i=0;i<=size-k;i++){
         for(int j=0; j<k;j++){
             avg += data[i+j];
         }
         avg/=k;
         cout << avg << " ";
         avg =0;
     }
     cout <<endl;
 }
