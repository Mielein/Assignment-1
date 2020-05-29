#include <iostream>
#include <array>

void swap(int *x, int *y){
    int s = *x;
    *x = *y;
    *y = s;
}

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j < r-1; ++j){
        if(a[j] <= x){
            i = i + 1;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return ++i;
}

void quicksort(int a[],int p,int r){
    if(p<r){
        int q = partition(a,p,q-1);
        quicksort(a,p,r);
        quicksort(a,q+1,r);
    }
}

void printArray(int arrPrint[], int len){  
    for (int i = 0; i < len; i++)  
        std::cout << arrPrint[i]<<std::endl;  
}  

int main(){
    std::cout<<"Type in the size of your array"<<std::endl;
    int n;
    std::cin>>n;

    int a[n];
    std::cout<<"Type in numbers that you want in your array and I’ll sort them for you "<<std::endl;
    for(int j = 0; j < n; ++j){
        std::cin>>a[j];    
    }
    quicksort(a, 0, n);
    std::cout<<"Your array sorted by quicksort is: "<<std::endl;
    printArray(a,n);
    return 0;
}

