#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

void clrscr(){
	system("@cls||clear");
	flush(stdin);
}

typedef enum {FALSE,TRUE} bool;
struct node{
	struct  node *anakkiri;
	int kode;
	int jumlah;
	int harga;
	int balance;
	struct  node *anakkanan;
};

struct node* cek(struct node *ptr,int kode){
	if(ptr!=NULL)
	{
		if(kode<ptr->kode)
		{
			ptr=cek(ptr->anakkiri,kode);
		}
		else if(kode>ptr->kode)
		{
			ptr=cek(ptr->anakkanan,kode);
		}
	}
	return(ptr);
}

struct node *insert(int kode, int harga, int jumlah, struct node *ptr, bool *bs)
{
	struct node *aptr,*bptr;
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->kode=kode;
		ptr->harga=harga;
		ptr->jumlah=jumlah;
		ptr->anakkiri=NULL;
		ptr->anakkanan=NULL;
		ptr->balance=0;
		*bs=TRUE;
		return(ptr);
	}
	if(kode<ptr->kode)
	{
		ptr->anakkiri=insert(kode, harga, jumlah, ptr->anakkiri, bs);
		if(*bs==TRUE)
		{
			switch(ptr->balance)
			{
				case -1:{
					ptr->balance=0;
					*bs=FALSE;
					break;
				}
				case 0:{
					ptr->balance=1;
					break;
				}
				case 1:{
					aptr=ptr->anakkiri;
					if(aptr->balance==1)
					{
						//rotasi LL
						ptr->anakkiri=aptr->anakkanan;
						aptr->anakkanan=ptr;
						ptr->balance=0;
						aptr->balance=0;
						ptr=aptr;
					}
					else
					{
						//rotasi LR
						bptr=aptr->anakkanan;
						aptr->anakkanan=bptr->anakkiri;
						bptr->anakkiri=aptr;
						ptr->anakkiri=bptr->anakkanan;
						bptr->anakkanan=ptr;
						if(bptr->balance==1){
							ptr->balance=-1;
						}
						else{
							ptr->balance=0;
						}
						if(bptr->balance==-1){
							aptr->balance=1;
						}
						else{
							aptr->balance=0;
						}
						bptr->balance=0;
						ptr=bptr;
					}
					*bs=FALSE;
				}
			}
		}
	}

	if(kode>ptr->kode)
	{
		ptr->anakkanan=insert(kode, harga, jumlah, ptr->anakkanan, bs);
		if(*bs==TRUE)
		{
			switch(ptr->balance)
			{
				case 1:{
					ptr->balance=0;
					*bs=FALSE;
					break;
				}
				case 0:{
					ptr->balance=-1;
					break;
				}
				case -1:{
					aptr=ptr->anakkanan;
					if(aptr->balance==-1)
					{ 
						//rotasi RR
						ptr->anakkanan=aptr->anakkiri;
						aptr->anakkiri=ptr;
						ptr->balance = 0;
						aptr->balance=0;
						ptr=aptr;
					}
					else
					{
						//rotasi RL
						bptr=aptr->anakkiri;
						aptr->anakkiri=bptr->anakkanan;
						bptr->anakkanan=aptr;
						ptr->anakkanan=bptr->anakkiri;
						bptr->anakkiri=ptr;
						if(bptr->balance== -1){
							ptr->balance=1;
						}
						else{
							ptr->balance=0;
						}
						if(bptr->balance==1){
							aptr->balance=-1;
						}
						else{
							aptr->balance=0;
						}
						bptr->balance=0;
						ptr=bptr;
					}
					*bs=FALSE;
				}
			}
		}
	}
	return(ptr);
}

void tampilkan(struct node *ptr,int level)
{
	if(ptr!=NULL){
		tampilkan(ptr->anakkanan, level+1);
		printf("\n");
		for(int i=0;i<level;i++)
		{
			printf("    ");
		}
		printf("%d",ptr->kode);
		tampilkan(ptr->anakkiri,level+1);
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->anakkiri);
		printf("- %d\t<%d> [Rp. %d]\n",ptr->kode,ptr->jumlah,ptr->harga);
		inorder(ptr->anakkanan);
	}
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("- %d\t<%d> [Rp. %d]\n",ptr->kode,ptr->jumlah,ptr->harga);
		preorder(ptr->anakkiri);
		preorder(ptr->anakkanan);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->anakkiri);
		postorder(ptr->anakkanan);
		printf("- %d\t<%d> [Rp. %d]\n",ptr->kode,ptr->jumlah,ptr->harga);
	}
}

int main()
{
	bool bs;
	int kode,harga,jumlah,pilih;
	char nama[50];
	struct node *root=(struct node *)malloc(sizeof(struct node));
	root=NULL;
	do{
		clrscr();
		printf("WELCOME TO JRH STORAGE MANAGEMENENT\n");
		printf("===================================\n\n");
		printf("1. Add Barang\n");
		printf("2. Display AVL Tree\n");
		printf("3. Preorder, Inorder, Postorder\n");
		printf("4. Exit\n");
		do{
			printf(">> Input Choice : ");
			scanf("%d",&pilih);
		}while(pilih<1||pilih>4);
		switch(pilih)
		{
			case 1:{
				clrscr();
				do{
					printf("Masukkan Kode Barang [0-9][0-9][1-9]: ");
					scanf("%d",&kode);
				}while(kode<0001||kode>999);
				do{
					printf("Masukkan Jumlah Barang [1..1000]: ");
					scanf("%d",&jumlah);
				}while(jumlah<1||jumlah>1000);			
				do{
					printf("Masukkan Harga Barang [10000..999999]: Rp. ");
					scanf("%d",&harga);
				}while(harga<10000||harga>999999);
				if(cek(root,kode)==NULL)
				{
					root=insert(kode, harga, jumlah, root, &bs);
					printf("Add New Item Success\n");
				}
				else
				{
					printf("Kode Barang Sudah Ada\n");
				}
				getch();
				break;
			}
			case 2:{
				clrscr();
				if(root==NULL)
				{
					printf("Tidak Ada Data\n");
				}
				else
				{
					printf("AVL Tree :\n");
					tampilkan(root, 1);
				}
				getch();
				break;
			}
			case 3:{
				clrscr();
				printf("Inorder: \n");
				inorder(root);
				printf("\nPreorder: \n");
				preorder(root);
				printf("\nPostorder: \n");
				postorder(root);
				getch();
				break;
			}
			case 4:{
				break;
			}
		}
	}while(pilih!=4);
}

