#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Random{
	public:
		virtual void random(char num){
		}
};

class RandomNumber:public Random
{
	int number;
	public:
		void random(char &num){
			srand((unsigned)time(NULL));
			number=rand()%11;
			num=(char)number+48;
		}
};

class RandomOperation:public Random
{
	char operation;
	public:
		void random(char &ope){
			srand((unsigned)time(NULL));
			int a=rand()%4;
			switch(a){
				case 0:operation='+';break;
				case 1:operation='-';break;
				case 2:operation='*';break;
				case 3:operation='/';
			}
			ope=operation;
		}
};

class SimpleRandomFactory
{
	public:
		static Random *creat_random(const string &choose)
		{
			if("number"==choose)
			{
				return new RandomNumber();
			}
			if("operation"==choose)
			{
				return new RandomOperation();
			}
		}
};

int main(){
	SimpleRandomFactory ovo;
	Random *n,*o;
	int num;char ope;
	n=ovo.creat_random("number");
	o=ovo.creat_random("operation");
	n->random(num);
	o->random(ope);
	cout<<num<<ope<<endl;
	return 0;
}
