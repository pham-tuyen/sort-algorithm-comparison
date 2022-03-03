#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void ShakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
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
	e<<"+Shaker sort: \n";
	int A[10000];
	for(int i=0;i<10000;i++){
		f>>A[i];
	}
	//random data
	f.open("D:\\sort\\Test\\random.txt",ios::in);
	start=clock();
	ShakerSort(A,10000);
	end=clock();
	e<<"Random data: "<<end-start<<" ms\n";
	f.close();
	//increasing data
	f.open("D:\\sort\\Test\\inc.txt",ios::in);
	start=clock();
	ShakerSort(A,10000);
	end=clock();
	e<<"Increasing data: "<<end-start<<" ms\n";
	f.close();
	//decreasing data
	f.open("D:\\sort\\Test\\dec.txt",ios::in);
	start=clock();
	ShakerSort(A,10000);
	end=clock();
	e<<"Decreasing data: "<<end-start<<" ms\n";
	f.close();
	//nearly increasing data
	f.open("D:\\sort\\Test\\nrinc.txt",ios::in);
	start=clock();
	ShakerSort(A,10000);
	end=clock();
	e<<"Nearly increasing data: "<<end-start<<" ms\n";
	f.close();
	e.close();
	return 0;
}
