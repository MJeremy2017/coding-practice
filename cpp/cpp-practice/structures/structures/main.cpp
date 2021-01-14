//
//  main.cpp
//  structures
//
//  Created by Yue Zhang on 13/1/21.
//

#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    double price;
};

struct Student {
    int id;
    int year;
    char name[20];
    
    Student() {
        id = 0;
        year = 1971;
        memset(name, 0, sizeof(name));
    }
    
    Student(int _id, int _year) {
        id = _id;
        year = _year;
    }
    
} student;

Book library[10];

bool cmp(Student s1, Student s2) {
    return  s1.id < s2.id;
}

int main() {
    // insert code here...
    Book book1;
    book1.title = "sinusitis";
    book1.author = "martin";
    
    cout << "book title is " << book1.title << endl;
    cout << "book author is " << book1.author << endl;
    
    for (int i=0; i<10; ++i) {
        library[i].title = "abc";
        library[i].author = "d";
    }
    
    cout << library[3].title << endl;
    
    Student student1(3, 13);
    cout << student1.year << endl;
    
    
    Student students[10];
    students[0].id = 3;
    students[1].id = 12;
    students[2].id = 4;
    
    sort(students+0, students+3, cmp);
    
    for (int i=0; i<3; ++i) {
        cout << students[i].id << endl;
    }
    return 0;
}
