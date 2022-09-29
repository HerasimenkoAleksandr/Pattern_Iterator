#pragma once
using namespace std;


class IIterator
{
public:
    virtual void IterNext() = 0;
    virtual void IterBack() = 0;
    virtual void IteShow() = 0;
};
class Collection
{
public:
    virtual IIterator* CreatIterator() = 0;
    virtual void SetA() = 0;
    virtual int GetA(int index) = 0;
};

class Collection_1 : public Collection
{
    int a[10];
public:
    void SetA();
    int GetA(int index);
    IIterator* CreatIterator();
};



class Iterator_1 : public IIterator
{
    Collection_1* obj;
    int index;

public:
    Iterator_1(Collection_1* obj1);
    void IterNext();
    void IterBack();
    void IteShow();
};
class Collection_2 : public Collection
{
    list <int> a;

public:
    void SetA();
    int GetA(int index);
    IIterator* CreatIterator();
};
class Iterator_2 : public IIterator
{
    Collection_2* obj;
    int index;

public:
    Iterator_2(Collection_2* obj1);
    void IterNext();
    void IterBack();
    void IteShow();
};





