/****************************************************
*
* Problem:
*                패리티 비트
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
#include<bitset>
using namespace std;
int CountOnes(int data);

int main(void){
    int numTestcases;
    unsigned int data;
    cin >>  numTestcases;
    for ( int i=0; i<numTestcases; i++){
        cin >> data;
        int count = CountOnes(data);
        if(count%2){
            //add 1
            data += (1<<31);
        }
        cout << data << endl;
    }
    return 0;
}

int CountOnes(int data){
    int count = 0;
    for(int i = 0; i<31; i ++){
        if((data >>i)%2) count++;
    }
    return count;
}
