/****************************************************
*
* Problem:
*                집합연산
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;

void Input_data(unsigned int *set);
void view_data(unsigned int *set, int size);
void AndSet(unsigned int *answer, unsigned int *set, unsigned int *set1);
void OrSet(unsigned int *answer,unsigned int *set, unsigned int *set1);
void Minus(unsigned int *answer,unsigned int *set, unsigned int *set1);
int main(void){
  int numTestcases;
  /* read the number of test cases*/
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      unsigned int set[5] = {0};
      unsigned int set1[5] = {0};
      unsigned int answer[5] = {0};
      Input_data(set);
      Input_data(set1);

      AndSet(answer, set,set1);
      view_data(answer,5);

      OrSet(answer, set,set1);
      view_data(answer,5);

      Minus(answer, set,set1);
      view_data(answer,5);

  }//end for
  return 0;
}//end main
void Input_data(unsigned int *set){
    int numData;
    int data;
    int index;
    cin >> numData;
    for(int i=0;i<numData;i++){
        cin >> data;
        index = data/32;
        data -= index*32;
        set[index] = set[index] | 1<<data;
    }
}
void view_data(unsigned int *set, int size){
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<32;j++){
             if (((set[i]>>j) & 1)) count ++;
        }
    }
    cout << count << " ";
    for(int i=0;i<size;i++){
        for(int j=0;j<32;j++){
             if (((set[i]>>j) & 1)) cout << i*32+j <<" ";
        }
    }
    cout<<endl;
}
void AndSet(unsigned int *answer, unsigned int *set, unsigned int *set1){
    for(int i=0;i<5;i++){
        for(int j=31;j>=0;j--){
            answer[i]= ((set[i]>>j) &(set1[i]>>j));
        }
    }
}
void OrSet(unsigned int *answer,unsigned int *set, unsigned int *set1){
    for(int i=0;i<5;i++){
        for(int j=31;j>=0;j--){
            answer[i] = ((set[i] >>j) | (set1[i]>>j));
        }
    }
}
void Minus(unsigned int *answer,unsigned int *set, unsigned int *set1){
    for(int i=0;i<5;i++){
        for(int j=31;j>=0;j--){
            answer[i]= ((set[i]>>j) & ~(set1[i]>>j));
        }
    }
}
