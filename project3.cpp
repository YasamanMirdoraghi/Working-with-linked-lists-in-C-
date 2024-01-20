#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    float data;
    int power;
    Node *next;
};
Node *Split(string &phrase);
void SortList(Node *&head, float x, int y);
void Simple(Node *head);
void Output(Node *node);
void Deleteziro(Node *&first);
void clear_list(Node *&f);

int main()
{
    string phrase;
    Node *f = NULL;
    cout << "\nWelcom to my program :)\n";
    cout << "Press zero to finish";
    do
    {
        cout << "\nPlease enter your desired phrase:" << endl;
        getline(cin >> ws, phrase, '\n');
        f = Split(phrase);
        Simple(f);
        Deleteziro(f);
        Output(f);
        clear_list(f);
        if (phrase == "0")
            cout << "\nbye :(" << endl;
    } while (phrase != "0");
}
// Split
Node *Split(string &phrase)
{
    Node *node = NULL;
    istringstream str(phrase);
    string one;
    while (getline(str, one, '+'))
    {
        istringstream str2(one);
        string two;
        bool NegativeSign = false;
        while (getline(str2, two, '-'))
        {
            string key1 = "x", key2 = "^";
            string coefficient = "1", power = "1";
            if (NegativeSign == false)
            {
                if (two != "")
                {
                    size_t size1 = two.find(key1);
                    size_t size2 = two.find(key2);
                    string posetive = "+" + two;
                    coefficient = posetive.substr(0, posetive.find(key1));
                    if (size1 != string::npos && size2 != string::npos)
                    {
                        if (coefficient == "+")
                            coefficient = coefficient + "1";
                        else
                            coefficient = coefficient;
                        power = posetive.substr(posetive.find(key2) + 1);
                    }
                    else if (size1 != string::npos && size2 == string::npos)
                    {
                        if (coefficient == "+")
                            coefficient = coefficient + "1";
                        else
                            coefficient = coefficient;
                    }
                    else if (size1 == string::npos && size2 == string::npos)
                        power = "0";

                    SortList(node, (stof(coefficient)), stoi(power));
                }
            }
            else
            {
                if (two != "")
                {
                    size_t size1 = two.find(key1);
                    size_t size2 = two.find(key2);
                    string negetive = "-" + two;
                    coefficient = negetive.substr(0, negetive.find(key1));
                    if (size1 != string::npos && size2 != string::npos)
                    {
                        if (coefficient == "-")
                            coefficient = coefficient + "1";
                        else
                            coefficient = coefficient;
                        power = negetive.substr(negetive.find(key2) + 1);
                    }
                    else if (size1 != string::npos && size2 == string::npos)
                    {
                        if (coefficient == "-")
                            coefficient = coefficient + "1";
                        else
                            coefficient = coefficient;
                    }
                    else if (size1 == string::npos && size2 == string::npos)
                        power = "0";
                    SortList(node, (stof(coefficient)), stoi(power));
                }
            }
            NegativeSign = true;
        }
    }
    return node;
}
// SortList
void SortList(Node *&head, float x, int y)
{
    Node *temp = new Node;
    temp->data = x;
    temp->power = y;
    if (!head)
    {
        temp->next = NULL;
        head = temp;
        return;
    }
    if (y > head->power)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node *p = head;
    Node *q = head->next;
    while (q != NULL && y < q->power)
    {
        p = q;
        q = q->next;
    }
    temp->next = q;
    p->next = temp;
}
// Simplify
void Simple(Node *head)
{
    Node *current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->power == current->next->power)
        {
            current->data += current->next->data;
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}
//Deleteziro
void Deleteziro(Node *&first)
{
    while (first && first->data == 0)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    if (!first)
        return;

    Node *m = first;
    Node *n = first->next;
    while (n)
    {
        if (n->data == 0)
        {
            Node *temp = n;
            n = n->next;
            m->next = n;
            delete temp;
        }
        else
        {
            m = n;
            n = n->next;
        }
    }
}
//clear_list
void clear_list(Node *&first)
{
    while (first)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}
// Output
void Output(Node *node)
{
    Node *temp = node;
    cout << "f(x)=";
    string key3 = "-";
    float sum = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    while (temp != NULL)
    {
        string r = to_string(temp->data);
        size_t size3 = r.find(key3);
        if (size3 != string::npos)
        {
            if (temp->data == -1)
            {
                if (temp->power == 1)
                {
                    a += -1;
                    cout << "-x";
                }
                else if (temp->power == 0)
                {
                    cout << temp->data;
                    b += -1;
                }
                else
                {
                    cout << "-x^" << temp->power;
                    c += -1;
                }
            }
            else
            {
                if (temp->power == 1)
                {
                    d += temp->data;
                    cout << temp->data << "x";
                }
                else if (temp->power == 0)
                {
                    e += temp->data;
                    cout << temp->data;
                }
                else
                {
                    f += temp->data;
                    cout << temp->data << "x^" << temp->power;
                }
            }
        }
        else
        {
            if (temp->data == 1)
            {
                if (temp->power == 1)
                {
                    cout << "+x";
                    a += 1;
                }
                else if (temp->power == 0)
                {
                    cout << "+" << temp->data;
                    b += 1;
                }
                else
                {
                    cout << "+x^" << temp->power;
                    c += 1;
                }
            }
            else
            {
                if (temp->power == 1)
                {
                    cout << "+" << temp->data << "x";
                    d += temp->data;
                }
                else if (temp->power == 0)
                {
                    cout << "+" << temp->data;
                    e += temp->data;
                }
                else
                {
                    cout << "+" << temp->data << "x^" << temp->power;
                    f += temp->data;
                }
            }
        }
        temp = temp->next;
    }
    if (sum == 0 && a == 0 && b == 0 && c == 0 && e == 0 && f == 0 && d == 0)
        cout << "0";
}