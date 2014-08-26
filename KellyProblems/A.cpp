/*How: 
  (Mloop) for every n (2ndloop)get line n times, then place it inside vector,(endloop) then go through vector(3rdloop)
   if current letter is = to E or T
   check if added to following 8 letters that are:
   on its right, below it, diagonally below it, or diagonally above it is
   if(E)==ELEPHANT, and TNAHPELE if (T)
   if yescount++;
   (endloop)
   if count == 0 then KElly is sad
   else for every characters the count can go through, 
   check if that nth count is even or not
   if even cout super else duper
   after going through, finally cout happy. then endl
*/
        
     



#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
	int n,e,v,l,t,count;
        string line,fin;
        
        fstream get("k.in");
        while(get>>n){
          count=0;                                           //balik sa 0 lagi pagnakakuha ulit ng number na input
          vector<string> lines;                              //remake the vector lines every after number input
          for(int i=0;i<n;i++){                              //loop for getting each line,& pushing back, continues until it loops n times
             get>>line;                                      // gets line, saves them to lines
             lines.push_back(line);  
          }
         
          for(int k=0;k<n;k++){                                     //row of letters
            for(int h=0;h<n;h++){                                   //col grid
                                                                       //[x,y] per letter 
 
              if(lines[k][h]=='E' || lines[k][h]=='T'){             //if letter is E or T, check if combined w/ nxt 7letters==Elephant if E or TNAHPELE if t
                 t=0;fin="";                                        //check letters going to the right ->
                 for(int l=h;l<n;l++){                              //[row] stays the same while [col++] to be able to jump to letters going to the right
                    if(t==8){break;}                                //initialization of l=h(row) so to not disturb the flow of the original [row,col] loop
                    fin+=lines[k][l];                               //fin receieves the new word or combined 8 letters
                    t++;
                 }
                 if(fin=="ELEPHANT"){                               
                    if(lines[k][h]=='E')
                    count++;          
                 }  
                 if(fin=="TNAHPELE"){
                    if(lines[k][h]=='T')
                    count++;          
                 }     
        
                 t=0;fin="";
                 for(int l=k;l<n;l++){                           //check the next 7 letters going down, simillar to first check(going to the right) but checks direction going down
                    if(t==8){break;}                             //row++ and col stays the same because we want to check the next letters going down
                    fin+=lines[l][h];
                    t++;
                 }
                 if(fin=="ELEPHANT"){
                    if(lines[k][h]=='E')
                    count++;          
                 }  
                 if(fin=="TNAHPELE"){
                    if(lines[k][h]=='T')
                    count++;          
                 }     
        

        	 t=0; e=k; v=h;fin="";                        // e=k and v=h because both will be increasing per loop
                 while(e<n && v<n && t<8){                   //checks diagonally going down; therefore row is directly proportional to col; 
                     fin+=lines[e][v];                    
                     t++; e++; v++;
                 }
                 if(fin=="ELEPHANT"){
                    if(lines[k][h]=='E')
                    count++;          
                 }  
                 if(fin=="TNAHPELE"){
                    if(lines[k][h]=='T')
                    count++;          
                 }     
        
                 
                 t=0; e=k; v=h;fin="";                   //simillar with the above
                 while(e>=0 && v<n && t<8){              //checks diagonal going up; we start from the bottom, that's why e--; inverse proportion
                    fin+=lines[e][v];
                    e--; v++; t++;
                }
                if(fin=="ELEPHANT"){
                    if(lines[k][h]=='E')
                    count++;          
                 }  
                 if(fin=="TNAHPELE"){
                    if(lines[k][h]=='T')
                    count++;          
                 }    
               }
              }
          }
          cout<<"Kelly is";                                         //THE PART WHERE WE PRINT SOMETHING OUT: 
                                                                    //ALWAYS START WITH Kelly is
          if(count==0)                                               //if there are no 'elephant' found, instant 'sad'
             cout<<" sad."<<endl;
          else{
             for(int i=0;i<count;i++){                         //loop that prints alternately between super and duper based on count
                if(i%2==0)
                    cout<<" super";
                else
                    cout<<" duper";
             }
             cout<<" happy."<<endl;                                
           
          }
        }
        return 0;
}