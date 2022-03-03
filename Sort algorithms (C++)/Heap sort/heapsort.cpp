#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
void HeapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
	        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

void swap(int a,int b){
	int t=a;
	a=b;
	b=t;
}

int main(){
	fstream f,e;
	clock_t start,end;
	e.open("D:\\sort\\Time\\time.txt",ios::app);
	e<<"+Heap sort: \n";
	int A[10000];
	for(int i=0;i<10000;i++){
		f>>A[i];
	}
	//random data
	f.open("D:\\sort\\Test\\random.txt",ios::in);
	start=clock();
	HeapSort(A,10000);
	end=clock();
	e<<"Random data: "<<end-start<<" ms\n";
	f.close();
	//increasing data
	f.open("D:\\sort\\Test\\inc.txt",ios::in);
	start=clock();
	HeapSort(A,10000);
	end=clock();
	e<<"Increasing data: "<<end-start<<" ms\n";
	f.close();
	//decreasing data
	f.open("D:\\sort\\Test\\dec.txt",ios::in);
	start=clock();
	HeapSort(A,10000);
	end=clock();
	e<<"Decreasing data: "<<end-start<<" ms\n";
	f.close();
	//nearly increasing data
	f.open("D:\\sort\\Test\\nrinc.txt",ios::in);
	start=clock();
	HeapSort(A,10000);
	end=clock();
	e<<"Nearly increasing data: "<<end-start<<" ms\n";
	f.close();
	e.close();
	return 0;
}
