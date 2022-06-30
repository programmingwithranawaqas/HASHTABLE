// Author : Programming with Rana Waqas
// Youtube Channel Name : Programming with Rana Waqas
// Subscribe and like if you are enjoying the videos

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class HashTable{
    Node **arr;
    int size;
public:
    HashTable()
    {
        arr = NULL;
        size = 0;
    }
    HashTable(int size)
    {
        arr = new Node*[size];
        for(int i=0; i<size; i++)
        {
            arr[i] = NULL;
        }
        this->size = size;
    }
    int HashFun(int data)
    {
        int key = data%size;
        return key;
    }
    void insert(int data)
    {
        int key = HashFun(data);
        //cout<<"KEY : "<<key<<endl;
        Node* temp = arr[key];
        if(temp == NULL)
        {
            arr[key] = new Node(data);
        }
        else
        {
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = new Node(data);
        }
    }

    void display()
    {

        if(arr==NULL)
        {
            cout<<"Empty HashTable."<<endl;
        }
        else
        {

            for(int i=0; i<size; i++)
            {
                cout<<"arr["<<i<<"] : ";
                Node* temp = arr[i];
                while(temp!=NULL)
                {
                    cout<<temp->data<<"==>";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
    }

    bool search(int data)
    {
        if(arr==NULL)
        {
            cout<<"HashTable is Empty."<<endl;
        }
        else
        {
            int key = HashFun(data);
            Node *temp = arr[key];
            if(temp==NULL)
            {
                cout<<"Data Not Found."<<endl;
                return false;
            }
            else
            {
                while(temp!=NULL)
                {
                    if(temp->data == data)
                    {
                        cout<<data<<" found."<<endl;
                        return true;
                    }
                    temp = temp->next;
                }
            }
            cout<<"Data Not Found."<<endl;
            return false;
        }
    }

};

int main()
{
    HashTable HT(6);
    HT.insert(24);
    HT.insert(25);
    HT.insert(20);
    HT.insert(30);
    HT.insert(21);
    HT.insert(27);
    HT.display();
    HT.search(27);
    return 0;
}
