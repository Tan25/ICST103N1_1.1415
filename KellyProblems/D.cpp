//Program for Problem D: Kelly and His Planet

#include <iostream>
#include <fstream>
using namespace std;

int main(){
  fstream get("a.in");
  int tc,g,h,num;            //tc=number of test cases, 
                             //g=i whenever words[i]==word[0], so that we can i++(g++) without disturbing
                             // the process of iteration through the letters,
                             //num denotes the current number of Kelly's
                       
  string word, words,fin;   //word == the words that make Kelly multiply
                            //words == the gamut of letters where the program searches through to find 'the' word
   
  while(get>>tc){           //gets the number of words that duplicates Kelly 
    for(int j=0;j<tc;j++){                           // loop for getting the word, and the words ,reinitiates num to 1
      get>>word>>words;                              
      num=1;
      
      for(int i=0;i<words.length();i++){               //loop for iterating through letters of the string words
                                              
         
          if(words[i]==word[0]){                       //checks whether current letter == word[0]
             g=i;                                         //if so, will give the value of i to g in order to get the next letters w/o disturbing the process of the iteration of i
             h=0;
             fin="";
             while(h<word.length()){                      //loops until h which is initially 0 becomes equal to word.length() at which time the loop will terminate
             fin+=words[g];                            
             g++;
             h++;
            
             }
             if(fin==word){                           //checks whether the string in fin previosuly created == word, * num by 2 if yes
              num*=2;
            
            }
         }
      }
     
      cout<<num<<endl;
   }
   }
  return 0;
}