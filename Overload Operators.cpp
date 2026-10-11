//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+(const Complex& x, const Complex& y) {
    Complex r;
    r.a = x.a + y.a;
    r.b = x.b + y.b;
    return r;    
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.a << "+i" << c.b;
    return out;
}
