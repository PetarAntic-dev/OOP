#include <iostream>
using namespace std;

int dummy=42;

class Vect
{
private:
    int size;
    int capacity;
    int *elements;

    void _copy(const Vect& orig);
public:
    Vect(int size = 0, int value = 0);
    ~Vect();
    Vect(const Vect& orig);
    Vect& operator=(const Vect& orig);
    void print();
    void push(int val);
    void pop();
    void sort();
    int& at(int pos);
    int& front();
    int& back();
    int* data();

    int operator[](int i);
    Vect operator+(const Vect& v);
};

int& Vect::front()
{
    if(this->size==0)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[0];
}

int* Vect::data()
{
    return this->elements;
}

int& Vect::back()
{
    if(this->size==0)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[this->size-1];
}

int& Vect::at(int pos)
{
    if(pos<0 || pos>=this->size)
    {
        cout<<"Error"<<endl;
        return dummy;
    }
    return this->elements[pos];
}

Vect::Vect(int size, int value)
{
    int capacity = 4;
    while (size >= capacity)
    {
        capacity*=2;
    }
    elements = new int[capacity];
    this->capacity = capacity;
    this->size = size;

    for (int i=0; i<this->size;i++ )
    {
        elements[i] = value;
    }
}

Vect::~Vect()
{
    delete [] elements;
}

void Vect::_copy(const Vect& orig)
{
    this->capacity = orig.capacity;
    this->size = orig.size;
    this->elements = new int[this->capacity];
    for (int i=0; i<this->size; i++)
    {
        this->elements[i] = orig.elements[i];
    }
}

Vect::Vect(const Vect& orig)
{
    _copy(orig);
}

Vect& Vect::operator=(const Vect& orig)
{
    if (this != &orig)
    {
        delete [] this->elements;
        _copy(orig);
    }
    return *this;
}

void Vect::print() {
    cout<<"C: "<< this->capacity << " S: " << this->size <<":\n";
    for (int i=0; i<this->size; i++)
    {
        cout<<this->elements[i] << " ";
    }
    cout<<endl;
}

void Vect::push(int val)
{
    if (this->size == this->capacity)
    {
        int newcap = this->capacity*2;
        int *tmp = new int[newcap];
        for (int i=0; i<this->size; i++)
        {
            tmp[i] = this->elements[i];
        }
        delete [] elements;
        elements = tmp;
        this->capacity = newcap;
    }

    this->elements[this->size] = val;
    this->size++;
}

void Vect::pop()
{
    if(this->size==0)return;
    this->size--;

    if(this->capacity/2>=this->size)
    {
        int newcap=this->capacity/2;
        int *tmp = new int[newcap];
        for (int i=0; i<this->size; i++)
        {
            tmp[i] = this->elements[i];
        }
        delete [] elements;
        elements = tmp;
        this->capacity = newcap;
    }
}

int Vect::operator[](int i) {
    if (i<0 || i > this->size-1)
    {
        return 42;
    }
    return this->elements[i];
}

Vect Vect::operator+(const Vect& v)
{
    int s=this->size+v.size;
    Vect ans(s);
    for (int i=0; i<this->size; i++)
    {
        ans.elements[i] = this->elements[i];
    }
    for(int i=0; i<v.size; i++)
    {
        ans.elements[i+this->size] = v.elements[i];
    }
    return ans;
}

void Vect::sort()
{
    int s=this->size;
    while(s--)
    {
        for(int i=0;i<s;i++)
        {
            if(this->elements[i]>this->elements[i+1])
            {
                swap(this->elements[i], this->elements[i+1]);
            }
        }
    }
}

int main() {
    // changed numbers
    Vect t(4, 50), v;

    t.print();

    v.push(300);
    v.push(150);
    v.pop();
    v.push(150);
    v.push(20);
    v.push(5);
    v.push(9999);

    v.print();

    Vect r = v + t;
    r.print();

    for(int i=0;i<6;i++) r.push(i * 3);
    r.print();

    r.sort();
    r.at(0) = 12345;
    r.print();

    cout<<"First: "<<r.front()<<" Last: "<<r.back()<<endl;

    r.print();
    r.pop();
    r.print();

    r.push(2025);
    r.print();
}
