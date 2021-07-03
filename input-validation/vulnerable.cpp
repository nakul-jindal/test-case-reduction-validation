#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream ifile ;
    ifile.open("test.txt");
    int a=0,sum=0; 
    cout<<"*****Welcome to bidding war***** \nInstructions: \n -Enter an increase in bid value from 1-10 \n -If you enter a value > 10, then modulo 10 is taken \n -Enter 0 to give up the war and exit\n";
    cout << "\nEnter initial bid : ";

    while (1){
        //ifile >> a;
        cin>>a;
        cout<<a<<endl;
        if (a==0) {
            cout<<"You quit the bidding war \n\n";
            break;
        }
        sum+=(a%10);
        if (sum>=200) {cout<<"you won with a bid of "<<sum<<endl; break;}

        sum+=(a%10);
        cout<<"your bid was matched by opposing teams \ncurrent bid = "<<sum<<endl;
        
        cout << "\nEnter increase in bid : ";
    }
    return 0;
}