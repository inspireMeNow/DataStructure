# ifndef __COMPLEX_H__
# define __COMPLEX_H__
# include <iostream>
using namespace std;
class Data{
   int fee=1;
   char status;
   int number;
   int time;
   int location;
   public:
   void Arrive(){
       cout<<"the car location is:"<<number<<endl;
   }
   void Leave(){
       cout<<"the time is"<<time<<",you should pay"<<fee*time<<endl;
   }
   char getStatus(){
       return status;
   }
   int getNumber(){
       return number;
   }
   int getTime(){
       return time;
   }
   Data(char status,int number,int time){
       this->status=status;
       this->number=number;
       this->time=time;
   }
   Data(){}
   friend ostream&operator<<(ostream &out,Data &c){
       out<<c.getStatus()<<c.getNumber()<<c.getTime()<<endl;
       return out;
   }
};
#endif