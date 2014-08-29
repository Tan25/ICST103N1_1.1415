#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;
int main(){
        string n1,n2,k,k2;
    
        char carF;
	int tc,m1,m2,i,j,carry=0,sum;
  cin>>tc;
   for(int h=0;h<tc;h++){
        carF='0';
        string pl;
        cin >> n1>>n2;
     if(n1.length()==1 && n2.length()==1){
           m1=atoi(n1.c_str());
           m2=atoi(n2.c_str());
           cout<<m1+m2<<endl;
     }else{
        i=n1.length()-1;
        j=n2.length()-1;
       
        while((i>=0) || (j>=0)){
           if(i>=0){
            k=n1[i];
            m1=atoi(k.c_str());
            i--;
           }else
              m1=0;

           if(j>=0){
             k=n2[j];
             m2=atoi(k.c_str()); 
             j--;
           } else
              m2=0;

           if(carF=='0')
              carry=0;
           
           sum=m1+m2+carry;
           ostringstream convert;
           convert<<sum;
           k=convert.str();
           
           
           if(k.length()>1){
             k2=k[1];
             
             pl+=k2;
             k2=k[0];
             carry=atoi(k2.c_str());
             carF='1';
             
           }else {
                carF='0';
                pl+=k;
           }
             
        }
        for(int p=pl.length()-1;p>=0;p--){
          cout<<pl[p];
        }
        cout <<endl;    
      }
     }  

}