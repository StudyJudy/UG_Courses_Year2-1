#include<iostream>
#include<queue>
#include <cstring>
#include<string>
#include<vector>
using namespace std;
int Count = 0;
bool IsGo = true;
template <class T>
class BinaryTreeNode
{
public:
    friend void Visit(BinaryTreeNode<T>*);
    friend void InOrder(BinaryTreeNode<T>*);
    friend void PreOrder(BinaryTreeNode<T>*);
    friend void PostOrder(BinaryTreeNode<T>*);
    friend void LevelOrder(BinaryTreeNode<T>*);
    T data;
    int height;
    BinaryTreeNode<T>* LeftChild;    // 左孩子
    BinaryTreeNode<T>* RightChild;   // 右孩子
    BinaryTreeNode() {}
    BinaryTreeNode(T data) : data(data), LeftChild(nullptr), RightChild(nullptr) {};
    ~BinaryTreeNode() {}
};
template <class T>
void Visit(BinaryTreeNode<T>* x)//输出当前节点的值
{
    if (x)
    {
        cout << x->data << ' ';
    }
}
template <class T>
void PreOrder(BinaryTreeNode<T>* t)//DLR
{
    if (t)
    {
        Visit(t);                 		// 访问根节点 
        PreOrder(t->LeftChild);    	// 遍历左子树 
        PreOrder(t->RightChild);  	//遍历右子树 
    }
}
template <class T>
void InOrder(BinaryTreeNode<T>* t)//LDR
{
    if (t) {
        InOrder(t->LeftChild); 	//遍历左子树 
        Visit(t); 				//访问根节点 
        InOrder(t->RightChild); 	//访问根节点 
    }
}
template <class T>
void PostOrder(BinaryTreeNode<T>* t)//LRD
{
    if (t)
    {
        PostOrder(t->LeftChild);    //遍历左子树 
        PostOrder(t->RightChild);  //遍历右子树 
        Visit(t);                      //访问根节点 
    }
}
template <class T>
void LevelOrder(BinaryTreeNode<T>* t)//层序
{
    queue <BinaryTreeNode<T>*>  Q;
    while (t)
    {
        Visit(t); 
        //将t的孩子放入队列 
        if (t->LeftChild) Q.push(t->LeftChild);//左
        if (t->RightChild) Q.push(t->RightChild);//右
        //访问下一个节点
    }
}

template<class T>
class BinaryTree
{
public:
    ~BinaryTree() {};
    void PreOrder(void(*Visit) (BinaryTreeNode<T>* u))
    {
        PreOrder(Visit, root);
    }
    void InOrder(void(*Visit)(BinaryTreeNode<T>* u))
    {
        InOrder(Visit, root);
    }
    void PostOrder(void(*Visit)(BinaryTreeNode<T>* u))
    {
        PostOrder(Visit, root);
    }
    BinaryTreeNode<T>* root;
    BinaryTreeNode<T>* root2;
    vector<T>datas;//存数据
    vector<T>origin;
    void CreateTree();//根据输入建立二叉树
    void CreateCompleteTree(BinaryTreeNode<T>*& u);//建立完全二叉树
    int Height(BinaryTreeNode<T>* u, T t);//深度
    BinaryTreeNode<T>* Find(BinaryTreeNode<T>* u, T node);//查找某个节点
    void PreOrder(void(*Visit) (BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);//前序
    void InOrder(void(*Visit) (BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);//中序
    void PostOrder(void(*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t);//后序
    void LevelOrder(void(*Visit)(BinaryTreeNode<T>* t), BinaryTreeNode<T>* u);//层序
    bool IsCompleteTree(BinaryTreeNode<T>* u); //判断是不是完全二叉树
    void ToCompleteTree(BinaryTreeNode<T>* u);//建立完全二叉树
};
template <class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t)//前序
{
    if (t)
    {
        Visit(t);//DLR
        PreOrder(Visit, t->LeftChild);
        PreOrder(Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::InOrder(void(*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t)//中序
{
    if (t)
    {
        InOrder(Visit, t->LeftChild);//LDR
        Visit(t);
        InOrder(Visit, t->RightChild);
    }
}
template <class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T>* u), BinaryTreeNode<T>* t)//后序
{
    if (t) 
    {
        PostOrder(Visit, t->LeftChild);//LRD
        PostOrder(Visit, t->RightChild);
        Visit(t);
    }
}

template <class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T>* t), BinaryTreeNode<T>* u)//层序
{
    int times = 0;
    int p = 1;
    queue<BinaryTreeNode<T>*> Q;
    if (u != nullptr)
    {
        Q.push(u);
    }
    while (!Q.empty())
    {
        BinaryTreeNode<T>* t = Q.front();
        Visit(t);
        if (t->LeftChild)
        {
            Q.push(t->LeftChild);//有左孩子就加进队列
        };
        if (t->RightChild)
        {
            Q.push(t->RightChild);//有右孩子就加进队列
        }
        Q.pop();
        times++;
        if (times == p)
        {
            cout << endl;//完全二叉树时候的换行输出
            p = p * 2 + 1;
        }
    }
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Find(BinaryTreeNode<T>* u, T node)
{
    if (u == nullptr)//空节点啥也不是
    {
        return nullptr;
    }
    if (u->data == node)//找到节点了
    {
        return u;
    }
    BinaryTreeNode<T>* lresult = Find(u->LeftChild, node);//左孩子查找
    BinaryTreeNode<T>* rresult = Find(u->RightChild, node);//右孩子查找
    return lresult != nullptr ? lresult : rresult;
}
/*template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* u)
{// 返回树的高度 .'
    if (u==nullptr) return 0;                    // empty tree
    else
    {
        int hl = Height(u->LeftChild);  // height of left
        int hr = Height(u->RightChild); // height of right
        if (hl > hr)
        {
            return ++hl;
        }
        else
            return ++hr;
    }
}*/
template<class T>
void BinaryTree<T>::CreateTree()
{
    int i;
    BinaryTreeNode <T>* t = new BinaryTreeNode <T>(this->origin[0]);//根节点
    t->height = 1;//根节点高度为1
    root = t;
    this->root->height = 1;
    for (i = 0; (i <= origin.size() / 2 - 1) && (Find(root, origin[i]) != nullptr); i++)//根据二叉树的性质，只有一半的节点有可能有孩子
    {
        if (2 * i + 1 < origin.size())//把数拿出来存在树里
        {
            if (origin[2 * i + 1] != -100000)//不是#
            {
                Find(root, origin[i])->LeftChild = new BinaryTreeNode<T>(origin[2 * i + 1]);//左孩子与父节点的关系
                Find(root, origin[i])->LeftChild->height = Find(root, origin[i])->height + 1;//孩子的高度是父节点的高度+1
            }
            else
            {
                Find(root, origin[i])->LeftChild = nullptr;//是#
            }
        }
        else
        {
            break;
        }
        if (2 * i + 2 < origin.size())
        {
            if (origin[2 * i + 2] != -100000)//不是#
            {
                Find(root, origin[i])->RightChild = new BinaryTreeNode<T>(origin[2 * i + 2]);//右孩子与父节点的关系
                Find(root, origin[i])->RightChild->height = Find(root, origin[i])->height + 1;//孩子的高度是父节点的高度+1
            }
            else
            {
                Find(root, origin[i])->RightChild = nullptr;//是#
            }
        }
        else
        {
            break;
        }

    }
    return;
}

template<class T>
bool BinaryTree<T>::IsCompleteTree(BinaryTreeNode<T>* u)//u是root
{
    if (u == nullptr)
        return false;
    queue<BinaryTreeNode<T>*> q;
    bool leaf = false;
    bool ans = true;
    q.push(u);
    while (!q.empty())
    {
        BinaryTreeNode<T>* tmp = q.front();
        q.pop();
        if (leaf)//如果一个节点没有子节点为叶子节点；已经出现了空子树的节点，后面出现的必须是叶子节点（左右子树必须为空）
        {
            if (tmp->LeftChild != nullptr || tmp->RightChild != nullptr)
            {
                ans = false;
                break;
            }
        }
        else//不是叶子节点
        {
            if (tmp->LeftChild != nullptr && tmp->RightChild != nullptr)//左右都有
            {
                q.push(tmp->LeftChild);
                q.push(tmp->RightChild);
            }
            else if (tmp->LeftChild != nullptr && tmp->RightChild == nullptr)//右孩子没有
            {
                leaf = true;//叶子节点
                q.push(tmp->LeftChild);//左孩子加进去
            }
            else if (tmp->LeftChild == nullptr && tmp->RightChild != nullptr)//左孩子没有
            {
                ans = false;//肯定非完全二叉树
                break;
            }
            else
            {
                leaf = true;//叶子节点
            }
        }
    }
    return ans;
}
template<class T>
void BinaryTree<T>::CreateCompleteTree(BinaryTreeNode<T>*& u)
{
    int i;
    BinaryTreeNode <T>* t = new BinaryTreeNode <T>(this->datas.at(0));
    root2 = t;
    BinaryTreeNode <T>* m = root2;//新的根节点
    for (i = 0; i <= datas.size() / 2 - 1; i++)
    {
        if (2 * i + 1 < datas.size())//把数拿出来存在树里
        {
            Find(root2, datas[i])->LeftChild = new BinaryTreeNode<T>(datas[2 * i + 1]);
        }
        else
        {
            break;
        }
        if (2 * i + 2 < datas.size())
        {
            Find(root2, datas[i])->RightChild = new BinaryTreeNode<T>(datas[2 * i + 2]);
        }
        else
        {
            break;
        }

    }
}
template<class T>
void BinaryTree<T>::ToCompleteTree(BinaryTreeNode<T>* u)
{
    CreateCompleteTree(root2);
    LevelOrder(Visit, root2);
}

int main()
{
    BinaryTree<int> BT;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>();
    cout << "请输入二叉树中节点的值：" << endl;
    char node2[50];
    cin.getline(node2,50);
    int data[20];
    int count = 0;
    int i = 0, j = 0;
    for (i = 0; i < strlen(node2); i++)//将字符串输入处理为整数存在两个vector中
    {
        int num = 0;
        if (node2[i] == '#')
        {
            data[count] = -100000;//#定值为-100000
            BT.origin.push_back(data[count]);//只存在二叉树的vector中
            i++;
            count++;
        }
        else
        {
            for (j = i; j < strlen(node2) && node2[j] != ' '; j++) {}
            if (node2[i] != '-')//负数
            {
                for (int m = i; m < j; m++)
                {
                    num = num * 10 + node2[m] - '0';//处理成数字
                }
                data[count] = num;
                BT.datas.push_back(data[count]);//存在完全二叉树的vector
                BT.origin.push_back(data[count]);//存在二叉树的vector
                count++;
                i = j;
            }
            else
            {
                for (int m = i + 1; m < j; m++)
                {
                    num = num * 10 + node2[m] - '0';//处理成数字
                }
                data[count] = 0 - num;//负数
                BT.datas.push_back(data[count]);//存在完全二叉树的vector
                BT.origin.push_back(data[count]);//存在二叉树的vector
                count++;
                i = j;
            }
        }
    }
    BT.CreateTree();
    root = BT.root;
    int node;
    if (BT.IsCompleteTree(BT.root))
    {
        cout << "True" << endl;
        cout << "输入节点z值" << endl;
        cin >> node;
        cout << node << "节点的高度为：" << BT.Find(BT.root, node)->height << endl;
    }
    else
    {
        cout << "False" << endl;
        cout << "输入节点z值" << endl;
        cin >> node;
        cout << node << "节点的高度为：" << BT.Find(BT.root, node)->height << endl;
        BT.ToCompleteTree(BT.root2);
    }
    cout << endl;
    return 0;
}