#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;
const long long int maxl=1200;
long long int length=100;
long int ar[maxl],a[maxl];
void read()
{
    for(int i=0;i<length;i++)
        a[i]=ar[i];
}
long int part(long int l,long int h);
void quicksort(long long int low,long long int high)
{
    long long int keypos;
    if(low<high)
    {
    keypos=part(low,high);
    quicksort(low,keypos-1);
    quicksort(keypos+1,high);
    }
}
long int part(long int low,long int high)
{
    long int key=a[low],i=low+1,j=high,temp;
    long int flag=1;
    while(flag)
    {
        Sleep(1);
        while(key>a[i] && i<high)
            i++;
        while(key<a[j])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
            flag=0;
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
main()
{
    for(long i=0;i<maxl;i++)
        ar[i]=rand();
    float start,fin,t;
    cout<<"QUICKSORT";
    for(;length<maxl;length+=100)
    {   read();
        start=clock();
        quicksort(0,length);
        fin=clock();
        t=(fin-start)/CLOCKS_PER_SEC;
        cout<<"\nTime taken for unsorted array of size "<<length<<": "<<t;
        start=clock();
        quicksort(0,length);
        fin=clock();
        t=(fin-start)/CLOCKS_PER_SEC;
        cout<<"\nTime taken for presorted array of size "<<length<<": "<<t;
    }
}
