#include <iostream>
#include <array>
//function to swap elements
void swap(int *x, int *y){
    int s = *x;
    *x = *y;
    *y = s;
}
//function to print Arrays
void printArray(int arrPrint[], int len){  
    for (int i = 0; i < len; i++)  
        std::cout << arrPrint[i]<<std::endl;  
} 

/**function sorts the elements larger than the pivot on 
   the right of the array and the smaller ones on the left**/
int partition(int a[], int p, int r){ 
    int x = a[r]; //x = pivot
    int i = p-1; //i = smaller element

    for(int j = p; j <= r-1; ++j){ 
        //if the element(j) is smaller than the pivot
        if(a[j] < x){
            //calculate +1 to smaller element
            ++i;
            //swaps the elements
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return ++i;
}
//function that completes quicksort
void quicksort(int a[], int p, int r){
    //if the starting point is smaller than the end point
    if(p < r){
        //create index for partition
        int q = partition(a, p, r);
        //implement partition in index
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}


//main function
int main(){
    std::cout<<"Type in the size of your array"<<std::endl;
    int n;
    std::cin>>n;

    int a[n];
    std::cout<<"Type in numbers that you want in your array (make sure the numbers are not repeated!) and I’ll sort them for you "<<std::endl;
    for(int j = 0; j < n; ++j){
        std::cin>>a[j];    
    }
    quicksort(a, 0, n-1);
    std::cout<<"Your array sorted by quicksort is: "<<std::endl;
    printArray(a,n);
    return 0;
}

