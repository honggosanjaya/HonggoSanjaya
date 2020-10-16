#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}

class bbm{
	private:
		int gasoline;
	
	public:
		bbm(){
			gasoline=100;
		}
		int CekBbm(){
			return gasoline;
		}
		
		void start()
		{
			int speed;
			srand(time(NULL));
			speed=rand()%100+1;
			if(gasoline>0&&gasoline!=20)
			{
				cout<<"Speed: "<<speed<<endl;
				if(speed>=50)
				{
					cout<<"You have spend 40 liters gasoline\n";
					gasoline=gasoline-40;
					getch();
				}
				else
				{
					cout<<"You have spend 20 liters gasoline\n";
					gasoline=gasoline-20;
					getch();
				}
				cout<<"Press enter to return to main menu..\n";
				getch();
			}
			else if(gasoline==20)
			{
				if(speed>=50)
				{
					cout<<"Your gasoline is not enough to run the car..\n";
					cout<<"Press enter to return to main menu..\n";
					getch();
				}
				else
				{
					cout<<"You have spend 20 liters gasoline\n";
					gasoline=gasoline-20;
					getch();
				}
			}
			else if(gasoline==0)
			{
				cout<<"Your gasoline is not enough to run the car..\n";
				cout<<"Press enter to return to main menu..\n";
				getch();
			}
		}

		void rest()
		{
			if(gasoline==100)
			{
				cout<<"Your gasoline is full...\n";
				cout<<"Press enter to return to main menu..\n";
				getch();
			}
			else
			{
				cout<<"successfully recharge 20 liters gasoline\n";
				gasoline=gasoline+20;
				cout<<"Press enter to return to main menu..\n";
				getch();
			}
		}	
};

int main()
{
	bbm car;
	int pilih;
	do{
		CLEAR_SCREEN();
		cout<<"Your gasoline's cars:"<<car.CekBbm()<<endl;
		cout<<"====================\n\n";
		cout<<"1. Start driving\n";
		cout<<"2. Rest\n";
		cout<<"3.Exit\n";
		printf("Choice:");
		scanf("%d",&pilih);
		switch(pilih){
			case 1:CLEAR_SCREEN();car.start();break;
			case 2:CLEAR_SCREEN();car.rest();break;
			case 3:CLEAR_SCREEN();break;
		}
	}while(pilih!=3);
}
