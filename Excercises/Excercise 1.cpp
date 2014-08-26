#include <iostream>
using namespace std;

void maxLength(int  input, int &counter, int &max) {
     
     /*input=tc, counter=tmp(because of &, will later replace value of tmp), max= max (the same with counter but replaces the        value of max */
     
     if (input != 0) {
        counter = counter++;
     }else {
        counter = 0;
     }
     if (max < counter){
        max = counter;
     }
}

int main () {
    int n; // length of substring
    int tc;//inputs from file
    int max;// current maximum length
    int tmp;// current length
    cin >> n;
    tmp = max = 0;//assigning of value 
    
    for (int i=0; i<n; i++) { // loop that terminates once i reaches n - 1 
          cin >> tc; //gets input from file 
          maxLength ( tc, tmp, max ); // calling of function and placing of arguments po
    }
    cout << max;
}