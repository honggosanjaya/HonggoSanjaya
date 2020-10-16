#include<iostream>
using namespace std;

int banyak=0;
int banyak1=0;
void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}

void menu(){
	cout<<"\nWelcome to Chatime Delivery Zone\n";
	cout<<"==================================\n";
	cout<<"1.Order Milk Tea\n";
	cout<<"2.Pay\n";
	cout<<"3.Exit\n\n";
}

void menu1(){
	int order;
	cout<<"choose an order\n";
	cout<<"================\n\n";
	cout<<"1.Java Pearl Milk Tea <@Rp.18.500>\n";
	cout<<"2.Grass Jelly Milk Tea <@Rp. 20500>\n";
	do{
		cout<<"Which Milk Tea do You Want to Order[1-2]:";
		cin>>order;
	}while(order<1||order>2);
	if(order==1)
	{
		cout<<"How much Java Pearl Milk Tea do you want to order";
		cin>>banyak;
	}
	else
	{
		cout<<"How Much Grass Jelly Milk Tea do you want to order";
		cin>>banyak1;
	}
	cout<<"Thank you...";
}

void menu2(){
	int harga,bayar,kembali;
		if(banyak==0&&banyak1==0)
		{
			cout<<"You haven't buy anything..";
		}
		else
		{
			cout<<"You Have Ordered  "<<banyak<<"Java Pearl Milk Tea and  "<<banyak1<<"Grass Jelly Milk Tea";
			harga=(banyak*18500)+(banyak1*20500);
			cout<<"\ntotal price:"<<harga;
			do{
				cout<<"\nInput your money[minimum Rp."<<harga<<"]:";
				cin>>bayar;
			}while(bayar<harga);
			kembali=bayar-harga;
			cout<<"\nyour change:"<<kembali;
		}
}

void exit(){
	cout<<"Thank you for buying our milk tea";
}

int main(){
	int pilih;
	
	do{
		menu();
		cout<<"Choose:";
		cin>>pilih;
		switch(pilih){
			case 1:CLEAR_SCREEN();menu1();break;
			case 2:CLEAR_SCREEN();menu2();break;
			case 3:CLEAR_SCREEN();exit();break;
		}
	}while(pilih!=3);
}
