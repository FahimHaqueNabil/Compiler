#include<iostream>
#include<string.h>

using namespace std;

void  run();

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

    int i, mid1=0, size=str.size();

    for(i=0; i<str.length(); i++){
        if(str[i]>='A'&& str[i]<='Z'){
            mid1++;
            break;
        }else{
            mid1++;
        }
    }


    if(str[0]=='\"'){
        string match1= str.substr(1,3);
        if(match1=="1" || match1=="3" || match1=="5" || match1=="7" || match1=="9"){
            string match2=str.substr(4,mid1-1);
            if(match2=="false" || match2=="true"){
                string match3= str.substr(mid1,2);
                if(match3>="A" && match3<="Z"){
                    string match4= str.substr(mid1+2,2);
                    if(match4>="a" && match4<="z"){
                        string match5=str.substr(mid1+4,3);
                        if(match5=="030"){
                            if(str[size-1]=='\"'){
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
    }else{
        cout<< "Not Accepted!\n\n";
    }


}
