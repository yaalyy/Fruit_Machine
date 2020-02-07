#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;


float credit=1;    // set initial credits
string fruit[6]={"Cherry","Bell","Lemon","Orange","Star","Skull"};      //set results

int random(int n)
{
  int m=rand()%n;       //OK
  return m;                    //function for random numbers 
}
void roll()
{
  credit-=0.2;   //paid credits
  string results[3];
  int bell_num=0,skull_num=0,same_num=0;


  for(int i=0;i<3;i++)
  {
    int m=random(6);         //Get results
    results[i]=fruit[m];
    if(results[i]=="Bell")
    {
      bell_num++;             
    }                               // get the number of bells and skulls
    if(results[i]=="Skull")
    {
      skull_num++;
    }
  }

  cout<<"Results:";
  for(int i=0;i<3;i++)
    cout<<results[i]<<" ";
  cout<<endl;

  if(results[0]==results[1])
  {
    same_num++;
  }
  if(results[0]==results[2])
  {
    same_num++;
  }
  if(results[2]==results[1])
  {
    same_num++;
  }


  if(skull_num>=2)
  {
    if(skull_num==3)
    {
      credit=0;
    }
    else if(skull_num==2)
    {
      credit--;
    }
  }
  else if(bell_num==3)
  {
    credit+=5;
  }
  else if(same_num==3)
  {
    credit++;
  }
  else if(same_num==2)
  {
    credit=credit+0.5;
  }
}


int main()
{
  srand((unsigned)time(NULL));
  string q;
  //roll();
  if(credit<0)
    credit=0;
  
  do
  {
    
    printf("You have %.1f credits\n",credit);
    cout<<"Would you like to continue or quiz"<<endl;
    cin>>q;
    if(q=="quiz")
      break;
    roll();

  }while(credit>0.2);    //check if credits is sufficient
  printf("In the end,you have %.1f credits\n",credit);
}
