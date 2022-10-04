#include<iostream>
//#include<string>
//#include<math.h>
using namespace std;

struct LL{
    int value;
    LL *node;
} *first=NULL;

int count(LL *p){
    
    int count=0;
    while (p)
    {
        count ++;
        p=p->node;
    }
    return count;

}


void insert(int value,int place){
    LL *t;
    t=new LL;
    t->value=value;
    if(!place){
        if (first==NULL)
        {
            t->node=NULL;
            first=t;
        }
    }
    else if (place && (place<=count(first)+1))
     {
        LL *p=first,*q=NULL;
        for (int i = 0; i < place; i++)
        {
            q=p;
            p=p->node;
        }
        q->node=t;
        t->node=p;
    }
    
    
}

void display(LL *p){
    
    while (p!=NULL)
    {
        cout<<p->value<<"->";
        p=p->node;
    }
    
}

int search(LL*p, int a)
{
    int count=1;
    while (p)
    {
        if (a==p->value)
        {
            return count;
        }
        count++;
        p=p->node;
        
    }
    
    return 0;
}

int main(){

first= new LL;
LL *a;
a= new LL;

a->value=0;
a->node=NULL;
first=a;
// LL *b;
// b= new LL;

// b->value=1;
// b->node=NULL;
// first->node=b;



bool start = true;
do
{
    system("cls");
    display(first);

    int a;
    cout<<endl<<"Select your choice:"<<endl<<"1.Insert a new member in the Linked List."<<endl<<"2. Search for an integer"<<endl<<"3.End the Program"<<""<<endl;
    cin>>a;
    if (a==1)
    {
        int b,c;
        cout<<endl<<"Enter the value and Position"<<endl;
        cin>>b>>c;
        insert(c,b);
    }
    else if (a==2)
    {
        int x;
        cout<<"Enter the Element to be saerched "<<endl;
        cin>>x;
        int y=search(first,x);
        if (y)
        {
            
        cout<<x<<" is at the position "<<y;
        }
        else
        {
            cout<<"Doesnt exist";
        }
        
        
        
    }
    
    else if (a==3)
    {
        cout<<"Exiting the program."<<endl;
        start=false;
    }
    
    
    } while (start);



}
