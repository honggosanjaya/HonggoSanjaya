#include<iostream>
#include<cstdlib>
#include<string>
#include<conio.h>
using namespace std;

class otoboat{
	protected:
		int distance;
		int fuel;
		int condition;
		int capacity;
	public:
		otoboat(){
			distance=0;
			fuel=0;
		}
		void set_distance(int distance){
			this->distance=distance;
		}
		void set_fuel(int fuel){
			this->fuel=fuel;
		}
		void set_condition(int condition){
			this->condition=condition;
		}
		int get_distance(){
			return distance;
		}
		int get_fuel(){
			return fuel;
		}
		int get_condition(){
			return condition;
		}
		void repair(){
			if(condition==100){
				cout<<"Your Boat's Condition just Perfect"<<endl;
			}
			else{
				condition=100;
				cout<<"Success Service Your Boat"<<endl;
			}
		}
};

class motorboat: public otoboat{
	public:
		motorboat(){
			condition=100;
		}
		void sail_motorboat(){
			if(fuel<45){
				cout<<"Your Boat's Fuel not Enough"<<endl;
			}
			else if(condition==0){
				cout<<"Your Boat's Condition is Bad, Repair it first"<<endl;
			}
			else{
				fuel=fuel-45;
				condition=condition-25;
				distance=(rand()%8)+8;
				cout<<"Success Sail with Your Boat"<<endl;
			}
		}
		void fill_fuel(){
			int isi;
			do{
				cout<<"Fill your Fuel [min 1 liters]: ";
				cin>>isi;
			}while(isi<1);
			if(fuel==100){
				cout<<"Your Boat's Fuel is Full"<<endl;
			}
			else if(fuel+isi>100){
				cout<<"Your Boat's Fuel filled ("<<100-fuel<<") liters"<<endl;
				fuel=100;
			}
			else{
				fuel=fuel+isi;
				cout<<"Your Boat's Fuel nows ["<<fuel<<"] liters"<<endl;	
			}
		}
};

class jetboat: public otoboat{
	public:
		jetboat(){
			condition=100;
		}
		void sail_jetboat(){
			if(fuel<60){
				cout<<"Your Boat's Fuel not Enough"<<endl;
			}
			else if(condition==0){
				cout<<"Your Boat's Condition is Bad, Repair it first"<<endl;
			}
			else{
				string turbo;
				cout<<"Use Turbo [y/n]?";
				cin>>turbo;
				if(turbo=="y"){
					fuel=0;
					condition=0;
					distance=(rand()%31)+30;
					cout<<"Success Sail with Your Boat"<<endl;
				}
				else if(turbo=="n"){
					fuel=fuel-60;
					condition=condition-18;
					distance=(rand()%11)+10;
					cout<<"Success Sail with Your Boat"<<endl;
				}
			}	
		}
		void FillFuel(){
			int isi;
			do{
				cout<<"Fill your Fuel [min 1 liters]: ";
				cin>>isi;
			}while(isi<1);
			if(fuel==250){
				cout<<"Your Boat's Fuel is Full"<<endl;
			}
			else if(fuel+isi>250){
				cout<<"Your Boat's Fuel filled ("<<250-fuel<<") liters"<<endl;
				fuel=250;
			}
			else{
				fuel=fuel+isi;
				cout<<"Your Boat's Fuel nows ["<<fuel<<"] liters"<<endl;	
			}
		}
};

int main(){
	int pilih, pilih_menu;
	motorboat biasa;
	jetboat mantap;
	cout<<"1. Pick Motorboat"<<endl;
	cout<<"2. Pick Jetboat"<<endl<<endl;
	do{
		cout<<"Choose New Boat: ";
		cin>>pilih;
	}while(pilih<1||pilih>2);
	switch(pilih){
		case 1:{
			do{
				cout<<endl<<endl<<"Boat Status"<<endl;
				cout<<"Machine Name: SCHIONNING Prowler VT950"<<endl;
				cout<<"Distance:"<<biasa.get_distance()<<endl;
				cout<<"Fuel:"<<biasa.get_fuel()<<endl;
				cout<<"Condition:"<<biasa.get_condition()<<endl<<endl<<endl;
				cout<<"------------------------"<<endl;
				cout<<" \tMain Menu "<<endl;
				cout<<"------------------------"<<endl;
				cout<<" 1. Sail with Your Boat"<<endl;
				cout<<" 2. Repair Your Boat"<<endl;
				cout<<" 3. Fill Your Boat's Fuel"<<endl;
				cout<<" 4. Exit"<<endl;
				do{
					cout<<"Choose: ";
					cin>>pilih_menu;
				}while(pilih_menu<1||pilih_menu>4);
				switch(pilih_menu){
					case 1:{
						biasa.sail_motorboat();
						getch();
						break;
					}
					case 2:{
						biasa.repair();
						getch();
						break;
					}
					case 3:{
						biasa.fill_fuel();
						getch();
						break;
					}
					case 4:{
						break;
					}	
				}
			}while(pilih_menu!=4);
			break;
		}
		case 2:{
			
			do{
				cout<<endl<<endl<<"Boat Status"<<endl;
				cout<<"Machine Name: Williams 385 Turbojet"<<endl;
				cout<<"Distance:"<<mantap.get_distance()<<endl;
				cout<<"Fuel:"<<mantap.get_fuel()<<endl;
				cout<<"Condition:"<<mantap.get_condition()<<endl<<endl;
				cout<<"------------------------"<<endl;
				cout<<" \tMain Menu "<<endl;
				cout<<"------------------------"<<endl;
				cout<<" 1. Sail with Your Boat"<<endl;
				cout<<" 2. Repair Your Boat"<<endl;
				cout<<" 3. Fill Your Boat's Fuel"<<endl;
				cout<<" 4. Exit"<<endl;
				do{
					cout<<"Choose: ";
					cin>>pilih_menu;
				}while(pilih_menu<1||pilih_menu>4);
				switch(pilih_menu){
						case 1:{
							mantap.sail_jetboat();
							getch();
							break;
						}
						case 2:{
							mantap.repair();
							getch();
							break;
						}
						case 3:{
							mantap.FillFuel();
							getch();
							break;
						}
						case 4:{
							break;
						}
				}
			}while(pilih_menu!=4);
			break;
		}
	}
}
