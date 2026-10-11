#include<bits/stdc++.h>
using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {
private:
    int l;
    int b;
    int h;

// The class should have the following functions : 
public:
// Constructors: 
// Box();
Box() : l {0}, b {0}, h {0} {}
// Box(int,int,int);
Box(int length, int breadth, int height) : l{length}, b{breadth}, h{height} {}
// Box(Box);
Box(const Box& b) : l{b.getLength()}, b{b.getBreadth()}, h{b.getHeight()} {}


// int getLength(); // Return box's length
int getLength() const {
    return l;
}
// int getBreadth (); // Return box's breadth
int getBreadth() const {
    return b;
}
// int getHeight ();  //Return box's height
int getHeight() const {
    return h;
}
// long long CalculateVolume(); // Return the volume of the box
long long CalculateVolume() const {
    return 1LL * l * b * h;
}

//Overload operator < as specified
//bool operator<(Box& b)
bool operator<(const Box& box) const {
    if (l < box.l) return true;
    if (b < box.b && l == box.l) return true;
    if (h < box.h && b == box.b && l == box.l) return true;
    return false;
}
};
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
ostream& operator<<(ostream& out, const Box& B) {
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}
