#include <omp.h>
#include <iostream>
using namespace std;

int main ()
{
int arr[5]={1,2,3,4,5},i;
float avg=0;
#pragma omp parallel
{
int id=omp_get_thread_num();
#pragma omp for
for(i=0;i<5;i++)
{
avg=avg+arr[i];
cout<<"for i= "<<i<<" thread "<<id<<"is executing "<<endl;

}

}
avg=avg/5;
cout<<"avg is "<<avg;
return 0;
}
