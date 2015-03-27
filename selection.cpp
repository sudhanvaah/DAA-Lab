#include<cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
long length = 1000;
const long max_length = 100000;
int list[max_length];
int sortedlist[300000];
double total_time,start,end,d1;
void read()
{
    for (long i = 0; i < length; i++)
    {
        sortedlist[i] = list[i];
    }
}
void selectionSort()
{
    int temp,m;
    for(long i = 0; i<length; i++)
    {
        m=i;
        for(long j = i+1; j < length-i; j++)
        {
            if(sortedlist[m]>sortedlist[j])
                m=j;
        }
        if(m!=i)
        {
            temp=sortedlist[m];
            sortedlist[m]=sortedlist[i];
            sortedlist[i]=temp;
        }
    }
}
int main()
{
int i;
int r;
for (i = 0; i < max_length; i++)
 {
  r = rand();
  list[i] = r;
 }
int maxlen = 0;
for (length = length; length <= max_length && maxlen ==0; )
    {
        read();
        start = clock();
        selectionSort();
        end = clock();
cout<<"\nWORST CASE";
cout<<"\nStart time for selection Sort is "<<start;
cout<<"\nEnd time for selection Sort is "<<end;
total_time = ((double) (end- start))/CLOCKS_PER_SEC;
cout<<"\nTime taken (worst case) to selection Sort "<<length<<" random numbers is: "<<total_time<<"\n";
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        start = clock();
        selectionSort();
        end = clock();
cout<<"\nBEST CASE";
cout<<"\nStart time for selection Sort is "<<start;
cout<<"\nEnd time for selection Sort is "<<end;
total_time = ((double) (end- start))/CLOCKS_PER_SEC;
cout<<"\nTime taken (best case) to selection Sort "<<length<<" random numbers is: "<<total_time<<"\n";
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
if (length <max_length)
{
length = length+10000;
}
else if (length = max_length)
{
length = length;
maxlen=1;
}
}
}
