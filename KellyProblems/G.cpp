#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;
int main(){
        string n1,n2,k,k2;  //n1 and n2 whole strings,k is for individual number characters,k2 is for 1) the number that remains behind when there is a carry
                                                                                            //and     2) for the carry
    
        char carF;                                                  //Answers the question: do we have a carry??
	int tc,m1,m2,i,j,carry,sum; //tc#oftimes two numbers will be added,m1 int version of n1and k1;m2 int of n2  and k2
  cin>>tc;
   for(int h=0;h<tc;h++){                    //you get two numbers tc times
        carF='0';                          //every loop ==redeclaration of string pl and the value of carF
        string pl; 
        cin >> n1>>n2;                    
     
                  
        i=n1.length()-1;             //we start i and j to the last indexes of n1 and n2 because we start adding from the rightmost
        j=n2.length()-1;
       
        while((i>=0) || (j>=0)){ //while there is still an index or digit available in eithertwo
           if(i>=0){            //does n1 still has a digit?YES: convert digit to int, i--
            k=n1[i];
            m1=atoi(k.c_str());
            i--;
           }else               //NO: this means that we no longer have a digit available, so we'll leave m1 0, in case that the other number still has some digits
              m1=0;

           if(j>=0){                    //simillar with the above
             k=n2[j];
             m2=atoi(k.c_str()); 
             j--;
           } else
              m2=0;

           if(carF=='0')      //Do we have a carry? 0 =no, 1 = yes
              carry=0;         //if no thencarry =0
           
           sum=m1+m2+carry;       
           ostringstream convert; //we have this in here because we need to check whether we have a carry or not
           convert<<sum;                //which we can determine by the number of the digits in sum
           k=convert.str();           //so we convert it to string to be able to count its digit(s)
           
           
           if(k.length()>1){          //if k has 2 digits, this means that we seperate the remaining digit from the carry
             k2=k[1];             //remaining digit
             
             pl+=k2;             //we place it inside string pl
             k2=k[0];
             carry=atoi(k2.c_str());  //carry =atoi of k[0]//leftmost digit
             carF='1';  //Yes, we have a carry for the next 
             if(i==-1 && j==-1){pl+=k2;}//for instances like 9+1, where we no longer have any digits left on either to add our carry to
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
