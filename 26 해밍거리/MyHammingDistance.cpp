#include "MyHammingDistance.h"
#include<iostream>
#define XOR(a,b) (!(a)^!(b))
using namespace std;
// constructors
MyBinaryNumber::MyBinaryNumber ():value(0)
{
}
MyBinaryNumber::MyBinaryNumber (unsigned int val):value(val)
{
}
// accessor functions
unsigned int MyBinaryNumber::getValue () const
{
    return value;
}
// mutator functions
void MyBinaryNumber::setValue (unsigned int val)
{
    value = val;
}
// 어떤 정수의해밍무게를계산하는함수
int MyBinaryNumber::getHammingWeight() const
{
    int count = 0;
    unsigned int mask = 1;
    unsigned int n = getValue();
    while( n != 0){
        if(n & mask)
            count ++;
        n >>= 1;
    }
    return count;
}
// comptue Hamming Distanceint
int MyBinaryNumber::getHammingDistance(const MyBinaryNumber& bn) const
{
    unsigned int bn0 = getValue();
    unsigned int bn1 = bn.getValue();
    unsigned int Hd = (~bn0&~bn1) | (bn0&bn1);
    //cout <<"Hd = "<<Hd<<endl;
    MyBinaryNumber answer(Hd);
    int result = answer.getHammingWeight();
    return 32-result;
}
