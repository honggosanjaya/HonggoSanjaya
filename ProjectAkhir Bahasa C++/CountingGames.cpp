#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>   
#include <cctype>


int counter=0;
using namespace std;
void clrscr(){
	system("@cls||clear");fflush(stdin);
}
class hitung{
	friend void set_nama(hitung&f, string name)
	{
		f.nama=name;
	}
	protected:
		int score;
		string nama;
		int correct_score;
		int wrong_score;
		
	public:
		hitung(){
			score=0;
			correct_score=0;
			wrong_score=0;
			nama=" ";
		}
		~hitung(){
			cout<<"Thank You For Using This Program ";
		}
		void set_score(int score){
			this->score=score;
		}	
		int get_score(){
			return score;
		}
		string get_nama()
		{
			return nama;
		}
		int get_wrong()
		{
			return wrong_score;
		}
		int get_correct()
		{
			return correct_score;
		}
		int get_counter()
		{
			return counter;
		}
};
const char newline='\n';
const char tab='\t';
class stage1 : public hitung{
	protected:
		int stage1_score;
		int b,c;
		int hasil_compare,hasil_user;
		const int MAX_TIME_LIMIT=12000;
	public:
		stage1(){
			stage1_score=0;
			b=0,c=0;
		}
		~stage1(){
			cout<<"destructor stage";
		}
		inline void acak_dan_hitung(int a)
		{
			long start_time=clock();
			int d,e,f,g;
			srand(time(NULL));
			b=(rand()%6+2);//random angka
			c=(rand()%4+6);//random angka
			d=(rand()%2);
			int& reference=d;
			e=(rand()%2);
			f=(rand()%2);
			g=(rand()%2);
			if(reference==1)
			{	
				if(e==1)
				{	
					if(f==1)
					{										
						cout<<"Soal + \n";
						cout<< a<<" + "<<b<< " = ";
						cin>>hasil_user;
						hasil_compare=a+b;
					}
					else
					{
						cout<<" Soal + -\n";
						cout<< a<<" + "<<b<<" - "<<c<<" = ";
						cin>>hasil_user;
						hasil_compare=a+b-c;
					}	
				}
				else
				{
					cout<<" Soal + + \n";
					cout<< a<<" + "<<b<<" + "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=a+b+c;
				}
			}
			else
			{
				if(e==1)
				{
					f=(rand()%2);
					if(f==1)
					{
						cout<<" Soal -\n";
						cout<< a<<" - "<<b<< " = ";
						cin>>hasil_user;
						hasil_compare=a-b;
					}
					else
					{			
						cout<<" Soal - + \n";
						cout<< a<<" - "<<b<<" + "<<c<<" = ";
						cin>>hasil_user;
						hasil_compare=a-b+c;
					}
				}
				else
				{
					cout<<" Soal - -\n ";
					cout<< a<<" - "<<b<<" - "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=a-b-c;
				}
			}
			long end_time=clock();
			if( end_time - start_time > MAX_TIME_LIMIT)
  			{ 
      			cout << "Time limit exceeded\n"; 
  			}
			else
			{
				if(hasil_user==hasil_compare)
				{
					clrscr();
					cout<<" Your Answer is Correct";
					stage1_score=10;
					score=score+stage1_score;
					correct_score++;
				}
				else
				{
					clrscr();
					cout<<" Your Answer is Wrong !!!";
					wrong_score++;
					// reset scrore dan save score
				}
				counter++;	
			}	
		}
		inline void acak_dan_hitung(int a,int b,int c)
		{
			long start_time=clock();
			int random1,random2,random3;
			srand(time(NULL));
			random1=(rand()%2);
			random2=(rand()%2);
			random3=(rand()%2);
			if(random1==1)
			{
				if(random2==1)
				{
					cout<<"Soal Perkalian\n";
					cout<< a<<" * "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=a*b;
				}
				else
				{
					cout<<"Soal Pembagian [ Rata-Rata Bawah] : ";
					cout<<"Soal Pembagian\n";
					cout<< a<<" / "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=a/b;
				}
			}
			else
			{
				if(random2==1)
				{
					cout<<"Soal Modulus \n";
					cout<< a<<" % "<< b<<" = ";
					cin>>hasil_user;
					hasil_compare=(a%b);
				}
				else
				{
					cout<<"Soal Bonus ";
					cout<< a<<" + "<< b<<" * "<<c<<" = ";
					cin>>hasil_user;
					hasil_compare=(a+(b*c));
				}
			}
			long end_time=clock();
			if( end_time - start_time > MAX_TIME_LIMIT)
  			{ 
      			cout << "Time limit exceeded\n"; 
  			}
  			else
			{
				if(hasil_user==hasil_compare)
				{
					clrscr();
					cout<<" Your Answer is Correct";
					stage1_score=20;
					score=score+stage1_score;
					correct_score++;
				}
				else
				{
					clrscr();
					cout<<" Your Answer is Wrong !!!";
					wrong_score++;
				}
				counter++;
			}
		}
		int get_stage1_score()
		{
			return stage1_score;
		}
};
class login{
	protected:
		string login_id;
		string login_pw;
	public :
		login(){
			login_id=" ";
			login_pw=" ";
		}
		void SetData(string user,string pass){
			this->login_id=user;
			this->login_pw=pass;
		}
		string get_user(){
			return login_id;
		}
		string get_pass(){
			return login_pw;
		}
		virtual void cek(){}
};

class CekLogin: public login{
	public:
		void cek(){
			if(login_id=="siap"&&login_pw=="siap"){
				cout<<"Berhasil Login";
				getch();
			}
			else{
				cout<<"Gagal, coba lagi"<<newline<<newline;
			}
		}
};
template <class T> 
class A{
	public:
		T data;
};

int main()
{
	stage1 angka;
	login *pointer;
	pointer=new CekLogin();
	CekLogin cek_login;
	pointer= &cek_login;
	string user,pass,name;
	do{
		cout<<"Login Dulu ya.."<<newline;
		cout<<"ID dan Password = siap"<<newline<<newline<<newline;
		cout<<"Masukkan ID : "; 
		cin>>user;
    	cout<<"Masukkan Pass : "; 
		cin>>pass;
		pointer->SetData(user,pass);
		pointer->cek();
	}while(pointer->get_user()!="siap" || pointer->get_pass()!="siap");
	int pilihan,pilihan1,age;
	do{
		clrscr();
		cout<<endl<<" Welcome To My Calculate Program "<<newline;
		cout<<"1. Mulai Perhitungan "<<newline;
		cout<<"2. Peraturan "<<newline;
		cout<<"3. Simpan Score"<<newline;
		cout<<"4. Show Score"<<newline;
		cout<<"5. Exit"<<newline;
		do{
			cout<<">> Input Your Choice : ";
			cin>>pilihan;
		}while((pilihan<1)||(pilihan>5));
		switch(pilihan)
		{
			case 1 : 
			{
				clrscr();
				do{
					cout<<"Please Insert Name[3-30] : ";
					getline(cin,name);
				}while((name.length()<3)||(name.length()>30));
				set_nama(angka,name);
				A<string>pertama;
				pertama.data=name;
				A<int>kedua;
   				cout<<"Please Input Your Age: ";
   				cin>>age;
   				kedua.data=age;
				do{
					clrscr();
				//	cout<<angka.cetak_nama();
					cout<<"Hi, "<<left<<setw(30)<<setfill('.')<<pertama.data<<newline;
					cout<<"Your Age "<<kedua.data<<newline;
					cout<<"Welcome to Counting Games"<<newline;
					cout<<"Your Score is : "<<angka.get_score()<<endl;
					cout<<"You Already Answer "<<angka.get_correct()<<" Correct Answer and "<<angka.get_wrong()<<" Wrong Score"<<newline<<newline;
					cout<<"Pilih Soal : "<<newline;
					cout<<"1. Tambah-Tambahan"<<newline;
					cout<<"2. Perkalian"<<newline;
					cout<<"3. Back"<<newline;
					do{
						cout<<">>Choose : ";
						cin>>pilihan1;
				}while((pilihan1<1)||(pilihan1>3));
				switch(pilihan1)
				{
					case 1 : 
					{
						clrscr();
						int a=(rand()%5+3);//random angka
						angka.acak_dan_hitung(a);
						getch();
						break;
					}
					case 2 : 
					{
						clrscr();
						int a=(rand()%3+5);
						int b=(rand()%3+4);
						int c=(rand()%3);
						angka.acak_dan_hitung(a,b,c);
						getch();
						break;
						//soal perkalian
					}
				}
			//	angka.stage1_hitung();
			//	angka.scoring();
			//	cout<<"score anda sekarang:"<<angka.get_score();
			//	break;
				}while(pilihan1!=3);	
			}
			case 2:
			{
				//peraturan
				break;
			}
			case 3 : 
			{	// save score
				clrscr();
				std::ofstream outfile;
				outfile.open("score.txt",std::ios_base::app);
				if(counter==0)
				{
					cout<<"tidak ada data untuk disimpan";
				}
				else 
				{
					outfile<<angka.get_nama()<<tab<<tab;
					outfile<<angka.get_score();
					outfile<<"\n";
					cout<<"Data anda telah disimpan";
				}
				getch();
				break;
				//save score
			}
			case 4 :
			{
				clrscr();
				std::ifstream infile("score.txt");
				if(infile.is_open())
				{
					cout<<" +----------+---------+"<<endl;
					cout<<" |  Name    |  Score  | "<<endl;
					cout<<" +----------+---------+"<<endl;
					std::string line;
					while(getline(infile,line))
					{
						cout<<" | "<<line.c_str()<<"    | ";
						cout<<"\n";
					}
					cout<<" +----------+---------+"<<endl;
					infile.close();
				}
				getch();
				break;	//display score
			}	
		}
	}while(pilihan!=5);
	cout<<"THANK YOU";
}

