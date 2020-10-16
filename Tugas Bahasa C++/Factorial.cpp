#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}

class faktorial{
	friend void SetAngka(faktorial&f,int number)
	{
		f.angka=number;
	}
	private:
		int angka;
	public:
		faktorial()
		{
			angka=0;
		}
		~faktorial()
		{
			cout<<endl<<"Thank you and have a nice day";
		}
		int GetAngka()
		{
			return angka;
		}
		inline int factor(int n)
		{
			int i;
			for(i=n;i>= 1;i--)
			{
				if(i==1)
					cout<<i;
				else
					cout<<i<<" x ";
						
				if(n==1)
					return(1);
				else
					return(n*factor(n-1));
			}
		}
		
		int faktor(int n)
		{
			if(n==1)
				return(1);
			else
				return(n*faktor(n-1));
		}
};

const char newline='\n';
int main()
{
	faktorial bilangan;
	int pilih;
	do{
		CLEAR_SCREEN();
		cout<<"Faktorial Number Calculation"<<newline;
		cout<<"============================"<<newline<<newline;
		cout<<"1. Factorial"<<newline;
		cout<<"2. Factorial with step"<<newline;
		cout<<"3. Exit"<<newline<<newline;
		cout<<"Choose:";
		cin>>pilih;
			switch(pilih){
				case 1:{
					CLEAR_SCREEN();
					int number;
					int hasil;
					do{
						cout<<"Input the number [1-20]: ";
						cin>>number;
					}while(number>20||number<1);
					SetAngka(bilangan,number);
					cout<<newline<<"The Result of Factorial"<<newline<<endl;				
					hasil=bilangan.faktor(number);
					cout<<newline<<number<<"! = "<<hasil;
					getch();
					break;
				}
				case 2:{
					CLEAR_SCREEN();
					int number;
					do{
						cout<<"Input the number [1-20]: ";
						cin>>number;
					}while(number>20||number<1);
					SetAngka(bilangan,number);
					cout<<newline<<"The Result of Factorial"<<newline<<newline;
					cout<<number<<"! = ";
					cout<<newline<<number<<"! = "<<bilangan.factor(number);
					getch();
					break;
				}
				case 3:{
					break;
				}
			}	
	}while(pilih!=3);	
}
