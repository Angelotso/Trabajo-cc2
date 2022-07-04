#include <iostream>
#include <string>
 
using namespace std;
#define SIZE 10 // definimos tamaño de la pila

template <class T> 
class Stack 
{
    private:
        int top;
        T st[SIZE];
    public:
        Stack();
        ~Stack();
        void push(T k);
        T pop();
        T top_ele();
        bool isFull();
        bool isEmpty();
};
template <class T> 
Stack<T>::Stack() 
{ 
    top = -1;//head por defecto 
}
template<class T>
Stack<T>::~Stack(){}

template <class T> 
void Stack<T>::push(T k)
{
    if(isFull())//verifica si la pila esta llena 
    {
        cout << "Error Stack lleno\n";
    }
    else{
        cout << "Elemento Insertado -> " << k << endl;
        cout<<"\n";
        top = top + 1;
        st[top] = k;
    }
}

template <class T> 
T Stack<T>::pop()
{
    T popped_element = st[top];//incializar el elemento popped
    top--;
    cout<<"elemento eliminado -> "<<popped_element<<endl;
    cout<<"\n";
}

template <class T> 
T Stack<T>::top_ele()
{
    T top_element = st[top];
    cout<<"elemento ->"<< top_element;
    cout<<"\n";
}
template <class T> 
bool Stack<T>::isEmpty()//verificar si la pla esta vacia
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T> 
bool Stack<T>::isFull()//verificar si la pila esta llena
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

int main()
{
    int opc;
    Stack<int> stack;
    do{
        cout<<"**MENU**";
		cout<<"\n(1) Push ";
		cout<<"\n(2) Pop ";
		cout<<"\n(3) Top ";
        cout<<"\n(4) Close ";
		cout<<"\nOpcion: ";
		cin>>opc;

        if(opc==1){
            int n;
            cout<<"Valor: ";
            cin>>n;
            stack.push(n);
        }
        else if(opc==2){
            stack.pop();
        }
        else if(opc==3){
            stack.top_ele();
        }
    }
    while(opc!=4);
    return 0;
}