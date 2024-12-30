#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Articles // articles in a shop
{
public:
    int aid;
    string aname;
    double aprice;
    int aqty;
    Articles *nextArticle;
    Articles *preArticle;
    Articles(int id, string name, double price, int qty)
    {
        aid = id;
        aname = name;
        aprice = price;
        aqty = qty;
        nextArticle = NULL;
        preArticle = NULL;
    }
};
Articles *ArticleHead[15]; // articles head pointers
Articles *ArticleTail[15]; // articles tail pointers
class Shops                // shops list
{
public:
    string sname;
    int id;
    Articles *addArtHead;
    Shops *nextShop;
    Shops(string name, int n)
    {
        sname = name;
        addArtHead = ArticleHead[n];
        id = n;
        nextShop = NULL;
    }
};
Shops *ShopHead;
Shops *ShopTail;
class StackItem // Article name stack
{
public:
    int top;
    string *Article;
    StackItem()
    {
        Article = new string[20];
        top = -1;
    }
    void push(string x)
    {
        if (top < 20)
        {
            top++;
            Article[top] = x;
        }
        else
        {
            cout << "Cart Full!!!";
        }
    }
    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Cart Empty!!!";
        }
    }
    string topElement()
    {
        if (top > -1)
        {
            return Article[top];
        }
        else
        {
            return "";
        }
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class StackPrice // Price stack
{
public:
    double *price;
    int top;
    StackPrice()
    {
        top = -1;
        price = new double[20];
    }
    void push(double p)
    {
        if (top < 20)
        {
            top++;
            price[top] = p;
        }
        else
        {
            cout << "Price List is Full";
        }
    }
    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Price List is empty";
        }
    }
    double topElement()
    {
        if (top > -1)
        {
            return price[top];
        }
        else
        {
            return 0.0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class StackQty // Stack Quantity
{
public:
    int top;
    int *qty;
    StackQty()
    {
        top = -1;
        qty = new int[20];
    }
    void push(int x)
    {
        if (top < 20)
        {
            top++;
            qty[top] = x;
        }
        else
        {
            cout << "Quantity List is full";
        }
    }
    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Quantity List is empty";
        }
    }
    int topElement()
    {
        if (top > -1)
        {
            return qty[top];
        }
        else
        {
            return 0;
        }
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Login
{
public:
    string lid, ilid;
    string lpwd, ilpwd;
    Login()
    {
        lid = "admin";
        ilid = "";
        lpwd = "admin";
        ilpwd = "";
    }
    void input()
    {
        cout << "Enter Login ID:";
        getline(cin, ilid);
        cout << "Enter Password:";
        getline(cin, ilpwd);
    }
    int check()
    {
        if (lid == ilid && lpwd == ilpwd)
        {
            cout << endl<< "Welcome Admin!!!" << endl;
            return 1;
        }
        else
        {
            cout << "Invalid Credentials!!!" << endl;
            return 0;
        }
    }
};
void Shop_Insert(Shops *temp)
{
    if (ShopHead == NULL)
    {
        ShopHead = temp;
        ShopTail = temp;
    }
    else
    {
        ShopTail->nextShop = temp;
        ShopTail = ShopTail->nextShop;
    }
}
void Article_Insert(int n, Articles *temp) // Creation of articles in a shop
{
    if (ArticleHead[n] == NULL)
    {
        ArticleHead[n] = temp;
        ArticleTail[n] = temp;
    }
    else
    {
        temp->preArticle = ArticleTail[n];
        ArticleTail[n]->nextArticle = temp;
        ArticleTail[n] = ArticleTail[n]->nextArticle;
    }
}
void display_Articles(int n) // Display aricles of nth shop
{
    Articles *temp = ArticleHead[n];
    int x = 1;
    cout << endl << "Article Name\t\t\tRate\t\tQuantity" << endl<< endl;
    while (temp != NULL)
    {
        cout << x++ << ". ";
        cout << temp->aname << "\t\tRs ";
        cout << temp->aprice << "\t\t";
        cout << temp->aqty << endl;
        temp = temp->nextArticle;
    }
}
void display_Shops() // Display all Shop details
{
    Shops *temp = ShopHead;
    while (temp != NULL)
    {
        cout << endl<< "\t\t\t** " << temp->sname << " **" << endl;
        display_Articles(temp->id);
        temp = temp->nextShop;
    }
}
void displayShopName() // Display all shop names
{
    Shops *temp = ShopHead;
    int x = 1;
    cout << "\t\t\t** SHOP NAMES **" << endl << endl;
    while (temp != NULL)
    {
        cout << x++ << ". " << temp->sname << endl;
        temp = temp->nextShop;
    }
}
void remove_All_Articles(Articles *temp, int id) // Remove all articles of the shop
{
    Articles *ptemp = temp;
    temp = temp->nextArticle;
    while (temp != NULL)
    {
        delete ptemp;
        ptemp = temp;
        temp = temp->nextArticle;
    }
    delete ptemp;
    ArticleHead[id - 1] = NULL;
}
void removeArticles(int shopno, int id)
{
    Articles *temp = ArticleHead[shopno];
    Articles *ptemp = temp;
    while (temp != NULL)
    {
        if (temp->aid == id)
        {
            if (temp == ArticleHead[shopno])
            {
                ArticleHead[shopno] = ArticleHead[shopno]->nextArticle;
            }
            else
            {
                ptemp->nextArticle = temp->nextArticle;
            }
            delete temp;
            temp = NULL;
            break;
        }
        else
        {
            ptemp = temp;
            temp = temp->nextArticle;
        }
    }
}
void update_Articles(Articles *temp, int id, int operation, double nprice, int nqty, string nname) // update article values
{
    while (temp != NULL)
    {
        if (temp->aid == id)
        {
            if (operation == 1)
            {
                temp->aprice = nprice;
            }
            else if (operation == 2)
            {
                temp->aqty = nqty;
            }
            else
            {
                temp->aname = nname;
            }
            break;
        }
        temp = temp->nextArticle;
    }
}
void remove_Shops(int id) // Remove a required shop
{
    Shops *temp = ShopHead;
    Shops *ptemp = temp;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            flag = 1;
            if (temp == ShopHead)
            {
                ShopHead = ShopHead->nextShop;
            }
            else
            {
                ptemp->nextShop = temp->nextShop;
            }
            remove_All_Articles(temp->addArtHead, id);
            delete temp;
            temp = NULL;
            break;
        }
        else
        {
            ptemp = temp;
            temp = temp->nextShop;
        }
    }
    if (flag == 0)
    {
        cout << "No such Shop exists" << endl;
    }
}
void Bill(double billamt) // Calc Bill
{
    int bchoice;
    cout << endl<< "Choose the payment method form the following" << endl<< endl;
    cout << "Press 1 for Cash - No discount" << endl;
    cout << "Press 2 for Card - 3% discount" << endl;
    cout << "Press 3 for UPIs - 5% discount" << endl;
    cout << "Your Choice:";
    cin >> bchoice;
    cout << endl;

    double dis = 0.0, total = 0.0;
    if (bchoice == 2)
    {
        cout << endl<< "Thank You for opting digital payments" << endl<< endl;
        dis = billamt * 0.03;
    }
    else if (bchoice == 3)
    {
        cout << endl<< "Thank You for opting digital payments" << endl<< endl;
        dis = billamt * 0.05;
    }
    total = billamt - dis;

    cout << "Your total Billing Amount = Rs " << billamt << endl;
    cout << "Your total Discount       = Rs " << dis << endl;
    cout << "Your Outstanding amount   = Rs " << total << endl;
    cout << endl << "Visit again Soon!";
}
int main(int argc, char const *argv[])
{
    // pre initializaion
    Articles *atemp;
    Shops *stemp;
    ShopHead = NULL;
    ShopTail = NULL;
    int noOfShops = 11;
    for (int i = 0; i < noOfShops; i++)
    {
        ArticleHead[i] = NULL;
        ArticleTail[i] = NULL;
    }
    double billamt = 0.0;
    int k = 0;
    bool buy = false;
    StackItem si;
    StackPrice sp;
    StackQty sq;
    // pre insertion
    string ShopNames[15] = {"Hamleys       ", "24/7     ", "Vijay Sales", "Minisu       ", "Croma", "Relience Digital", "Relience Trends", "Bata      ", "Pantaloons", "Gulati        ", "Subway", "", "", "", ""};
    // Hamley Shop
    string Hamley_name[5] = {"Monkey Toy\t", "Chess Board\t", "Hat    \t", "Duck Toy  \t", "Teddy Bear\t"};
    double Hamley_price[5] = {200, 400, 325, 150, 250};
    int Hamley_qty[5] = {4, 22, 35, 9, 45};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Hamley_name[i], Hamley_price[i], Hamley_qty[i]);
        Article_Insert(0, atemp);
    }
    stemp = new Shops("Hamleys", 0);
    Shop_Insert(stemp);
    // 24/7
    string t247_name[5] = {"Pizza\t", "Cold Drink\t", "Juice Pack\t", "Pasta\t", "Apple\t"};
    double t247_price[5] = {290, 80, 95, 160, 45};
    int t247_qty[5] = {5, 35, 60, 3, 25};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, t247_name[i], t247_price[i], t247_qty[i]);
        Article_Insert(1, atemp);
    }
    stemp = new Shops("24/7", 1);
    Shop_Insert(stemp);
    // Vijay sales
    string VijaySales_name[5] = {"Washing machine", "Roti maker\t", "Standing fan\t", "Air Conditioner", "Electric Chair"};
    double VijaySales_price[5] = {15000, 4000, 3000, 16000, 30000};
    int VijaySales_qty[5] = {33, 45, 60, 34, 25};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, VijaySales_name[i], VijaySales_price[i], VijaySales_qty[i]);
        Article_Insert(2, atemp);
    }
    stemp = new Shops("Vijay Sales", 2);
    Shop_Insert(stemp);
    // Minisu
    string Minisu_name[5] = {"Earplugs\t", "Charger\t", "Hand towels\t", "Mask\t\t", "Sanitizer\t"};
    double Minisu_price[5] = {500, 200, 600, 1600, 200};
    int Minisu_qty[5] = {30, 42, 55, 78, 100};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Minisu_name[i], Minisu_price[i], Minisu_qty[i]);
        Article_Insert(3, atemp);
    }
    stemp = new Shops("Minisu", 3);
    Shop_Insert(stemp);
    // Croma
    string Croma_name[5] = {"MI Phone\t", "Head Phone\t", "Adapter\t", "Tablet\t", "Pen Drive\t"};
    double Croma_price[5] = {20000, 3000, 600, 2000, 25000};
    int Croma_qty[5] = {39, 21, 65, 38, 89};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Croma_name[i], Croma_price[i], Croma_qty[i]);
        Article_Insert(4, atemp);
    }
    stemp = new Shops("Croma", 4);
    Shop_Insert(stemp);
    // Relience Digital
    string RelienceDigtial_name[5] = {"Geyser\t", "Weighing Machine", "Oven\t\t", "Television\t", "Rice Cooker\t"};
    double RelienceDigtial_price[5] = {22000, 3000, 1100, 20000, 25000};
    int RelienceDigtial_qty[5] = {11, 89, 20, 47, 78};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, RelienceDigtial_name[i], RelienceDigtial_price[i], RelienceDigtial_qty[i]);
        Article_Insert(5, atemp);
    }
    stemp = new Shops("Relience Digital", 5);
    Shop_Insert(stemp);
    // Relience Trends
    string RelienceTrends_name[5] = {"Sweater\t", "Jacket\t", "Cap\t\t", "Joggers\t", "Gloves\t"};
    double RelienceTrends_price[5] = {4500, 3000, 600, 700, 300};
    int RelienceTrends_qty[5] = {17, 69, 51, 90, 56};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, RelienceTrends_name[i], RelienceTrends_price[i], RelienceTrends_qty[i]);
        Article_Insert(6, atemp);
    }
    stemp = new Shops("Relience Trends", 6);
    Shop_Insert(stemp);
    // Bata
    string Bata_name[5] = {"Sports shoes\t", "School shoes\t", "Sandal\t", "Heels\t", "Sleepers\t"};
    double Bata_price[5] = {4500, 3000, 600, 700, 900};
    int Bata_qty[5] = {35, 67, 45, 40, 89};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Bata_name[i], Bata_price[i], Bata_qty[i]);
        Article_Insert(7, atemp);
    }
    stemp = new Shops("Bata", 7);
    Shop_Insert(stemp);
    // Pantaloons
    string Pantaloons_name[5] = {"Skirt\t", "Top\t\t", "Leggings\t", "Kurti\t", "Jeans\t"};
    double Pantaloons_price[5] = {450, 800, 800, 900, 1000};
    int Pantaloons_qty[5] = {67, 38, 78, 68, 89};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Pantaloons_name[i], Pantaloons_price[i], Pantaloons_qty[i]);
        Article_Insert(8, atemp);
    }
    stemp = new Shops("Pantaloons", 8);
    Shop_Insert(stemp);
    // Gulati
    string Gulati_name[5] = {"Tie\t\t", "Blazer\t", "Socks\t", "Trousers\t", "Belt\t\t"};
    double Gulati_price[5] = {90, 2000, 100, 200, 300};
    int Gulati_qty[5] = {80, 65, 56, 76, 67};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Gulati_name[i], Gulati_price[i], Gulati_qty[i]);
        Article_Insert(9, atemp);
    }
    stemp = new Shops("Gulati", 9);
    Shop_Insert(stemp);
    // Subway
    string Subway_name[5] = {"Burger\t", "Chicken tikka sub", "Paneer tikka sub", "Pepsi\t", "Vegetable Sub"};
    double Subway_price[5] = {180, 200, 300, 40, 500};
    int Subway_qty[5] = {89, 51, 83, 45, 36};
    for (int i = 0; i < 5; i++)
    {
        atemp = new Articles(i + 1, Subway_name[i], Subway_price[i], Subway_qty[i]);
        Article_Insert(10, atemp);
    }
    stemp = new Shops("Subway", 10);
    Shop_Insert(stemp);
    // post
    int choice;
    string id, pwd;
    cout << endl<< "Welcome to Shopping Club" << endl;
    cout << "Enter your choice:" << endl;
    cout << "Press 1 for Admin" << endl;
    cout << "Press 2 for Customer" << endl;
    cout << "Press 3 for Sneak-Peek" << endl;
    cout << "Your Choice:";
    cin >> choice;
    cout << endl;
    if (choice == 1) // Administration
    {
        Login L;
        getchar();
        L.input();
        int x = L.check();
        if (x == 0) // Wrong credentials
        {
            cout << endl<< "Try again!" << endl;
            L.input();
            x = L.check();
            if (x == 0) // Retry
            {
                cout << endl<< "Maximum attempts reached!" << endl;
                exit(0);
            }
        }
        if (x == 1) // Correct Credentials & proceeding with admin functions
        {
            do
            {
                int adchoice;
                cout << endl<< "Choose for the admin functions:" << endl;
                cout << "Press 1 to view shops" << endl;
                cout << "Press 2 to add a shop" << endl;
                cout << "Press 3 to remove a shop" << endl;
                cout << "Press 4 to modify a shop" << endl;
                cout << "Your Choice:";
                cin >> adchoice;
                cout << endl;
                if (adchoice == 1)
                {
                    displayShopName();
                }
                else if (adchoice == 2) // Add a new shop with Articles
                {
                    string s;
                    int nArticles;
                    getchar();
                    cout << "Enter the Shop name:";
                    getline(cin, s);
                    // Create a new shop node
                    cout << "Enter the number of Articles:";
                    cin >> nArticles;
                    string Shop_Article_name[nArticles];
                    double Shop_Article_price[nArticles];
                    int Shop_Article_qty[nArticles];
                    cout << "Enter Article details:" << endl;
                    for (int i = 0; i < nArticles; i++)
                    {
                        cout << endl;
                        getchar();
                        cout << "Article " << i + 1 << " Name:";
                        getline(cin, Shop_Article_name[i]);
                        cout << "Article " << i + 1 << " Price:";
                        cin >> Shop_Article_price[i];
                        cout << "Article " << i + 1 << " Quantity:";
                        cin >> Shop_Article_qty[i];
                    }
                    for (int i = 0; i < nArticles; i++)
                    {
                        atemp = new Articles(noOfShops, Shop_Article_name[i], Shop_Article_price[i], Shop_Article_qty[i]);
                        Article_Insert(noOfShops, atemp);
                    }
                    stemp = new Shops(s, noOfShops);
                    ShopNames[noOfShops] = s;
                    Shop_Insert(stemp);
                    displayShopName();
                    cout << endl;
                    cout << "\t\t\t** SHOP DETAILS **" << endl<< endl;
                    display_Articles(noOfShops);
                    noOfShops++;
                }
                else if (adchoice == 3) // Removing a particular shop
                {
                    int rshop;
                    cout << endl<< "ns=" << noOfShops;
                    stemp = ShopHead;
                    cout << "Choose the Shop no. to delete:" << endl;
                    for (int k = 0; k < noOfShops; k++)
                    {
                        cout << k + 1 << ". " << stemp->sname << "\t\t";
                        stemp = stemp->nextShop;
                        if ((k + 1) % 3 == 0)
                        {
                            cout << endl;
                        }
                    }
                    cout << endl;
                    cout << "Your Choice:";
                    cin >> rshop;
                    remove_Shops(rshop - 1);
                    cout << endl;
                    displayShopName();
                    noOfShops--;
                }
                else if (adchoice == 4) // Modify a particular shop
                {
                    int schoice;
                    string scname;
                    int mchoice;
                    getchar();
                    stemp = ShopHead;
                    cout << "Choose the Shop no. to modify:" << endl;
                    for (int k = 0; k < noOfShops; k++)
                    {
                        cout << k + 1 << ". " << stemp->sname << "\t\t";
                        stemp = stemp->nextShop;
                        if ((k + 1) % 3 == 0)
                        {
                            cout << endl;
                        }
                    }
                    cout << endl;
                    cout << "Your Choice:";
                    cin >> schoice;
                    scname = ShopNames[schoice - 1];
                    cout << endl<< "Choose from the following operations:" << endl;
                    cout << "Press 1 to add  an article" << endl;
                    cout << "Press 2 to remove an article" << endl;
                    cout << "Press 3 to modify an article" << endl;
                    cout << "Your Choice:";
                    cin >> mchoice;
                    cout << endl;
                    if (mchoice == 1) // Add article
                    {
                        cout << "Initial Shop Details" << endl;
                        display_Articles(schoice - 1);
                        getchar();
                        string naname;
                        int naqty;
                        double naprice;
                        cout << endl<< "Enter the article name:";
                        getline(cin, naname);
                        cout << "Enter the artice price:";
                        cin >> naprice;
                        cout << "Enter the article quantity:";
                        cin >> naqty;
                        atemp = new Articles(ArticleTail[schoice - 1]->aid + 1, naname, naprice, naqty);
                        Article_Insert(schoice - 1, atemp);
                        cout << endl;
                        display_Articles(schoice - 1);
                    }
                    else if (mchoice == 2) // Remove article
                    {
                        int rarticle;
                        display_Articles(schoice - 1);
                        cout << "Choose the article to remove:" << endl;
                        cout << "Your Choice:";
                        cin >> rarticle;
                        removeArticles(schoice - 1, rarticle);
                        display_Articles(schoice - 1);
                    }
                    else if (mchoice == 3) // Update values
                    {
                        int z = 0;
                        do
                        {
                            int marticle;        // article id
                            int marchoice;       // operation
                            double nprice = 0.0; // updated price
                            int nqty;            // updated qty
                            string nname;        // updated name
                            display_Articles(schoice - 1);
                            cout << "Choose the article:" << endl;
                            cin >> marticle;
                            cout << "Choose from the following opeartions" << endl;
                            cout << "Press 1 to update the price" << endl;
                            cout << "Press 2 to update the quantity" << endl;
                            cout << "Press 3 to update the name" << endl;
                            cin >> marchoice;
                            if (marchoice == 1)
                            {
                                cout << "Enter the new price:";
                                cin >> nprice;
                            }
                            else if (marchoice == 2)
                            {
                                cout << "Enter the updated quantity:";
                                cin >> nqty;
                            }
                            else
                            {
                                cout << "Enter the updated name:";
                                getchar();
                                getline(cin, nname);
                            }
                            update_Articles(ArticleHead[schoice - 1], marticle, marchoice, nprice, nqty, nname);
                            display_Articles(schoice - 1);
                            cout << "Press 0 to update further else press 1:";
                            cin >> z;
                        } while (z == 0);
                    }
                }
                else
                {
                    cout << endl<< "Invalid Choice!" << endl;
                }
                cout << endl<< "Press 0 for more admin options else Press 1:";
                cin >> k;
            } while (k == 0);
        }
    }
    else if (choice == 2) // Customer Options
    {
        cout << "Welcome Customer(s)" << endl<< endl;
        int y = 0, z = 0;
        int shopselect;
        int artselect;
        int qtyselect;
        cout << "Choose the Shop from below" << endl<< endl;
        do
        {
            displayShopName(); // Choose Shop
            cout << "Yourchoice:";
            cin >> shopselect;
            cout << endl;
            cout << "Choose the product to buy else Press 0" << endl;
            display_Articles(shopselect - 1); // Choose Article
            do
            {
                cout << "Article:";
                cin >> artselect;
                if (artselect != 0)
                {
                    cout << "Quantity:";
                    cin >> qtyselect;
                }
                string artselectname = "";
                double artselectprice = 0.0;
                atemp = ArticleHead[shopselect - 1];
                if (artselect != 0)
                {
                    buy = true;
                    while (atemp != NULL)
                    {
                        if (atemp->aid == artselect)
                        {
                            artselectname = atemp->aname;
                            artselectprice = atemp->aprice;
                            if (qtyselect > atemp->aqty)
                            {
                                qtyselect = atemp->aqty;
                            }
                            atemp->aqty = atemp->aqty - qtyselect;
                        }
                        atemp = atemp->nextArticle;
                    }
                }
                si.push(artselectname); // Push in array
                sq.push(qtyselect);
                sp.push(artselectprice);
                cout << "Press 0 to purchase from other article else press 1:";
                cin >> z;
            } while (z == 0);
            cout << endl<< "Press 0 to purchase from other shops else press 1:";
            cin >> y;
        } while (y == 0);
        // Displaying Products and quantity
        int sno = 1;
        cout << endl<< "\t\t\t\t*** BILL DETAILS ***" << endl<< endl;
        cout << "Sno.\t\tArticleName\t\t\t\tRate\t\tQuantity \tPrice" << endl<< endl;
        while (!si.isempty())
        {
            cout << sno << "\t\t" << si.topElement() << "\t\t\t" << sp.topElement() << "\t\t"<< sq.topElement() << "\t\t" << sp.topElement() * sq.topElement();
            billamt = billamt + sp.topElement() * sq.topElement();
            si.pop();
            sp.pop();
            sq.pop();
            sno++;
            cout << endl;
        }
        if (buy == true) // if bought
        {
            Bill(billamt);
        }
        else
        {
            cout << endl<< "\t\t\t** Please do visit again for new arrivals **" << endl;
        }
    }
    else if (choice == 3) // Sneak Peek
    {
        cout << "Have a look at our Shopping Club Offerings" << endl;
        display_Shops();
    }
    else
    {
        cout << endl<< "Invalid Choice!" << endl;
        exit(0);
    }
    return 0;
}
// displayshopname
