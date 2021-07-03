#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int main(){

    ifstream ifile ;
    ifile.open("test.txt");
    int a=0,sum=0; 
    string str = "";
    float f;
    
cout<<"*****Welcome to bidding war***** \nInstructions: \n -Enter an increase in bid value from 1-10 \n -If you enter a value > 10, then modulo 10 is taken \n -Enter 0 to give up the war and exit\n";    
cout << "\nEnter initial bid : ";

    while (1){
        getline(ifile,str);
        int i = str.find_first_not_of(" \t");
        int j = str.find_last_not_of(" \t");
        str = str.substr(i, j-i+1);
        stringstream ss(str);

        if ((!(ss >> a)) || (ss.str().compare(to_string(a))) || (a<0)){
            cout<<ss.str()<<"\nplease enter a non-negative integer bid : ";
            continue;
        }

        cout<<a<<endl;

        if (a==0) {
            cout<<"You quit the bidding war \n";
            break;
        }
        
        sum+=(a%10);
        if (sum>=100) {
            cout<<"you won with a bid of "<<sum<<endl; 
            break;
            }

        sum+=(a%10);
        cout<<"your bid was matched by opposing teams \ncurrent bid = "<<sum<<endl;
        
        cout << "\nEnter increase in bid : ";
    }
    return 0;
}
