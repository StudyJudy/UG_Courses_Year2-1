#include <iostream>
#include<cstring>
#include<string>
using namespace std;
//栈的定义
template<class T>
class Stack 
{ 
public:
    int top = -1;
    T stack[50];
    bool IsEmpty() const { return top == -1; }
    T Top();
    void Push(T x);
    void Pop();
};
template<class T>
T Stack<T>::Top() 
{
	return stack[top];
} 
template<class T>
void Stack<T>::Push(T x)
{
    top++;
    stack[top] = x;
}
template<class T>
void Stack<T>::Pop()
{
    top--;
}

//运算符优先级
int priority(char ch)
{
    if (ch == '(' || ch == ')')
    {
        return 3;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//弹出来的两个数字与运算符进行运算
float calculate(float num1, float num2, char ch)
{
    switch (ch)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        return num1 / num2;
        break;
    default:
        break;
    }
}
bool Float(int i,char *str)
{
    for (; str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='('&&str[i]!=')' && i < strlen(str); i++)//不是运算符，就只能是数字和.
    {
        if (str[i]=='.')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Stack<float> num;//存数字的栈
    Stack<char> operators;//存运算符的栈
    char str[50];
    cin >> str;//输入字符串
    int len = strlen(str);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i]>'9')//是符号不是数字
        {
            if (str[i] == '('||operators.IsEmpty())
            {
                operators.Push(str[i]);
            }
            else
            {
                if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
                {
                    if (priority(str[i]) > priority(operators.Top()))//优先级比栈首高直接压进栈
                    {
                        operators.Push(str[i]);
                    }
                    else
                    {
                        while ((priority(str[i]) <= priority(operators.Top())) && !operators.IsEmpty()&&operators.Top()!='(')//直到遇到优先级比他小的再压进栈
                        {
                            float num2 = num.Top();
                            num.Pop();
                            float num1 = num.Top();
                            num.Pop();
                            char ch = operators.Top();
                            operators.Pop();
                            num.Push(calculate(num1, num2, ch));
                        }
                        operators.Push(str[i]);
                    }
                }
                else//是(
                {
                    while (operators.Top() != '(')
                    {
                        float num2 = num.Top();
                        num.Pop();
                        float num1 = num.Top();
                        num.Pop();
                        char ch = operators.Top();
                        operators.Pop();
                        num.Push(calculate(num1, num2, ch));
                    }
                    operators.Pop();
                }
            }
        }
        else//是数字，有可能多位数，有可能小数
        {
            float tempnum = 0;
            if (!Float(i,str))//后面没有.就肯定不是小数了
            {
                for (; str[i] <= '9' && str[i] >= '0' && i < len; i++)
                {
                    if ((str[i] >= '0') && (str[i] <= '9'))
                    {
                        tempnum = tempnum * 10 + str[i] - '0';
                    }
                }
            }
            else//是小数
            {
                double tmp10 = 10;
                for (; str[i] <= '9' && str[i] >= '0' && i < len&&str[i]!='.'; i++)//处理小数的整数部分
                {
                    if ((str[i] >= '0') && (str[i] <= '9'))
                    {
                        tempnum = tempnum * 10 + str[i] - '0';
                    }
                }
                i++;//'.'
                for (; str[i] <= '9' && str[i] >= '0' && i < len; i++)//处理小数的小数部分
                {
                    if ((str[i] >= '0') && (str[i] <= '9'))
                    {
                        tempnum+= float(str[i] - '0')/tmp10;
                    }
                    tmp10 *= 10;
                }
            }
            num.Push(tempnum);
            i--;
        }
    }
    while (!operators.IsEmpty())//直到符号栈空了运算才完成
    {
        float num2 = num.Top();
        num.Pop();
        float num1 = num.Top();
        num.Pop();
        char ch = operators.Top();
        operators.Pop();
        num.Push(calculate(num1, num2, ch));
    }
    cout << num.Top();//此时数字栈栈顶元素就是运算结果
	return 0;
}