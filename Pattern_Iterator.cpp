#include <iostream>
#include <list>
#include"Header.h"
using namespace std;


void Client()
{
    
    int p;
    cout << " select a collection to see the iterator at work" << endl;
    cout<< "Enter 1 for Collection_1 " << endl;
    cout << "Enter 2 for Collection_1 " << endl;
    cin >> p;
    Collection* A; // интерфейс контейнера 
    if(p==1)
       A = new Collection_1();// подхватывается объект хранения информации (контейнер)
    else
       A = new Collection_2();

    A->SetA();

    IIterator* B = A->CreatIterator();// создаеться итератор "B" для конкретного объекта хранения информации 
    B->IterNext(); // работа итератора
    B->IteShow();
    B->IterNext();
    B->IteShow();

    system("pause");
    cout << "enter 1 to repeat" << endl;
    cin >> p;
    if(p==1)
    Client();


}





int main()
{
    Client();
   

    return 0;
}



void Collection_1::SetA()
{
    for (int i = 0; i < 10; i++)
        a[i] = i + 1;
}
int Collection_1::GetA(int index)
{
    return a[index];
}

IIterator* Collection_1::CreatIterator()
{
    return new Iterator_1(this);
}





Iterator_1::Iterator_1(Collection_1* obj1) :obj{ new Collection_1 }, index{ 0 }
{
    obj = obj1;
}

void Iterator_1::IterNext()
{
    cout << "IterNext" << endl;
    ++index;

}
void Iterator_1::IterBack()
{
    cout << "IterBack" << endl;
    ++index;
}

void Iterator_1::IteShow()
{

    cout << obj->GetA(index) << endl;
}



void Collection_2::SetA()
{
    for (int i = 0; i < 10; i++)
        a.push_back((i * 2) + 4);

}
int Collection_2::GetA(int index)
{


    int g = 0;
    for (auto i = a.begin(); i != a.end(); i++)
    {
        g++;
        if (g == index)
            return *i;
    }

}

IIterator* Collection_2::CreatIterator()
{
    return new Iterator_2(this);
}

Iterator_2::Iterator_2(Collection_2* obj1) :obj{ new Collection_2 }, index{ 0 }
{
    obj = obj1;
}

void Iterator_2::IterNext()
{
    cout << "IterNext" << endl;
    ++index;

}
void Iterator_2::IterBack()
{
    cout << "IterBack" << endl;
    ++index;
}

void Iterator_2::IteShow()
{

    cout << obj->GetA(index) << endl;
}
