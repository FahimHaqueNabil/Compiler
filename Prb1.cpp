#include<iostream>
#include<string.h>

using namespace std;

void run();

int main(){
    int n;

    do{
        cout<< "Choose one:\n1. Run::\n2. Exit:\n\n";
        cout<< "Enter your option:\n";
        cin>> n;

        if(n==1) run();
        else if(n==2) break;

    }while(true);
    return 0;
}


void run(){
    string str;
    cout<< "Enter your Expression:\n";
    cin>> str;

    int i, mid=0, size=str.size();

    for(i=0; i<str.length(); i++){
        if(str[i]=='@' || str[i]=='#' || str[i]=='$'){
            mid++;
            break;
        }else{
            mid++;
        }
    }

    string match1= str.substr(0, mid-1);
    if(match1>="A" && match1<="Z"){
        string match2= str.substr(mid-1,1);
        if(match2=="@" || match2=="#" || match2== "$"){
            string match3= str.substr(mid,3);
            if(match3=="UIU"){
                string match4= str.substr(mid+3,1);
                if(match4>="1" && match4<="3"){
                    string match5=str.substr(mid+4,3);
                    if(match5>="001" && match5<="999"){
                        string match6= str.substr(mid+7,1);
                        if(match6=="+" || match6=="-" || match6=="NULL"){
                            cout<< "Accepted!\n\n";
                        }else{
                            cout<< "Not Accepted!\n\n";
                        }
                    }else{
                        cout<< "Not Accepted!\n\n";
                    }
                }else{
                    cout<< "Not Accepted!\n\n";
                }
            }else{
                cout<< "Not Accepted!\n\n";
            }

        }else{
            cout<< "Not Accepted!\n\n";
        }
    }else{
        cout<< "Not Accepted!\n\n";
    }


}
