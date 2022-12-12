#include<iostream>
#include<stdlib.h>

using namespace std;

struct Tree{
    char huruf;
    Tree *left;
    Tree *right;
};

Tree *node, *root=NULL, *parent;

Tree *tambahNode(char data){
    node = new Tree();
    node->huruf = data;//t
    node->left = NULL;
    node->right = NULL;
    if(root==NULL)
    {
        root = node;
    }
    parent = node;
    return node;
}

void tambahChild(Tree *nodeBaru, string pos)
{
    if(pos == "kiri")
    {
        parent->left = nodeBaru;
    }
    else
    {
        parent->right = nodeBaru;
    }

    parent = nodeBaru;
}

void preOrder(Tree *current)
{
    if(current!=NULL){
        cout<<current->huruf<<" ";
        preOrder(current->left);
        preOrder(current->right);
    }
}

void menu(int pilih)
{
    char data;
    Tree *inputan;
    switch(pilih)
    {
        case 1:
            cout<<"Masukkan satu huruf: ";
            cin>>data;
            inputan = tambahNode(data);
            tambahChild(inputan,"kiri");
            break;
        //case 2: tambahKiri();break;
        case 3: preOrder(root);break;
        //case 4: tambahKiri();break;
        //case 5: tambahKiri();break;
        case 0: exit(0);break;
    }
}

int main()
{
    int pilih;
    do {
        cout<<"1. Tambah Kiri"<<endl;
        cout<<"2. Tambah Kanan"<<endl;
        cout<<"3. Pre Order"<<endl;
        cout<<"4. In Order"<<endl;
        cout<<"5. Post Order"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Masukkan pilihan: ";
        cin>>pilih;
        menu(pilih);
    }
    while(pilih!=0);
}
