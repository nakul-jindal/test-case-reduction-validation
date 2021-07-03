#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 


  
int main(){
    srand(time(NULL)); 
    int n;
    cin>>n;

    //generate random pair of integers 
    for (int i=0;i<n;i++){
        cout<<rand()-rand()<<" "<<rand()-rand()<<endl; 
        //rand()-rand() to get negative integers as well  
    }
}
