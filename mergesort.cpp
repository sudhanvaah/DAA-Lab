#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const long long int maxl=100000;
long long int length=1000;
long int ar[maxl],a[maxl];
void read()
{
    for(int i=0;i<length;i++)
        a[i]=ar[i];
}
void merge(long int low, long int mid,long int high)
{
    long int i=low,j=mid+1,k=low,c[maxl];
    while(i<=mid and j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=low;i<k;i++)
        a[i]=c[i];
}
void mergesort(long int low,long int high)
{
    long int mid;
    if(low<high)
    {
     mid=(low+high)/2;
     mergesort(low,mid);
     mergesort(mid+1,high);
     merge(low,mid,high);
    }
}
main()
{
    for(long i=0;i<maxl;i++)
        ar[i]=rand();
    float start,fin,t;
    cout<<"MERGE SORT";
    for(;length<maxl;length+=10000)
    {   read();
        start=clock();
        mergesort(0,length);
        fin=clock();
        t=(fin-start)/CLOCKS_PER_SEC;
        cout<<"\n\n---------------------------------------";
        cout<<"\nTime taken for unsorted array of size "<<length<<": "<<t;
        start=clock();
        mergesort(0,length);
        fin=clock();
        t=(fin-start)/CLOCKS_PER_SEC;
        cout<<"\n\nTime taken for presorted array of size "<<length<<": "<<t;
        cout<<"\n---------------------------------------";
    }
    return 0;
}
