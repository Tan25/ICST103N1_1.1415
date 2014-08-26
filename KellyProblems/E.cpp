/* in K, there are n number of E's, in E, there are m number of L's, and in L there are h number of Y's 
    this means that we count all Y's tht can be made from the above
   */


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
	fstream get("K.in");
        string name;
        int num,ck,ce,cl,cy,sum,prod;              //num=number of test cases,ck=#of K's,ce=E,cl=L,cy=Y, sum=total of # made byck,ceand cl                 
        get>>num;
        for(int i=0;i<num;i++){
          get>>name;
          ck=0,ce=0,cl=0,cy=0;
 	  for(int j=0;j<name.length();j++){
	    if(name[j]=='K')
                 ck++;
            else if (name[j]=='E')
                 ce++;
            else if (name[j]=='L')
                { cl++;}
            else if (name[j]=='Y')
                 cy++;
	  }	
          
          if(ck==1 && ce==1&& cl==2 && cy==1)            //MAKES UP 1 whole KELLY 
          {     cout<<1;                     }
          else {
              if(cl==2){                                 //this is due to l being originally 2 in the word kelly :P:P:P:P:P
                 cl=1;                                   
                
              }else {                                   // else, because every time an l is added to the two current l's, 2(#ofL's added)+1 is made
                 cl=((cl-2)*2)+1;                       //===thus the number of l's containing Y's
              }
              //if(ck==1){ ck=1; }                        
              //if(ce==1){ ce=1; }  
             
              prod=ck*ce*cl;
              sum=0;
              for(int i=0;i<prod;i++){
                  sum=cy+sum;
              }
              cout<<sum%(10^9+7);                   //kaylangan kasi
              
          }
          cout<<endl;
	}        
 	return 0;       
}