#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    int price;

    Product(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
public:
    vector<Product *> products;

    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    vector<Product *> getProduct()
    {
        return products;
    }

    int calculateTotal()
    {

        int total=0;

        for (auto i : products)
        {
            total += i->price;
        }

        return total;
    }
};

class CartInvoicePrinter
{

public:
    ShoppingCart *cart;

    CartInvoicePrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printInvoice()
    {

        cout << "YOUR TOTAL PRODUCTS ARE :- " << endl;

        for (auto i : cart->getProduct())
        {
            cout << i->name << " - " << i->price << endl;
        }
        cout<<"YOUR TOTAL AMOUNT IS : "<<cart->calculateTotal()<<endl;
        cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    }
};

class storage
{

public:
    ShoppingCart *cart;

    storage(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void saveToDatabase(){
        cout<<"your all products have been saved to database";
    }
};

int main()
{

    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("watch",5000));
    cart->addProduct(new Product("shirt",1000));
    cart->addProduct(new Product("pant",3000));
    cart->addProduct(new Product("shoes",15000));
    cart->addProduct(new Product("jacket",12000));

    CartInvoicePrinter* invoice = new CartInvoicePrinter(cart);
    invoice->printInvoice();

    storage* Storage = new storage(cart);
    Storage->saveToDatabase();

    return 0;
}