//---------------------------------------------------------------------------

#include <vcl.h>
#include <system.Diagnostics.hpp>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int * x;
int * x_Bubble;
int * x_Selection;
int * x_Bubble_up1;
int * x_Bubble_up2;
int * x_ins;
int * x_mrg;
int * x_Qic;
int * x_hep;
int n;
TStopwatch st;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void bubble_sort(int *x , int n)
{
	for (int i=0 ; i < n; i++)
	{
		for (int j=0; j<n-1; j++)
		{
			if (x[j]>x[j+1])
			{
				int t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
}
//---------------------------------------------------------------------------
void bubble_sort_update1(int *x , int n)
{
	for (int i=0 ; i < n; i++)
	{
		for (int j=0; j<n-i-1; j++)
		{
			if (x[j]>x[j+1])
			{
				int t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
}
//---------------------------------------------------------------------------
void bubble_sort_update2(int *x , int n)
{
	for (int i=0 ; i < n; i++)
	{
		bool b=false;
		for (int j=0; j<n-i-1; j++)
		{
			if (x[j]>x[j+1])
			{
				int t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
				b=true;
			}
		}
		if (b==false) {
			break;
		}
	}
}
//---------------------------------------------------------------------------
void selection_sort(int *x , int n)
{
	for (int i=0; i<n; i++)
	{
		int min=i;
		for (int j=i; j<n; j++)
		{
			if (x[min]>x[j])
			{
				min=j;
			}
		}
		int t=x[min];
		x[min]=x[i];
		x[i]=t;
	}
}
//---------------------------------------------------------------------------
void insertion_sort2(int * x, int n)
{
	for (int i = 0; i < n; i++)
	{
		int t = x[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (x[j] > t)
			{
				x[j + 1] = x[j];
				x[j] = t;
			}
			else	{ break; }
		}
	}
}

void insertion_sort(int *x , int n)
{
	for (int i=0; i<n; i++)
	{
		int t=x[i];
		int j=i-1;
		while (j>=0 && t<x[j])
		{
		   x[j+1]=x[j];
		   x[j]=t;
		   j--;
		}
	}
}
//---------------------------------------------------------------------------
void merge(int a[],int sx,int lx,int sy,int ly)
{
	int *x=new int [lx];
	int *y=new int [ly];
	for (int i=0; i<lx; i++) {
		x[i]=a[sx+i];
	}
	for (int i=0; i<ly; i++) {
		y[i]=a[sy+i];
	}

	int n=lx+ly;
	int yi=0;
	int xi=0;

	for (int i=sx; i<sx+n; i++)
	{
		if (x[xi]<y[yi] && xi<lx) {
			a[i]=x[xi++];
			continue;
		}
		if (y[yi]<x[xi] && yi<ly) {
			a[i]=y[yi++];
			continue;
		}
		if (xi>=lx) {
			a[i]=y[yi++];
			continue;
		}
		if (yi>=ly) {
			a[i]=x[xi++];
			continue;
		}
	}

}

void mergesort(int x[],int s,int n)
{
	if (n>1) {
		mergesort(x,s,n/2);
		mergesort(x,s+n/2,n-n/2);
		merge(x,s,n/2,s+n/2,n-n/2);
	}
}
//---------------------------------------------------------------------------
int partition(int x[],int s, int n)
{
	int p_index=s;
	int p=x[s];
	int i=s;
	for (int j=s; j<s+n; j++) {
		if (x[j]<p) {
			i++;
			int t=x[j];
			x[j]=x[i];
			x[i]=t;
		}
	}
	int t=x[i];
	x[i]=x[s];
	x[s]=t;
	p_index=i;
	return p_index;
}
void Quicksort(int x[] , int s, int n)
{
	if (n>1)
	{
		int p =partition(x,s,n);
		Quicksort(x ,s   , p-s);
		Quicksort(x ,p+1 , n-(p-s)-1 );
	}
}
void Quicksort_up1(int x[] , int s, int n)
{
	while (n>1)
	{
		int p =partition(x,s,n);
		if (p<n-p)
		{
			Quicksort_up1(x ,s   , p-s);
			s=p+1;
			n=n-(p-s)-1;
		}
		else
		{
			Quicksort_up1(x ,p+1 , n-(p-s)-1 );
			n=p-s;
		}
	}
}
//---------------------------------------------------------------------------
void heapy(int a[], int idx, int n)
{
	int l = 2 * idx + 1;
	int r = 2 * idx + 2;
	int min = idx;
	if (l<n && a[min]<a[l])
	{
		min = l;
	}
	if (r<n && a[min]<a[r])
	{
		min = r;
	}
	if (min != idx)
	{
		int t = a[min];
		a[min] = a[idx];
		a[idx] = t;

		heapy(a, min, n); // b ������
	}
}

void heap_sort(int a[],int n)
{
	for (int i=n/2-1; i >=0 ; i--)
	{
		heapy(a,i,n);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int t = a[0];
		a[0] = a[i];
		a[i] = t;
		heapy(a, 0, i); //  i = n-1
	}
}
//---------------------------------------------------------------------------
int * create_array(int n)
{
	srand(time(NULL));
	int * _x=NULL;
	_x=new int [n];
	x_Bubble=new int [n];
	x_Selection=new int [n];
	x_Bubble_up1=new int [n];
	x_Bubble_up2=new int [n];
	x_ins=new int [n];
	x_mrg=new int [n];
	x_Qic=new int [n];
	x_hep=new int [n];
	for (int i=0; i<n; i++) {
		//_x[i]=n-i;
		_x[i]=random(1000);
		x_Bubble[i]=_x[i];
		x_Selection[i]=_x[i];
		x_Bubble_up1[i]=_x[i];
		x_Bubble_up2[i]=_x[i];
		x_ins[i]=_x[i];
		x_mrg[i]=_x[i];
		x_Qic[i]=_x[i];
		x_hep[i]=_x[i];
	}
	return _x;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Edit1->Text=="") {
		ShowMessage("���� ��� ��������");
		Edit1->SetFocus();
	}
	else
	{
		n=StrToInt(Edit1->Text);
		x=new int [n];
		x=create_array(n);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	ListBox1->Items->Clear();
	for (int i=0; i<n; i++) {
		ListBox1->Items->Add(IntToStr(x_Qic[i]) );
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	st.Start();
	bubble_sort(x_Bubble,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	st.Start();
	selection_sort(x_Selection,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	st.Start();
	bubble_sort_update1(x_Bubble_up1,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	st.Start();
	bubble_sort_update2(x_Bubble_up2,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
	st.Start();
	insertion_sort2(x_ins,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------
/*

100 000 items
bubble 		42 sec
selection 	11 sec
bubble up1	30 sec
bubble up2	30 sec
insertion	7  sec

merge       16 msec   for 100 000
merge       281 msec  for 1 000 000
merge       3  sec    for 10 000 000

quick       16   msec   for 100 000
quick       1    sec    for 1 000 000

heap        31   msec   for 100 000

*/




void __fastcall TForm1::Button8Click(TObject *Sender)
{
	st.Start();
	mergesort(x_mrg,0,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	st.Start();
	Quicksort(x_Qic,0,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    st.Start();
	heap_sort(x_hep,n);
	st.Stop();
	ShowMessage(IntToStr(st.ElapsedMilliseconds));
	st.Reset();

}
//---------------------------------------------------------------------------

