//pesudo code operation function for Stack using array
#include <iostream>
using namespace std;
class Stack {
    private:
        int size, capacity;
        int *arr;
    public:
        Stack(int n) {
            capacity = n;
            arr = new int[capacity];
            size = 0;
        }
        bool isEmpty() {
            return (size == 0) ? 1 : 0;
        }

//#2 implement basic operation include:
    //push;
        void push(int a) {
            if (size == capacity) return;
            else {
                arr[size] = a;
                size++;
            }
        }
    //pop
        void pop() {
            if (isEmpty) return;
            size --;
        }
};
//both operation use constant step so the complexity will be O(1)