#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void InsertionSort(int A[], int n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        x = A[i];
        pos = i - 1;
        while (pos >= 0 && A[pos] > x)
        {
            A[pos + 1] = A[pos];
            pos--;
        }
        A[pos + 1] = x;
    }
}


int main(){
	fstream f,e;
	clock_t start,end;
	e.open("D:\\sort\\Time\\time.txt",ios::app);
	e<<"+Insertion sort: \n";
	int A[10000];
	for(int i=0;i<10000;i++){
		f>>A[i];
	}
	//random data
	f.open("D:\\sort\\Test\\random.txt",ios::in);
	start=clock();
	InsertionSort(A,10000);
	end=clock();
	e<<"Random data: "<<end-start<<" ms\n";
	f.close();
	//increasing data
	f.open("D:\\sort\\Test\\inc.txt",ios::in);
	start=clock();
	InsertionSort(A,10000);
	end=clock();
	e<<"Increasing data: "<<end-start<<" ms\n";
	f.close();
	//decreasing data
	f.open("D:\\sort\\Test\\dec.txt",ios::in);
	start=clock();
	InsertionSort(A,10000);
	end=clock();
	e<<"Decreasing data: "<<end-start<<" ms\n";
	f.close();
	//nearly increasing data
	f.open("D:\\sort\\Test\\nrinc.txt",ios::in);
	start=clock();
	InsertionSort(A,10000);
	end=clock();
	e<<"Nearly increasing data: "<<end-start<<" ms\n";
	f.close();
	e.close();
	return 0;
}
