# include <iostream>

using namespace std;

class Student {
    public:
    float GPA;
    Student* next;
};

int main(){

    Student x,y;

    x.next = &y;
    
    cout << "hello";

    return 0;
}