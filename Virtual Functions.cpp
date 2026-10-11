#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Person() {};
};

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    static int next_id;
public:
    Student() : cur_id{++next_id} {}
    
    void getdata() override {
        cin >> name >> age;
        for (int i = 0; i < 6; i++) cin >> marks[i];
    }
    
    void putdata() override {
        int sum = 0;
        for (const int& m : marks) sum += m;
        cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << '\n';
    }
};

class Professor : public Person {
private:
    int publications;
    int cur_id;
    static int next_id;
public:
    Professor() : cur_id{++next_id} {}
    
    void getdata() override {
        cin >> name >> age >> publications;
    }
    
    void putdata() override {
        cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
    }
};

int Student::next_id {0};
int Professor::next_id {0};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    
    vector<Person*> people;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        Person* p;
        if (type == 1) p = new Professor;
        else           p = new Student;
        p->getdata();
        people.push_back(p);
    }
    
    for (Person* p : people) p->putdata();
    for (Person* p : people) delete p;
     
    return 0;
}
