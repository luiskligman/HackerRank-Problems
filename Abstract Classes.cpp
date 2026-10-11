// Write your MyBook class here
class MyBook : public Book {
    int price;
public:
    //   Class Constructor
    MyBook(string t, string a, int p) : Book(t, a), price{p} {}
    
    void display() override {
        cout << "Title: " << title << '\n';
        cout << "Author: " << author << '\n';
        cout << "Price: " << price << '\n';
    }
};    
// End class
