#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class indo{
	private:
		string nama;
		int konsonan;
		int vokal;
	public:
		indo(){
			nama=" ";
			konsonan=0;
			vokal=0;
		}
		void setNama(string nama){
			this->nama=nama;
		}
		void setVokal(int vokal){
			this->vokal=vokal;
		}
		void setKonsonan(int konsonan){
			this->konsonan=konsonan;
		}
		string getNama(){
			return nama;
		}
		int getVokal(){
			return vokal;
		}
		int getKonsonan(){
			return konsonan;
		}
		int hitungVokal(string nama){
			int totHuruf=0;
			cout<<"Vokal : ";
	   		for (int z=0;z<nama[z];z++) 
	    	{
	        	totHuruf++;
			}
	    	for (int g=0;g<totHuruf;g++)
	    	{
	        	if (nama[g]=='a'||nama[g]=='i'||nama[g]=='u'||nama[g]=='e'||nama[g]=='o'||nama[g]=='A'||nama[g]=='I'||nama[g]=='U'||nama[g]=='E'||nama[g]=='O')
	        	{
	            	vokal++;
	        	}
	    	}
			cout<<vokal<<endl;
		}
		int hitungKonsonan(string nama){
			int totHuruf=0;
			cout<<"Konsonan : ";
			for (int z=0;z<nama[z];z++) 
	    	{
	        	totHuruf++;
			}
	    	for (int g=0;g<totHuruf;g++)
	    	{
	      		if (nama[g]=='b'||nama[g]=='c'||nama[g]=='d'||nama[g]=='f'||nama[g]=='g'||nama[g]=='h'||nama[g]=='j'||nama[g]=='k'||nama[g]=='l'||nama[g]=='m'||nama[g]=='n'||nama[g]=='p'||
		  		nama[g]=='q'||nama[g]=='r'||nama[g]=='s'||nama[g]=='t'||nama[g]=='v'||nama[g]=='w'||nama[g]=='x'||nama[g]=='y'||nama[g]=='z'||nama[g]=='B'||nama[g]=='C'||nama[g]=='D'||
		  		nama[g]=='F'||nama[g]=='G'||nama[g]=='H'||nama[g]=='J'||nama[g]=='K'||nama[g]=='L'||nama[g]=='M'||nama[g]=='N'||nama[g]=='P'||nama[g]=='Q'||nama[g]=='R'||nama[g]=='S'||
		  		nama[g]=='T'||nama[g]=='V'||nama[g]=='W'||nama[g]=='X'||nama[g]=='Y'||nama[g]=='Z')
		  		{
	        		konsonan++;
		  		}
			}
			cout<<konsonan<<endl;
		}
};

int main(){
	indo jodoh1,jodoh2;
	int vokal1,vokal2,konsonan1,konsonan2;
	int relation,relation1,relation2,result;
	string nama1,nama2;
	cout<<"Please insert first name:";
	getline(cin,nama1);
	jodoh1.setNama(nama1);
	vokal1=jodoh1.hitungVokal(nama1);
	konsonan1=jodoh1.hitungKonsonan(nama1);

	cout<<"Please insert second name:";
	getline(cin,nama2);	
	jodoh2.setNama(nama2);
	vokal2=jodoh2.hitungVokal(nama2);
	konsonan2=jodoh2.hitungKonsonan(nama2);
	cout<<"Calculating...."<<endl;
   	cout<<"Please wait..."<<endl;
	relation1=((jodoh1.getVokal()*2)+jodoh1.getKonsonan());
   	relation2=((jodoh2.getVokal()*2)+jodoh2.getKonsonan());
   	relation=relation1+relation2;
   	result=relation%4;
   	cout<<"Your result is between "<<nama1 <<"and "<<nama2<<" is :"<<endl;
   	if(result==0){
   		cout<<"Congratulations, both of you is Best Friend Forever";
	}else if(result==1){
		cout<<"Congratulations, both of you is Best Friend";
	}else if(result==2){
		cout<<"Sorry, both of you is just a Friend";
	}else{
		cout<<"Sorry, both of you is Sometime friend sometime not";
	}
	return 0;
} 
