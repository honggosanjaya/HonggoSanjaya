#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}

class toko{
	private:
		int quan;
		int price;
		char type[30];
		char colour[30];
	public:
		toko(){
			quan=0;
			price=0;
		}
		~toko(){
			cout<<endl<<"All of the Orders have been removed.\n Thank you for Shopping with Pretty Dress Shop";
		}
		void set_quan(int banyak,int harga){
			this->quan=banyak;
			this->price=harga;
		}
		void set_type(char* tipe){
			strcpy(this->type,tipe);
		}
		void set_colour(char* warna){
			strcpy(this->colour,warna);		
		}
		int GetQuan(){
			return quan;
		}
		int GetPrice(){
			return price;
		}
		string GetType(){
			return type;
		}
		string GetColour(){
			return colour;
		}
};

void pesan(int& order,toko *baju[])
{
	char tipe[30];
	char warna[30];
	int harga,banyak;
	int& ref=banyak;
	baju[order]=new(nothrow)toko[11];
	if(order<10)
	{
		do{
			cout<<"Input the Dress Type [4-20 Characters]:";
			cin>>tipe;
		}while(strlen(tipe)<4||strlen(tipe)>20);
		baju[order]->set_type(tipe);
		do{
			cout<<"Input the Dress Colour [4-20 Characters]:";
			cin>>warna;
		}while(strlen(warna)<4||strlen(warna)>20);
		baju[order]->set_colour(warna);
		do{
			cout<<"Input the Dress Price [500..2000]:USD. ";
			cin>>harga;
		}while(harga<500||harga>2000);
		do{
			cout<<"Input the Quantity of the Dress [1..20]:";
			cin>>banyak;
		}while(ref<1||ref>20);
		baju[order]->set_quan(banyak,harga);
		order++;
		cout<<"Success to add a Dress Order";
	}
	else
	{
		cout<<"Can't take more order!!";
	}
}

void view(int& order, toko *baju[])
{
	if(order>0)
	{
		cout<<"List Ordered Dresses"<<endl;
		cout<<"======================"<<endl<<endl;
		cout<<"================================================================"<<endl;
		cout<<"|No.|  	Type		|   Colour   | Qty |  Price  |  Subtotal  |"<<endl;
		cout<<"================================================================"<<endl;
		int i,total=0,subtotal;
		int no=1;
		for(i=0;i<order;i++)
		{
			subtotal=(baju[i]->GetQuan())*(baju[i]->GetPrice());
			total=total+subtotal;
			cout<<"| "<<no<<" |\t\t\t"<<baju[i]->GetType()<<" |\t"<<baju[i]->GetColour()<<" |\t"<<baju[i]->GetQuan()<<" |\t"<<baju[i]->GetPrice()<<" |\t"<<subtotal<<" |"<<endl;
			no++;
		}
		cout<<"================================================================"<<endl;
		cout<<"Total Price: USD."<<total;
	}
	else
	{
		cout<<"There is no order"<<endl;
	}
}

int main()
{
	toko *baju[11];
	int pilih,order=0;
	do{
		CLEAR_SCREEN();
		cout<<"Welcome to Pretty's Dress Shop"<<endl;
		cout<<"==============================="<<endl<<endl;
		cout<<"1. Order Dress"<<endl;
		cout<<"2. View Order Dress"<<endl;
		cout<<"3. Exit and Delete All Orders"<<endl;
		do{
			cout<<"Choice:";
			cin>>pilih;
		}while(pilih<1||pilih>3);
		switch(pilih){
			case 1:{
				CLEAR_SCREEN();
				pesan(order,baju);
				getch();
				break;
			}
			case 2:{
				CLEAR_SCREEN();
				view(order,baju);	
				getch();
				break;
				}
			case 3:{
				break;
			}	
		}
	}while(pilih!=3);
}






