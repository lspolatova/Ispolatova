#include <iostream>
 #include <cstdlib>// для system
using namespace std;
class CMyStack
{
    private:
        struct Node
        {
            int d;
            Node *p;
        };
        Node *top = NULL;
        int colvo = 0;
    public:
        void push(int d)
        {
             Node *pv = new Node;
             pv->d = d;
             pv->p = top;
             top = pv;
             colvo = colvo + 1;
        }
        int pop()
        {
             if (top == NULL)
             {
                 std::cout << "empty list" << std::endl;
				 return -1;
             }  
             int temp = top->d;
             Node *pv = top;
             top = top->p;
             delete pv;
             colvo = colvo - 1;
             return temp;
        }
        int Mytop()
        {
             if (top == NULL)
             {
                 std::cout << "empty list" << std::endl;
				 return -1;
             }  
             int temp = top->d;
             return temp;
        }
		int size(){
		     if (top == NULL)
             {
                 std::cout << "empty list" << std::endl;
				 return -1;
             }
			 return colvo;  	
		}
		void empty(){
		     if (top == NULL)
             {
                 std::cout << "empty list" << std::endl;
             }
             else 
            {
                std::cout << "not empty list" << std::endl; 
		    }
		     
		}		      
		~CMyStack()
        {
            while (top)
            {
                Node *pv = top;
                top = top->p;
                delete pv;
            }  
 
        }
  


};
int main() 
{ 
    CMyStack newStack;
    newStack.pop();
    newStack.push(1);
    std::cout << newStack.pop() << std::endl;
    newStack.push(2);
    newStack.push(3);
    std::cout << newStack.pop() << std::endl;
    std::cout << newStack.Mytop() << std::endl;
    std::cout << newStack.size() << std::endl;
    newStack.empty();
    system("pause"); 
    return 0; 
}


