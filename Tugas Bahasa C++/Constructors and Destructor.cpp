#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}

class guru{
	private:
		int happiness;
		int energy;
		string name;
		string gender;
		
	public:
		guru(int x1, int y1){
			happiness=x1;
			energy=y1;
		}
		guru(const guru &p2){
			happiness =p2.happiness;
			energy =p2.energy;
		}
		~guru(){
			cout<<"\nsampai jumpa...";
		}
		int Cekhappiness(){
			return happiness;
		}
		int Cekenergy(){
			return energy;
		}
		string Ceknama(){
			return name;
		}
		string Cekgender(){
			return gender;
		}
		void male(string &nama){
			this->name=nama;
		}
		void female(string &nama){
			this->name=nama;
		}
		void eat(int tambah, int kurang){
			if(energy==0)
			{
				cout<<"You don't have enough energy... You need to rest for a while..."<<endl;
				getch();
			}
			else
			{
				if(happiness==100)
				{
					energy=energy-kurang;
					cout<<"Eating something delicious..."<<endl;
					cout<<"energy decrease 10 points";
					getch();
				}
				else
				{
					happiness=happiness+tambah;
					energy=energy-kurang;
					cout<<"Eating something delicious..."<<endl;
					cout<<"Happiness increase 20 points energy decrease 10 points";
					getch();
					if(happiness>100)
					{
						happiness=100;
					}
				}
			}
		}
	
		void teaching(){
			if(energy==0)
			{
				cout<<"You don't have enough energy... You need to rest for a while..."<<endl;
				getch();
			}
			else if(happiness==0)
			{
				cout<<"You don't have enough happiness... You need to eat something delicious..."<<endl;
				getch();
			}
			else
			{
				happiness=happiness-10;
				energy=energy-10;
				cout<<"Teaching..."<<endl;
				cout<<"Happiness decrease 10 points energy decrease 10 points";
				getch();
			}
		}
		
		void eat(int tambah){
			if(energy==100)
			{
				cout<<"You don't need to rest again";
				getch();
			}
			else
			{
				energy=energy+tambah;
				cout<<"Resting..."<<endl;
				cout<<"Energy increase 20 points";
				getch();
				if(energy>100)
				{
					energy=100;
				}
			}
		}
};

int main(){
	guru belajar(100,100);
	guru p2 = belajar;

	int pilih,ulang_menu=1;
	do{
		CLEAR_SCREEN();
		cout<<"MINI CONSOLE LECTURE"<<endl;
		cout<<"======================"<<endl;
		cout<<"1. Male"<<endl;
		cout<<"2. Female"<<endl;
		cout<<"3. Exit"<<endl;
		do{
			cout<<"Choose:";
			cin>>pilih;
		}while(pilih<1||pilih>3);
		if(pilih==3)
		{
			return 0;
		}
		else 
		{
			int pil;
			string nama;
			do{
				cout<<"Please type the lecture's name [3-20 character]: "<<endl;
				cin>>nama;
			}while(nama.length()<3||nama.length()>20);
			if(pilih==1)
			{
				belajar.male(nama);	
			}
			else if(pilih==2)
			{
				belajar.female(nama);
			}
			
			do{
				CLEAR_SCREEN();
				cout<<"welcome "<<belajar.Ceknama()<<endl;
				if(pilih==1)
				{
					cout<<belajar.Ceknama()<<" is a boy"<<endl;
				}
				else
				{
					cout<<belajar.Ceknama()<<" is a girl"<<endl;
				}
					if(pil==4)
					{
						cout<<"energy:"<<p2.Cekenergy()<<endl;
						cout<<"happiness:"<<p2.Cekhappiness()<<endl<<endl;
					}
					else
					{
						cout<<"energy:"<<belajar.Cekenergy()<<endl;
						cout<<"happiness:"<<belajar.Cekhappiness()<<endl<<endl;
					}

				cout<<"1. Eating"<<endl;
				cout<<"2. Teaching"<<endl;
				cout<<"3. Rest"<<endl;
				cout<<"4. Return to main menu"<<endl;
				do{
					cout<<"choose:"<<endl;
					cin>>pil;
				}while(pil<1||pil>4);
				switch(pil){
					case 1:{
						CLEAR_SCREEN();
						belajar.eat(20,10);
						break;
					}
					case 2:{
						CLEAR_SCREEN();
						belajar.teaching();
						break;
					}
					case 3:{
						CLEAR_SCREEN();
						belajar.eat(20);
						break;
					}
					case 4:{	
						break;
					}
				}
			}while(pil!=4);
		}
	}while(ulang_menu=1);
}


