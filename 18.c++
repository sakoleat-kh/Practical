#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Book {
    private:
        char *author, *title, *publischer;
        float *price;
        int *stock;

    public:
        Book() {
            author = new char[50];
            title = new char[50];
            publischer = new char[50];
            price = new float;
            stock = new int;
        }

    void feedData() {
        cout << "\nEnter Author Name: ";
        cin.getline(author, 50);
        cout << "Enter Title Name: ";
        cin.getline(title, 50);
        cout << "Enter Publischer Name: ";
        cin.getline(publischer, 50);
        cout << "Enter Price: ";
        cin >> *price;
        cout << "Enter Stock Position: ";
        cin >> *stock;
        cin.ignore();
    }

    void showData() {
        cout << "\nAuthor Name: " << author;
        cout << "\nTitle Name: " << title;
        cout << "\nPublischer Name: " << publischer;
        cout << "\nPrice: " << *price;
        cout << "\nStock Available: " << *stock << endl; 
    }

    int search(char t[], char a[]) {
        if (strcmp(title, t) == 0 && strcmp(author, a) == 0)
            return 1;
        else
            return 0;
    }

    void buyBook() {
        int count;
        cout << "\nEnter Number pf Copies Required: ";
        cin >> count;
        if (count <= *stock) {
            *stock = *stock - count;
            cout << "\nBooks Bougth Successfully!" << endl;
            cout << "Total Cost: Rs. " << (*price) * count << endl;
        } else {
            cout << "\nRequired Copies Not in stock" << endl;
        }
    }
};

int main() {
    int n, i, choice;
    cout << "\nEnter Number of Books in Inventory: ";
    cin >> n;
    cin.ignore();

    Book *b[n];
    for (i = 0; i < n; i++) {
        b[i] = new Book;
        b[i]->feedData();
    }

    char titleInput[50], authorInput[50];
    cout << "\nEnter Title and Author to Search: " << endl;
    cout << "Title: ";
    cin.getline(titleInput, 50);
    cout << "Author: ";
    cin.getline(authorInput, 50);

    int found = 0;

    for (i = 0; i < n; i++) {
        if (b[i]->search(titleInput, authorInput)) {
            b[i]->showData();
            b[i]->buyBook();
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "\nBook Not Found" << endl;
    }
    return 0;
}