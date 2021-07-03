#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std ;

//function to find the test case with greatest branch coverage
int max(int* arr, int n){
    int m = 0 , t;
    for (int i=0;i<n;i++)
        if (arr[i]>=m) {m=arr[i]; t=i;}
    if (m==0) return n;
    else return t;
}

//function to calculate adjusted branch coverage of each test case
void sum(int* arr , int** a , int n, int b){
    for (int i=0;i<n;i++){
        arr[i]=0;
        for (int j=0;j<b;j++)
            if (a[i][j]) arr[i]++;    
} 
}

int main (){
    int n,b,k;
    
    //get k value from user
    cout<<"enter value of k : "<<endl;
    cin>>k;
    
    //get n and number of branches in program
    ifstream in; 
    in.open("n.txt");
    in >> n;
    in.close();
    in.open("b.txt");
    in >>b;
    in.close();
    
    //initialise n*b matrix to store branch coverage of each test case
    int **a;
    a = new int *[n];
    
    for(int i = 0; i <n; i++)
        a[i] = new int[b]();
    
    //get keys of branches covered by each test case from files created in bashscript
    for (int i=0;i<n;i++){
        string fname = to_string(i+1);
        in.open(fname);
        int t; 
        while (!in.eof()){
            in >> t;
            a[i][t-1] = 1;
        }
        in.close();
    }
    
    //to store the number of un-touched branches covered by each test case 
    int *branches;
    branches= new int[n]();
    
    sum(branches, a , n , b);

    //dynamic array to store the top priority test cases
    vector<int> reduced;

    //k-iterations at max
    for (int i=0 ; i<k ; i++){
        int m = max(branches,n);
        if (m==n) break;        //break if all branches covered
        reduced.push_back(m+1); //push back the key value of best test case
        
        //remove the already covered branches from branch coverage of remaining test cases
        for (int j=0;j<b;j++){
            if (a[m][j]) 
            for (int l=0;l<n;l++){
                a[l][j]=0;
            }
        }
        
        sum(branches, a , n , b);
    }

    //output the key value of top (<=k) test cases
    ofstream out;
    out.open("red.txt");
    
    for (auto& it : reduced) {
        out << it << endl;
}
    out.close();
}