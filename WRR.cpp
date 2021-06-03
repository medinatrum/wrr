#include <iostream>
using namespace std;

int main(){
  int i,j,k=0,p=0,q,s=0,idle=0,done=0;                                                   
  float sum=0;
  p=2; //broj klasa
  int a[p][4];
  int b[p][5];

q=100;  //quantum-tezinski koeficijent
int total=0;
  cout<<"\n\nClass\tArrival\tLength\n-------\t-------\t-----\n"; 
  for(i=0;i<p;i++){
    for(j=0;j<3;j++){
      cin>>a[i][j];

    }
    a[i][3]=a[i][2]; 
total+=a[i][3];
  }
  //std::cout<<"Total length="<<total<<std::endl;

  std::cout<<"Pretpostaviti ćemo različite dužine ulaznih tokova: "<<std::endl;
/////KLASA 1
  int pct1=a[0][3]*0.5; 
  int pct2=a[0][3]*0.3;
  int pct3=a[0][3]*0.2;
  ////KLASA 2
  int pct4=a[1][3]*0.4;
  int pct5=a[1][3]*0.25;
  int pct6=a[1][3]*0.2;
  int pct7=a[1][3]*0.1;
  int pct8=a[1][3]*0.05;

  std::cout<<"Packets[class1] : \n"<<pct1<<" "<<pct2<<" "<<pct3<<std::endl;
  std::cout<<"Packets[class 2] : \n"<<pct4<<" "<<pct5<<" "<<pct6<<" "<<pct7<<" "<<pct8<<std::endl;

  cout<<"\n\nRR for classes \n\n";

  i=a[0][1];//arr time for first class

  while(done!=p){
    if(k==p)
      k=0;

    if(a[k][1]<=i){

      if(a[k][2]!=0){

        if(a[k][2]>=q){
          printf("%5d-----------\n        |class-%-4d|\n",i,a[k][0]);
          a[k][2]-=q;
          i+=q;
        }
        else{    
          printf("%5d-----------\n        |class-%-4d|\n",i,a[k][0]);
          i+=a[k][2];
          a[k][2]=0;
        }
        if(a[k][2]==0){  
          b[s][0]=a[k][0];   
          b[s][1]=a[k][1];   
          b[s][2]=i;         
          b[s][3]=a[k][3];  
          b[s][4]=((i-a[k][1])-a[k][3]);      
          sum+=((i-a[k][1])-a[k][3]);
          s++;
          done++; 
        }
        idle=0;
      }
      k++;             
    }
     else{
      if(idle==0){
        idle=1;
        k=0;
      }
      else if(idle==1){
        printf("%5d-----------\n        |Idle  |\n",i); 
        idle=2;
        i++;     
      }   
      else
        i++;           
   }
  }

  printf("%5d-----------\n",i); 

  cout<<endl;

  cout<<"\n\nClass\tArrival\tFinish\tTotal\tWait\n------------------------------------\n";

  for(i=0;i<s;i++)
    cout<<b[i][0]<<"\t"<<b[i][1]<<"\t"<<b[i][2]-1<<"\t"<<b[i][3]<<"\t"<<b[i][4]<<"\n";

  cout<<"\n\nAvg. Wait time = "<<sum/p<<endl<<endl;


  std::cout << "Za primjer ćemo pretpostaviti da prva 3 ulazna toka pripadaju Klasi 1, a ostalih 5 klasi 2.\n" 
  <<"Izlazni bandwidth omjeru u 40%, a klasi 2 u omjeru 60%  " << std::endl;

/* int B=500000000; */
/* int B1=B*40/100; */
/* int B2=B*60/100; */

double p1=40;
double p2=60;
std::cout<<"Procenat izlaznog bandwitha koji zauzimaju pojedinačni tokovi: "<<std::endl;
std::cout<<p1*pct1/a[0][3] <<"%"<<std::endl;
std::cout<<p1*pct2/a[0][3] <<"%"<<std::endl;
std::cout<<p1*pct3/a[0][3] <<"%"<<std::endl;
std::cout<<p2*pct4/a[1][3] <<"%"<<std::endl;
std::cout<<p2*pct5/a[1][3] <<"%"<<std::endl;
std::cout<<p2*pct6/a[1][3] <<"%"<<std::endl;
std::cout<<p2*pct7/a[1][3] <<"%"<<std::endl;
std::cout<<p2*pct8/a[1][3] <<"%"<<std::endl;


     return 0;
} 
