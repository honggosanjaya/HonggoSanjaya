#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class bentuk{
	protected:
		int lebar;
		int panjang;
		int number1;
		int number2;
		string kata;
	public:
		virtual int pattern()=0;
		bentuk(){
			lebar=0;
			panjang=0;
		}
		void SetLebar(int lebar){
			this->lebar=lebar;
		}
		void SetPanjang(int panjang){
			this->panjang=panjang;
		}
		int GetPanjang(){
			return panjang;
		}
		int GetLebar(){
			return lebar;
		}
		void SetNum1(int number1){
			this->number1=number1;
		}
		void SetNum2(int number2){
			this->number2=number2;
		}
		int GetNum1(){
			return number1;
		}
		int GetNum2(){
			return number2;
		}
		void SetKata(string kata){
			this->kata=kata;
		}
		string GetKata(){
			return kata;
		}		
};

class bentuk1:public bentuk{
	public:
		int pattern(){
			for (int a=1; a<=lebar; a++){
				for(int b=0; b<panjang; b++){
					cout<<kata[b];	
				}
				cout<<endl;
				}
		}
};

class bentuk2:public bentuk{
	public:
		int pattern(){
			int angka;
			for (int a=1; a<=lebar; a++){
				for(int b=1; b<=panjang;  b++){
					angka=(rand()%number2)+number1;
					cout<<setfill('0')<<setw(2)<<angka<<" ";
				}
				cout<<endl;
				}
		}
};


int main(){
	bentuk *pointer;
	int pilih;
	srand(time(NULL));
	do{
		cout<<endl<<"Pattern Rectangle"<<endl;
		cout<<"==================="<<endl;
		cout<<"1. String Pattern"<<endl;
		cout<<"2. Number Pattern"<<endl;
		cout<<"3. Exit"<<endl;
		do{
			cout<<"Choose:";
			cin>>pilih;
		}while(pilih<1||pilih>3);
		switch(pilih){
			case 1:{
				pointer=new bentuk1();
				int panjang,lebar,cek;
				string kata;
				do{
					cout<<"Input Rectangle Width [3..20] : ";
					cin>>lebar;
				}while(lebar<3||lebar>20);
				do{
					cout<<"Input rectangle Length [3..20] : ";
					cin>>panjang;
					cin.sync();
					cin.clear();
				}while(panjang<3||panjang>20);
				cek=lebar+panjang;
				do{
					cout<<"Input a String [min "<<cek<<"] : ";
					getline(cin,kata);
				}while(kata.length()<cek);
				pointer->SetPanjang(panjang);
				pointer->SetLebar(lebar);
				pointer->SetKata(kata);
				pointer->pattern();
				break;
			}
			case 2:{
				pointer=new bentuk2();
				int panjang,lebar,number1,number2;
				do{
					cout<<"Input Rectangle width [3..20] : ";
					cin>>lebar;
				}while(lebar<3||lebar>20);
				do{
					cout<<"Input rectangle Length [3..20] : ";
					cin>>panjang;
				}while(panjang<3||panjang>20);
				do{
					cout<<"Input First Number [min 2] : ";
					cin>>number1;
				}while(number1<2);
				cout<<"Input Second Number : ";
				cin>>number2;
				pointer->SetPanjang(panjang);
				pointer->SetLebar(lebar);
				pointer->SetNum1(number1);
				pointer->SetNum2(number2);
				cout<<endl<<endl<<"Rectangle Result :"<<endl;
				pointer->pattern();
				break;
			}
			case 3:{
				break;
			}
		}
	}while(pilih!=3);
}

