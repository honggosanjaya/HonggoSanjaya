#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;
void CLEAR_SCREEN(){
	if (system("CLS")) system("clear");
}
class konversi{
	private:
		int num;
		float angka;
	public:
			konversi()
			{
				num=0;
				angka=0;
			}
			void SetAngka(int n)
			{
				this->num=n;
			}
			int GetNum()
			{
				return num;
			}
			float GetAngka()
			{
				return angka;
			}
			void desimal()
			{
				cout<<"Number in decimal : "<<dec<<showpos<<num<<endl;
			}
			void hexadesimal()
			{
				cout<<"Number in hexadecimal : "<<hex<<num<<endl;
			}
			void oktal()
			{
				cout<<"Number in octal : "<<oct<<num<<endl;
			}
			void scientific()
			{
				angka=num;
				cout<<"Number in scientific:"<<std::scientific<<noshowpos<<angka<<endl;
			}
			void pecahan()
			{
				angka=num;
				cout<<"Number in float:"<<setprecision(2)<<std::fixed<<noshowpos<<angka<<endl<<endl<<endl;
			}	
};

int main()
{
	konversi bilangan;
	string nama;
	int num;
	char ulang;
	string user_input;
	do{
		cout<<"Input your name [3-20 characters]: "<<endl;
		cin>>nama;	
	}while(nama.length()>20||nama.length()<3);
	CLEAR_SCREEN();
	cout<<"Hello, "<<left<<setw(20)<<setfill('x')<<nama<<endl<<endl;
	cout<<"Today's lesson is about converting a number"<<endl;
	cout<<"-------------------------------------------"<<endl<<endl;
	do{
		do{
			cout<<"Input a number [1-100]:";
			getline(cin, user_input);
			num = atoi(user_input.c_str());
			cin.sync();
			cin.clear();
		}while(num>100||num<1);
		bilangan.SetAngka(num);
		bilangan.desimal();
		bilangan.hexadesimal();
		bilangan.oktal();
		bilangan.scientific();
		bilangan.pecahan();
		do{
			cout<<"Do you want to replay? [y/n]: ";
			cin>>ulang;
			if(ulang=='n')
			{
				return 0;
			}
		}while(ulang!='y'&&ulang!='n');
	}while(ulang=='y');	
}
