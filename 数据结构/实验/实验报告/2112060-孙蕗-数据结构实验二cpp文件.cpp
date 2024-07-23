#include<iostream>
using namespace std;
template<class T>
class ChainNode
{
public:
    T data;
    ChainNode<T>* link;
};
template<class T>
class CircularChain//循环链表
{
public:
    CircularChain();
    bool IsEmpty() const { return first == 0; }
    int Length();
    CircularChain<T>& Insert(int k, T& x);
    void print(int k);
    CircularChain<T>& Reverse();
    CircularChain<T>& Append(const T& x);
    ChainNode<T>* first;// 头指针
    ChainNode<T>* last;//尾指针
};
template<class T>
CircularChain<T>::CircularChain()//头尾指针的初始化
{
    first = nullptr;
    last = nullptr;
}
template<class T>
int CircularChain<T>::Length()//计算循环链表的长度
{
    int len = 0;
    if (first == nullptr)//头指针空，为空链表
    {
        return 0;
    }
    else
    {
        ChainNode<T>* current = first;
        if (first == last)//头尾指针相等，链表中只有一个元素
        {
            return 1;
        }
        else
        {
            while (current->link != this->first)
            {
                len++;
                current = current->link;
            }
            len++;
            return len;
        }
    }
}
template<class T>
void CircularChain<T>::print(int k)//输出
{
    ChainNode<T>* current;
    int i = 1;
    for (current = first; i <= k && current; current = current->link)
    {
        cout << current->data << " ";
        i++;
    }
}
template<class T>
CircularChain<T>& CircularChain<T>::Insert(int k, T& x)//插入（当k=0时，为头插）
{
    ChainNode<T>* p = first;
    for (int index = 1; index < k && p; index++)
        p = p->link;
    ChainNode<T>* y = new ChainNode<T>; //新节点
    y->data = x;
    if (k) //k!=0,插在中间
    {
        y->link = p->link;
        p->link = y;
    }
    else//k=0，头插
    {
        y->link = first;//新建节点为头节点
        first = y;
    }
    return *this;
}
template<class T>
CircularChain<T>& CircularChain<T>::Append(const T& x)//尾插
{
    ChainNode<T>* y = new ChainNode<T>;//新节点
    y->data = x;
    if (this->Length() != 0) //非空链表
    {
        y->link = first;
        last->link = y;
        last = y;
        last->link = first;
    }
    else // 空链表，头尾指针指向同一个元素
    {
        first = y;
        last = y;
    }
    return *this;
}
template<class T>
CircularChain<T>& CircularChain<T>::Reverse()//循环链表的翻转，头插翻转
{
    int k = this->Length();
    ChainNode<T>* p = first->link;
    last = first;//将原本的头节点变成尾节点，头尾指针都指向头元素
    for (int i = 1; i < k; i++)//将头节点后的元素按顺序头插
    {
        this->Insert(0, p->data);
        p = p->link;
    }
    last->link = first;//翻转后，原来的尾节点变成头节点，原来的头节点变成尾节点，循环也跟着翻转
    return *this;
}

template<class T>
class Chain {
public:
    Chain() { first = nullptr; }//初始化头节点
    bool IsEmpty() const { return first == 0; }
    int Length();
    Chain<T>& Insert(int k, T& x);
    Chain<T>& Reverse();
    Chain<T>& Append(T& x);
    T knumber(int k);
    void print(int k);
    ChainNode<T>* first;
    ChainNode<T>* last;
    Chain<T>& DeleteB(CircularChain<T>& B);
};
template<class T>
int Chain<T>::Length()//计算元素个数
{
    ChainNode<T>* current = first;
    int len = 0;
    while (current)
    {
        len++;
        current = current->link;
    }
    return len;
}
template<class T>
void Chain<T>::print(int k)//输出元素
{
    ChainNode<T>* current;
    int i = 1;
    for (current = first; i <= k + 1 && current; current = current->link)
    {
        cout << current->data << " ";
        i++;
    }
}
template<class T>
Chain<T>& Chain<T>::Insert(int k, T& x)//插入
{
    ChainNode<T>* p = first;
    for (int index = 1; index < k && p; index++)
        p = p->link;
    ChainNode<T>* y = new ChainNode<T>; //新建节点
    y->data = x;
    if (k) //中间插入
    {
        y->link = p->link; p->link = y;
    }
    else //头插
    {
        y->link = first;  first = y;
    }
    return *this;
}
template<class T>
Chain<T>& Chain<T>::Append(T& x)//尾插
{
    ChainNode<T>* y = new ChainNode<T>;//新节点
    y->data = x;
    if (this->Length() != 0) //非空链表
    {
        last->link = y;
        y->link = nullptr;
        last = y;
    }
    else
    {
        first = y;
        last = y;
        last->link = nullptr;
    }
    return *this;
}
template<class T>
Chain<T>& Chain<T>::Reverse()//就地翻转
{
    if (this->first == nullptr)//空链表 
    {
        return *this;
    }
    ChainNode<T>* p1 = this->first->link;//p1为本次要翻转的元素
    ChainNode<T>* p2 = nullptr;//p2为下一个要翻转的元素
    this->first->link = nullptr;//变尾节点
    while (p1 != nullptr)
    {
        p2 = p1->link;//下一个要翻转的元素
        p1->link = this->first;//翻转
        this->first = p1;//换到头之后，变成头结点
        p1 = p2;//下一个要翻转的元素
    }
    return *this;
}
template<class T>
T Chain<T>::knumber(int k)//快慢指针，中间空k-1个元素
{
    ChainNode<T>* p1 = first;
    for (int i = 1; i < k + 1 && p1; i++)
    {
        p1 = p1->link;
    }
    ChainNode<T>* p2 = first;
    for (int i = 1; p1; i++)
    {
        p1 = p1->link;
        p2 = p2->link;
    }
    return p2->data;
}
template<class T>
Chain<T>& Chain<T>::DeleteB(CircularChain<T>& B)//删除A中B出现的元素
{
    ChainNode<T>* a1 = this->first;//A的指针不动，动B的
    ChainNode<T>* a2 = a1;//a2指向的是a1的前一个
    int i = 0;
    while (a1 != 0)//没到尾
    {
        ChainNode<T>* b1 = B.first;
        int i = 1;
        while (a1->data != b1->data && i <= B.Length())//a1不动动b1
        {
            b1 = b1->link;
            i++;
        }
        if (a1->data == b1->data)//找到了，有相同的元素，要删除A中节点
        {
            if (a1 == this->first)//如果是A的头节点
                first = first->link;//直接指向下一个
            else
            {
                a2->link = a1->link;//a2是a1的前一个，删除a1节点意味着a2下一个指向的是a1的下一个
                a1 = a1->link;//a1指向a1的下一个元素，即删除a1，a1也往前动了一个  
            }
        }
        else//A中出现元素B中没有，要留下
        {
            a2 = a1;
            a1 = a1->link;//a2指的是a1的前一个，a1往前动一个，接着找
        }
    }
    return *this;
}
int main()
{
    Chain<int> ForwardchainA;
    CircularChain<int> circlechainB;
    int n;
    int k;
    cin >> k;
    while (cin >> n)
    {
        ForwardchainA.Append(n);
    }
    int B[10] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 10; i++)
    {
        circlechainB.Append(B[i]);
    }
    cout << endl;
    cout << "B.Length():" << circlechainB.Length() << endl;
    cout << "A:";
    ForwardchainA.print(ForwardchainA.Length());
    cout << endl;
    cout << "B:";
    circlechainB.print(circlechainB.Length());
    cout << endl;
    cout << "A Reverse:";
    ForwardchainA.Reverse();
    ForwardchainA.print(ForwardchainA.Length());
    cout << endl;
    cout << "B Reverse:";
    circlechainB.Reverse();
    circlechainB.print(circlechainB.Length());
    cout << endl;
    cout << "circlechainB first:" << circlechainB.first->data << "    " << "circlechainB last:" << circlechainB.last->data << endl;
    cout << "A delete_B:";
    ForwardchainA.DeleteB(circlechainB);
    ForwardchainA.print(ForwardchainA.Length());
    cout << endl;
    cout << "delete A_k:";
    cout << ForwardchainA.knumber(k);
    cout << endl;
    return 0;
}