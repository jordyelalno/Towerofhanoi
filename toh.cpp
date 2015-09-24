#include<cstdlib>
#include<stdio.h>
#include<iomanip>
#include<iostream>

using namespace std;

struct node1
{
    int data1;
    node1 *next1;
}*top1 = NULL, *p1 = NULL, *np1 = NULL;

struct node2
{
    int data2;
    node2 *next2;
}*top2 = NULL, *p2 = NULL, *np2 = NULL;

struct node3
{
    int data3;
    node3 *next3;
}*top3 = NULL, *p3 = NULL, *np3 = NULL;

void inputtower1(int data)
{
    np1 = new node1;
    np1->data1 = data;
    np1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = np1;
    }
    else
    {
        np1->next1 = top1;
        top1 = np1;
    }
    cout<<" A"<<endl;
}

void inputawal(int data)
{
    np1 = new node1;
    np1->data1 = data;
    np1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = np1;
    }
    else
    {
        np1->next1 = top1;
        top1 = np1;
    }
}
    
void inputtower2(int data)
{
    np2 = new node2;
    np2->data2 = data;
    np2->next2 = NULL;
    if (top2 == NULL)
    {
        top2 = np2;
    }
    else
    {
        np2->next2 = top2;
        top2 = np2;
    }
    cout<<" B"<<endl;
}

void inputtower3(int data)
{
    np3 = new node3;
    np3->data3 = data;
    np3->next3 = NULL;
    if (top3 == NULL)
    {
        top3 = np3;
    }
    else
    {
        np3->next3 = top3;
        top3 = np3;
    }
    cout<<" C"<<endl;
}

int ambil1()
{
    if (top1 == NULL)
    {
        return 0;
    }
    else
    {
        p1 = top1;
        top1 = top1->next1;
        cout<<" dari A ke ";
        return(p1->data1);
        delete(p1);
    }
}

int ambil2()
{
    if (top2 == NULL)
    {
        return 0;
    }
    else
    {
        p2 = top2;
        top2 = top2->next2;    
        cout<<" dari B ke ";
        return(p2->data2);
        delete(p2);
    }
}

int ambil3()
{
    if (top3 == NULL)
    {
        return 0;
    }
    else
    {
        p3 = top3;
        top3 = top3->next3;
    	cout<<" dari C ke ";
        return(p3->data3);
        delete(p3);
    }
}

void MenaraHanoi(int N, char asal, char bantu, char tujuan);

int main()

{
	char jawaban;
	
	cout<<"=========PROGRAM MENARA HANOI=========\n\n";
    cout<<setw(25)<<"Dibuat oleh:\n";
    cout<<"Dedy Van Hauten \t(1400910039)\n";
    cout<<"Jordy Cahyo Elalno \t(1400910024)\n";
    cout<<"Richard Nathaniel C \t(1400910015)\n\n";

    int piringan,i;

    cout<< "\nPROGRAM MENARA HANOI\n";

    cout<< "Masukkan banyaknya piringan: ";

    scanf("%d",&piringan);
    
    if(cin.fail()){
    	cin.clear();
    	cin.ignore();
    	system("cls");
    	
    	cout<<"Input Hanya Boleh Angka! \n";
    	main();
    	
    } else
    { if(piringan<3){
    	cin.clear();
    	cin.ignore();
    	system("cls");
    	
    	cout<<"Input Tidak Boleh Kurang Dari 3 \n";
    	main();
    }
    }

    cout<< endl;
    
    for (i = piringan; i >= 1; i--)
    {
        inputawal(i);
    } 

    MenaraHanoi(piringan,'A','B','C');
    
	cout<<"Tekan Y untuk kembali ke Awal, tekan yang lain untuk mengakhiri program  ";
	cin>>jawaban;
    if(jawaban == 'y' || jawaban == 'Y')
    {
    	system("cls");
    	main();
    } else{
    	exit(EXIT_SUCCESS);
    }

    return 0;

}

void MenaraHanoi(int N, char asal, char bantu, char tujuan)

{

    if(N == 1)
	{
		cout<<"Piringan "<<N;
		if (asal=='A') {
			ambil1();
			if (tujuan=='B') {inputtower2(N);}
			if (tujuan=='C') {inputtower3(N);}
		} 
		if (asal=='B') {
			ambil2();
			if (tujuan=='A') {inputtower1(N);}
			if (tujuan=='C') {inputtower3(N);}
		} 
		if (asal=='C') {
			ambil3();
			if (tujuan=='B') {inputtower2(N);}
			if (tujuan=='A') {inputtower1(N);}
		} 
	}
    else
    {
        MenaraHanoi(N-1,asal,tujuan, bantu);
        cout<<"Piringan "<<N;
        if (asal=='A') {
			ambil1();
			if (tujuan=='B') {inputtower2(N);}
			if (tujuan=='C') {inputtower3(N);}
		} 
		if (asal=='B') {
			ambil2();
			if (tujuan=='A') {inputtower1(N);}
			if (tujuan=='C') {inputtower3(N);}
		} 
		if (asal=='C') {
			ambil3();
			if (tujuan=='B') {inputtower2(N);}
			if (tujuan=='A') {inputtower1(N);}
		} 
        MenaraHanoi(N-1, bantu, asal, tujuan);
    }
}

