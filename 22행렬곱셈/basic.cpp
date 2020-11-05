/****************************************************
*
* Problem:
*                행렬 곱셈
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
void setData(int **data,int row ,int column);
void setZero(int **data,int row, int column);
void viewData(int **data,int row ,int column);
void multiData(int **answer, int **data, int **data1, int row, int column, int column2);
int main(void){
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      int row, column, column2;
      cin >> row;
      cin >> column;
      cin >> column2;

      int ** data = nullptr;
      data = new int*[row];
      for(int j =0; j<row;j++) {
        data[j] = new int[column];
      }

      int ** data1 = nullptr;
      data1 = new int*[column];
      for(int j =0; j<column;j++) {
        data1[j] = new int[column2];
      }

      int ** answer = nullptr;
      answer = new int*[row];
      for(int j =0; j<row;j++) {
        answer[j] = new int[column2];
      }
      setZero(answer,row,column2);
      setData(data,row,column);
      setData(data1,column, column2);
      multiData(answer,data,data1,row,column,column2);
      viewData(answer,row,column2);
      for(int j =0; j<row;j++) {
        delete[] data[j];
      }
      delete []data;

      for(int j =0; j<column;j++) {
        delete[] data1[j];
      }
      delete []data1;

      for(int j =0; j<row;j++) {
        delete[] answer[j];
      }
      delete []answer;

  }// end for
  return 0;
}// end main
void setZero(int **data,int row, int column){
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          data[i][j] = 0;
      }
  }
}
void multiData(int **answer, int **data, int **data1, int row, int column, int column2){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            for(int k =0; k < column2;k++){
                answer[i][k] += data[i][j] * data1[j][k];
            }
        }
    }
}
void setData(int **data,int row ,int column){
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          cin >> data[i][j];
      }
  }
}
void viewData(int **data,int row ,int column){
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          cout << data[i][j]<<" ";
      }
      cout << endl;
  }
}
