#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int *LeftArr = new int[n1];
    int *RightArr = new int[n2];
    for (int i = 0; i < n1; i++)
        LeftArr[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        RightArr[i] = A[mid + 1 + i];
    int i = 0, j = 0, current = left;
    while (i < n1 && j < n2)
        if (LeftArr[i] <= RightArr[j])
            A[current++] = LeftArr[i++];
        else
            A[current++] = RightArr[j++];
    while (i < n1)
        A[current++] = LeftArr[i++];
    while (j < n2)
        A[current++] = RightArr[j++];
    delete[] LeftArr, RightArr;
}

void _MergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        _MergeSort(A, left, mid);
        _MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

void MergeSort(int A[], int n)
{
    _MergeSort(A, 0, n - 1);
}


int main(){
	fstream f,e;
	clock_t start,end;
	e.open("D:\\sort\\Time\\time.txt",ios::app);
	e<<"+Merge sort: \n";
	int A[10000];
	for(int i=0;i<10000;i++){
		f>>A[i];
	}
	//random data
	f.open("D:\\sort\\Test\\random.txt",ios::in);
	start=clock();
	MergeSort(A,10000);
	end=clock();
	e<<"Random data: "<<end-start<<" ms\n";
	f.close();
	//increasing data
	f.open("D:\\sort\\Test\\inc.txt",ios::in);
	start=clock();
	MergeSort(A,10000);
	end=clock();
	e<<"Increasing data: "<<end-start<<" ms\n";
	f.close();
	//decreasing data
	f.open("D:\\sort\\Test\\dec.txt",ios::in);
	start=clock();
	MergeSort(A,10000);
	end=clock();
	e<<"Decreasing data: "<<end-start<<" ms\n";
	f.close();
	//nearly increasing data
	f.open("D:\\sort\\Test\\nrinc.txt",ios::in);
	start=clock();
	MergeSort(A,10000);
	end=clock();
	e<<"Nearly increasing data: "<<end-start<<" ms\n";
	f.close();
	e.close();
	return 0;
}
