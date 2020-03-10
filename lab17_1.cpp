#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string tolower_for_str (string x){
    string y = x;
    for (int i = 0 ; i < x.size() ; i++)
    {
        y[i] = tolower(x[i]);
    }
    return y;
}

int main(){
    ifstream name1;
    name1.open("name_score.txt");
    string textline;
    char name [100];
    vector <string> name_list;
    vector <float> score_list;
    vector <string> g_list;
    while (getline(name1,textline)){
    	float a,b,c,sum;
        string grade;
    	char format [] = "%[^:]: %f %f %f";
        sscanf (textline.c_str() , format , name , &a , &b , &c);
        sum = a + b + c ;
        if(sum >= 80) grade = "A";
            else if (sum >= 70) grade = "B";
            else if (sum >= 60) grade = "C";
            else if (sum >= 50) grade = "D";
            else grade = "F";
        g_list.push_back(grade.c_str());
        score_list.push_back(sum);
        name_list.push_back(name);
    }
    vector <string> name_list1;
        for (int p = 0 ; p < name_list.size() ; p++)
    {
        name_list1.push_back(name_list[p]);
    }
    vector <string> g_list1;
        for (int p = 0 ; p < g_list.size() ; p++)
    {
        g_list1.push_back(g_list[p]);
    }
    string word;
    for(int b = 0 ; ; b++){
        for (int i=0 ; ; i++){
            cout << "Please input your command : ";
            getline (cin,word);
            word = tolower_for_str (word);
            if ( word == "exit") break;
            if ( word.substr(0,5) == "grade" || word.substr(0,4) == "name" ) break;
            else cout << "Invalid command " << endl;
        }
        cout << "---------------------------------" << endl;
        if ( word.substr(0,5) == "grade" ){
            bool checkgrade = 0;
            if (word.substr(6,1) == "a" || word.substr(6,1) == "b" || word.substr(6,1) == "c" || word.substr(6,1) == "d" || word.substr(6,1) == "f" ){   
                for (int j = 0 ; j < g_list.size() ; j++){
                    for (int f = 0 ; f < g_list.size() ; f++){
                        g_list[f] = tolower_for_str (g_list1[f]);
                        checkgrade += 1;
                    }
                    if (word.substr(6,1) == g_list[j]) cout << name_list1[j] << endl;
                } 
            }
             if (checkgrade == 0) cout << "Cannot found. " << endl;
            cout << "---------------------------------" << endl;
        }
        
        if (word.substr(0,4) == "name") {
           for (int r = 0 ; r < g_list.size() ; r++){
                   name_list[r] = tolower_for_str (name_list[r]);
            }
            bool checkname = 0;
            for ( int z = 0 ; z < name_list.size() ; z++){
                if ( name_list[z] == word.substr(5,word.size())){
                    checkname += 1;
                    for (int k = 0 ; k < g_list.size() ; k++){
                        if (word.substr(5,word.size()) == name_list[k]) {
                            cout << name_list1[k] << "'s grade = " << g_list1[k] << endl;  
                        }
                    } 
                }
            }
            if (checkname == 0) cout << "Cannot found. " << endl;
            cout << "---------------------------------" << endl;
        }
        if ( word == "exit") break;
    }
    return 0;
}