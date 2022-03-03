#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void Partition(int A[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = A[(left + right) / 2]; 
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot) 
            j--;
        if (i <= j)
        {
            if (i < j)
                swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    Partition(A, left, j);
    Partition(A, i, right);
}

void QuickSort(int A[], int n)
{
    Partition(A, 0, n - 1);
}

int main(){
	fstream f,e;
	clock_t start,end;
	e.open("D:\\sort\\Time\\time.txt",ios::app);
	e<<"+Quick sort: \n";
	int A[10000];
	for(int i=0;i<10000;i++){
		f>>A[i];
	}
	//random data
	f.open("D:\\sort\\Test\\random.txt",ios::in);
	start=clock();
	QuickSort(A,10000);
	end=clock();
	e<<"Random data: "<<end-start<<" ms\n";
	f.close();
	//increasing data
	f.open("D:\\sort\\Test\\inc.txt",ios::in);
	start=clock();
	QuickSort(A,10000);
	end=clock();
	e<<"Increasing data: "<<end-start<<" ms\n";
	f.close();
	//decreasing data
	f.open("D:\\sort\\Test\\dec.txt",ios::in);
	start=clock();
	QuickSort(A,10000);
	end=clock();
	e<<"Decreasing data: "<<end-start<<" ms\n";
	f.close();
	//nearly increasing data
	f.open("D:\\sort\\Test\\nrinc.txt",ios::in);
	start=clock();
	QuickSort(A,10000);
	end=clock();
	e<<"Nearly increasing data: "<<end-start<<" ms\n";
	f.close();
	e.close();
	return 0;
}
