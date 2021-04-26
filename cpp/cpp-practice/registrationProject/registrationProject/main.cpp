//
//  main.cpp
//  registrationProject
//
//  Created by Yue Zhang on 21/2/21.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string filepath = "/Users/yuezhang/Workspace/github/leetcoding/cpp/cpp-practice/registrationProject/registrationProject/data/";

void Register() {
    string username, password;
    ofstream ofs;
    cout << "username: ";
    cin >> username;
    cout << "password: ";
    cin >> password;
    
    ofs.open(filepath + username + ".txt");

    ofs << username << endl;
    ofs << password << endl;
    ofs.close();
}

bool Login() {
    string username, password;
    string f_username, f_password;
    cout << "username: ";
    cin >> username;
    cout << "password: ";
    cin >> password;
    
    // open file and compare
    ifstream file;
    file.open(filepath + username + ".txt");
    getline(file, f_username);
    getline(file, f_password);
    file.close();
    
    cout << "f: " << f_username << " " << f_password << endl;
    if (f_username == username && f_password == password) {
        cout << "Login Success" << endl;
        return true;
    } else {
        cout << "Login Failed, Either Username or Password is wrong!" << endl;
        return false;
    }
    
}


int main() {
    int choice;
    cout << "choose registion\n1.Register\n2.Login" << endl;
    cin >> choice;

    if (choice == 1) {
        Register();
    } else if (choice == 2) {
        bool status;
        status = Login();
        if (status == false) main();
    } else {
        cout << "wrong input!" << endl;
    }
    
    return 0;
}
