#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *title, char *isbn, int value) : price(value)
    {
        this->title = new char[strlen(title)+1];
        this->isbn = new char[strlen(isbn)+1];
        strcpy(this->title, title);
        strcpy(this->isbn, isbn);
    }
    void ShowBookInfo()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"Price: "<<price<<endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char *DRMKey;
public:
    EBook(char *title, char *isbn, int value, char *Key)
        : Book(title, isbn, value)
    {
        DRMKey = new char[strlen(Key)+1];
        strcpy(DRMKey, Key);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"Auth Key: "<<DRMKey<<endl;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}