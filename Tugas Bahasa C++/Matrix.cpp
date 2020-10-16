#include<iostream>

using namespace std;
class matrix{
	private:
		int num1;
		int num2;
		int num3;
		int num4;
	public:
		matrix(){
			num1=0;
			num2=0;
			num3=0;
			num4=0;
		}
		~matrix(){
			cout<<"Open Our Vision and Encourage Ourself"<<endl;
		}
		void setData(int a,int b,int c,int d){
			this->num1=a;
			this->num2=b;
			this->num3=c;
			this->num4=d;
		}
		
		matrix operator*(const matrix& c) const{
			matrix result;
			result.num1=((num1*c.num1)+(num2*c.num3));
			result.num2=((num1*c.num2)+(num2*c.num4));
			result.num3=((num3*c.num1)+(num4*c.num3));
			result.num4=((num3*c.num2)+(num4*c.num4));
			return result;
		}
		
		int getNum1(){
			return num1;
		}
		int getNum2(){
			return num2;
		}
		int getNum3(){
			return num3;
		}
		int getNum4(){
			return num4;
		}
};


int main(){
	matrix A,B,C;
	int pilih,a,b,c,d;
	int value=0;
	if(value==0){
		cout<<"No Matrix Data ..."<<endl;
	}
	
	do{
		cout<<"BlueJack Calculation Matrix 2 Dimension"<<endl;
		cout<<"=========================================="<<endl;
		cout<<"1. Input Matrix"<<endl;
		cout<<"2. Calculate your Matrix"<<endl;
		cout<<"3. Exit"<<endl;
		do{
			cout<<"Choose:";
			cin>>pilih;
		}while(pilih<1||pilih>3);
		
		switch(pilih){
			case 1:{
				cout<<"Input Matrix 1"<<endl;
				cout<<"================="<<endl;
				do{
					cout<<"Input Number 1 [0..9]:";
					cin>>a;
				}while(a<0||a>9);
				do{
					cout<<"Input Number 2 [0..9]:";
					cin>>b;
				}while(b<0||b>9);
				do{
					cout<<"Input Number 3 [0..9]:";
					cin>>c;
				}while(c<0||c>9);
				do{
					cout<<"Input Number 4 [0..9]:";
					cin>>d;
				}while(d<0||d>9);
				A.setData(a,b,c,d);
				cout<<"| " <<A.getNum1()<<"\t"<<A.getNum2()<<" |"<<endl;
				cout<<"| " <<A.getNum3()<<"\t"<<A.getNum4()<<" |"<<endl;
				
				
				cout<<"Input Matrix 2"<<endl;
				cout<<"================="<<endl;
				do{
					cout<<"Input Number 1 [0..9]:";
					cin>>a;
				}while(a<0||a>9);
				do{
					cout<<"Input Number 2 [0..9]:";
					cin>>b;
				}while(b<0||b>9);
				do{
					cout<<"Input Number 3 [0..9]:";
					cin>>c;
				}while(c<0||c>9);
				do{
					cout<<"Input Number 4 [0..9]:";
					cin>>d;
				}while(d<0||d>9);
				B.setData(a,b,c,d);
				cout<<"| " <<B.getNum1()<<"\t"<<B.getNum2()<<" |"<<endl;
				cout<<"| " <<B.getNum3()<<"\t"<<B.getNum4()<<" |"<<endl<<endl<<endl;
				value++;
				
				cout<<"| " <<A.getNum1()<<"\t"<<A.getNum2()<<" |\t\t| " <<B.getNum1()<<"\t"<<B.getNum2()<<" |"<<endl;
				cout<<"| " <<A.getNum3()<<"\t"<<A.getNum4()<<" |\t\t| " <<B.getNum3()<<"\t"<<B.getNum4()<<" |"<<endl;
				break;
			}
			case 2:{
				cout<<"Calculating Matrix Result:"<<endl;
				matrix C=A*B;
				cout<<"| " <<A.getNum1()<<"\t"<<A.getNum2()<<" |\tx\t| " <<B.getNum1()<<"\t"<< B.getNum2()<<" |\t=\t|"<<C.getNum1()<<"\t"<<C.getNum2()<<" |"<<endl;
				cout<<"| " <<A.getNum3()<<"\t"<<A.getNum4()<<" |\t \t| " <<B.getNum3()<<"\t"<< B.getNum4()<<" |\t \t|"<<C.getNum3()<<"\t"<<C.getNum4()<<" |"<<endl;
				break;
			}
			case 3:{
				break;
			}
		}
	}while(pilih!=3);
}
