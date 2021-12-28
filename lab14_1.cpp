#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N ,double B[] )
{
    double sum , min = A[0] , max = A[0] , mean=0 , sumx2=0 , sumGM = 0 , sumHM = 0;
    for(int i=0; i<N ;i++)
    {
        if(A[i]<min) min=A[i];
        if(A[i]>max) max=A[i];

        sum+=A[i] ; mean=sum/N;
        sumx2 += pow(A[i],2);
        sumGM += log10(A[i]);
        sumHM +=1/A[i];
    }
    B[0]=mean;
    B[1]=sqrt(sumx2/N - pow(mean,2));
    B[2]=pow(10,sumGM/N);
    B[3]=N/sumHM;
    B[4]=max;
    B[5]=min;
}
