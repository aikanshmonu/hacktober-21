
#include<iostream>
using namespace std;

void moveneg(int *arr,int size);

int main()
{
    int arr[] = {-1,2,3,4,-5};
    int *a;
    int size = sizeof(arr)/sizeof(arr[0]);
    moveneg(arr,size);
    a=arr;
    for (int i = 0;i<size;i++){
        cout<<*(a+i)<<endl;
    }
    return 0;
}

void moveneg(int *arr,int n)
{
    int pve = n-1;
    int nve = 0;
    while(nve<pve){
        if(arr[nve]>0){
            swap(arr[nve],arr[pve--]);
            continue;
        }
        nve++;
    }
}