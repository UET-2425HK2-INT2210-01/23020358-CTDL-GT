//pseudo code operation function for Queue using array
#include <iostream>
using namespace std;
//#1 implement Queue with array
class Queue {
    private:
        int size, capacity, frontindex;
        int *arr;
    public:
        Queue(int n) {
            capacity = n;
            arr = new int[capacity];
            size = 0;
            frontindex = 0;
        }
        bool isEmpty() {
            return (size == 0) ? 1 : 0;
        }

//#2 implement basic operation include:
    //enqueue;
        void enqueue(int a) {
            int end = (frontindex + size) % capacity;
            if (size == capacity) return;
            else {
                arr[end] = a;
                size++;
            }
        }
    //dequeue
        void dequeue() {
            if (isEmpty) return;
            frontindex = (frontindex + 1) % capacity;
            size --;
        }
};
//both 2 operation require constant step to run so the complexity should be O(1) for both operation
