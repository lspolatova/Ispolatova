// шаблон стек
#include <iostream>
#include <cassert> // библиотека для assert
#include <iomanip>  // для setw

/*

setw(количество_позиций_для_вывода_числа). Компоненты-функции, позволяющие изменять флаги состояния объекта cout.

Функция assert оценивает выражение, которое передается ей в качестве аргумента, через параметр expression. Если аргумент-выражение этого макроса в функциональной форме равно нулю (т.е. выражение ложно), сообщение записывается на стандартное устройство вывода ошибок и вызывается функция abort, работа программы прекращается.

*/

using namespace std;

// Интерфейс шаблона класса 
template <typename T>   
// typename говорит о том, что в шаблоне будет использоваться встроенный тип данных, такой как: int, double,float, char
// T — это параметр шаблона класса, который может принимать любой из встроенных типов данных.

class Stack
{

private:

    T *stackPtr;           // указатель на стек
    int size;              // максимальное количество элементов в стеке
    T top;                 // номер текущего элемента стека
                                      
public:
    
    Stack(int = 10);        // по умолчанию размер стека равен 10 элементам
    ~Stack();               // деструктор
    bool push(const T);   // поместить элемент в стек
    bool pop();             // удалить из стека элемент
    void printStack();      // Вывод стека
};
 
int main()
{
    Stack <int> myStack(5);
 
    // заполняем стек
    cout << "Введите 5 элементов в стек: \n";
    int ct = 0;
    while (ct++ != 5)
    {
        int temp;
        cin >> temp;
        myStack.push(temp);
    }
 
    cout << "\nЭлементы стека: \n";
    myStack.printStack(); // вывод стека на экран
 
    cout << "\nУдаляем два элемента из стека:\n";
 
    myStack.pop(); // удаляем 1 элемент из стека
    myStack.pop(); // удаляем 2 элемент из стека
    cout << "Элементы стека: \n";
    myStack.printStack(); // вывод стека на экран
 
    return 0;
}
 
// реализация функций шаблона класса Stack
// перед каждой функцией необходимо объявлять шаблон, точно такой же, как и перед классом — template <typename T> (элемент-функции шаблона класса, объявляются точно также, как и обычные шаблоны функций)
// Чтобы привязать каждую элемент-функцию к шаблону класса, используем бинарную операцию разрешения области действия — :: с именем шаблона класса — Stack<T>

// конструктор стека
template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s: 10;   // инициализировать размер стека
    stackPtr = new T[size]; // выделить память под стек
    top = -1;               // значение -1 говорит о том, что стек пуст
}
 
// деструктор стека
template <typename T>
Stack<T>::~Stack()
{
    delete [] stackPtr; // удаляем стек
}
 
// элемент функция класса  Stack для помещения элемента в стек
// если возвращаемое значение true - операция успешно завершена,
// false - элемент в стек не добавлен
template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false; // стек полон
 
    top++;
    stackPtr[top] = value; // помещаем элемент в стек
 
    return true; // успешное выполнение операции
}
 
// элемент функция для удаления элемента из стека
// если возвращаемое значение true - операция успешно завершена
// false - стек пуст
template <typename T>

  // проверяем размер стека
   // assert(top > 0); // номер текущего элемента должен быть больше 0
   
    //stackPtr[--top];
bool Stack<T>::pop()
{
    if (top == - 1)
        return false; // стек пуст
 
    stackPtr[top] = 0; // удаляем элемент из стека
    top--;
 
    return true; // успешное выполнение операции
}
 
// вывод стека на экран
template <typename T>
void Stack<T>::printStack()
{
    for (int ix = size -1; ix >= 0; ix--)
        cout << setw(5) << stackPtr[ix] << endl;
}


// Вариант 2 - прописать stack и использовать
// адаптер stack определен в заголовочном файле
// stack интерфейс дя контейнера
// переименование операций в pop и push и удаление нетекстовых операций
// по умолчанию стек хранит элементы в двусторонней очереди

/*
#include <stdio.h>
#include <iostream>

using namespace std;
 

template <class T,class C = deque<T>> class std::stack
{

protected:
 C c;
 
public:
 typedef typename C: :value_type value_type;
 typedef typename C: :size_type size_type;
 
 typedef C container_type;
 
 explicit stack (const C& a=C()) :c(a) {}
 
 bool empty() const {return c.empty();}
 size_type size() const {return c.size();}
 
 value_type& top() {return c.back();}
 const value_type& top() const {return c.back();}
 
 void push (const value_type& x) {c.push_back(x);}
 void pop() {c.pop_back();}

};

*/
